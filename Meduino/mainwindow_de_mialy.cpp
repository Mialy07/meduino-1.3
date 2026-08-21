#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include "history.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ajout_page->setVisible(0);
    ui->options_page->setVisible(1);
    ui->supression_page->setVisible(1);
    liste=chargerMedicaments();
    qDebug() << "Nombre de médicaments :" << liste.size();

    ui->tableau_medoc->setRowCount(liste.size());
    ui->tableau_medoc->setColumnCount(6);

    ui->tableau_medoc->setHorizontalHeaderLabels({
        "Nom",
        "Type",
        "Dosage",
        "Stock",
        "Seuil",
        "Boîte"
    });
    updateTableau();

    Arduino= new QSerialPort();
    Arduino->setPortName("/dev/ttyACM0");
    Arduino->setBaudRate(QSerialPort::Baud9600);
    Arduino->open(QIODevice::ReadWrite);

    connect(Arduino, &QSerialPort::readyRead,this, &MainWindow::lire_donnees_arduino);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accueil_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Accueil_page);
}
void MainWindow::on_Calendrier_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->calendrier_page);
}
void MainWindow::on_historique_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->historique_page);
}
void MainWindow::on_stock_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stock_page);
}
void MainWindow::on_boite_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->boite_page);
}
void MainWindow::on_medoc_btn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->info_medicament_page);
}


QList<Medicament> MainWindow::chargerMedicaments()
{
    QList<Medicament> liste;

    QFile fichier("/home/mialy/Meduino/medicaments.json");

    if (!fichier.open(QIODevice::ReadOnly))
    {
        qDebug() << "Impossible d'ouvrir le fichier";
        qDebug() << "Chemin recherché :" << fichier.fileName();
        return liste;
    }

    QByteArray donnees = fichier.readAll();
    fichier.close();

    QJsonDocument document = QJsonDocument::fromJson(donnees);

    if (document.isNull() || !document.isArray())
    {
        return liste;
    }

    QJsonArray tableau = document.array();

    for (const QJsonValue &valeur : tableau)
    {
        QJsonObject objet = valeur.toObject();

        Medicament Medicament(
            objet["id"].toInt(),
            objet["nom"].toString(),
            objet["type"].toInt(),
            objet["dosage"].toInt(),
            objet["stock"].toInt(),
            objet["seuil"].toInt(),
            objet["boite"].toInt()
            );

        liste.append(Medicament);
    }

    return liste;
}


void MainWindow::on_ajout_clicked()
{
    ui->options_page->setVisible(0);
    ui->ajout_page->setVisible(1);
}


void MainWindow::on_supression_clicked()
{
    ui->supression_page->setVisible(1);
    ui->options_page->setVisible(0);
}


void MainWindow::on_new_confirm_btn_clicked()
{
    ui->options_page->setVisible(1);
    ui->ajout_page->setVisible(0);

    Medicament nouveau;
    nouveau.nom=ui->new_nom->text();

    liste.append(nouveau);

    updateTableau();
}

void MainWindow::updateTableau() {
    ui->tableau_medoc->setRowCount(0);
    for(int i=0;i<liste.size();i++)
    {
        ui->Historique_tableau->setItem(i,0,new QTableWidgetItem(liste[i].nom));
        ui->Historique_tableau->setItem(i,1,new QTableWidgetItem(QString::number(liste[i].type)));
        ui->Historique_tableau->setItem(i,2,new QTableWidgetItem(QString::number(liste[i].dosage)));
        ui->Historique_tableau->setItem(i,3,new QTableWidgetItem(QString::number(liste[i].stock)));
        ui->Historique_tableau->setItem(i,4,new QTableWidgetItem(QString::number(liste[i].seuil)));
        ui->Historique_tableau->setItem(i,5,new QTableWidgetItem(QString::number(liste[i].boite)));
    }
}

void MainWindow::on_historique_calendarWidget_clicked(const QDate &date)
{
    historique_liste.clear();
    ui->Historique_tableau->setColumnCount(7);
    ui->Historique_tableau->setHorizontalHeaderLabels({"Type","Jour","Mois","Heure","Minute","Medicament","Quantite"});
    QFile fichier("/home/mialy/Meduino/historique.log");

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
    for(int i=0;i<liste.size();i++)
    {
        ui->Historique_tableau->insertRow(i);
        ui->Historique_tableau->setItem(i,0,new QTableWidgetItem(liste[i].type));
        ui->Historique_tableau->setItem(i,1,new QTableWidgetItem(QString::number(liste[i].date.day())));
        ui->Historique_tableau->setItem(i,2,new QTableWidgetItem(QString::number(liste[i].date.month())));
        ui->Historique_tableau->setItem(i,3,new QTableWidgetItem(QString::number(liste[i].hour)));
        ui->Historique_tableau->setItem(i,4,new QTableWidgetItem(QString::number(liste[i].min)));
        ui->Historique_tableau->setItem(i,5,new QTableWidgetItem(liste[i].nom_medoc));
        ui->Historique_tableau->setItem(i,6,new QTableWidgetItem(QString::number(liste[i].quantite)));
    }
}


void MainWindow::on_historique_calendarWidget_activated(const QDate &date)
{
}

void MainWindow::communication_Arduino(QTime matin, QTime midi, QTime soir,QSerialPort *Arduino)
{
    /*QTime now= QTime::currentTime();
    if(now==matin)
    {

        distribution_matin(Arduino);
    }
    if(now==midi)
    {
        distribution_midi(Arduino);
    }
    if(now==soir)
    {
        distribution_soir(Arduino);
    }*/
}

void MainWindow::distribution_midi(QSerialPort *Arduino)
{

}
void MainWindow::distribution_soir(QSerialPort *Arduino)
{

}
void MainWindow::distribution_matin(QSerialPort *Arduino)
{
    /*int compteur=0;
    do
    {
        compteur++;
    }
    while(compteur<liste.size());*/
}

void MainWindow::lire_donnees_arduino()
{
    QByteArray data=Arduino->readAll();
    donnees_arduino.clear();
    donnees_arduino=QString::fromUtf8(data);
}
