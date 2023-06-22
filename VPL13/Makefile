CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -pedantic -Iinclude
LFLAGS = -o build/program.out

SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = include

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard *.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean

all: program.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

program.out: $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LFLAGS) $^

clean:
	rm -rf $(OBJ_DIR)/*.o build/program.out