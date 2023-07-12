CC = g++
CFLAGS = -std=c++11 -Wall

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
THIRD_PARTY_DIR = third_party

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

TARGET = meu_projeto
TEST_TARGET = meu_projeto_test

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS) program/main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

program/main.o: program/main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(OBJECTS) $(TEST_DIR)/testes.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@
