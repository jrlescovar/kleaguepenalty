void limparcartapresida(int n){
	if(n == 1){
	gotoxy(11,7);
	printf("         \n");
	gotoxy(11,8);
	printf("         \n");
	gotoxy(11,9);
	printf("         \n");
	gotoxy(11,10);
	printf("         \n");
	gotoxy(11,11);
	printf("         \n");
	gotoxy(11,12);
	printf("         \n");
	gotoxy(6,13);
	printf("                       ");

	}else{
		gotoxy(100,7);
		printf("         \n");
		gotoxy(100,8);
		printf("         \n");
		gotoxy(100,9);
		printf("         \n");
		gotoxy(100,10);
		printf("         \n");
		gotoxy(100,11);
		printf("         \n");
		gotoxy(100,12);
		printf("         \n");
		gotoxy(95,13);
		printf("                      ");
		textcolor(15);
	}
	
}
void limparcartaSecreta(int n){
	if(n == 1){
	gotoxy(11,15);
	printf("         \n");
	gotoxy(11,16);
	printf("         \n");
	gotoxy(11,17);
	printf("         \n");
	gotoxy(11,18);
	printf("         \n");
	gotoxy(11,19);
	printf("         \n");
	gotoxy(11,20);
	printf("         \n");
	gotoxy(6,21);
	printf("                       ");

	}else{
		gotoxy(100,15);
		printf("         \n");
		gotoxy(100,16);
		printf("         \n");
		gotoxy(100,17);
		printf("         \n");
		gotoxy(100,18);
		printf("         \n");
		gotoxy(100,19);
		printf("         \n");
		gotoxy(100,20);
		printf("         \n");
		gotoxy(95,21);
		printf("                      ");
		textcolor(15);
	}
	
}
void limparmsg1(){
	gotoxy(45,22);
	printf("                                                ");//limpar mensagem de gol ou defesa.
}
void msgErroA(){
	printCentralizado("[ TECLA INVALIDA ] TENTE DE [1] a [9] ou [C] para Cavadinha",26,15);
	Sleep(1700);
	printCentralizado("                                                             ",26,15);
}
void msgErroP(){
	printCentralizado("CARTA PENALTI PRESIDENTE JA FOI UTILIZADA",26,15);
	Sleep(1700);
	printCentralizado("                                          ",26,15);
}
void msgErroC(){
	printCentralizado("                                                             ",26,15);
	printCentralizado("CARTA SECRETA JA FOI UTILIZADA",26,15);
	Sleep(1700);
	printCentralizado("                                           ",26,15);
}
void msgCarta(){
	printCentralizado("CARTA SECRETA INDISPONIVEL NESSA ROUND, ACESSA MENU AJUDA PARA ENTENDER MAIS SOBRE",26,15);
	Sleep(1700);
	printCentralizado("                                                                                    ",26,15);
}
void msgcontagemPlayoff(int rodadaOficial) {
    gotoxy(39, 19);
    printf("FALTAM %d RODADAS PARA O INICIO DOS PLAYOFFS", 10 - rodadaOficial);
    gotoxy(119, 29);
    Sleep(1200);
}
