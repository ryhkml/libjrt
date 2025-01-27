#include <libjrt.h>

void test_null() {
    const char *value = NULL;
    ASSERT_NULL(value);
}
