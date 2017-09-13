#include "Parse_Manager.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

#include <QDebug>
#include <iostream>

using namespace std;

Parse_Manager::Parse_Manager()
{

}

vector<QStringList> Parse_Manager::digitalCsv() const
{
    return m_digitalCsv;
}

vector<vector<QStringList>> Parse_Manager::allTables() const
{
    return m_allTables;
}




void Parse_Manager::csvToVector(const QString &myUrl)
{
    m_digitalCsv.clear();

    QFile monCsv(myUrl);

    QStringList tempList;

    if (monCsv.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream fluxLecture(&monCsv);

        while ( !fluxLecture.atEnd() )
        {
            tempList << fluxLecture.readLine();
        }

        qDebug() << tempList.length();

        m_digitalCsv.resize(tempList.length());

        for ( int i (0) ; i < tempList.length() ; i++ )
        {
            m_digitalCsv[i] << tempList[i];
        }

        qDebug() << m_digitalCsv[0];
    }

    else
    {
        qDebug() << "could not open file: " << myUrl;
    }

}

QStringList Parse_Manager::getEntities()
{
    QStringList myEntities = m_digitalCsv[0];

    return myEntities;
}

vector<QStringList> Parse_Manager::myTableCreator (const QStringList &listAttributes)
{
    bool erreur(0);
    vector<int> attributeIndex(0);

    for (int p(0) ; p < listAttributes.length() ; p++)
    {
        int index = m_digitalCsv[0].lastIndexOf(listAttributes[p]);

        if ( index != -1)
        {
            qDebug() << listAttributes[p] << "est un attribut present";
            attributeIndex.push_back(index);
        }

        else
        {
            qDebug() << listAttributes[p] << "n'est pas present dans la liste d'attributs.";
            erreur = 1;
        }
    }

    vector<QStringList> newTable(0);
    QStringList temp;
    int tempIndex;
    int num_identifiant(0);


    if(!erreur)
    {


        for ( int i (0) ; i < m_digitalCsv.size() ; i++ )
        {
            for ( int j(0) ; j < attributeIndex.size() ; j++ )
            {
                tempIndex = attributeIndex[j];
                temp << m_digitalCsv[i][tempIndex];
            }

//            if (!newTable.find(temp))
//            {
                newTable.resize(newTable.size()+1);

                newTable[num_identifiant] << ;
//            }
                num_identifiant++;
            temp.clear();
        }
    }
    return newTable;
}

//bool Parse_Manager::checkDuplicate (const vector<QStringList> &myTabSoFar, const QStringList &newEntry)
//{

//}
