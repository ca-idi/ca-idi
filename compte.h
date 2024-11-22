#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include "client.h"

class Compte {
public:
    Compte(Client *client, const QString &id, double soldeInitial, const QString &rib);

    void Crediter(double montant);  // Crédite le compte
    void Debiter(double montant);   // Débite le compte
    void Virement(const QString &destinataireCIN, double montant);  // Effectuer un virement
    void InfoCompte();  // Afficher les informations du compte

    double getSolde() const;  // Récupérer le solde du compte
    QString getRIB() const;   // Récupérer le RIB du compte

private:
    Client *client;          // Pointeur vers l'objet Client
    QString id;              // ID du compte
    double solde;            // Solde du compte
    QString rib;             // RIB du compte
};

#endif // COMPTE_H
