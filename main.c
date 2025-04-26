#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"

int main(void){
	char confirmaLocal,confirmaTime;
	system("mode con: cols=120 lines=30");
	//tree *raiz = NULL;
	//dadosAutomaticos(&raiz);
	//imprimeEmOrdem(raiz);
	tela1();
	system("cls");
	while (kbhit()) {
        getch();  // Descarta as teclas pendentes na fila de entrada
    }
	do{
		confirmaLocal = tela2();
		switch(confirmaLocal){
			case '1':
				clrscr();
				do{
					confirmaTime = telaBrasil();
				}
				while(confirmaTime != 27);
				clrscr();
			break;
			default:
				if (confirmaLocal != 0 && confirmaLocal != '\n' && confirmaLocal != 27) {
	                gotoxy(41, 29);
	                printf("SELECIONE UMA NACIONALIDADE VALIDA");
	                Sleep(1000);
	                gotoxy(41,29);
	                printf("                                   ");
            	}
			break;
				
		}
	}while(confirmaLocal != 27);
	clrscr();
    printf("\nEntrar Tela de Encerramento aqui.");
	return 0; // FIM
}
