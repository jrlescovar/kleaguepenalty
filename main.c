#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"
#include "./comandos/ligaBrasil.h"
#include "./comandos/listaEncadeada.h"

int main(void){
	int rodada;
	int buscar;
	char confirmaLocal,confirmaTime,timeConfirmado,menuSelecionado;
	system("mode con: cols=120 lines=30");
	tree *raiz = NULL; //Times Brasilerios
	tree *resultado = NULL; // times Brasilerios
	tree *moverTimesParaLista = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticos(&raiz); // INSERIR DADOS LIGA BRASIL
	SemanaBrasil* campeonatoBrasil = gerarPartidas();// gerar partidas  Ligas BRasil;
	listaDupla *listaBrasil = NULL; //CRIAR A LISTA PARA OS TIME BR
	//exibirLista(lista);
	//imprimeEmOrdem(raiz);
	tela1();
	system("cls");
	
	while (kbhit()) {
        getch();  // Descarta as teclas pendentes na fila de entrada
    }
    
    
    //jogo começa aqui " "
	do {
	    fflush(stdin);
	    confirmaLocal = tela2(); // TELA DE CONFIRMAR NACIONALIDADE
	    if (confirmaLocal == 27) {
	        break; // Sai do loop sem mostrar mensagem
	    }
	
	    switch (confirmaLocal) {
	        case '1':
	           do {
				    confirmaTime = telaBrasil();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
				
				
				    if (confirmaTime >= '0' && confirmaTime <= '9') {  //TECLA DE 0 a 10 for apertada
				        buscar = confirmaTime - '0';
				
				        // Se o código for 0, muda para 10
				        if (buscar == 0) {
				            buscar = 10;  // Muda o ID para 10 quando escolher '0'
				        }
				        resultado = buscaPorCodigo(raiz, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultado,"KL PENALTY - BRASIL",14,2,2,14,14);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".

				            	int x = 1;
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
				            	rodada = 1;
				                do{
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada
				                	menuSelecionado = ligaBrasil(listaBrasil,buscar,campeonatoBrasil,rodada);
				                	switch(menuSelecionado){
				                		case 'E':
				                			gerenciarElenco(&listaBrasil,resultado);
				                		case 'N':
				                			if(rodada != 1){
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 9){
				                				rodada++;
				                			}
				                		break;
				                		default:
				                				if(menuSelecionado == 27)
				                					menuSelecionado = 'o';
				                			break;
				                			
				                	}
				                }while(menuSelecionado != 27);
				                
				            }
				            else if (timeConfirmado != 27){//Se aperta tecla errada exibe msg, aperta ESC fecha o JOGO
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
	} while(confirmaLocal != 27);

	clrscr();
    printf("\nEntrar Tela de Encerramento aqui.");
	return 0; // FIM
}
