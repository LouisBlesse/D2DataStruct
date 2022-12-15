#include<iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Edge;
class Vertex;

class Edge {
public:
    int DestinationVertexID = 0;

    Edge() {}
    Edge(int destVID) {
        DestinationVertexID = destVID;
    }
    void setEdgeValues(int destVID) {
        DestinationVertexID = destVID;
    }
    int getDestinationVertexID() {
        return DestinationVertexID;
    }
};

class Vertex {
public:
    int state_id;
    string state_name;
    int state_outdegree;

    list < Edge > edgeList;

    Vertex() {
        state_id = 0;
        state_name = "";
        state_outdegree = 0;
    }

    Vertex(int id, string sname) {
        state_id = id;
        state_name = sname;
    }

    int getStateID() {
        return state_id;
    }
    string getStateName() {
        return state_name;
    }
    int getStateoutdegree() {
        return state_outdegree;
    }
    void setID(int id) {
        state_id = id;
    }
    void setStateName(string sname) {
        state_name = sname;
    }

    void setOutdegree(int soutdegree) {
        state_outdegree = soutdegree;
    }

    list < Edge > getEdgeList() {
        return edgeList;
    }

    void printEdgeList() {
        cout << "[";
        for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
            cout << it->getDestinationVertexID() << " --> ";
        }
        cout << "]";
        cout << endl;
    }

    int printEdgeList2() {

        int nb = 0;

        for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
            nb++;
        }
        return nb;
    }

};

class Graph {

    vector < Vertex > vertices;

public:

    bool checkIfVertexExistByID(int vid) {
        bool flag = false;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getStateID() == vid) {
                return true;
            }
        }
        return flag;
    }

    void addVertex(Vertex newVertex) {
        bool check = checkIfVertexExistByID(newVertex.getStateID());
        if (check == true) {}
        else {
            vertices.push_back(newVertex);
        }
    }

    Vertex getVertexByID(int vid) {
        Vertex temp;
        for (int i = 0; i < vertices.size(); i++) {
            temp = vertices.at(i);
            if (temp.getStateID() == vid) {
                return temp;
            }
        }
        return temp;
    }

    bool checkIfEdgeExistByID(int fromVertex, int toVertex) {
        Vertex v = getVertexByID(fromVertex);
        list < Edge > e;
        e = v.getEdgeList();
        bool flag = false;
        for (auto it = e.begin(); it != e.end(); it++) {
            if (it->getDestinationVertexID() == toVertex) {
                flag = true;
                return flag;
                break;
            }

        }
        return flag;
    }

    void addEdgeByID(int fromVertex, int toVertex) {
        bool check1 = checkIfVertexExistByID(fromVertex);
        bool check2 = checkIfVertexExistByID(toVertex);

        bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
        if ((check1 && check2 == true)) {

            if (check3 == true) {}
            else {

                for (int i = 0; i < vertices.size(); i++) {

                    if (vertices.at(i).getStateID() == fromVertex) {
                        Edge e(toVertex);
                        vertices.at(i).edgeList.push_back(e);
                    }
                    else if (vertices.at(i).getStateID() == toVertex) {
                        Edge e(toVertex);
                        vertices.at(i).edgeList.push_back(e);
                    }
                }
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < vertices.size(); i++) {
            Vertex temp;
            temp = vertices.at(i);
            cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
            temp.printEdgeList();
        }
    }

    void getnbEdges() {
        int id;
        int node[5] = {};
        int rank[5] = {};

        for (int j = 0; j < vertices.size(); j++) {
            Vertex temp;
            temp = vertices.at(j);
            id = temp.getStateID();
            int nb = temp.printEdgeList2();
            for (int i = 0; i < 5; i++) {
                if ((nb > rank[i] || rank[i] == NULL)) {
                    node[i + 1] = node[i];
                    rank[i + 1] = rank[i];
                    node[i] = id;
                    rank[i] = nb;
                    i = 6;
                }
            }
        }
        cout << "Voici les cinq premier site : " << endl;
        for (int i = 0; i < 5; i++) {
            cout << node[i] << " : " << rank[i] << endl;
        }
    }

    void getnboutdegree() {
        int id;
        int nb;
        int node[5] = {};
        int rank[5] = {};

        for (int j = 0; j < vertices.size(); j++) {
            Vertex temp;
            temp = vertices.at(j);
            id = temp.getStateID();
            nb = temp.getStateoutdegree();
            for (int i = 0; i < 5; i++) {
                if ((nb > rank[i] || rank[i] == NULL)) {
                    node[i + 1] = node[i];
                    rank[i + 1] = rank[i];
                    node[i] = id;
                    rank[i] = nb;
                    i = 6;
                }
            }
        }
        cout << "Voici les cinq premier site : " << endl;
        for (int i = 0; i < 5; i++) {
            cout << node[i] << " : " << rank[i] << endl;
        }
    }
};