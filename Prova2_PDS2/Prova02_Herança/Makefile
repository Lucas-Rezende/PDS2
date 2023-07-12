# Nome do seu projeto
PROJECT_NAME = meu_projeto

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -std=c++11 -Wall

# Diretórios do projeto
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = tests
THIRD_PARTY_DIR = third_party

# Arquivos fonte
MAIN_FILE = program/main.cpp
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SOURCE_FILES = $(wildcard $(TEST_DIR)/*.cpp)
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SOURCE_FILES)) $(patsubst $(TEST_DIR)/%.cpp, $(TEST_DIR)/%.o, $(TEST_SOURCE_FILES))

# Comandos
MKDIR_P = mkdir -p
RM = rm -rf

# Bibliotecas Doctest
DOCTEST_LIBS = -L$(THIRD_PARTY_DIR) -ldoctest

# Regras do Makefile
.PHONY: all clean

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJECT_FILES) $(MAIN_FILE) -o $(PROJECT_NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

test: $(TEST_DIR)/testes.o $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(TEST_DIR)/testes.o $(OBJECT_FILES) -o $(PROJECT_NAME)_test $(DOCTEST_LIBS)

$(TEST_DIR)/testes.o: $(TEST_DIR)/testes.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(RM) $(PROJECT_NAME) $(PROJECT_NAME)_test $(OBJECT_FILES) $(TEST_DIR)/*.o

# Compilação dos testes
run_tests: test
	./$(PROJECT_NAME)_test
