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
void printCentralizado(const char* texto, int linha, int cor) {
    int larguraTela = 118; // Porque vai do 2 até 119 (119 - 2 + 1 = 118 colunas visíveis)
    int tamanhoTexto = strlen(texto);

    int coluna = 2 + (larguraTela - tamanhoTexto) / 2;

    gotoxy(coluna, linha);
    textcolor(cor);
    printf("%s", texto);
    textcolor(15);
}
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
    textcolor(15);
}

void MolduraColoridaTrave(int CI, int LI, int CF, int LF, int corTopo, int corBase, int corEsquerda, int corDireita) {
    int i;
    // Canto superior esquerdo
    textcolor(corEsquerda);
    gotoxy(CI, LI);
    printf("%c", 201);
    //gotoxy(CI, LF);
    //printf("%c", 200);
    textcolor(corDireita);
    gotoxy(CF, LI);
    printf("%c", 187);
    //gotoxy(CF, LF);
   // printf("%c", 188);
    textcolor(corTopo);
    for (i = CI + 1; i < CF; i++) {
        gotoxy(i, LI);
        printf("%c", 205);
    }
    /*textcolor(corBase);
    for (i = CI + 1; i < CF; i++) {
        gotoxy(i, LF);
        printf("%c", 205);
    }*/
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
    textcolor(15);
} 
void mudarcorautomatico(void){
	
	//int corBORDAS;
	int cor_banner, cor1, cor2, cor3;
    int cores_permitidas[] = {1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14};
    int total_cores = sizeof(cores_permitidas) / sizeof(cores_permitidas[0]);

    srand(time(NULL)); // inicializa aleatoriedade

    do {
        // Cor aleatória para o banner
        cor_banner = cores_permitidas[rand() % total_cores];
        //corBORDAS = cores_permitidas[rand () % total_cores];

        // Três cores diferentes para as mensagens
        /*int idx1, idx2, idx3;
        do {
            idx1 = rand() % total_cores;
            idx2 = rand() % total_cores;
            idx3 = rand() % total_cores;
        } while (idx1 == idx2 || idx1 == idx3 || idx2 == idx3);

        cor1 = cores_permitidas[idx1];
        cor2 = cores_permitidas[idx2];
        cor3 = cores_permitidas[idx3];*/

        // Imprime o banner com cor animada
        MolduraColorida(1, 1, 120, 30,cor_banner,cor_banner,cor_banner,cor_banner);
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
        textcolor(cor_banner);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        gotoxy(31, 22);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        gotoxy(31, 24);
        cprintf("Pressione [QUALQUER TECLA] Para iniciar KL Penalty em C...");

        Sleep(500); // tempo de espera entre animações
    } while (!kbhit());
    textcolor(15);
}
void apresentacao(void){
	
	gotoxy(49, 14);
	printf("KL Penalty | version BETA");
	gotoxy(36, 15);
	printf("Copyright Joao Lescovar | 2025. All Rights Reserved");
	gotoxy(21, 16);
	printf("Jogo Desenvolvido com base nas Estruturas de dados apresentadas na Universidade");
	gotoxy(39, 17);
	printf("Desenvolvido para treinar Estrutura de dados");
	gotoxy(5, 29);
	printf("Entre em contato comigo : jrlescovar@gmail.com");
	gotoxy(92,29);
	printf("Ultima Att em: 20/05/2025");
	mudarcorautomatico();

}




