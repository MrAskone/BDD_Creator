#include "wmanager.h"
#include <QApplication>

#include <QDir>
#include <QFileDialog>
#include <iostream>

#include <QFile>
#include <QTextStream>

using namespace std;
WManager::WManager(QObject *parent) : QObject(parent)
{
    qDebug() << "WManager::instance construite ";

    // 1/2 Initialisation des valeurs pour le QML avant chargement du fichier
    // propriétés simples
    setPropString(" ");//.... in .cpp 1/3  : Rajout propriété du Context QML
    setLargeurBouton(190);
}

void WManager::load()
{
    QList<QString> fichiersQML;
    // Chargement d'une ou plusieurs fenêtres avec pour fichiers sources :
    fichiersQML << QString("interface"); // pour une source "evaluation.qml"

    for( int t=0 ; t<1 ; t++)
    {
        makeQMLtab(fichiersQML[t] );
        std::cout << "tab " << t << " ready." << std::endl;
    }
}

void WManager::makeQMLtab(QString nomFichierQMLsansExtension)
{
    QQuickView* view = new QQuickView();
    quickViews.push_back(view);

    view->setResizeMode( QQuickView::SizeRootObjectToView);
    view->setGeometry(QRect(200, 200, 950, 650));

    // Mise en mémoire des objets pour communiquer avec le QML (avant le chargement de la page)
    m_QMLcontexts << view->engine()->rootContext();

    m_qmlContext = m_QMLcontexts.at(0);
    m_qmlContext->setContextProperty("Context", this->getInstance());
    //

    // 2/2 Initialisation des valeurs pour le QML avant chargement du fichier
    // Initialisation des modèles (même vides)
    QStringList directoryList(" ");
    updateQML_model("attributesListModel", directoryList);

    QStringList fileList(" ");
    updateQML_model("ListModel", fileList);

    QStringList extensionList(" ");
    updateQML_model("extensionListModel", extensionList);
    //

    QString repertoireProjet = getRepertoireProjet();

    QString fichierQML = repertoireProjet + QString("/qml/") + nomFichierQMLsansExtension + QString(".qml");
    std::cout  << "charge le fichier QML : " << fichierQML.toLatin1().constData() << std::endl;

    // Chargement du fichier QML
    view->setSource( QUrl::fromLocalFile(fichierQML) ) ;
    view->show();
}

// Permet d'afficher des informations sur les répertoires du projet en cours
// Dans le paramétrage du projet "Project", necessite que "shadow build" soit décoché
QString WManager::getRepertoireProjet(bool trace)//false
{
    QString repertoireduFichierApplication( qApp->applicationFilePath() );
    if( trace)
        std::cout << "qApp->applicationFilePath() = "<< repertoireduFichierApplication.toLatin1().constData() << std::endl;

    QDir fichier(repertoireduFichierApplication);
    fichier.cdUp() ;
    fichier.cdUp() ;
    if( trace)
        std::cout << "qApp->applicationName() = "<< qApp->applicationName().toLatin1().constData() << std::endl;

    fichier.cd(qApp->applicationName());
    QString repertoireProjet  = fichier.absolutePath() ;
    if( trace)
        std::cout  << "repertoireProjet : " << repertoireProjet.toLatin1().constData() << std::endl;

    return repertoireProjet;
}

void WManager::displayInitialInformations()
{
    getRepertoireProjet(true);
}

//.............................................................
// Mise à jour du modele de xxxxView du QML (du type Context.nomModele)
void WManager::updateQML_model(QString nomModele, QStringList sl)
{
    m_qmlContext = m_QMLcontexts.at(0);
    m_qmlContext->setContextProperty(nomModele, QVariant::fromValue( sl ) );
}

void WManager::testActionQML(int i)
{
    qDebug() << "WManager::testActionQML : " << i;
}


