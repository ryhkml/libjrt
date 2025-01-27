#include <libjrt.h>

#define BUFFER_SIZE 16

void test_not_null() {
    const char *value = "";
    ASSERT_NOT_NULL(value);

    const char another_value[BUFFER_SIZE];
    ASSERT_NOT_NULL(another_value);
}
