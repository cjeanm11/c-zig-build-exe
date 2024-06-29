SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := src/headers
CLANG_FORMAT := clang-format
CLANG_FORMAT_FLAGS := -i -style=file

CFLAGS := -I$(SRC_DIR)/$(INCLUDE_DIR)

run: run-c

# C-related targets
c: build run-c

# C++-related targets (if needed)
c++: build-c++ run-c

# Zig-related targets (if needed)
z: build-z run-z

# Run the selected executable
run-c:
	@echo "Running C executable..."
	@./${BUILD_DIR}/bin/a.out

run-z:
	@echo "Running Zig executable..."
	@./zig-out/bin/zig-build-exe

# Build targets
build: build-c  # Default build is for C

build-c: clean format zig-cc
build-c++: clean format zig-c++

build-z: clean format
	@echo "Zig compile Zig..."
	@zig build

# Compile C code with Zig
zig-cc:
	@echo "Zig compile C..."
	@mkdir -p $(BUILD_DIR)/bin
	@zig cc $(CFLAGS) ${SRC_DIR}/main.c -o ${BUILD_DIR}/bin/a.out  # Pass CFLAGS here

# Compile C++ code with Zig
zig-c++:
	@echo "Zig compile C++..."
	@mkdir -p $(BUILD_DIR)/bin
	@zig c++ $(CFLAGS) ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/bin/a.out # Pass CFLAGS here


# Format code
format:
	@echo "formatting..."
	@find $(SRC_DIR) -name "*.c" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(SRC_DIR) -name "*.cpp" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(INCLUDE_DIR) -name "*.h" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \; # Format headers

# Clean up
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR) zig-out *.o a.out

# Mark targets as phony to ensure they are always run
.PHONY: run cc c c++ z run-c run-z zig-cc zig-c++ build build-c build-c++ build-z format clean
