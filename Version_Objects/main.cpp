#include <QCoreApplication>
#include "dataparser.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataParser myCsv;
//    myCsv.loadData("gares_ferroviaires_de_tous_types_exploitees_ou_non.csv");
    myCsv.loadData("gares_ferroviaires_de_tous_types_exploitees_ou_non.csv");

    Table initialCsv (myCsv.getInitialCsv());
//    initialCsv.displayTable();

    myCsv.generatePreEntities();

    myCsv.generateMPD();
//    myCsv.afficheEntityFromBase(5);

    myCsv.generateAllCsv();

    return a.exec();
}
