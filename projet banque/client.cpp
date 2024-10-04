#include <iostream>
#include <cstring>
#include "client.h"
#include "compte.h"

using namespace std;

Client::Client(string id, string lastName, string firstName, string phone) {
    CIN = id;
    nom = lastName;
    prenom = firstName;
    numero = phone;
}

string Client::ModifierNumero() {
    string nouveauNum;
    while (true) {
        system("CLS");
        cout << "\n\tMODIFICATION DE NUMERO\n";
        cout << "Tapez votre nouveau numéro (10 chiffres) : ";
        cin >> nouveauNum;

        if (nouveauNum.length() != 10) {
            cout << "NUMERO INCORRECT\n\n";
            system("pause");
        } else {
            system("CLS");
            cout << "\n\tVotre nouveau numéro est " << nouveauNum << ". Voulez-vous confirmer (y/n) ? ";
            string choix;
            cin >> choix;

            if (choix == "y") {
                numero = nouveauNum;
                cout << "\nNuméro changé !\n\n";
                system("pause");
                break;
            } else if (choix == "n") {
                cout << "RETOUR\n";
                system("pause");
            } else {
                cout << "Choix invalide. Retour.\n";
                system("pause");
                break;
            }
        }
    }
}

string Client::getNom() {
    return nom;
}

string Client::getCIN() {
    return CIN;
}

string Client::getNum() {
    return numero;
}

string Client::getPrenom() {
    return prenom;
}