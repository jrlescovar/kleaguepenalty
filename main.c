#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"

int main(void){
	system("mode con: cols=120 lines=30");
	//tree *raiz = NULL;
	//dadosAutomaticos(&raiz);
	tela1();
	
	clrscr();
	printf("Tela 1 finish, entrar em Cena agora a Tela 2"); 
	getch();

    //imprimeEmOrdem(raiz);
	return 0; // FIM
}
