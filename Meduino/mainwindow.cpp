#include "mainwindow.h"
#include "ui_mainwindow2.0.h"
#include "medicament.h"
#include "manipulerFichier.h"
#include "history.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>

QStringList headerMedoc = { "Nom", "Type", "Dosage", "Stock", "Seuil", "Boite" };
QStringList headerCalendrier = { "Medicaments", "Matin", "Midi", "Soir" };
QStringList headerStock = { "Medicaments", "stock disponible", "boire" };

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configuration des pages
    ui->ajout_page->setVisible(false);
    ui->options_page->setVisible(true);
    ui->supression_page->setVisible(false);
    ui->modification_page->setVisible(false);
    ui->stock_page_2->setVisible(false);

    // Chargement des medicaments
    liste = chargerMedicaments();
    qDebug() << "Nombre de medicaments :" << liste.size();

    // Configuration des tableaux
    configurerTableau(ui->tableau_medoc, headerMedoc);
    configurerTableau(ui->tableau_calendrier, headerCalendrier);
    // configurerTableau(ui->tableau_stock, headerStock);

    // Mise a jour des tableaux
    updateTableauMedoc();
    updateTableauCalendrier();

    // Configuration Arduino
    Arduino = new QSerialPort();
    Arduino->setPortName("/dev/ttyACM0");
    Arduino->setBaudRate(QSerialPort::Baud9600);
    Arduino->open(QIODevice::ReadWrite);

    connect(Arduino, &QSerialPort::readyRead, this, &MainWindow::lire_donnees_arduino);

    timer_distribution = new QTimer();
    timer_distribution->setSingleShot(true);

    connect(timer_distribution, &QTimer::timeout,this, [this]()
            {
                qDebug() << "TAKEN non reçu après 5 secondes.";

                non_prise(liste[compteur_medoc_distribution], temps_distribution);
            });


    // Compte a rebours
    countDown = new CompteARebour(this);
    countDown->setLabel(ui->temps_restant);

    connect(countDown, qOverload<const QString&>(&CompteARebour::tempsChange), this, &MainWindow::on_temps_change);
    connect(countDown, qOverload<int>(&CompteARebour::tempsChange),
            this, [this](int secondes) {
//                qDebug() << "Secondes restantes:" << secondes;
            });
    connect(countDown, &CompteARebour::termine, this, &MainWindow::on_compte_termine);

    // Charger les horaires de prise
    temps = chargerPrise();
    restartCountDown();

    timer_verification_heure = new QTimer(this);

    connect(timer_verification_heure, &QTimer::timeout, this, &MainWindow::verification_heure);

    timer_verification_heure->start(1000); // vérifier chaque seconde
}

// ==================== COMPTE A REBOURS ====================

void MainWindow::restartCountDown()
{
    if (temps.size() >= 3)
    {
        QTime maraina = temps[0];
        QTime atoandro = temps[1];
        QTime hariva = temps[2];

        ui->priseMatin->setTime(maraina);
        ui->priseMidi->setTime(atoandro);
        ui->priseSoir->setTime(hariva);

        QTime maintenant = QTime::currentTime();
        QTime prochainePrise;
        int diff = 0;

        if (maraina >= maintenant)
        {
            prochainePrise = maraina;
            diff = maintenant.secsTo(maraina);
            if(maraina==maintenant)
            {
                distribution_matin();
            }
        }
        else if (atoandro >= maintenant)
        {
            prochainePrise = atoandro;
            diff = maintenant.secsTo(atoandro);
            if(atoandro==maintenant)
                distribution_midi();
        }
        else if (hariva >= maintenant)
        {
            prochainePrise = hariva;
            diff = maintenant.secsTo(hariva);
            if(hariva==maintenant)
                distribution_soir();
        }
        else
        {
            prochainePrise = maraina.addSecs(24 * 3600);
            diff = maintenant.secsTo(prochainePrise);
            if (diff < 0) diff += 24 * 3600;
        }

        countDown->demarrer(diff);
    }
}

