#include <libjrt.h>

int add_int_not_equal(int x, int y) { return x + y; }

void test_int_not_equal() { ASSERT_INT_NOT_EQUAL(9999, add_int_not_equal(5, 4)); }
