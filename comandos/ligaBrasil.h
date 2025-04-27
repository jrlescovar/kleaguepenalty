#ifndef LIGABRASIL_H
#define LIGABRASIL_H
char telaBrasil(void){
	clrscr();
	MolduraColorida(1, 1, 120, 30,2,2,14,14);
	gotoxy(85,3);
	printf("P: Presidente");
	gotoxy(100,3);
	printf("#: Jogador Estrela");
	gotoxy(92,4);
	printf("$: Valor de Mercado");
	gotoxy(95,2);
	printf("[??]: Overall ");
	
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
	printCentralizado("KL PENALTY - BRASIL",3,14);
	gotoxy(42, 4);
	printf("SELECIONE A EQUIPE QUE DESEJA JOGAR");
	gotoxy(35, 28);
	printf("[APERTE] O NUMERO DA EQUIPE QUE DESEJA SELECIONAR");

	
	gotoxy(8,15);
    printf("[ APERTE  1 ]");
    gotoxy(10,7);
    textcolor(11);
    printf("CAPIM FC");
    gotoxy(9,9);
    textcolor(3);
    printf("P: JonVlogs");
    gotoxy(8,11);
    printf("#: Barata [90]");
    gotoxy(13,13);
    printf("$: XXX.XXX");
	MolduraColorida(4, 6, 24, 14, 11, 2, 8, 8);
	
	gotoxy(31,15);
    printf("[ APERTE  2 ]");
    gotoxy(33	,7);
    textcolor(1);
    printf("DENDELE FC");
    gotoxy(32,9);
    textcolor(14);
    printf("P: Luquet4");
    gotoxy(28,11);
    printf("#: Marcelin Jr [83]");
    gotoxy(36,13);
    textcolor(1);
    printf("$: XXX.XXX");
	MolduraColorida(27, 6, 47, 14, 1, 1, 14, 14);
	
	gotoxy(54,15);
    printf("[ APERTE  3 ]");
    gotoxy(52,7);
    textcolor(1);
    printf("DESIMPEDIDOS GOTI");
    gotoxy(56,9);
    textcolor(1);
    printf("P: Yuri 22");
    gotoxy(53,11);
    printf("#: J. Pedro [88]");
    gotoxy(59,13);
    printf("$: XXX.XXX");
	MolduraColorida(50, 6, 70, 14, 2, 2, 1, 1);
	
	gotoxy(77,15);
    printf("[ APERTE  4 ]");
    gotoxy(77,7);
    textcolor(9);
    printf("FC REAL ELITE");
    gotoxy(77,9);
    textcolor(9);
    printf("P: Allan Stag");
    gotoxy(76,11);
    printf("#: Davi .I [89]");
    gotoxy(82,13);
    textcolor(13);
    printf("$: XXX.XXX");
	MolduraColorida(73, 6, 93, 14, 13, 13, 9, 9);
	
	gotoxy(101,15);
    printf("[ APERTE 5 ]");
    gotoxy(103,7);
    textcolor(15);
    printf("FLUXO FC");
    gotoxy(103,9);
    textcolor(8);
    printf("P: Nobru");
    gotoxy(100,11);
    printf("#: Boolt [84]");
    gotoxy(106,13);
    textcolor(4);
    printf("$: XXX.XXX");
	MolduraColorida(96, 6, 117, 14, 8, 4, 15, 15);
	
	gotoxy(8,26);
    printf("[ APERTE  6 ]");
    gotoxy(8,18);
    textcolor(5);
    printf("FUNKBOL CLUBE");
    gotoxy(8,20);
    textcolor(14);
    printf("P: MC Hariel");
    gotoxy(6,22);
    printf("#: Douglinha [87]");
    gotoxy(13,24);
    textcolor(5);
    printf("$: XXX.XXX");
	MolduraColorida(4, 17, 24, 25, 5, 5, 14, 14);
	
	gotoxy(31,26);
    printf("[ APERTE  7 ]");
    gotoxy(33,18);
    textcolor(15);
    printf("FURIA FC");
    gotoxy(30,20);
    textcolor(7);
    printf("P: Cris Guedes");
    gotoxy(30,22);
    printf("#: Leleti [92]");
    gotoxy(36,24);
    printf("$: XXX.XXX");
	MolduraColorida(27, 17, 47, 25, 7, 15, 15, 7);
	
	gotoxy(54,26);
    printf("[ APERTE  8 ]");
    gotoxy(57,18);
    textcolor(15);
    printf("G3X FC");
    gotoxy(56,20);
    textcolor(1);
    printf("P: Gaules");
    gotoxy(52,22);
    printf("#: Kelvin K9 [95]");
    gotoxy(59,24);
    textcolor(14);
    printf("$: XXX.XXX");
	MolduraColorida(50, 17, 70, 25, 15, 15, 1, 14);
	
	gotoxy(77,26);
    printf("[ APERTE  9 ]");
    gotoxy(80,18);
    textcolor(2);
    printf("LOUD SC");
    gotoxy(79,20);
    textcolor(10);
    printf("P: Coringa");
    gotoxy(78,22);
    printf("#: ?????? [??]");
    gotoxy(82,24);
    textcolor(2);
    printf("$: XXX.XXX");
	MolduraColorida(73, 17, 93, 25, 2, 2, 10, 10);
	
	gotoxy(101,26);
    printf("[ APERTE 0 ]");
    gotoxy(101,18);
    textcolor(15);
    printf("Nyvelados FC");
    gotoxy(103,20);
    textcolor(8);
    printf("P: Nyvi");
    gotoxy(100,22);
    printf("#: Leo Gol [88]");
    gotoxy(106,24);
    textcolor(15);
    printf("$: XXX.XXX");
	MolduraColorida(96, 17, 117, 25, 8, 8, 15, 15);

	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}

