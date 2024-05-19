# Define variables
SRC_DIR := src
BUILD_DIR := build
CLANG_FORMAT := clang-format
CLANG_FORMAT_FLAGS := -i -style=file
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
LIBFT := $(LIBFT_DIR)/libft.a

SOURCES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.cpp)  # Include both C and C++ sources
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(SOURCES))) $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(SOURCES)))  # Handle object files for both C and C++
EXECUTABLE := $(BUILD_DIR)/bin/a.out

# Default to C executable
run: run-c
cc: zig-cc
c: build run-c
z: zig

zig:  
	@rm -rf $(BUILD_DIR) zig-out
	@zig build
	@./zig-out/bin/zig-build-exe
	@$<

# Run C executable
run-c:
	@echo "Running C executable..."
	@./build/bin/a.out
	@$<

run-z:
	@echo "Running Zig executable..."
	@./zig-out/bin/zig-build-exe
	@$<

zig-cc:
	@echo "Zig compile C..."
	@zig cc src/main.c -o build/bin/a.out
	@$<

build: clean format $(EXECUTABLE)
	@zig build

# Linking object files 
$(EXECUTABLE): $(OBJECTS) $(LIBFT)
	@echo "Linking object files..."
	@mkdir -p $(BUILD_DIR)/bin
	@clang++ $(OBJECTS) -o $@ -L$(LIBFT_DIR) -lft  # Use clang++ for linking C++ files

# Compile C to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@clang -c $< -o $@

# Compile C++ to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@clang++ -c $< -o $@

format:
	@echo "formatting..."
	@find $(SRC_DIR) -name "*.c" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;
	@find $(SRC_DIR) -name "*.cpp" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR) zig-out *.o a.out

# Compile libft
$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: run run-c run-cpp build format clean
