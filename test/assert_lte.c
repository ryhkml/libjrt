#include <libjrt.h>

void test_lte() {
    ASSERT_LTE(2, 2);
    ASSERT_LTE(2, -1);
}
