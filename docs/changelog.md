# Changelog
Todas as mudanças notáveis deste projeto serão documentadas neste arquivo.

---
## Sumário
- **Added** – Novas funcionalidades.
- **Changed** – Mudanças em funcionalidades existentes.
- **Improved** – Melhorias visuais, estruturais ou de desempenho.
- **Fixed** – Correções de bugs.
- **Removed** – Funcionalidades removidas.
- **Deprecated** – Funcionalidades que serão removidas futuramente.

**Modelo de versão:**  
`[Versão] – YYYY-MM-DD`

---

## [1.2.2] - 2025-11
### Added
- Implementação completa do sistema de gerenciamento de estados do jogo.
- Adição de tela inicial com instruções de controle e início do jogo.
- Sistema de pausa, permitindo continuar ou encerrar a partida.
- Nova tela de Game Over com arte ASCII e opção de reiniciar o jogo.
- Implementação de limpeza de tela multiplataforma para garantir comportamento consistente em diferentes sistemas operacionais.


---

## [1.1.2] - 2025-11
### Added
- Introdução de novas matrizes de caracteres para representar graficamente o herói, fantasmas, paredes e espaços vazios, proporcionando uma interface visual mais clara e agradável.
- Criação da função auxiliar `imprimemaparate()` para modularizar a renderização e reduzir duplicação de código.

### Changed
- Atualização da função `imprimemapa()` para renderizar de forma estruturada os novos elementos gráficos.
- Revisão dos arquivos de header com diretivas de inclusão adequadas, garantindo declarações corretas, evitando múltiplas definições e melhorando a organização do projeto.

### Improved
- Interface gráfica geral do jogo aprimorada, tornando o layout mais limpo, organizado e de melhor legibilidade durante a jogabilidade.

---

## [1.0.2] - 2025-11
### Fixed
- Adicionada uma função utilitária `limpatela()` para limpar a tela do terminal usando códigos ANSI, garantindo uma exibição mais limpa do mapa durante o loop principal.
- A lógica principal do jogo foi atualizada para chamar `limpatela()` antes de imprimir o mapa, evitando acúmulo de frames anteriores no terminal.
- Atualização dos testes, incluindo a correção no teste `test_imprimemapa_nao_crasha`, que agora também chama `limpatela()` para refletir o comportamento real da aplicação e manter consistência entre testes e execução principal.


---

## [1.0.1] - 2025-11
### Fixed
- Correção de um bug onde fantasmas ficavam travados ao encontrar paredes ou posições inválidas.  
  - A lógica de movimento estava reutilizando a mesma direção aleatória durante todas as tentativas, devido à reinicialização inadequada da semente do gerador de números aleatórios.  
  - Agora, uma nova direção aleatória é gerada a cada tentativa, garantindo que os fantasmas busquem corretamente alternativas válidas de movimento.  
  - Esse fix impede que os fantasmas permaneçam parados por múltiplas iterações consecutivas.


---

## [1.0.0] - 2025-11
### Added
- Configuração inicial do ambiente Docker e documentação base.  
- Criação do primeiro `Makefile` para build do projeto.  
- Workflow de Integração Contínua (CI) para compilação automática.  
- Regras automatizadas de teste integradas ao Makefile.  
- Inclusão de arquivos de testes revisados e padronizados para as funções originais.  
- Habilitação do botão de dispatch manual para o workflow de CI.  
- Regras adicionais de build para compilar e executar testes unitários.  
- Workflow de Deploy Contínuo (CD) para gerar releases automatizadas.

### Changed
- Ajustes e correção no arquivo `Makefile` para integração com o workflow de CD.

### Contributors
- @Luana-Menezes (primeira contribuição)  
- @Gabrielhxavier (primeira contribuição)  
- @andrei Rocha7 (primeira contribuição)  
- @LUIZUFPE (primeira contribuição)  
- @BHSA (primeira contribuição)
