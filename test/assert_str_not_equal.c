#include <libjrt.h>

void test_str_not_equal() {
    const char *message = "Yikes";
    ASSERT_STR_NOT_EQUAL("yikes", message);
    ASSERT_STR_NOT_EQUAL("OK", message);
}
