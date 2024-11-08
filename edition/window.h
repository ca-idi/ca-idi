#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QCheckBox>  // Inclure pour les cases à cocher

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

public slots:
    // Slots pour modifier l'affichage des champs
    void toggleIdVisibility(bool checked);
    void togglePwdVisibility(bool checked);

private:
    QLineEdit *echoLineEdit1;  // Identifiant
    QLineEdit *echoLineEdit2;  // Mot de passe
    QCheckBox *showIdCheckBox; // Case à cocher pour l'identifiant
    QCheckBox *showPwdCheckBox; // Case à cocher pour le mot de passe

    void echoChanged(int);
};
 //! [0]

#endif
