#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// #START / FIGURE: circle;

bool is_circle_valid(string figure) {
  if (!regex_match(figure, regex(R"(^circle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'circle'" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^circle\(.*)"))) {
    cout << "Wrong character: Expected '('" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^circle\((\d+(\.\d+)?)(\s).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (!regex_match(
                 figure,
                 regex(R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).*)"))) {
    cout << "Wrong character: Expected ')'" << endl;
    return false;
  } else if (
      regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).+)"))) {
    cout << "An unexpected character at the end of the line" << endl;
    return false;
  }

  return true;
}

void get_circle_data(string figure, double circle_data[]) {
  int k = 0;
  string temp;
  cmatch result;

  regex_match(
      figure.c_str(), result,
      regex(
          R"((circle)(\()(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)))"));
  for (size_t i = 0; i < result.size(); i++) {
    try {
      temp = result[i];
      if (temp[0] != '.') {
        circle_data[k] = stod(result[i]);
        k++;
      }
    } catch (...) {
      cout << "";
    }
  }
}

double calc_circle_perimeter(double radius) { return (2 * radius * M_PI); }

double calc_circle_area(double radius) { return (powf(radius, 2) * M_PI); }

// #END / FIGURE: circle;

// #START / FIGURE: triangle;

bool is_triangle_valid(string figure) {
  if (!regex_match(figure, regex(R"(^triangle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'triangle'" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^triangle\(\(.*)"))) {
    cout << "Wrong character: Expected '(('" << endl;
    return false;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\)\).*)"))) {
    cout << "Wrong character: Expected '))'" << endl;
    return false;
  } else if (
      regex_match(
          figure,
          regex(
              R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\)\).+)"))) {
    cout << "An unexpected character at the end of the line" << endl;
    return false;
  }
  return true;
}

void get_triangle_data(string figure, double triangle_data[]) {
  int k = 0;
  string temp;
  cmatch result;

  regex_match(
      figure.c_str(), result,
      regex(
          R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\)\))"));
  for (size_t i = 0; i < result.size(); i++) {
    try {
      temp = result[i];
      if (temp[0] != '.') {
        triangle_data[k] = stod(result[i]);
        k++;
      }
    } catch (...) {
      cout << "";
    }
  }
}

double calc_triangle_perimeter(double figure_data[]) {
  // sides of triangle;
  double a, b, c;

  a = sqrt(powf(figure_data[0] - figure_data[2], 2) +
           powf(figure_data[1] - figure_data[3], 2));
  b = sqrt(powf(figure_data[2] - figure_data[4], 2) +
           powf(figure_data[3] - figure_data[5], 2));
  c = sqrt(powf(figure_data[4] - figure_data[0], 2) +
           powf(figure_data[5] - figure_data[1], 2));

  return a + b + c;
}

double calc_triangle_area(double figure_data[]) {
  // sides of triangle;
  double a, b, c;

  a = sqrt(powf(figure_data[0] - figure_data[2], 2) +
           powf(figure_data[1] - figure_data[3], 2));
  b = sqrt(powf(figure_data[2] - figure_data[4], 2) +
           powf(figure_data[3] - figure_data[5], 2));
  c = sqrt(powf(figure_data[4] - figure_data[0], 2) +
           powf(figure_data[5] - figure_data[1], 2));

  // semi-perimeter;
  double s = (a + b + c) / 2;

  return sqrt(s * (s - a) * (s - b) * (s - c));
}
// #END / FIGURE: triangle;

// #START / BASE() functions;

bool is_figure_type_valid(string figure_type) {
  array<string, 2> figure_types = {"circle", "triangle"};

  for (size_t i = 0; i < figure_types.size(); i++) {
    if (figure_type == figure_types[i]) return true;
  }
  cout << "Invalid figure type: " << figure_type << endl;
  return false;
}

bool is_figure_valid(string figure, string figure_type) {
  if (!is_figure_type_valid(figure_type)) return false;

  if (figure_type == "circle")
    return is_circle_valid(figure);
  else if (figure_type == "triangle")
    return is_triangle_valid(figure);

  return false;
}

string get_figure_type(string figure) {
  string figure_type = "";

  for (auto &ch : figure) {
    if (ch == '(') {
      break;
    }
    figure_type += ch;
  }

  return figure_type;
}

void get_figure_data(string figure, string figure_type, double figure_data[]) {
  if (figure_type == "circle")
    get_circle_data(figure, figure_data);
  else if (figure_type == "triangle")
    get_triangle_data(figure, figure_data);
}

double calc_figure_perimeter(string figure_type, double figure_data[]) {
  if (figure_type == "circle")
    return calc_circle_perimeter(figure_data[2]);
  else if (figure_type == "triangle")
    return calc_triangle_perimeter(figure_data);

  return 0;
}

double calc_figure_area(string figure_type, double figure_data[]) {
  if (figure_type == "circle")
    return calc_circle_area(figure_data[2]);
  else if (figure_type == "triangle")
    return calc_triangle_area(figure_data);

  return 0;
}

// #END / BASE() functions;

int get_figure_array_length(string figure_type) {
  if (figure_type == "circle")
    return 3;
  else if (figure_type == "triangle")
    return 8;

  return 0;
}

int main(int argc, char **argv) {
  string figure = " ", figure_type;
  double f_perimeter, f_area;

  while (true) {
    cout << "Enter a figure: " << endl;
    getline(cin, figure);
    if (figure == "") return 0;

    figure_type = get_figure_type(figure);
    if (!is_figure_valid(figure, figure_type)) return -1;

    int data_array_len = get_figure_array_length(figure_type);
    double *figure_data = new double[data_array_len];
    get_figure_data(figure, figure_type, figure_data);

    f_perimeter = calc_figure_perimeter(figure_type, figure_data);
    f_area = calc_figure_area(figure_type, figure_data);
    cout << "perimeter = " << fixed << setprecision(3) << f_perimeter << endl;
    cout << "area = " << fixed << setprecision(3) << f_area << endl << endl;

    // *Clear memory
    delete[] figure_data;
  }

  return 0;
}