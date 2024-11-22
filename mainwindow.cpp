#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), client(new Client("0123456789", "Saidi", "Camil", "0612345678")),
    compte(new Compte(client, "123456789", 1000.0, "RIB-987654321")) {

    // Initialisation de l'interface de connexion
    setupLoginUI();
}

MainWindow::~MainWindow() {
    delete client;
    delete compte;
}


void MainWindow::setupLoginUI() {
    // Créer les éléments pour la connexion
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Champ pour entrer le CIN
    QLabel *cinLabel = new QLabel("Nom d'utilisateur (CIN):", this);
    cinInput = new QLineEdit(this);
    cinInput->setPlaceholderText("Entrez votre CIN");

    // Champ pour entrer le mot de passe
    QLabel *passwordLabel = new QLabel("Mot de passe:", this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);  // Masquer le mot de passe
    passwordInput->setPlaceholderText("Entrez votre mot de passe");

    // Label pour afficher les erreurs
    errorLabel = new QLabel(this);
    errorLabel->setStyleSheet("QLabel { color : red; }");

    // Bouton pour se connecter
    QPushButton *loginButton = new QPushButton("Se connecter", this);
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);

    // Organiser les éléments dans le layout de la connexion
    layout->addWidget(cinLabel);
    layout->addWidget(cinInput);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordInput);
    layout->addWidget(errorLabel);
    layout->addWidget(loginButton);

    setWindowTitle("Connexion");
}

void MainWindow::onLoginClicked() {
    // Récupérer le CIN et le mot de passe entrés par l'utilisateur
    QString cin = cinInput->text();
    QString password = passwordInput->text();

    // Vérification des informations de connexion
    if (cin == client->getCIN() && password == "password") {  // Vérification du CIN et du mot de passe
        // Connexion réussie
        errorLabel->clear();
        setupAccountUI();
    } else {
        // Affichage d'une erreur si le CIN ou le mot de passe est incorrect
        errorLabel->setText("Identifiant ou mot de passe incorrect.");
    }
}

void MainWindow::setupAccountUI() {
    // Cache les éléments de connexion et montre les informations du compte
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Créer les éléments pour afficher les informations du compte
    accountInfoLabel = new QLabel(this);
    displayAccountInfo();

    layout->addWidget(accountInfoLabel);

    // Ajouter des boutons pour les actions possibles sur le compte
    QPushButton *creditButton = new QPushButton("Créditer le compte", this);
    connect(creditButton, &QPushButton::clicked, this, &MainWindow::onCreditClicked);
    layout->addWidget(creditButton);

    QPushButton *debitButton = new QPushButton("Débiter le compte", this);
    connect(debitButton, &QPushButton::clicked, this, &MainWindow::onDebitClicked);
    layout->addWidget(debitButton);

    QPushButton *transferButton = new QPushButton("Effectuer un virement", this);
    connect(transferButton, &QPushButton::clicked, this, &MainWindow::onTransferClicked);
    layout->addWidget(transferButton);

    QPushButton *changePhoneButton = new QPushButton("Changer le numéro de téléphone", this);
    connect(changePhoneButton, &QPushButton::clicked, this, &MainWindow::onChangePhoneClicked);
    layout->addWidget(changePhoneButton);

    setWindowTitle("Compte Bancaire");
}

void MainWindow::displayAccountInfo() {
    // Affichage des informations du compte, y compris le CIN de l'utilisateur
    accountInfoLabel->setText("Nom: " + client->getNom() + "\nPrénom: " + client->getPrenom() +
                              "\nNuméro: " + client->getNum() + "\nCIN: " + client->getCIN());
}

void MainWindow::onCreditClicked() {
    // Demander à l'utilisateur combien il souhaite créditer
    bool ok;
    double amount = QInputDialog::getDouble(this, "Créditer le compte", "Entrez le montant à créditer :",
                                            0, 0, 10000, 2, &ok);
    if (ok && amount > 0) {
        compte->Crediter(amount);  // Créditer le compte
        displayAccountInfo();  	// Rafraîchir les informations du compte
    }
}

void MainWindow::onDebitClicked() {
    // Demander à l'utilisateur combien il souhaite débiter
    bool ok;
    double amount = QInputDialog::getDouble(this, "Débiter le compte", "Entrez le montant à débiter :",
                                            0, 0, 10000, 2, &ok);
    if (ok && amount > 0) {
        compte->Debiter(amount);   // Débiter le compte
        displayAccountInfo();  	// Rafraîchir les informations du compte
    }
}

void MainWindow::onTransferClicked() {
    // Demander à l'utilisateur le CIN du destinataire et le montant
    bool ok;
    QString recipientCIN = QInputDialog::getText(this, "Virement", "Entrez le CIN du destinataire :",
                                                 QLineEdit::Normal, "", &ok);
    if (ok && !recipientCIN.isEmpty()) {
        double amount = QInputDialog::getDouble(this, "Virement", "Entrez le montant à transférer :",
                                                0, 0, 10000, 2, &ok);
        if (ok && amount > 0) {
            compte->Virement(recipientCIN, amount);  // Effectuer le virement
            displayAccountInfo();               	// Rafraîchir les informations du compte
        }
    }
}

void MainWindow::onChangePhoneClicked() {
    // Demander à l'utilisateur un nouveau numéro de téléphone
    bool ok;
    QString newPhone = QInputDialog::getText(this, "Changer le numéro de téléphone",
                                             "Entrez le nouveau numéro de téléphone :",
                                             QLineEdit::Normal, client->getNum(), &ok);
    if (ok && validatePhoneNumber(newPhone)) {
        client->ModifierNumero(newPhone);  // Mettre à jour le numéro de téléphone
        displayAccountInfo();          	// Rafraîchir les informations du compte
    } else {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone invalide.");
    }
}

bool MainWindow::validatePhoneNumber(const QString &phoneNumber) {
    // Vérifier si le numéro de téléphone est valide (10 chiffres)
    return phoneNumber.length() == 10 && phoneNumber.toStdString().find_first_not_of("0123456789") == std::string::npos;
}
