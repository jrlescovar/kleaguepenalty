void cartaPenaltiCasa(){
	textcolor(11);
	gotoxy(11,7);
    printf(" .-----. \n");
	gotoxy(11,8);
	printf("| P _ P |\n");
	gotoxy(11,9);
	printf("|  [P]  |\n");
	gotoxy(11,10);
	printf("|   :   |\n");
	gotoxy(11,11);
	printf("| P - P |\n");
	gotoxy(11,12);
	printf(" '-----' \n");
	gotoxy(6,13);
	printf("[PENALTI PRESIDENTE]");
	textcolor(15);
}
void cartaPenaltiCasaOponente(){
	textcolor(11);
	gotoxy(11,7);
    printf(" .-----. \n");
	gotoxy(11,8);
	printf("| P _ P |\n");
	gotoxy(11,9);
	printf("|  [P]  |\n");
	gotoxy(11,10);
	printf("|   :   |\n");
	gotoxy(11,11);
	printf("| P - P |\n");
	gotoxy(11,12);
	printf(" '-----' \n");
	textcolor(15);
}
void cartaPenaltiFora(){
	textcolor(11);
	gotoxy(100,7);
    printf(" .-----. \n");
	gotoxy(100,8);
	printf("| P _ P |\n");
	gotoxy(100,9);
	printf("|  [P]  |\n");
	gotoxy(100,10);
	printf("|   :   |\n");
	gotoxy(100,11);
	printf("| P - P |\n");
	gotoxy(100,12);
	printf(" '-----' \n");
	gotoxy(95,13);
	printf("[PENALTI PRESIDENTE]");
	textcolor(15);
}
void cartaPenaltiForaOponente(){
	textcolor(11);
	gotoxy(100,7);
    printf(" .-----. \n");
	gotoxy(100,8);
	printf("| P _ P |\n");
	//gotoxy(100,9);
	//printf("|   :   |\n");
	gotoxy(100,9);
	printf("|  [P]  |\n");
	gotoxy(100,10);
	printf("|   :   |\n");
	gotoxy(100,11);
	printf("| P - P |\n");
	gotoxy(100,12);
	printf(" '-----' \n");
	textcolor(15);
}
void cartaSecretaCasa(char cartaId, int raridade){
	if(cartaId == '1'){
		textcolor(raridade);
		gotoxy(11,15);
	    printf(" .-----. \n");
		gotoxy(11,16);
		printf("| G - 2 |\n");
		gotoxy(11,17);
		printf("|  [X]  |\n");
		gotoxy(11,18);
		printf("|   :   |\n");
		gotoxy(11,19);
		printf("| G X 2 |\n");
		gotoxy(11,20);
		printf(" '-----' \n");
		gotoxy(10,21);
		printf("[GOL DOBRO]");
		textcolor(15);
	}
	if(cartaId == '2'){
		textcolor(raridade);
		gotoxy(11,15);
	    printf(" .-----. \n");
		gotoxy(11,16);
		printf("| R + 1 |\n");
		gotoxy(11,17);
		printf("|  [X]  |\n");
		gotoxy(11,18);
		printf("|   :   |\n");
		gotoxy(11,19);
		printf("| R + 1 |\n");
		gotoxy(11,20);
		printf(" '-----' \n");
		gotoxy(11,21);
		printf("[REFLEXO]");
		textcolor(15);
	}
}
void cartaSecretaFora(char cartaId, int raridade){
	if(cartaId == '1'){
		textcolor(raridade);
		gotoxy(100,15);
	    printf(" .-----. \n");
		gotoxy(100,16);
		printf("| G - 2 |\n");
		gotoxy(100,17);
		printf("|  [X]  |\n");
		gotoxy(100,18);
		printf("|   :   |\n");
		gotoxy(100,19);
		printf("| G X 2 |\n");
		gotoxy(100,20);
		printf(" '-----' \n");
		gotoxy(99,21);
		printf("[GOL DOBRO]");
		textcolor(15);
	}
	if(cartaId == '2'){
		textcolor(raridade);
		gotoxy(100,15);
	    printf(" .-----. \n");
		gotoxy(100,16);
		printf("| R + 1 |\n");
		gotoxy(100,17);
		printf("|  [X]  |\n");
		gotoxy(100,18);
		printf("|   :   |\n");
		gotoxy(100,19);
		printf("| R + 1 |\n");
		gotoxy(100,20);
		printf(" '-----' \n");
		gotoxy(100,21);
		printf("[REFLEXO]");
		textcolor(15);
	}
}


