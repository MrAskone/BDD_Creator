#include "dataparser.h"

//#include <QFile>
//#include <QDir>
//#include <QTextStream>

//#include <QDebug>

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <algorithm>

using namespace std;

Table::Table()
{

}

void Table::setTable(std::vector<ligne> newTable)
{
    m_data = newTable;
}

vector<ligne> Table::getTable()
{
    return m_data;
}

ligne Table::getFirstLine()
{
    return m_data[0];
}


vector<int> Table::indexEntites(ligne nomEntites)
{
    vector<int> myIndexes;

    for (size_t i(0) ; i < nomEntites.size() ; i++)
    {
        for (size_t j(0) ; j < m_data[0].size() ; j++)
        {
            if (nomEntites[i] == m_data[0][j])
            {
                myIndexes.push_back(j);
            }
        }
    }
    return myIndexes;
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
    for (colonne v : m_data)
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
    string stringFromCsv;

    vector<ligne> tableTemp;

    myFile.open(fichierUrl);

    if (myFile.is_open())
    {
        cout << fichierUrl << " successufully accessed.\n";

        while ( getline (myFile, stringFromCsv) )
        {
            istringstream streamLine(stringFromCsv);
            string valeurLigne;

            ligne lineFromCsv;

            while ( getline( streamLine, valeurLigne, ';' ) )
            {
                lineFromCsv.push_back(valeurLigne);
            }
            tableTemp.push_back( lineFromCsv );
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

bool DataParser::loadDataInColumns(string fichierUrl)
{
    bool verif = false;

    ifstream myFile;
    string stringFromCsv;

    int numColonne (0);

    vector<colonne> tableTemp;

    myFile.open(fichierUrl);

    if (myFile.is_open())
    {
        cout << fichierUrl << " successufully accessed.\n";

        bool firstLine (true);

        while ( getline (myFile, stringFromCsv) )
        {
            istringstream streamLine(stringFromCsv);
            string valeurCase;
            numColonne = 0;
            while ( getline( streamLine, valeurCase, ';' ) )
            {
                if (firstLine)
                {
                    tableTemp.push_back(colonne(0));
                }
                tableTemp[numColonne].push_back(valeurCase);

                cout << tableTemp[numColonne][tableTemp[numColonne].size()-1] << endl << endl;
                numColonne ++;
            }

            firstLine = false;
            //            tableTemp.push_back( colonneFromCsv );
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

void DataParser::generatePrimaryKeyIndex(vector<ligne> &newEntite)     // OK but could be improved.
// Try adding the index to the entity without copying the whole Table.
{
    vector<ligne> indexedEntity;

    for (size_t i(0) ; i < newEntite.size() ; i++)
    {
        indexedEntity.push_back(ligne(0));
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

void DataParser::generatePreEntity(Table nomEntite, ligne nomsColonnesCsvInitial)      //OK
{
    ligne listeAttributs = m_initialCsv.getFirstLine();
    vector<ligne> initialCsv = m_initialCsv.getTable();

    vector<ligne> newEntite;

    bool verif = true;

    for (size_t i(0) ; i < nomsColonnesCsvInitial.size() ; i++)
    {
        if( find(listeAttributs.begin(), listeAttributs.end(), nomsColonnesCsvInitial[i]) == listeAttributs.end() )
        {
            verif = false;
        }
    }

    if (verif)
    {
        vector<int> myIndexes = m_initialCsv.indexEntites(nomsColonnesCsvInitial);

        ligne ligneTemp;
        bool duplicate;

        for ( ligne ligneOfCsv : initialCsv )
        {
            duplicate = false;      // reinitialize duplicate to false to check for duplicates once again

            for ( ligne ligneEntite : newEntite )
            {

                ligneTemp.clear();  // reinitialize ligneTemp

                for ( int indexColonne : myIndexes)
                {
                    ligneTemp.push_back(  ligneOfCsv [indexColonne] );
                }

                duplicate = ( ligneTemp == ligneEntite );

                if (duplicate)
                {
                    break;
                }
            }

            if( !duplicate )
            {
                newEntite.push_back(ligne(0));

                for ( int indexColonne : myIndexes )
                {
                    newEntite[ newEntite.size() - 1 ].push_back (  ligneOfCsv [ indexColonne ] );
                }
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
    vector<ligne> maTable (nomTable.getTable());
    vector<ligne> uneEntite (entite.getTable());

    for ( size_t numLigneOfTable (0) ; numLigneOfTable < maTable.size() ; numLigneOfTable++ )           // impossible d'utiliser for auto si on veut modifier maTable
    {
        for ( ligne ligneOfEntite : uneEntite)
        {
            if ( maTable [numLigneOfTable] [indexInCurrentTable] == ligneOfEntite [indexInEntite] )
            {
                if( maTable [numLigneOfTable] [indexInCurrentTable] == uneEntite[0][indexInEntite])
                {
                    maTable [numLigneOfTable] [indexInCurrentTable] = uneEntite[0][indexInEntite] + "_FK";
                }

                else
                {
                    maTable [numLigneOfTable] [indexInCurrentTable] = ligneOfEntite[0];
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
                if (    entite.getFirstLine() [indexInForeignTable] == nomTable.getFirstLine() [indexInCurrentTable] &&
                        entite.getTable() != nomTable.getTable() &&
                        entite.getFirstLine() [indexInForeignTable] != nomTable.getFirstLine()[1]   )
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

void DataParser::generateProperty(Table nomProperty, ligne numColonneCsvInitial)
{
    generatePreEntity(nomProperty, numColonneCsvInitial);
    updateEntity(m_base[m_base.size()-1]);
}


//-------------------------------------------

void DataParser::updateEntities()
{

    cout << "\nUpdating Entities\n";

    for (size_t i(0) ; i < m_base.size() ; i++)
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



