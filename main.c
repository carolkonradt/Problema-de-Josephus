#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"tadlib.h"

int main()
{
    Lista* lista;
    int i, j, n=0, q, m=0, cont=0, k;
    srand(time(NULL));

    lista=list_create();

    printf("-----BEM VINDO AO PROBLEMA DE JOSEPHUS-----\n\n");
    printf("Insira a quantidade de soldados: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        insert_ending(lista, "Soldado", i);
    }

    q=quantity(lista);
    print_list(lista);
    m=0;/*indica o soldado eliminado, inicia zerado*/
    for(j=1; j<q; j++){
        cont=quantity(lista);
        i=rand()%(cont*2);
            if(i<cont)
                k=i;
            else{
                k=i%cont;
            }

        printf("Numero sorteado: %d\n", i);
        m=remove_index(lista, k, m);/*m= numero do soldado eliminado=posant*/
        printf("Eliminado: Soldado %d\n", m);
        print_list(lista);
    }
        printf("Sobrevivente:\n");
        print_list(lista);
        free_list(lista);

    return 0;
}
