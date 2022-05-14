#include <geom.h>
#include <math.h>
#include <stdlib.h>

#include "ctest.h"

CTEST(suite1, isinto) {
  CTEST_LOG("checking isInto() function\n");
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

CTEST(suite1, segments) {
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