char telaEspanha(void){
	clrscr();
	MolduraColorida(1, 1, 120, 30,4,4,14,14);
	gotoxy(95,2);
	printf("[??]: Overall Equipe");
	
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
	printCentralizado("KL PENALTY - ESPANHA",3,4);
	gotoxy(42, 4);
	printf("SELECIONE A EQUIPE QUE DESEJA JOGAR");
	gotoxy(35, 29);
	printf("[APERTE] O NUMERO DA EQUIPE QUE DESEJA SELECIONAR");

	
	gotoxy(8,11);
    printf("[ APERTE  1 ]");
    gotoxy(12,8);
    textcolor(9);
    printf("1K FC");
    gotoxy(20,7);
    printf("[??]");
	MolduraColorida(4, 6, 24, 10, 5, 5, 9, 9);
	
	gotoxy(31,11);
    printf("[ APERTE  2 ]");
    gotoxy(30,8);
    textcolor(12);
    printf("ANIQUILADORES FC");
    gotoxy(43,7);
    printf("[??]");
	MolduraColorida(27, 6, 47, 10, 4, 4, 12, 12);
	
	gotoxy(54,11);
    printf("[ APERTE  3 ]");
    gotoxy(56,8);
    textcolor(11);
    printf("EL BARRIO");
    gotoxy(66,7);
    printf("[??]");
	MolduraColorida(50, 6, 70, 10, 11, 11, 8, 8);
	
	gotoxy(77,11);
    printf("[ APERTE  4 ]");
    gotoxy(78,8);
    textcolor(4);
    printf("JIJANTES FC");
    gotoxy(89,7);
    printf("[??]");
	MolduraColorida(73, 6, 93, 10, 1, 1, 4, 4);
	
	gotoxy(101,11);
    printf("[ APERTE 5 ]");
    gotoxy(102,8);
    textcolor(8);
    printf("KUNISPORTS");
    gotoxy(113,7);
    printf("[??]");
	MolduraColorida(96, 6, 117, 10, 8, 8, 5, 5);
	
	gotoxy(8,19);
    printf("[ APERTE  6 ]");
    gotoxy(8,16);
    textcolor(2);
    printf("LOS TRONCOS FC");
    gotoxy(20,15);
    printf("[??]");
	MolduraColorida(4, 14, 24, 18, 2, 2, 7, 7);	
	
	gotoxy(31,19);
    printf("[ APERTE  7 ]");
    gotoxy(35,16);
    textcolor(15);
    printf("PIO FC");
    gotoxy(43,15);
    printf("[??]");
	MolduraColorida(27, 14, 47, 18, 8, 14, 15, 15);
	
	gotoxy(54,19);
    printf("[ APERTE  8 ]");
    gotoxy(55,16);
    textcolor(13);
    printf("PORCINOS FC");
    gotoxy(66,15);
    printf("[??]");
	MolduraColorida(50, 14, 70, 18, 13, 13, 13, 13);
	
	gotoxy(77,19);
    printf("[ APERTE  9 ]");
    gotoxy(77,16);
    textcolor(14);
    printf("RAYO BARCELONA");
    gotoxy(89,15);
    printf("[??]");
	MolduraColorida(73, 14, 93, 18, 8, 8,14,14);
	
	gotoxy(101,19);
    printf("[ APERTE 0 ]");
    gotoxy(102,16);
    textcolor(1);
    printf("SAIYANS FC");
    gotoxy(113,15);
    printf("[??]");
	MolduraColorida(96, 14, 117, 18, 14, 1, 6,6);
		
	gotoxy(31,27);
    printf("[ APERTE  W ]");
    gotoxy(31,24);
    textcolor(8);
    printf("ULT. MOSTOLES");
    gotoxy(43,23);
    printf("[??]");
	MolduraColorida(27, 22, 47, 26, 14, 4, 8, 8);
	
	gotoxy(77,27);
    printf("[ APERTE  E ]");
    gotoxy(78,24);
    textcolor(8);
    printf("xBURYER TEAM");
    gotoxy(89,23);
    printf("[??]");
	MolduraColorida(73, 22, 93, 26, 8, 8,15,15);

	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}
void mudarcor(){
	gotoxy(13,8);textcolor(10);
	printf("1");
	gotoxy(13,9);textcolor(14);
	printf("2");
	gotoxy(13,10);
	printf("3");
	gotoxy(13,11);
	printf("4");
	gotoxy(13,12);
	printf("5");
	gotoxy(13,13);
	printf("6");
	gotoxy(13,14);
	textcolor(6);
	printf("7");
	gotoxy(13,15);
	printf("8");
	gotoxy(13,16);
	printf("9");
	gotoxy(12,17);
	printf("10");textcolor(4);
	gotoxy(12,18);
	printf("11");
	gotoxy(12,19);
	printf("12");textcolor(15);
}


