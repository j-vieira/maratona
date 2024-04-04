#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct no {
    int chave;
    int conteudo;
    no* proximo;
};

struct listaEncadeada{
    no* inicio;
    int n;
};


void constroiLista(listaEncadeada *lista){
    lista->inicio = NULL;
    lista->n = 0;
}

void enumera(listaEncadeada *lista){
    no* proximo;
    proximo = lista->inicio;
    int n = 0;
    
    while(proximo != NULL){
        printf("chave:%d, conteudo:%d\n", proximo->chave, proximo->conteudo);
        proximo = proximo->proximo;
        n++;
    }
}


void destruir(listaEncadeada *lista){
    no* atual; no* proximo;
    proximo = lista->inicio;
    while(proximo != NULL){
        atual = proximo;
        proximo = proximo->proximo;
        free(atual);
    }
}
/*
    busca para lista encadeada nao ordenada
*/
int buscaListaNaoOrdenada(listaEncadeada *lista, int chave){ 
    no* atual;
    atual = lista->inicio;
    while(atual != NULL && chave != atual->chave){
        atual = atual->proximo;
    }
    if(atual != NULL){
        return atual->conteudo;
    }else{
        return -1;
    }
} 
/*
    busca em lista encadeada ordenada ou nao
*/
int buscaGeral(listaEncadeada *lista, int posicao){
    no* atual = lista->inicio;
    for(int i=1; i<posicao; i++){
        atual = atual->proximo;
    }
    return atual->conteudo;
}
/*
    busca para lista encadeada ordenada
*/
int buscaListaOrdenada(listaEncadeada *lista, int chave){
    no* atual = lista->inicio;
    while(atual != NULL && atual->chave < chave){
        atual = atual->proximo;
    }
    if(atual != NULL && atual->chave == chave){
        return atual->conteudo;
    }else{
        return -1;
    }
}

/*
    busca para lista encadeada ordenada
    que retorna onde o elemento deveria
    estar caso nao seja encontrado
*/
int varianteBuscaListaOrdenada(listaEncadeada *lista, int chave, no *anterior){
    no* atual = lista->inicio;
    anterior = NULL;

    while(atual != NULL && atual->chave < chave){
        atual = atual->proximo;
        anterior = atual;
    }
    if(atual != NULL && atual->chave == chave){
        return atual->conteudo;
    }else{
        return -1;
    }
}

int insere(listaEncadeada *lista, int chave, int conteudo){
    no* atual = lista->inicio;
    
    no* novo;
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->proximo = NULL;
    
    while(atual != NULL){
        atual = atual->proximo;
    }
    
    atual->proximo = novo;

    atual = novo;
}

int main(){
    listaEncadeada lista;
    constroiLista(&lista);
    enumera(&lista);
    printf("Lista construida.\n");
    return 0;
}