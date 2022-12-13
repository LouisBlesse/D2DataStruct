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

	cout << "Quelle image voulez-vous encodez ?" << endl << "99- Chat" << endl;
	cin >> choix2;
    if (choix2 == 99) {
        int enc;
        cout << "Combien de niveau d'encodage voulez vous ?" << endl;
        cin >> enc;
        Mat img = imread("C:/Users/Charles/Documents/UQAC/Structure de donnée/Projet 2/Fichiers/Exo4/Images/chat.png", IMREAD_GRAYSCALE);

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
    }
}

void Programme4::Play() {
        Encode();
}