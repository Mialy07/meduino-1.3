#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "medicament.h"
#include "history.h"
#include "compteARebour.h"
#include <QTime>
#include <QFile>
#include <QSerialPort>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList <Medicament> liste;
    QList <QTime> temps;
    QList <History> historique_liste;
    QSerialPort *Arduino;
    QString donnees_arduino;

    QTimer *timer_distribution;
    int compteur_medoc_distribution;
    int temps_distribution;
    QFile *fichier_historique;

    QTimer *timer_verification_heure ;


    void restartCountDown();

    void configurerTableau(QTableWidget *tab, QStringList& headers);
    void retourOptions();

    // Fonctions de la version 1
    void updateTableauMedoc();
    void updateTableauCalendrier();
    void etirerTableau(QTableWidget *tab);

    // Fonctions de la version 2
    void updateTableau(); // Garde pour compatibilite mais peu utilise

    void non_prise(Medicament medoc, int temps);
    void envoyer_medicament_matin();
    void envoyer_medicament_midi();
    void envoyer_medicament_soir();

    void verification_heure();

private slots:
    // Navigation (version 1 & 2)
    void on_accueil_btn_clicked();
    void on_Calendrier_btn_clicked();
    void on_historique_btn_clicked();
    // void on_stock_btn_clicked();
    // void on_boite_btn_clicked();
    void on_medoc_btn_clicked();

    // Gestion des medicaments (version 1)
    void on_ajout_clicked();
    void on_supression_clicked();
    void on_modification_clicked();
    void on_annuler_btn_clicked();
    void on_modif_confirm_btn_clicked();
    void on_modif_annuler_btn_clicked();
    void on_new_confirm_btn_clicked();

    // Gestion du calendrier (version 1)
    void on_calendrier_modif_btn_clicked();
    void on_calendrier_confirmer_btn_clicked();
    void on_calendrier_annuler_btn_clicked();

    // Historique (version 2)
    void on_historique_calendarWidget_clicked(const QDate &date);
    void update_tableau_historique(QList <History> liste);

    // Arduino (version 2)
    void distribution_matin();
    void distribution_midi();
    void distribution_soir();
    void lire_donnees_arduino();

    // Restock (version 1)
    void on_restock_confirmer_btn_clicked();
    void on_restock_annuler_btn_clicked();
    void on_restock_btn_clicked();
    void on_new_annuler_btn_clicked();

    // Compte a rebours
    void on_temps_change(const QString &temps);
    void on_compte_termine();

    void on_calendrier_temps_btn_clicked();

    void on_temps_annuler_btn_clicked();

    void on_temps_confirmer_btn_clicked();

private:
    Ui::MainWindow *ui;
    CompteARebour* countDown;
};

#endif // MAINWINDOW_H
