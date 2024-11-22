#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "client.h"
#include "compte.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();    	// Slot pour gérer la connexion
    void setupAccountUI();    	// Slot pour configurer l'interface après connexion
    void displayAccountInfo();	// Slot pour afficher les informations du compte

    // Actions sur le compte
    void onCreditClicked();   	// Slot pour créditer le compte
    void onDebitClicked();    	// Slot pour débiter le compte
    void onTransferClicked(); 	// Slot pour effectuer un virement
    void onChangePhoneClicked();  // Slot pour changer le numéro de téléphone

private:
    QLineEdit *cinInput;      	// Champ pour saisir le CIN
    QLineEdit *passwordInput; 	// Champ pour saisir le mot de passe
    QLabel *errorLabel;       	// Label pour afficher les erreurs
    QLabel *accountInfoLabel; 	// Label pour afficher les infos du compte

    Client *client;           	// Pointeur vers l'objet Client
    Compte *compte;           	// Pointeur vers l'objet Compte

    void setupLoginUI();      	// Méthode pour configurer l'interface de connexion
    bool validatePhoneNumber(const QString &phoneNumber); // Méthode pour valider un numéro de téléphone
};

#endif // MAINWINDOW_H
