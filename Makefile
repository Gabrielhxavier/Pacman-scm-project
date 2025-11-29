# =============================
#   CONFIGURAÇÕES DO PROJETO
# =============================

CC = gcc

# Flags de compilação
# -Wall: mostra warnings básicos
# -Wextra: mostra warnings adicionais
# -Iinclude: adiciona o diretório include/ ao caminho de headers
# -Itests: permite incluir unity.h e headers dos testes
CFLAGS = -Wall -Wextra -Iinclude -Itests

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

# Regra padrão executada com "make"
all: $(TARGET)


# =============================
#   COMPILAÇÃO DO JOGO
# =============================

# Cada arquivo .c vira build/arquivo.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linka e cria o executável final do jogo
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


# =============================
#   RODAR O PROGRAMA
# =============================

run: $(TARGET)
	./$(TARGET)


# =============================
#   COMPILAÇÃO DOS TESTES
# =============================

# Todos os arquivos test_*.c dentro de tests/
TEST_FILES = $(wildcard $(TEST_DIR)/test_*.c)

# Converte tests/test_X.c → build/tests/test_X
TEST_BINARIES = $(TEST_FILES:$(TEST_DIR)/%.c=$(TEST_BUILD)/%)

# Regras de compilação dos testes unitários
# Cada teste precisa:
#   - test_X.c
#   - unity.c
#   - objetos do jogo (mapa.o, pecman.o, etc.)
#
$(TEST_BUILD)/test_%: $(TEST_DIR)/test_%.c $(TEST_DIR)/unity.c $(OBJ)
	mkdir -p $(TEST_BUILD)
	$(CC) $(CFLAGS) $^ -o $@


# Compila todos os testes
compila-tests: $(TEST_BINARIES)
	@echo "✓ Todos os testes foram compilados na pasta build/tests/"


# Executa todos os testes
test: tests
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
