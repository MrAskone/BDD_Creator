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

void DataParser::afficheEntityFromBase(int indice)
{
    m_base[indice].displayTable();
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

void DataParser::generatePreEntity(Table nomEntite, vector<string> colonnesCsvInitial)
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

        cout << "\nEntite created";
        cout << "\nLes indides de l'entite sont: \t\t";

        for ( int indice : myIndexes )
        {
            cout << indice << "; ";
        }

        cout << endl;

        vector<string> ligneTemp;
        bool duplicate;
        int ligneId (0);

        for ( int ligneCsv (0) ; ligneCsv < initialCsv.size() ; ligneCsv++ )
        {
            duplicate = false;

            for ( size_t ligneEntite (0) ; ligneEntite < newEntite.size() ; ligneEntite ++ )
            {

                ligneTemp.clear();

                for ( int colonne (0) ; colonne < myIndexes.size() ; colonne++ )
                {
                    ligneTemp.push_back( initialCsv [ ligneCsv ] [ myIndexes [ colonne ] ] );
                }

                if( ligneTemp == newEntite [ ligneEntite ] )        // si il y a un duple, on sort de la boucle des 'j'
                {
                    ligneEntite = newEntite.size();
                    duplicate = true;
                }
            }

            if( !duplicate )
            {
                newEntite.push_back(vector<string>(0));

                for ( int colonne (0) ; colonne < myIndexes.size() ; colonne++ )
                {
                    newEntite[ ligneId ].push_back ( initialCsv[ ligneCsv ][ myIndexes [colonne] ] );
                }
                ligneId ++;
            }
        }
    }

    nomEntite.setTable(newEntite);
    m_base.push_back(nomEntite);

    cout << "L'entite renseigne les attributs:\t";
    afficheEntities(nomEntite);
    cout << "\nL'entite a une taille de:\t\t" << newEntite.size() << " lignes" << endl;

    //    }

    //    else
    //    {
    //        cout << "Some colonnes weren't found in the Csv.\n";
    //    }

}

void DataParser::updateEntity(int tableIndex)
{

}

void DataParser::generateProperty(Table nomProperty, vector<string> colonnesCsvInitial)
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

    Table nom_ligne_nature;

    string latitude ("latitude_wgs84");
    string longitude ("longitude_wgs84");
    string code_ligne ("code_ligne");
    string nom ("nom");
    string nature ("nature");

    vector<string> colonnes_latitude_longitude { nom, code_ligne, nature, latitude, longitude};

    generateProperty ( nom_ligne_nature, colonnes_latitude_longitude );
}


void DataParser::generatePreEntities()
{

    Table ville;
    Table code_ligne;
    Table nom;
    Table nature;
    Table dept;

    vector<string> colonnes_ville { "ville", "dept" };
    vector<string> colonnes_code_ligne { "code_ligne" };
    vector<string> colonnes_nom { "nom", "cp", "ville" };
    vector<string> colonnes_nature { "nature" };
    vector<string> colonnes_dept { "dept" };


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



