CFLAGS = -Wall -Wextra -std=c11 -fPIC -Ilib -Iinclude -MMD -MP

LDLIBS = -ljrt
LDFLAGS = -Llib

AR = ar
ARFLAGS = rcs

SRC_DIR = lib
BUILD_DIR = out
TARGET_DIR = lib

LIB_SRC = $(SRC_DIR)/libjrt.c
LIB_OBJ = $(BUILD_DIR)/libjrt.o
LIB_TARGET = $(TARGET_DIR)/libjrt.a

# Test
TEST_DIR = test
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_EXEC = $(BUILD_DIR)/test_runner

.PHONY: all library clean install uninstall test

all: library

test: $(LIB_TARGET)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LDFLAGS) -o $(TEST_EXEC) $(LDLIBS)
	@./$(TEST_EXEC)

library: $(LIB_TARGET)

$(LIB_TARGET): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(LIB_OBJ): $(LIB_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(LIB_OBJ) $(LIB_TARGET) $(BUILD_DIR)/test* $(BUILD_DIR)/libjrt.d

install: $(LIB_TARGET)
	sudo install -m 644 include/libjrt.h /usr/local/include
	sudo install -m 644 $(LIB_TARGET) /usr/local/lib

uninstall:
	sudo rm -f /usr/local/include/libjrt.h
	sudo rm -f /usr/local/lib/libjrt.a

DEPFILES = $(wildcard $(BUILD_DIR)/*.d)
-include $(DEPFILES)
