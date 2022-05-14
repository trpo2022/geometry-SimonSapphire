#include <geom.h>

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  int triangles_amount, circles_amount;
  string figure = " ", figure_type;
  double f_perimeter, f_area;
  double circle_array[100][5], triangle_array[100][10];
  string circle_strings[100], triangle_strings[100];

  triangles_amount = circles_amount = 0;

  cout << "Enter a figure: " << endl;
  while (true) {
    getline(cin, figure);
    if (figure == "")
      break;

    figure_type = get_figure_type(figure);
    if (!is_figure_valid(figure, figure_type))
      break;

    int data_array_len = get_figure_array_length(figure_type);
    double* figure_data = new double[data_array_len];
    get_figure_data(figure, figure_type, figure_data);

    f_perimeter = calc_figure_perimeter(figure_type, figure_data);
    f_area = calc_figure_area(figure_type, figure_data);

    if (figure_type == "circle") {
      for (int i = 0; i < data_array_len; i++) {
        circle_array[circles_amount][i] = figure_data[i];
      }
      circle_array[circles_amount][3] = f_perimeter;
      circle_array[circles_amount][4] = f_area;
      circle_strings[circles_amount] = figure;
    } else if (figure_type == "triangle") {
      for (int i = 0; i < data_array_len; i++) {
        triangle_array[triangles_amount][i] = figure_data[i];
      }
      triangle_array[triangles_amount][8] = f_perimeter;
      triangle_array[triangles_amount][9] = f_area;
      triangle_strings[triangles_amount] = figure;
    }

    figure_type == "circle" ? circles_amount++ : triangles_amount++;

    // *Clear memory
    delete[] figure_data;
  }

  print_CT_data(
          circles_amount,
          triangles_amount,
          circle_strings,
          triangle_strings,
          circle_array,
          triangle_array);

  return 0;
}
