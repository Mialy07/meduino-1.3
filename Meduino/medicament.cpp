#include "medicament.h"

Medicament::Medicament()
{
}

Medicament::~Medicament()
{
}

Medicament::Medicament(int id,QString nom,int type,int dosage,int stock,int seuil,int boite)
{
    this->id = id;
    this->nom = nom;
    this->dosage = dosage;
    this->type = type;
    this->stock = stock;
    this->boite = boite;
    this->seuil = seuil;
    this->QtMatin = 0;
    this->QtMidi = 0;
    this->QtSoir = 0;
}

void Medicament::setPrise(int matin, int midi, int soir) {
    this->QtMatin = matin;
    this->QtMidi = midi;
    this->QtSoir = soir;
}
