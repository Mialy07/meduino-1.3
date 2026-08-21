#ifndef TABLEAU_H
#define TABLEAU_H

#include <QTableWidget>

class Tableau : private QTableWidget {
public:
    Tableau();
    ~Tableau();
    void updateTable();
};

#endif // TABLEAU_H
