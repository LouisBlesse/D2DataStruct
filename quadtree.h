#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <opencv2/opencv.hpp>


#ifndef MAX_DIM
#define MAX_DIM 8192

using namespace std;

struct qt_node {
    bool is_leaf;
    int pixel_value;
    int* p;
    int prows;
    int pcols;
    int r_min;
    int r_max;
    int c_min;
    int c_max;
    int deviation;

    qt_node* NW;
    qt_node* NE;
    qt_node* SE;
    qt_node* SW;
};

struct qt {

};

qt_node* init_node();

void add_values(qt_node* q, int* p, int num_rows, int num_cols);

void split_qt_node(qt_node* q);

float get_avg_pxvalue(qt_node* q);

float get_pixel_variance(qt_node* q);

void build_tree(qt_node* start, int max_var);

void unpack_tree(qt_node* start, int* unpacked, int total_rows, int total_cols);

void unpack_tree(qt_node* start, cv::Mat& modified, int total_rows, int total_cols);

int count_tree_nodes(qt_node* start);

int check_num_pixels(qt_node* start);

#endif