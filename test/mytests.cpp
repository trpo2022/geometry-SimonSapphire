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
