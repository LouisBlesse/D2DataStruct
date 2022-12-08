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
        else if (choix == 4) {
            Tree.racine = deleteKDTree(Tree.racine);
            printTree(Tree.racine);
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
    if (Tree != NULL)
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
            search(t->gauche,P, i + 1);
        }
        else {
            search(t->droite,P, i + 1);
        }
    }
    else {
        if (P.val2 < t->data.val2) {
            search(t->gauche, P, i + 1);
        }
        else {
            search(t->droite, P, i + 1);
        }

    }
}

KdTree::KdNoeud* Programme1::deleteKDTree(KdTree::KdNoeud* Tree)
{
    int I1;
    int I2;
    cout << "Quel est la premiere valeur du neud ?\n";
    cin >> I1;
    cout << "Quel est la deuxieme valeur du neud ?\n";
    cin >> I2;

    KdTree::KdNoeud::Point P(I1, I2);

    if (search(Tree, P, 0) == 1) {
        cout << "Le point que vous voulez supprimer est bien dans l'arbre\n\n";
        Tree = deleteKDNoeud(Tree,P,0);
    }
    else {
        cout << "Le point que vous voulez supprimer n'est pas dans l'abre\n\n";
    }

    return Tree;
}

KdTree::KdNoeud* Programme1::deleteKDNoeud(KdTree::KdNoeud* t, KdTree::KdNoeud::Point P, int depth)
{
    if (t == NULL)
        return NULL;

    int cd = depth % 2;

    // If the point to be deleted is present at root
    if (t->data.val1 == P.val1 && t->data.val2 == P.val2)
    {
        // 2.b) If right child is not NULL
        if (t->droite != NULL)
        {
            // Find minimum of root's dimension in right subtree
            KdTree::KdNoeud* min = findMin(t->droite, cd, depth);

            // Copy the minimum to root
            t->data.val1 = min->data.val1;
            t->data.val2 = min->data.val2;

            // Recursively delete the minimum
            t->droite = deleteKDNoeud(t->droite, min->data, depth + 1);
        }
        else if (t->gauche != NULL) // same as above
        {
            KdTree::KdNoeud* min = findMin(t->gauche, cd, depth);
            t->data.val1 = min->data.val1;
            t->data.val2 = min->data.val2;
            t->droite = deleteKDNoeud(t->gauche, min->data, depth + 1);
        }
        else // If node to be deleted is leaf node
        {
            delete t;
            return NULL;
        }
        return t;
    }

    // 2) If current node doesn't contain point, search downward
    if (cd == 0) {
        if (P.val1 < t->data.val1)
            t->gauche = deleteKDNoeud(t->gauche, P, depth + 1);
        else
            t->droite = deleteKDNoeud(t->droite, P, depth + 1);
        return t;
    }
    else {
        if (P.val2 < t->data.val2)
            t->gauche = deleteKDNoeud(t->gauche, P, depth + 1);
        else
            t->droite = deleteKDNoeud(t->droite, P, depth + 1);
        return t;
    }

}

KdTree::KdNoeud* Programme1::findMin(KdTree::KdNoeud* t, int d, int depth)
{
    // Base cases
    if (t == NULL)
        return NULL;

    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % 2;

    // Compare point with root with respect to cd (Current dimension)
    if (cd == d)
    {
        if (t->gauche == NULL)
            return t;
        return findMin(t->gauche, d, depth + 1);
    }

    // If current dimension is different then minimum can be anywhere
    // in this subtree
    return minNode(t,
        findMin(t->gauche, d, depth + 1),
        findMin(t->droite, d, depth + 1), d);
}

KdTree::KdNoeud* Programme1::minNode(KdTree::KdNoeud* x, KdTree::KdNoeud* y, KdTree::KdNoeud* z, int d)
{
    KdTree::KdNoeud* res = x;
    if (d == 0) {
        if (y != NULL && y->data.val1 < res->data.val1)
            res = y;
        if (z != NULL && z->data.val1 < res->data.val1)
            res = z;
    }
    else {
        if (y != NULL && y->data.val2 < res->data.val2)
            res = y;
        if (z != NULL && z->data.val2 < res->data.val2)
            res = z;
    }

    return res;
}