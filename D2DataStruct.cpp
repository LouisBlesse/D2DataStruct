// D2DataStruct.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Programme1.h"
#include "Programme2.h"
#include "Programme3.h"
using namespace std;

int main()
{
    int choix = 0;
    while (choix != 6) {
        cout << "Quel programme voulez vous lancer \n 1: Kd-Tree\n 2: Hypergraph et referencement web \n 3: Labyrinthes \n 4: Compression d’images \n 6: Quitter\n\n";
        cin >> choix;


        if (choix == 1) {
            Programme1 party = Programme1();
            party.Play();
        }
        else if (choix == 2) {
            Programme2 party = Programme2();
            party.Play();
        }
        else if (choix == 3) {
            Programme3 party = Programme3();
            party.Play();
        }
        /*else if (choix == 4) {
            Programme4 party = Programme4();
            party.Play();
        }*/

    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
