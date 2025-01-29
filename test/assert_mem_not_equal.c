#include <libjrt.h>

typedef struct {
    int id;
    char name[16];
} User;

void test_mem_not_equal() {
    int arr1[] = {0, 1, 2};
    int arr2[] = {0, 1, 3};
    ASSERT_MEM_NOT_EQUAL(arr1, arr2, sizeof(arr1));

    User user1 = {1, "Elon"};
    User user2 = {1, "Yikes"};
    ASSERT_MEM_NOT_EQUAL(&user1, &user2, sizeof(User));

    // Compare the last 2 different integers
    int arr3[] = {1, 2, 3, 6, 9};
    int arr4[] = {1, 2, 3, 4, 5};
    ASSERT_MEM_NOT_EQUAL(&arr3[3], &arr4[3], sizeof(int) * 2);

    // Different string literals. Size 6 to include null terminator
    ASSERT_MEM_NOT_EQUAL("test1", "test2", 6);
}
