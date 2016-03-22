#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

typedef struct grafo Grafo;
typedef struct lista_viz ListaViz;
ListaViz * cria_lista_viz();
Grafo * cria_grafo();
int existe_g(Grafo * g, int info);
int menor_caminho(Grafo * g, int orig, int dest);
int menor_cam(Grafo * g, int orig, int dest, int custo);
ListaViz * retira_l_prim(ListaViz * l);
int existe_caminho(Grafo*g,int orig, int dest);
void existe_cam(Grafo * g, int orig, int dest);
void marcar(Grafo * g, int info);
void desmarcar(Grafo * g, int info);
void desmarcar_todos(Grafo * g);
int conexo (Grafo * g);
int visitados_g(Grafo * g);
int tamanho_g(Grafo * g);
void desmarca_vis(Grafo * g);
int numero_de_nos(Grafo * g);
ListaViz * insere_lista_viz(ListaViz * l, int info, int peso);
Grafo * busca_g(Grafo * g, int x);
int retorna_info_ult(Grafo * g);
Grafo * insere_vertice_grafo(Grafo * g);
Grafo * insere_aresta_grafo(Grafo * g, int valor1, int valor2, int peso);
void imprime_grafo(Grafo * g);
void destroi_lista_viz(ListaViz * l);
void destroi_grafo(Grafo * g);
ListaViz * retira_repetidos_l(ListaViz * l);
Grafo * retira_repetidos_g(Grafo * g);
Grafo * retorna_prox_g(Grafo * g);
ListaViz * retorna_prox_l(ListaViz * l);
ListaViz * retorna_lista(Grafo * g);
int retorna_peso(ListaViz * l);
int retorna_info (Grafo * g);
int retorna_info_l(ListaViz * l);
int retorna_tamanho_l(ListaViz * l);
int existe_l(ListaViz * l, int n);
ListaViz * busca_viz(ListaViz * l, int n);
ListaViz * retira_l(ListaViz * l, int info);
Grafo * retira_aresta(Grafo * g, int v1, int v2);
Grafo * retira_g (Grafo * g, int info);
void imprime_lista(ListaViz * l);
ListaViz * retorna_menor_caminho(Grafo * g);

#endif // GRAFO_H_INCLUDED
