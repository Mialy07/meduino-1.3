#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QDate>

class History
{
public:
    QString type;
    QDate date;
    int hour;
    int min;
    QString nom_medoc;
    int quantite;
    History();
    ~History();
};

#endif // HISTORY_H
