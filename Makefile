CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = build

SRCS = $(SRC_DIR)/aligned_malloc.c
OBJS = $(OBJ_DIR)/aligned_malloc.o
TEST_SRCS = $(TEST_DIR)/test_aligned_malloc.c
TEST_OBJS = $(OBJ_DIR)/test_aligned_malloc.o

TARGET = aligned_malloc
TEST_TARGET = test_aligned_malloc

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(OBJ_DIR)/main.o

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJS) $(TEST_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: clean test