void MainWindow::on_temps_change(const QString &temps)
{
//    qDebug() << "Temps restant:" << temps;
}

void MainWindow::on_compte_termine()
{
    qDebug() << "Le compte a rebours est termine !";
    QMessageBox::information(this, "Termine", "Le compte a rebours est termine !");
}

void MainWindow::configurerTableau(QTableWidget *tab, QStringList& headers)
{
    tab->setRowCount(liste.size());
    tab->setColumnCount(headers.length());
    tab->setHorizontalHeaderLabels(headers);

    tab->setSelectionBehavior(QAbstractItemView::SelectRows);
    tab->setSelectionMode(QAbstractItemView::SingleSelection);

    tab->setVisible(false);
}

void MainWindow::retourOptions()
{
    ui->options_page->setVisible(true);
    ui->modification_page->setVisible(false);
    ui->ajout_page->setVisible(false);
    ui->supression_page->setVisible(false);
    ui->stock_page_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ==================== NAVIGATION (version 1 & 2) ====================

void MainWindow::on_accueil_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Accueil_page);
}

void MainWindow::on_Calendrier_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->calendrier_page);
    ui->tableau_calendrier->setVisible(true);
}

void MainWindow::on_historique_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->historique_page);
}

// void MainWindow::on_stock_btn_clicked()
// {
//     ui->stackedWidget->setCurrentWidget(ui->stock_page_2);
// }

// void MainWindow::on_boite_btn_clicked()
// {
//     ui->stackedWidget->setCurrentWidget(ui->boite_page);
// }

void MainWindow::on_medoc_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->info_medicament_page);
    ui->tableau_medoc->setVisible(true);
}

// ==================== GESTION DES MEDICAMENTS (version 1) ====================

void MainWindow::on_ajout_clicked()
{
    ui->options_page->setVisible(false);
    ui->ajout_page->setVisible(true);
    ui->supression_page->setVisible(false);
    ui->modification_page->setVisible(false);
    ui->stock_page_2->setVisible(false);

    ui->new_nom->clear();
    ui->new_type->setCurrentIndex(0);
    ui->new_dosage->setValue(0);
    ui->new_stock->setValue(0);
}

void MainWindow::on_supression_clicked()
{
    int currentRow = ui->tableau_medoc->currentRow();
    if (currentRow < 0 || currentRow >= liste.size())
    {
        QMessageBox::warning(this, "Selection requise", "Veuillez selectionner un medicament a supprimer.");
        return;
    }

    QString nomMedicament = liste[currentRow].nom;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer la suppression",
                                  QString("Voulez-vous vraiment supprimer le medicament '%1' ?").arg(nomMedicament),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        liste.removeAt(currentRow);
        updateTableauMedoc();
        QMessageBox::information(this, "Succes", "Medicament supprime avec succes.");
    }
}

void MainWindow::on_modification_clicked()
{
    int currentRow = ui->tableau_medoc->currentRow();
    if (currentRow < 0 || currentRow >= liste.size())
    {
        QMessageBox::warning(this, "Selection requise", "Veuillez selectionner un medicament a modifier.");
        return;
    }

    ui->options_page->setVisible(false);
    ui->modification_page->setVisible(true);
    ui->ajout_page->setVisible(false);
    ui->supression_page->setVisible(false);
    ui->stock_page_2->setVisible(false);

    Medicament &med = liste[currentRow];
    ui->modif_nom->setText(med.nom);
    ui->modif_type->setCurrentIndex(med.type - 1); // type: 1=gelule, 2=pilule, 3=sirop
    ui->modif_dosage->setValue(med.dosage);
    ui->modif_stock->setValue(med.stock);
    ui->modif_seuil->setValue(med.seuil);
    ui->modif_boite->setValue(med.boite);

    ui->modif_index->setText(QString::number(currentRow));
}

