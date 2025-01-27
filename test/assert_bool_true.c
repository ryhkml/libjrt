#include <libjrt.h>
#include <stdbool.h>

void test_true() {
    const int ok = 1;
    ASSERT_TRUE(ok);

    const bool valid = true;
    ASSERT_TRUE(valid);
}
