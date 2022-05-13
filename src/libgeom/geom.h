#pragma once

#include <string>

using namespace std;

// #START / FIGURE: circle;
bool is_circle_valid(string figure);
void get_circle_data(string figure, double circle_data[]);
double calc_circle_perimeter(double radius);
double calc_circle_area(double radius);
double segment_length(double x1, double y1, double x2, double y2);
bool is_CC_intersected(double circle_data_1[], double circle_data_2[]);
// #END / FIGURE: circle;

// #START / FIGURE: triangle;
bool is_triangle_valid(string figure);
void get_triangle_data(string figure, double triangle_data[]);
double calc_triangle_perimeter(double figure_data[]);
double calc_triangle_area(double figure_data[]);
// #END / FIGURE: triangle;

// #START / BASE() functions;
bool is_figure_type_valid(string figure_type);
bool is_figure_valid(string figure, string figure_type);
string get_figure_type(string figure);
void get_figure_data(string figure, string figure_type, double figure_data[]);
double calc_figure_perimeter(string figure_type, double figure_data[]);
double calc_figure_area(string figure_type, double figure_data[]);
int get_figure_array_length(string figure_type);
// #END / BASE() functions;
