#include "manipulerFichier.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QList>

QFile fichierMedoc("/home/mialy/Downloads/Meduino_version1_3/Meduino/medicaments.json");
QFile fichierPrise("/home/mialy/Downloads/Meduino_version1_3/Meduino/prise.txt");

QList<Medicament> chargerMedicaments()
{
    QList<Medicament> liste;

    if (!fichierMedoc.open(QIODevice::ReadOnly))
    {
        qDebug() << "Impossible d'ouvrir le fichier";
        qDebug() << "Chemin recherche :" << fichierMedoc.fileName();
        return liste;
    }

    QByteArray donnees = fichierMedoc.readAll();
    fichierMedoc.close();

    QJsonDocument document = QJsonDocument::fromJson(donnees);

    if (document.isNull() || !document.isArray())
    {
        return liste;
    }

    QJsonArray tableau = document.array();

    for (const QJsonValue &valeur : tableau)
    {
        QJsonObject objet = valeur.toObject();

        Medicament med(
            objet["id"].toInt(),
            objet["nom"].toString(),
            objet["type"].toInt(),
            objet["dosage"].toInt(),
            objet["stock"].toInt(),
            objet["seuil"].toInt(),
            objet["boite"].toInt()
            );

        med.setPrise(
            objet["matin"].toInt(),
            objet["midi"].toInt(),
            objet["soir"].toInt()
            );
        liste.append(med);
    }

    return liste;
}

void sauvegarderMedicaments(QList <Medicament> &lisitra)
{
    if (!fichierMedoc.open(QIODevice::WriteOnly))
    {
        qDebug() << "Impossible d'ouvrir le fichier en ecriture";
        qDebug() << "Chemin :" << fichierMedoc.fileName();
        return;
    }

    QJsonArray tableau;

    for (const Medicament &med : lisitra)
    {
        QJsonObject objet;
        objet["id"] = med.id;
        objet["nom"] = med.nom;
        objet["type"] = med.type;
        objet["dosage"] = med.dosage;
        objet["stock"] = med.stock;
        objet["seuil"] = med.seuil;
        objet["boite"] = med.boite;
        objet["matin"] = med.QtMatin;
        objet["midi"] = med.QtMidi;
        objet["soir"] = med.QtSoir;

        tableau.append(objet);
    }

    QJsonDocument document(tableau);
    QByteArray donnees = document.toJson(QJsonDocument::Indented);

    fichierMedoc.write(donnees);
    fichierMedoc.close();

    qDebug() << "Donnees sauvegardees avec succes !";
}

QList<QTime> chargerPrise()
{
    QList<QTime> liste;

    if (!fichierPrise.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier de prise";
        qDebug() << "Chemin recherche :" << fichierPrise.fileName();
        return liste;
    }

    QTextStream in(&fichierPrise);
    while (!in.atEnd())
    {
        QString ligne = in.readLine().trimmed();
        if (ligne.isEmpty()) continue;

        QStringList lignes = ligne.split(":");
        if (lignes.size() < 4) continue;

        int heure = lignes[1].toInt();
        int minute = lignes[2].toInt();
        int seconde = lignes[3].toInt();

        if (lignes[0] == "soir")
        {
            heure += 12;
        }

        QTime temps(heure, minute, seconde);
        if (temps.isValid()) {
            liste.append(temps);
        }
    }

    fichierPrise.close();
    qDebug() << "Prise chargees :" << liste.size();
    return liste;
}

void sauvegarderPrise(QList<QTime> &liste)
{
    if (!fichierPrise.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Impossible d'ouvrir le fichier";
        qDebug() << "Chemin recherche :" << fichierPrise.fileName();
        return;
    }

    if (liste.size() < 3) {
        qDebug() << "La liste doit contenir au moins 3 elements (matin, midi, soir)";
        fichierPrise.close();
        return;
    }

    QTime matin = liste[0];
    QTime midi = liste[1];
    QTime soir = liste[2];

    QTextStream out(&fichierPrise);

    out << "matin:" << matin.hour() << ":" << matin.minute() << ":" << matin.second() << ":AM\n";
    out << "midi:" << midi.hour() << ":" << midi.minute() << ":" << midi.second() << ":PM\n";
    out << "soir:" << (soir.hour() - 12) << ":" << soir.minute() << ":" << soir.second() << ":PM\n";

    fichierPrise.close();
    qDebug() << "Fichier de prise sauvegarde !";
}
