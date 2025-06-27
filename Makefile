CC = clang
BUILD_DIR = build
TEST_DIR = tests

# For some reason, this doesn't compile for me :(
# DEBUG_FLAGS = -fsanitize=address,leak,undefined

.PHONY: test clean

test: $(BUILD_DIR)/array_test
	@echo "Running tests..."
	$(BUILD_DIR)/array_test

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/array_test: $(BUILD_DIR) T_array.h $(TEST_DIR)/array_test.c
	$(CC) $(TEST_DIR)/array_test.c -o $@ $(DEBUG_FLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
