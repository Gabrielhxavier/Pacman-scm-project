# Relatório de SCM - Pacman-scm-project

## Estratégia de Branching Utilizada

O projeto adota o modelo Git Flow para gerenciamento de branches:

- **main**: Branch principal com código estável e pronto para produção.
- **feature/nome-task**: Branches para desenvolvimento de novas funcionalidades, criadas a partir de `main` e mescladas de volta via Pull Request (PR).
- Outros tipos de branches temporários: `fix/`, `docs/`, `test/`, `ci/`, `build/`, `chore/`.

### Convenções de Commits
Seguimos as convenções de commits do padrão [Conventional Commits](https://github.com/iuricode/padroes-de-commits):
- `feat:` para novas funcionalidades
- `fix:` para correções de bugs
- `docs:` para documentação
- `test:` para testes
- `ci:` para configurações de CI
- `build:` para build e dependências
- `chore:` para tarefas diversas

### Proteções do Repositório
- Merge direto em `main` proibido; apenas via PR.
- Revisões obrigatórias em PRs.
- Push force desabilitado.

## Procedimentos de Build e CI/CD

### Build
- Utilizaremos um `Makefile` para compilar o projeto C.
- Testes são executados via `make test` (usando a biblioteca Unity para testes unitários).

### Makefile

- **Makefile**: Sistema de build para compilação, testes e gerenciamento do projeto Pacman.

Este Makefile implementa um sistema completo de build para o projeto Pacman, organizando a compilação do jogo principal e dos testes unitários em um fluxo estruturado e automatizado.

#### PONTOS RELEVANTES:

##### Estrutura de Diretórios
- **src/**: Código fonte principal do jogo
- **build/**: Arquivos compilados e binários
- **build/tests/**: Testes unitários compilados
- **tests/**: Código fonte dos testes
- **include/**: Headers e includes do projeto

##### Configurações de Compilação
- **Compilador:** GCC
- **Flags principais:** `-Wall -Wextra -Iinclude` (warnings ativos e includes)
- **Flags de testes:** Flags principais + `-Itests -DTEST` (macro TEST ativada)

##### Regras Principais

**Build do Jogo:**
- Compilação individual de objetos (.o) a partir dos fontes (.c)
- Linking dos objetos no executável final `build/pacman`
- Criação automática do diretório build quando necessário

**Sistema de Testes:**
- Detecção automática de arquivos `test_*.c` no diretório tests
- Compilação com Unity testing framework (`tests/unity.c`)
- Inclusão específica de módulos testados (`mapa.c`, `pecman.c`)
- Execução sequencial de todos os testes com feedback visual

**Comandos Disponíveis:**
- `make all` ou `make`: Compila o jogo completo
- `make run`: Compila e executa o jogo
- `make compila-tests`: Compila todos os testes
- `make test`: Compila e executa todos os testes
- `make clean`: Remove todos os arquivos gerados

##### Características Técnicas
- **Wildcards automáticos:** Detecção dinâmica de arquivos .c
- **Pattern rules:** Reutilização de regras para múltiplos arquivos
- **Dependencies explícitas:** Garantia de rebuild quando necessário
- **Feedback visual:** Mensagens informativas durante execução
- **Fail-fast nos testes:** Interrupção imediata em caso de falha

**Objetivos da implementação:**
- **Automatização:** Simplificar processo de build com comandos únicos
- **Organização:** Manter estrutura clara de diretórios e arquivos
- **Qualidade:** Garantir compilação com warnings ativos
- **Testabilidade:** Prover sistema robusto de testes unitários
- **Manutenibilidade:** Facilitar expansão e modificações futuras

### CI/CD
- **CI.yml**: Workflow que roda em PRs para `main`, compilando o código e executando testes.

A construção desse código, implementou um pipeline CI no GitHub Actions para automatizar a compilação e testes do projeto Pacman. O fluxo é acionado automaticamente em pull requests para a branch main ou manualmente. O processo executa em container Docker, compila o projeto usando make e executa os testes quando disponíveis, garantindo validação automática das alterações antes da integração no código principal.

#### PONTOS RELEVANTES:

##### Triggers

- Execução em container Ubuntu latest
- Checkout automático do repositório

##### Build de Imagem (Docker)

- Construção da imagem a partir do Dockerfile em .devcontainer/
- Tag: pacman-ci

##### Compilação e Testes (Docker)

- Compilação do projeto Pacman via comando make
- Execução condicional de testes:

  Se existir diretório tests: executa make test
  Caso contrário: mensagem "Nenhum teste encontrado"

Objetivos da construção do pipeline: 

- Validação Automática: Garantir que novas alterações não quebrem a base de código existente;
- Controle de Qualidade: Executar testes automaticamente antes da integração no branch principal;
- Feedback Rápido: Fornecer informações imediatas sobre o status do build para os desenvolvedores;
- Consistência: Garantir que o build e testes executem em ambiente controlado e replicável.

- **CD.yml**: Workflow que roda quando uma tag `v*` é criada, gerando uma release com binários distribuíveis.

A construção desse código implementou um pipeline CD (Continuous Deployment) no GitHub Actions para automatizar a criação de releases do projeto Pacman. O fluxo é acionado automaticamente quando tags versionadas (ex: v1.0.0) são criadas via push. O processo executa em container Docker, compila o projeto, empacota os binários em múltiplos formatos e publica uma release automaticamente no GitHub.

#### PONTOS RELEVANTES:

##### Triggers
- Acionado por push de tags seguindo padrão `v*` (ex: v1.0.0, v2.1.3)
- Execução em container Ubuntu latest
- Permissão de escrita para conteúdo do repositório

##### Build e Compilação
- Build da imagem Docker a partir do `.devcontainer/Dockerfile`
- Compilação do projeto via `make` em container Docker
- Execução com usuário específico (`$(id -u):$(id -g)`) para segurança

##### Empacotamento e Distribuição
- Criação de diretório `dist` com estrutura organizada
- Cópia do binário `pacman` e documentação (README.md, changelog.md)
- Geração de pacotes em múltiplos formatos:
  - **TAR.GZ**: Formato tradicional para sistemas Unix/Linux
  - **ZIP**: Formato universal para multiplataforma
- Nomeação automática usando a tag versionada (`pacman-${{ github.ref_name }}`)

##### Criação Automática de Release
- Utilização da action `softprops/action-gh-release@v1`
- Nome da release formatado com versão (ex: "Pacman Release v1.0.0")
- Upload automático dos pacotes gerados
- Geração automática de release notes
- Release pública e final (não draft ou prerelease)

**Objetivos da construção do pipeline:**
- **Automatização de Releases:** Eliminar processo manual de empacotamento e publicação;
- **Distribuição Consistente:** Garantir que todas as releases sigam o mesmo padrão;
- **Multiplataforma:** Oferecer pacotes em formatos adequados para diferentes sistemas;
- **Rastreabilidade:** Associar releases específicas às tags versionadas do código;
- **Documentação Inclusa:** Incluir automaticamente README e changelog nos pacotes.

### Estrutura do Projeto
```
pacman-scm-project/
├── .github/
│   └── workflows/
│       ├── CI.yml
│       └── CD.yml
├── .devcontainer/
│   ├── devcontainer.json
│   └── Dockerfile
├── docs/
│   ├── relatorio.md
│   └── changelog.md
├── include/
│   ├── pecman.h
│   └── mapa.h
├── src/
│   ├── pecman.c
│   ├── mapa.c
│   └── mapa.txt
├── tests/
├── README.md
├── Makefile
└── .gitignore
```

## Forma de Versionamento Adotada

- **Tags e Releases**: Tags são criadas em `main` para marcar versões, seguindo o formato `vMAJOR.MINOR.PATCH` (ex.: `v1.0.0`).
- Iniciamos em `v1.0.0`.
- Cada tag dispara o workflow `CD.yml` para gerar uma release automática.

## Gerenciamento de Issues

- Utilizamos labels para categorizar issues: `feature`, `fix`, `docs`, `test`, `ci`, `build`, `chore`.
- Ciclo de vida de um bug/feature:
  1. Criação da issue com descrição e label.
  2. Atribuição a um membro da equipe.
  3. Criação de branch correspondente (ex.: `feature/nome-task`).
  4. Desenvolvimento e commits convencionais.
  5. PR com link para a issue (usando `closes #N` ou `Fixes #N`).
  6. Revisão e merge.
  7. Fechamento automático da issue.

- Controle de trabalho via aba "Projects" do GitHub, com colunas: To do, In progress, In review, Done.

### Divisão de Trabalho
| # | Pessoa  | Descrição | Tipo      | Dependências  |
|---|---------|-----------------------|---------------|--------------|
| 0 | Todos   | Setup Inicial Github  | Setup         | -            |
| 1 | Luana   | Docker/DevContainer   | Config. CI/CD | -            |
| 2 | Gabriel | Makefile              | Config. CI/CD | #3           |
| 3 | Luiz    | Testes Unity          | Config. CI/CD | #2           |
| 4 | Andrei  | Workflow CI.yml       | Config. CI/CD | #2, #3       |
| 5 | Bruno   | Workflow CD.yml       | Config. CI/CD | #2, #3       |
| 6 | Luana   | Limpeza de Tela       | Task Fix      | -            |
| 7 | Gabriel | Melhoria de UI        | Task Fix      | -            |
| 8 | Luiz    | Sistema de Pontuação  | Task Feature  | -            |
| 9 | Andrei  | Sistema de Vidas      | Task Feature  | -            |
| 10| Bruno   | Game Over / Game On   | Task Feature  | #9           |

## Lições Aprendidas

#### Luana
- Já tive contato com as boas práticas de Git, GitHub, CI e CD, etc em contextos acadêmicos e profissionais anteriormente. Então, este projeto tem sido uma oportunidade valiosa para consolidar, revisar e aprofundar conceitos e práticas que já conhecia com algum nível de conhecimento.

#### Gabriel
- Preencher Depois

#### Luiz
- Preencher Depois

#### Andrei
- Preencher Depois

#### Bruno
- O meu uso anterior de Git se resumia a clonagem de repositórios públicos com finalidade estritamente de execução. Esse projeto possibilitou materializar os conhecimentos obtidos em aula, reforçando e os fixando como uma parte das minhas habilidades. Assim, foi uma etapa muito proveitosa do curso para mim, já que a partir de um nível de desconhecimento, agora possuo um nível razoável.
