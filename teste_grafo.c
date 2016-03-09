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

    fclose(f_grafo_e);

    //Teste operações no grafo
    g = retira_repetidos_g(g);
    g = insere_vertice_grafo(g, 6);
    g = insere_aresta_grafo(g, 3, 6, 13);

    imprime_grafo(g);
    printf("\n");

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

    i = 1;
    j = 1;

    fprintf(f_grafo_s, "%d\n", tamanho_grafo);

    while(g_temp != NULL && i <= tamanho_grafo){
            l_temp = retorna_lista(g_temp);
        while(j <= tamanho_grafo){
            if(l_temp == NULL){
                fprintf(f_grafo_s, "0 ");
            }

            else{
                if(busca_viz(l_temp, j) == 0){
                    fprintf(f_grafo_s, "0 ");
                }

                if(busca_viz(l_temp, j)){
                    fprintf(f_grafo_s, "%d ", retorna_peso(l_temp));
                    l_temp = retorna_prox_l(l_temp);
                }
            }

            j++;
    }

        fprintf(f_grafo_s, "\n");
        g_temp = retorna_prox_g(g_temp);
        i++;
        j = 1;
    }


    destroi_grafo(g);

    fclose(f_grafo_s);

    return 0;
}
