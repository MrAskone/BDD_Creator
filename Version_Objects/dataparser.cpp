#include "dataparser.h"

//#include <QFile>
//#include <QDir>
//#include <QTextStream>

//#include <QDebug>

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;

Table::Table()
{

}

void Table::setTable(vector<vector<string>> newTable)
{
    m_data = newTable;
}

vector<string> Table::getFirstLine()
{
    return m_data[0];
}


vector<int> Table::indexEntites(vector<string> nomEntites)
{
    vector<int> myIndexes;

    for (int i(0) ; i < nomEntites.size() ; i++)
    {
        for (int j(0) ; j < m_data[0].size() ; j++)
        {
            if (nomEntites[i] == m_data[0][j])
            {
                myIndexes.push_back(j);
            }
        }
    }
    return myIndexes;
}


vector<vector<string>> Table::getTable()
{
    return m_data;
}

void Table::displayFirstLine() const
{
    for ( string str : m_data[0])
    {
        cout << str << ";";
    }
}

void Table::displayTable() const
{
    for (vector<string> v : m_data)
    {
        for ( string str : v)
        {
            cout << str << ";";
        }
        cout << "\n";
    }
}


//vector<string> Table::colonnes() const
//{

//}

//int Table::nbColonnes() const
//{

//}

//-------------------------------------------------------------------

DataParser::DataParser()
{

}

void DataParser::afficheTable(Table myTable) const      //ok
{
    myTable.displayTable();
}

void DataParser::afficheEntities(Table myTable) const   //ok
{
    myTable.displayFirstLine();
}

bool DataParser::loadData(string fichierUrl)            // OK
{

    bool verif = false;

    ifstream myFile;
    string line;

    vector<vector<string>> tableTemp;

    myFile.open(fichierUrl);

    if (myFile.is_open())
    {
        cout << fichierUrl << " successufully accessed.\n";

        while ( getline (myFile, line) )
        {
            istringstream streamLine(line);
            string valeurColonne;

            vector<string> colonne;

            while ( getline( streamLine, valeurColonne, ';' ) )
            {
                colonne.push_back(valeurColonne);
            }
            tableTemp.push_back( colonne );
        }

        m_initialCsv.setTable(tableTemp);

        myFile.close();

        verif = true;

    }

    else
    {
        cout << "wtf";
    }

    return verif;

}

void DataParser::generatePreEntity(string nomEntite, vector<string> colonnesCsvInitial)
{
    vector<string> listeAttributs = m_initialCsv.getFirstLine();
    vector<vector<string>> initialCsv = m_initialCsv.getTable();

    vector<vector<string>> newEntite;

    bool verif = true;

        for (int i(0) ; i < colonnesCsvInitial.size() ; i++)
        {
            if( find(listeAttributs.begin(), listeAttributs.end(), colonnesCsvInitial[i]) == listeAttributs.end())
            {
                verif = false;
            }
        }

    if (verif)
    {
        vector<int> myIndexes = m_initialCsv.indexEntites(colonnesCsvInitial);

        for ( int i(0) ; i < initialCsv.size() ; i++ )
        {
            for ( int j(0) ; j < newEntite.size() ; j++ )
            {
//                for ( int k(0) ; )
            }
        }

        if ()

    }


}

void DataParser::updateEntity(int i)
{

}

void DataParser::generateProperty(string nomProperty, vector<string> colonnesCsvInitial)
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

Table DataParser::getInitialCsv()
{
    return m_initialCsv;
}


