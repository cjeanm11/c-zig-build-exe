# Define variables
SRC_DIR := src
BUILD_DIR := build

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE := $(BUILD_DIR)/a.out

run: $(EXECUTABLE)
	@$(EXECUTABLE)

build: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	@clang $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@clang -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f *.o
	@rm -f a.out

# Define all targets as .PHONY
.PHONY: all
all: run build clean
