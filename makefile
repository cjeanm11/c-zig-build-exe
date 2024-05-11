# Define variables
SRC_DIR := src
BUILD_DIR := build
CLANG_FORMAT := clang-format
CLANG_FORMAT_FLAGS := -i -style=file
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
LIBFT := $(LIBFT_DIR)/libft.a

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BUILD_DIR)/bin/a.out

# Default to C executable
run: run-c

# Run C executable
run-c: $(EXECUTABLE)
	@echo "Running C executable..."
	@$<

# Run Zig executable
run-z:
	@echo "Running Zig executable..."
	@./zig-out/bin/zig-build-exe

build: clean format $(EXECUTABLE)
	@echo "Building with Zig..."
	@zig build

# Linking object files 
$(EXECUTABLE): $(OBJECTS) $(LIBFT)
	@echo "Linking object files..."
	@mkdir -p $(BUILD_DIR)/bin
	@clang $(OBJECTS) -o $@ -L$(LIBFT_DIR) -lft

# Compile C to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@clang -c $< -o $@

format:
	@echo "Formatting source files..."
	@find $(SRC_DIR) -name "*.c" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR) zig-out *.o a.out

# Compile libft
$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: run run-c run-z build format clean
