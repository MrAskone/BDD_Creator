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
        cout << "File could not be loaded";
    }

    return verif;

}

void DataParser::generatePrimaryKeyIndex(vector<vector<string>> &newEntite)     //OK
{
    vector<vector<string>> indexedEntity;

    for (int i(0) ; i < newEntite.size() ; i++)
    {
        indexedEntity.push_back(vector<string>(0));
        if ( i == 0)
        {
            indexedEntity[0].push_back("id_"+ newEntite[0][0]);
        }
        else
        {
            indexedEntity[i].push_back(to_string(i));
        }
        for (string valeur : newEntite[i])
        {
            indexedEntity[i].push_back(valeur);
        }
    }

    newEntite = indexedEntity;
    cout << "Indexes added to Entity\n";

}

void DataParser::generatePreEntity(Table nomEntite, vector<string> colonnesCsvInitial)      //OK
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

        generatePrimaryKeyIndex(newEntite);
        nomEntite.setTable(newEntite);
        m_base.push_back(nomEntite);

        cout << "L'entite renseigne les attributs:\t";
        afficheEntities(nomEntite);
        cout << "\nL'entite a une taille de:\t\t" << newEntite.size() << " lignes" << endl;
    }

    else
    {
        cout << "Some colonnes weren't found in the Csv.\n";
    }
}

void DataParser::insertForeignKey(Table &nomTable, size_t indexInCurrentTable, Table &entite, size_t indexInEntite)
{
    vector<vector<string>> maTable (nomTable.getTable());
    vector<vector<string>> uneEntite (entite.getTable());

    for ( int ligneOfTable (0) ; ligneOfTable < maTable.size() ; ligneOfTable++ )           // impossible d'utiliser for auto si on veut modifier maTable
    {
        for ( vector<string> ligneOfEntite : uneEntite)
        {
            if ( maTable [ligneOfTable] [indexInCurrentTable] == ligneOfEntite [indexInEntite] )
            {
                if( maTable [ligneOfTable] [indexInCurrentTable] == uneEntite[0][indexInEntite])
                {
                    maTable [ligneOfTable] [indexInCurrentTable] = uneEntite[0][indexInEntite] + "_FK";
                }

                else
                {
                    maTable [ligneOfTable] [indexInCurrentTable] = ligneOfEntite[0];
                }
            }
        }
    }
    nomTable.setTable(maTable);
}

void DataParser::updateEntity(Table &nomTable)
{
    cout << endl << nomTable.getTable()[0][1] << endl;



    for ( size_t indexInCurrentTable (0) ; indexInCurrentTable < nomTable.getFirstLine().size() ; indexInCurrentTable ++ )
    {
        for ( Table entite : m_base)
        {
            for ( size_t indexInForeignTable (0) ; indexInForeignTable < entite.getFirstLine().size() ; indexInForeignTable ++ )
            {
                if (entite.getFirstLine() [indexInForeignTable] == nomTable.getFirstLine() [indexInCurrentTable] &&
                        entite.getTable() != nomTable.getTable() &&
                        entite.getFirstLine() [indexInForeignTable] != nomTable.getFirstLine()[1])
                {
                    cout << entite.getFirstLine() [indexInForeignTable] << " was found in " << entite.getTable()[0][1]
                         << " in colonne number: " << indexInForeignTable << endl;

                    insertForeignKey(nomTable, indexInCurrentTable, entite, indexInForeignTable);
                }
            }
        }
    }
    cout << endl;
}

void DataParser::generateProperty(Table nomProperty, vector<string> colonnesCsvInitial)
{
    generatePreEntity(nomProperty, colonnesCsvInitial);
    updateEntity(m_base[m_base.size()-1]);
}


//-------------------------------------------

void DataParser::updateEntities()
{

    cout << "\nUpdating Entities\n";

    for (int i(0) ; i < m_base.size() ; i++)
    {
        updateEntity(m_base[i]);
    }

}

void DataParser::generateProperties()
{

    Table nom_ligne_nature;

    string latitude_longitude ("wgs84");
//    string latitude ("latitude_wgs84");
//    string longitude ("longitude_wgs84");
    string code_ligne ("code_ligne");
    string nom ("nom");
    string nature ("nature");

    vector<string> colonnes_latitude_longitude { latitude_longitude,/* latitude, longitude,*/  nom, code_ligne, nature };

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
    cout << "\ngenerating MPD\n";
    updateEntities();
    generateProperties();
}

Table DataParser::getInitialCsv()
{
    return m_initialCsv;
}



