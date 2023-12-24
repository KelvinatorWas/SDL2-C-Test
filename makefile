# First time makeing a make file, no judgment.

CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = `sdl2-config --cflags --libs`

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# List all source files
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/game/*.c)

# Make object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Create a list of directories
DIRECTORIES = $(sort $(dir $(OBJS)))

# Target
all: template_sdl2

# Create the executable
template_sdl2: $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ $(LDFLAGS)

# Create object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRECTORIES)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(SRC_DIR)

# Make necessary directories
$(DIRECTORIES) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
