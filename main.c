#include<conio2.h>
#include<stdio.h>
#include<stdlib.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"

int main(void){
	tree *raiz = NULL;
	dadosAutomaticos(&raiz);
    imprimeEmOrdem(raiz);
	return 0; // FIM
}
