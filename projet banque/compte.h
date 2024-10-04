#include <iostream>
#ifndef COMPTE_H
#define COMPTE_H

using namespace std;

class Compte {
private:
    string id;       // Correspond à ID
    double solde;    // Solde du compte
    string rib;      // RIB du compte

public: 
    Compte(string, double, string);

    string getRIB();       // Récupère le RIB
    double getSolde();     // Récupère le solde

    void MENU();           // Affiche le menu principal
    void Crediter();       // Fonction pour créditer le compte
    void Debiter();        // Fonction pour débiter le compte
    void Virement();       // Fonction pour effectuer un virement
    void InfoCompte();     // Affiche les informations du compte
};

#endif
