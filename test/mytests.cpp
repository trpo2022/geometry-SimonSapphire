#include <geom.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "ctest.h"

CTEST(intersections, isinto) {
  CTEST_LOG("checking isInto() function");
  ASSERT_EQUAL(1, isInto(0, -1, 1));
  ASSERT_EQUAL(0, isInto(-1, 1, 1));
  ASSERT_EQUAL(0, isInto(1, -1, 1));
  ASSERT_EQUAL(0, isInto(3, -1, 1));
  ASSERT_EQUAL(0, isInto(-50, -1, 1));

  ASSERT_EQUAL(0, isInto(1, 1, 1));
  ASSERT_EQUAL(0, isInto(1.2, 1.2, 2.2));
  ASSERT_EQUAL(0, isInto(2.2, 1.2, 2.2));
  ASSERT_EQUAL(1, isInto(1.21, 1.2, 2.2));
}

CTEST(intersections, segments) {
  CTEST_LOG("checking is_segments_intersected() function..");

  double p1_x, p1_y, p2_x, p2_y, triangle_data[4];
  p1_x = -1;
  p1_y = 1;
  p2_x = 1;
  p2_y = -1;
  triangle_data[0] = -1;
  triangle_data[1] = -1;
  triangle_data[2] = 1;
  triangle_data[3] = 1;

  ASSERT_EQUAL(1, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = 1;
  p1_y = -1;
  p2_x = 1;
  p2_y = 1;

  ASSERT_EQUAL(0, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = 1;
  p1_y = -1;
  p2_x = 0;
  p2_y = 0;

  p1_x = 1;
  p1_y = -1;
  p2_x = 1;
  p2_y = 1;

  ASSERT_EQUAL(0, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = 1;
  p1_y = -1;
  p2_x = 0;
  p2_y = 0;

  ASSERT_EQUAL(0, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = 1;
  p1_y = -1;
  p2_x = 0;
  p2_y = 0.01;

  ASSERT_EQUAL(1, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = -1;
  p1_y = 1;
  p2_x = -1;
  p2_y = -1;

  ASSERT_EQUAL(0, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));

  p1_x = 1;
  p1_y = -1;
  p2_x = 0;
  p2_y = 0;

  ASSERT_EQUAL(0, is_segments_intersected(p1_x, p1_y, p2_x, p2_y,
                                          triangle_data[0], triangle_data[1],
                                          triangle_data[2], triangle_data[3]));
}

CTEST(intersections, Tsegment) {
  CTEST_LOG("checking is_T_segement_intersected() function..");

  double p1_x, p1_y, p2_x, p2_y, triangle_data[6];
  triangle_data[0] = -1;
  triangle_data[1] = -1;
  triangle_data[2] = 1;
  triangle_data[3] = 1;
  triangle_data[4] = 1;
  triangle_data[5] = -1;

  CTEST_LOG("checking line matching..");

  p1_x = 1;
  p1_y = -1;
  p2_x = 1;
  p2_y = 2;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 1;
  p1_y = -1;
  p2_x = -1;
  p2_y = -1;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 1;
  p1_y = -1;
  p2_x = 1;
  p2_y = 1;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  CTEST_LOG("checking touchings..");
  p1_x = 1;
  p1_y = -1;
  p2_x = 0;
  p2_y = 0;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 1;
  p1_y = -1;
  p2_x = 0.5;
  p2_y = -0.5;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 0;
  p1_y = -2;
  p2_x = 2;
  p2_y = 0;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 0;
  p1_y = 1;
  p2_x = 1;
  p2_y = 1;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 0;
  p1_y = 1;
  p2_x = -1;
  p2_y = -1;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = 1;
  p1_y = 1;
  p2_x = -2;
  p2_y = -1;
  ASSERT_EQUAL(
      0, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  CTEST_LOG("checking intersections..");

  p1_x = 1;
  p1_y = -1;
  p2_x = -1;
  p2_y = 1;
  ASSERT_EQUAL(
      1, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = -1;
  p1_y = 1;
  p2_x = 1;
  p2_y = 0;
  ASSERT_EQUAL(
      1, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));

  p1_x = -1;
  p1_y = 1;
  p2_x = 0.5;
  p2_y = -0.5;
  ASSERT_EQUAL(
      1, is_T_segement_intersected(p1_x, p1_y, p2_x, p2_y, triangle_data));
}

CTEST(intersections, Csegment) {
  CTEST_LOG("checking is_C_segement_intersected() function..");

  double p1_x, p1_y, p2_x, p2_y, circle_data[3];
  circle_data[0] = 0;
  circle_data[1] = 0;
  circle_data[2] = 1;

  CTEST_LOG("checking touchings..");
  p1_x = -2;
  p1_y = 1;
  p2_x = 1;
  p2_y = 1;
  ASSERT_EQUAL(0,
               is_C_segement_intersected(p1_x, p1_y, p2_x, p2_y, circle_data));

  p1_x = 0;
  p1_y = 1;
  p2_x = 1;
  p2_y = 0;
  ASSERT_EQUAL(0,
               is_C_segement_intersected(p1_x, p1_y, p2_x, p2_y, circle_data));

  CTEST_LOG("checking intersections..");

  p1_x = -2;
  p1_y = 1;
  p2_x = 1;
  p2_y = -1;
  ASSERT_EQUAL(1,
               is_C_segement_intersected(p1_x, p1_y, p2_x, p2_y, circle_data));

  p1_x = 0;
  p1_y = 0;
  p2_x = 1;
  p2_y = -1;
  ASSERT_EQUAL(1,
               is_C_segement_intersected(p1_x, p1_y, p2_x, p2_y, circle_data));
}

CTEST(intersections, TT) {
  CTEST_LOG("checking isIntersectTT() function..");

  double triangle_data_1[6], triangle_data_2[6];
  triangle_data_1[0] = -1;
  triangle_data_1[1] = -1;
  triangle_data_1[2] = 1;
  triangle_data_1[3] = 1;
  triangle_data_1[4] = 1;
  triangle_data_1[5] = -1;

  CTEST_LOG("checking line matching..");

  triangle_data_2[0] = -1;
  triangle_data_2[1] = -1;
  triangle_data_2[2] = 1;
  triangle_data_2[3] = 1;
  triangle_data_2[4] = -1;
  triangle_data_2[5] = 1;
  ASSERT_EQUAL(0, is_TT_intersected(triangle_data_1, triangle_data_2));

  CTEST_LOG("checking touchings..");

  triangle_data_2[0] = 2;
  triangle_data_2[1] = -1;
  triangle_data_2[2] = 1;
  triangle_data_2[3] = -2;
  triangle_data_2[4] = 1;
  triangle_data_2[5] = -1;
  ASSERT_FALSE(is_TT_intersected(triangle_data_1, triangle_data_2));

  triangle_data_2[0] = -2;
  triangle_data_2[1] = -1;
  triangle_data_2[2] = 1;
  triangle_data_2[3] = 2;
  triangle_data_2[4] = -1;
  triangle_data_2[5] = 1;
  ASSERT_EQUAL(0, is_TT_intersected(triangle_data_1, triangle_data_2));

  CTEST_LOG("checking intersection..");

  triangle_data_2[0] = 2;
  triangle_data_2[1] = -1;
  triangle_data_2[2] = 1;
  triangle_data_2[3] = -2;
  triangle_data_2[4] = -1;
  triangle_data_2[5] = 1;
  ASSERT_TRUE(is_TT_intersected(triangle_data_1, triangle_data_2));
}

CTEST(intersections, TC) {
  CTEST_LOG("checking is_TC_intersected() function..");

  double triangle_data[6], circle_data[6];
  triangle_data[0] = -1;
  triangle_data[1] = -1;
  triangle_data[2] = 1;
  triangle_data[3] = 1;
  triangle_data[4] = 1;
  triangle_data[5] = -1;

  circle_data[2] = 1;

  CTEST_LOG("checking touching..");
  circle_data[0] = 2;
  circle_data[1] = 0;
  circle_data[2] = 1;
  ASSERT_FALSE(is_TC_intersected(triangle_data, circle_data));

  CTEST_LOG("checking intersection..");
  circle_data[0] = 0;
  circle_data[1] = 0;
  ASSERT_TRUE(is_TC_intersected(triangle_data, circle_data));
}

CTEST(intersections, CC) {
  CTEST_LOG("checking is_CC_intersected() function..");

  double circle_data_1[3], circle_data_2[3];
  CTEST_LOG("checking is_CC_intersected() function..");
  circle_data_1[0] = 0;
  circle_data_1[1] = 0;
  circle_data_1[2] = 1;

  CTEST_LOG("checking touching..");
  circle_data_2[0] = 2;
  circle_data_2[1] = 0;
  circle_data_2[2] = 1;
  ASSERT_FALSE(is_CC_intersected(circle_data_1, circle_data_2));

  CTEST_LOG("checking concentration..");
  circle_data_2[0] = 0;
  circle_data_2[1] = 0;
  circle_data_2[2] = 2;
  ASSERT_FALSE(is_CC_intersected(circle_data_1, circle_data_2));

  CTEST_LOG("checking intersection..");
  circle_data_2[0] = 1;
  circle_data_2[1] = 1;
  circle_data_2[2] = 1;
  ASSERT_TRUE(is_CC_intersected(circle_data_1, circle_data_2));
}

CTEST(figure_functions, figure_validation) {
  string figure, figure_type;
  CTEST_LOG("checking circle..");
  figure = "circle(0 0, 1.5)";
  figure_type = "circle";
  ASSERT_TRUE(is_figure_valid(figure, figure_type));

  figure = "circfle(0 0, 1.5)";
  figure_type = "circle";
  ASSERT_FALSE(is_figure_valid(figure, figure_type));

  CTEST_LOG("checking triangle..");
  figure = "triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))";
  figure_type = "triangle";
  ASSERT_TRUE(is_figure_valid(figure, figure_type));

  figure = "triangle((-3.0 1y-2, -1 0.0, -3.0 2.0, -3 -2))";
  figure_type = "triangle";
  ASSERT_FALSE(is_figure_valid(figure, figure_type));
}

CTEST(figure_functions, getting_figure_type) {
  string figure = "circle(0 0, 1.5)";
  string figure_type = "circle";

  CTEST_LOG("checking circle..");
  ASSERT_EQUAL(0, strcmp(figure_type.c_str(), get_figure_type(figure).c_str()));

  figure = "circ3le1(0 0, 1.5)";
  ASSERT_NOT_EQUAL(
      0, strcmp(figure_type.c_str(), get_figure_type(figure).c_str()));

  CTEST_LOG("checking triangle..");
  figure = "triangle((-3.0 1y-2, -1 0.0, -3.0 2.0, -3 -2))";
  figure_type = "triangle";
  ASSERT_EQUAL(0, strcmp(figure_type.c_str(), get_figure_type(figure).c_str()));

  figure = "rtrianagle((-3.0 1y-2, -1 0.0, -3.0 2.0, -3 -2))";
  ASSERT_NOT_EQUAL(
      0, strcmp(figure_type.c_str(), get_figure_type(figure).c_str()));
}

CTEST(figure_functions, calculation_perimeter) {
  string figure_type = "circle";
  CTEST_LOG("checking circle..");
  double circle_data[] = {1, 1, 0};
  ASSERT_DBL_NEAR(0, calc_figure_perimeter(figure_type, circle_data));

  circle_data[2] = 1;
  ASSERT_DBL_NEAR(6.2832, calc_figure_perimeter(figure_type, circle_data));

  CTEST_LOG("checking triangle..");
  figure_type = "triangle";
  double triangle_data[] = {-3.0, -2, -1, 0.0, -3.0, 2.0, -3, -2};
  ASSERT_DBL_NEAR(9.65685, calc_figure_perimeter(figure_type, triangle_data));

  triangle_data[0] = 3;
  triangle_data[1] = -2;
  triangle_data[2] = 3;
  triangle_data[3] = 2;
  triangle_data[4] = 1;
  triangle_data[5] = 0;
  triangle_data[6] = 3;
  triangle_data[7] = -2;
  ASSERT_DBL_NEAR(9.65685, calc_figure_perimeter(figure_type, triangle_data));
}

CTEST(figure_functions, calculation_area) {
  string figure_type = "circle";
  CTEST_LOG("checking circle..");
  double circle_data[] = {1, 1, 0};
  ASSERT_DBL_NEAR(0, calc_figure_area(figure_type, circle_data));

  circle_data[2] = 1;
  ASSERT_DBL_NEAR(3.1416, calc_figure_area(figure_type, circle_data));

  CTEST_LOG("checking triangle..");
  figure_type = "triangle";
  double triangle_data[] = {-3.0, -2, -1, 0.0, -3.0, 2.0, -3, -2};
  ASSERT_DBL_NEAR(4, calc_figure_area(figure_type, triangle_data));

  triangle_data[0] = 3;
  triangle_data[1] = -2;
  triangle_data[2] = 3;
  triangle_data[3] = 2;
  triangle_data[4] = 1;
  triangle_data[5] = 0;
  triangle_data[6] = 3;
  triangle_data[7] = -2;
  ASSERT_DBL_NEAR(4, calc_figure_area(figure_type, triangle_data));
}

CTEST(figure_functions, get_figure_array_length) {
  string figure_type = "circle";
  CTEST_LOG("checking circle..");
  ASSERT_EQUAL(3, get_figure_array_length(figure_type));

  CTEST_LOG("checking triangle..");
  figure_type = "triangle";
  ASSERT_EQUAL(8, get_figure_array_length(figure_type));
}
