#include "Programme3.h"
#include <iostream>
#include <queue>
#include <stack>
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
	cout << "\nOu voulez vous mettre l'entree du labyrinthe ? (x puis y)\n";
	cin >> Xuser;
	cin >> Yuser;
	labyrinthe[Xuser][Yuser].start = 1;
	Point pStart(Xuser, Yuser);

	cout << "\nOu voulez vous mettre la sortie ? (x puis y)\n";
	cin >> Xuser;
	cin >> Yuser;
	labyrinthe[Xuser][Yuser].stop = 1;
	Point pEnd(Xuser, Yuser);

	PrintLabyrinthe(labyrinthe, size);
	
	int choix = 0;
	while (choix != 3) {
		cout << "\nComment voulez vous résoudre le labyrinthe ? \n 1: BFS \n 2: A*";
		cin >> choix;
		if (choix == 1) {
			BFS(labyrinthe, size, pStart, pEnd);
		}
		else if (choix == 2) {
			A(labyrinthe, size, pStart, pEnd);
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
			if (t[i][j].visited == true) {
				cout << "\033[33m";
			}
			else if (t[i][j].start == 1) {
				cout << "\033[32m";
			}
			else if (t[i][j].stop == 1) {
				cout << "\033[31m";
			}
			cout << "[" << t[i][j].data << "]";
			cout << "\033[0m";
				
			}
		cout << "\n";
	}
	cout << "\n\n";	
}

void  Programme3::BFS(Cell** t, const int size, Point src, Point dest) {

	int rowNum[] = { -1, 0, 0, 1 };
	int colNum[] = { 0, -1, 1, 0 };

	t[src.x][src.y].visited = true;

	queue<Point> queue;

	src.dist = 0;
	queue.push(src); 

	while (!queue.empty())
	{
		Point pt = queue.front();

		if (pt.x == dest.x && pt.y == dest.y) {
			cout << "\n Point trouve !\n";
			return;
		}

		queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = pt.x + rowNum[i];
			int y = pt.y + colNum[i];

			if ((x >= 0) && (x < size) && (y >= 0) && (y < size)) {
				if (t[x][y].visited != true && ((t[pt.x][pt.y].data == t[x][y].data - 1) || (t[pt.x][pt.y].data == t[x][y].data + 1)))
				{
					t[x][y].visited = true;
					Point cell (x, y, pt.dist + 1);
					cout << "x = " << x << " y = " << y;
					queue.push(cell);
					PrintLabyrinthe(t, size);
					if (x == dest.x && y == dest.y) {
						cout << "\n Point trouve !\n";
						return;
					}


				}
			}



		}
	}

	return;
}

void  Programme3::A(Cell** t, const int size, Point src, Point dest){
	vector<Point> empty;

	if (src.x == dest.x && src.y == dest.y) {
		return;
	}

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			t[x][y].fCost = FLT_MAX;
			t[x][y].gCost = FLT_MAX;
			t[x][y].hCost = FLT_MAX;
			t[x][y].parentX = -1;
			t[x][y].parentY = -1;
			t[x][y].x = x;
			t[x][y].y = y;

			t[x][y].visited = false;
		}
	}

	int x = src.x;
	int y = src.y;
	t[x][y].fCost = 0.0;
	t[x][y].gCost = 0.0;
	t[x][y].hCost = 0.0;
	t[x][y].parentX = x;
	t[x][y].parentY = y;

	vector<Cell> openList;
	openList.emplace_back(t[x][y]);
	bool destinationFound = false;

	while (!openList.empty() && openList.size() < size*size) {
		Cell node(x,y);
		do {
			float temp = FLT_MAX;
			vector<Cell>::iterator itNode;
			for (vector<Cell>::iterator it = openList.begin();
				it != openList.end(); it = next(it)) {
				Cell n = *it;
				if (n.fCost < temp) {
					temp = n.fCost;
					itNode = it;
				}
			}
			node = *itNode;
			openList.erase(itNode);
		} while ((node.x >= 0) && (node.x < size) && (node.y >= 0) && (node.y < size) == false);

		x = node.x;
		y = node.y;
		t[x][y].visited = true;

		for (int newX = -1; newX <= 1; newX++) {
			for (int newY = -1; newY <= 1; newY++) {
				
				double gNew, hNew, fNew;

				if ((node.x + newX >= 0) && (node.x + newX < size) && (node.y + newY >= 0) && (node.y + newY < size)) {
					if (t[x + newX][y + newY].data == t[x][y].data || t[x + newX][y + newY].data == t[x][y].data - 1 || t[x + newX][y + newY].data == t[x][y].data + 1) {
						
						if (node.x + newX == dest.x && node.y + newY == dest.y)
						{
							t[x + newX][y + newY].parentX = x;
							t[x + newX][y + newY].parentY = y;
							t[x + newX][y + newY].visited = true;
							destinationFound = true;
							PrintLabyrinthe(t, size);
							makePath(t, dest);
							return;
						}
						else if (t[x + newX][y + newY].visited == false)
						{

							gNew = node.gCost + 1.0;
							hNew = calculateD(x + newX, y + newY, dest);
							fNew = gNew + hNew;
							if (t[x + newX][y + newY].fCost == FLT_MAX || t[x + newX][y + newY].fCost > fNew)
							{
								t[x + newX][y + newY].fCost = fNew;
								t[x + newX][y + newY].gCost = gNew;
								t[x + newX][y + newY].hCost = hNew;
								t[x + newX][y + newY].parentX = x;
								t[x + newX][y + newY].parentY = y;
								openList.emplace_back(t[x + newX][y + newY]);
							}
							PrintLabyrinthe(t, size);
						}
						
					}
				}
								
			}
			
		}
	}
	if (destinationFound == false) {
		cout << "Destination not found" << endl;
		return;
	}
}

void Programme3::makePath(Cell** t, Point dest) {
	try {
		cout << "\nPassage trouvé\n" << endl;
		int x = dest.x;
		int y = dest.y;
		stack<Cell> path;
		vector<Cell> usablePath;

		while (!(t[x][y].parentX == x && t[x][y].parentY == y)
			&& t[x][y].x != -1 && t[x][y].y != -1)
		{
			path.push(t[x][y]);
			int tempX = t[x][y].parentX;
			int tempY = t[x][y].parentY;
			x = tempX;
			y = tempY;

		}
		path.push(t[x][y]);

		while (!path.empty()) {
			Cell top = path.top();
			path.pop();
			usablePath.emplace_back(top);
		}

	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

double Programme3::calculateD(int x, int y, Point dest) {
	double d = (sqrt((x - dest.x) * (x - dest.x)+ (y - dest.y) * (y - dest.y)));
	return d;
}


