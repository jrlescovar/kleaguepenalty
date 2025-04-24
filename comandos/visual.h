#ifndef VISUAL_H
#define VISUAL_H
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
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

void tela1(void)
{
    system("cls");
    Moldura(1, 1, 120, 30);
    //logodoJogo();
    apresentacao();
	textcolor(7);//cor padrão
	textbackground(0);//fundo padrão
   
}

#endif
