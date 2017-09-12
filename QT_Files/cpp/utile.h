#ifndef UTILE_H
#define UTILE_H

#include <QStringList>
#include <vector>

class Utile
{
    // Pas besoin de constructeurs puisque tous les membres son statiques

public:
    // 3 - Récupération de lignes d'un fichier
    static void setLinesInFile (const QString &url, const QStringList &sl);
    static QStringList getLinesFromFile(const QString &url);

    // 2 - Récupération de fichier d'un dossier
    static QStringList listFiles(QString dirname, QString filter = "*.*");
    static QStringList listFilesFromFileDialog(QString dirname, QString filter = "*.*");

    // 1 - Debug initiaux de tableaux d'entiers
    static void affichageTab(const std::vector<int>& tab);
    static void afficheTabTab (const std::vector<std::vector<int>>& tab);

    // Fonction pour Bases de Données
    static std::vector<QStringList> csvToVector(const QString &myUrl);
    static QStringList getEntities(const QString &myUrl);

    static std::vector<QStringList> myTableCreator (const QStringList &listAttributes);
//    static bool checkDuplicate (const vector<QStringList> &myTabSoFar, const QStringList &newEntry);

};

#endif // UTILE_H
