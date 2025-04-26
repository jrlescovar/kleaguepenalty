#ifndef VISUAL_H
#define VISUAL_H
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void padrao(void){
	textcolor(7);//cor padrão
	textbackground(0);//fundo padrão
}
void Moldura(int CI, int LI, int CF, int LF)
{
    int i;
    gotoxy(CI, LI);
    printf("%c", 201);
    gotoxy(CI, LF);
    printf("%c", 200);
    gotoxy(CF, LI);
    printf("%c", 187);
    gotoxy(CF, LF);
    printf("%c", 188);
    for (i = CI + 1; i < CF; i++)
    {
        gotoxy(i, LI);
        printf("%c", 205);
        gotoxy(i, LF);
        printf("%c", 205);
    }
    for (i = LI + 1; i < LF; i++)
    {
        gotoxy(CI, i);
        printf("%c", 186);
        gotoxy(CF, i);
        printf("%c", 186);
    }
}
void ClearTela(void) //criar em breve
{ // limpa tela pricipal e mensagem
    int x, y;
    for (x = 1; x <= 79; x++)
    {
        for (y = 1; y <= 20; y++)
        {
            gotoxy(x, y);
            printf(" ");
        }
    }

}


void mudarcorautomatico(void){
	int cor_banner, cor1, cor2, cor3;
    int cores_permitidas[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14};
    int total_cores = sizeof(cores_permitidas) / sizeof(cores_permitidas[0]);

    srand(time(NULL)); // inicializa aleatoriedade

    do {
        // Cor aleatória para o banner
        cor_banner = cores_permitidas[rand() % total_cores];

        // Três cores diferentes para as mensagens
        int idx1, idx2, idx3;
        do {
            idx1 = rand() % total_cores;
            idx2 = rand() % total_cores;
            idx3 = rand() % total_cores;
        } while (idx1 == idx2 || idx1 == idx3 || idx2 == idx3);

        cor1 = cores_permitidas[idx1];
        cor2 = cores_permitidas[idx2];
        cor3 = cores_permitidas[idx3];

        // Imprime o banner com cor animada
        textcolor(cor_banner);
        gotoxy(23,5);
	    printf("___  _  ___        ____     ____  _____    _____  ____    ________  ___ ___    \n");
	    gotoxy(23,6);
		printf("|  |/ ] | |       |    \\   /  __] |    \\  /     \\ |  |    |      |  |  |  |    \n");
	    gotoxy(23,7);
		printf("|  ' /  | |       |  o  ) /  [___ |_ |  \\ |  o  | |  |    |      |  |  |  |     \n");
	    gotoxy(23,8);
		printf("|    \\  | |___    |   _/  |    _] |  |  | |     | |  |___ |_|  |_|  |  ~  |     \n");
	    gotoxy(23,9);
		printf("|     | |    |    |  |    |   [_  |  |  | |  _  | |     |   |  |    |  ___,     \n");
	    gotoxy(23,10);
		printf("|  .  | |    |    |  |    |     | |  |  | |  |  | |     |   |  |    |   |       \n");
	    gotoxy(23,11);
		printf("|__|\\_| |____|    |__|    |_____| |__|__| |__|__| |_____|   |__|    |____/      \n");

        // Mensagens piscando embaixo
        gotoxy(31, 20);
        textcolor(cor1);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        gotoxy(31, 22);
        textcolor(cor2);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        gotoxy(31, 24);
        textcolor(cor3);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        Sleep(500); // tempo de espera entre animações
    } while (!kbhit());
}
void apresentacao(void){
	
	gotoxy(49, 14);
	printf("KL Penalty | version 1.1");
	gotoxy(36, 15);
	printf("Copyright Joao Lescovar | 2025. All Rights Reserved");
	gotoxy(21, 16);
	printf("Jogo Desenvolvido com base nas Estruturas de dados apresentadas na Universidade");
	gotoxy(39, 17);
	printf("Desenvolvido para treinar Estrutura de dados");
	gotoxy(5, 29);
	printf("Entre em contato comigo : jrlescovar@gmail.com");
	gotoxy(92,29);
	printf("Ultima Att em: 24/04/2025");
	mudarcorautomatico();

}
#include <conio2.h>
#include <stdio.h>

