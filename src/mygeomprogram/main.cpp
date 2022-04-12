#include <geometry.h>

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

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