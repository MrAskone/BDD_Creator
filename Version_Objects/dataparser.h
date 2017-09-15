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


private:
    std::vector<std::vector<std::string>> m_data;

};



class DataParser
{
public:
    DataParser();

    bool loadData(std::string fichierUrl);
    Table getInitialCsv();

    void generatePreEntities();

    void generateMPD();

    void afficheEntityFromBase(int indice);
    void afficheTable(Table myTable) const;
    void afficheEntities(Table myTable) const;

private:
    std::vector<Table> m_base;
    Table m_initialCsv;

        // dans le generatePreEntities
    void generatePrimaryKeyIndex(std::vector<std::vector<std::string> > &newEntite);
    void generatePreEntity(Table nomEntite, std::vector<std::string> colonnesCsvInitial);


        // dans le generateMPD
    void insertForeignKey (Table &nomTable, std::size_t indexInCurrentTable, Table &entite, std::size_t indexInEntite );
    void updateEntities();
    void updateEntity(Table &nomTable);
        // &
    void generateProperties();
    void generateProperty( Table nomProperty, std::vector<std::string> colonnesCsvInitial);


};

#endif // DATAPARSER_H