void MolduraColorida(int CI, int LI, int CF, int LF, int corTopo, int corBase, int corEsquerda, int corDireita) {
    int i;
    // Canto superior esquerdo
    textcolor(corEsquerda);
    gotoxy(CI, LI);
    printf("%c", 201);
    gotoxy(CI, LF);
    printf("%c", 200);
    textcolor(corDireita);
    gotoxy(CF, LI);
    printf("%c", 187);
    gotoxy(CF, LF);
    printf("%c", 188);
    textcolor(corTopo);
    for (i = CI + 1; i < CF; i++) {
        gotoxy(i, LI);
        printf("%c", 205);
    }
    textcolor(corBase);
    for (i = CI + 1; i < CF; i++) {
        gotoxy(i, LF);
        printf("%c", 205);
    }
    textcolor(corEsquerda);
    for (i = LI + 1; i < LF; i++) {
        gotoxy(CI, i);
        printf("%c", 186);
    }
    textcolor(corDireita);
    for (i = LI + 1; i < LF; i++) {
        gotoxy(CF, i);
        printf("%c", 186);
    }
    textcolor(WHITE);
} 

void tela1(void)
{
    system("cls");
    Moldura(1, 1, 120, 30);
    apresentacao();
    padrao();
}
char tela2(void){
	clrscr();
    Moldura(1, 1, 120, 30);
    textcolor(12);
    gotoxy(4,3);
    printf("[ESC] FECHAR JOGO");
    textcolor(15);
    gotoxy(48,3);
    printf("BEM VINDO AO KL PENALTY");
    gotoxy(39,4);
    printf("SELECIONE A NACIONALIDADE QUE DESEJA JOGAR");
    gotoxy(31,28);
    printf("[APERTE] O NUMERO DA NACIONALIDADE QUE DESEJA SELECIONAR");
    //molduras de cima 
    //brazil
    gotoxy(20,15);
    printf("[ APERTE  1 ]");
    gotoxy(21,9);
    textcolor(14);
    printf("B R A S I L");
    gotoxy(21,11);
    textcolor(2);
    printf("EQUIPES: 10");
    MolduraColorida(16, 6, 36, 14, 2, 2, 14, 14);
    gotoxy(44,9);
    printf("C O M I N G");
    gotoxy(46,11);
    printf("S O O N");
	MolduraColorida(39, 6, 59, 14, 14, 14, 4, 4);
	gotoxy(67,9);
    printf("C O M I N G");
    gotoxy(69,11);
    printf("S O O N");
	MolduraColorida(62, 6, 82, 14, 2, 11, 12, 6);
	gotoxy(90,9);
    printf("C O M I N G");
    gotoxy(92,11);
    printf("S O O N");
	MolduraColorida(85, 6, 105, 14, 7, 7, 2, 4);
	//molduras de baixo
	gotoxy(21,20);
    printf("C O M I N G");
    gotoxy(23,22);
    printf("S O O N");
	MolduraColorida(16, 17, 36, 25, 15, 4, 15, 14);
	gotoxy(44,20);
    printf("C O M I N G");
    gotoxy(46,22);
    printf("S O O N");
	MolduraColorida(39, 17, 59, 25, 15, 15, 9, 4);
	gotoxy(67,20);
    printf("C O M I N G");
    gotoxy(69,22);
    printf("S O O N");
	MolduraColorida(62, 17, 82, 25, 7, 7, 7, 7);
	gotoxy(90,20);
    printf("C O M I N G");
    gotoxy(92,22);
    printf("S O O N");
	MolduraColorida(85, 17, 105, 25, 7, 7, 7, 7);
	
	
	gotoxy(119,29);
	fflush(stdin);
    return getch();
	
}

