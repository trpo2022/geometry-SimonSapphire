#include <iostream>
#include <regex>
#include <string>

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

// #END / FIGURE: circle;

// #START / FIGURE: triangle;

bool is_triangle_valid(string figure) {
  if (!regex_match(figure, regex(R"(^triangle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'triangle'" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^triangle\(\(.*)"))) {
    cout << "Wrong character: Expected '(('" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return false;
  } else if (!regex_match(figure, regex(R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\)\).*)"))) {
    cout << "Wrong character: Expected '))'" << endl;
    return false;
  } else if (regex_match(figure, regex(R"(^triangle\(\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\s)(\d+(\.\d+)?)\)\).+)"))) {
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

// #END / FIGURE: triangle;


// #START / BASE() functions;

bool is_figure_type_valid(string figure_type) {
  array<string, 2> figure_types = {"circle", "triangle"};
  
  for(size_t i = 0; i < figure_types.size(); i++){
    if (figure_type == figure_types[i]) return true;
  }
  cout << "Invalid figure type: " << figure_type << endl;
  return false;
}

bool is_figure_valid(string figure, string figure_type){
  if(!is_figure_type_valid(figure_type)) return false;

  if (figure_type == "circle") return is_circle_valid(figure);
  else if (figure_type == "triangle") return is_triangle_valid(figure);
  
  return false;
}

string get_figure_type(string figure) {
  string figure_type = "";

  for (auto &ch : figure) {
    if (ch == '('){
      break;
    }
    figure_type += ch;
  }

  return figure_type;
}

void get_figure_data(string figure, string figure_type, double figure_data[]) {
  if (figure_type == "circle") get_circle_data(figure, figure_data);
  else if (figure_type == "triangle") get_triangle_data(figure, figure_data);
}

// #END / BASE() functions;

int get_figure_array_length(string figure_type) {
  if (figure_type == "circle") return 3;
  else if (figure_type == "triangle") return 8;

  return 0;
}

int main(int argc, char** argv) {
  string figure, figure_type;
  
  cout << "Enter a figure: " << endl;
  getline(cin, figure);
  figure_type = get_figure_type(figure);
  if(!is_figure_valid(figure, figure_type)) return -1;

  int data_array_len = get_figure_array_length(figure_type);
  double *figure_data = new double[data_array_len];
  get_figure_data(figure, figure_type, figure_data);

  for (int i = 0; i < data_array_len; i++) {
    cout << figure_data[i] << endl;
  }

  // *Clear memory
  delete []figure_data;

  return 0;
}