#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/dadosAutomaticosEspanha.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"
#include "./comandos/ligaBrasil.h"
#include "./comandos/ligaEspanha.h"
#include "./comandos/listaEncadeada.h"
#include "./comandos/jogoRodando.h"
#include "./comandos/cartas.h"
#include "./comandos/limpar_mensagem.h"

 
int main(void){
	srand(time(NULL));//inicializar sistema de sorteio.
	int rodada,rodadaOficial,rodadaPlayoffBrasil = 0,buscar;
	char confirmaLocal,confirmaTime,timeConfirmado,menuSelecionado,passarPagina;
	system("mode con: cols=120 lines=30");//padronizar tela "creio eu que ta mudando nada rs"
	//LIGA BRASIL TUDO AQUI ABAIXO.
	tree *raiz = NULL; //Times Brasilerios
	tree *resultado = NULL; // times Brasilerios
	tree *moverTimesParaLista = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	// INSERIR DADOS LIGA BRASIL
	dadosAutomaticos(&raiz);
	SemanaBrasil* campeonatoBrasil = gerarPartidas();// gerar partidas  Ligas BRasil;
	listaDupla *listaBrasil = NULL; //CRIAR A LISTA PARA OS TIME BR
	listaDupla *listaTabela = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semana = malloc(sizeof(SemanaBrasil)); //buscar o jogos dessa rodada
	Confronto *confronto = malloc(sizeof(Confronto));
	//playoffsBrasil
	playoffsConfrontos *jogosQuartasBrasil;jogosQuartasBrasil= malloc(sizeof(playoffsConfrontos));//usa 1-2-3 confrontos
	playoffsConfrontos *jogosSemiBrasil;jogosSemiBrasil = malloc(sizeof(playoffsConfrontos));//usa 1-2 confrontos
	
	//LIGA ESPANHA ABAIXO.
	tree *raizEspanha = NULL; //Times Brasilerios
	tree *resultadoEspanha = NULL; // times Brasilerios
	tree *moverTimesParaListaEspanha = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosEspanha(&raizEspanha);
	SemanaBrasil* campeonatoEspanha = gerarPartidasEspanha();// gerar partidas  Ligas BRasil;
	listaDupla *listaEspanha = NULL; //CRIAR A LISTA PARA OS TIME BR
	listaDupla *listaTabelaEspanha = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaEspanha  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoEspanha = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosEspanha;jogosEspanha= malloc(sizeof(playoffsConfrontos));
	
	
	tela1(); //tela de abertura apenas.
	system("cls");
	
	while (kbhit()) { //caso seleciona 1 e ao mesmo tempo aperte outras teclas
        getch();  // Descarta as teclas pendentes na fila de entrada
    }
    
    //jogo começa aqui " "
	do {
	    fflush(stdin);
	    confirmaLocal = tela2(); // TELA DE CONFIRMAR NACIONALIDADE "selecionar se vai jogar na liga do brasil, espanha etc...
	    if (confirmaLocal == 27) { 
	        break; // Sai do loop sem mostrar mensagem
	    }
	    switch (confirmaLocal) { 
	        case '1'://escolheu liga brasil
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
				            timeConfirmado = teladoTime(resultado,"KL PENALTY - BRASIL",14,2,2,14,14,1);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
				            	int x = 1;
								while( x <= 10){
									moverTimesParaLista = buscaPorCodigo(raiz, x);
									inserirLista(&listaBrasil, moverTimesParaLista);
									x++;
									
								}
				            	rodada = 1;
				                do{
				                	//criarQuartas
				                	if(rodadaOficial == 10){
				                		listaTabela = copiarLista(listaBrasil);//salva a tabela para nao exiber novas informações do playoffs
										criarQuartasBR(&jogosQuartasBrasil,listaBrasil);
				                	}
				                	//criarSemiFinal
				                	if(rodadaOficial == 11){
				                		criarSemiBR(jogosQuartasBrasil,&jogosSemiBrasil,listaBrasil);
				                	}
				                	//criarSemiFinak
									if(rodadaOficial == 12){
				                		criarFinalBr(&jogosSemiBrasil,listaBrasil);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOsSeteMelhores(listaBrasil,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaBrasil(listaBrasil,listaTabela,buscar,campeonatoBrasil,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
				                			if(rodadaOficial <= 9){
				                				semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
												semana = semana->prox;
				                				rodadaOficial++;
				                			}
				                			if(rodadaOficial < 10)//chegar em 10 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                				
				                				
				                			
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 9){
				                				semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,0);
													confronto = confronto->prox;
												}while(confronto != NULL);
												semana = semana->prox;
				                				rodadaOficial++;
				                			}
				                			if(rodadaOficial<10)//chegar em 10 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima;
				                			//PlayOffs
				                			if(rodadaOficial >= 10 && rodadaOficial < 13){
				                				if(rodadaOficial == 10){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->primeiroConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->segundoConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->terceiroConfronto,1);
					                			}
					                			
					                			if(rodadaOficial == 11){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->primeiroConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->segundoConfronto,1);
					             
					                			}
					                			
					                			if(rodadaOficial == 12){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->terceiroConfronto,1);
					                			}
					                			rodadaOficial++;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial==10){
				                					clrscr();
				                					if(playoffJogos != 1){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil);
				                				}
				                				if(rodadaOficial==11){
				                					clrscr();
				                					exibirPlayoffsSemiFinalBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil, jogosSemiBrasil);
				                				}
				                				if(rodadaOficial==12){
				                					clrscr();
				                					exibirPlayoffsFinalBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil,jogosSemiBrasil);
				                				}
				                				if(rodadaOficial == 13){
				                					clrscr();
				                					acabouLigaBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil,jogosSemiBrasil);
				                				}
												if(rodadaOficial <10){
											        gotoxy(39, 19);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 10 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaBrasil,resultado,1);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaBrasil);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaBrasil);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaBrasil);
				                				}
				                			}while(passarPagina != 27);
				                		break;
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
	            
			case '2':
				do {
				    confirmaTime = telaEspanha();//TELA DE CONFIRMAR TIME 
				    if (confirmaTime == 27)
				        break; // sai da seleção de time volta para seleção de NACIONALIDADE
				
					
				    if ((confirmaTime >= '0' && confirmaTime <= '9') || confirmaTime == 'W' || confirmaTime == 'E') {  // TECLA DE 0 a 9 ou W/E
					    buscar = confirmaTime - '0';
					
					    // Se o código for 0, muda para 10
					    if (buscar == 0) {
					        buscar = 10;  // Muda o ID para 10 quando escolher '0'
					    }
					    if (confirmaTime == 'W') {
					        buscar = 11;  // Muda o ID para 11 quando escolher 'W'
					    }
					    if (confirmaTime == 'E') {
					        buscar = 12;  // Muda o ID para 12 quando escolher 'E'
					    }
				        resultadoEspanha = buscaPorCodigo(raizEspanha, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoEspanha,"KL PENALTY - ESPANHA",4,4,4,14,14,2);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
				            	int x = 1;
								while( x <= 12){
									moverTimesParaListaEspanha = buscaPorCodigo(raizEspanha, x);
									inserirLista(&listaEspanha, moverTimesParaListaEspanha);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	/*if(rodadaOficial == 12){
				                		listaTabelaEspanha = copiarLista(listaEspanha);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
				                	}
				                	//criarquartas
				                	if(rodadaOficial == 13){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
				                	}
				                	//criarSemis
									if(rodadaOficial == 14){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
				                	}*/
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOsSeteMelhores(listaEspanha,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaEspanha(listaEspanha,listaTabelaEspanha,buscar,campeonatoEspanha,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':				                			
				                			if(rodadaOficial <= 11){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,1);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
				                				rodadaOficial++;
				                			}
				                			if(rodadaOficial < 12)//chegar em 10 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 11){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,0);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
				                				//jogarBrasil(&listaBrasil,resultado,&campeonatoBrasil,rodadaOficial);
				                				rodadaOficial++;
				                			}
				                			
				                			if(rodadaOficial<12)//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima;
				                			//PlayOffs
				                			/*if(rodadaOficial >= 12 && rodadaOficial < 16){
				                				if(rodadaOficial == 12){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->primeiroConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->segundoConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->terceiroConfronto,1);
					                			}
					                			
					                			if(rodadaOficial == 13){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->primeiroConfronto,1);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->segundoConfronto,1);
					             
					                			}
					                			
					                			if(rodadaOficial == 14){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->terceiroConfronto,1);
					                			}
					                			rodadaOficial++;
				                			}
				                			*/
				                		break;
				                		case 'P':
				                			/*
				                				if(rodadaOficial==12){
				                					clrscr();
				                					if(playoffJogos != 1){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil);
				                				}
				                				if(rodadaOficial==11){
				                					clrscr();
				                					exibirPlayoffsSemiFinalBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil, jogosSemiBrasil);
				                				}
				                				if(rodadaOficial==12){
				                					clrscr();
				                					exibirPlayoffsFinalBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil,jogosSemiBrasil);
				                				}
				                				if(rodadaOficial == 13){
				                					clrscr();
				                					acabouLigaBrasil(rodadaOficial, listaBrasil, jogosQuartasBrasil,jogosSemiBrasil);
				                				}*/
												if(rodadaOficial <12){
											        gotoxy(39, 19);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 10 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaEspanha,resultadoEspanha,2);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaEspanha);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaEspanha);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaEspanha);
				                				}
				                			}while(passarPagina != 27);
				                		break;
				                		case 'N':
				                			if(rodada != 1){
				                				
				                				rodada--;
				                			}
				                		break;
				                		case 'M':
				                			if(rodada < 11){
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
	                teclaInvalida();//mensagem de tecla invalida...
	            }
	            break;
	    }
	} while(confirmaLocal != 27); //nao escolheu nada e apertou esc fecha o jogo.

	clrscr();
    printf("\nEntrar Tela de Encerramento aqui.");
	return 0; // FIM
}
