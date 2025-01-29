#include <libjrt.h>

void test_gte() {
    ASSERT_GTE(2, 2);
    ASSERT_GTE(-1, 2);
}
