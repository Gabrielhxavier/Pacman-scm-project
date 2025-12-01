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

### CI/CD
- **CI.yml**: Workflow que roda em PRs para `main`, compilando o código e executando testes.
- **CD.yml**: Workflow que roda ao criar uma tag, compilando, zipando e publicando uma release no GitHub.

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
| # | Pessoa  | Descrição | Tipo          | Dependências |
|---|---------|-----------------------|---------------|--------------|
| 0 | Todos   | Setup Inicial Github         | Setup         | -            |
| 1 | Luana   | Docker/DevContainer   | Config. CI/CD | -            |
| 2 | Gabriel | Makefile              | Config. CI/CD | #3           |
| 3 | Luiz    | Testes Unity          | Config. CI/CD | #2           |
| 4 | Andrei  | Workflow CI.yml      | Config. CI/CD | #2, #3       |
| 5 | Bruno   | Workflow CD.yml  | Config. CI/CD | #2, #3       |
| 6 | Luana   | Limpeza de Tela       | Task Fix      | -            |
| 7 | Gabriel | Input sem Enter       | Task Fix      | -            |
| 8 | Luiz    | Sistema de Pontuação  | Task Feature  | -      |
| 9 | Andrei  | Sistema de Vidas      | Task Feature  | -          |
| 10| Bruno   | Game Over / Game On   | Task Feature  | #9           |

## Lições Aprendidas

#### Luana
- Já tive contato com as boas práticas de Git, GitHub, CI e CD, etc em contextos acadêmicos e profissionais anteriormente. Então, este projeto tem sido uma oportunidade valiosa para consolidar, revisar e aprofundar conceitos e práticas que já conhecia com algum nível de conhecimento.

#### Gabriel
- Preencher Depois

#### Luiz
- Durante o projeto pude aprender melhor a utilizar as ferramentas de gerenciamento de configuração de software, assim como a estudar melhor os testes e o código do projeto. Através do projeto pude perceber o impacto do uso delas e sua importância no resultado do projeto, evidenciando que não pode ignorar os passos e etapas do projeto. No projeto todos conseguiram ter a possibilidade de contribuir, dando suas opiniões e trazendo experiências prévias com as ferramentas. Devido a uma forte interação e sinergia presente na equipe conseguimos superar os desafios que apareceram ao longo do desenvolvimento do projeto. Para projetos futuros desejo aplicar o conhecimento aprendido como também assumir outras posições como por exemplo: do responsável de CI/CD, entre outras.

#### Andrei
- Preencher Depois

#### Bruno
- Preencher Depois
