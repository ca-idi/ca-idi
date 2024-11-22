#include "client.h"

Client::Client(const QString &cin, const QString &nom, const QString &prenom, const QString &num)
    : CIN(cin), nom(nom), prenom(prenom), numero(num) {}

QString Client::getCIN() const {
    return CIN;
}

QString Client::getNom() const {
    return nom;
}

QString Client::getPrenom() const {
    return prenom;
}

QString Client::getNum() const {
    return numero;
}

void Client::setNum(const QString &num) {
    numero = num;
}

void Client::ModifierNumero(const QString &newNum) {
    numero = newNum;  // Met à jour le numéro avec le nouveau numéro
}
