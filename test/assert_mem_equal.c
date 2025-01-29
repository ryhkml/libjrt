#include <libjrt.h>

typedef struct {
    int id;
    char name[16];
} User;

void test_mem_equal() {
    int arr1[] = {0, 1, 2};
    int arr2[] = {0, 1, 2};
    ASSERT_MEM_EQUAL(arr1, arr2, sizeof(arr1));

    User user1 = {1, "Elon"};
    User user2 = {1, "Elon"};
    ASSERT_MEM_EQUAL(&user1, &user2, sizeof(User));

    // Partial array comparison. First 3 integers only
    int arr3[] = {0, 1, 2, 3, 4, 5};
    int arr4[] = {0, 1, 2, 3, 4, 5};
    ASSERT_MEM_EQUAL(arr3, arr4, sizeof(int) * 3);
}
