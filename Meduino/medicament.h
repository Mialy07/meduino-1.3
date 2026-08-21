#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QString>

class Medicament
{
public:

    Medicament();
    ~Medicament();

    Medicament(int id,QString nom,int type,int dosage,int stock,int seuil,int boite);

    int id;
    QString nom;
    int type;
    int dosage;
    int stock;
    int seuil;
    int boite;

    int QtMatin, QtMidi, QtSoir;
    void setPrise(int matin = 0, int midi = 0, int soir = 0);
};

#endif // MEDICAMENT_H
