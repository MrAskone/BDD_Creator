#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <vector>
#include <string>

class Table
{
public:
    Table();

    std::vector<std::string> colonnes() const;
    int nbColonnes() const;

private:
    std::vector<std::vector<std::string>> m_data;

};



class DataParser
{
public:
    DataParser();

    bool loadData(std::string nomFichier);
    void generatePreEntities();
    void generateMPD();



private:
    std::vector<Table> m_base;

        // dans le generatePreEntities
    void generatePreEntity(std::string nomEntite, std::vector<std::string> colonnesCsvInitial);

        // dans le generateMPD
    void updateEntities();
    void updateEntity(int i);
        // &
    void generateProperties();
    void generateProperty( std::string nomProperty, std::vector<std::string> colonnesCsvInitial);


};

#endif // DATAPARSER_H
