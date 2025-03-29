# Algoritmo de Tideman - Eleição Condorcet

Este projeto implementa o **algoritmo de Tideman**, um método de votação baseado no critério de **Condorcet**, onde o vencedor é o candidato que vence em confrontos diretos contra todos os outros candidatos.

## Como Funciona

1. **Entrada de Votação**: Eleitores classificam os candidatos por ordem de preferência.
2. **Registro de Preferências**: O algoritmo registra as preferências de cada eleitor.
3. **Detecção de Pares**: Calcula a força das vitórias entre os pares de candidatos.
4. **Ordenação de Pares**: Os pares são ordenados pela força das vitórias.
5. **Bloqueio de Pares**: Tranca os pares sem criar ciclos.
6. **Vencedor**: O vencedor final é o candidato que não é derrotado por ninguém no gráfico de vitórias.

## Requisitos

- Linguagem C
- Biblioteca `cs50.h`

## Como Usar

1. Compile o código com:

    ```bash
    make tideman
    ```

2. Execute o programa com os candidatos como argumentos:

    ```bash
    ./tideman <candidato1> <candidato2> <candidato3> ...
    ```

3. O programa pedirá o número de eleitores e suas preferências.

## Funções principais

- **`vote()`**: Registra a votação de um eleitor.
- **`record_preferences()`**: Atualiza as preferências entre os candidatos.
- **`add_pairs()`**: Determina os pares vencedores.
- **`sort_pairs()`**: Ordena os pares por força de vitória.
- **`lock_pairs()`**: Tranca os pares sem criar ciclos.
- **`print_winner()`**: Exibe o vencedor final.

## Exemplo

### Entrada

```bash
./tideman Alice Bob Charlie
