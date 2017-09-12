#include "utile.h"

#include <QCoreApplication>
#include <QFile>

#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path ("C:/Users/34011-58-11/Antoine_Afpa_QT/6-METTRE EN PLACE UNE BASE DE DONNEES/TP_Gares/TP openData-n° 1/gares_ferroviaires_de_tous_types_exploitees_ou_non.csv");

    QFile myFile (path);

    if (!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "nope!";
    }

    else
    {
        qDebug() << "step one clear!";
    }

    vector<QStringList> myDigitalCsv = Utile::csvToVector(path);

    QStringList myEntities = Utile::getEntities(myDigitalCsv);

    qDebug() << myEntities << endl << "loaded in vector";

    return a.exec();
}
