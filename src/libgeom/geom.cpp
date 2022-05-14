#include <geom.h>

#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// #START / FIGURE: circle;

bool is_circle_valid(string figure)
{
  if (!regex_match(figure, regex(R"(^circle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'circle'" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^circle\(.*)"))) {
    cout << "Wrong character: Expected '('" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^circle\((-?\d+(\.\d+)?)(\s).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
          !regex_match(
                  figure,
                  regex(R"(^circle\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
          !regex_match(
                  figure,
                  regex(R"(^circle\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
          !regex_match(
                  figure,
                  regex(R"(^circle\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).*)"))) {
    cout << "Wrong character: Expected ')'" << endl;
    return false;
  } else if (
          regex_match(
                  figure,
                  regex(R"(^circle\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).+)"))) {
    cout << "An unexpected character at the end of the line" << endl;
    return false;
  }

  return true;
}

void get_circle_data(string figure, double circle_data[])
{
  int k = 0;
  string temp;
  cmatch result;

  regex_match(
          figure.c_str(),
          result,
          regex(R"((circle)(\()(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)))"));
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

double calc_circle_perimeter(double radius)
{
  return (2 * radius * M_PI);
}

double calc_circle_area(double radius)
{
  return (powf(radius, 2) * M_PI);
}

double segment_length(double x1, double y1, double x2, double y2)
{
  return sqrt(powf((x1 - x2), 2) + powf((y1 - y2), 2));
}

bool is_CC_intersected(double circle_data_1[], double circle_data_2[])
{
  double line = segment_length(
          circle_data_1[0],
          circle_data_1[1],
          circle_data_2[0],
          circle_data_2[1]);
  if (circle_data_1[2] + line <= circle_data_2[2]) {
    return false;
  }

  if (circle_data_2[2] + line <= circle_data_1[2]) {
    return false;
  }

  if (circle_data_1[2] + circle_data_2[2] <= line) {
    return false;
  }

  return true;
}

// #END / FIGURE: circle;

// #START / FIGURE: triangle;

bool is_triangle_valid(string figure)
{
  if (!regex_match(figure, regex(R"(^triangle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'triangle'" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^triangle\(\(.*)"))) {
    cout << "Wrong character: Expected '(('" << endl;
    return false;
  } else if (
          !regex_match(
                  figure,
                  regex(R"(^triangle\(\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (
          !regex_match(
                  figure,
                  regex(R"(^triangle\(\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)\)\).*)"))) {
    cout << "Wrong character: Expected '))'" << endl;
    return false;
  } else if (
          regex_match(
                  figure,
                  regex(R"(^triangle\(\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)\)\).+)"))) {
    cout << "An unexpected character at the end of the line" << endl;
    return false;
  }
  return true;
}

void get_triangle_data(string figure, double triangle_data[])
{
  int k = 0;
  string temp;
  cmatch result;

  regex_match(
          figure.c_str(),
          result,
          regex(R"(^triangle\(\((-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)(,\s?)(-?\d+(\.\d+)?)(\s)(-?\d+(\.\d+)?)\)\))"));
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

double calc_triangle_perimeter(double figure_data[])
{
  // sides of triangle;
  double a, b, c;

  a
          = sqrt(powf(figure_data[0] - figure_data[2], 2)
                 + powf(figure_data[1] - figure_data[3], 2));
  b
          = sqrt(powf(figure_data[2] - figure_data[4], 2)
                 + powf(figure_data[3] - figure_data[5], 2));
  c
          = sqrt(powf(figure_data[4] - figure_data[0], 2)
                 + powf(figure_data[5] - figure_data[1], 2));

  return a + b + c;
}

double calc_triangle_area(double figure_data[])
{
  // sides of triangle;
  double a, b, c;

  a
          = sqrt(powf(figure_data[0] - figure_data[2], 2)
                 + powf(figure_data[1] - figure_data[3], 2));
  b
          = sqrt(powf(figure_data[2] - figure_data[4], 2)
                 + powf(figure_data[3] - figure_data[5], 2));
  c
          = sqrt(powf(figure_data[4] - figure_data[0], 2)
                 + powf(figure_data[5] - figure_data[1], 2));

  // semi-perimeter;
  double s = (a + b + c) / 2;

  return sqrt(s * (s - a) * (s - b) * (s - c));
}
// #END / FIGURE: triangle;

// #START / BASE() functions;

bool is_figure_type_valid(string figure_type)
{
  array<string, 2> figure_types = {"circle", "triangle"};

  for (size_t i = 0; i < figure_types.size(); i++) {
    if (figure_type == figure_types[i])
      return true;
  }
  cout << "Invalid figure type: " << figure_type << endl;
  return false;
}

bool is_figure_valid(string figure, string figure_type)
{
  if (!is_figure_type_valid(figure_type))
    return false;

  if (figure_type == "circle")
    return is_circle_valid(figure);
  else if (figure_type == "triangle")
    return is_triangle_valid(figure);

  return false;
}

string get_figure_type(string figure)
{
  string figure_type = "";

  for (auto& ch : figure) {
    if (ch == '(') {
      break;
    }
    figure_type += ch;
  }

  return figure_type;
}

void get_figure_data(string figure, string figure_type, double figure_data[])
{
  if (figure_type == "circle")
    get_circle_data(figure, figure_data);
  else if (figure_type == "triangle")
    get_triangle_data(figure, figure_data);
}

double calc_figure_perimeter(string figure_type, double figure_data[])
{
  if (figure_type == "circle")
    return calc_circle_perimeter(figure_data[2]);
  else if (figure_type == "triangle")
    return calc_triangle_perimeter(figure_data);

  return 0;
}

double calc_figure_area(string figure_type, double figure_data[])
{
  if (figure_type == "circle")
    return calc_circle_area(figure_data[2]);
  else if (figure_type == "triangle")
    return calc_triangle_area(figure_data);

  return 0;
}

int get_figure_array_length(string figure_type)
{
  if (figure_type == "circle")
    return 3;
  else if (figure_type == "triangle")
    return 8;

  return 0;
}

// #END / BASE() functions;

// #START Intersections
int isInto(double x, double left, double right)
{
  if (fabs(x - left) < 0.0001 || fabs(x - right) < 0.0001) {
    return 0;
  }
  if (x > left && x < right) {
    return 1;
  }
  return 0;
}

bool is_segments_intersected(
        double p1_x,
        double p1_y,
        double p2_x,
        double p2_y,
        double t1_x,
        double t1_y,
        double t2_x,
        double t2_y)
{
  int p_constflag = 0;
  int t_constflag = 0;
  if (p2_x == p1_x) {
    p_constflag = 1;
  }

  if (t2_x == t1_x) {
    t_constflag = 1;
  }

  double k_p = 0;
  if (!p_constflag) {
    k_p = (p2_y - p1_y) / (p2_x - p1_x);
  }
  double b_p = p1_y - (p1_x * k_p);

  double k_t = 0;
  if (!t_constflag) {
    k_t = (t2_y - t1_y) / (t2_x - t1_x);
  }
  double b_t = t1_y - (t1_x * k_t);

  if (t_constflag == 1 && p_constflag == 1) {
    return 0;
  }

  if ((k_t == k_p) && !(t_constflag == 1 || p_constflag == 1)) {
    return 0;
  }

  double x = 0;
  if (p_constflag) {
    x = p1_x;
  } else if (t_constflag) {
    x = t1_x;
  } else {
    x = (b_p - b_t) / (k_t - k_p);
  }

  double t_left = t1_x;
  double t_right = t2_x;
  if (t_left > t_right) {
    double tmp = t_left;
    t_left = t_right;
    t_right = tmp;
  }

  double p_left = p1_x;
  double p_right = p2_x;
  if (p_left > p_right) {
    double tmp = p_left;
    p_left = p_right;
    p_right = tmp;
  }

  if (isInto(x, t_left, t_right) && isInto(x, p_left, p_right)) {
    return 1;
  }

  return 0;
}

int is_T_segement_intersected(
        double p1_x,
        double p1_y,
        double p2_x,
        double p2_y,
        double triangle_data[])
{
  int result = 0;
  result += is_segments_intersected(
          p1_x,
          p1_y,
          p2_x,
          p2_y,
          triangle_data[0],
          triangle_data[1],
          triangle_data[2],
          triangle_data[3]);
  result += is_segments_intersected(
          p1_x,
          p1_y,
          p2_x,
          p2_y,
          triangle_data[2],
          triangle_data[3],
          triangle_data[4],
          triangle_data[5]);
  result += is_segments_intersected(
          p1_x,
          p1_y,
          p2_x,
          p2_y,
          triangle_data[4],
          triangle_data[5],
          triangle_data[0],
          triangle_data[1]);

  return result;
}

int is_TT_intersected(double triangle_data_1[], double triangle_data_2[])
{
  int result = 0;
  result += is_T_segement_intersected(
          triangle_data_1[0],
          triangle_data_1[1],
          triangle_data_1[2],
          triangle_data_1[3],
          triangle_data_2);
  result += is_T_segement_intersected(
          triangle_data_1[2],
          triangle_data_1[3],
          triangle_data_1[4],
          triangle_data_1[5],
          triangle_data_2);
  result += is_T_segement_intersected(
          triangle_data_1[4],
          triangle_data_1[5],
          triangle_data_1[0],
          triangle_data_1[1],
          triangle_data_2);

  return result;
}

int is_C_segement_intersected(
        double p1_x,
        double p1_y,
        double p2_x,
        double p2_y,
        double circle_data[])
{
  double k = (p2_y - p1_y) / (p2_x - p1_x);
  double c = p1_y - (k * p1_x);

  double A = k * k + 1;
  double B = 2 * (k * c - (k * circle_data[1]) - circle_data[0]);
  double C = (circle_data[0]) * (circle_data[0])
          + (circle_data[1]) * (circle_data[1]) + c * c
          - (circle_data[2]) * (circle_data[2]);

  double discriminant = B * B - 4 * A * C;

  if (discriminant <= 0) {
    return 0;
  }

  double x1 = (-1 * B + sqrt(discriminant)) / (2 * A);
  double x2 = (-1 * B - sqrt(discriminant)) / (2 * A);

  double p_left = p1_x;
  double p_right = p2_x;
  if (p_left > p_right) {
    double tmp = p_left;
    p_left = p_right;
    p_right = tmp;
  }

  if (isInto(x1, p_left, p_right) || isInto(x2, p_left, p_right)) {
    return 1;
  }

  return 0;
}

int is_TC_intersected(double triangle_data[], double circle_data[])
{
  int result = 0;
  result += is_C_segement_intersected(
          triangle_data[0],
          triangle_data[1],
          triangle_data[2],
          triangle_data[3],
          circle_data);
  result += is_C_segement_intersected(
          triangle_data[2],
          triangle_data[3],
          triangle_data[4],
          triangle_data[5],
          circle_data);
  result += is_C_segement_intersected(
          triangle_data[4],
          triangle_data[5],
          triangle_data[0],
          triangle_data[1],
          circle_data);

  return result;
}
// #END Intersections

// print circle and triangle datas
void print_CT_data(
        int circles_amount,
        int triangles_amount,
        string circle_strings[],
        string triangle_strings[],
        double (*circle_array)[5],
        double (*triangle_array)[10])
{
  // print circles data
  if (circles_amount > 0) {
    for (int i = 0; i < circles_amount; i++) {
      cout << endl << i + 1 << ". " << circle_strings[i] << endl;
      cout << "   perimeter = " << fixed << setprecision(3)
           << circle_array[i][3] << endl;
      cout << "   area = " << fixed << setprecision(3) << circle_array[i][4]
           << endl;
      cout << "   intersetcs: " << endl;
      for (int j = 0; j < circles_amount; j++) {
        if (j != i && is_CC_intersected(circle_array[i], circle_array[j])) {
          cout << "     " << j + 1 << ". "
               << "circle" << endl;
        }
      }
      for (int j = 0; j < triangles_amount; j++) {
        if (is_TC_intersected(triangle_array[j], circle_array[i])) {
          cout << "     " << j + 1 + circles_amount << ". "
               << "triangle" << endl;
        }
      }
    }
  }

  // print triangles data
  if (triangles_amount > 0) {
    for (int i = 0; i < triangles_amount; i++) {
      cout << endl
           << i + 1 + circles_amount << ". " << triangle_strings[i] << endl;
      cout << "   perimeter = " << fixed << setprecision(3)
           << triangle_array[i][8] << endl;
      cout << "   area = " << fixed << setprecision(3) << triangle_array[i][9]
           << endl;
      cout << "   intersetcs: " << endl;
      for (int j = 0; j < triangles_amount; j++) {
        if (j != i && is_TT_intersected(triangle_array[i], triangle_array[j])) {
          cout << "     " << j + 1 + circles_amount << ". "
               << "triangle" << endl;
        }
      }
      for (int j = 0; j < circles_amount; j++) {
        if (is_TC_intersected(triangle_array[i], circle_array[j])) {
          cout << "     " << j + 1 << ". "
               << "circle" << endl;
        }
      }
    }
  }
}
