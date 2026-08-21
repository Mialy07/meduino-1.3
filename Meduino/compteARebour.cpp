#include "compteARebour.h"

CompteARebour::CompteARebour(QObject *parent)
    : QObject(parent)
    , timerCompteRebours(nullptr)
    , labelAffichage(nullptr)
    , secondesRestantes(0)
    , secondesInitiales(0)
    , enPause(false)
{
    initTimer();
}

CompteARebour::~CompteARebour()
{
    if (timerCompteRebours)
    {
        timerCompteRebours->stop();
        delete timerCompteRebours;
    }
}

void CompteARebour::initTimer()
{
    timerCompteRebours = new QTimer(this);
    connect(timerCompteRebours, &QTimer::timeout, this, &CompteARebour::updateTimer);
}

void CompteARebour::demarrer(int secondes)
{
    secondesInitiales = secondes;
    secondesRestantes = secondes;
    enPause = false;
    afficherTempsRestant();
    timerCompteRebours->start(1000);
}

void CompteARebour::demarrer(int jours, int heures, int minutes, int secondes)
{
    int totalSecondes = jours * 86400 + heures * 3600 + minutes * 60 + secondes;
    demarrer(totalSecondes);
}

void CompteARebour::pause()
{
    if (timerCompteRebours->isActive() && !enPause)
    {
        timerCompteRebours->stop();
        enPause = true;
    }
}

void CompteARebour::reprendre()
{
    if (enPause && secondesRestantes > 0)
    {
        timerCompteRebours->start(1000);
        enPause = false;
    }
}

void CompteARebour::arreter()
{
    timerCompteRebours->stop();
    enPause = false;
    secondesRestantes = 0;
    afficherTempsRestant();
    emit termine();
}

void CompteARebour::reinitialiser(int secondes)
{
    timerCompteRebours->stop();
    enPause = false;
    demarrer(secondes);
}

void CompteARebour::reinitialiser(int jours, int heures, int minutes, int secondes)
{
    int totalSecondes = jours * 86400 + heures * 3600 + minutes * 60 + secondes;
    reinitialiser(totalSecondes);
}

void CompteARebour::setLabel(QLabel *label)
{
    labelAffichage = label;
    if (labelAffichage)
    {
        QFont font("Arial", 64, QFont::Bold);
        labelAffichage->setFont(font);
    }
}

int CompteARebour::getTempsRestant() const
{
    return secondesRestantes;
}

QString CompteARebour::getTempsFormate() const
{
    int jours = secondesRestantes / 86400;
    int heures = (secondesRestantes % 86400) / 3600;
    int minutes = (secondesRestantes % 3600) / 60;
    int secondes = secondesRestantes % 60;

    return QString("%1:%2:%3:%4")
        .arg(jours, 2, 10, QChar('0'))
        .arg(heures, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(secondes, 2, 10, QChar('0'));
}

bool CompteARebour::isActif() const
{
    return timerCompteRebours->isActive();
}

bool CompteARebour::estEnPause() const
{
    return enPause;
}

void CompteARebour::updateTimer()
{
    if (secondesRestantes > 0)
    {
        secondesRestantes--;
        afficherTempsRestant();
        emit tempsChange(secondesRestantes);
        emit tempsChange(getTempsFormate());
    }
    else
    {
        timerCompteRebours->stop();
        enPause = false;
        afficherTempsRestant();
        emit termine();
        if (labelAffichage)
        {
            QMessageBox::information(nullptr, "Termine", "Le compte a rebours est termine !");
        }
    }
}

void CompteARebour::afficherTempsRestant()
{
    if (labelAffichage)
    {
        labelAffichage->setText(getTempsFormate());
    }
}
