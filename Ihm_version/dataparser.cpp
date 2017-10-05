#include "dataparser.h"

#include <iostream>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>

using namespace std;

DataParser::DataParser(QObject *parent) : QObject(parent)
{

}


void DataParser::loadFromCsv(QString urlOfCsv)
{
    urlOfCsv = urlOfCsv.remove(0,8);
    QFile myFile (urlOfCsv);

    if (myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream myStream(&myFile);
        vector<QStringList> monCsv;
        QStringList ligneQSL;
        QString uneLigne;

        while(!myStream.atEnd())
        {
            uneLigne = myStream.readLine();
            ligneQSL.clear();

            for (QString uneCase : uneLigne.split(';'))
            {
                ligneQSL.push_back(uneCase);
            }
            monCsv.push_back(ligneQSL);
        }
        m_csvInitial.setEntite(monCsv);

        myFile.close();
    }

    else
    {
        qDebug() << "File could not open\n";
    }
}


//////////////////////////////////
//////////////////////////////////
//// ----- Q_PROPERTIES ----- ////
//////////////////////////////////
//////////////////////////////////


void DataParser::setListeColonnes(const QStringList &listeDesColonnes)
{

    QString message;

    if (m_listeColonnes != listeDesColonnes)
    {
        m_listeColonnes = listeDesColonnes;
        emit listeColonnesChanged();

        message = "Nouvelle liste de colonnes chargée!";
    }

    else
    {
        message = "Liste de colonnes inchangée.";
    }

    setMessageToUser(message);

}


QStringList DataParser::getListeColonnes() const
{
    return m_listeColonnes;
}


void DataParser::setListeEntites(const QStringList &listeDesEntites)
{

    QString message;

    if (m_listeEntites != listeDesEntites)
    {
        m_listeEntites = listeDesEntites;
        emit listeEntitesChanged();

        message = "Nouvelle liste d'entités chargée!";
    }

    else
    {
        message = "Liste d'entités inchangée.";
    }

    setMessageToUser(message);

}

QStringList DataParser::getListeEntites() const
{
    return m_listeEntites;
}

void DataParser::setContenuOfEntite(const QStringList &contenuDeLEntite)
{
    QString message;

    if (m_contenuOfEntite != contenuDeLEntite)
    {
        m_contenuOfEntite = contenuDeLEntite;
        emit contenuOfEntiteChanged();

        message = "liste de colonnes de l'entité updated!";
    }

    else
    {
        message = "Liste de colonnes de l'entité inchangée.";
    }

    setMessageToUser(message);
}

QStringList DataParser::getContenuOfEntite() const
{
    return m_contenuOfEntite;
}


void DataParser::setMessageToUser(const QString &message)
{
    if (m_messageToUser != message)
    {
        m_messageToUser = message;
        emit messageToUserChanged();
    }
}

QString DataParser::getMessageToUser() const
{
    return m_messageToUser;
}



