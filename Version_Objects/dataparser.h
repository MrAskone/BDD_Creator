#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <vector>
#include <string>

typedef std::vector<std::string> ligne;
typedef std::vector<std::string> colonne;

class Table
{
public:
    Table();

    void setTable(std::vector<ligne>);

    std::vector<ligne> getTable ();
    ligne getFirstLine ();

    std::vector<int> indexEntites (ligne nomEntites);

    void displayTable() const;
    void displayFirstLine() const;


private:
    std::vector<ligne> m_data;

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
    void generatePrimaryKeyIndex(std::vector<ligne> &newEntite);
    void generatePreEntity(Table nomEntite, ligne nomsColonnesCsvInitial);


        // dans le generateMPD
    void insertForeignKey (Table &nomTable, std::size_t indexInCurrentTable, Table &entite, std::size_t indexInEntite );
    void updateEntities();
    void updateEntity(Table &nomTable);
        // &
    void generateProperty(Table nomProperty, ligne numColonneCsvInitial);
    void generateProperties();


};

#endif // DATAPARSER_H
