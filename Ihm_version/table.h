#ifndef TABLE_H
#define TABLE_H

#include <QStringList>
#include <vector>


class Table
{
public:
    Table();


    void affiche() const;

    std::vector<QStringList> getEntite() const;
    void setEntite(const std::vector<QStringList> &entite);

    QString getNomEntite() const;
    void setNomEntite(const QString &nomEntite);

private:

    std::vector<QStringList> m_entite;
    QString m_nomEntite;

};

#endif // TABLE_H