// Fonction appelée à partir du QML pour exécuter une action C++
void WManager::sendActionToCpp(QString nomAction, QString parametre/*=""*/)
{

    qDebug() << "WManager::sendActionfromQML : nomAction = " << nomAction;
    qDebug() << "WManager::sendActionfromQML : parametre = " << parametre;

    if ( nomAction == "displayAttributeList" )                         // Add to List Button
    {
        string path = parametre.remove(0, 8);

        if (monCsv.loadData(path))
        {

        }



    }
//    else if ( nomAction == "deleteLast" )                   // Delete last Directory Button
//    {
//        if ( directoryList.length() > 0)
//        {
//            directoryList.pop_back();
//            updateQML_model("myListModel" , directoryList);
//            setPropString ("Last entry deleted");
//        }
//        else
//        {
//            setPropString("List is already empty.");
//        }                                                   // End of Delete last Directory
//    }

//    else if( nomAction == "displayAttributeList")                // Display File List Button
//    {
//        if (directoryList.length() > 0)
//        {
//            for (int i(0); i < directoryList.size(); i++)
//            {
//                QString path(directoryList[i]);
//                QDir dirTemp(path);

//                foreach(QFileInfo item, dirTemp.entryInfoList ())
//                {
//                    QString pathFile = item.absoluteFilePath();
//                    int pos = pathFile.size() - pathFile.lastIndexOf(".");

//                    if (item.isFile() && !fileList.contains(pathFile))
//                    {
//                        fileList << pathFile;

//                        if (!extensionList.contains(pathFile.right(pos)) && pos < pathFile.size())
//                        {
//                            extensionList << pathFile.right(pos);
//                        }
//                    }
//                }
//            }
//            qDebug() << "File List updated";
//            updateQML_model("myFileListModel", fileList);
//            setPropString("File List updated!");
//            qDebug() << "Extension List updated";
//            updateQML_model("extensionListModel", extensionList);

//        }                                                   // End of Display File List

//        else
//        {
//            setPropString("Error: no directory");
//        }
//    }

//    else if(nomAction == "extensionSelected")               // File List shows Combo Box extension files only
//    {                                                       // Code is not opti: all files are reloaded.
//        fileList.clear();                                   //Need to find way to change display only

//        for (int i(0); i < directoryList.size(); i++)
//        {
//            QString path(directoryList[i]);
//            QDir dirTemp(path);

//            foreach(QFileInfo item, dirTemp.entryInfoList ())
//            {
//                QString pathFile = item.absoluteFilePath();

//                if (pathFile.contains(parametre) && !fileList.contains(pathFile) )
//                {
//                    fileList << pathFile;
//                }
//            }
//        }
//        qDebug() << "File List updated";
//        updateQML_model("myFileListModel", fileList);
//        setPropString("File List updated!");
//    }

//    else if(nomAction == "combineFiles")
//    {
//        QString dirPath = "C:/_Projects/CombinedFiles";     // Creates Folder for the combined file
//        QDir dir (dirPath);

//        if (!dir.exists())
//        {
//            qDebug() << "Creating" << dirPath << "directory";
//            dir.mkpath(dirPath);
//        }

//        else
//        {
//            qDebug() << dirPath << "directory already exists";
//        }

//        QFile fileCombined("C:/_Projects/CombinedFiles/combinedFiles.csv");
//        //         Creates file
//        if(!fileCombined.open(QIODevice::WriteOnly|QIODevice::Text))
//        {
//            qDebug() << "Could not open file for writing";
//            return;
//        }

//        for (int i(0) ; i < fileList.size() ; i++)
//        {

//            QFile filesToCombine(fileList[i]);

//            if(!filesToCombine.open(QIODevice::ReadOnly|QIODevice::Text))
//            {
//                qDebug() << "Could not open file for reading";
//                return;
//            }

//            QTextStream out(&filesToCombine);
//            QString copiedData = out.readAll();

//            QStringList mapDeData = copiedData.split("\n");



//            QTextStream in(&fileCombined);
//            in << "FILE NAME: " << fileList[i] << endl;
//            in << "--------------------------------------------------------------------"
//                  "-----------------------------------------" << endl;
//            in << mapDeData[0];

//            //            for (int i (0); i < mapDeData.length() ; i++)
//            //            {
//            //                if (i%2 == 0)
//            //                {
//            //                    in << mapDeData[i];
//            //                }
//            //            }
//            qDebug() << fileList[i] << " was copied successfully.";

//            QStringList nomsDesEntites = mapDeData[0].split(";");

//            for (int p(0) ; p < nomsDesEntites.length() ; p++)
//            {
//                QString reference (nomsDesEntites[p]);
//                QFile newCSV("C:/_Projects/CombinedFiles/"+reference+".csv");
//                if(!newCSV.open(QIODevice::WriteOnly|QIODevice::Text))
//                {
//                    qDebug() << "Could not open" << nomsDesEntites[p] << "for reading";
//                    return;
//                }
//                QTextStream entityInfo(&newCSV);
//                entityInfo << p;
//                newCSV.close();
//            }


//            setPropString ("combinedFiles.txt created");
//            filesToCombine.close();
//        }
//        fileCombined.close();
//    }

//    else if(nomAction == "removeSingleFile")
//    {
//        int pos = parametre.toInt();
//        QString removeIt = fileList[pos];
//        fileList.removeAt(pos);
//        updateQML_model("myFileListModel", fileList);
//        qDebug() << removeIt;
//    }

//    else if(nomAction == "clearAllFiles")                   // Clear File List Button
//    {
//        fileList.clear();
//        extensionList.clear();
//        setPropString("File list cleared");
//        updateQML_model("myFileListModel", fileList);
//        updateQML_model("extensionListModel", extensionList);
//    }                                                       // End of Clear File List

//    else if (nomAction == "append")
//    {
//        QString dirPath = "C:/_Projects/CombinedFiles";     // Creates Folder for the combined file
//        QDir dir (dirPath);

//        int pos = parametre.toInt();

//        if (!dir.exists())
//        {
//            qDebug() << "Cannot Find Directory:" << dirPath;

//            return;
//        }
//        else
//        {
//            qDebug() << dirPath << " Directory found";
//        }


//        QFile fileCombined("C:/_Projects/CombinedFiles/combinedFiles.txt");
//        //         Creates file
//        if(!fileCombined.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text))
//        {
//            qDebug() << "Could not open file for writing";
//            return;
//        }

//        else
//        {
//            qDebug() << "File ready for writing";
//        }

//        QFile fileToAppend (fileList[pos]);

//        if(!fileToAppend.open(QIODevice::ReadOnly|QIODevice::Text))
//        {

//            qDebug() << "Could not open file for reading";
//            return;

//        }

//        else
//        {
//            QTextStream out(&fileToAppend);
//            QString copiedData = out.readAll();

//            QTextStream in(&fileCombined);
//            in << "FILE NAME: " << fileList[pos] << endl;
//            in << "--------------------------------------------------------------------"
//                  "-----------------------------------------" << endl;
//            in << copiedData;

//            qDebug() << fileList[pos] << " was copied successfully.";

//            fileToAppend.close();
//        }
//        fileCombined.close();
//        setPropString ("combinedFiles.txt updated");
//    }

}


//................ Rajout d'une propriété du Context pour le QML .............
//.... in .cpp 2/3  : Rajout propriété du Context QML
void WManager::setPropString(const QString &a) {
    if (a != m_propString) {
        m_propString = a;
        emit propStringChanged();
    }
}

void WManager::setLargeurBouton(const int &i) {
    if (i != m_largeurBouton) {
        m_largeurBouton = i;
        emit largeurBoutonChanged();
    }
}


//.... in .cpp 3/3  : Rajout propriété du Context QML
QString WManager::propString_r() const {
    return m_propString;
}

int WManager::largeurBouton() const {
    return m_largeurBouton;
}
