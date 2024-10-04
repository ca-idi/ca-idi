#include <iostream>
#include "compte.cpp"
#include "client.cpp"
#include <windows.h> // Pour afficher les symboles

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); // Pour afficher les symboles (€ éèà et tout)
    system("CLS");
    
    int tentatives = 0;
    while (tentatives < 3) {
        system("CLS");
        cout << "\tcamil saidi\tamir sbiai\n";
        cout << "\t1\t2\n";
        
        int choix;
        cin >> choix;
        
        if (choix == 1) {
            Client client("FR-AAAC1234Z567", "camil", "saidi", "0679434567");
            Compte monCompte("0002", 150, "FR76 3000 4028 3798 7654 3210 123");
            
            cout << "\n\tEntrer le code de sécurité : ";
            int code;
            cin >> code;
            
            if (code == 5678) {
                system("CLS");
                cout << "\n\tBienvenue\n\n\n";
                system("pause");
                monCompte.MENU();
                return 0;
            }
        } else if (choix == 2) {
            Client client2("FR-AAAC9876Y543", "amir", "sbiai", "0607654321");
            Compte monCompte2("0003", 200, "FR76 3000 4028 3798 7654 3210 456");
            
            cout << "\n\tEntrer le code de sécurité : ";
            int code;
            cin >> code;
            
            if (code == 8765) {
                system("CLS");
                cout << "\n\tBienvenue\n\n\n";
                system("pause");
                monCompte2.MENU();
                return 0;
            }
        } else {
            system("CLS");
            cout << "ERREUR\n\n Il vous reste " << (2 - tentatives) << " essais \n\n";
            system("pause");
            tentatives++;
        }
    }
    
    return 0;
}
