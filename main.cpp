#include <iostream>
#include <regex>
#include <string>

using namespace std;

int check_circle(string figure) {
  if (!regex_match(figure, regex(R"(^circle\W+.*)"))) {
    cout << "Wrong name of figure: expected 'circle'" << endl;
    return 1;
  } else if (!regex_match(figure, regex(R"(^circle\(.*)"))) {
    cout << "Wrong character: Expected '('" << endl;
    return 2;
  } else if (!regex_match(figure, regex(R"(^circle\((\d+(\.\d+)?)(\s).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return 3;
  } else if (!regex_match(
                 figure,
                 regex(R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?).*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return 4;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)\W+.*)"))) {
    cout << "Wrong digit: Expected <double>" << endl;
    return 5;
  } else if (
      !regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).*)"))) {
    cout << "Wrong character: Expected ')'" << endl;
    return 6;
  } else if (
      regex_match(
          figure,
          regex(
              R"(^circle\((\d+(\.\d+)?)(\s)(\d+(\.\d+)?)(,\s?)(\d+(\.\d+)?)(\)).+)"))) {
    cout << "An unexpected character at the end of the line" << endl;
    return 7;
  }

  return 200;
}

string get_figure_type(string figure) {
  string figure_type;

  for (auto &ch : figure) {
    if (ch == '('){
      break;
    }
    figure_type += ch;
  }

  return figure_type;
}

void get_circle_data(string figure, double circle_data[], string& figure_type) {
  int k = 0;
  string temp;
  cmatch result;

  figure_type = "circle";

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

int main(int argc, char** argv) {
  string figure, figure_type;

  cout << "Enter a figure: " << endl;
  getline(cin, figure);
  figure_type = get_figure_type(figure);

  return 0;
}