# =============================
#   CONFIGURAÇÕES DO PROJETO
# =============================

CC = gcc

# Flags para o JOGO (sem -DTEST!)
CFLAGS = -Wall -Wextra -Iinclude -Itests

# Flags APENAS para testes
TESTFLAGS = $(CFLAGS) -DTEST

# Diretórios
SRC_DIR      = src
BUILD_DIR    = build
TEST_DIR     = tests
TEST_BUILD   = $(BUILD_DIR)/tests

# Arquivos do jogo
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET = $(BUILD_DIR)/pacman


# =============================
#   REGRAS PRINCIPAIS
# =============================

all: $(TARGET)


# =============================
#   COMPILAÇÃO DO JOGO (SEM TESTE)
# =============================

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)


# =============================
#   COMPILAÇÃO DOS TESTES
# =============================

TEST_FILES = $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINARIES = $(TEST_FILES:$(TEST_DIR)/%.c=$(TEST_BUILD)/%)

$(TEST_BUILD)/test_%: $(TEST_DIR)/test_%.c $(TEST_DIR)/unity.c $(SRC)
	mkdir -p $(TEST_BUILD)
	$(CC) $(TESTFLAGS) $^ -o $@

compila-tests: $(TEST_BINARIES)
	@echo "✓ Todos os testes foram compilados em build/tests/"


test: compila-tests
	@echo "====== EXECUTANDO TESTES ======"
	@for t in $(TEST_BINARIES); do \
		echo "--> $$t"; \
		./$$t || exit 1; \
		echo ""; \
	done
	@echo "✓ Todos os testes passaram com sucesso!"


# =============================
#   LIMPAR
# =============================

clean:
	rm -rf $(BUILD_DIR)/pacman $(BUILD_DIR)/*.o $(TEST_BUILD)