void MainWindow::on_annuler_btn_clicked()
{
    ui->options_page->setVisible(true);
    ui->ajout_page->setVisible(false);
    ui->supression_page->setVisible(false);
    ui->modification_page->setVisible(false);
}

void MainWindow::on_modif_confirm_btn_clicked()
{
    qDebug() << "Manova zavatra ny fotoana\n";
    int index = ui->modif_index->text().toInt();

    if (index < 0 || index >= liste.size())
    {
        QMessageBox::warning(this, "Erreur", "Index de medicament invalide.");
        return;
    }

    if (ui->modif_nom->text().isEmpty())
    {
        QMessageBox::warning(this, "Champ requis", "Veuillez saisir un nom pour le medicament.");
        return;
    }

    Medicament &med = liste[index];
    med.nom = ui->modif_nom->text();
    med.type = ui->modif_type->currentIndex() + 1;
    med.dosage = ui->modif_dosage->value();
    med.stock = ui->modif_stock->value();
    med.seuil = ui->modif_seuil->value();
    med.boite = ui->modif_boite->value();

    updateTableauMedoc();

    ui->options_page->setVisible(true);
    ui->modification_page->setVisible(false);

    QMessageBox::information(this, "Succes", "Medicament modifie avec succes.");
    sauvegarderMedicaments(liste);
}

void MainWindow::on_modif_annuler_btn_clicked()
{
    retourOptions();
}

void MainWindow::on_new_confirm_btn_clicked()
{
    if (ui->new_nom->text().isEmpty())
    {
        QMessageBox::warning(this, "Champ requis", "Veuillez saisir un nom pour le medicament.");
        return;
    }

    int newId = liste.size() + 1;

    Medicament nouveau(
        newId,
        ui->new_nom->text(),
        ui->new_type->currentIndex() + 1,
        ui->new_dosage->value(),
        ui->new_stock->value(),
        10, // seuil par defaut
        1   // boîte par defaut
        );

    liste.append(nouveau);
    updateTableauMedoc();

    ui->options_page->setVisible(true);
    ui->ajout_page->setVisible(false);

    QMessageBox::information(this, "Succes", "Medicament ajoute avec succes.");
    sauvegarderMedicaments(liste);
}

// ==================== MISE A JOUR DES TABLEAUX (version 1) ====================

void MainWindow::updateTableauMedoc()
{
    ui->tableau_medoc->setRowCount(liste.size());
    ui->tableau_medoc->clearContents();

    for(int i = 0; i < liste.size(); i++)
    {
        QString typeStr;
        switch(liste[i].type)
        {
        case 1: typeStr = "Gelule"; break;
        case 2: typeStr = "Pilule"; break;
        case 3: typeStr = "Sirop"; break;
        default: typeStr = "Inconnu";
        }

        ui->tableau_medoc->setItem(i, 0, new QTableWidgetItem(liste[i].nom));
        ui->tableau_medoc->setItem(i, 1, new QTableWidgetItem(typeStr));
        ui->tableau_medoc->setItem(i, 2, new QTableWidgetItem(QString::number(liste[i].dosage)));
        ui->tableau_medoc->setItem(i, 3, new QTableWidgetItem(QString::number(liste[i].stock)));
        ui->tableau_medoc->setItem(i, 4, new QTableWidgetItem(QString::number(liste[i].seuil)));
        ui->tableau_medoc->setItem(i, 5, new QTableWidgetItem(QString::number(liste[i].boite)));
    }

    etirerTableau(ui->tableau_medoc);
}

