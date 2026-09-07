# Redes Neurais

Exemplos de redes neurais artificiais em C, baseados no livro sobre redes neurais.

## Requisitos

- Ubuntu ou outra distribuicao Linux
- GCC
- Biblioteca matematica padrao

Para instalar o GCC no Ubuntu:

```bash
sudo apt update
sudo apt install build-essential
```

## Compilacao

Entre no diretorio do primeiro exemplo:

```bash
cd livro_redes_neurais/code/rn_01
```

Compile com o GCC:

```bash
mkdir -p dist
gcc main.c -o dist/main -Wall -Wextra -lm
```

A opcao `-lm` vincula a biblioteca matematica, necessaria para a funcao `exp()`.
O diretorio `dist/` e ignorado pelo Git.

## Execucao

```bash
./dist/main
```

O programa solicita os parametros da rede, os dados de entrada e os valores esperados durante a execucao.
