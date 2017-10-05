#include "table.h"

#include <QDebug>

using namespace std;

Table::Table() : m_nomEntite(""), m_entite()
{

}

void Table::affiche() const
{
    qDebug() << getEntite() << endl;
}


///////////////////////////////////////////
///////////////////////////////////////////
//// ----- GETTEURS & ACCESSEURS ----- ////
///////////////////////////////////////////
///////////////////////////////////////////


std::vector<QStringList> Table::getEntite() const
{
    return m_entite;
}

void Table::setEntite(const std::vector<QStringList> &entite)
{
    m_entite = entite;
}

QString Table::getNomEntite() const
{
    return m_nomEntite;
}

void Table::setNomEntite(const QString &nomEntite)
{
    m_nomEntite = nomEntite;
}