void MainWindow::updateTableauCalendrier()
{
    ui->tableau_calendrier->setRowCount(liste.size());
    ui->tableau_calendrier->clearContents();

    for (int i = 0; i < liste.size(); i++)
    {
        ui->tableau_calendrier->setItem(i, 0, new QTableWidgetItem(liste[i].nom));
        ui->tableau_calendrier->setItem(i, 1, new QTableWidgetItem(QString::number(liste[i].QtMatin)));
        ui->tableau_calendrier->setItem(i, 2, new QTableWidgetItem(QString::number(liste[i].QtMidi)));
        ui->tableau_calendrier->setItem(i, 3, new QTableWidgetItem(QString::number(liste[i].QtSoir)));
    }

    etirerTableau(ui->tableau_calendrier);
}

void MainWindow::etirerTableau(QTableWidget *tab)
{
    int nbColonnes = tab->columnCount();
    for (int i = 0; i < nbColonnes; i++)
    {
        tab->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

// ==================== GESTION DU CALENDRIER (version 1) ====================

void MainWindow::on_calendrier_modif_btn_clicked()
{
    int index = ui->tableau_calendrier->currentRow();

    if (index < 0 || index >= liste.size())
    {
        QMessageBox::warning(this, "Selection requise", "Veuillez selectionner un medicament a modifier.");
        return;
    }

    Medicament &med = liste[index];

    ui->calendrier_modification_page->setCurrentIndex(1);
    ui->spinMatin->setValue(med.QtMatin);
    ui->spinMidi->setValue(med.QtMidi);
    ui->spinSoir->setValue(med.QtSoir);

    ui->calendrier_modif_index->setText(QString::number(index));
}

void MainWindow::on_calendrier_confirmer_btn_clicked()
{
    int index = ui->calendrier_modif_index->text().toInt();
    int matin, midi, soir;

    if (index < 0 || index >= liste.size())
    {
        QMessageBox::warning(this, "Erreur", "Index de medicament invalide.");
        return;
    }

    matin = ui->spinMatin->value();
    midi = ui->spinMidi->value();
    soir = ui->spinSoir->value();

    Medicament &med = liste[index];
    med.setPrise(matin, midi, soir);

    updateTableauCalendrier();

    QMessageBox::information(this, "Succes", "Calendrier modifie avec succes.");
    sauvegarderMedicaments(liste);

    ui->calendrier_modification_page->setCurrentIndex(0);
}

void MainWindow::on_calendrier_annuler_btn_clicked()
{
    ui->calendrier_modification_page->setCurrentIndex(0);
}

// ==================== FONCTIONS DE LA VERSION 2 ====================

void MainWindow::updateTableau()
{
    // Fonction de la version 2, gardee pour compatibilite
    /*ui->tableau_medoc->setRowCount(0);
    for(int i=0; i<liste.size(); i++)
    {
        ui->Historique_tableau->setItem(i, 0, new QTableWidgetItem(liste[i].nom));
        ui->Historique_tableau->setItem(i, 1, new QTableWidgetItem(QString::number(liste[i].type)));
        ui->Historique_tableau->setItem(i, 2, new QTableWidgetItem(QString::number(liste[i].dosage)));
        ui->Historique_tableau->setItem(i, 3, new QTableWidgetItem(QString::number(liste[i].stock)));
        ui->Historique_tableau->setItem(i, 4, new QTableWidgetItem(QString::number(liste[i].seuil)));
        ui->Historique_tableau->setItem(i, 5, new QTableWidgetItem(QString::number(liste[i].boite)));
    }*/
}

void MainWindow::on_historique_calendarWidget_clicked(const QDate &date)
{
    historique_liste.clear();
    ui->Historique_tableau->setColumnCount(7);
    ui->Historique_tableau->setHorizontalHeaderLabels({"Type","Jour","Mois","Heure","Minute","Medicament","Quantite"});
    QFile fichier("/home/mialy/Downloads/Meduino_version1_3/Meduino/historique.log");

    if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!fichier.atEnd())
        {
            QString ligne = fichier.readLine().trimmed();
            QStringList lignes = ligne.split(":");

            if(lignes[1].toInt()==date.day() && lignes[2].toInt()==date.month())
            {
                History nouveau;
                nouveau.date=date;
                nouveau.type=lignes[0];
                nouveau.hour=lignes[3].toInt();
                nouveau.min=lignes[4].toInt();
                nouveau.nom_medoc=lignes[5];
                nouveau.quantite=lignes[6].toInt();
                historique_liste.append(nouveau);
            }

            qDebug() << ligne;
            qDebug() << date.toString();
        }
        update_tableau_historique(historique_liste);

        fichier.close();
    }
    else
    {
        qDebug() << "tsy mety misokatra meduino";
    }
}

