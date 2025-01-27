#include <libjrt.h>
#include <stdlib.h>

void test_ptr_equal() {
    int index = 1;
    int *ptr_index1 = &index;
    int *ptr_index2 = &index;
    ASSERT_PTR_EQUAL(ptr_index1, ptr_index2);

    int *ptr_malloc1 = malloc(sizeof(int));
    int *ptr_malloc2 = ptr_malloc1;
    ASSERT_PTR_EQUAL(ptr_malloc1, ptr_malloc2);

    free(ptr_malloc1);
}
