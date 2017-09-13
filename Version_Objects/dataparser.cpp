#include "dataparser.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

#include <QDebug>
#include <iostream>

using namespace std;

Table::Table()
{

}

vector<string> Table::colonnes() const
{

}

int Table::nbColonnes() const
{

}

//-------------------------------------------------------------------

DataParser::DataParser()
{

}

bool DataParser::loadData(string nomFichier)
{

}

void DataParser::generatePreEntity(string nomEntite, std::vector<string> colonnesCsvInitial)
{

}

void DataParser::updateEntity(int i)
{

}

void DataParser::generateProperty(string nomProperty, std::vector<string> colonnesCsvInitial)
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

    string entite1 ("nom_ligne_nature");

    string latitude ("latitude_wgs84");
    string longitude ("longitude_wgs84");
    string code_ligne ("code_ligne");
    string nom ("nom");
    string nature ("nature");

    vector<string> colonnes_latitude_longitude { nom, code_ligne, nature, latitude, longitude};

    generateProperty ( entite1, colonnes_latitude_longitude );
}


void DataParser::generatePreEntities()
{

    string ville ("ville");
    string code_ligne ("code_ligne");
    string nom ("nom");
    string nature ("nature");
    string cp ("cp");
    string dept ("dept");

    vector<string> colonnes_ville { ville, dept };
    vector<string> colonnes_code_ligne { code_ligne };
    vector<string> colonnes_nom { nom, cp, ville };
    vector<string> colonnes_nature { nature };
    vector<string> colonnes_dept { dept };


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

