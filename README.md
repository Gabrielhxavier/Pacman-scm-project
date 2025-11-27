# 🎮 Pacman-scm-project

## 🧩 Funcionalidades para serem adicionadas

### 🏆 Prioridades Iniciais
- [ ] Limpeza de Tela (Interface)
- [ ] Sistema de input aprimorado (sem pressionar Enter)
- [ ] Sistema de Pontuação
- [ ] Sistema de Vidas (Pacman perde vida ao encostar em Fantasma)
- [ ] Game Over / Game On

### 🕹️ Melhoria da Jogabilidade
- [ ] Implementar níveis de dificuldade
- [ ] Adicionar poder especial (pílula que destrói fantasmas)

### 💻 Melhoria da Interface Gráfica
- [ ] Interface intuitiva para início, game over e fases

### 👻 Melhoria dos Fantasmas
- [ ] Adicionar mais Fantasmas de acordo com o nível
- [ ] Implementar perseguição ao Pacman (IA)



## 🚀 Como Compilar e Executar o Projeto

Para fazer o deploy da aplicação Pacman, siga os passos abaixo. A aplicação é escrita em C e requer um compilador como GCC.

Este projeto utiliza um **Makefile** para automatizar todo o processo de compilação, organização e execução do jogo Pacman-SCM.

---

### 🔧 1. Compilar o Projeto

No diretório raiz do repositório, execute:
   ```
   make
   ```
Este comando irá:

- Criar automaticamente a pasta `build/` (se não existir)
- Compilar todos os arquivos `.c` do projeto
- Gerar os arquivos objeto dentro de `build/*.o`
- Criar o executável final em: 
   ```
   build/pacman.exe
   ```

---

### ▶️ 2. Executar o Jogo

Ainda na raiz do projeto, execute:
   ```
   make run
   ```

A regra `run` executa o jogo diretamente do diretório raiz, garantindo que o arquivo src/mapa.txt seja encontrado corretamente pelo `fopen`.

A aplicação é um jogo de terminal e será executada diretamente no console.

---

### 🧹 3. Limpar Arquivos Compilados

Para remover arquivos temporários e o executável, execute:
   ```
   make clean
   ```


## 📂 Estrutura do Projeto
   ```
Pacman-scm-project/
│
├── .devcontainer/
│   ├── devcontainer.json
│   └── Dockerfile
│
├── build/
│   ├── mapa.o
│   ├── pacman.exe
│   └── pecman.o
│
├── docs/
│
├── include/
│   ├── mapa.h
│   └── pecman.h
│
├── src/
│   ├── mapa.c
│   ├── mapa.txt
│   └── pecman.c
│
├── .gitignore
├── Makefile
├── README.md

   ```


