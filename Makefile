# =============================
#   CONFIGURAÇÕES DO PROJETO
# =============================

# Compilador
CC = gcc

# Flags de compilação
# -Wall: mostra warnings básicos
# -Wextra: mostra warnings adicionais
# -Iinclude: adiciona o diretório include/ ao caminho de headers
CFLAGS = -Wall -Wextra -Iinclude

# Diretórios principais
SRC_DIR   = src
BUILD_DIR = build

# Lista todos os .c dentro de src/
SRC = $(wildcard $(SRC_DIR)/*.c)

# Converte: src/nome.c → build/nome.o
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Nome do executável final
TARGET = $(BUILD_DIR)/pacman.exe


# =============================
#   REGRAS PRINCIPAIS
# =============================

# Regra padrão que será executada ao rodar "make"
all: $(TARGET)


# =============================
#   COMPILAÇÃO DOS ARQUIVOS .c
# =============================

# Regra genérica:
# Cada arquivo .c vira um .o dentro de build/
#
#   $< é o arquivo de entrada   (src/arquivo.c)
#   $@ é o arquivo de saída     (build/arquivo.o)
#
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


# =============================
#      LINKAGEM FINAL
# =============================

# Une todos os .o e gera o executável pacman.exe
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


# =============================
#   RODAR O PROGRAMA
# =============================

run: $(TARGET)
	./$(TARGET)


# =============================
#   LIMPAR ARQUIVOS GERADOS
# =============================

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

