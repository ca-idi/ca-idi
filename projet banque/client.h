#include <iostream>
#include "compte.h"

#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

class Client {
private:
    string CIN;          // Correspond à CIN
    string nom;        // Correspond à nom
    string prenom;     // Correspond à prenom
    string numero;     // Correspond à numero

public:
    Client(string, string, string, string);
    string getCIN();
    string getNom();
    string getPrenom();
    string getNum();
    string ModifierNumero(); // Correspond à ModifNum
};

#endif