void MainWindow::update_tableau_historique(QList <History> liste)
{
    ui->Historique_tableau->setRowCount(0);
    ui->Historique_tableau->clearContents();
    for(int i=0; i<liste.size(); i++)
    {
        ui->Historique_tableau->insertRow(i);
        ui->Historique_tableau->setItem(i, 0, new QTableWidgetItem(liste[i].type));
        ui->Historique_tableau->setItem(i, 1, new QTableWidgetItem(QString::number(liste[i].date.day())));
        ui->Historique_tableau->setItem(i, 2, new QTableWidgetItem(QString::number(liste[i].date.month())));
        ui->Historique_tableau->setItem(i, 3, new QTableWidgetItem(QString::number(liste[i].hour)));
        ui->Historique_tableau->setItem(i, 4, new QTableWidgetItem(QString::number(liste[i].min)));
        ui->Historique_tableau->setItem(i, 5, new QTableWidgetItem(liste[i].nom_medoc));
        ui->Historique_tableau->setItem(i, 6, new QTableWidgetItem(QString::number(liste[i].quantite)));
    }
}

void MainWindow::distribution_midi()
{
    qDebug() << "tafiditra distribution midi";
    compteur_medoc_distribution = 0;
    temps_distribution = 0;

    envoyer_medicament_midi();
}

void MainWindow::distribution_soir()
{
    qDebug() << "tafiditra distribution soir";
    compteur_medoc_distribution = 0;
    temps_distribution = 0;

    envoyer_medicament_soir();
}

void MainWindow::distribution_matin()
{
    qDebug() << "tafiditra distribution matin";
    compteur_medoc_distribution = 0;
    temps_distribution = 0;

    envoyer_medicament_matin();
}

void MainWindow::envoyer_medicament_matin()
{
    if (compteur_medoc_distribution >= liste.size())
    {
        qDebug() << "Distribution du matin terminee.";
        return;
    }

    QString commande = QString::number(liste[compteur_medoc_distribution].boite)+ "+" + QString::number(liste[compteur_medoc_distribution].QtMatin) + "\n";

    Arduino->write(commande.toUtf8());

    qDebug() << "Envoye a Arduino :" << commande;

    timer_distribution->start(5000);
}

void MainWindow::envoyer_medicament_midi()
{
    if (compteur_medoc_distribution >= liste.size())
    {
        qDebug() << "Distribution du midi terminee.";
        return;
    }

    QString commande = QString::number(liste[compteur_medoc_distribution].boite)+ "+" + QString::number(liste[compteur_medoc_distribution].QtMidi) + "\n";

    Arduino->write(commande.toUtf8());

    qDebug() << "Envoye a Arduino :" << commande;

    timer_distribution->start(5000);
}

void MainWindow::envoyer_medicament_soir()
{
    if (compteur_medoc_distribution >= liste.size())
    {
        qDebug() << "Distribution du soir terminee.";
        return;
    }

    QString commande = QString::number(liste[compteur_medoc_distribution].boite)+ "+" + QString::number(liste[compteur_medoc_distribution].QtSoir) + "\n";

    Arduino->write(commande.toUtf8());

    qDebug() << "Envoye a Arduino :" << commande;

    timer_distribution->start(5000);
}

