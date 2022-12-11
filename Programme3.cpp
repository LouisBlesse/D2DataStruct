#include "Programme3.h"
#include <iostream>
using namespace std;

void Programme3::Play() {
	int size;
	cout << "Quelle est la taille du labyrinthes que vous voulez generer ?";
	cin >> size;
	Cell** labyrinthe = generate(size);


	PrintLabyrinthe(labyrinthe, size);
	labyrinthe = GrowTree(labyrinthe, size);
	cout << "\nLe labyrinthe a ete genere avec l'algorithme du Growing Tree :";
	PrintLabyrinthe(labyrinthe, size);

	int Xuser, Yuser;
	cout << "\nOu voulez vous mettre l'entree du labyrinthe ? (x puis y)\n ";
	cin >> Xuser;
	cin >> Yuser;
	labyrinthe[Xuser][Yuser].start = 1;

	cout << "\nOu voulez vous mettre la sortie ? (x puis y)\n ";
	cin >> Xuser;
	cin >> Yuser;
	labyrinthe[Xuser][Yuser].stop = 1;

	PrintLabyrinthe(labyrinthe, size);
	
	int choix = 0;
	while (choix != 3) {
		cout << "\nComment voulez vous résoudre le labyrinthe ? \n 1: BFS \n 2: A*";
		cin >> choix;
		if (choix == 1) {
			cout << "wip";
		}
		else if (choix == 2) {
			cout << "wip";
		}
	}

}

Cell** Programme3::generate(int size) {
	Cell** ary = new Cell* [size];
	for (int i = 0; i < size; ++i) {
		ary[i] = new Cell[size];
	}
	return ary;
}



Cell** Programme3::GrowTree(Cell** t, int size) {

	int x = rand() % size;
	int y = rand() % size;

	t[x][y].know = 1;
	t[x][y].data = 1;

	while (checkEnd(t, size) == 0) {
		char deplacement = getDirection(t, size, x, y);
		int data = t[x][y].data;
		if (deplacement == 'N') {
			y = y - 1;
			t[x][y].data = data + 1;
			t[x][y].know = 1;
		}
		else if (deplacement == 'S') {
			y = y + 1;
			t[x][y].data = data + 1;
			t[x][y].know = 1;
		}
		else if (deplacement == 'E') {
			x = x + 1;
			t[x][y].data = data + 1;
			t[x][y].know = 1;
		}
		else if (deplacement == 'O') {
			x = x - 1;
			t[x][y].data = data + 1;
			t[x][y].know = 1;
		}

		if (deplacement == 'B') {
			int ok = 0;
			//cout << "Bloqué, recule";
			if (x > 0) {
				if ((t[x - 1][y].data == data - 1) && ok ==0) {
					x = x - 1;
					data--;
					ok = 1;
				}
			}
			if (x < size-1){
				if ((t[x + 1][y].data == data - 1) && ok == 0) {
					x = x + 1;
					data--;
					ok = 1;
				}
			}
			if (y > 0) {
				if ((t[x][y - 1].data == data - 1) && ok == 0){
					y = y - 1;
					data--;
					ok = 1;
				}
			}
			if(y < size-1) {
				if ((t[x][y + 1].data == data - 1) && ok ==0) {
					y = y + 1;
					data--;
					ok = 1;
				}
			}
		}
		//cout << "x = " << x << " y = " << y;
		
		PrintLabyrinthe(t, size);
	}

	return t;
	
}

bool Programme3::checkEnd(Cell** t, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; j++) {
			if (t[i][j].know == 0) {
				return 0;
			}
		}
	}

	return 1;
}

char Programme3::getDirection(Cell** t, int size,int x, int y) {
	bool ok = 0;
	char liste[] = { 'N', 'S', 'E', 'O' };
	//char listeNon[] = {' '};
	string listeNon = {' '};
	char dep = ' ';
	//cout << "x = " << x << " y = " << y;
	while (ok == 0) {
		int random = rand() % 4;
		dep = liste[random];
		//cout << dep;
		if (dep == 'N') {
			if (y > 0) {
				if (t[x][y - 1].know == 0) {
					ok = 1;
				}
				else {
					listeNon+='N';
					//cout << "add N to listenon\n";
				}
			}
			else {
				listeNon += 'N';
				//cout << "add N to listenon\n";
			}
		}
		else if (dep == 'S') {
			if (y < size-1) {
				if (t[x][y + 1].know == 0) {
					ok = 1;
				}
				else {
					listeNon += 'S';
					//cout << "add s to listenon\n";
				}
			}
			else {
				listeNon += 'S';
				//cout << "add s to listenon\n";
			}
		}
		else if (dep == 'E') {
			if (x < size-1) {
				if (t[x + 1][y].know == 0) {
					ok = 1;
				}
				else {
					listeNon += 'E';
					//cout << "add E to listenon\n";
				}
			}
			else {
				listeNon += 'E';
				//cout << "add E to listenon\n";
			}
		}
		else {
			if (x > 0) {
				if (t[x - 1][y].know == 0) {
					ok = 1;
				}
				else {
					listeNon += 'O';
					//cout << "add O to listenon\n";
				}
			}
			else {
				listeNon += 'O';
				//cout << "add O to listenon\n";
			}
		}

		//cout << "liste non : " << listeNon;

		if (listeNon.find('N') != std::string::npos && listeNon.find('S') != std::string::npos && listeNon.find('E') != std::string::npos && listeNon.find('O') != std::string::npos) {
			//cout << "enter";
			dep = 'B';
			ok = 1;
		}
	}
	return dep;
}

void Programme3::PrintLabyrinthe(Cell** t, int size) {

	cout << "\n\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; j++) {
			if (t[i][j].start == 1) {
				cout << "\033[32m" << "[" << t[i][j].data << "]";
			}
			else if (t[i][j].stop == 1) {
				cout << "\033[31m" << "[" << t[i][j].data << "]";
			}
			cout << "\033[0m"<< "[" << t[i][j].data << "]";
		}
		cout << "\n";
	}
	cout << "\n\n";	
}