void tela1(void)
{
    system("cls");
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
    // Borda Personalizada Brasil
    int i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 2 : 1); // Escolhe cor direto
	
	    gotoxy(17 + i, 7);  
	    printf((i % 2 == 0) ? "#" : "$");
	
	    gotoxy(17 + i, 13);
	    printf((i % 2 == 0) ? "#" : "$");
	    i++;
	}
    gotoxy(21,9);
    textcolor(14);
    printf("B R A S I L");
    gotoxy(21,11);
    textcolor(2);
    printf("EQUIPES: 10");
    MolduraColorida(16, 6, 36, 14, 2, 2, 14, 14);
    
    i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 4 : 14); // Escolhe cor direto
	
	    gotoxy(40 + i, 7);  
	    printf((i % 2 == 0) ? "@" : "$");
	
	    gotoxy(40 + i, 13);
	    printf((i % 2 == 0) ? "@" : "$");
	    i++;
	}
    gotoxy(43,9);
    printf("E S P A N H A");
    gotoxy(44,11);
    printf("EQUIPES: 12");
	MolduraColorida(39, 6, 59, 14, 14, 14, 4, 4);
	gotoxy(43,15);
	printf("[ APERTE  2 ]");
	
	i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 2 : 12); // Escolhe cor direto
	
	    gotoxy(63 + i, 7);  
	    printf((i % 2 == 0) ? "-" : "^");
	
	    gotoxy(63 + i, 13);
	    printf((i % 2 == 0) ? "-" : "^");
	    i++;
	}
	gotoxy(67,9);
    printf("C O M I N G");
    gotoxy(69,11);
    printf("S O O N");
	MolduraColorida(62, 6, 82, 14, 2, 11, 12, 6);
	
	i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 2 : 4); // Escolhe cor direto
	
	    gotoxy(86 + i, 7);  
	    printf((i % 2 == 0) ? "*" : "=");

	    gotoxy(86 + i, 13);
	    printf((i % 2 == 0) ? "*" : "=");
	    i++;
	}
	gotoxy(90,9);
    printf("I T A L I A");
    gotoxy(90,11);
    printf("EQUIPES: 12");textcolor(15);
    gotoxy(89,15);
	printf("[ APERTE  4 ]");
	MolduraColorida(85, 6, 105, 14, 7, 7, 10, 4);
	//molduras de baixo
	i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 15 : 8); // Escolhe cor direto
	
	    gotoxy(17 + i, 18);  
	    printf((i % 2 == 0) ? "+" : "!");

	    gotoxy(17 + i, 24);
	    printf((i % 2 == 0) ? "+" : "!");
	    i++;
	}
	gotoxy(21,20);
    printf("C O M I N G");
    gotoxy(23,22);
    printf("S O O N");
	MolduraColorida(16, 17, 36, 25, 15, 4, 15, 14);
	i = 0;
	while(i<19) {
	    textcolor((i % 2 == 0) ? 9 : 4); // Escolhe cor direto
	
	    gotoxy(40 + i, 18);  
	    printf((i % 2 == 0) ? "&" : "~");

	    gotoxy(40 + i, 24);
	    printf((i % 2 == 0) ? "&" : "~");
	    i++;
	}
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

char teladoTime(tree *resultado,const char* msg,int cor,int corTopo,int corBase,int corEsquerda, int corDireita,int localidade) {
    clrscr();
    MolduraColorida(1, 1, 120, 30,corTopo,corBase,corEsquerda,corDireita);
    //exibir moldura dos time que tem 3 cores
    if(localidade == 1){
	    if(resultado->time.codigo == 1){
	    	MolduraColorida(20,6,101,24,resultado->time.cor1,2,resultado->time.cor2, resultado->time.cor2);
	    }else if(resultado->time.codigo == 5){
	    		MolduraColorida(20,6,101,24,resultado->time.cor1,resultado->time.cor2,15, 15);
	    }else if(resultado->time.codigo == 7){
	    		MolduraColorida(20,6,101,24,resultado->time.cor2,resultado->time.cor1,resultado->time.cor2,resultado->time.cor1);
	    }else if(resultado->time.codigo == 8){
	    		MolduraColorida(20,6,101,24,resultado->time.cor1,resultado->time.cor1,1, resultado->time.cor2);
	    }else{
	    	MolduraColorida(20,6,101,24,resultado->time.cor1,resultado->time.cor1,resultado->time.cor2, resultado->time.cor2);
	    }
    }
    if(localidade == 2){
		 if (resultado->time.codigo == 7) {
	        MolduraColorida(20,6,101,24, resultado->time.cor1, 14, resultado->time.cor2, resultado->time.cor2);
		}else if (resultado->time.codigo == 11) {
	        MolduraColorida(20,6,101,24, 14, 4, 8,8);
		}else if (resultado->time.codigo == 8) {
	        MolduraColorida(20,6,101,24, 13, 13, 13,13);
		}else if (resultado->time.codigo == 10) {
	        MolduraColorida(20,6,101,24, 14, resultado->time.cor2, resultado->time.cor1,resultado->time.cor1);
		}else
			MolduraColorida(20,6,101,24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
		
	}
	if(localidade == 3){
		MolduraColorida(20,6,101,24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
	}
    
    gotoxy(92,4);
	printf("$: Valor de Mercado");
	gotoxy(95,3);
	printf("[??]: Overall ");
    printCentralizado(msg,3,cor);
    printCentralizado("SELECIONANDO A EQUIPE",4,15);
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
        printf("Time %s  [%d]", resultado->time.nomeEquipe,((resultado->time.jogador1.overall + resultado->time.jogador2.overall) + (resultado->time.jogador3.overall + resultado->time.jogador4.overall) + (resultado->time.jogador5.overall + resultado->time.goleiro1.overall))/6); 
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
		gotoxy(90,23);
		printf("$: %.3f",resultado->time.valorMercado/1000);
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
