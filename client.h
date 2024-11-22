#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client {
public:
    Client(const QString &cin, const QString &nom, const QString &prenom, const QString &num);

    QString getCIN() const;        // Récupérer le CIN
    QString getNom() const;        // Récupérer le nom
    QString getPrenom() const;     // Récupérer le prénom
    QString getNum() const;        // Récupérer le numéro de téléphone
    void setNum(const QString &num); // Modifier le numéro de téléphone
    void ModifierNumero(const QString &newNum); // Modifier le numéro via une méthode dédiée

private:
    QString CIN;        // Correspond au CIN
    QString nom;        // Correspond au nom
    QString prenom;     // Correspond au prénom
    QString numero;     // Correspond au numéro de téléphone
};

#endif // CLIENT_H
