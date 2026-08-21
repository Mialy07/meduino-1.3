#ifndef COMPTEAREBOUR_H
#define COMPTEAREBOUR_H

#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>
#include <QFont>

class CompteARebour : public QObject
{
    Q_OBJECT

public:
    explicit CompteARebour(QObject *parent = nullptr);
    ~CompteARebour();

    void demarrer(int secondes);
    void demarrer(int jours, int heures, int minutes, int secondes);
    void arreter();
    void pause();
    void reprendre();
    void reinitialiser(int secondes);
    void reinitialiser(int jours, int heures, int minutes, int secondes);

    void setLabel(QLabel *label);

    int getTempsRestant() const;
    QString getTempsFormate() const;

    bool isActif() const;
    bool estEnPause() const;

signals:
    void tempsChange(const QString &temps);
    void tempsChange(int secondes);
    void termine();

private slots:
    void updateTimer();

private:
    void afficherTempsRestant();
    void initTimer();

    QTimer *timerCompteRebours;
    QLabel *labelAffichage;
    int secondesRestantes;
    int secondesInitiales;
    bool enPause;
};

#endif // COMPTEAREBOUR_H
