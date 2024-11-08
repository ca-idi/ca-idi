#include "window.h"
#include "ui_window.h"
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>  // Inclure pour les cases à cocher

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    //! [1] Créer un groupe pour les widgets de l'interface
    QGroupBox *echoGroup = new QGroupBox(tr("Echo"));

    QLabel *echoLabel = new QLabel(tr("Identifiant:"));
    QComboBox *echoComboBox = new QComboBox;
    QLabel *echoLabel1 = new QLabel(tr("Mot de passe:"));

    // Déclarer et initialiser les QLineEdit
    echoLineEdit1 = new QLineEdit;
    echoLineEdit1->setPlaceholderText("Entrer votre texte");
    echoLineEdit2 = new QLineEdit;
    echoLineEdit2->setPlaceholderText("Entrer votre texte");

    // Créer des cases à cocher pour afficher/masquer les champs
    QCheckBox *showIdCheckBox = new QCheckBox(tr("Afficher l'identifiant"));
    QCheckBox *showPwdCheckBox = new QCheckBox(tr("Afficher le mot de passe"));

    // Connecter les cases à cocher aux fonctions correspondantes
    connect(showIdCheckBox, &QCheckBox::toggled, this, &Window::toggleIdVisibility);
    connect(showPwdCheckBox, &QCheckBox::toggled, this, &Window::togglePwdVisibility);

    // Créer un layout pour organiser les widgets
    QGridLayout *echoLayout = new QGridLayout;
    echoLayout->addWidget(echoLabel, 0, 0);
    echoLayout->addWidget(echoLineEdit1, 0, 1);
    echoLayout->addWidget(showIdCheckBox, 0, 2);  // Ajouter la case pour afficher l'identifiant
    echoLayout->addWidget(echoLabel1, 1, 0);
    echoLayout->addWidget(echoLineEdit2, 1, 1);
    echoLayout->addWidget(showPwdCheckBox, 1, 2);  // Ajouter la case pour afficher le mot de passe

    // Appliquer ce layout au groupe
    echoGroup->setLayout(echoLayout);

    // Créer un layout principal pour l'ensemble de la fenêtre
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(echoGroup, 0, 0);  // Positionner le groupe à (0, 0)
    setLayout(layout);

    // Définir le titre de la fenêtre
    setWindowTitle(tr("Line Edits"));

    // Connecter la combobox à la fonction qui changera l'echo mode
    connect(echoComboBox, QOverload<int>::of(&QComboBox::activated), this, &Window::echoChanged);
}

void Window::toggleIdVisibility(bool checked)
{
    // Modifier l'echo mode pour l'identifiant en fonction de l'état de la case à cocher
    if (checked) {
        echoLineEdit1->setEchoMode(QLineEdit::Normal);  // Afficher le texte
    } else {
        echoLineEdit1->setEchoMode(QLineEdit::Password);  // Masquer le texte
    }
}

void Window::togglePwdVisibility(bool checked)
{
    // Modifier l'echo mode pour le mot de passe en fonction de l'état de la case à cocher
    if (checked) {
        echoLineEdit2->setEchoMode(QLineEdit::Normal);  // Afficher le texte
    } else {
        echoLineEdit2->setEchoMode(QLineEdit::Password);  // Masquer le texte
    }
}

void Window::echoChanged(int index)
{
    switch (index) {
    case 0: // Normal (texte visible)
        echoLineEdit1->setEchoMode(QLineEdit::Normal);
        break;
    case 1: // Password (texte masqué)
        echoLineEdit1->setEchoMode(QLineEdit::Password);
        break;
    case 2: // PasswordEchoOnEdit (texte masqué, mais visible quand l'utilisateur tape)
        echoLineEdit1->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        break;
    case 3: // No Echo (aucun texte visible)
        echoLineEdit1->setEchoMode(QLineEdit::NoEcho);
        break;
    }
}
