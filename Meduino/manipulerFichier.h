#ifndef MANIPULERFICHIER_H
#define MANIPULERFICHIER_H

#include <QList>
#include <QFile>
#include "medicament.h"

QList<Medicament> chargerMedicaments();
void sauvegarderMedicaments(QList <Medicament> &lisitra);
QList<QTime> chargerPrise();
void sauvegarderPrise(QList<QTime> &liste);

#endif // MANIPULERFICHIER_H
