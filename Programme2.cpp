#include "Programme2.h"
#include <iostream>
#include "hypergraph.h"
#include <fstream>

using namespace std;

void Indegree(Graph g) {
	g.getnbEdges();
}

void Pagerank(Graph g) {
	g.getnboutdegree();
}

void Programme2::Play() {

	auto i = 0;
	int id;
	int id1;
	int id2;
	int outdegree;
	string url;
	Graph g;

	ifstream Read_text1("C:/Users/Charles/Documents/UQAC/Structure_de_donnee/Projet2/Fichiers/Exo2/eu-2005.nodes.txt");

	while (Read_text1 >> id >> outdegree >> url && i < 10000) {
		Vertex v1;
		v1.setID(id);
		v1.setStateName(url);
		v1.setOutdegree(outdegree);
		g.addVertex(v1);
		i++;
	}

	Read_text1.close();

	ifstream Read_text2("C:/Users/Charles/Documents/UQAC/Structure_de_donnee/Projet2/Fichiers/Exo2/eu-2005.edges.txt");

	i = 0;
	while (Read_text2 >> id1 >> id2 && i < 10000) {
		if (id1 != id2)
			g.addEdgeByID(id1, id2, 0);
		i++;
	}

	Read_text2.close();

	g.printGraph();

	system("PAUSE");
	int choix;

	cout << "Quelle algorithme voulez vous lancez ?\n1-Indegree\n2-PageRank" << endl;
	cin >> choix;
	if (choix == 1) {
		Indegree(g);
	}
	else if (choix == 2) {
		Pagerank(g);
	}
}