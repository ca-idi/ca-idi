#include "compte.h"
#include <QMessageBox>

Compte::Compte(Client *client, const QString &id, double soldeInitial, const QString &rib)
    : client(client), id(id), solde(soldeInitial), rib(rib) {}

void Compte::Crediter(double montant) {
    if (montant > 0) {
        solde += montant;
        QMessageBox::information(nullptr, "Crédit", QString("Votre solde a été crédité de %1. Nouveau solde: %2").arg(montant).arg(solde));
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Le montant doit être positif.");
    }
}

void Compte::Debiter(double montant) {
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        QMessageBox::information(nullptr, "Débit", QString("Votre solde a été débité de %1. Nouveau solde: %2").arg(montant).arg(solde));
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Montant invalide ou solde insuffisant.");
    }
}

void Compte::Virement(const QString &destinataireCIN, double montant) {
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        QMessageBox::information(nullptr, "Virement", QString("Virement de %1 vers le compte %2 effectué. Nouveau solde: %3").arg(montant).arg(destinataireCIN).arg(solde));
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Montant invalide ou solde insuffisant.");
    }
}

void Compte::InfoCompte() {
    QMessageBox::information(nullptr, "Info Compte",
                             QString("Nom: %1\nPrénom: %2\nCIN: %3\nNuméro: %4\nSolde: %5\nRIB: %6")
                                 .arg(client->getNom()).arg(client->getPrenom()).arg(client->getCIN()).arg(client->getNum()).arg(solde).arg(rib));
}

double Compte::getSolde() const {
    return solde;
}

QString Compte::getRIB() const {
    return rib;
}
