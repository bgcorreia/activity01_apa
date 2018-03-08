# Activity 01 - APA - UFPB

## Description

This project intends to implement the ordering algorithm Insertition and Selection Sort in C ++.

## Compilation/Linker

To compile/linker execute `make` in the clone directory.

Example:

```bash
user@host:~/activity01-apa$ make
Compilando arquivo objeto: ordenacao
user@host:~/activity01-apa$
```

## Execution

Then, execute the generated binary:

```bash
user@host:~/activity01-apa$ ./ordenacao -h

Uso: ./ordenacao [OPÇÕES]

OPÇÕES:

 -t [is|ss]     Tipo da Ordenação. P/ InsertionSort -> IS , SelectionSort -> SS.

                        Ex.: -t is | -t ss

 -i [Arquivo]   Defini o arquivo de entrada, com os valores a seremordenados.

                        Ex.: -i ./couting.txt | -i ~/ordenar.txt
                        

 -h      Mostra esta tela de ajuda e sai
 -v      Mostra a versão do programa e sai
 
   
Exemplo completo de uso:

./ordenacao -t ss -i entrada.txt 
```