void cartaSecretaOponenteCasa(int raridade){
	textcolor(raridade);
	gotoxy(11,15);
    printf(" .-----. \n");
	gotoxy(11,16);
	printf("| ? _ ? |\n");
	gotoxy(11,17);
	printf("|  [?]  |\n");
	gotoxy(11,18);
	printf("|   :   |\n");
	gotoxy(11,19);
	printf("| ? - ? |\n");
	gotoxy(11,20);
	printf(" '-----' \n");
	textcolor(15);
}
void cartaSecretaOponenteFora(int raridade){
	textcolor(raridade);
	gotoxy(100,15);
    printf(" .-----. \n");
	gotoxy(100,16);
	printf("| ? _ ? |\n");
	gotoxy(100,17);
	printf("|  [?]  |\n");
	gotoxy(100,18);
	printf("|   :   |\n");
	gotoxy(100,19);
	printf("| ? - ? |\n");
	gotoxy(100,20);
	printf(" '-----' \n");
	textcolor(15);
}
void exibirTrave(){
	int y;
	MolduraColoridaTrave(30,6,90,18,7,7,7,7);
	gotoxy(31,9);
	printf("___________________________________________________________");
	gotoxy(31,14);
	printf("___________________________________________________________");
	gotoxy(30,18);
	printf("                                                                  ");
	y = 1;
	while(y < 7){
		if(y < 4){
			gotoxy(38,y+6);
			printf("|");
			gotoxy(82,y+6);
			printf("|");
		}else{
			gotoxy(38,y+11);
			printf("|");
			gotoxy(82,y+11);
			printf("|");
		}
		y++;
	}
	y = 1;
	while(y < 4){
		gotoxy(60,y+6);
		printf("|");
		//gotoxy(60,y+14);
		//printf("|");
		y++;
	}
	y = 1;
	while(y < 6){
		gotoxy(48,y+9);
		printf("|");
		gotoxy(72,y+9);
		printf("|");
		y++;
	}
	//linhda de cima
	gotoxy(33,8);
	printf("[1]");
	gotoxy(48,7);
	printf("[2]");
	gotoxy(71,7);
	printf("[3]");
	gotoxy(85,8);
	printf("[4]");
	//meio
	gotoxy(38,12);
	printf("[5]");
	gotoxy(59,12);
	printf("[C]");
	gotoxy(81,12);
	printf("[6]");
	//rasteira
	gotoxy(33,16);
	printf("[7]");
	gotoxy(59,16);
	printf("[8]");
	gotoxy(85,16);
	printf("[9]");
	gotoxy(119,29);

}
void encontrarAreas(int encontrado, char tecla){
	Sleep(250);
	if(encontrado == 1){//catou
		printCentralizado("DEFENDEUUUUUUU",22,4);
		textcolor(4);
	}else{//golll
		printCentralizado("GOOLLLLLLLLLLL",22,10);
		textcolor(10);
	}
	if(tecla == 49){
		gotoxy(33,8);
		printf("[1]");
	}
	if(tecla == 50){
		gotoxy(48,7);
		printf("[2]");
	}
	if(tecla == 51){
		gotoxy(71,7);
		printf("[3]");
	}
	if(tecla == 52){
		gotoxy(85,8);
		printf("[4]");
	}
	if(tecla == 53){
		gotoxy(38,12);
		printf("[5]");
	}
	if(tecla == 54){
		gotoxy(81,12);
		printf("[6]");
	}
	if(tecla == 55){
		gotoxy(33,16);
		printf("[7]");	
	}
	if(tecla == 56){
		gotoxy(59,16);
		printf("[8]");
	}
	if(tecla == 57){
		gotoxy(85,16);
		printf("[9]");
	}
	if(tecla == 'C'){
		gotoxy(59,12);
		printf("[C]");
	}
	Sleep(1400);
	textcolor(15);	
	gotoxy(45,22);
	printf("                                                ");//limpar mensagem de gol ou defesa.
	gotoxy(119,29);			
}
void encontrarAreasGoleiro(int encontrado, char tecla){
	Sleep(450);
	if(encontrado == 1){//catou
		printCentralizado("DEFENDEUUUUUUU",22,10);
		textcolor(10);
	}else{//golll
		printCentralizado("GOOLLL DELES",22,4);
		textcolor(4);
	}
	if(tecla == 49){
		gotoxy(33,8);
		printf("[1]");
	}
	if(tecla == 50){
		gotoxy(48,7);
		printf("[2]");
	}
	if(tecla == 51){
		gotoxy(71,7);
		printf("[3]");
	}
	if(tecla == 52){
		gotoxy(85,8);
		printf("[4]");
	}
	if(tecla == 53){
		gotoxy(38,12);
		printf("[5]");
	}
	if(tecla == 54){
		gotoxy(81,12);
		printf("[6]");
	}
	if(tecla == 55){
		gotoxy(33,16);
		printf("[7]");	
	}
	if(tecla == 56){
		gotoxy(59,16);
		printf("[8]");
	}
	if(tecla == 57){
		gotoxy(85,16);
		printf("[9]");
	}
	if(tecla == 'C'){
		gotoxy(59,12);
		printf("[C]");
	}
	gotoxy(119,29);
	Sleep(1700);
	limparmsg1();
	textcolor(15);				
}
void encontrarAreasDefesa(char tecla){
	textcolor(9);
	if(tecla == 49){
		gotoxy(33,8);
		printf("[1]");
	}
	if(tecla == 50){
		gotoxy(48,7);
		printf("[2]");
	}
	if(tecla == 51){
		gotoxy(71,7);
		printf("[3]");
	}
	if(tecla == 52){
		gotoxy(85,8);
		printf("[4]");
	}
	if(tecla == 53){
		gotoxy(38,12);
		printf("[5]");
	}
	if(tecla == 54){
		gotoxy(81,12);
		printf("[6]");
	}
	if(tecla == 55){
		gotoxy(33,16);
		printf("[7]");	
	}
	if(tecla == 56){
		gotoxy(59,16);
		printf("[8]");
	}
	if(tecla == 57){
		gotoxy(85,16);
		printf("[9]");
	}
	if(tecla == 'C'){
		gotoxy(59,12);
		printf("[C]");
	}
	gotoxy(119,29);
	textcolor(15);
}
