#include <libjrt.h>

int add_int_equal(int x, int y) { return x + y; }

void pass_by_ref(int *x) { *x = *x + 1; }

void test_int_equal() {
    ASSERT_INT_EQUAL(1, 1);
    ASSERT_INT_EQUAL(2, 1 + 1);
    ASSERT_INT_EQUAL(-1, 1 - 2);
    ASSERT_INT_EQUAL(9, add_int_equal(5, 4));

    int y = 1;
    pass_by_ref(&y);
    ASSERT_INT_EQUAL(2, y);
}
