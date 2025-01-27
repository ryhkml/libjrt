#include <libjrt.h>
#include <stdlib.h>

void test_ptr_not_equal() {
    int index = 1;
    int *ptr_index1 = &index;
    int *ptr_index2 = NULL;
    ASSERT_PTR_NOT_EQUAL(ptr_index2, ptr_index1);

    int *ptr_malloc1 = malloc(sizeof(int));
    int *ptr_malloc2 = malloc(sizeof(int));
    ASSERT_PTR_NOT_EQUAL(ptr_malloc1, ptr_malloc2);

    free(ptr_malloc1);
    free(ptr_malloc2);
}
