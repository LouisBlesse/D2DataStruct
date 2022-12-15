#pragma once
#include "KdTree.cpp"
class Programme1
{
public:
	void Play();
	KdTree Add(KdTree);
	KdTree::KdNoeud* insert(KdTree::KdNoeud::Point, KdTree::KdNoeud* , int);
	void printTree(KdTree::KdNoeud*);
	void searchKDTree(KdTree::KdNoeud*);
	bool search(KdTree::KdNoeud*, KdTree::KdNoeud::Point, int);
	KdTree::KdNoeud* deleteKDNoeud(KdTree::KdNoeud* , KdTree::KdNoeud::Point , int );
	KdTree::KdNoeud* findMin(KdTree::KdNoeud*, int, int);
	KdTree::KdNoeud* minNode(KdTree::KdNoeud* , KdTree::KdNoeud* , KdTree::KdNoeud* , int );
	KdTree::KdNoeud* deleteKDTree(KdTree::KdNoeud*);
};

