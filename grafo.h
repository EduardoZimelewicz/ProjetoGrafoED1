#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct lista_viz ListaViz;
typedef struct grafo Grafo;
Grafo * cria_grafo();
Grafo * retira_repetidos_g(Grafo * g);
ListaViz * retira_repetidos_l(ListaViz * l);
void destroi_grafo(Grafo * g);
void destroi_lista_viz(ListaViz * l);
Grafo * insere_vertice_grafo(Grafo * g, int info);
Grafo * insere_aresta_grafo(Grafo * g, int valor1, int valor2, int peso);
ListaViz * insere_lista_viz(ListaViz * l, int info, int peso);
void imprime_grafo(Grafo * g);
int numero_de_nos(Grafo * g);
Grafo * retorna_prox_g(Grafo * g);
ListaViz * retorna_prox_l(ListaViz * l);
int retorna_peso(ListaViz * l);
ListaViz * retorna_lista(Grafo * g);
int busca_viz(ListaViz * l, int n);

#endif // GRAFO_H_INCLUDED
