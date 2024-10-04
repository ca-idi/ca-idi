#include <iostream>
#include "compte.h"
#include "client.h"

using namespace std;

Client client("FR-AAAC9876X123", "camil", "saidi", "0612345678");

Compte::Compte(string id, double soldeInitial, string rib) { // constructeur
    this->id = id; // Correction de la confusion
    solde = soldeInitial;
    this->rib = rib; // Correction de la confusion
}

double Compte::getSolde() {
    return solde;
}

string Compte::getRIB() {
    return rib;
}

void Compte::Crediter() { // CREDITER LE COMPTE
    system("CLS");
    cout << "\n\tCRÉDITER\n\n";
    cout << " 1. Déposer une somme\n";
    cout << " 2. Créditer un autre compte\n";
    cout << " 3. Retour\n\n Choix : ";
    unsigned int choix;
    cin >> choix;

    if (choix == 1) {
        system("CLS");
        cout << "\n\tDÉPOSER UNE SOMME\n\n";
        cout << "Combien voulez-vous déposer ?\n";
        double montant;
        cin >> montant;

        if (montant >= 0) {
            solde += montant;
            cout << "\n SOLDE AJOUTÉ\n\n Votre solde s'élève à " << solde << " €\n";
        } else {
            cout << "\n ERREUR : SOLDE NÉGATIF";
        }
        system("pause");
    } else if (choix == 2) {
        system("CLS");
        cout << "\n\tCRÉDITER UN AUTRE COMPTE\n\n";
        cout << "Quel compte voulez-vous créditer ? ENTREZ LE NOM\n";
        string autreCompte;
        cin >> autreCompte;
        system("CLS");
        cout << "Combien voulez-vous créditer ?\n";
        double montant;
        cin >> montant;

        if (montant >= 0) {
            solde += montant;
            cout << "\n SOLDE AJOUTÉ\n\n Votre solde s'élève à " << solde << " €\n";
        } else {
            cout << "\n ERREUR : SOLDE NÉGATIF";
        }
        system("pause");
    }
}

void Compte::Debiter() { // DEBITER LE COMPTE
    system("CLS");
    cout << "\n\tDÉBITER\n\n";
    cout << "Combien voulez-vous retirer ?\n";
    double montant;
    cin >> montant;

    if (montant >= 0) {
        solde -= montant;
        cout << "\n SOLDE RETIRÉ\n\n Votre solde s'élève à " << solde << " €\n";
    } else {
        cout << "\n ERREUR : SOLDE NÉGATIF";
    }
    system("pause");
}

void Compte::Virement() {
    system("CLS");
    cout << "Quel compte voulez-vous créditer ? ENTREZ LE NOM\n";
    string autreCompte;
    cin >> autreCompte;
    system("CLS");
    cout << "Montant du virement : ";
    double montant;
    cin >> montant;

    if (montant >= 0) {
        solde -= montant;
        cout << "\n VIREMENT EFFECTUÉ\n\n Votre solde s'élève à " << solde << " €\n\n";
    } else {
        cout << "\n ERREUR : SOLDE NÉGATIF";
    }
    system("pause");
}

void Compte::InfoCompte() {
    system("CLS");
    cout << "\n\tINFO COMPTE\n\n";
    cout << " 1. Info Personnelle\n";
    cout << " 2. Consulter son solde\n";
    cout << " 3. Consulter son RIB\n";
    cout << " 4. Modifier son numéro\n";
    cout << " 5. Retour\n\n";

    int choix;
    cin >> choix;
    switch (choix) {
    case 1:
        system("CLS");
        cout << "\n\tINFO PERSONNELLE\n\n";
        cout << "Nom : " << client.getNom() << endl;
        cout << "Prénom : " << client.getPrenom() << endl;
        cout << "Numéro de Téléphone : " << client.getNum() << endl;
        cout << "CIN : " << client.getCIN() << endl << endl;
        system("pause");
        break;
    case 2:
        system("CLS");
        cout << "\n\tSOLDE\n";
        cout << "Vous avez " << solde << " € sur votre compte\n\n";
        system("pause");
        break;
    case 3:
        system("CLS");
        cout << "\n\tRIB\n\n" << rib << endl << endl;
        system("pause");
        break;
    case 4:
        client.ModifierNumero();
        break;
    default:
        break;
    }
}

void Compte::MENU() {
    int cpt = 1;
    while (cpt != 0) {
        system("CLS");
        cout << "\n\t--- GESTION DU COMPTE DE " << client.getNom() << " " << client.getPrenom() << " ---\n\n";
        cout << " 1. Créditez votre compte\n";
        cout << " 2. Débitez votre compte\n";
        cout << " 3. Virement\n";
        cout << " 4. Info Compte\n\n";
        cout << " 5. Quitter \n\n Choix : ";

        int choix;
        cin >> choix;
        switch (choix) {
        case 1:
            Crediter();
            break;
        case 2:
            Debiter();
            break;
        case 3:
            Virement();
            break;
        case 4:
            InfoCompte();
            break;
        case 5:
            cpt = 0;
            break;
        default:
            system("CLS");
            cout << "\n\tERREUR\n\n";
            system("pause");
            break;
        }
    }
}