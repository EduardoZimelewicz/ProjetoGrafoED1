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
        g = insere_vertice_grafo(g);
        for(j = 1; j <= tamanho_grafo; j++){
            fscanf(f_grafo_e, "%d", &peso);
            if(peso != 0){
                g = insere_aresta_grafo(g, i, j, peso);
            }
        }
    }
    //Fim da leitura
    fclose(f_grafo_e);
    g = retira_repetidos_g(g);

    int rodando = 1;
    int ops; //opções de operações

    while(rodando){

    printf("Projeto de ED1: Grafos. Eduardo Zimelewicz e Paulo Vivas\n");
    printf("\n");
    printf("O projeto permite as seguintes operacoes no grafo lido do arquivo: GrafoEntrada.txt\n");
    printf("1)Inserir vertice\n");
    printf("2)Inserir aresta entre dois vertices\n");
    printf("3)Retirar um vertice\n");
    printf("4)Verificar se eh conexo\n");
    printf("5)Mostrar menor caminho entre dois vertices\n");
    printf("6)Imprime o grafo\n");
    printf("0)Para fechar o programa\n");

    scanf("%d", &ops);

    switch(ops){
    case 0:{
        rodando = 0;
        break;
    }
    case 1:{
        g = insere_vertice_grafo(g);
        break;
    }
    case 2:{
        int v1;
        int v2;
        int peso2;
        printf("Escolha os dois vertices e o peso:\n");
        printf("vertice 1:\n");
        scanf("%d", &v1);
        printf("vertice 2:\n");
        scanf("%d", &v2);
        printf("peso:\n");
        scanf("%d", &peso2);
        if(!existe_g(g, v1)){
            printf("O vertice 1 nao existe no grafo atual. Insira o seguinte vertice para realizar a operacao\n");
            break;
        }
        else if(!existe_g(g, v2)){
            printf("O vertice 2 nao existe no grafo atual. Insira o seguinte vertice para realizar a operacao\n");
            break;
        }
        g = insere_aresta_grafo(g, v1, v2, peso2);
        break;
        }
    case 3:{
        int v1;
        printf("Escolha o vertice para ser retirado:\n");
        scanf("%d", &v1);
        if(!existe_g(g, v1)){
            printf("O vertice escolhido nao existe no grafo atual\n");
            break;
        }
        else{
            g = retira_g(g, v1);
        }
        break;
    }
    case 4:{
        if(conexo(g)){
            printf("O grafo eh conexo\n");
            break;
        }
        else{
            printf("O grafo nao eh conexo\n");
        }
        desmarcar_todos(g);
        break;
    }
    case 5:{
        printf("Escolha os dois vertices:\n");
        int v1, v2, resultado;
        printf("vertice 1:\n");
        scanf("%d", &v1);
        printf("vertice 2:\n");
        scanf("%d", &v2);
        if(!existe_g(g, v1)){
            printf("O vertice 1 nao existe no grafo atual. Insira o seguinte vertice para realizar o calculo\n");
            break;
        }
        else if(!existe_g(g, v2)){
            printf("O vertice 2 nao existe no grafo atual. Insira o seguinte vertice para realizar o calculo\n");
            break;
        }
        resultado = menor_caminho(g, v1, v2);
        printf("O menor caminho do vertice %d ao %d eh: %d\n", v1, v2, resultado);
        desmarcar_todos(g);
        break;
    }
    case 6:
        imprime_grafo(g);
        printf("\n");
        break;
    default:
        printf("O operaçao escolhida nao existe\n");
        break;
    }

     //Teste operações no grafo
    /*
    imprime_grafo(g);
    printf("\n");

    printf("%d\n", conexo(g));
    printf("%d\n", menor_caminho(g, 2, 6));
    //Fim dos testes
    */

    }

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
    int mat_de_imp [tamanho_grafo][tamanho_grafo];
    for(i = 0; i < tamanho_grafo; i++){
        for(j = 0; j < tamanho_grafo; j++){
            mat_de_imp[i][j] = 0;
        }
    }

    i = 0;
    j = 0;
    g_temp = g;
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