char ligaBrasil(){
	clrscr();
	int y,x,i;
	
	i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 14 : 2); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "#" : "$");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "#" : "$");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,2,2,14,14);
	
	Moldura(10, 5, 68, 18);
	
	gotoxy(12,4);
	printf("TABELA GERAL");
	textcolor(14);
	gotoxy(25,4);
	printf("KL - PENALTY BRASIL");
	textcolor(15);
	gotoxy(11,6);
	printf("POS");
	
	y = 6;
	while(y <= 17){
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
	
	
	
	
	Moldura(69, 5, 111, 18);
	gotoxy(83,4);
	printf("PROXIMOS JOGOS");
	
	
	Moldura(10, 20, 27, 23);
	gotoxy(16,21);
	printf("ELENCO");
	gotoxy(24,22);
	printf("[E]");

	Moldura(30, 20, 48, 23);
	gotoxy(34,21);
	printf("ESTATISTICAS");
	gotoxy(45,22);
	printf("[W]");
	
	Moldura(51, 20, 69, 23);
	gotoxy(55,21);
	printf("? EM BREVE ?");
	
	Moldura(72, 20, 90, 23);
	gotoxy(76,21);
	printf("PLAY - OFFS");
	gotoxy(87,22);
	printf("[P]");
	
	Moldura(93, 20, 111, 23);
	gotoxy(96,21);
	printf("? EM BREVE ?");
	
	
	
	Moldura(10, 24, 27, 27);
	gotoxy(16,25);
	printf("TROCAS");
	gotoxy(24,26);
	printf("[T]");
	
	Moldura(30, 24, 48, 27);
	gotoxy(34,25);
	printf("ESTATISTICAS");
	gotoxy(33,26);
	printf("POR TIME [G]");
	
	Moldura(51, 24, 69, 27);
	gotoxy(57,25);
	printf("CARTAS");
	gotoxy(66,26);
	printf("[C]");
	
	Moldura(72, 24, 90, 27);
	gotoxy(78,25);
	printf("OUTRAS");
	gotoxy(75,26);
	printf("KL - LIGAS");
	gotoxy(87,26);
	printf("[L]");
	
	MolduraColorida(93, 24, 111, 27,14,14,14,14);
	textcolor(14);
	gotoxy(97,25);
	printf("JOGAR AGORA");
	gotoxy(108,26);
	printf("[J]");
	textcolor(15);
	
	gotoxy(10,2);
	textcolor(11);
	printf("CAPIM FC   PRESIDENTE: Jon Vlogs");
	textcolor(15);
	gotoxy(65,2);
	printf("VALOR DE MERCADO: $ 000.000   SALDO ATUAL $ 000.000");
	
	
	
	gotoxy(119,29);
	return toupper(getch());
}

#endif
