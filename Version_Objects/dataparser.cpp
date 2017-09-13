#include "dataparser.h"

//#include <QFile>
//#include <QDir>
//#include <QTextStream>

//#include <QDebug>

#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <iostream>

using namespace std;

Table::Table()
{

}

//vector<QString> Table::colonnes() const
//{

//}

//int Table::nbColonnes() const
//{

//}

//-------------------------------------------------------------------

DataParser::DataParser()
{

}

bool DataParser::loadData(QString fichierUrl)
{

    QFile myFile (fichierUrl);
    Table temp;

    if (myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream fluxLecture (&myFile);

        while ( !fluxLecture.atEnd() )
        {
            qDebug() << fluxLecture.readLine();
        }
    }

    else
    {
        qDebug() << fichierUrl + " could not be opened.\n";
    }

    return 0;

}

void DataParser::generatePreEntity(QString nomEntite, std::vector<QString> colonnesCsvInitial)
{

}

void DataParser::updateEntity(int i)
{

}

void DataParser::generateProperty(QString nomProperty, std::vector<QString> colonnesCsvInitial)
{

}


//-------------------------------------------

void DataParser::updateEntities()
{

    for (int i(0) ; i < m_base.size() ; i++)
    {
        updateEntity(i);
    }

}

void DataParser::generateProperties()
{

    QString entite1 ("nom_ligne_nature");

    QString latitude ("latitude_wgs84");
    QString longitude ("longitude_wgs84");
    QString code_ligne ("code_ligne");
    QString nom ("nom");
    QString nature ("nature");

    vector<QString> colonnes_latitude_longitude { nom, code_ligne, nature, latitude, longitude};

    generateProperty ( entite1, colonnes_latitude_longitude );
}


void DataParser::generatePreEntities()
{

    QString ville ("ville");
    QString code_ligne ("code_ligne");
    QString nom ("nom");
    QString nature ("nature");
    QString cp ("cp");
    QString dept ("dept");

    vector<QString> colonnes_ville { ville, dept };
    vector<QString> colonnes_code_ligne { code_ligne };
    vector<QString> colonnes_nom { nom, cp, ville };
    vector<QString> colonnes_nature { nature };
    vector<QString> colonnes_dept { dept };


    generatePreEntity( ville, colonnes_ville );
    generatePreEntity( code_ligne, colonnes_code_ligne );
    generatePreEntity( nom, colonnes_nom );
    generatePreEntity( nature, colonnes_nature );
    generatePreEntity( dept, colonnes_dept );

}

void DataParser::generateMPD()
{
    updateEntities();
    generateProperties();
}

