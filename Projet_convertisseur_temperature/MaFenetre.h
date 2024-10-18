#include <QApplication>

#if QT_VERSION >= 0x050000
#include <QtWidgets> /* tous les widgets de Qt5 */
#else
#include <QtGui>
#endif

#define CELCIUS_FARENHEIT 0
#define FARENHEIT_CELCIUS 1

class MaFenetre : public QDialog
{
    Q_OBJECT
public:
    MaFenetre( QWidget *parent=0 );
private:
    // les widgets
    QLineEdit *valeur;
    QLabel *resultat;
    QLabel *unite;
    QComboBox *choixConversion;
    QPushButton *bConvertir;
    QPushButton *bQuitter;
    QDoubleValidator *doubleValidator;
    void afficherUnite();
signals:
    // Mécanisme(s) Qt
    void actualiser();
private slots:
    void convertir();
    void permuter();
public slots:
};
