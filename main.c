#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "./comandos/dadosAutomaticos.h"
#include "./comandos/dadosAutomaticosEspanha.h"
#include "./comandos/dadosAutomaticosItalia.h"
#include "./comandos/dadosAutomaticosAmericas.h"
#include "./comandos/times.h"
#include "./comandos/visual.h"
#include "./comandos/ligaBrasil.h"
#include "./comandos/ligaEspanha.h"
#include "./comandos/ligaItalia.h"
#include "./comandos/ligaAmericas.h"
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
	playoffsConfrontos *jogosEspanha; jogosEspanha= malloc(sizeof(playoffsConfrontos));
	//liga Italia.
	tree *raizItalia = NULL; //Times Brasilerios
	tree *resultadoItalia = NULL; // times Brasilerios
	tree *moverTimesParaListaItalia = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosItalia(&raizItalia);
	SemanaBrasil* campeonatoItalia = gerarPartidasItalia();// gerar partidas  Ligas BRasil;
	listaDupla *listaItalia = NULL; //CRIAR A LISTA PARA OS TIME BR
	listaDupla *listaTabelaItalia = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaItalia  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoItalia = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosItalia; jogosItalia= malloc(sizeof(playoffsConfrontos));
	
	//liga americas ABAIXO
	tree *raizAmericas = NULL; //Times Brasilerios
	tree *resultadoAmericas = NULL; // times Brasilerios
	tree *moverTimesParaListaAmericas = NULL; //Pegar os times da Arvore e inserir na Lista de times 
	dadosAutomaticosAmericas(&raizAmericas);
	SemanaBrasil* campeonatoAmericas = gerarPartidasAmericas();// gerar partidas  Ligas BRasil;
	listaDupla *listaAmericas = NULL; //CRIAR A LISTA PARA OS TIME BR
	listaDupla *listaTabelaAmericas = NULL; //Cria para salvar tabela antes dos dados do playoffs
	SemanaBrasil *semanaAmericas  = malloc(sizeof(SemanaBrasil)); 
	Confronto *confrontoAmericas = malloc(sizeof(Confronto));
	playoffsConfrontos *jogosAmericas; jogosAmericas= malloc(sizeof(playoffsConfrontos));
	
	
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
													jogarConfronto(&listaBrasil,resultado,&confronto,1,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
												semana = semana->prox;
				                				rodadaOficial++;
				                				if(rodadaOficial != 10)//chegar em 10 para para nao exibir vento...
				                					rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                				break;	
				                			}
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
				                		case 'J':
				                			if(rodadaOficial <= 9){
				                				semana = buscarSemana(campeonatoBrasil, rodadaOficial); //buscar o jogos dessa rodada
												confronto = semana->primeiroConfronto;
												do{
													jogarConfronto(&listaBrasil,resultado,&confronto,0,1);
													confronto = confronto->prox;
												}while(confronto != NULL);
												semana = semana->prox;
				                				rodadaOficial++;
				                				if(rodadaOficial != 10)//chegar em 10 para para nao exibir vento...
				                					rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
				                				break;	
				                			}//mudar a pagina da rodada para a proxima;
				                			//PlayOffs
				                			if(rodadaOficial >= 10 && rodadaOficial < 13){
				                				if(rodadaOficial == 10){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->primeiroConfronto,0);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->segundoConfronto,0);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosQuartasBrasil->terceiroConfronto,0);
					                			}
					                			
					                			if(rodadaOficial == 11){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->primeiroConfronto,0);
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->segundoConfronto,0);
					             
					                			}
					                			
					                			if(rodadaOficial == 12){
					                				jogarConfrontoPlayoff(&listaBrasil,resultado,&jogosSemiBrasil->terceiroConfronto,0);
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
				                					passarPagina = exibirEstatisticas(listaBrasil,1);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaBrasil,1);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaBrasil,1);
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
				                	if(rodadaOficial == 12){
				                		listaTabelaEspanha = copiarLista(listaEspanha);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffEspanha(&jogosEspanha,listaEspanha,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,4);
				                	}
				                	if(rodadaOficial == 16){
				                		criarPlayoffEspanha(&jogosEspanha,listaEspanha,5);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaEspanha,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaEspanha(listaEspanha,listaTabelaEspanha,buscar,campeonatoEspanha,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);			                			
				                			if(rodadaOficial < 12){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,1,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
				                				rodadaOficial++;
				                				
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosEspanha->playin1Confronto && jogosEspanha->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin2Confronto,1);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 11){
				                				semanaEspanha = buscarSemana(campeonatoEspanha, rodadaOficial); //buscar o jogos dessa rodada
												confrontoEspanha = semanaEspanha->primeiroConfronto;
												do{
													jogarConfronto(&listaEspanha,resultadoEspanha,&confrontoEspanha,0,2);
													confrontoEspanha = confrontoEspanha->prox;
												}while(confrontoEspanha != NULL);
												semanaEspanha = semanaEspanha->prox;
				                				rodadaOficial++;
				                			}
				                			
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;
												break; //mudar a pagina da rodada para a proxima;
											}
				                			if(rodadaOficial == 12){
			                					if (jogosEspanha->playin1Confronto && jogosEspanha->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin2Confronto,0);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->playin3Confronto,0);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->q3Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->s2Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaEspanha,resultadoEspanha,&jogosEspanha->finalConfronto,0);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsEspanha(rodadaOficial, listaEspanha, jogosEspanha,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
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
				                					passarPagina = exibirEstatisticas(listaEspanha,2);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaEspanha,2);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaEspanha,2);
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
			case '4':
				do {
				    confirmaTime = telaItalia();//TELA DE CONFIRMAR TIME 
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
				        resultadoItalia = buscaPorCodigo(raizItalia, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoItalia,"KL PENALTY - ITALIA",10,15,15,10,4,3);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
				            	int x = 1;
								while( x <= 12){
									moverTimesParaListaItalia = buscaPorCodigo(raizItalia, x);
									inserirLista(&listaItalia, moverTimesParaListaItalia);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	if(rodadaOficial == 12){
				                		listaTabelaItalia = copiarLista(listaItalia);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffItalia(&jogosItalia,listaItalia,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffItalia(&jogosItalia,listaItalia,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffItalia(&jogosItalia,listaItalia,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffItalia(&jogosItalia,listaItalia,4);
				                	}
				                	if(rodadaOficial == 16){
				                		criarPlayoffItalia(&jogosItalia,listaItalia,5);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaItalia,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaItalia(listaItalia,listaTabelaItalia,buscar,campeonatoItalia,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);			                			
				                			if(rodadaOficial < 12){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoItalia,&confrontoItalia,1,3);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaItalia = semanaItalia->prox;
				                				rodadaOficial++;
				                				
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosItalia->playin1Confronto && jogosItalia->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin2Confronto,1);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 11){
				                				semanaItalia = buscarSemana(campeonatoItalia, rodadaOficial); //buscar o jogos dessa rodada
												confrontoItalia = semanaItalia->primeiroConfronto;
												do{
													jogarConfronto(&listaItalia,resultadoItalia,&confrontoItalia,0,3);
													confrontoItalia = confrontoItalia->prox;
												}while(confrontoItalia != NULL);
												semanaItalia = semanaItalia->prox;
				                				rodadaOficial++;
				                			}
				                			
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;
												break; //mudar a pagina da rodada para a proxima;
											}
				                			if(rodadaOficial == 12){
			                					if (jogosItalia->playin1Confronto && jogosItalia->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin2Confronto,0);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->playin3Confronto,0);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->q3Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->s2Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaItalia,resultadoItalia,&jogosItalia->finalConfronto,0);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsItalia(rodadaOficial, listaItalia, jogosItalia,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaItalia,resultadoItalia,3);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaItalia,3);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaItalia,3);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaItalia,3);
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
			case '3':
				do {
				    confirmaTime = telaAmericas();//TELA DE CONFIRMAR TIME 
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
				        resultadoAmericas = buscaPorCodigo(raizAmericas, buscar);  //Busca na arvore o TIME.
				        do {
				            timeConfirmado = teladoTime(resultadoAmericas,"KL PENALTY - AMERICAS",9,15,15,9,9,4);
				            if (timeConfirmado == 'S'){
				            	//Jogo "Roda aqui dentro".
								rodadaOficial = 1;
								rodada = 1;
				            	int x = 1;
								while( x <= 12){
									moverTimesParaListaAmericas = buscaPorCodigo(raizAmericas, x);
									inserirLista(&listaAmericas, moverTimesParaListaAmericas);
									x++;
									
								}
				                do{
				                	//criarPlayin
				                	if(rodadaOficial == 12){
				                		listaTabelaAmericas = copiarLista(listaAmericas);//salva a tabela para nao exiber novas informações do playoffs
										criarPlayoffAmericas(&jogosAmericas,listaAmericas,1);
				                	}
				                	//criarPlayin final
				                	if(rodadaOficial == 13){
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,2);
				                	}
				                	//criar quartas ultima quarta
									if(rodadaOficial == 14){
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,3);
				                	}
				                	if(rodadaOficial == 15){
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,4);
				                	}
				                	if(rodadaOficial == 16){
				                		criarPlayoffAmericas(&jogosAmericas,listaAmericas,5);
				                	}
				                	//                           listaTimes  codtime  jogosRodadas    NumRodada5
									int playoffJogos = estaEntreOs10Melhores(listaAmericas,buscar); //verificar se meu time jogara playoff
				                	menuSelecionado = ligaAmericas(listaAmericas,listaTabelaAmericas,buscar,campeonatoAmericas,rodada,playoffJogos,rodadaOficial);
				                	switch(menuSelecionado){
				                		case 'S':
											Sleep(100);			                			
				                			if(rodadaOficial < 12){
				                				semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoAmericas,&confrontoAmericas,1,4);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												semanaAmericas = semanaAmericas->prox;
				                				rodadaOficial++;
				                				
				                			}
				                			if(rodadaOficial < 12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial; //mudar a pagina da rodada para a proxima
												break;
				                			}
			                				if(rodadaOficial == 12){
			                					if (jogosAmericas->playin1Confronto && jogosAmericas->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin1Confronto,1);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin2Confronto,1);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin3Confronto,1);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q2Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q3Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s1Confronto,1);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s2Confronto,1);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->finalConfronto,1);
												rodadaOficial++;
												break;
				                			}
				                		break;
				                		case 'J':
				                			if(rodadaOficial <= 11){
				                				semanaAmericas = buscarSemana(campeonatoAmericas, rodadaOficial); //buscar o jogos dessa rodada
												confrontoAmericas = semanaAmericas->primeiroConfronto;
												do{
													jogarConfronto(&listaAmericas,resultadoAmericas,&confrontoAmericas,0,4);
													confrontoAmericas = confrontoAmericas->prox;
												}while(confrontoAmericas != NULL);
												semanaAmericas = semanaAmericas->prox;
				                				rodadaOficial++;
				                			}
				                			
				                			if(rodadaOficial<12){//chegar em 12 para para nao exibir vento...
				                				rodada = rodadaOficial;
												break; //mudar a pagina da rodada para a proxima;
											}
				                			if(rodadaOficial == 12){
			                					if (jogosAmericas->playin1Confronto && jogosAmericas->playin2Confronto){
			                						jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin1Confronto,0);
					                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin2Confronto,0);
					                				rodadaOficial++; 
			                					}
			                					break;
				                			}
				                			if(rodadaOficial == 13){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->playin3Confronto,0);
				                				rodadaOficial++; 
												break;
				                			}
				                			if(rodadaOficial == 14){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q1Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q2Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->q3Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 15){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s1Confronto,0);
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->s2Confronto,0);
				                				rodadaOficial++;
												break;
				                			}
				                			if(rodadaOficial == 16){
				                				jogarConfrontoPlayoff(&listaAmericas,resultadoAmericas,&jogosAmericas->finalConfronto,0);
												rodadaOficial++;
												break;
				                			}
				                			
				                		break;
				                		case 'P':
				                				if(rodadaOficial>=12){
				                					clrscr();
				                					if(playoffJogos == 0){
				                						printCentralizado("SEU TIME FOI ELIMINADO NA FASE DE GRUPOS!",28,15);
				                					}
				                					exibirPlayoffsAmericas(rodadaOficial, listaAmericas, jogosAmericas,rodadaOficial - 11);
				                				}
												if(rodadaOficial <12){
											        gotoxy(39, 29);
											        printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 12 - rodadaOficial);
											        gotoxy(119, 29);
											        Sleep(1200);
											        limparBufferTeclado();
											    }
											    
				                		break;
				                		case 'E':
				                			gerenciarElenco(&listaAmericas,resultadoAmericas,4);//(lista atualizada, arvoreFormação time)
				                		break;
				                		case 'W':
				                			passarPagina = 'A';
				                			do{
				                				if(passarPagina == 'A'){
				                					passarPagina = exibirEstatisticas(listaAmericas,4);
				                				}
				                				if(passarPagina == 'G')
				                				{
				                					passarPagina = exibirTopGoleiros(listaAmericas,4);
				                				}
				                				if(passarPagina == 'P'){
				                					passarPagina = exibirTopPresidentes(listaAmericas,4);
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
					
				}while (confirmaTime != 27); 
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
