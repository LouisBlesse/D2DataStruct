#include "Programme1.h"
#include <iostream>
using namespace std;

void Programme1::Play() {
	KdTree Tree = KdTree();
    int choix = 0;

    while (choix != 6) {
        cout << "Que voulez vous faire ?\n 1: Ajouter un neud \n 2: Afficher le KDTree  \n 3: Rechercher un neud \n 4: Supprimer un neud\n";
        cin >> choix;
        if (choix == 1) {
            Tree = Add(Tree);
            printTree(Tree.racine);
        }
        else if (choix == 2) {
            printTree(Tree.racine);
        }
        else if (choix == 3) {
            searchKDTree(Tree.racine);
        }
    }
}

KdTree Programme1::Add(KdTree Tree) {
    int I1;
    int I2;
    cout << "Quel est la premiere valeur du neud ?\n";
    cin >> I1;
    cout << "Quel est la deuxieme valeur du neud ?\n";
    cin >> I2;

    KdTree::KdNoeud::Point P(I1, I2);

    if (Tree.racine == NULL) {
        Tree.racine = new KdTree::KdNoeud(P);
    }
    else {

        Tree.racine = insert(P, Tree.racine, 0);
    }
    return Tree;
}

KdTree::KdNoeud* Programme1::insert(KdTree::KdNoeud::Point P, KdTree::KdNoeud *t, int i)
{
    int cd = i % 2;
    if (t == NULL)
        return new KdTree::KdNoeud(P);

    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (cd == 0) {
        if (P.val1 < t->data.val1) {
            t->gauche = insert(P, t->gauche, i + 1);
        }
        else {
            t->droite = insert(P, t->droite, i + 1);
        }
    }
    else {
        if (P.val2 < t->data.val2) {
            t->gauche = insert(P, t->gauche, i + 1);
        }
        else {
            t->droite = insert(P, t->droite, i + 1);
        }

    }

    return t;
}

void Programme1::printTree(KdTree::KdNoeud* Tree)
{
    if (Tree != 0)
    {
        printTree(Tree->gauche);
        cout << "(" << Tree->data.val1 << " , " << Tree->data.val2 << ")" << endl;
        printTree(Tree->droite);
    }
}

void Programme1::searchKDTree(KdTree::KdNoeud* Tree)
{
    int I1;
    int I2;
    cout << "Quel est la premiere valeur du neud ?\n";
    cin >> I1;
    cout << "Quel est la deuxieme valeur du neud ?\n";
    cin >> I2;

    KdTree::KdNoeud::Point P(I1, I2);

    if (search(Tree, P, 0) == 1) {
        cout << "Le point que vous cherchez est bien dans l'arbre\n\n";
    }
    else {
        cout << "Le point que vous cherchez n'est pas dans l'abre\n\n";
    }
}

bool Programme1::search(KdTree::KdNoeud* t, KdTree::KdNoeud::Point P, int i) {
    int cd = i % 2;
    if (t == NULL)
        return 0;
    
    if (t->data.val1 == P.val1 && t->data.val2 == P.val2)
        return 1;

    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (cd == 0) {
        if (P.val1 < t->data.val1) {
            t->gauche = insert(P, t->gauche, i + 1);
        }
        else {
            t->droite = insert(P, t->droite, i + 1);
        }
    }
    else {
        if (P.val2 < t->data.val2) {
            t->gauche = insert(P, t->gauche, i + 1);
        }
        else {
            t->droite = insert(P, t->droite, i + 1);
        }

    }
}