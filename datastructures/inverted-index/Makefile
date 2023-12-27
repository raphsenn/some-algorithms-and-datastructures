CC := g++
CFLAGS := -std=c++17 -Wall
INCLUDE := -Iinclude
LIBS := -lgtest -lgtest_main -lpthread

SRC_DIR := src
TESTS_DIR := tests
BUILD_DIR := build

APP_SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC_FILES := $(wildcard $(TESTS_DIR)/*.cpp)

APP_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(APP_SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TESTS_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC_FILES))

TEST_EXEC := test

all: $(TEST_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TEST_EXEC): $(TEST_OBJ_FILES) $(BUILD_DIR)/inverted_index.o
	$(CC) $^ -o $@ $(LIBS)

$(BUILD_DIR)/inverted_index.o: $(SRC_DIR)/inverted_index.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f test
run_tests: $(TEST_EXEC)
	cd .. && ./test
