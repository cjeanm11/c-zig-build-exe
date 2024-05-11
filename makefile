# Makefile for C and C++ compilation using Zig and Clang Format

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR_C := include/c
INCLUDE_DIR_CPP := include/cpp
CLANG_FORMAT := clang-format
CLANG_FORMAT_FLAGS := -i -style=file

CFLAGS := -I$(INCLUDE_DIR_C)
CXXFLAGS := -I$(INCLUDE_DIR_CPP)

c: clean format zig-cc run-c
c++: clean format zig-c++ run-c
cpp: clean format zig-c++ run-c
z:  clean format zig-z run-z
zig: clean format zig-z run-z

run-c:
	@echo "Running C executable..."
	@./${BUILD_DIR}/bin/a.out

run-z:
	@echo "Running Zig executable..."
	@./zig-out/bin/zig-build-exe

	
zig-z: 
	@echo "Zig compile Zig..."
	@zig build
	
zig-cc:
	@echo "Zig compile C..."
	@mkdir -p $(BUILD_DIR)/bin
	@zig cc $(CFLAGS) $(shell find $(SRC_DIR) -name "*.c") -o $(BUILD_DIR)/bin/a.out

zig-c++:
	@echo "Zig compile C++..."
	@mkdir -p $(BUILD_DIR)/bin
	@zig c++ $(CXXFLAGS) $(shell find $(SRC_DIR) -name "*.cpp") -o $(BUILD_DIR)/bin/a.out

format:
	@echo "Formatting code..."
	@find $(SRC_DIR) -name "*.c" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(SRC_DIR) -name "*.cpp" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(INCLUDE_DIR_C) -name "*.h" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(INCLUDE_DIR_CPP) -name "*.hpp" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;

clean:
	@echo "Cleaning..."
	@rm -rf zig-cache
	@rm -rf $(BUILD_DIR) zig-out *.o a.out

.PHONY: run c c++ cpp run-c build build-c build-c++ format clean