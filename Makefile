# =============================
#   CONFIGURAÇÕES DO PROJETO
# =============================

CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Iinclude -Itests -DTEST

# Diretórios principais
SRC_DIR      = src
BUILD_DIR    = build
TEST_DIR     = tests
TEST_BUILD   = $(BUILD_DIR)/tests

# Arquivos do jogo
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET = $(BUILD_DIR)/pacman   # Linux NÃO usa .exe


# =============================
#   REGRAS PRINCIPAIS
# =============================

all: $(TARGET)


# =============================
#   COMPILAÇÃO DO JOGO
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

# Todos arquivos test_*.c
TEST_FILES = $(wildcard $(TEST_DIR)/test_*.c)

# Gerar nomes dos binários
TEST_BINARIES = $(TEST_FILES:$(TEST_DIR)/%.c=$(TEST_BUILD)/%)

# Cada teste usa:
#    test_X.c  + unity.c + mapa.c + pecman.c
#
$(TEST_BUILD)/test_%: $(TEST_DIR)/test_%.c $(TEST_DIR)/unity.c $(SRC_DIR)/mapa.c $(SRC_DIR)/pecman.c
	mkdir -p $(TEST_BUILD)
	$(CC) $(CFLAGS) $^ -o $@


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
#   LIMPAR ARQUIVOS GERADOS
# =============================

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
	rm -rf $(TEST_BUILD)
