#include <libjrt.h>

void test_lt() {
    ASSERT_LT(2, 1);
    ASSERT_LT(2, -1);
}
