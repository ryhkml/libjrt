#include <libjrt.h>
#include <stdbool.h>

void test_false() {
    const int ok = 0;
    ASSERT_FALSE(ok);

    const bool valid = false;
    ASSERT_FALSE(valid);
}
