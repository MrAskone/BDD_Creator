#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <vector>
#include <QString>

class Table
{
public:
    Table();

    std::vector<QString> colonnes() const;
    int nbColonnes() const;

private:
    std::vector<std::vector<QString>> m_data;

};



class DataParser
{
public:
    DataParser();

    bool loadData(QString fichierUrl);
    void generatePreEntities();
    void generateMPD();



private:
    std::vector<Table> m_base;
    Table initialCsv;

        // dans le generatePreEntities
    void generatePreEntity(QString nomEntite, std::vector<QString> colonnesCsvInitial);

        // dans le generateMPD
    void updateEntities();
    void updateEntity(int i);
        // &
    void generateProperties();
    void generateProperty( QString nomProperty, std::vector<QString> colonnesCsvInitial);


};

#endif // DATAPARSER_H
