<div align="center">
	<h1>Just Run Test</h1>
</div>

A simple library for performing unit test in C. The test results are displayed in easy-to-read messages.

## Build and Install

```sh
make && make install
```

To test the ASSERT macro, run:

```sh
make && make install && make test
```

## Usage

```c
// test/add.c
#include <libjrt.h>

#include "../src/add.h"

int add(int x, int y) {
	return x + y;
}

void test_add() {
	ASSERT_INT_EQUAL(2, add(1, 1));
}
```

```c
// test/main.c
#include <libjrt.h>

void test_add();

int main(void) {
	printf("Test add\n");
	just_run_test(test_add);

	return just_print_test_result();
}
```

Remember to include the CFLAGS `-ljrt` when compiling.

## Assertion lists

-   `ASSERT_STR_EQUAL(expected, actual)`
-   `ASSERT_STR_NOT_EQUAL(expected, actual)`
-   `ASSERT_INT_EQUAL(expected, actual)`
-   `ASSERT_INT_NOT_EQUAL(expected, actual)`
-   `ASSERT_TRUE(actual)`
-   `ASSERT_FALSE(actual)`
-   `ASSERT_NULL(actual)`
-   `ASSERT_NOT_NULL(actual)`
-   `ASSERT_PTR_EQUAL(expected, actual)`
-   `ASSERT_PTR_NOT_EQUAL(expected, actual)`
-   `ASSERT_GT(expected, actual)`
-   `ASSERT_LT(expected, actual)`
-   `ASSERT_GTE(expected, actual)`
-   `ASSERT_LTE(expected, actual)`
-   `ASSERT_MEM_EQUAL(expected, actual, size)`
-   `ASSERT_MEM_NOT_EQUAL(expected, actual, size)`

## Formatter

`~/.clang-format` base from [Google](https://google.github.io/styleguide/cppguide.html)

```
BasedOnStyle: Google
IndentWidth: 4
ColumnLimit: 120
```

_In Google i trust_

## TODO

-   [x] Add new assertion ASSERT_GT, ASSERT_LT, ASSERT_GTE, ASSERT_LTE, ASSERT_MEM_EQUAL, ASSERT_MEM_NOT_EQUAL, **and** more
