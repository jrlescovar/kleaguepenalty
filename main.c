#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"

int main(void){
	char confirmaLocal,confirmaTime,timeConfirmado;
	system("mode con: cols=120 lines=30");
	tree *raiz = NULL;
	tree *resultado = NULL;
	int buscar;
	dadosAutomaticos(&raiz);
	//imprimeEmOrdem(raiz);
	tela1();
	system("cls");
	while (kbhit()) {
        getch();  // Descarta as teclas pendentes na fila de entrada
    }
	do {
	    fflush(stdin);
	    confirmaLocal = tela2();
	
	    if (confirmaLocal == 27) {
	        break; // Sai do loop sem mostrar mensagem
	    }
	
	    switch (confirmaLocal) {
	        case '1':
	           do {
				    confirmaTime = telaBrasil();
				
				    if (confirmaTime == 27)
				        break; // sair da seleção de times
				
				    if (confirmaTime >= '0' && confirmaTime <= '9') {
				        buscar = confirmaTime - '0';
				
				        // Se o código for 0, muda para 10
				        if (buscar == 0) {
				            buscar = 10;  // Muda o ID para 10 quando escolher '0'
				        }
				
				        resultado = buscaPorCodigo(raiz, buscar);
				
				        do {
				            timeConfirmado = teladoTime(resultado);
				            if (timeConfirmado == 'S') {
				                clrscr();
				                printf("TELA DE JOGO AQUI");
				                getch();
				            }
				            else if (timeConfirmado != 27) {
				                teclaInvalida();
				            }
				
				        } while (timeConfirmado != 27);
				    }
				
				} while (confirmaTime != 27);
	            break;
	
	        default:
	            if (confirmaLocal != '\n' && confirmaLocal != 0) {
	                teclaInvalida();
	            }
	            break;
	    }
	} while (confirmaLocal != 27);

	clrscr();
    printf("\nEntrar Tela de Encerramento aqui.");
	return 0; // FIM
}
