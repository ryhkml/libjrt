#include <libjrt.h>

void test_str_equal() {
    char *message = "Yikes";
    ASSERT_STR_EQUAL("Yikes", message);

    char *another_message = message;
    ASSERT_STR_EQUAL(another_message, message);
}
