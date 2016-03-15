#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    //Leitura do arquivo
    int tamanho_grafo = 0;
    FILE * f_grafo_e;
    f_grafo_e = fopen("GrafoEntrada.txt", "r");

    if(f_grafo_e == NULL){
        printf("Erro na leitura do arquivo");
        return 1;
    }

    fscanf(f_grafo_e, "%d", &tamanho_grafo);

    int i,j;
    int peso = 0;
    Grafo * g = cria_grafo();

    //Inserçao no grafo
    for(i = 1; i <= tamanho_grafo; i++){
        g = insere_vertice_grafo(g, i);
        for(j = 1; j <= tamanho_grafo; j++){
            fscanf(f_grafo_e, "%d", &peso);
            if(peso != 0){
                g = insere_aresta_grafo(g, i, j, peso);
            }
        }
    }
    //Fim da leitura
    fclose(f_grafo_e);

    //Teste operações no grafo
    g = retira_repetidos_g(g);

    imprime_grafo(g);
    printf("\n");

    printf("%d\n", conexo(g));

    imprime_grafo(g);
    printf("\n");
    //Fim dos testes

    //Escrita do Arquivo
    FILE * f_grafo_s;
    f_grafo_s = fopen("GrafoSaida.txt", "w");

    if(f_grafo_s == NULL){
        printf("Erro na leitura do arquivo");
        return 1;
    }

    tamanho_grafo = numero_de_nos(g);
    Grafo * g_temp = g;
    ListaViz * l_temp = NULL;

    //Criação da matriz de impressão
    g_temp = g;
    int mat_de_imp [tamanho_grafo][tamanho_grafo];
    for(i = 0; i < tamanho_grafo; i++){
        for(j = 0; j < tamanho_grafo; j++){
            mat_de_imp[i][j] = 0;
        }
    }

    i = 0;
    j = 0;
    while(g_temp != NULL){
        l_temp = retorna_lista(g_temp);
        while(l_temp != NULL){
            if(i != j){
                mat_de_imp[i][j] = retorna_peso(l_temp);
                l_temp = retorna_prox_l(l_temp);
            }
            j++;
        }
        g_temp = retorna_prox_g(g_temp);
        j = 0;
        i++;
    }

    fprintf(f_grafo_s, "%d\n", tamanho_grafo);

    for(i = 0; i < tamanho_grafo; i++){
        for(j = 0; j < tamanho_grafo; j++){
           fprintf(f_grafo_s,"%d ", mat_de_imp[i][j]);
        }
        fprintf(f_grafo_s,"\n");
    }
    //Término da escrita

    destroi_grafo(g);

    fclose(f_grafo_s);

    return 0;
}
