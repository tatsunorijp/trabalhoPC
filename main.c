#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void get_arq(FILE *q, int quantLinhas, int quantAtributos, float matriz[][quantAtributos]){
    char c, i = 0, j = 0;
    char linha[1000],buffer[100];
    char *aux;

    while(!feof(q)){
        fgets(linha,1000,q);

        aux = strtok(linha,",");
        while(aux != NULL){
            matriz[i][j] = *aux;
            j++;
            aux = strtok(NULL,",");
        }
        j=0;
        i++;
    }
}


void main(int argc, char *argv[]) {
    int natributos, nlinhasbase, nlinhasteste;
    char *nomeArquivoBase = (char*)malloc(20 * sizeof(char));
    char *nomeArquivoTeste = (char*)malloc(20 * sizeof(char));

    FILE *arquivoBase;
    FILE *arquivoTeste;

    nomeArquivoBase = argv[1];
    nomeArquivoTeste = argv[2];

    natributos = atoi(argv[3]);
    nlinhasteste = atoi(argv[4]);
    nlinhasbase = atoi(argv[5]);

    float base[nlinhasbase][natributos];
    float teste[nlinhasteste][natributos];

    arquivoBase = fopen(nomeArquivoBase, "r");
    arquivoTeste = fopen(nomeArquivoTeste, "r");

    get_arq(arquivoBase,nlinhasbase,natributos,base);
    get_arq(arquivoTeste,nlinhasteste,natributos,teste);
}