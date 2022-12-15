#include "Programme4.h"
#include "quadtree.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void Encode() {
	int choix2 = 0;

	cout << "Quelle image voulez-vous encodez ?" << endl << "1- Chat" << endl << "2- Lune" << endl << "3- montgolfiere" << endl << "4- motif" << endl << "5- motif3" << endl << "6- soleil" << endl << "7- tableau" << endl << "8- tableau2" << endl;
	cin >> choix2;
    string choix = "C:/Users/Charles/Documents/UQAC/Structure_de_donnee/Projet2/Fichiers/Exo4/Images/";
    string choixname;
    string choixfile;
    if (choix2 == 1) {
        choixname = "chat.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 2) {
        choixname = "lune.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 3) {
        choixname = "montgolfiere.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 4) {
        choixname = "motif.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 5) {
        choixname = "motif3.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 6) {
        choixname = "soleil.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 7) {
        choixname = "tableau.png";
        choixfile = choix + choixname;
    }
    if (choix2 == 8) {
        choixname = "tableau2.png";
        choixfile = choix + choixname;
    }

    int enc;
    cout << "Combien de niveau d'encodage voulez vous ?" << endl;
    cin >> enc;
    Mat img = imread(choixfile, IMREAD_GRAYSCALE);
        int rows = img.rows;
        int cols = img.cols;

        int* pixels = new int[rows * cols];


        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                pixels[r * cols + c] = img.at<uint8_t>(r, c);
            }
        }

        qt_node* q = init_node();
        add_values(q, pixels, rows, cols);
        build_tree(q, enc);
        unpack_tree(q, img, rows, cols);

        delete[] pixels;

        imshow("Encoder", img);
        waitKey(0);

        cout << "Voulez vous la decoder ?" << endl << "1-oui\n2-non" << endl;
        cin >> choix2;
        if (choix2 == 1) {
            imshow("Decoder", img);
            waitKey(0);
        }
        else if (choix2 == 2) {
            cout << "Malheuresement pas encore disponible" << endl;
        }
    }

void Programme4::Play() {
        Encode();
}