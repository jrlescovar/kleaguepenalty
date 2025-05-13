#ifndef JOGORODANDO_H
#define JOGORODANDO_H7

void embaralhar(char *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void limparBufferTeclado() {
    while (kbhit()) getch();
}
int calcularPontuacaoGoleiro(int overall) {
    if (overall >= 90)
        return 6;
    else if (overall >= 86)
        return 5;
    else if (overall >= 83)
        return 4;
    else
        return 3;
}

void jogarConfronto(listaDupla **lista,tree *resultado,Confronto **confronto,int simula){
	clrscr();
	int i,y,penaltiTime, penaltiOponente,ok,quantidade,encontrado,qtdColocada,repetida,penalidade,teclacerta,conferirpenaltifora,paranaoexibirmesnagemdeteclaerrada;
	int cartaSecretaTime, cartaSecretaOponente,goldobro,goldobroOponente,valorFinal,CartaDefesaOponente,goldeouro = 0;
	char timeCarta,oponenteCarta;
	char tecla,chute;
	char opcoes[10] = {49, 50, 51, 52, 53, 54, 55, 56, 57, 67}; //Simular Pulo ou Chute;
	char cartas[4] = {49,50,49,50}; //oficial
	//char cartas[4] = {49,49,49,49}; //teste
	char penaltiFora[5] = {4,2,5,4,5};
	char defesa[9];
	listaDupla *meuTime = buscarTimeNaLista(*lista, resultado->time.codigo);
	listaDupla *timeCasa = buscarTimeNaLista(*lista, (*confronto)->codigo1);
	listaDupla *timeFora = buscarTimeNaLista(*lista, (*confronto)->codigo2);
	
	
	if(((*confronto)->codigo1 == meuTime->info.elenco.codigo || (*confronto)->codigo2 == meuTime->info.elenco.codigo ) && simula == 0){
		MolduraColorida(1,1,120,30,2,2,14,14); 
		//sortear cartas
		penaltiTime = 1; //adicionar penalti presidente
		penaltiOponente = 1; //adicionar penalti presidente
		cartaSecretaTime = 1; //adicionar carta secreta time
		cartaSecretaOponente = 1; //adicionar carta secreta oponente
		paranaoexibirmesnagemdeteclaerrada = 0;
		embaralhar(cartas,4);
		timeCarta = cartas[0];
		oponenteCarta = cartas[1];
		CartaDefesaOponente = 0;
		if(oponenteCarta == '2'){
			cartaSecretaOponenteFora(13);
			CartaDefesaOponente = rand() %5;
			CartaDefesaOponente = (CartaDefesaOponente * 2) + 1;
		}
		
		if((*confronto)->codigo1 == resultado->time.codigo){
			if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeFora->info.elenco.jogador1.overall,
		        timeFora->info.elenco.jogador2.overall,
		        timeFora->info.elenco.jogador3.overall,
		        timeFora->info.elenco.jogador4.overall,
		        timeFora->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
		
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
		    int escolhido = candidatos[rand() % qtd];
		
		    // Aplicar fórmula: 1, 3, 5, 7, 9
		    valorFinal = (escolhido * 2) + 1;
			}else{
				valorFinal = 0;
			}
		}else{
			if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeCasa->info.elenco.jogador1.overall,
		        timeCasa->info.elenco.jogador2.overall,
		        timeCasa->info.elenco.jogador3.overall,
		        timeCasa->info.elenco.jogador4.overall,
		        timeCasa->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
		
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
		    int escolhido = candidatos[rand() % qtd];
		
		    valorFinal = (escolhido * 2) + 2;
			}else{
				valorFinal = 0;
			}
		}
		embaralhar(penaltiFora,5);
		conferirpenaltifora = 0;
		goldobro = 0;
		goldobroOponente =0;
		//Ordem das batidas;
		if((*confronto)->codigo1 == resultado->time.codigo)
			y = 1; //selecionar casa ou fora
		else
			y = 2;//selecionar casa ou fora
		//alterar para 10.
		while(y <= 10){
			if(y % 2!=0){
				//começa batendo
				//primeiro bater o penalti
				do{
					ok = 0; //conferir TECLA APERTADA
					do{
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){ //posicionar nome do time casa
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);//posicionar nome do time casa
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);//posicionar nome do time casa
						}
						gotoxy(58,4);textcolor(15); //colocar placar
				        printf("%d",(*confronto)->placarCasa); //colocar placar
				        gotoxy(60,4);
				        printf("X"); //colocar placar
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora); //colocar placar
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora); //posicionar nome do time fora
				        textcolor(15);
						exibirTrave(); //area do gol
						
						//carta presidente
						if(penaltiTime == 1) //se o penalti nao foi batido
							cartaPenaltiCasa();
							
						if(penaltiOponente == 1)//se o penalti nao foi batido
							cartaPenaltiForaOponente();
						
		
						if(cartaSecretaTime  == 1){//carta secreta foi usada
							if(timeCarta == '1')
								cartaSecretaCasa(timeCarta,4);
							if(timeCarta == '2')
								cartaSecretaCasa(timeCarta,13);
						}
							
						if(cartaSecretaOponente == 1){//carta secreta foi usada
							if(oponenteCarta == '1')
								cartaSecretaOponenteFora(4);
							if(oponenteCarta == '2'){
								cartaSecretaOponenteFora(13);
							}
						}	
						gotoxy(7,5);
						printf("                                                                                                              ");
						gotoxy(9,5);
						printf("MINHAS CARTAS"); //posicionar escrita pra gameplay
						gotoxy(96,5);
						printf("ADVERSARIO CARTAS"); //posicionar escrita pra gameplay
						gotoxy(30,26);
						//Quem vai bater na BOLA...
						quantidade = 0;
						textcolor(timeCasa->info.elenco.cor1);
						if(y == 1){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome); //buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador1.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 3){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador2.overall >= 87)  
								quantidade--; //tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 5){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador3.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 7){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador4.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 9){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador5.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						gotoxy(67,20);
						textcolor(timeFora->info.elenco.cor1);
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
							
						
						
						printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
						gotoxy(119,29);
						limparBufferTeclado();
						exibirTrave();
						tecla = toupper(getch());
						if(tecla == 'P' && penaltiTime == 1){
							//bater penalti presidente
							limparcartapresida(1);
							gotoxy(67,20);
							textcolor(timeFora->info.elenco.cor1);
							printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
							
							
							gotoxy(33,20);
							textcolor(timeCasa->info.elenco.cor1);
							printf("%s NA BOLA...",timeCasa->info.elenco.presida.nome);
							printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
							printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
							gotoxy(119,29);
							teclacerta = 0;
							do{
								limparBufferTeclado();
								tecla = toupper(getch());
								if((tecla >= 49 && tecla <= 57) || tecla == 67){
									teclacerta = 1; //Apertou tecla certa, continue
								}
								else
									msgErroA();
							}while(teclacerta != 1);
							embaralhar(opcoes, 10);//embaralhar pulos
							quantidade = 0;//quantidade de pulos;
							quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
						    //Sortear aonde goleiro pulo;
							encontrado = 0;
						    for (int i = 0; i < quantidade; i++){
						        if (opcoes[i] == tecla) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
						    quantidade = 0;
						    encontrarAreas(encontrado, tecla);
						    if(encontrado == 1){
								timeCasa->info.elenco.presida.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.presida.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
							penaltiTime = 0;
							limparBufferTeclado();
							tecla = 'P';
						}else{
							if(tecla == 'P' && penaltiTime == 0)
								msgErroP();
						}
					
						
						
						if(tecla == 'X' && cartaSecretaTime == 1){
							if(timeCarta == '1'){
								//Carta secreta GOL DOBRO
								if(CartaDefesaOponente == y)
									CartaDefesaOponente += 2;
								limparcartaSecreta(1);								
								textcolor(timeCasa->info.elenco.cor1);
								quantidade = 0;
								if(y == 1){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome); //buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador1.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador1.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 3){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador2.overall >= 87)  
										quantidade--; //tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador2.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 5){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador3.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador3.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 7){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador4.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador4.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 9){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador5.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador5.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								gotoxy(67,20);
								textcolor(timeFora->info.elenco.cor1);
								printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
								if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
									quantidade += 4;
							    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
									quantidade += 5;
							    if (timeFora->info.elenco.goleiro1.overall>= 90){
									quantidade += 6;
									switch (y) {
										case 1:
											if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
												quantidade--;
											break;
										case 3:
											if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
												quantidade--;
											break;
										case 5:
											if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
												quantidade--;
											break;
										case 7:
											if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
												quantidade--;
											break;
										case 9:
											if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
												quantidade--;
											break;
									}
								}
								printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
								printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
								gotoxy(119,29);
								teclacerta = 0;
								do{
									limparBufferTeclado();
									tecla = toupper(getch());
									if((tecla >= 49 && tecla <= 57) || tecla == 67){
										teclacerta = 1; //Apertou tecla certa, continue
									}
									else
										msgErroA();
								}while(teclacerta != 1);
								//embaralhar pulos
								embaralhar(opcoes, 10);
							    //Sortear aonde goleiro pulo;
								encontrado = 0;
							    for (int i = 0; i < quantidade; i++){
							        if (opcoes[i] == tecla) {
							            encontrado = 1; //goleiro CATOU
							        }
							    }
							    quantidade = 0;
							    encontrarAreas(encontrado, tecla);
							    
								cartaSecretaTime = 0;
								limparBufferTeclado();
								tecla = '1';
								goldobro = 1;
								if(y == 1){ //jogador 1
									if(encontrado == 1){
										timeCasa->info.elenco.jogador1.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador1.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 3){ //jogador 2
									if(encontrado == 1){
										timeCasa->info.elenco.jogador2.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador2.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 5){ //jogador 3
									if(encontrado == 1){
										timeCasa->info.elenco.jogador3.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador3.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 7){ //jogador 4
									if(encontrado == 1){
										timeCasa->info.elenco.jogador4.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador4.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 9){ //jogador 5
									if(encontrado == 1){
										timeCasa->info.elenco.jogador5.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador5.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
										
									}
								}
							}else{
								msgCarta();//msg carta indisponivel.
								limparBufferTeclado();
							}
						}else{
							if(cartaSecretaTime == 0 && tecla == 'X')
								msgErroC();
						}
						
						
						
						
						if((tecla >= 49 && tecla <= 57) || tecla == 67){
							ok = 1; //Apertou tecla certa bora para proxima.
						}else if(tecla == 'P' || tecla == 'X' ){
							Sleep(1);//ja avisou no msgErroP acima;
						}else{
							msgErroA();
						}
						
						
						//acabei de chutar
						limparBufferTeclado();
					}while(ok != 1);
					
					
					//oponente defende meu chute
					if(goldobro==0){
						if(CartaDefesaOponente !=0){
							
							if(oponenteCarta == '2' && cartaSecretaOponente == 1){
								if(CartaDefesaOponente ==  y ){
									cartaSecretaOponente = 0;
									quantidade++;
									limparcartaSecreta(2);
									printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									CartaDefesaOponente  = 0;
									Sleep(1100);
								}
							}
						}
						gotoxy(35,25);
						printf("                                                                      ");
						//tecla = toupper(getch());
						embaralhar(opcoes, 10);
						//quantidade de pulos;
						if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeFora->info.elenco.goleiro1.overall>= 90){
							quantidade += 6;
							switch (y) {
								case 1:
									if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 3:
									if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 5:
									if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 7:
									if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 9:
									if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
							
						}
					    if (timeFora->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
					    //Sortear aonde goleiro pulo;
						encontrado = 0;
					    for (int i = 0; i < quantidade; i++){
					        if (opcoes[i] == tecla) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
					    	    
						encontrarAreas(encontrado, tecla);
						if(y == 1){ //jogador 1
							if(encontrado == 1){
								timeCasa->info.elenco.jogador1.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador1.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 3){ //jogador 2
							if(encontrado == 1){
								timeCasa->info.elenco.jogador2.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador2.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 5){ //jogador 3
							if(encontrado == 1){
								timeCasa->info.elenco.jogador3.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador3.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 7){ //jogador 4
							if(encontrado == 1){
								timeCasa->info.elenco.jogador4.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador4.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 9){ //jogador 5
							if(encontrado == 1){
								timeCasa->info.elenco.jogador5.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador5.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						limparmsg1();	
					}else
						goldobro = 0;
							
				}while(ok != 1);
				
				
				if((penaltiFora[conferirpenaltifora] == 5 && penaltiOponente == 1 )&& conferirpenaltifora !=0){
					//Sleep(450);
					limparBufferTeclado();
					//atualiza o placar antes de ir pro proxima cobrança
					limparcartapresida(2);
					gotoxy(7,5);
					printf("                                                                                                              ");
					gotoxy(9,5);
					printf("MINHAS CARTAS");
					gotoxy(96,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(30,26);
					textcolor((*confronto)->cor1);
					if(strlen((*confronto)->timeCasa) > 10){
						gotoxy(41, 4);
			        	printf("%s",(*confronto)->timeCasa);
					}else{
						gotoxy(46,4);
						printf("%s",(*confronto)->timeCasa);
					}
					gotoxy(58,4);textcolor(15);
			        printf("%d",(*confronto)->placarCasa);
			        gotoxy(60,4);
			        printf("X");
			        gotoxy(62,4);
			        printf("%d",(*confronto)->placarFora);
			        textcolor((*confronto)->cor2);
					gotoxy(66,4);
			        printf("%s",(*confronto)->timeFora);
			        textcolor(15);
				
					//carta presidente do oponente
					for(int i=0;i<9;i++)
						defesa[i]=0;
					gotoxy(31,20);
					printf("                                                             "); //Limpar jogador na bola... goleiro no gool...
					quantidade = 0; //quantidade de vezes que Goleiro vai defender
					exibirTrave();
					textcolor(timeFora->info.elenco.cor1);
					gotoxy(67,20); //posicionar e exibir presidente oponente.
					printf("%s NA BOLA...",timeFora->info.elenco.presida.nome);
					printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
					
					gotoxy(33,20);
					textcolor(timeCasa->info.elenco.cor1); // posicionar e exiber goleiro casa
					printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
					textcolor(15);
					quantidade += calcularPontuacaoGoleiro(timeCasa->info.elenco.goleiro1.overall);
					qtdColocada = 0;//numero de defesa colocada no vetor.
					ok = 0;
					do {
						printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
						gotoxy(60,26);
						printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
						gotoxy(119,29);
						limparBufferTeclado();
						tecla = toupper(getch());
					
						if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
							gotoxy(60,26);
							printf("                         ");
							if(qtdColocada < quantidade) {
								repetida = 0;
								for(int i = 0; i < qtdColocada; i++) {
									if(tecla == defesa[i]) {
										repetida = 1;
										break;
									}
								}
								if(repetida){
									gotoxy(36,28);
									printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
									Sleep(1300);
									gotoxy(36,28);
									printf("                                                               ");
								} else {
									defesa[qtdColocada] = tecla;
									qtdColocada++;
									encontrarAreasDefesa(tecla);
								}
							}
						} else {
							gotoxy(39,28);
							printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
							Sleep(1300);
							gotoxy(39,28);
							printf("                                                                 ");
						}
					
						if(qtdColocada == quantidade) {
							ok = 1;
						}
					
					}while(ok != 1);
					gotoxy(30,25);
					printf("                                                                               ");
					embaralhar(opcoes, 10);
					//Sortear aonde bateu penalti
					encontrado = 0;
				    for(int i = 0; i < quantidade; i++){
				        if (defesa[i] == opcoes[0]) {
				            encontrado = 1; //goleiro CATOU
				        }
				    }
				    limparBufferTeclado();
					char ob = opcoes[0];
					encontrarAreasGoleiro(encontrado, ob);
					if(encontrado == 1){
						timeFora->info.elenco.presida.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.presida.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
					penaltiOponente = 0;
					conferirpenaltifora++;
				}else{
					conferirpenaltifora++;
				}
				
				
				
				if(valorFinal == y){
					if(oponenteCarta == '1' && cartaSecretaOponente == 1){
						limparcartaSecreta(2);
						cartaSecretaOponente = 0;
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
						printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
						//atualiza o placar antes de ir pro proxima cobrança
						gotoxy(7,5);
						printf("                                                                                                              ");
						printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
						gotoxy(9,5);
						printf("MINHAS CARTAS");
						gotoxy(96,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(30,26);
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
						
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();
						textcolor(timeFora->info.elenco.cor1);
						if(y == 1){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
							if(timeFora->info.elenco.jogador1.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 3){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
							if(timeFora->info.elenco.jogador2.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 5){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
							if(timeFora->info.elenco.jogador3.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 7){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
							if(timeFora->info.elenco.jogador4.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 9){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
							if(timeFora->info.elenco.jogador5.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						
						
						gotoxy(33,20);
						textcolor(timeCasa->info.elenco.cor1);
						printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
						textcolor(15);
						
						qtdColocada = 0;//numero de defesa colocada no vetor.
						if (timeCasa->info.elenco.goleiro1.overall>= 90){
							quantidade += 6;
							switch (y) {
								case 1:
									if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 3:
									if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 5:
									if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 7:
									if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 9:
									if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
						}
						if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
						
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							} else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
						
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(y == 1){ //jogador 1
							if(encontrado == 1){
								timeFora->info.elenco.jogador1.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador1.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 3){ //jogador 2
							if(encontrado == 1){
								timeFora->info.elenco.jogador2.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador2.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 5){ //jogador 3
							if(encontrado == 1){
								timeFora->info.elenco.jogador3.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador3.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 7){ //jogador 4
							if(encontrado == 1){
								timeFora->info.elenco.jogador4.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador4.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 9){ //jogador 5
							if(encontrado == 1){
								timeFora->info.elenco.jogador5.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador5.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						gotoxy(45,22);
						limparmsg1();
						gotoxy(119,29);
						goldobroOponente = 1;
					}
				}
				if(goldobroOponente == 0){
					//defender o penalti
					for(int i=0;i<9;i++)
						defesa[i]=0;
					gotoxy(31,20);
					printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
					//atualiza o placar antes de ir pro proxima cobrança
					gotoxy(7,5);
					printf("                                                                                                              ");
					gotoxy(9,5);
					printf("MINHAS CARTAS");
					gotoxy(96,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(30,26);
					textcolor((*confronto)->cor1);
					if(strlen((*confronto)->timeCasa) > 10){
						gotoxy(41, 4);
			        	printf("%s",(*confronto)->timeCasa);
					}else{
						gotoxy(46,4);
						printf("%s",(*confronto)->timeCasa);
					}
					gotoxy(58,4);textcolor(15);
			        printf("%d",(*confronto)->placarCasa);
			        gotoxy(60,4);
			        printf("X");
			        gotoxy(62,4);
			        printf("%d",(*confronto)->placarFora);
			        textcolor((*confronto)->cor2);
					gotoxy(66,4);
			        printf("%s",(*confronto)->timeFora);
			        textcolor(15);
					
					quantidade = 0; //quantidade de vezes que Goleiro vai defender
					exibirTrave();
					textcolor(timeFora->info.elenco.cor1);
					if(y == 1){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
						if(timeFora->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 3){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
						if(timeFora->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 5){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
						if(timeFora->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 7){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
						if(timeFora->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 9){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
						if(timeFora->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					
					
					gotoxy(33,20);
					textcolor(timeCasa->info.elenco.cor1);
					if(strcmp(timeCasa->info.elenco.nomeEquipe,"Fluxo FC") == 0)
						textcolor(4);
					printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
					textcolor(15);
					
					qtdColocada = 0;//numero de defesa colocada no vetor.
					if (timeCasa->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (y) {
							case 1:
								if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 7:
								if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 9:
								if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
					}
					if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					ok = 0;
					do {
						printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
						gotoxy(60,26);
						printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
						gotoxy(119,29);
						limparBufferTeclado();
						tecla = toupper(getch());
						if(tecla == 'X' && cartaSecretaTime == 1){
							if(timeCarta == '2'){
								limparcartaSecreta(1);
								printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
								cartaSecretaTime = 0;
								quantidade++;
								gotoxy(60,26);
								printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
								paranaoexibirmesnagemdeteclaerrada = 1;
							}else{
								msgCarta();//msg carta indisponivel.
								limparBufferTeclado();
								paranaoexibirmesnagemdeteclaerrada = 1;
							}
						}else{
							if(cartaSecretaTime == 0 && tecla == 'X'){
								msgErroC();
								paranaoexibirmesnagemdeteclaerrada = 1;
							}
							
						}
						if(paranaoexibirmesnagemdeteclaerrada == 0){
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							}else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
					
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						}else{
							paranaoexibirmesnagemdeteclaerrada=0;
						}
					}while(ok != 1);
					gotoxy(30,25);
					printf("                                                                               ");
					embaralhar(opcoes, 10);
					//Sortear aonde bateu penalti
					encontrado = 0;
				    for(int i = 0; i < quantidade; i++){
				        if (defesa[i] == opcoes[0]) {
				            encontrado = 1; //goleiro CATOU
				        }
				    }
					char ob = opcoes[0];
					encontrarAreasGoleiro(encontrado, ob);
					if(y == 1){ //jogador 1
						if(encontrado == 1){
							timeFora->info.elenco.jogador1.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador1.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 3){ //jogador 2
						if(encontrado == 1){
							timeFora->info.elenco.jogador2.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador2.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 5){ //jogador 3
						if(encontrado == 1){
							timeFora->info.elenco.jogador3.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador3.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 7){ //jogador 4
						if(encontrado == 1){
							timeFora->info.elenco.jogador4.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador4.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 9){ //jogador 5
						if(encontrado == 1){
							timeFora->info.elenco.jogador5.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador5.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
					gotoxy(45,22);
					limparmsg1();
					gotoxy(119,29);
					
				}else{
					goldobroOponente =0;
				}
				
				
				y+=2;//ir pro proximo batedor
				//acabou ai
				
			}else{
				//começar defendendo
				CartaDefesaOponente ++;
				while(y <= 10){
					//começa defendendo
					gotoxy(7,5);
					printf("                                                                                                         ");
					gotoxy(98,5);
					printf("MINHAS CARTAS");
					gotoxy(7,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(31,20);
					printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
					exibirTrave(); //exibe a trave
					if(penaltiTime == 1)
						cartaPenaltiFora();  //confere se tem penalti ou nao ativo.
					if(penaltiOponente == 1)
						cartaPenaltiCasaOponente();
					
					if(cartaSecretaTime  == 1){//carta secreta foi usada
						if(timeCarta == '1')
							cartaSecretaFora(timeCarta,4);
						if(timeCarta == '2')
							cartaSecretaFora(timeCarta,13);
					}
							
					if(cartaSecretaOponente == 1){//carta secreta foi usada
						if(oponenteCarta == '1')
							cartaSecretaOponenteCasa(4);
						if(oponenteCarta == '2'){
							cartaSecretaOponenteCasa(13);
						}
					}
					
					
					
					
					

			        
			        //penaltiPresidente
			        if((penaltiFora[conferirpenaltifora] == 5 && penaltiOponente == 1 )&& conferirpenaltifora !=0){
						//Sleep(450);
						limparBufferTeclado();
						//atualiza o placar antes de ir pro proxima cobrança
						limparcartapresida(1);
						gotoxy(7,5);
						printf("                                                                                                              ");
						textcolor((*confronto)->cor1);
						//
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
					
						//carta presidente do oponente
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
					    printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();
						gotoxy(7,5);
						printf("                                                                                                              ");
						gotoxy(98,5);
						printf("MINHAS CARTAS");
						gotoxy(7,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						textcolor(timeCasa->info.elenco.cor1);
						gotoxy(67,20); //posicionar e exibir presidente oponente.
						printf("%s NA BOLA...",timeCasa->info.elenco.presida.nome);
						printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
						
						gotoxy(33,20);
						textcolor(timeFora->info.elenco.cor1); // posicionar e exiber goleiro casa
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
						textcolor(15);
						quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
						qtdColocada = 0;//numero de defesa colocada no vetor.
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
						
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							} else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
						
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
					    limparBufferTeclado();
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(encontrado == 1){
							timeCasa->info.elenco.presida.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.presida.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
						penaltiOponente = 0;conferirpenaltifora++;
					}else{
						conferirpenaltifora++;
					}
					
					
					if(valorFinal == y){
						if(oponenteCarta == '1' && cartaSecretaOponente == 1){
							textcolor((*confronto)->cor1);
							if(strlen((*confronto)->timeCasa) > 10){
								gotoxy(41, 4);
					        	printf("%s",(*confronto)->timeCasa);
							}else{
								gotoxy(46,4);
								printf("%s",(*confronto)->timeCasa);
							}
							gotoxy(58,4);textcolor(15);
					        printf("%d",(*confronto)->placarCasa);
					        gotoxy(60,4);
					        printf("X");
					        gotoxy(62,4);
					        printf("%d",(*confronto)->placarFora);
					        textcolor((*confronto)->cor2);
							gotoxy(66,4);
					        printf("%s",(*confronto)->timeFora);
					        textcolor(15);
					        gotoxy(31,20);
							printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");
							cartaSecretaOponente = 0;
							for(int i=0;i<9;i++)
								defesa[i]=0;
							
							quantidade = 0; //quantidade de vezes que Goleiro vai defender
							exibirTrave();
							textcolor(timeCasa->info.elenco.cor1);
							if(y == 2){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome);
								if(timeCasa->info.elenco.jogador1.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador1.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 4){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);
								if(timeCasa->info.elenco.jogador2.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador2.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 6){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);
								if(timeCasa->info.elenco.jogador3.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador3.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 8){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);
								if(timeCasa->info.elenco.jogador4.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador4.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 10){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);
								if(timeCasa->info.elenco.jogador5.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador5.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							
							
							gotoxy(33,20);
							textcolor(timeFora->info.elenco.cor1);
							printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
							textcolor(15);
							gotoxy(119,29);
							Sleep(1200);
							printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
							limparcartaSecreta(1);
							qtdColocada = 0;//numero de defesa colocada no vetor.
							if (timeFora->info.elenco.goleiro1.overall>= 90){
								quantidade += 6;
								switch (y) {
									case 2:
										if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
											quantidade--;
										break;
									case 4:
										if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
											quantidade--;
										break;
									case 6:
										if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
											quantidade--;
										break;
									case 8:
										if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
											quantidade--;
										break;
									case 10:
										if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
											quantidade--;
										break;
								}
							}
							if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
								quantidade += 4;
						    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
								quantidade += 5;
						    if (timeFora->info.elenco.goleiro1.overall <= 82) 
								quantidade +=3;
								
							ok = 0;
							do {
								printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
								gotoxy(60,26);
								printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
								gotoxy(119,29);
								limparBufferTeclado();
								tecla = toupper(getch());
							
								if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
									gotoxy(60,26);
									printf("                         ");
									if(qtdColocada < quantidade) {
										repetida = 0;
										for(int i = 0; i < qtdColocada; i++) {
											if(tecla == defesa[i]) {
												repetida = 1;
												break;
											}
										}
										if(repetida){
											gotoxy(36,28);
											printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
											Sleep(1300);
											gotoxy(36,28);
											printf("                                                               ");
										} else {
											defesa[qtdColocada] = tecla;
											qtdColocada++;
											encontrarAreasDefesa(tecla);
										}
									}
								} else {
									gotoxy(39,28);
									printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
									Sleep(1300);
									gotoxy(39,28);
									printf("                                                                 ");
								}
							
								if(qtdColocada == quantidade) {
									ok = 1;
								}
							
							}while(ok != 1);
							gotoxy(30,25);
							printf("                                                                               ");
							embaralhar(opcoes, 10);
							//Sortear aonde bateu penalti
							encontrado = 0;
						    for(int i = 0; i < quantidade; i++){
						        if (defesa[i] == opcoes[0]) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
							char ob = opcoes[0];
							encontrarAreasGoleiro(encontrado, ob);
							if(y == 2){ //jogador 1
								if(encontrado == 1){
									timeCasa->info.elenco.jogador1.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador1.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 4){ //jogador 2
								if(encontrado == 1){
									timeCasa->info.elenco.jogador2.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador2.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 6){ //jogador 3
								if(encontrado == 1){
									timeCasa->info.elenco.jogador3.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador3.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 8){ //jogador 4
								if(encontrado == 1){
									timeCasa->info.elenco.jogador4.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador4.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 10){ //jogador 5
								if(encontrado == 1){
									timeCasa->info.elenco.jogador5.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador5.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
									
								}
							}
							gotoxy(45,22);
							limparmsg1();
							gotoxy(119,29);
							goldobroOponente = 1;
						}
					}
					if(goldobroOponente == 0){
						gotoxy(7,5);
						printf("                                                                                                         ");
						gotoxy(98,5);
						printf("MINHAS CARTAS");
						gotoxy(7,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						//Exibe Placar
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
						
						
						
						
						
						
						
						
						
						
				        //defender o penalti
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();//exibir o GOL
						
						textcolor(timeCasa->info.elenco.cor1);
						if(y == 2){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome);
							if(timeCasa->info.elenco.jogador1.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 4){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);
							if(timeCasa->info.elenco.jogador2.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 6){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);
							if(timeCasa->info.elenco.jogador3.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 8){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);
							if(timeCasa->info.elenco.jogador4.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 10){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);
							if(timeCasa->info.elenco.jogador5.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						
						
						gotoxy(67,20);
						textcolor(timeFora->info.elenco.cor1);
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
						textcolor(15);
						
						qtdColocada = 0;//numero de defesa colocada no vetor.
						if (timeFora->info.elenco.goleiro1.overall>= 90 ){
							quantidade += 6;
							switch (y) {
								case 2:
									if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 4:
									if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 6:
									if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 8:
									if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 10:
									if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
						}	
						if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeFora->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
							if(tecla == 'X' && cartaSecretaTime == 1){
								if(timeCarta == '2'){
									limparcartaSecreta(2);
									printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									cartaSecretaTime = 0;
									quantidade++;
									gotoxy(60,26);
									printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
									paranaoexibirmesnagemdeteclaerrada = 1;
								}else{
									msgCarta();//msg carta indisponivel.
									limparBufferTeclado();
									paranaoexibirmesnagemdeteclaerrada = 1;
								}
							}else{
								if(cartaSecretaTime == 0 && tecla == 'X'){
									msgErroC();
									paranaoexibirmesnagemdeteclaerrada = 1;
								}
								
							}
							if(paranaoexibirmesnagemdeteclaerrada == 0){
								if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
									gotoxy(60,26);
									printf("                         ");
									if(qtdColocada < quantidade) {
										repetida = 0;
										for(int i = 0; i < qtdColocada; i++) {
											if(tecla == defesa[i]) {
												repetida = 1;
												break;
											}
										}
										if(repetida){
											gotoxy(36,28);
											printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
											Sleep(1300);
											gotoxy(36,28);
											printf("                                                               ");
										} else {
											defesa[qtdColocada] = tecla;
											qtdColocada++;
											encontrarAreasDefesa(tecla);
										}
									}
								} else {
									gotoxy(39,28);
									printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
									Sleep(1300);
									gotoxy(39,28);
									printf("                                                                 ");
								}
							
								if(qtdColocada == quantidade) {
									ok = 1;
								}
							}else{
								paranaoexibirmesnagemdeteclaerrada=0;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(y == 2){ //jogador 1
							if(encontrado == 1){
								timeCasa->info.elenco.jogador1.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador1.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 4){ //jogador 2
							if(encontrado == 1){
								timeCasa->info.elenco.jogador2.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador2.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 6){ //jogador 3
							if(encontrado == 1){
								timeCasa->info.elenco.jogador3.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador3.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 8){ //jogador 4
							if(encontrado == 1){
								timeCasa->info.elenco.jogador4.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador4.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 10){ //jogador 5
							if(encontrado == 1){
								timeCasa->info.elenco.jogador5.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador5.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						gotoxy(45,22);
						printf("                                                ");//limpar mensagem de gol ou defesa.
						gotoxy(119,29);
					
					}else{
						goldobroOponente =0;
					}
					
					
					
					
					
					
					
					
					//agora eu ataco.

					do{
						//Quem vai bater na BOLA...
						quantidade = 0;
						do{
							textcolor((*confronto)->cor1);
							if(strlen((*confronto)->timeCasa) > 10){
								gotoxy(41, 4);
					        	printf("%s",(*confronto)->timeCasa);
							}else{
								gotoxy(46,4);
								printf("%s",(*confronto)->timeCasa);
							}
							gotoxy(58,4);textcolor(15);
					        printf("%d",(*confronto)->placarCasa);
					        gotoxy(60,4);
					        printf("X");
					        gotoxy(62,4);
					        printf("%d",(*confronto)->placarFora);
					        textcolor((*confronto)->cor2);
							gotoxy(66,4);
					        printf("%s",(*confronto)->timeFora);
					        textcolor(15);
							exibirTrave();
							
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");
							gotoxy(31,20);
							printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
							textcolor(timeFora->info.elenco.cor1);
							if(y == 2){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
								if(timeFora->info.elenco.jogador1.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador1.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 4){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
								if(timeFora->info.elenco.jogador2.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador2.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 6){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
								if(timeFora->info.elenco.jogador3.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador3.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 8){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
								if(timeFora->info.elenco.jogador4.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador4.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 10){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
								if(timeFora->info.elenco.jogador5.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador5.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							gotoxy(33,20);
							textcolor(timeCasa->info.elenco.cor1);
							printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
							printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15);
							gotoxy(119,29);
							ok = 0;
							limparBufferTeclado();
							tecla = toupper(getch());
							if(tecla == 'P' && penaltiTime == 1){
								limparcartapresida(2);
								gotoxy(7,5);
								printf("                                                                                                              ");
								gotoxy(98,5);
								printf("MINHAS CARTAS");
								gotoxy(7,5);
								printf("ADVERSARIO CARTAS");
								gotoxy(31,20);
								printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
								//bater penalti presidente
								gotoxy(33,20);
								textcolor(timeCasa->info.elenco.cor1);
								printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
								
								
								gotoxy(67,20);
								textcolor(timeFora->info.elenco.cor1);
								printf("%s NA BOLA...",timeFora->info.elenco.presida.nome);
								printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
								printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
								gotoxy(119,29);
								teclacerta = 0;
								do{
									limparBufferTeclado();
									tecla = toupper(getch());
									if((tecla >= 49 && tecla <= 57) || tecla == 67){
										teclacerta = 1; //Apertou tecla certa, continue
									}
									else
										msgErroA();
								}while(teclacerta != 1);
								embaralhar(opcoes, 10);//embaralhar pulos
								quantidade = 0;//quantidade de pulos;
								quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
							    //Sortear aonde goleiro pulo;
								encontrado = 0;
							    for (int i = 0; i < quantidade; i++){
							        if (opcoes[i] == tecla) {
							            encontrado = 1; //goleiro CATOU
							        }
							    }
							    quantidade = 0;
							    encontrarAreas(encontrado, tecla);
							    if(encontrado == 1){
									timeFora->info.elenco.presida.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.presida.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
								penaltiTime = 0;
								limparBufferTeclado();
								tecla = 'P';
							}else{
								if(tecla == 'P' && penaltiTime == 0)
									msgErroP();
							}
							
							if(tecla == 'X' && cartaSecretaTime == 1){
								if(timeCarta == '1'){
									gotoxy(7,5);
									printf("                                                                                                              ");
									gotoxy(98,5);
									printf("MINHAS CARTAS");
									gotoxy(7,5);
									printf("ADVERSARIO CARTAS");
									gotoxy(31,20);
									printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
									//Carta secreta GOL DOBRO
									if(CartaDefesaOponente == y)
										CartaDefesaOponente += 2;
									limparcartaSecreta(2);								
									textcolor(timeFora->info.elenco.cor1);
									quantidade = 0;
									if(y == 2){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome); //buscando o jogador para exibição
										if(timeFora->info.elenco.jogador1.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador1.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 4){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador2.overall >= 87)  
											quantidade--; //tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador2.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 6){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador3.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador3.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 8){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador4.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador4.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 10){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador5.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador5.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									gotoxy(33,20);
									textcolor(timeCasa->info.elenco.cor1);
									printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
									if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
										quantidade += 4;
								    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
										quantidade += 5;
								    if (timeCasa->info.elenco.goleiro1.overall>= 90){
										quantidade += 6;
										switch (y) {
											case 2:
												if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
													quantidade--;
												break;
											case 4:
												if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
													quantidade--;
												break;
											case 6:
												if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
													quantidade--;
												break;
											case 8:
												if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
													quantidade--;
												break;
											case 10:
												if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
													quantidade--;
												break;
										}
									}
									printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
									gotoxy(119,29);
									teclacerta = 0;
									do{
										limparBufferTeclado();
										tecla = toupper(getch());
										if((tecla >= 49 && tecla <= 57) || tecla == 67){
											teclacerta = 1; //Apertou tecla certa, continue
										}
										else
											msgErroA();
									}while(teclacerta != 1);
									//embaralhar pulos
									embaralhar(opcoes, 10);
								    //Sortear aonde goleiro pulo;
									encontrado = 0;
								    for (int i = 0; i < quantidade; i++){
								        if (opcoes[i] == tecla) {
								            encontrado = 1; //goleiro CATOU
								        }
								    }
								    quantidade = 0;
								    encontrarAreas(encontrado, tecla);
								    
									cartaSecretaTime = 0;
									limparBufferTeclado();
									tecla = '1';
									goldobro = 1;
									if(y == 2){ //jogador 1
										if(encontrado == 1){
											timeFora->info.elenco.jogador1.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador1.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos +=2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 4){ //jogador 2
										if(encontrado == 1){
											timeFora->info.elenco.jogador2.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador2.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 6){ //jogador 3
										if(encontrado == 1){
											timeFora->info.elenco.jogador3.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador3.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 8){ //jogador 4
										if(encontrado == 1){
											timeFora->info.elenco.jogador4.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador4.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 10){ //jogador 5
										if(encontrado == 1){
											timeFora->info.elenco.jogador5.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador5.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
											
										}
									}
								}else{
									msgCarta();//msg carta indisponivel.
									limparBufferTeclado();
								}
							}else{
								if(cartaSecretaTime == 0 && tecla == 'X')
									msgErroC();
							}
							
							if((tecla >= 49 && tecla <= 57) || tecla == 67){
								ok = 1; //Apertou tecla certa bora para proxima.
							}else if(tecla == 'P' || tecla == 'X' ){
								Sleep(1);//ja avisou no msgErroP acima;
							}else{
								msgErroA();
							}
							
						}while(ok != 1);
						
						
						if(goldobro == 0){
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");

							if(CartaDefesaOponente !=0){
							
								if(oponenteCarta == '2' && cartaSecretaOponente == 1){
									if(CartaDefesaOponente ==  y ){
										cartaSecretaOponente = 0;
										quantidade++;
										limparcartaSecreta(1);
										printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
										CartaDefesaOponente  = 0;
										Sleep(1100);
									}
								}
							}
							gotoxy(35,25);
							printf("                                                                      ");
							embaralhar(opcoes, 10);
							//quantidade de pulos;
							if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
								quantidade += 4;
						    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
								quantidade += 5;
						    if (timeCasa->info.elenco.goleiro1.overall>= 90 ){
								quantidade += 6;
								switch (y) {
									case 2:
										if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
											quantidade--;
										break;
									case 4:
										if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
											quantidade--;
										break;
									case 6:
										if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
											quantidade--;
										break;
									case 8:
										if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
											quantidade--;
										break;
									case 10:
										if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
											quantidade--;
										break;
								}
								
							}
						    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
								quantidade +=3;
								
						    //Sortear aonde goleiro pulo;
							encontrado = 0;
						    for (int i = 0; i < quantidade; i++){
						        if (opcoes[i] == tecla) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
    
							encontrarAreas(encontrado, tecla);
							if(y == 2){ //jogador 1
								if(encontrado == 1){
									timeFora->info.elenco.jogador1.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador1.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 4){ //jogador 2
								if(encontrado == 1){
									timeFora->info.elenco.jogador2.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador2.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 6){ //jogador 3
								if(encontrado == 1){
									timeFora->info.elenco.jogador3.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador3.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 8){ //jogador 4
								if(encontrado == 1){
									timeFora->info.elenco.jogador4.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador4.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 10){ //jogador 5
								if(encontrado == 1){
									timeFora->info.elenco.jogador5.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador5.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
									
								}
							}
							gotoxy(45,22);
							printf("                                                ");//limpar mensagem de gol ou defesa.
						}else
							goldobro = 0;
					}while(ok != 1);
					y+=2;//ir pro proximo batedor
				}
				
			}	
		}
		//mostrar o ultimo placar
		textcolor((*confronto)->cor1);
		if(strlen((*confronto)->timeCasa) > 10){
			gotoxy(41, 4);
        	printf("%s",(*confronto)->timeCasa);
		}else{
			gotoxy(46,4);
			printf("%s",(*confronto)->timeCasa);
		}
		gotoxy(58,4);textcolor(15);
        printf("%d",(*confronto)->placarCasa);
        gotoxy(60,4);
        printf("X");
        gotoxy(62,4);
        printf("%d",(*confronto)->placarFora);
        textcolor((*confronto)->cor2);
		gotoxy(66,4);
        printf("%s",(*confronto)->timeFora);
        textcolor(15);
        //Animação de fim de jogo aqui em baixo...
        Sleep(1000);
        //Atualizar dados de fim de jogo.
        
        if((*confronto)->placarCasa > (*confronto)->placarFora){
	    	timeCasa->info.vitoria+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.derrota += 1;
	    	timeCasa->info.saldo += 450;
	    	timeFora->info.saldo += 50;
	    }
	    if((*confronto)->placarCasa == (*confronto)->placarFora){
	    	timeCasa->info.empate+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=1;
	    	timeFora->info.pontos +=1;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.empate += 1;
	    	timeCasa->info.saldo += 250;
	    	timeFora->info.saldo += 250;
	    }
	    if((*confronto)->placarCasa < (*confronto)->placarFora){
	    	timeCasa->info.derrota+=1;
	    	timeCasa->info.partidas += 1;
	    	timeFora->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.vitoria += 1;
	    	timeCasa->info.saldo += 50;
	    	timeFora->info.saldo += 450;
	    }

	}else{
		//simula o jogo
		int valorFinalFora,CartaDefesaTime;
		embaralhar(cartas,4);
		timeCarta = cartas[0];
		oponenteCarta = cartas[1];
		CartaDefesaTime = 0;
		CartaDefesaOponente = 0;
		if(timeCarta == '2'){
			CartaDefesaTime = rand() %5;
			CartaDefesaTime +=1;
		}
		
		if(oponenteCarta == '2'){
			CartaDefesaOponente = rand() %5;
			CartaDefesaOponente +=1;
		}
		
		
		
		if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeFora->info.elenco.jogador1.overall,
		        timeFora->info.elenco.jogador2.overall,
		        timeFora->info.elenco.jogador3.overall,
		        timeFora->info.elenco.jogador4.overall,
		        timeFora->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
	
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
			int escolhido = candidatos[rand() % qtd];
		    valorFinalFora = escolhido  + 1;
		}else{
			valorFinalFora = 0;
		}
		
		if(timeCarta == '1'){
			int overalls[5] = {
		        timeCasa->info.elenco.jogador1.overall,
		        timeCasa->info.elenco.jogador2.overall,
		        timeCasa->info.elenco.jogador3.overall,
		        timeCasa->info.elenco.jogador4.overall,
		        timeCasa->info.elenco.jogador5.overall
		    };
	
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
	
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
	
		    int escolhido = candidatos[rand() % qtd];
		
		    valorFinal = escolhido  + 1;
		}else{
			valorFinal = 0;
		}
		penalidade = 1;		
		do{
			//ataque time casa
			quantidade = 0;
			embaralhar(opcoes, 10);
			chute = opcoes[0];
			if(valorFinal == penalidade){ //aqui sera ativado gol dobro
				
				if(timeCarta == '1'){
					if(CartaDefesaOponente== penalidade){
							CartaDefesaOponente + 1;
					}
					if(penalidade == 1){
						if(timeCasa->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeCasa->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 3){
						if(timeCasa->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeCasa->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeCasa->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time fora
					if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeFora->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeFora->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}
			    	
					//adiciona os dados
					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeCasa->info.elenco.jogador1.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador1.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeCasa->info.elenco.jogador2.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador2.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeCasa->info.elenco.jogador3.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador3.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeCasa->info.elenco.jogador4.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador4.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeCasa->info.elenco.jogador5.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador5.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
				}	
				valorFinal = 0;
			}else{
					if(penalidade == 1){
						if(timeCasa->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeCasa->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 3){
						if(timeCasa->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeCasa->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeCasa->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time fora
					if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeFora->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeFora->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
					
					if(CartaDefesaOponente == penalidade){
						quantidade ++;
						CartaDefesaOponente = 0;
					}
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}
			    	
					//adiciona os dados
					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeCasa->info.elenco.jogador1.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador1.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeCasa->info.elenco.jogador2.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador2.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeCasa->info.elenco.jogador3.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador3.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeCasa->info.elenco.jogador4.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador4.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeCasa->info.elenco.jogador5.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador5.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
			
			}
			quantidade = 0;
			embaralhar(opcoes, 10);
			chute = opcoes[0];
			if(valorFinalFora == penalidade){
				
				if(oponenteCarta == '1'){
					
					if(CartaDefesaTime == penalidade){
						CartaDefesaTime += 0;
					}
					if(penalidade == 1){
						if(timeFora->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeFora->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 3){
						if(timeFora->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeFora->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeFora->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time casa
					if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeCasa->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}

					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeFora->info.elenco.jogador1.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador1.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeFora->info.elenco.jogador2.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador2.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeFora->info.elenco.jogador3.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador3.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeFora->info.elenco.jogador4.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador4.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeFora->info.elenco.jogador5.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador5.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos +=2 ;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
					valorFinal = 0;
				}
			}else{
				//ataque time  Fora
				if(penalidade == 1){
					if(timeFora->info.elenco.jogador1.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador1.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 2){
					if(timeFora->info.elenco.jogador2.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador2.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 3){
					if(timeFora->info.elenco.jogador3.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador3.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 4){
					if(timeFora->info.elenco.jogador4.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador4.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;						
				}
				if(penalidade == 5){
					if(timeFora->info.elenco.jogador5.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador5.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				//defesa time casa
				if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
					quantidade += 4;
			    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
					quantidade += 5;
			    if (timeCasa->info.elenco.goleiro1.overall>= 90){
					quantidade += 6;
					switch (penalidade) {
						case 1:
							if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
								quantidade--;
							break;
						case 2:
							if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
								quantidade--;
							break;
						case 3:
							if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
								quantidade--;
							break;
						case 4:
							if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
								quantidade--;
							break;
						case 5:
							if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
								quantidade--;
							break;
					}
					
				}
			    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
					quantidade +=3;
				if(CartaDefesaTime == penalidade){
						quantidade ++;
						CartaDefesaTime = 0;
				}
				embaralhar(opcoes,10);
				encontrado = 0;
				for(int i = 0; i < quantidade; i++){
		        if(opcoes[i] == chute) {
		            	encontrado = 1; //goleiro CATOU
		        	}
		    	}
				if(penalidade == 1){ //jogador 1
					if(encontrado == 1){
						timeFora->info.elenco.jogador1.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador1.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 2){ //jogador 2
					if(encontrado == 1){
						timeFora->info.elenco.jogador2.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador2.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
				}
				if(penalidade == 3){ //jogador 3
					if(encontrado == 1){
						timeFora->info.elenco.jogador3.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador3.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 4){ //jogador 4
					if(encontrado == 1){
						timeFora->info.elenco.jogador4.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador4.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 5){ //jogador 5
					if(encontrado == 1){
						timeFora->info.elenco.jogador5.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador5.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						
					}
				}
			}
			
			penalidade++;
		}while(penalidade<=5);
		// penalti presidente casa
		
		encontrado = 0;
		quantidade = calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
		embaralhar(opcoes, 10);
		chute = opcoes[0];
		embaralhar(opcoes, 10);
		for(int i = 0; i < quantidade; i++){
		    if(chute == opcoes[i]) {
		        encontrado = 1; // goleiro catou
		    }
		}
		if(encontrado == 1){
		    timeCasa->info.elenco.presida.errou += 1;
		    timeFora->info.elenco.goleiro1.defesa += 1;
		}else{
		    (*confronto)->placarCasa += 1;
		    timeCasa->info.elenco.presida.gols += 1;
		    timeCasa->info.golsFeitos += 1;
		    timeFora->info.golsSofridos += 1;
		    timeFora->info.elenco.goleiro1.golsSofridos +=1;
		}
		
		// penalti presidente fora
		encontrado = 0;
		quantidade = calcularPontuacaoGoleiro(timeCasa->info.elenco.goleiro1.overall);
		embaralhar(opcoes, 10);
		chute = opcoes[0];
		embaralhar(opcoes, 10);
		for(int i = 0; i < quantidade; i++){
		    if (chute == opcoes[i]) {
		        encontrado = 1; // goleiro catou
		    }
		}
		if(encontrado == 1){
		    timeFora->info.elenco.presida.errou += 1;
		    timeCasa->info.elenco.goleiro1.defesa += 1;
		}else{
		    (*confronto)->placarFora += 1;
		    timeFora->info.elenco.presida.gols += 1;
		    timeFora->info.golsFeitos += 1;
		    timeCasa->info.golsSofridos += 1;
		    timeCasa->info.elenco.goleiro1.golsSofridos +=1;
		}
		
		if((*confronto)->placarCasa > (*confronto)->placarFora){
	    	timeCasa->info.vitoria+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.derrota += 1;
	    	timeCasa->info.saldo += 450;
	    	timeFora->info.saldo += 50;
	    }
	    if((*confronto)->placarCasa == (*confronto)->placarFora){
	    	timeCasa->info.empate+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=1;
	    	timeFora->info.pontos +=1;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.empate += 1;
	    	timeCasa->info.saldo += 250;
	    	timeFora->info.saldo += 250;
	    }
	    if((*confronto)->placarCasa < (*confronto)->placarFora){
	    	timeCasa->info.derrota+=1;
	    	timeCasa->info.partidas += 1;
	    	timeFora->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.vitoria += 1;
	    	timeCasa->info.saldo += 50;
	    	timeFora->info.saldo += 450;
	    }
		
	}
	
	ordenarPorPontos(lista);
}





void jogarConfrontoPlayoff(listaDupla **lista,tree *resultado,Confronto **confronto,int simula){
	clrscr();
	int i,y,penaltiTime, penaltiOponente,ok,quantidade,encontrado,qtdColocada,repetida,penalidade,teclacerta,conferirpenaltifora,paranaoexibirmesnagemdeteclaerrada;
	int cartaSecretaTime, cartaSecretaOponente,goldobro,goldobroOponente,valorFinal,CartaDefesaOponente,goldeouro = 0;
	char timeCarta,oponenteCarta;
	char tecla,chute;
	char opcoes[10] = {49, 50, 51, 52, 53, 54, 55, 56, 57, 67}; //Simular Pulo ou Chute;
	char cartas[4] = {49,50,49,50}; //oficial
	//char cartas[4] = {49,49,49,49}; //teste
	char penaltiFora[5] = {4,2,5,4,5};
	char defesa[9];
	MolduraColorida(1,1,120,30,2,2,14,14); 
	//exibirTrave();
	//exibirTrave();
	listaDupla *meuTime = buscarTimeNaLista(*lista, resultado->time.codigo);
	listaDupla *timeCasa = buscarTimeNaLista(*lista, (*confronto)->codigo1);
	listaDupla *timeFora = buscarTimeNaLista(*lista, (*confronto)->codigo2);
	
	if(((*confronto)->codigo1 == meuTime->info.elenco.codigo || (*confronto)->codigo2 == meuTime->info.elenco.codigo ) && simula == 0){
		//sortear cartas
		penaltiTime = 1; //adicionar penalti presidente
		penaltiOponente = 1; //adicionar penalti presidente
		cartaSecretaTime = 1; //adicionar carta secreta time
		cartaSecretaOponente = 1; //adicionar carta secreta oponente
		paranaoexibirmesnagemdeteclaerrada = 0;
		embaralhar(cartas,4);
		timeCarta = cartas[0];
		oponenteCarta = cartas[1];
		CartaDefesaOponente = 0;
		if(oponenteCarta == '2'){
			cartaSecretaOponenteFora(13);
			CartaDefesaOponente = rand() %5;
			CartaDefesaOponente = (CartaDefesaOponente * 2) + 1;
		}
		
		if((*confronto)->codigo1 == resultado->time.codigo){
			if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeFora->info.elenco.jogador1.overall,
		        timeFora->info.elenco.jogador2.overall,
		        timeFora->info.elenco.jogador3.overall,
		        timeFora->info.elenco.jogador4.overall,
		        timeFora->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
		
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
		    int escolhido = candidatos[rand() % qtd];
		
		    // Aplicar fórmula: 1, 3, 5, 7, 9
		    valorFinal = (escolhido * 2) + 1;
			}else{
				valorFinal = 0;
			}
		}else{
			if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeCasa->info.elenco.jogador1.overall,
		        timeCasa->info.elenco.jogador2.overall,
		        timeCasa->info.elenco.jogador3.overall,
		        timeCasa->info.elenco.jogador4.overall,
		        timeCasa->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
		
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
		    int escolhido = candidatos[rand() % qtd];
		
		    valorFinal = (escolhido * 2) + 2;
			}else{
				valorFinal = 0;
			}
		}
		embaralhar(penaltiFora,5);
		conferirpenaltifora = 0;
		goldobro = 0;
		goldobroOponente =0;
		//Ordem das batidas;
		if((*confronto)->codigo1 == resultado->time.codigo)
			y = 1; //selecionar casa ou fora
		else
			y = 2;//selecionar casa ou fora
		//alterar para 10.
		while(y <= 10){
			if(y % 2!=0){
				//começa batendo
				//primeiro bater o penalti
				do{
					ok = 0; //conferir TECLA APERTADA
					do{
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){ //posicionar nome do time casa
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);//posicionar nome do time casa
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);//posicionar nome do time casa
						}
						gotoxy(58,4);textcolor(15); //colocar placar
				        printf("%d",(*confronto)->placarCasa); //colocar placar
				        gotoxy(60,4);
				        printf("X"); //colocar placar
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora); //colocar placar
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora); //posicionar nome do time fora
				        textcolor(15);
						exibirTrave(); //area do gol
						
						//carta presidente
						if(penaltiTime == 1) //se o penalti nao foi batido
							cartaPenaltiCasa();
							
						if(penaltiOponente == 1)//se o penalti nao foi batido
							cartaPenaltiForaOponente();
						
		
						if(cartaSecretaTime  == 1){//carta secreta foi usada
							if(timeCarta == '1')
								cartaSecretaCasa(timeCarta,4);
							if(timeCarta == '2')
								cartaSecretaCasa(timeCarta,13);
						}
							
						if(cartaSecretaOponente == 1){//carta secreta foi usada
							if(oponenteCarta == '1')
								cartaSecretaOponenteFora(4);
							if(oponenteCarta == '2'){
								cartaSecretaOponenteFora(13);
							}
						}	
						gotoxy(7,5);
						printf("                                                                                                              ");
						gotoxy(9,5);
						printf("MINHAS CARTAS"); //posicionar escrita pra gameplay
						gotoxy(96,5);
						printf("ADVERSARIO CARTAS"); //posicionar escrita pra gameplay
						gotoxy(30,26);
						//Quem vai bater na BOLA...
						quantidade = 0;
						textcolor(timeCasa->info.elenco.cor1);
						if(y == 1){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome); //buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador1.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 3){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador2.overall >= 87)  
								quantidade--; //tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 5){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador3.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 7){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador4.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
							
						}
						if(y == 9){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);//buscando o jogador para exibição
							if(timeCasa->info.elenco.jogador5.overall >= 87)
								quantidade--;//tirar reflexo do goleiro
							if(timeCasa->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						gotoxy(67,20);
						textcolor(timeFora->info.elenco.cor1);
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
							
						
						
						printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
						gotoxy(119,29);
						limparBufferTeclado();
						exibirTrave();
						tecla = toupper(getch());
						if(tecla == 'P' && penaltiTime == 1){
							//bater penalti presidente
							limparcartapresida(1);
							gotoxy(67,20);
							textcolor(timeFora->info.elenco.cor1);
							printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
							
							
							gotoxy(33,20);
							textcolor(timeCasa->info.elenco.cor1);
							printf("%s NA BOLA...",timeCasa->info.elenco.presida.nome);
							printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
							printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
							gotoxy(119,29);
							teclacerta = 0;
							do{
								limparBufferTeclado();
								tecla = toupper(getch());
								if((tecla >= 49 && tecla <= 57) || tecla == 67){
									teclacerta = 1; //Apertou tecla certa, continue
								}
								else
									msgErroA();
							}while(teclacerta != 1);
							embaralhar(opcoes, 10);//embaralhar pulos
							quantidade = 0;//quantidade de pulos;
							quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
						    //Sortear aonde goleiro pulo;
							encontrado = 0;
						    for (int i = 0; i < quantidade; i++){
						        if (opcoes[i] == tecla) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
						    quantidade = 0;
						    encontrarAreas(encontrado, tecla);
						    if(encontrado == 1){
								timeCasa->info.elenco.presida.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.presida.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
							penaltiTime = 0;
							limparBufferTeclado();
							tecla = 'P';
						}else{
							if(tecla == 'P' && penaltiTime == 0)
								msgErroP();
						}
					
						
						
						if(tecla == 'X' && cartaSecretaTime == 1){
							if(timeCarta == '1'){
								//Carta secreta GOL DOBRO
								if(CartaDefesaOponente == y)
									CartaDefesaOponente += 2;
								limparcartaSecreta(1);								
								textcolor(timeCasa->info.elenco.cor1);
								quantidade = 0;
								if(y == 1){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome); //buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador1.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador1.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 3){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador2.overall >= 87)  
										quantidade--; //tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador2.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 5){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador3.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador3.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 7){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador4.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador4.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								if(y == 9){
									gotoxy(33,20);
									printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);//buscando o jogador para exibição
									if(timeCasa->info.elenco.jogador5.overall >= 87)
										quantidade--;//tirar reflexo do goleiro
									if(timeCasa->info.elenco.jogador5.overall >= 90)
										quantidade--;
									if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
										quantidade++;
									if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
										quantidade++;
								}
								gotoxy(67,20);
								textcolor(timeFora->info.elenco.cor1);
								printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
								if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
									quantidade += 4;
							    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
									quantidade += 5;
							    if (timeFora->info.elenco.goleiro1.overall>= 90){
									quantidade += 6;
									switch (y) {
										case 1:
											if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
												quantidade--;
											break;
										case 3:
											if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
												quantidade--;
											break;
										case 5:
											if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
												quantidade--;
											break;
										case 7:
											if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
												quantidade--;
											break;
										case 9:
											if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
												quantidade--;
											break;
									}
								}
								printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
								printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
								gotoxy(119,29);
								teclacerta = 0;
								do{
									limparBufferTeclado();
									tecla = toupper(getch());
									if((tecla >= 49 && tecla <= 57) || tecla == 67){
										teclacerta = 1; //Apertou tecla certa, continue
									}
									else
										msgErroA();
								}while(teclacerta != 1);
								//embaralhar pulos
								embaralhar(opcoes, 10);
							    //Sortear aonde goleiro pulo;
								encontrado = 0;
							    for (int i = 0; i < quantidade; i++){
							        if (opcoes[i] == tecla) {
							            encontrado = 1; //goleiro CATOU
							        }
							    }
							    quantidade = 0;
							    encontrarAreas(encontrado, tecla);
							    
								cartaSecretaTime = 0;
								limparBufferTeclado();
								tecla = '1';
								goldobro = 1;
								if(y == 1){ //jogador 1
									if(encontrado == 1){
										timeCasa->info.elenco.jogador1.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador1.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 3){ //jogador 2
									if(encontrado == 1){
										timeCasa->info.elenco.jogador2.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador2.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 5){ //jogador 3
									if(encontrado == 1){
										timeCasa->info.elenco.jogador3.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador3.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 7){ //jogador 4
									if(encontrado == 1){
										timeCasa->info.elenco.jogador4.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador4.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
									}
								}
								if(y == 9){ //jogador 5
									if(encontrado == 1){
										timeCasa->info.elenco.jogador5.errou += 1;
										timeFora->info.elenco.goleiro1.defesa += 1;
									}else{
										(*confronto)->placarCasa += 2;
										timeCasa->info.elenco.jogador5.gols += 2;
										timeCasa->info.golsFeitos += 2;
										timeFora->info.golsSofridos += 2;
										timeFora->info.elenco.goleiro1.golsSofridos +=1;
										
									}
								}
							}else{
								msgCarta();//msg carta indisponivel.
								limparBufferTeclado();
							}
						}else{
							if(cartaSecretaTime == 0 && tecla == 'X')
								msgErroC();
						}
						
						
						
						
						if((tecla >= 49 && tecla <= 57) || tecla == 67){
							ok = 1; //Apertou tecla certa bora para proxima.
						}else if(tecla == 'P' || tecla == 'X' ){
							Sleep(1);//ja avisou no msgErroP acima;
						}else{
							msgErroA();
						}
						
						
						//acabei de chutar
						limparBufferTeclado();
					}while(ok != 1);
					
					
					//oponente defende meu chute
					if(goldobro==0){
						if(CartaDefesaOponente !=0){
							
							if(oponenteCarta == '2' && cartaSecretaOponente == 1){
								if(CartaDefesaOponente ==  y ){
									cartaSecretaOponente = 0;
									quantidade++;
									limparcartaSecreta(2);
									printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									CartaDefesaOponente  = 0;
									Sleep(1100);
								}
							}
						}
						gotoxy(35,25);
						printf("                                                                      ");
						//tecla = toupper(getch());
						embaralhar(opcoes, 10);
						//quantidade de pulos;
						if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeFora->info.elenco.goleiro1.overall>= 90){
							quantidade += 6;
							switch (y) {
								case 1:
									if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 3:
									if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 5:
									if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 7:
									if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 9:
									if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
							
						}
					    if (timeFora->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
					    //Sortear aonde goleiro pulo;
						encontrado = 0;
					    for (int i = 0; i < quantidade; i++){
					        if (opcoes[i] == tecla) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
					    	    
						encontrarAreas(encontrado, tecla);
						if(y == 1){ //jogador 1
							if(encontrado == 1){
								timeCasa->info.elenco.jogador1.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador1.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 3){ //jogador 2
							if(encontrado == 1){
								timeCasa->info.elenco.jogador2.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador2.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 5){ //jogador 3
							if(encontrado == 1){
								timeCasa->info.elenco.jogador3.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador3.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 7){ //jogador 4
							if(encontrado == 1){
								timeCasa->info.elenco.jogador4.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador4.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 9){ //jogador 5
							if(encontrado == 1){
								timeCasa->info.elenco.jogador5.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador5.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						limparmsg1();	
					}else
						goldobro = 0;
							
				}while(ok != 1);
				
				
				if((penaltiFora[conferirpenaltifora] == 5 && penaltiOponente == 1 )&& conferirpenaltifora !=0){
					//Sleep(450);
					limparBufferTeclado();
					//atualiza o placar antes de ir pro proxima cobrança
					limparcartapresida(2);
					gotoxy(7,5);
					printf("                                                                                                              ");
					gotoxy(9,5);
					printf("MINHAS CARTAS");
					gotoxy(96,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(30,26);
					textcolor((*confronto)->cor1);
					if(strlen((*confronto)->timeCasa) > 10){
						gotoxy(41, 4);
			        	printf("%s",(*confronto)->timeCasa);
					}else{
						gotoxy(46,4);
						printf("%s",(*confronto)->timeCasa);
					}
					gotoxy(58,4);textcolor(15);
			        printf("%d",(*confronto)->placarCasa);
			        gotoxy(60,4);
			        printf("X");
			        gotoxy(62,4);
			        printf("%d",(*confronto)->placarFora);
			        textcolor((*confronto)->cor2);
					gotoxy(66,4);
			        printf("%s",(*confronto)->timeFora);
			        textcolor(15);
				
					//carta presidente do oponente
					for(int i=0;i<9;i++)
						defesa[i]=0;
					gotoxy(31,20);
					printf("                                                             "); //Limpar jogador na bola... goleiro no gool...
					quantidade = 0; //quantidade de vezes que Goleiro vai defender
					exibirTrave();
					textcolor(timeFora->info.elenco.cor1);
					gotoxy(67,20); //posicionar e exibir presidente oponente.
					printf("%s NA BOLA...",timeFora->info.elenco.presida.nome);
					printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
					
					gotoxy(33,20);
					textcolor(timeCasa->info.elenco.cor1); // posicionar e exiber goleiro casa
					printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
					textcolor(15);
					quantidade += calcularPontuacaoGoleiro(timeCasa->info.elenco.goleiro1.overall);
					qtdColocada = 0;//numero de defesa colocada no vetor.
					ok = 0;
					do {
						printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
						gotoxy(60,26);
						printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
						gotoxy(119,29);
						limparBufferTeclado();
						tecla = toupper(getch());
					
						if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
							gotoxy(60,26);
							printf("                         ");
							if(qtdColocada < quantidade) {
								repetida = 0;
								for(int i = 0; i < qtdColocada; i++) {
									if(tecla == defesa[i]) {
										repetida = 1;
										break;
									}
								}
								if(repetida){
									gotoxy(36,28);
									printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
									Sleep(1300);
									gotoxy(36,28);
									printf("                                                               ");
								} else {
									defesa[qtdColocada] = tecla;
									qtdColocada++;
									encontrarAreasDefesa(tecla);
								}
							}
						} else {
							gotoxy(39,28);
							printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
							Sleep(1300);
							gotoxy(39,28);
							printf("                                                                 ");
						}
					
						if(qtdColocada == quantidade) {
							ok = 1;
						}
					
					}while(ok != 1);
					gotoxy(30,25);
					printf("                                                                               ");
					embaralhar(opcoes, 10);
					//Sortear aonde bateu penalti
					encontrado = 0;
				    for(int i = 0; i < quantidade; i++){
				        if (defesa[i] == opcoes[0]) {
				            encontrado = 1; //goleiro CATOU
				        }
				    }
				    limparBufferTeclado();
					char ob = opcoes[0];
					encontrarAreasGoleiro(encontrado, ob);
					if(encontrado == 1){
						timeFora->info.elenco.presida.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.presida.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
					penaltiOponente = 0;
					conferirpenaltifora++;
				}else{
					conferirpenaltifora++;
				}
				
				
				
				if(valorFinal == y){
					if(oponenteCarta == '1' && cartaSecretaOponente == 1){
						limparcartaSecreta(2);
						cartaSecretaOponente = 0;
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
						printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
						//atualiza o placar antes de ir pro proxima cobrança
						gotoxy(7,5);
						printf("                                                                                                              ");
						printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
						gotoxy(9,5);
						printf("MINHAS CARTAS");
						gotoxy(96,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(30,26);
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
						
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();
						textcolor(timeFora->info.elenco.cor1);
						if(y == 1){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
							if(timeFora->info.elenco.jogador1.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
							if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 3){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
							if(timeFora->info.elenco.jogador2.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
							if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 5){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
							if(timeFora->info.elenco.jogador3.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
							if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 7){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
							if(timeFora->info.elenco.jogador4.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
							if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 9){
							gotoxy(67,20);
							printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
							if(timeFora->info.elenco.jogador5.overall >= 87)
								quantidade--;
							if(timeFora->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
							if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						
						
						gotoxy(33,20);
						textcolor(timeCasa->info.elenco.cor1);
						printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
						textcolor(15);
						
						qtdColocada = 0;//numero de defesa colocada no vetor.
						if (timeCasa->info.elenco.goleiro1.overall>= 90){
							quantidade += 6;
							switch (y) {
								case 1:
									if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 3:
									if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 5:
									if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 7:
									if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 9:
									if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
						}
						if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
						
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							} else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
						
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(y == 1){ //jogador 1
							if(encontrado == 1){
								timeFora->info.elenco.jogador1.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador1.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 3){ //jogador 2
							if(encontrado == 1){
								timeFora->info.elenco.jogador2.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador2.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 5){ //jogador 3
							if(encontrado == 1){
								timeFora->info.elenco.jogador3.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador3.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 7){ //jogador 4
							if(encontrado == 1){
								timeFora->info.elenco.jogador4.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador4.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 9){ //jogador 5
							if(encontrado == 1){
								timeFora->info.elenco.jogador5.errou += 1;
								timeCasa->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarFora += 2;
								timeFora->info.elenco.jogador5.gols += 2;
								timeFora->info.golsFeitos += 2;
								timeCasa->info.golsSofridos += 2;
								timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						gotoxy(45,22);
						limparmsg1();
						gotoxy(119,29);
						goldobroOponente = 1;
					}
				}
				if(goldobroOponente == 0){
					//defender o penalti
					for(int i=0;i<9;i++)
						defesa[i]=0;
					gotoxy(31,20);
					printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
					//atualiza o placar antes de ir pro proxima cobrança
					gotoxy(7,5);
					printf("                                                                                                              ");
					gotoxy(9,5);
					printf("MINHAS CARTAS");
					gotoxy(96,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(30,26);
					textcolor((*confronto)->cor1);
					if(strlen((*confronto)->timeCasa) > 10){
						gotoxy(41, 4);
			        	printf("%s",(*confronto)->timeCasa);
					}else{
						gotoxy(46,4);
						printf("%s",(*confronto)->timeCasa);
					}
					gotoxy(58,4);textcolor(15);
			        printf("%d",(*confronto)->placarCasa);
			        gotoxy(60,4);
			        printf("X");
			        gotoxy(62,4);
			        printf("%d",(*confronto)->placarFora);
			        textcolor((*confronto)->cor2);
					gotoxy(66,4);
			        printf("%s",(*confronto)->timeFora);
			        textcolor(15);
					
					quantidade = 0; //quantidade de vezes que Goleiro vai defender
					exibirTrave();
					textcolor(timeFora->info.elenco.cor1);
					if(y == 1){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
						if(timeFora->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 3){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
						if(timeFora->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 5){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
						if(timeFora->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 7){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
						if(timeFora->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(y == 9){
						gotoxy(67,20);
						printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
						if(timeFora->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					
					}	
					gotoxy(33,20);
					textcolor(timeCasa->info.elenco.cor1);
					if(strcmp(timeCasa->info.elenco.nomeEquipe,"Fluxo FC") == 0)
						textcolor(4);
					printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
					textcolor(15);
					
					qtdColocada = 0;//numero de defesa colocada no vetor.
					if (timeCasa->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (y) {
							case 1:
								if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 7:
								if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 9:
								if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
					}
					if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					ok = 0;
					do {
						printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
						gotoxy(60,26);
						printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
						gotoxy(119,29);
						limparBufferTeclado();
						tecla = toupper(getch());
						if(tecla == 'X' && cartaSecretaTime == 1){
							if(timeCarta == '2'){
								limparcartaSecreta(1);
								printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
								cartaSecretaTime = 0;
								quantidade++;
								gotoxy(60,26);
								printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
								paranaoexibirmesnagemdeteclaerrada = 1;
							}else{
								msgCarta();//msg carta indisponivel.
								limparBufferTeclado();
								paranaoexibirmesnagemdeteclaerrada = 1;
							}
						}else{
							if(cartaSecretaTime == 0 && tecla == 'X'){
								msgErroC();
								paranaoexibirmesnagemdeteclaerrada = 1;
							}
							
						}
						if(paranaoexibirmesnagemdeteclaerrada == 0){
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							}else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
					
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						}else{
							paranaoexibirmesnagemdeteclaerrada=0;
						}
					}while(ok != 1);
					gotoxy(30,25);
					printf("                                                                               ");
					embaralhar(opcoes, 10);
					//Sortear aonde bateu penalti
					encontrado = 0;
				    for(int i = 0; i < quantidade; i++){
				        if (defesa[i] == opcoes[0]) {
				            encontrado = 1; //goleiro CATOU
				        }
				    }
					char ob = opcoes[0];
					encontrarAreasGoleiro(encontrado, ob);
					if(y == 1){ //jogador 1
						if(encontrado == 1){
							timeFora->info.elenco.jogador1.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador1.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 3){ //jogador 2
						if(encontrado == 1){
							timeFora->info.elenco.jogador2.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador2.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 5){ //jogador 3
						if(encontrado == 1){
							timeFora->info.elenco.jogador3.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador3.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 7){ //jogador 4
						if(encontrado == 1){
							timeFora->info.elenco.jogador4.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador4.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(y == 9){ //jogador 5
						if(encontrado == 1){
							timeFora->info.elenco.jogador5.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 1;
							timeFora->info.elenco.jogador5.gols += 1;
							timeFora->info.golsFeitos += 1;
							timeCasa->info.golsSofridos += 1;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
					gotoxy(45,22);
					limparmsg1();
					gotoxy(119,29);
					
				}else{
					goldobroOponente =0;
				}
				
				
				y+=2;//ir pro proximo batedor
				//acabou ai
				
			}else{
				//começar defendendo
				CartaDefesaOponente ++;
				while(y <= 10){
					//começa defendendo
					gotoxy(7,5);
					printf("                                                                                                         ");
					gotoxy(98,5);
					printf("MINHAS CARTAS");
					gotoxy(7,5);
					printf("ADVERSARIO CARTAS");
					gotoxy(31,20);
					printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
					exibirTrave(); //exibe a trave
					if(penaltiTime == 1)
						cartaPenaltiFora();  //confere se tem penalti ou nao ativo.
					if(penaltiOponente == 1)
						cartaPenaltiCasaOponente();
					
					if(cartaSecretaTime  == 1){//carta secreta foi usada
							if(timeCarta == '1')
								cartaSecretaFora(timeCarta,4);
							if(timeCarta == '2')
								cartaSecretaFora(timeCarta,13);
					}
							
					if(cartaSecretaOponente == 1){//carta secreta foi usada
						if(oponenteCarta == '1')
							cartaSecretaOponenteCasa(4);
						if(oponenteCarta == '2'){
							cartaSecretaOponenteCasa(13);
						}
					}
					
					
					
					
					

			        
			        //penaltiPresidente
			        if((penaltiFora[conferirpenaltifora] == 5 && penaltiOponente == 1 )&& conferirpenaltifora !=0){
						//Sleep(450);
						limparBufferTeclado();
						//atualiza o placar antes de ir pro proxima cobrança
						limparcartapresida(1);
						gotoxy(7,5);
						printf("                                                                                                              ");
						textcolor((*confronto)->cor1);
						//
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
					
						//carta presidente do oponente
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
					    printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();
						gotoxy(7,5);
						printf("                                                                                                              ");
						gotoxy(98,5);
						printf("MINHAS CARTAS");
						gotoxy(7,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						textcolor(timeCasa->info.elenco.cor1);
						gotoxy(67,20); //posicionar e exibir presidente oponente.
						printf("%s NA BOLA...",timeCasa->info.elenco.presida.nome);
						printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
						
						gotoxy(33,20);
						textcolor(timeFora->info.elenco.cor1); // posicionar e exiber goleiro casa
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
						textcolor(15);
						quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
						qtdColocada = 0;//numero de defesa colocada no vetor.
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
						
							if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
								gotoxy(60,26);
								printf("                         ");
								if(qtdColocada < quantidade) {
									repetida = 0;
									for(int i = 0; i < qtdColocada; i++) {
										if(tecla == defesa[i]) {
											repetida = 1;
											break;
										}
									}
									if(repetida){
										gotoxy(36,28);
										printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
										Sleep(1300);
										gotoxy(36,28);
										printf("                                                               ");
									} else {
										defesa[qtdColocada] = tecla;
										qtdColocada++;
										encontrarAreasDefesa(tecla);
									}
								}
							} else {
								gotoxy(39,28);
								printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
								Sleep(1300);
								gotoxy(39,28);
								printf("                                                                 ");
							}
						
							if(qtdColocada == quantidade) {
								ok = 1;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
					    limparBufferTeclado();
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(encontrado == 1){
							timeCasa->info.elenco.presida.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.presida.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
						penaltiOponente = 0;conferirpenaltifora++;
					}else{
						conferirpenaltifora++;
					}
					
					
					if(valorFinal == y){
						if(oponenteCarta == '1' && cartaSecretaOponente == 1){
							textcolor((*confronto)->cor1);
							if(strlen((*confronto)->timeCasa) > 10){
								gotoxy(41, 4);
					        	printf("%s",(*confronto)->timeCasa);
							}else{
								gotoxy(46,4);
								printf("%s",(*confronto)->timeCasa);
							}
							gotoxy(58,4);textcolor(15);
					        printf("%d",(*confronto)->placarCasa);
					        gotoxy(60,4);
					        printf("X");
					        gotoxy(62,4);
					        printf("%d",(*confronto)->placarFora);
					        textcolor((*confronto)->cor2);
							gotoxy(66,4);
					        printf("%s",(*confronto)->timeFora);
					        textcolor(15);
					        gotoxy(31,20);
							printf("                                                            "); //Limpar jogador na bola... goleiro no gool...
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");
							cartaSecretaOponente = 0;
							for(int i=0;i<9;i++)
								defesa[i]=0;
							
							quantidade = 0; //quantidade de vezes que Goleiro vai defender
							exibirTrave();
							textcolor(timeCasa->info.elenco.cor1);
							if(y == 2){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome);
								if(timeCasa->info.elenco.jogador1.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador1.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 4){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);
								if(timeCasa->info.elenco.jogador2.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador2.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 6){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);
								if(timeCasa->info.elenco.jogador3.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador3.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 8){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);
								if(timeCasa->info.elenco.jogador4.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador4.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 10){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);
								if(timeCasa->info.elenco.jogador5.overall >= 87)
									quantidade--;
								if(timeCasa->info.elenco.jogador5.overall >= 90)
									quantidade--;
								if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							
							
							gotoxy(33,20);
							textcolor(timeFora->info.elenco.cor1);
							printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
							textcolor(15);
							gotoxy(119,29);
							Sleep(1200);
							printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
							limparcartaSecreta(1);
							qtdColocada = 0;//numero de defesa colocada no vetor.
							if (timeFora->info.elenco.goleiro1.overall>= 90){
								quantidade += 6;
								switch (y) {
									case 2:
										if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
											quantidade--;
										break;
									case 4:
										if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
											quantidade--;
										break;
									case 6:
										if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
											quantidade--;
										break;
									case 8:
										if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
											quantidade--;
										break;
									case 10:
										if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
											quantidade--;
										break;
								}
							}
							if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
								quantidade += 4;
						    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
								quantidade += 5;
						    if (timeFora->info.elenco.goleiro1.overall <= 82) 
								quantidade +=3;
								
							ok = 0;
							do {
								printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
								gotoxy(60,26);
								printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
								gotoxy(119,29);
								limparBufferTeclado();
								tecla = toupper(getch());
							
								if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
									gotoxy(60,26);
									printf("                         ");
									if(qtdColocada < quantidade) {
										repetida = 0;
										for(int i = 0; i < qtdColocada; i++) {
											if(tecla == defesa[i]) {
												repetida = 1;
												break;
											}
										}
										if(repetida){
											gotoxy(36,28);
											printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
											Sleep(1300);
											gotoxy(36,28);
											printf("                                                               ");
										} else {
											defesa[qtdColocada] = tecla;
											qtdColocada++;
											encontrarAreasDefesa(tecla);
										}
									}
								} else {
									gotoxy(39,28);
									printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
									Sleep(1300);
									gotoxy(39,28);
									printf("                                                                 ");
								}
							
								if(qtdColocada == quantidade) {
									ok = 1;
								}
							
							}while(ok != 1);
							gotoxy(30,25);
							printf("                                                                               ");
							embaralhar(opcoes, 10);
							//Sortear aonde bateu penalti
							encontrado = 0;
						    for(int i = 0; i < quantidade; i++){
						        if (defesa[i] == opcoes[0]) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
							char ob = opcoes[0];
							encontrarAreasGoleiro(encontrado, ob);
							if(y == 2){ //jogador 1
								if(encontrado == 1){
									timeCasa->info.elenco.jogador1.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador1.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 4){ //jogador 2
								if(encontrado == 1){
									timeCasa->info.elenco.jogador2.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador2.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 6){ //jogador 3
								if(encontrado == 1){
									timeCasa->info.elenco.jogador3.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador3.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 8){ //jogador 4
								if(encontrado == 1){
									timeCasa->info.elenco.jogador4.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador4.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 10){ //jogador 5
								if(encontrado == 1){
									timeCasa->info.elenco.jogador5.errou += 1;
									timeFora->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarCasa += 2;
									timeCasa->info.elenco.jogador5.gols += 2;
									timeCasa->info.golsFeitos += 2;
									timeFora->info.golsSofridos += 2;
									timeFora->info.elenco.goleiro1.golsSofridos +=1;
									
								}
							}
							gotoxy(45,22);
							limparmsg1();
							gotoxy(119,29);
							goldobroOponente = 1;
						}
					}
					if(goldobroOponente == 0){
						gotoxy(7,5);
						printf("                                                                                                         ");
						gotoxy(98,5);
						printf("MINHAS CARTAS");
						gotoxy(7,5);
						printf("ADVERSARIO CARTAS");
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						//Exibe Placar
						textcolor((*confronto)->cor1);
						if(strlen((*confronto)->timeCasa) > 10){
							gotoxy(41, 4);
				        	printf("%s",(*confronto)->timeCasa);
						}else{
							gotoxy(46,4);
							printf("%s",(*confronto)->timeCasa);
						}
						gotoxy(58,4);textcolor(15);
				        printf("%d",(*confronto)->placarCasa);
				        gotoxy(60,4);
				        printf("X");
				        gotoxy(62,4);
				        printf("%d",(*confronto)->placarFora);
				        textcolor((*confronto)->cor2);
						gotoxy(66,4);
				        printf("%s",(*confronto)->timeFora);
				        textcolor(15);
						
						
						
						
						
						
						
						
						
						
				        //defender o penalti
						for(int i=0;i<9;i++)
							defesa[i]=0;
						gotoxy(31,20);
						printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
						quantidade = 0; //quantidade de vezes que Goleiro vai defender
						exibirTrave();//exibir o GOL
						
						textcolor(timeCasa->info.elenco.cor1);
						if(y == 2){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador1.nome);
							if(timeCasa->info.elenco.jogador1.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 4){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador2.nome);
							if(timeCasa->info.elenco.jogador2.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 6){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador3.nome);
							if(timeCasa->info.elenco.jogador3.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 8){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador4.nome);
							if(timeCasa->info.elenco.jogador4.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						if(y == 10){
							gotoxy(33,20);
							printf("%s NA BOLA...",timeCasa->info.elenco.jogador5.nome);
							if(timeCasa->info.elenco.jogador5.overall >= 87)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall >= 90)
								quantidade--;
							if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
								quantidade++;
							if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
								quantidade++;
						}
						
						
						gotoxy(67,20);
						textcolor(timeFora->info.elenco.cor1);
						printf("%s NO GOL...",timeFora->info.elenco.goleiro1.nome);
						textcolor(15);
						
						qtdColocada = 0;//numero de defesa colocada no vetor.
						if (timeFora->info.elenco.goleiro1.overall>= 90 ){
							quantidade += 6;
							switch (y) {
								case 2:
									if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
										quantidade--;
									break;
								case 4:
									if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
										quantidade--;
									break;
								case 6:
									if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
										quantidade--;
									break;
								case 8:
									if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
										quantidade--;
									break;
								case 10:
									if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
										quantidade--;
									break;
							}
						}	
						if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
							quantidade += 4;
					    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
							quantidade += 5;
					    if (timeFora->info.elenco.goleiro1.overall <= 82) 
							quantidade +=3;
							
						ok = 0;
						do {
							printCentralizado("APERTE A TECLA AONDE DESEJA ADICIONAR REFLEXO !" ,25,15);
							gotoxy(60,26);
							printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
							gotoxy(119,29);
							limparBufferTeclado();
							tecla = toupper(getch());
							if(tecla == 'X' && cartaSecretaTime == 1){
								if(timeCarta == '2'){
									limparcartaSecreta(2);
									printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									cartaSecretaTime = 0;
									quantidade++;
									gotoxy(60,26);
									printf("REFLEXOS DISPONIVEIS: %d", quantidade - qtdColocada);
									paranaoexibirmesnagemdeteclaerrada = 1;
								}else{
									msgCarta();//msg carta indisponivel.
									limparBufferTeclado();
									paranaoexibirmesnagemdeteclaerrada = 1;
								}
							}else{
								if(cartaSecretaTime == 0 && tecla == 'X'){
									msgErroC();
									paranaoexibirmesnagemdeteclaerrada = 1;
								}
								
							}
							if(paranaoexibirmesnagemdeteclaerrada == 0){
								if((tecla >= 49 && tecla <= 57) || tecla == 67) { // tecla válida
									gotoxy(60,26);
									printf("                         ");
									if(qtdColocada < quantidade) {
										repetida = 0;
										for(int i = 0; i < qtdColocada; i++) {
											if(tecla == defesa[i]) {
												repetida = 1;
												break;
											}
										}
										if(repetida){
											gotoxy(36,28);
											printf("[ TECLA INVALIDA ] ESTA TECLA JA FOI SELECIONADA !");
											Sleep(1300);
											gotoxy(36,28);
											printf("                                                               ");
										} else {
											defesa[qtdColocada] = tecla;
											qtdColocada++;
											encontrarAreasDefesa(tecla);
										}
									}
								} else {
									gotoxy(39,28);
									printf("[ TECLA INVALIDA ] USE [1] A [9] OU [C] !");
									Sleep(1300);
									gotoxy(39,28);
									printf("                                                                 ");
								}
							
								if(qtdColocada == quantidade) {
									ok = 1;
								}
							}else{
								paranaoexibirmesnagemdeteclaerrada=0;
							}
						
						}while(ok != 1);
						gotoxy(30,25);
						printf("                                                                               ");
						embaralhar(opcoes, 10);
						//Sortear aonde bateu penalti
						encontrado = 0;
					    for(int i = 0; i < quantidade; i++){
					        if (defesa[i] == opcoes[0]) {
					            encontrado = 1; //goleiro CATOU
					        }
					    }
						char ob = opcoes[0];
						encontrarAreasGoleiro(encontrado, ob);
						if(y == 2){ //jogador 1
							if(encontrado == 1){
								timeCasa->info.elenco.jogador1.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador1.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 4){ //jogador 2
							if(encontrado == 1){
								timeCasa->info.elenco.jogador2.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador2.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 6){ //jogador 3
							if(encontrado == 1){
								timeCasa->info.elenco.jogador3.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador3.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 8){ //jogador 4
							if(encontrado == 1){
								timeCasa->info.elenco.jogador4.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador4.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
							}
						}
						if(y == 10){ //jogador 5
							if(encontrado == 1){
								timeCasa->info.elenco.jogador5.errou += 1;
								timeFora->info.elenco.goleiro1.defesa += 1;
							}else{
								(*confronto)->placarCasa += 1;
								timeCasa->info.elenco.jogador5.gols += 1;
								timeCasa->info.golsFeitos += 1;
								timeFora->info.golsSofridos += 1;
								timeFora->info.elenco.goleiro1.golsSofridos +=1;
								
							}
						}
						gotoxy(45,22);
						printf("                                                ");//limpar mensagem de gol ou defesa.
						gotoxy(119,29);
					
					}else{
						goldobroOponente =0;
					}
					
					
					
					
					
					
					
					
					//agora eu ataco.

					do{
						//Quem vai bater na BOLA...
						quantidade = 0;
						do{
							textcolor((*confronto)->cor1);
							if(strlen((*confronto)->timeCasa) > 10){
								gotoxy(41, 4);
					        	printf("%s",(*confronto)->timeCasa);
							}else{
								gotoxy(46,4);
								printf("%s",(*confronto)->timeCasa);
							}
							gotoxy(58,4);textcolor(15);
					        printf("%d",(*confronto)->placarCasa);
					        gotoxy(60,4);
					        printf("X");
					        gotoxy(62,4);
					        printf("%d",(*confronto)->placarFora);
					        textcolor((*confronto)->cor2);
							gotoxy(66,4);
					        printf("%s",(*confronto)->timeFora);
					        textcolor(15);
							exibirTrave();
							
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");
							gotoxy(31,20);
							printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
							textcolor(timeFora->info.elenco.cor1);
							if(y == 2){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome);
								if(timeFora->info.elenco.jogador1.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador1.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 4){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);
								if(timeFora->info.elenco.jogador2.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador2.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
								
							}
							if(y == 6){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);
								if(timeFora->info.elenco.jogador3.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador3.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 8){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);
								if(timeFora->info.elenco.jogador4.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador4.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							if(y == 10){
								gotoxy(67,20);
								printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);
								if(timeFora->info.elenco.jogador5.overall >= 87)
									quantidade--;
								if(timeFora->info.elenco.jogador5.overall >= 90)
									quantidade--;
								if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
									quantidade++;
								if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
									quantidade++;
							}
							gotoxy(33,20);
							textcolor(timeCasa->info.elenco.cor1);
							printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome);
							printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15);
							gotoxy(119,29);
							ok = 0;
							limparBufferTeclado();
							tecla = toupper(getch());
							if(tecla == 'P' && penaltiTime == 1){
								limparcartapresida(2);
								gotoxy(7,5);
								printf("                                                                                                              ");
								gotoxy(98,5);
								printf("MINHAS CARTAS");
								gotoxy(7,5);
								printf("ADVERSARIO CARTAS");
								gotoxy(31,20);
								printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
								//bater penalti presidente
								gotoxy(33,20);
								textcolor(timeCasa->info.elenco.cor1);
								printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
								
								
								gotoxy(67,20);
								textcolor(timeFora->info.elenco.cor1);
								printf("%s NA BOLA...",timeFora->info.elenco.presida.nome);
								printCentralizado("! ! ! CARTA PENALTI PRESIDENTE ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
								printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
								gotoxy(119,29);
								teclacerta = 0;
								do{
									limparBufferTeclado();
									tecla = toupper(getch());
									if((tecla >= 49 && tecla <= 57) || tecla == 67){
										teclacerta = 1; //Apertou tecla certa, continue
									}
									else
										msgErroA();
								}while(teclacerta != 1);
								embaralhar(opcoes, 10);//embaralhar pulos
								quantidade = 0;//quantidade de pulos;
								quantidade += calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
							    //Sortear aonde goleiro pulo;
								encontrado = 0;
							    for (int i = 0; i < quantidade; i++){
							        if (opcoes[i] == tecla) {
							            encontrado = 1; //goleiro CATOU
							        }
							    }
							    quantidade = 0;
							    encontrarAreas(encontrado, tecla);
							    if(encontrado == 1){
									timeFora->info.elenco.presida.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.presida.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
								penaltiTime = 0;
								limparBufferTeclado();
								tecla = 'P';
							}else{
								if(tecla == 'P' && penaltiTime == 0)
									msgErroP();
							}
							
							if(tecla == 'X' && cartaSecretaTime == 1){
								if(timeCarta == '1'){
									gotoxy(7,5);
									printf("                                                                                                              ");
									gotoxy(98,5);
									printf("MINHAS CARTAS");
									gotoxy(7,5);
									printf("ADVERSARIO CARTAS");
									gotoxy(31,20);
									printf("                                                                 "); //Limpar jogador na bola... goleiro no gool...
									//Carta secreta GOL DOBRO
									if(CartaDefesaOponente == y)
										CartaDefesaOponente += 2;
									limparcartaSecreta(2);								
									textcolor(timeFora->info.elenco.cor1);
									quantidade = 0;
									if(y == 2){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador1.nome); //buscando o jogador para exibição
										if(timeFora->info.elenco.jogador1.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador1.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 4){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador2.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador2.overall >= 87)  
											quantidade--; //tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador2.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 6){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador3.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador3.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador3.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 8){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador4.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador4.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador4.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									if(y == 10){
										gotoxy(67,20);
										printf("%s NA BOLA...",timeFora->info.elenco.jogador5.nome);//buscando o jogador para exibição
										if(timeFora->info.elenco.jogador5.overall >= 87)
											quantidade--;//tirar reflexo do goleiro
										if(timeFora->info.elenco.jogador5.overall >= 90)
											quantidade--;
										if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
											quantidade++;
										if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
											quantidade++;
									}
									gotoxy(33,20);
									textcolor(timeCasa->info.elenco.cor1);
									printf("%s NO GOL...",timeCasa->info.elenco.goleiro1.nome); //exibir goleiro para gameplay
									if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
										quantidade += 4;
								    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
										quantidade += 5;
								    if (timeCasa->info.elenco.goleiro1.overall>= 90){
										quantidade += 6;
										switch (y) {
											case 2:
												if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
													quantidade--;
												break;
											case 4:
												if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
													quantidade--;
												break;
											case 6:
												if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
													quantidade--;
												break;
											case 8:
												if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
													quantidade--;
												break;
											case 10:
												if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
													quantidade--;
												break;
										}
									}
									printCentralizado("! ! ! CARTA GOL DOBRO ATIVADA ! ! !",5,timeFora->info.elenco.cor1);
									printCentralizado("! APERTE A TECLA AONDE DESEJA CHUTAR !" ,25,15); //aperte a tecla para chutar
									gotoxy(119,29);
									teclacerta = 0;
									do{
										limparBufferTeclado();
										tecla = toupper(getch());
										if((tecla >= 49 && tecla <= 57) || tecla == 67){
											teclacerta = 1; //Apertou tecla certa, continue
										}
										else
											msgErroA();
									}while(teclacerta != 1);
									//embaralhar pulos
									embaralhar(opcoes, 10);
								    //Sortear aonde goleiro pulo;
									encontrado = 0;
								    for (int i = 0; i < quantidade; i++){
								        if (opcoes[i] == tecla) {
								            encontrado = 1; //goleiro CATOU
								        }
								    }
								    quantidade = 0;
								    encontrarAreas(encontrado, tecla);
								    
									cartaSecretaTime = 0;
									limparBufferTeclado();
									tecla = '1';
									goldobro = 1;
									if(y == 2){ //jogador 1
										if(encontrado == 1){
											timeFora->info.elenco.jogador1.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador1.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos +=2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 4){ //jogador 2
										if(encontrado == 1){
											timeFora->info.elenco.jogador2.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador2.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 6){ //jogador 3
										if(encontrado == 1){
											timeFora->info.elenco.jogador3.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador3.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 8){ //jogador 4
										if(encontrado == 1){
											timeFora->info.elenco.jogador4.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador4.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
										}
									}
									if(y == 10){ //jogador 5
										if(encontrado == 1){
											timeFora->info.elenco.jogador5.errou += 1;
											timeCasa->info.elenco.goleiro1.defesa += 1;
										}else{
											(*confronto)->placarFora += 2;
											timeFora->info.elenco.jogador5.gols += 2;
											timeFora->info.golsFeitos += 2;
											timeCasa->info.golsSofridos += 2;
											timeCasa->info.elenco.goleiro1.golsSofridos +=1;
											
										}
									}
								}else{
									msgCarta();//msg carta indisponivel.
									limparBufferTeclado();
								}
							}else{
								if(cartaSecretaTime == 0 && tecla == 'X')
									msgErroC();
							}
							
							if((tecla >= 49 && tecla <= 57) || tecla == 67){
								ok = 1; //Apertou tecla certa bora para proxima.
							}else if(tecla == 'P' || tecla == 'X' ){
								Sleep(1);//ja avisou no msgErroP acima;
							}else{
								msgErroA();
							}
							
						}while(ok != 1);
						
						
						if(goldobro == 0){
							gotoxy(7,5);
							printf("                                                                                                              ");
							gotoxy(98,5);
							printf("MINHAS CARTAS");
							gotoxy(7,5);
							printf("ADVERSARIO CARTAS");

							if(CartaDefesaOponente !=0){
							
								if(oponenteCarta == '2' && cartaSecretaOponente == 1){
									if(CartaDefesaOponente ==  y ){
										cartaSecretaOponente = 0;
										quantidade++;
										limparcartaSecreta(1);
										printCentralizado("! ! ! CARTA REFLEXO ATIVADA ! ! !",5,timeCasa->info.elenco.cor1);
										CartaDefesaOponente  = 0;
										Sleep(1100);
									}
								}
							}
							gotoxy(35,25);
							printf("                                                                      ");
							embaralhar(opcoes, 10);
							//quantidade de pulos;
							if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
								quantidade += 4;
						    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
								quantidade += 5;
						    if (timeCasa->info.elenco.goleiro1.overall>= 90 ){
								quantidade += 6;
								switch (y) {
									case 2:
										if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
											quantidade--;
										break;
									case 4:
										if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
											quantidade--;
										break;
									case 6:
										if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
											quantidade--;
										break;
									case 8:
										if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
											quantidade--;
										break;
									case 10:
										if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
											quantidade--;
										break;
								}
								
							}
						    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
								quantidade +=3;
								
						    //Sortear aonde goleiro pulo;
							encontrado = 0;
						    for (int i = 0; i < quantidade; i++){
						        if (opcoes[i] == tecla) {
						            encontrado = 1; //goleiro CATOU
						        }
						    }
    
							encontrarAreas(encontrado, tecla);
							if(y == 2){ //jogador 1
								if(encontrado == 1){
									timeFora->info.elenco.jogador1.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador1.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 4){ //jogador 2
								if(encontrado == 1){
									timeFora->info.elenco.jogador2.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador2.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 6){ //jogador 3
								if(encontrado == 1){
									timeFora->info.elenco.jogador3.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador3.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 8){ //jogador 4
								if(encontrado == 1){
									timeFora->info.elenco.jogador4.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador4.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
								}
							}
							if(y == 10){ //jogador 5
								if(encontrado == 1){
									timeFora->info.elenco.jogador5.errou += 1;
									timeCasa->info.elenco.goleiro1.defesa += 1;
								}else{
									(*confronto)->placarFora += 1;
									timeFora->info.elenco.jogador5.gols += 1;
									timeFora->info.golsFeitos += 1;
									timeCasa->info.golsSofridos += 1;
									timeCasa->info.elenco.goleiro1.golsSofridos +=1;
									
								}
							}
							gotoxy(45,22);
							printf("                                                ");//limpar mensagem de gol ou defesa.
						}else
							goldobro = 0;
					}while(ok != 1);
					y+=2;//ir pro proximo batedor
				}
				
			}	
		}
		//mostrar o ultimo placar
		textcolor((*confronto)->cor1);
		if(strlen((*confronto)->timeCasa) > 10){
			gotoxy(41, 4);
        	printf("%s",(*confronto)->timeCasa);
		}else{
			gotoxy(46,4);
			printf("%s",(*confronto)->timeCasa);
		}
		gotoxy(58,4);textcolor(15);
        printf("%d",(*confronto)->placarCasa);
        gotoxy(60,4);
        printf("X");
        gotoxy(62,4);
        printf("%d",(*confronto)->placarFora);
        textcolor((*confronto)->cor2);
		gotoxy(66,4);
        printf("%s",(*confronto)->timeFora);
        textcolor(15);
        //Animação de fim de jogo aqui em baixo...
        Sleep(1000);
        //Atualizar dados de fim de jogo.
        
        if((*confronto)->placarCasa > (*confronto)->placarFora){
	    	timeCasa->info.vitoria+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.derrota += 1;
	    	timeCasa->info.saldo += 450;
	    	timeFora->info.saldo += 50;
	    }
	    if((*confronto)->placarCasa == (*confronto)->placarFora){
	    	timeCasa->info.empate+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=1;
	    	timeFora->info.pontos +=1;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.empate += 1;
	    	timeCasa->info.saldo += 250;
	    	timeFora->info.saldo += 250;
	    }
	    if((*confronto)->placarCasa < (*confronto)->placarFora){
	    	timeCasa->info.derrota+=1;
	    	timeCasa->info.partidas += 1;
	    	timeFora->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.vitoria += 1;
	    	timeCasa->info.saldo += 50;
	    	timeFora->info.saldo += 450;
	    }

	}else{
		//simula o jogo
		int valorFinalFora,CartaDefesaTime;
		int penaltiPP = 1;
		embaralhar(cartas,4);
		timeCarta = cartas[0];
		oponenteCarta = cartas[1];
		CartaDefesaTime = 0;
		CartaDefesaOponente = 0;
		if(timeCarta == '2'){
			CartaDefesaTime = rand() %5;
			CartaDefesaTime +=1;
		}
		
		if(oponenteCarta == '2'){
			CartaDefesaOponente = rand() %5;
			CartaDefesaOponente +=1;
		}
		
		
		
		if(oponenteCarta == '1'){
				int overalls[5] = {
		        timeFora->info.elenco.jogador1.overall,
		        timeFora->info.elenco.jogador2.overall,
		        timeFora->info.elenco.jogador3.overall,
		        timeFora->info.elenco.jogador4.overall,
		        timeFora->info.elenco.jogador5.overall
		    };
		
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
	
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
		
			int escolhido = candidatos[rand() % qtd];
		    valorFinalFora = escolhido  + 1;
		}else{
			valorFinalFora = 0;
		}
		
		if(timeCarta == '1'){
			int overalls[5] = {
		        timeCasa->info.elenco.jogador1.overall,
		        timeCasa->info.elenco.jogador2.overall,
		        timeCasa->info.elenco.jogador3.overall,
		        timeCasa->info.elenco.jogador4.overall,
		        timeCasa->info.elenco.jogador5.overall
		    };
	
		    // Encontrar o maior overall
		    int maior = overalls[0];
		    for (int i = 1; i < 5; i++) {
		        if (overalls[i] > maior) {
		            maior = overalls[i];
		        }
		    }
	
		    // Coletar índices dos maiores
		    int candidatos[5];
		    int qtd = 0;
		    for (int i = 0; i < 5; i++) {
		        if (overalls[i] == maior) {
		            candidatos[qtd++] = i;
		        }
		    }
	
		    int escolhido = candidatos[rand() % qtd];
		
		    valorFinal = escolhido  + 1;
		}else{
			valorFinal = 0;
		}
		penalidade = 1;		
		do{
			//ataque time casa
			if(penaltiPP == 1){
				// penalti presidente casa
				encontrado = 0;
				quantidade = calcularPontuacaoGoleiro(timeFora->info.elenco.goleiro1.overall);
				embaralhar(opcoes, 10);
				chute = opcoes[0];
				embaralhar(opcoes, 10);
				for(int i = 0; i < quantidade; i++){
				    if(chute == opcoes[i]) {
				        encontrado = 1; // goleiro catou
				    }
				}
				if(encontrado == 1){
				    timeCasa->info.elenco.presida.errou += 1;
				    timeFora->info.elenco.goleiro1.defesa += 1;
				}else{
				    (*confronto)->placarCasa += 1;
				    timeCasa->info.elenco.presida.gols += 1;
				    timeCasa->info.golsFeitos += 1;
				    timeFora->info.golsSofridos += 1;
				    timeFora->info.elenco.goleiro1.golsSofridos +=1;
				}
				
				// penalti presidente fora
				encontrado = 0;
				quantidade = calcularPontuacaoGoleiro(timeCasa->info.elenco.goleiro1.overall);
				embaralhar(opcoes, 10);
				chute = opcoes[0];
				embaralhar(opcoes, 10);
				for(int i = 0; i < quantidade; i++){
				    if (chute == opcoes[i]) {
				        encontrado = 1; // goleiro catou
				    }
				}
				if(encontrado == 1){
				    timeFora->info.elenco.presida.errou += 1;
				    timeCasa->info.elenco.goleiro1.defesa += 1;
				}else{
				    (*confronto)->placarFora += 1;
				    timeFora->info.elenco.presida.gols += 1;
				    timeFora->info.golsFeitos += 1;
				    timeCasa->info.golsSofridos += 1;
				    timeCasa->info.elenco.goleiro1.golsSofridos +=1;
				}
				penaltiPP = 0;
			}
			
			quantidade = 0;
			embaralhar(opcoes, 10);
			chute = opcoes[0];
			if(valorFinal == penalidade){ //aqui sera ativado gol dobro
				
				if(timeCarta == '1'){
					if(CartaDefesaOponente== penalidade){
							CartaDefesaOponente + 1;
					}
					if(penalidade == 1){
						if(timeCasa->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeCasa->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 3){
						if(timeCasa->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeCasa->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeCasa->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time fora
					if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeFora->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeFora->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}
			    	
					//adiciona os dados
					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeCasa->info.elenco.jogador1.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador1.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeCasa->info.elenco.jogador2.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador2.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeCasa->info.elenco.jogador3.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador3.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeCasa->info.elenco.jogador4.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador4.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeCasa->info.elenco.jogador5.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 2;
							timeCasa->info.elenco.jogador5.gols += 2;
							timeCasa->info.golsFeitos += 2;
							timeFora->info.golsSofridos += 2;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
				}	
				valorFinal = 0;
			}else{
					if(penalidade == 1){
						if(timeCasa->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador1.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador1.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeCasa->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador2.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador2.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 3){
						if(timeCasa->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador3.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador3.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeCasa->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador4.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador4.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeCasa->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeCasa->info.elenco.jogador5.overall <= 80 && timeFora->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeCasa->info.elenco.jogador5.overall <= 77 && timeFora->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time fora
					if (timeFora->info.elenco.goleiro1.overall >= 83 &&  timeFora->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeFora->info.elenco.goleiro1.overall >= 86  && timeFora->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeFora->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeCasa->info.elenco.jogador1.overall >= 84 && timeCasa->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeCasa->info.elenco.jogador2.overall >= 84 && timeCasa->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeCasa->info.elenco.jogador3.overall >= 84 && timeCasa->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeCasa->info.elenco.jogador4.overall >= 84 && timeCasa->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeCasa->info.elenco.jogador5.overall >= 84 && timeCasa->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeFora->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
					
					if(CartaDefesaOponente == penalidade){
						quantidade ++;
						CartaDefesaOponente = 0;
					}
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}
			    	
					//adiciona os dados
					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeCasa->info.elenco.jogador1.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador1.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeCasa->info.elenco.jogador2.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador2.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeCasa->info.elenco.jogador3.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador3.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeCasa->info.elenco.jogador4.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador4.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeCasa->info.elenco.jogador5.errou += 1;
							timeFora->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarCasa += 1;
							timeCasa->info.elenco.jogador5.gols += 1;
							timeCasa->info.golsFeitos += 1;
							timeFora->info.golsSofridos += 1;
							timeFora->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
			
			}
			quantidade = 0;
			embaralhar(opcoes, 10);
			chute = opcoes[0];
			if(valorFinalFora == penalidade){
				
				if(oponenteCarta == '1'){
					
					if(CartaDefesaTime == penalidade){
						CartaDefesaTime += 0;
					}
					if(penalidade == 1){
						if(timeFora->info.elenco.jogador1.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 2){
						if(timeFora->info.elenco.jogador2.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
						
					}
					if(penalidade == 3){
						if(timeFora->info.elenco.jogador3.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 4){
						if(timeFora->info.elenco.jogador4.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					if(penalidade == 5){
						if(timeFora->info.elenco.jogador5.overall >= 87)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall >= 90)
							quantidade--;
						if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
							quantidade++;
						if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
							quantidade++;
					}
					//defesa time casa
					if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
						quantidade += 4;
				    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
						quantidade += 5;
				    if (timeCasa->info.elenco.goleiro1.overall>= 90){
						quantidade += 6;
						switch (penalidade) {
							case 1:
								if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
									quantidade--;
								break;
							case 2:
								if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
									quantidade--;
								break;
							case 3:
								if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
									quantidade--;
								break;
							case 4:
								if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
									quantidade--;
								break;
							case 5:
								if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
									quantidade--;
								break;
						}
						
					}
				    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
						quantidade +=3;
						
					embaralhar(opcoes,10);
					encontrado = 0;
					for(int i = 0; i < quantidade; i++){
			        if(opcoes[i] == chute) {
			            	encontrado = 1; //goleiro CATOU
			        	}
			    	}

					if(penalidade == 1){ //jogador 1
						if(encontrado == 1){
							timeFora->info.elenco.jogador1.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador1.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 2){ //jogador 2
						if(encontrado == 1){
							timeFora->info.elenco.jogador2.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador2.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 3){ //jogador 3
						if(encontrado == 1){
							timeFora->info.elenco.jogador3.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador3.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 4){ //jogador 4
						if(encontrado == 1){
							timeFora->info.elenco.jogador4.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador4.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos += 2;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
					}
					if(penalidade == 5){ //jogador 5
						if(encontrado == 1){
							timeFora->info.elenco.jogador5.errou += 1;
							timeCasa->info.elenco.goleiro1.defesa += 1;
						}else{
							(*confronto)->placarFora += 2;
							timeFora->info.elenco.jogador5.gols += 2;
							timeFora->info.golsFeitos += 2;
							timeCasa->info.golsSofridos +=2 ;
							timeCasa->info.elenco.goleiro1.golsSofridos +=1;
							
						}
					}
					valorFinal = 0;
				}
			}else{
				//ataque time  Fora
				if(penalidade == 1){
					if(timeFora->info.elenco.jogador1.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador1.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador1.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador1.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 2){
					if(timeFora->info.elenco.jogador2.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador2.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador2.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador2.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 3){
					if(timeFora->info.elenco.jogador3.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador3.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador3.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador3.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 4){
					if(timeFora->info.elenco.jogador4.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador4.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador4.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador4.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				if(penalidade == 5){
					if(timeFora->info.elenco.jogador5.overall >= 87)
						quantidade--;
					if(timeFora->info.elenco.jogador5.overall >= 90)
						quantidade--;
					if(timeFora->info.elenco.jogador5.overall <= 80 && timeCasa->info.elenco.goleiro1.overall >= 82)
						quantidade++;
					if(timeFora->info.elenco.jogador5.overall <= 77 && timeCasa->info.elenco.goleiro1.overall >= 80)
						quantidade++;
				}
				//defesa time casa
				if (timeCasa->info.elenco.goleiro1.overall >= 83 &&  timeCasa->info.elenco.goleiro1.overall <= 85) 
					quantidade += 4;
			    if (timeCasa->info.elenco.goleiro1.overall >= 86  && timeCasa->info.elenco.goleiro1.overall <= 89) 
					quantidade += 5;
			    if (timeCasa->info.elenco.goleiro1.overall>= 90){
					quantidade += 6;
					switch (penalidade) {
						case 1:
							if(timeFora->info.elenco.jogador1.overall >= 84 && timeFora->info.elenco.jogador1.overall <= 86)
								quantidade--;
							break;
						case 2:
							if(timeFora->info.elenco.jogador2.overall >= 84 && timeFora->info.elenco.jogador2.overall <= 86)
								quantidade--;
							break;
						case 3:
							if(timeFora->info.elenco.jogador3.overall >= 84 && timeFora->info.elenco.jogador3.overall <= 86)
								quantidade--;
							break;
						case 4:
							if(timeFora->info.elenco.jogador4.overall >= 84 && timeFora->info.elenco.jogador4.overall <= 86)
								quantidade--;
							break;
						case 5:
							if(timeFora->info.elenco.jogador5.overall >= 84 && timeFora->info.elenco.jogador5.overall <= 86)
								quantidade--;
							break;
					}
					
				}
			    if (timeCasa->info.elenco.goleiro1.overall <= 82) 
					quantidade +=3;
				if(CartaDefesaTime == penalidade){
						quantidade ++;
						CartaDefesaTime = 0;
				}
				embaralhar(opcoes,10);
				encontrado = 0;
				for(int i = 0; i < quantidade; i++){
		        if(opcoes[i] == chute) {
		            	encontrado = 1; //goleiro CATOU
		        	}
		    	}
				if(penalidade == 1){ //jogador 1
					if(encontrado == 1){
						timeFora->info.elenco.jogador1.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador1.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 2){ //jogador 2
					if(encontrado == 1){
						timeFora->info.elenco.jogador2.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador2.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						}
				}
				if(penalidade == 3){ //jogador 3
					if(encontrado == 1){
						timeFora->info.elenco.jogador3.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador3.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 4){ //jogador 4
					if(encontrado == 1){
						timeFora->info.elenco.jogador4.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador4.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
					}
				}
				if(penalidade == 5){ //jogador 5
					if(encontrado == 1){
						timeFora->info.elenco.jogador5.errou += 1;
						timeCasa->info.elenco.goleiro1.defesa += 1;
					}else{
						(*confronto)->placarFora += 1;
						timeFora->info.elenco.jogador5.gols += 1;
						timeFora->info.golsFeitos += 1;
						timeCasa->info.golsSofridos += 1;
						timeCasa->info.elenco.goleiro1.golsSofridos +=1;
						
					}
				}
			}

			penalidade++;
			
			//desempate			
			if(penalidade == 6){
				if((*confronto)->placarCasa == (*confronto)->placarFora){
					goldeouro = 1;
				}
			}
			
			if(goldeouro == 1){
				penalidade = 1;
				goldeouro = 2;
			}
			
			if(goldeouro == 2){
				if((*confronto)->placarCasa != (*confronto)->placarFora){
					break; // sai do loop se houver vencedor
				}
				if(penalidade == 6){
					penalidade = 1; // reinicia a rodada do gol de ouro
				}
			}
			//fim do desempate

			
		}while(penalidade<=5);
		
		
		if((*confronto)->placarCasa > (*confronto)->placarFora){
	    	timeCasa->info.vitoria+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.derrota += 1;
	    	timeCasa->info.saldo += 450;
	    	timeFora->info.saldo += 50;
	    }
	    if((*confronto)->placarCasa == (*confronto)->placarFora){
	    	timeCasa->info.empate+=1;
	    	timeCasa->info.partidas += 1;
	    	timeCasa->info.pontos +=1;
	    	timeFora->info.pontos +=1;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.empate += 1;
	    	timeCasa->info.saldo += 250;
	    	timeFora->info.saldo += 250;
	    }
	    if((*confronto)->placarCasa < (*confronto)->placarFora){
	    	timeCasa->info.derrota+=1;
	    	timeCasa->info.partidas += 1;
	    	timeFora->info.pontos +=3;
	    	timeFora->info.partidas += 1;
	    	timeFora->info.vitoria += 1;
	    	timeCasa->info.saldo += 50;
	    	timeFora->info.saldo += 450;
	    }
		
	}
}
#endif
