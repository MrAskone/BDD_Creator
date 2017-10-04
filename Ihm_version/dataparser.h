#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include <QStringList>

class DataParser : public QObject
{
    Q_OBJECT
public:
    explicit DataParser(QObject *parent = nullptr);

    Q_PROPERTY(QStringList listeColonnes READ getListeColonnes WRITE setListeColonnes NOTIFY listeColonnesChanged)
    Q_PROPERTY(QStringList listeEntites READ getListeEntites WRITE setListeEntites NOTIFY listeEntitesChanged)
    Q_PROPERTY(QStringList contenuOfEntite READ getContenuOfEntite WRITE setContenuOfEntite NOTIFY contenuOfEntiteChanged)

    Q_PROPERTY(QString messageToUser READ getMessageToUser WRITE setMessageToUser NOTIFY messageToUserChanged)
    // Q_PROPERTY( type nomPropriete READ nomPropriete WRITE setNomPropriete NOTIFY nomProprieteChanged )
    //READ =>   fonction Pour Recuperer La Valeur
    //WRITE =>  fonction Pour Changer La Valeur
    //NOTIFY => fonction Pour Emettre Un Signal
    //QML:  Context.nomPropriete
    //Context.nomPropriete = "xxxx" (=> appelle la fonction WRITE)

signals:

    void listeColonnesChanged();
    void listeEntitesChanged();
    void contenuOfEntiteChanged();

    void messageToUserChanged();

public slots:

    void setListeColonnes( const QStringList &listeDesColonnes );
    QStringList getListeColonnes() const;

    void setListeEntites( const QStringList &listeDesEntites );
    QStringList getListeEntites() const;

    void setContenuOfEntite( const QStringList &contenuDeLEntite );
    QStringList getContenuOfEntite() const;

    void setMessageToUser(const QString &message);
    QString getMessageToUser() const;

private:

    QStringList m_listeColonnes;
    QStringList m_listeEntites;
    QStringList m_contenuOfEntite;

    QString m_messageToUser;


};

#endif // DATAPARSER_H
