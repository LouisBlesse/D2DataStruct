#include "KdTree.h"

class KdTree {
public:
	class KdNoeud
	{
	public:
		class Point {
			public:
				int val1;
				int val2;
				Point(const int& i1, const int& i2) : val1(i1), val2(i2){}
		};
		Point data;
		KdNoeud* gauche;
		KdNoeud* droite;
		int hauteur;
		bool endWord;
		KdNoeud(const Point& d) : gauche(0), data(d), droite(0), hauteur(0) { }
		KdNoeud(const KdTree::KdNoeud& noeud) : gauche(noeud.gauche), data(noeud.data), droite(noeud.droite), hauteur(noeud.hauteur) { }
	};
	// Les membres données
	KdNoeud* racine; //racine de l'arbre
	int cpt; // Nombre de noeuds dans l'arbre
	// Les membres méthodes privés
	//...
};