char ligaEspanha(listaDupla *lista, listaDupla *lista2,int buscar,SemanaBrasil* campeonato,int rodada,int playoffJogos,int rodadaOficial){
	
	
	int jogador1, jogador2;
	clrscr();
	listaDupla *aux = buscarTimeNaLista(lista, buscar);
	int y,x,i;
	
	i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 14 : 4); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "$" : "@");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "$" : "@");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,4,4,14,14);
	
	Moldura(10, 5, 68, 20);
	
	gotoxy(12,4);
	printf("TABELA GERAL");
	textcolor(14);
	gotoxy(25,4);
	printf("KL - PENALTY BRASIL");
	textcolor(15);
	gotoxy(11,6);
	printf("POS");
	y = 6;
	while(y <= 19){
		gotoxy(14, y); 
    	printf("%c", 186);
    	gotoxy(35, y); 
    	printf("%c", 186);
    	gotoxy(41, y); 
    	printf("%c", 186);
		gotoxy(45, y);
    	printf("%c", 186);
    	gotoxy(49, y); 
    	printf("%c", 186);
    	gotoxy(53, y);
    	printf("%c", 186);
    	gotoxy(58, y); 
    	printf("%c", 186);
    	gotoxy(63,y);
    	printf("%c", 186);
    	y++;
	}
	
	
	gotoxy(22,6);
	printf("EQUIPE");
	
	gotoxy(37,6);
	printf("PTS");
	
	gotoxy(43,6);
	printf("V");
	
	gotoxy(47,6);
	printf("E");

	gotoxy(51,6);
	printf("D");

	gotoxy(55,6);
	printf("GF");
	
	gotoxy(60,6);
	printf("GS");
	
	gotoxy(65,6);
	printf("GA");
	
	x = 11;
	while(x < 68){
		gotoxy(x, 7);
		if (x != 14 || x != 35 || x != 41 || x != 45 || x != 49 || x != 53 || x != 58 || x != 63)
			printf("%c", 205);
		x++;
	}
	
	

	Moldura(69, 5, 111, 20);
	
	if(rodada == 1)
	{	
		gotoxy(84,4);
		printf("PROXIMOS JOGOS --> [M]");
		
	}else if(rodada == 11){
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS");
	}else{
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS --> [M]");
	}
	
	
	Moldura(10, 21, 27, 24);
	gotoxy(16,22);
	printf("ELENCO");
	gotoxy(24,23);
	printf("[E]");

	Moldura(30, 21, 48, 24);
	gotoxy(34,22);
	printf("ESTATISTICAS");
	gotoxy(45,23);
	printf("[W]");

	
	
	Moldura(51, 21, 69, 24);
	gotoxy(55,22);
	printf("? EM BREVE ?");
	
	Moldura(72, 21, 90, 24);
	gotoxy(76,22);
	printf("PLAY - OFFS");
	gotoxy(87,23);
	printf("[P]");

	
	MolduraColorida(93, 21, 111, 24,14,14,14,14);
	textcolor(14);
	gotoxy(99,22);
	printf("SIMULAR");
	gotoxy(99,23);
	printf(" AGORA   [S]");
	textcolor(15);
	
	
	
	Moldura(10, 25, 27, 28);/*
	gotoxy(16,25);
	printf("TROCAS");
	gotoxy(24,26);
	printf("[T]");*/
	gotoxy(14,26);
	printf("? EM BREVE ?");
	
	Moldura(30, 25, 48, 28);/*
	gotoxy(34,25);
	printf("ESTATISTICAS");
	gotoxy(36,26);
	printf("POR TIME [G]");*/
	gotoxy(34,26);
	printf("? EM BREVE ?");
	
	Moldura(51, 25, 69, 28);/*
	gotoxy(57,25);
	printf("CARTAS");
	gotoxy(66,26);
	printf("[C]");*/
	gotoxy(55,26);
	printf("? EM BREVE ?");
	
	Moldura(72, 25, 90, 28);/*
	gotoxy(78,25);
	printf("OUTRAS");
	gotoxy(75,26);
	printf("KL - LIGAS");
	gotoxy(87,26);
	printf("[L]");*/
	gotoxy(76,26);
	printf("? EM BREVE ?");
	
	MolduraColorida(93, 25, 111, 28,14,14,14,14);
	textcolor(14);
	gotoxy(97,26);
	printf("JOGAR AGORA");
	gotoxy(108,27);
	printf("[J]");
	textcolor(15);
	/*
    if(playoffJogos == 1){
    		textcolor(14);
			gotoxy(97,25);
			printf("JOGAR AGORA");
			gotoxy(99,26);
			printf("PLAYOFF  [J]");
			textcolor(15);
    }else if(playoffJogos == 0){
    		textcolor(14);
    		gotoxy(97,25);
			printf("           ");
			gotoxy(99,25);
			printf("SIMULAR");
			gotoxy(99,26);
			printf("PLAYOFF  [J]");
			textcolor(15);
    }*/
	
	printCentralizado("APERTA [H] PARA ACESSAR MENU 'AJUDA' ",29,15);
	gotoxy(10,2);
	textcolor(aux->info.elenco.cor1);
	printf("%s  PRESIDENTE: %s",aux->info.elenco.nomeEquipe, aux->info.elenco.presida.nome);
	textcolor(15);
	gotoxy(69,2);
	if(aux->info.saldo < 1000){
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.0f", aux->info.elenco.valorMercado/1000, aux->info.saldo);
	}else if(aux->info.saldo <= 9999)
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	else if(aux->info.saldo > 9999 && aux->info.saldo < 99999)
	{
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	}else
		printf("VALOR DE MERCADO: $ %.3f   SALDO: $ %.3f", aux->info.elenco.valorMercado/1000, aux->info.saldo/1000);
	
	if(rodadaOficial > 12){
		exibirTabela(lista2,8);
	}else{
		exibirTabela(lista, 8);
	}
	mudarcor();
	exibirSemana(campeonato,rodada);
	
	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}