char telaBrasil(void){
	clrscr();
	Moldura(1, 1, 120, 30);
	
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
	gotoxy(49, 3);
	textcolor(14);
	printf("KL PENALTY - BRASIL");
	textcolor(15);
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
/* Tabela de cores (textcolor()):

BLACK = 0
BLUE = 1
GREEN = 2
CYAN = 3
RED = 4
MAGENTA = 5
BROWN = 6
LIGHTGRAY = 7
DARKGRAY = 8
LIGHTBLUE = 9
LIGHTGREEN = 10
LIGHTCYAN = 11
LIGHTRED = 12
LIGHTMAGENTA = 13
YELLOW = 14
WHITE = 15*/
void teclaInvalida(void){
	gotoxy(41, 29);
    printf("TECLA INVALIDA, APERTA UMA TECLA VALIDA!");
    Sleep(1000);
    gotoxy(41,29);
    printf("                                        ");
}

/*
char teladoTime(tree *resultado){
	clrscr();
	Moldura(1, 1, 120, 30);
	Moldura(20,6,101,24);
	gotoxy(49, 3);
	textcolor(14);
	printf("KL PENALTY - BRASIL");
	textcolor(15);
	gotoxy(48, 4);
	printf("SELECIONANDO A EQUIPE");
	MolduraColorida(65,26,77,28,10,10,10,10);
	gotoxy(68,27);
	textcolor(10);
	printf("[S] SIM");
	MolduraColorida(81,26,93,28,12,12,12,12);
	gotoxy(83,27);
	textcolor(12);
	printf("[ESC] NAO");
	textcolor(resultado->time.cor1);
	gotoxy(22,7);
	printf("Time %s", resultado->time.nomeEquipe);
	gotoxy(70,7);
    printf("  Presidente: %s [%d]", resultado->time.presida.nome,resultado->time.presida.overall);
    textcolor(resultado->time.cor2);
    gotoxy(32,10);
    printf("[%s] - %s [%d]", resultado->time.jogador1.posicao,resultado->time.jogador1.nome,resultado->time.jogador1.overall);
    gotoxy(60,12);
    printf("[%s] - %s [%d]", resultado->time.jogador2.posicao,resultado->time.jogador2.nome,resultado->time.jogador2.overall);
    gotoxy(32,14);
    printf("[%s] - %s [%d]", resultado->time.jogador3.posicao,resultado->time.jogador3.nome,resultado->time.jogador3.overall);
    gotoxy(60,16);
    printf("[%s] - %s [%d]", resultado->time.jogador4.posicao,resultado->time.jogador4.nome,resultado->time.jogador4.overall);
    gotoxy(32,18);
    printf("[%s] - %s [%d]", resultado->time.jogador5.posicao,resultado->time.jogador5.nome,resultado->time.jogador5.overall);
    gotoxy(60,20);
    printf("[%s] - %s [%d]", resultado->time.goleiro1.posicao,resultado->time.goleiro1.nome,resultado->time.goleiro1.overall);
    textcolor(15);
    gotoxy(28,27);
    printf("Confirma a Escolha do Time  ------>");
    
    gotoxy(119,29);
    return toupper(getch());
}*/

char teladoTime(tree *resultado) {
    clrscr();
    Moldura(1, 1, 120, 30);
    Moldura(20,6,101,24);

    gotoxy(49, 3);
    textcolor(14);
    printf("KL PENALTY - BRASIL");
    textcolor(15);
    gotoxy(48, 4);
    printf("SELECIONANDO A EQUIPE");

    MolduraColorida(65,26,77,28,10,10,10,10);
    gotoxy(68,27);
    textcolor(10);
    printf("[S] SIM");

    MolduraColorida(81,26,93,28,12,12,12,12);
    gotoxy(83,27);
    textcolor(12);
    printf("[ESC] NAO");

    char tecla;
    int toggle = 0;

    do {
        // Cor do nome do time e presidente
        if (toggle == 0)
            textcolor(resultado->time.cor1);
        else
            textcolor(resultado->time.cor2);
        gotoxy(22,7);
        printf("Time %s", resultado->time.nomeEquipe); 
        gotoxy(70,7);
        printf("Presidente: %s [%d]", resultado->time.presida.nome, resultado->time.presida.overall);

        // Cor dos jogadores e goleiro (invertida da do time)
        if (toggle == 0)
            textcolor(resultado->time.cor2);
        else
            textcolor(resultado->time.cor1);
        gotoxy(32,10);
        printf("[%s] - %s [%d]", resultado->time.jogador1.posicao, resultado->time.jogador1.nome, resultado->time.jogador1.overall);
        gotoxy(60,12);
        printf("[%s] - %s [%d]", resultado->time.jogador2.posicao, resultado->time.jogador2.nome, resultado->time.jogador2.overall);
        gotoxy(32,14);
        printf("[%s] - %s [%d]", resultado->time.jogador3.posicao, resultado->time.jogador3.nome, resultado->time.jogador3.overall);
        gotoxy(60,16);
        printf("[%s] - %s [%d]", resultado->time.jogador4.posicao, resultado->time.jogador4.nome, resultado->time.jogador4.overall);
        gotoxy(32,18);
        printf("[%s] - %s [%d]", resultado->time.jogador5.posicao, resultado->time.jogador5.nome, resultado->time.jogador5.overall);
        gotoxy(60,20);
        printf("[%s] - %s [%d]", resultado->time.goleiro1.posicao, resultado->time.goleiro1.nome, resultado->time.goleiro1.overall);

		
		textcolor(10);
        gotoxy(28,27);
        printf("Confirma a Escolha do Time  ------>");
        gotoxy(119,29);

        toggle = !toggle;
        int tempoEspera = 1500; // em milissegundos
		int tempoPassado = 0;
		int passo = 10; // 10ms de cada vez
		
		while (tempoPassado < tempoEspera) {
		    if (kbhit()) break; // Se alguma tecla for pressionada, sai na hora
		    Sleep(passo);
		    tempoPassado += passo;
}
    } while (!kbhit());

    tecla = toupper(getch());
    textcolor(15); // volta cor padrão
    return tecla;
}

#endif
