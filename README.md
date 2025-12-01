# 🎮 Pacman-scm-project

## 📋 Sobre o Projeto

Este projeto é uma implementação do clássico jogo Pacman em C. O objetivo é aplicar de forma integrada conceitos, práticas e ferramentas de SCM, incluindo:

- Versionamento de código e identificação de releases
- Controle de mudanças e rastreabilidade (issues, pull requests, revisões)
- Automação de builds e integração contínua (CI)
- Colaboração efetiva em equipe

---

## 🧩 Funcionalidades Implementadas e Planejadas

### ✅ Implementadas
- [x] Limpeza de Tela (Interface)
- [x] Interface intuitiva para o jogo
- [x] Game Over / Game On
- [x] Bug de travamento do fantasma em posição inválida
- [x] Sistema de Pontuação

### 🏆 Em Desenvolvimento
- [ ] Sistema de Vidas (Pacman perde vida ao encostar em Fantasma)

### 🕹️ Melhoria da Jogabilidade (Futuro)
- [ ] Implementar níveis de dificuldade
- [ ] Adicionar poder especial (pílula que destrói fantasmas)

### 👻 Melhoria dos Fantasmas (Futuro)
- [ ] Adicionar mais Fantasmas de acordo com o nível
- [ ] Implementar perseguição ao Pacman (IA)

---

## 🛠️ Ambiente de Desenvolvimento

Este projeto utiliza **Docker** para criar um ambiente replicável para todos os membros da equipe. O ambiente de desenvolvimento é configurado através de um Dev Container que inclui todas as dependências necessárias.

### Requisitos
- Docker instalado
- VS Code com extensão "Dev Containers"

### Configuração do Ambiente
1. Clone o repositório
2. Abra o projeto no VS Code
3. O VS Code detectará automaticamente o Dev Container e perguntará se deseja reabrir no container
4. Todas as dependências (GCC, Make, etc.) já estarão configuradas

---

## 🚀 Como Compilar e Executar o Projeto

Este projeto utiliza um **Makefile** para automatizar todo o processo de compilação, organização e execução do jogo Pacman-SCM.

---

### Comandos Disponíveis

#### 🔧 Compilar o Projeto
```bash
make
```
ou
```bash
make all
```

Este comando irá:
- Criar automaticamente a pasta `build/` (se não existir)
- Compilar todos os arquivos `.c` do projeto
- Gerar os arquivos objeto dentro de `build/*.o`
- Criar o executável final em `build/pacman`

---

#### ▶️ Executar o Jogo
```bash
make run
```

A regra `run` compila (se necessário) e executa o jogo diretamente do diretório raiz, garantindo que o arquivo `src/mapa.txt` seja encontrado corretamente.

A aplicação é um jogo de terminal e será executada diretamente no console.

---

#### 🧪 Executar Testes

O projeto utiliza o framework **Unity** para testes unitários.

**Compilar e executar todos os testes:**
```bash
make test
```

**Apenas compilar os testes (sem executar):**
```bash
make compila-tests
```

Os binários dos testes são gerados em `build/tests/`.

---

#### 🧹 Limpar Arquivos Compilados
```bash
make clean
```

Remove todos os arquivos objeto (`.o`), executáveis e testes compilados.

---

## 📦 Releases e Versionamento

O projeto segue o versionamento semântico (SemVer) no formato `vMAJOR.MINOR.PATCH`.

- As **releases** são criadas automaticamente através do workflow de CD quando uma tag é criada
- O histórico de mudanças pode ser consultado no [CHANGELOG.md](docs/changelog.md)
- Releases disponíveis: [GitHub Releases](../../releases)

---

## 📚 Documentação Adicional

- [Relatório de SCM](docs/relatorio.md) - Estratégias de branching, CI/CD, versionamento e lições aprendidas
