#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct grafo {
    int dist; //dist�ncia para Dijkstra
    int info;
    struct lista_viz * lista_de_viz;
    struct grafo * prox; //pr�ximo na lista do grafo;
}Grafo;

typedef struct lista_viz {
    int peso;
    int info;
    struct lista_viz * prox; //pr�ximo na lista de vizinhos
}ListaViz;

ListaViz * cria_lista_viz(){
    ListaViz * l = (ListaViz *) malloc (sizeof(ListaViz));
    l = NULL;
    return l;
}

Grafo * cria_grafo(){
    Grafo * g = (Grafo *) malloc (sizeof(Grafo));
    g = NULL;
    return g;
}


int numero_de_nos(Grafo * g){
    Grafo * temp = g;
    int numero = 0;
    while(temp != NULL){
        numero++;
        temp = temp->prox;
    }
    return numero;
}

ListaViz * insere_lista_viz(ListaViz * l, int info, int peso){
    ListaViz * nova = (ListaViz *) malloc (sizeof(ListaViz));
    nova->peso = peso;
    nova->info = info;
    nova->prox = NULL;

    if(l == NULL){
         return nova;
    }

    else{
        ListaViz * temp = l;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = nova;
        return l;
    }
}

Grafo * insere_vertice_grafo(Grafo * g, int info){
    Grafo * novo = (Grafo *) malloc (sizeof(Grafo));
    novo->dist = 0;
    novo->info = info;
    novo->lista_de_viz = NULL;
    novo->prox = NULL;

    if(g == NULL){
        return novo;
    }

    else{
        Grafo * temp = g;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novo;
        return g;
    }
}

Grafo * insere_aresta_grafo(Grafo * g, int valor1, int valor2, int peso){
    Grafo * temp = g;
    while(temp != NULL){
        if(temp->info == valor1){
            temp->lista_de_viz = insere_lista_viz(temp->lista_de_viz, valor2, peso);
        }

        if(temp->info == valor2){
            temp->lista_de_viz = insere_lista_viz(temp->lista_de_viz, valor1, peso);
        }

        temp = temp->prox;
    }

    return g;
}

void imprime_grafo(Grafo * g){
    Grafo * temp = g;
    while(temp != NULL){
        printf("vizinhos do no %d: ", temp->info);
        ListaViz * l_temp = temp->lista_de_viz;
        while(l_temp != NULL){
            printf(" || %d, custo: %d ", l_temp->info, l_temp->peso);
            l_temp = l_temp->prox;
        }
        printf("\n");
        temp = temp->prox;
    }
}

void destroi_lista_viz(ListaViz * l){
    if(l != NULL){
       destroi_lista_viz(l->prox);
       free(l);
    }
}

void destroi_grafo(Grafo * g){
    if(g != NULL){
        destroi_grafo(g->prox);
        destroi_lista_viz(g->lista_de_viz);
        free(g);
    }
}


ListaViz * retira_repetidos_l(ListaViz * l){
    ListaViz * l_temp1 = l;
    ListaViz * l_temp2 = l;
    ListaViz * l_ant = NULL;
    while(l_temp1 != NULL){
        while(l_temp2->prox != NULL){
            l_ant = l_temp2;
            l_temp2 = l_temp2->prox;

            if(l_temp2->info == l_temp1->info){
                l_ant->prox = l_temp2->prox;
                l_temp2 = l_ant;
                l_ant = NULL;
            }
        }
        l_temp1 = l_temp1->prox;
        l_temp2 = l_temp1;
    }

    return l;
}

Grafo * retira_repetidos_g(Grafo * g){
    Grafo * g_temp = g;
    while(g_temp != NULL){
        retira_repetidos_l(g_temp->lista_de_viz);
        g_temp = g_temp->prox;
    }
    return g;
}

Grafo * retorna_prox_g(Grafo * g){
    return g->prox;
}

ListaViz * retorna_prox_l(ListaViz * l){
    return l->prox;
}

ListaViz * retorna_lista(Grafo * g){
    return g->lista_de_viz;
}

int retorna_peso(ListaViz * l){
    return l->peso;
}

int busca_viz(ListaViz * l, int n){
    ListaViz * l_temp = l;
    while(l_temp->prox != NULL && n != l_temp->info){
        l_temp = l_temp->prox;
    }
    if(n == l_temp->info){
        return 1;
    }
    return 0;
}
