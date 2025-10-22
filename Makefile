TARGET = breakout-game
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -std=c99

LDFLAGS = -L/usr/local/lib -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)


run: all
	./$(BUILD_DIR)/$(TARGET)