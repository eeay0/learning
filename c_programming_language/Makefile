# Compiler and Flags
CC = clang
CFLAGS  := -std=c23 -Wall -Wextra -Wpedantic -Werror \
            -Wshadow -Wconversion -Wstrict-prototypes -Wformat=2 \
            -Wmissing-prototypes -Wvla -fstack-protector-strong \
            -O3 -g -fsanitize=address,undefined -fno-common
# LDFLAGS: Linker flags, needed for the sanitizers.
LDFLAGS = -fsanitize=address,undefined

# Directories
SRCS_DIR = .
BUILD_DIR = out

# Find all .c files and create corresponding .o and executable names
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
TARGETS = $(patsubst $(SRCS_DIR)/%.c,$(BUILD_DIR)/%,$(SRCS))

# Phony targets do not represent files
.PHONY: all clear json

# The default goal: build all targets
all: $(TARGETS)

# Rule to compile a .c file into a .o file in the build directory
$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link a target executable from its object file
$(BUILD_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) $(LDFLAGS) $< -o $@
	chmod +x $@

# Generate compile_commands.json for clangd
json:
	bear -- make all

# Run the Clang Static Analyzer on all source files
# Remove the build directory and its contents
clear:
	rm -rf $(BUILD_DIR) compile_commands.json
