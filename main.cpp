#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int info;
 struct nodo *prox;
}Nodo;

typedef struct nodo2{
 int info;
 struct nodo2 *ant, *prox;
}Nodo2;

//Escolhi apenas uma posição por causa da quantidade de
//elementos que tinha no vetor
Nodo vetAux[0];


//CRIAR
Nodo * criar_no(){
    Nodo *novo =(Nodo*)malloc(sizeof(Nodo));
    return novo;
}


//INSERIR
Nodo* inserir_no_inicio(Nodo * Lista, int dado){
    Nodo *novo_no=criar_no();
    novo_no->info=dado;

    if(Lista == NULL){
        Lista=novo_no;
        novo_no->prox=NULL;
    }else{ novo_no->prox=Lista;
           Lista=novo_no;
         }
         return Lista;
}


int vet[3];
void organizar(Nodo *Lista){
    Nodo *aux = Lista;

    int i = -1;
    while(aux!=NULL){
            i++;
            vet[i]=aux->info;
            aux=aux->prox;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(vet[i]==vet[j]){
                vetAux[0].info = vet[i];
            }
        }
    }
}


int main(){
    Nodo * Lista=NULL;
    Nodo2 * Lista2=NULL;

    Lista=inserir_no_inicio(Lista,2);
    Lista=inserir_no_inicio(Lista,0);
    Lista=inserir_no_inicio(Lista,2);

    organizar(Lista);
    printf("O elemento repetido foi: %i ",*vetAux);
    return 0;
}
