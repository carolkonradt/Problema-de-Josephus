#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tadlib.h"

struct no{
    char nome[30];
    int num;
    struct no *prox;
};

struct listInfo{
    No *inicio;
    No *fim; /*para facilitar a identificação do último nó, que apontará para o primeiro*/
    int quant;
};

Lista* list_create(void){
    Lista *c;

    c=(Lista*)malloc(sizeof(Lista));
    c->inicio=NULL;
    c->fim=NULL;
    c->quant=0;
}

void list_empty(Lista*list){
    if(list->quant<=0)
        printf("A lista esta vazia!\n\n");

    else
        printf("A lista possui elementos\n\n");


}

void insert_beginning(Lista* list, char* name, int numero){
    No* novo_no;

    novo_no=(No*)malloc(sizeof(No));
    strcpy(novo_no->nome, name);
    novo_no->num=numero;

    novo_no->prox=list->inicio;
    list->inicio=novo_no;

    if(list->fim==NULL)/*significa que a lista está vazia*/
        list->fim=novo_no;

    list->fim->prox=list->inicio; /*faz o último nó apontar pro primeiro*/
    list->quant++;
    printf("Inserido com sucesso!\n\n");

}

void insert_ending(Lista* list, char* name, int numero){
    No* novo_no;

    novo_no=(No*)malloc(sizeof(No));
    strcpy(novo_no->nome, name);
    novo_no->num=numero;

    if(list->inicio==NULL){
        list->inicio=novo_no;
        list->fim=novo_no;
        list->fim->prox=list->inicio;
    }else{
        list->fim->prox=novo_no;/*coloca no final da lista*/
        list->fim=novo_no;/*atualiza o ponteiro fim*/
        list->fim->prox=list->inicio;/*faz o fim apontar para o início*/
    }

    list->quant++;
    /*printf("Inserido com sucesso!\n\n");*/
}

void insert_index(Lista* list, char* name, int numero, int posic){
    No* novo_no;
    No* p;
    No* aux;
    int i=1;

    p=list->inicio;

    if(posic<=0||(posic>list->quant+1))
        printf("A posicao nao e valida!\n\n");
    else{
        if(posic==1){
            insert_beginning(list, name, numero);
        }
        else{
            if(posic==(list->quant+1)){
                insert_ending(list, name, numero);
            }
            else{
                novo_no=(No*)malloc(sizeof(No));
                strcpy(novo_no->nome, name);
                novo_no->num=numero;

                while(i<posic-1){
                    p=p->prox;
                    i++;
                }

                aux=p->prox;
                p->prox=novo_no;
                novo_no->prox=aux;
                list->quant++;
                printf("Inserido com sucesso!\n\n");
            }
        }
    }
}

int remove_beginning(Lista* list){
    No *p;
    int j;

    if(list->inicio==NULL)
        printf("Nao e possivel remover, a lista esta vazia!\n\n");
    else{
        p=list->inicio;
        j=p->num;
        list->inicio=list->inicio->prox;
        list->fim->prox=list->inicio;

        free(p);
        list->quant--;

        /*printf("Removido com sucesso!\n\n");*/
    }
    return j;
}

int remove_index(Lista* list, int numero, int posant){/*remove na posição desejada*//*posant=posição anterior*/
    No *p;
    No *aux;
    int i=1, j, k, l;

    if(list->inicio==NULL){
        printf("A lista esta vazia!\n\n");
    }
    else{
        p=list->inicio;
        k=0;

        if(posant>0&&posant<(list->fim->num)){
            while(k<posant){
                p=p->prox;
                k=p->num;
            }
        }
        if(posant>=(list->fim->num) || posant<list->inicio->num){
            p=list->inicio;
            k=p->num;
        }
        printf("Primeira posicao: %d\n", k);
        if(numero<0){
            printf("Posicao invalida!\n\n");
        }
        else{
            if(numero==0){
                if(p==list->inicio){
                    j=remove_beginning(list);
                }
                else{
                    for(l=1; l<list->quant; l++){/*percorre para acessar a posição anterior a que se quer excluir*/
                        p=p->prox;
                    }
                    aux=p->prox;
                    p->prox=aux->prox;
                    j=aux->num;
                    free(aux);
                    list->quant--;
                }
            }
            else{
                while(i<numero){
                    p=p->prox;
                    i++;
                }

                if(p==list->fim){
                    j=remove_beginning(list);
                }
                else{
                    if(p->prox==list->fim){
                        aux=p->prox;/*guarda o ultimo*/
                        list->fim=p;/*o anterior vira o ultimo*/
                        list->fim->prox=list->inicio;
                        list->quant--;
                        free(aux);
                        j=aux->num;
                    }
                    else{
                        aux=p->prox;
                        p->prox=aux->prox;
                        j=aux->num;
                        free(aux);
                        list->quant--;

                    }
                }
            }
        }

    }
        return j;
}


int quantity(Lista* list){
    int quant;

    quant=list->quant;

    return quant;
}

void print_list(Lista* list){
    No *p;

    if(list->inicio==NULL)
        printf("A lista esta vazia!\n\n");
    else{
        p=list->inicio;

        /*printf("A lista possui %d elementos:\n", list->quant);*/
        printf("---------------\n");

        do{
            print_index(p);
            p=p->prox;
        }
        while(p!=list->inicio);

        printf("---------------\n\n\n");
    }
}


void sort_list(Lista* list){
    No* aux;
    int i, j, min, troca, vet[list->quant-1];

    aux=list->inicio;

    for(i=1; i<=(list->quant); i++){
        vet[i-1]=aux->num;
        aux=aux->prox;
        }

    for(i = 0; i <(list->quant-1); i++){ /*selection sort*/
        min = i;
        for(j = i+1; j <(list->quant); j++){
            if(vet[j]<vet[min])
                min=j;
        }
        if(i!=min){
            troca=vet[i];
            vet[i]=vet[min];
            vet[min]=troca;
        }
    }
    printf("Lista ordenada:\n---------------\n\n");
    for(i=0; i<(list->quant); i++){
        aux=list->inicio;

        while(vet[i]!=aux->num)
            aux=aux->prox;

        print_index(aux);
    }
    printf("---------------\n\n");
}


void print_index(No* nodo){
    if(nodo==NULL)
        printf("Nao e possivel imprimir esse elemento!\n\n");
    else{
        printf("%s %d\n", nodo->nome, nodo->num);
    }
}

void free_list(Lista *list){
    No *p;
    No *aux;

    list->fim->prox=NULL;
    if(list->quant == 0)
        printf("A lista esta vazia!\n\n");
    else{
        aux=list->inicio;
        while(aux!=NULL){
            p=aux;
            aux=aux->prox;
            free(p);
            list->quant--;
        }
    }
}


int maior(Lista* list){
    No* p;
    No* aux;
    int i=-100, j=1, k;

    if(list->inicio==NULL){
        printf("A lista esta vazia!\n\n");
        return NULL;
    }
    else{
        p=list->inicio;

        do{
            if(p->num>i){
                i=p->num; /*pega o maior número*/
                k=j; /*guarada a posição do nó*/
            }
            p=p->prox;
            j++;
        }while(p!=list->inicio);

        p=list->inicio;
        for(j=1; j<k-1; j++)
            p=p->prox;

        if(k==1){
            aux=p;
            list->inicio=p->prox;
            list->fim->prox=list->inicio;
        }
        else{
            aux=p->prox;
            p->prox=aux->prox;
        }

        free(aux);
        list->quant--;
        return i;
    }
}

int return_int(No* nodo){
    return nodo->num;
}

char return_string(No* nodo){
    return nodo->nome;
}
