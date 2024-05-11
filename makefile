# Define variables
SRC_DIR := src
BUILD_DIR := build
CLANG_FORMAT := clang-format
CLANG_FORMAT_FLAGS := -i -style=file

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BUILD_DIR)/a.out

run: $(EXECUTABLE)
	@$(EXECUTABLE)

build: clean format $(EXECUTABLE)
	@echo "building..."

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@clang $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@clang -c $< -o $@

format:
	@echo "formatting..."
	@find $(SRC_DIR) -name "*.c" -exec $(CLANG_FORMAT) $(CLANG_FORMAT_FLAGS) {} \;

clean:
	@echo "cleaning..."
	@rm -rf $(BUILD_DIR)
	@rm -f *.o
	@rm -f a.out

# Define all targets as .PHONY
.PHONY: all run build format clean
