#ifndef PARSE_MANAGER_H
#define PARSE_MANAGER_H

#include <QStringList>
#include <vector>

class Parse_Manager
{
public:
    Parse_Manager();

    // Fonction pour Bases de Données
    QStringList getEntities();

    std::vector<QStringList> myTableCreator (const QStringList &listAttributes);
//    checkDuplicate (const std::vector<QStringList> &myTabSoFar, const QStringList &newEntry);


    // Accesseurs

    std::vector<QStringList> digitalCsv() const;
    std::vector<std::vector<QStringList>> allTables() const;

    // Manipulateurs
    void csvToVector(const QString &myUrl);



private:

    std::vector<QStringList> m_digitalCsv;
    std::vector<std::vector<QStringList>> m_allTables;


};

#endif // PARSE_MANAGER_H
