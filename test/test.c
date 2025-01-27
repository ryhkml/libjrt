#include <libjrt.h>

void test_str_equal();
void test_str_not_equal();

void test_int_equal();
void test_int_not_equal();

void test_true();
void test_false();

void test_null();
void test_not_null();

void test_ptr_equal();
void test_ptr_not_equal();

int main(void) {
    printf("STR\n");
    just_run_test(test_str_equal);
    just_run_test(test_str_not_equal);

    printf("\nINT\n");
    just_run_test(test_int_equal);
    just_run_test(test_int_not_equal);

    printf("\nBOOL\n");
    just_run_test(test_true);
    just_run_test(test_false);

    printf("\nNULL\n");
    just_run_test(test_null);
    just_run_test(test_not_null);

    printf("\nPOINTER\n");
    just_run_test(test_ptr_equal);
    just_run_test(test_ptr_not_equal);

    printf("\n");

    return just_print_test_result();
}
