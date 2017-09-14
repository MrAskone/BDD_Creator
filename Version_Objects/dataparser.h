#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <vector>
#include <string>

class Table
{
public:
    Table();

    void setTable(std::vector<std::vector<std::string>>);

    std::vector<std::vector<std::string>> getTable ();
    std::vector<std::string> getFirstLine ();

    std::vector<int> indexEntites (std::vector<std::string> nomEntites);

    void displayTable() const;
    void displayFirstLine() const;

//    int nbColonnes() const;
//    std::vector<std::string> colonnes() const;

private:
    std::vector<std::vector<std::string>> m_data;

};



class DataParser
{
public:
    DataParser();

    bool loadData(std::string fichierUrl);
    void generatePreEntities();
    void generateMPD();
    Table getInitialCsv();

    void afficheEntityFromBase(int indice);

    void afficheTable(Table myTable) const;
    void afficheEntities(Table myTable) const;

private:
    std::vector<Table> m_base;
    Table m_initialCsv;

        // dans le generatePreEntities
    void generatePreEntity(Table nomEntite, std::vector<std::string> colonnesCsvInitial);

        // dans le generateMPD
    void updateEntities();
    void updateEntity(size_t tableIndex);
        // &
    void generateProperties();
    void generateProperty( Table nomProperty, std::vector<std::string> colonnesCsvInitial);


};

#endif // DATAPARSER_H