void MainWindow::lire_donnees_arduino()
{
    QByteArray data = Arduino->readAll();
    donnees_arduino.clear();
    donnees_arduino = QString::fromUtf8(data);
    if (donnees_arduino == "TAKEN")
    {
        timer_distribution->stop();
        qDebug() << "Medicament pris !";

        if (fichier_historique->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(fichier_historique);

            out << "Check:"
                << QDate::currentDate().day() << ":"
                << QDate::currentDate().month() << ":"
                << QTime::currentTime().hour() << ":"
                << QTime::currentTime().minute() << ":"
                << liste[compteur_medoc_distribution].nom << ":"
                << "0\n";

            fichier_historique->close();
        }
        compteur_medoc_distribution++;
        envoyer_medicament_matin();
    }
}

void MainWindow::non_prise(Medicament medoc, int temps) //0:matin, 1:midi , 2:soir
{
    QFile fichier("/home/mialy/Projet/Meduino/historique.log");

    if (fichier.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&fichier);

        out << "Check:"
            << QDate::currentDate().day() << ":"
            << QDate::currentDate().month() << ":"
            << QTime::currentTime().hour() << ":"
            << QTime::currentTime().minute() << ":"
            << medoc.nom << ":"
            << "1\n";

        fichier.close();
    }
}

void MainWindow::on_restock_btn_clicked()
{
    int currentRow = ui->tableau_medoc->currentRow();
    if (currentRow < 0 || currentRow >= liste.size())
    {
        QMessageBox::warning(this, "Selection requise", "Veuillez selectionner un medicament a modifier.");
        return;
    }

    ui->options_page->setVisible(false);
    ui->modification_page->setVisible(false);
    ui->ajout_page->setVisible(false);
    ui->supression_page->setVisible(false);
    ui->stock_page_2->setVisible(true);

    ui->modif_stock->setValue(liste[currentRow].stock);
    ui->restock_index->setText(QString::number(currentRow));
}

void MainWindow::on_restock_confirmer_btn_clicked()
{
    int index = ui->restock_index->text().toInt();

    if (index < 0 || index >= liste.size())
    {
        QMessageBox::warning(this, "Erreur", "Index de medicament invalide.");
        return;
    }

    Medicament& med = liste[index];
    med.stock = ui->modif_stock->value();

    updateTableauMedoc();

    ui->options_page->setVisible(true);
    ui->stock_page_2->setVisible(false);

    QMessageBox::information(this, "Succes", "Stock modifie avec succes.");
    sauvegarderMedicaments(liste);
}

void MainWindow::on_restock_annuler_btn_clicked()
{
    retourOptions();
}

void MainWindow::on_new_annuler_btn_clicked()
{
    retourOptions();
}

void MainWindow::on_calendrier_temps_btn_clicked()
{
    ui->calendrier_modification_page->setCurrentWidget(ui->page_temps);
}

void MainWindow::on_temps_annuler_btn_clicked()
{
    ui->calendrier_modification_page->setCurrentWidget(ui->page);
}

void MainWindow::on_temps_confirmer_btn_clicked()
{
    QTime matin = ui->priseMatin->time();
    QTime midi = ui->priseMidi->time();
    QTime soir = ui->priseSoir->time();

    temps.clear();

    temps.append(matin);
    temps.append(midi);
    temps.append(soir);

    countDown->arreter();
    sauvegarderPrise(temps);

    temps = chargerPrise();
    restartCountDown();

    ui->calendrier_modification_page->setCurrentWidget(ui->page);
}

void MainWindow::verification_heure()
{
    QTime heureActuelle = QTime::currentTime();

    if (heureActuelle==ui->priseMatin->time())
    {
        qDebug() << "efa maraina ooo";
        distribution_matin();
    }
    else if(heureActuelle==ui->priseMidi->time())
    {
        qDebug() << "efa atoandro ooo";
        distribution_midi();
    }
    else if(heureActuelle==ui->priseSoir->time())
    {
        qDebug() << "efa hariva ooo";
        distribution_soir();
    }
}
