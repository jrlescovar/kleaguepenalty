#ifndef LIGABRASIL_H
#define LIGABRASIL_H
#include "listaEncadeada.h"

#define NUM_TIMES 10
#define NUM_RODADAS 9 


// Estruturas

typedef struct Confronto {
    char timeCasa[20];
    int cor1;
    char placarCasa[3]; // 2 dígitos + \0
    char timeFora[20];
    int cor2;
    char placarFora[3];
    struct Confronto* prox;
    struct Confronto* ant;
} Confronto;

typedef struct SemanaBrasil {
    int numeroRodada;
    Confronto* primeiroConfronto;
    struct SemanaBrasil* prox;
    struct SemanaBrasil* ant;
} SemanaBrasil;

// Funções de criação

Confronto* criarConfronto(char* casa, char* fora) {
    Confronto* novo = (Confronto*)malloc(sizeof(Confronto));
    if(strcmp(casa,"Capim FC") == 0 )
    	novo->cor1 = 11;
    if(strcmp(casa,"Dendele FC") == 0 )
    	novo->cor1 = 1;
    if(strcmp(casa,"DesimpedidosGoti") == 0 )
    	novo->cor1 = 2;
    if(strcmp(casa,"FC Real Elite") == 0 )
    	novo->cor1 = 13;
    if(strcmp(casa,"Fluxo FC") == 0 )
    	novo->cor1 = 4;
    if(strcmp(casa,"Funkbol Clube") == 0 )
    	novo->cor1 = 5;
    if(strcmp(casa,"Furia FC") == 0 )
    	novo->cor1 = 7;
    if(strcmp(casa,"G3X FC") == 0 )
    	novo->cor1 = 15;
    if(strcmp(casa,"LOUD SC") == 0 )
    	novo->cor1 = 2;
    if(strcmp(casa,"Nyvelados FC") == 0 )
    	novo->cor1 = 8;
    	
    if(strcmp(fora,"Capim FC") == 0 )
    	novo->cor2 = 11;
    if(strcmp(fora,"Dendele FC") == 0 )
    	novo->cor2 = 1;
    if(strcmp(fora,"DesimpedidosGoti") == 0 )
    	novo->cor2 = 2;
    if(strcmp(fora,"FC Real Elite") == 0 )
    	novo->cor2 = 13;
    if(strcmp(fora,"Fluxo FC") == 0 )
    	novo->cor2 = 4;
    if(strcmp(fora,"Funkbol Clube") == 0 )
    	novo->cor2 = 5;
    if(strcmp(fora,"Furia FC") == 0 )
    	novo->cor2 = 7;
    if(strcmp(fora,"G3X FC") == 0 )
    	novo->cor2 = 15;
    if(strcmp(fora,"LOUD SC") == 0 )
    	novo->cor2 = 2;
    if(strcmp(fora,"Nyvelados FC") == 0 )
    	novo->cor2 = 8;
    
    strcpy(novo->timeCasa, casa);
    strcpy(novo->placarCasa, "  "); // Espaço em branco nos dois caracteres
    strcpy(novo->timeFora, fora);
    strcpy(novo->placarFora, "  ");
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

SemanaBrasil* criarSemana(int numero) {
    SemanaBrasil* nova = (SemanaBrasil*)malloc(sizeof(SemanaBrasil));
    nova->numeroRodada = numero;
    nova->primeiroConfronto = NULL;
    nova->prox = NULL;
    nova->ant = NULL;
    return nova;
}

// Função para gerar todas as partidas (9 semanas)

SemanaBrasil* gerarPartidas() {
	 srand(time(NULL));
    char* allTimes1[NUM_TIMES] = {
        "Capim FC", "Dendele FC", "DesimpedidosGoti", "FC Real Elite", "Fluxo FC",
        "Funkbol Clube", "Furia FC", "G3X FC", "LOUD SC", "Nyvelados FC"
    };
    char* allTimes2[NUM_TIMES] = {
        "Dendele FC", "Nyvelados FC", "Fluxo FC", "LOUD SC", "Funkbol Clube",
        "FC Real Elite", "Furia FC", "DesimpedidosGoti", "Capim FC", "G3X FC"
    };
    char* allTimes3[NUM_TIMES] = {
        "Funkbol Clube", "FC Real Elite", "Furia FC", "Nyvelados FC", "LOUD SC",
        "Capim FC", "Dendele FC", "DesimpedidosGoti", "G3X FC", "Fluxo FC"
    };
    char* allTimes4[NUM_TIMES] = {
        "Nyvelados FC", "Funkbol Clube", "Dendele FC", "G3X FC", "FC Real Elite",
        "Fluxo FC", "LOUD SC", "Capim FC", "DesimpedidosGoti", "Furia FC"
    };
    char* allTimes5[NUM_TIMES] = {
        "Fluxo FC", "Capim FC", "Furia FC", "DesimpedidosGoti", "Funkbol Clube",
        "G3X FC", "Nyvelados FC", "FC Real Elite", "Dendele FC", "LOUD SC"
    };
    char* allTimes6[NUM_TIMES] = {
        "G3X FC", "LOUD SC", "Nyvelados FC", "Capim FC", "Dendele FC",
        "FC Real Elite", "Fluxo FC", "Furia FC", "DesimpedidosGoti", "Funkbol Clube"
    };
    char* allTimes7[NUM_TIMES] = {
        "FC Real Elite", "DesimpedidosGoti", "LOUD SC", "Furia FC", "Nyvelados FC",
        "Capim FC", "Fluxo FC", "Funkbol Clube", "Dendele FC", "G3X FC"
    };
    char* allTimes8[NUM_TIMES] = {
        "DesimpedidosGoti", "Fluxo FC", "G3X FC", "Nyvelados FC", "Furia FC",
        "LOUD SC", "Capim FC", "Funkbol Clube", "FC Real Elite", "Dendele FC"
    };
    char* allTimes9[NUM_TIMES] = {
        "LOUD SC", "Capim FC", "FC Real Elite", "DesimpedidosGoti", "Fluxo FC",
        "Nyvelados FC", "G3X FC", "Furia FC", "Funkbol Clube", "Dendele FC"
    };
    char* allTimes10[NUM_TIMES] = {
    "Furia FC", "DesimpedidosGoti", "Fluxo FC", "LOUD SC", "G3X FC",
    "Capim FC", "FC Real Elite", "Dendele FC", "Nyvelados FC", "Funkbol Clube"
	};

    // Lista de todas as tabelas
    char** allTimesList[10] = {allTimes1, allTimes2, allTimes3, allTimes4, allTimes5, allTimes6, allTimes7, allTimes8, allTimes9, allTimes10};


    int escolha = rand() % 10;
    char** allTimes = allTimesList[escolha];

    int tabela[NUM_TIMES];
    for (int i = 0; i < NUM_TIMES; i++) {
        tabela[i] = i;
    }

    SemanaBrasil* primeiraSemana = NULL;
    SemanaBrasil* semanaAtual = NULL;

    for (int rodada = 0; rodada < NUM_RODADAS; rodada++) {
        SemanaBrasil* novaSemana = criarSemana(rodada + 1);

        for (int i = 0; i < NUM_TIMES / 2; i++) {
            int casa = tabela[i];
            int fora = tabela[NUM_TIMES - 1 - i];

            Confronto* novoConfronto = criarConfronto(allTimes[casa], allTimes[fora]);
            
            if (novaSemana->primeiroConfronto == NULL) {
                novaSemana->primeiroConfronto = novoConfronto;
            } else {
                Confronto* atual = novaSemana->primeiroConfronto;
                while (atual->prox != NULL) {
                    atual = atual->prox;
                }
                atual->prox = novoConfronto;
                novoConfronto->ant = atual;
            }
        }

        if (primeiraSemana == NULL) {
            primeiraSemana = novaSemana;
        } else {
            semanaAtual->prox = novaSemana;
            novaSemana->ant = semanaAtual;
        }
        semanaAtual = novaSemana;

        // Rotacionar os times
        int ultimo = tabela[NUM_TIMES - 1];
        for (int i = NUM_TIMES - 1; i > 1; i--) {
            tabela[i] = tabela[i - 1];
        }
        tabela[1] = ultimo;
    }

    return primeiraSemana;
}



// Função para buscar uma semana específica
SemanaBrasil* buscarSemana(SemanaBrasil* inicio, int numeroRodada) {
    SemanaBrasil* atual = inicio;
    while (atual != NULL) {
        if (atual->numeroRodada == numeroRodada) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL; // Não encontrou
}
void exibirSemana(SemanaBrasil* inicio, int numeroRodada) {
    SemanaBrasil* semana = buscarSemana(inicio, numeroRodada);

    if (semana == NULL) {
        printf("Rodada %d não encontrada.\n", numeroRodada);
        return;
    }

    gotoxy(87, 6); // Centralizado para título
    printf("RODADA %d", semana->numeroRodada);

    Confronto* confronto = semana->primeiroConfronto;
    
    int y = 8;
    while (confronto != NULL) {
		
		textcolor(confronto->cor1);
		if(strlen(confronto->timeCasa) > 13){
			gotoxy(71, y);
        	printf("%s",confronto->timeCasa);
		}else if(strlen(confronto->timeCasa) <= 14){
			gotoxy(74,y);
			printf("%s",confronto->timeCasa);
		}
		gotoxy(88,y);
		textcolor(15);
        printf("%s",confronto->placarCasa);
        gotoxy(90,y);
        printf("X");
        gotoxy(92,y);
        printf("%s",confronto->placarFora);
        textcolor(confronto->cor2);
        if(strlen(confronto->timeFora) > 14){
			gotoxy(94, y);
        	printf("%s",confronto->timeFora);
		}else{
			gotoxy(95,y);
			printf("%s",confronto->timeFora);
		}
        y += 2;
        confronto = confronto->prox;
    }
    textcolor(15);
}


void registrarPlacar(Confronto* confronto, int golsCasa, int golsFora) {
    snprintf(confronto->placarCasa, sizeof(confronto->placarCasa), "%2d", golsCasa);
    snprintf(confronto->placarFora, sizeof(confronto->placarFora), "%2d", golsFora);
}

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
    gotoxy(76,22);
    printf("#: Lukinhas [85]");
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

char ligaBrasil(listaDupla *lista, int buscar,SemanaBrasil* campeonato,int rodada){
	int jogador1, jogador2;
	clrscr();
	listaDupla *aux = buscarTimeNaLista(lista, buscar);
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
	
	if(rodada == 1)
	{	
		gotoxy(84,4);
		printf("PROXIMOS JOGOS --> [M]");
		
	}else if(rodada == 9){
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS");
	}else{
		gotoxy(76,4);
		printf("[N] <-- PROXIMOS JOGOS --> [M]");
	}
	
	
	Moldura(10, 20, 27, 23);
	gotoxy(16,21);
	printf("ELENCO");
	gotoxy(24,22);
	printf("[E]");

	Moldura(30, 20, 48, 23);/*
	gotoxy(34,21);
	printf("ESTATISTICAS");
	gotoxy(45,22);
	printf("[W]");*/
	gotoxy(34,21);
	printf("? EM BREVE ?");
	
	
	Moldura(51, 20, 69, 23);
	gotoxy(55,21);
	printf("? EM BREVE ?");
	
	Moldura(72, 20, 90, 23);/*
	gotoxy(76,21);
	printf("PLAY - OFFS");
	gotoxy(87,22);
	printf("[P]");*/
	gotoxy(76,21);
	printf("? EM BREVE ?");
	
	Moldura(93, 20, 111, 23);
	gotoxy(96,21);
	printf("? EM BREVE ?");
	
	
	
	Moldura(10, 24, 27, 27);/*
	gotoxy(16,25);
	printf("TROCAS");
	gotoxy(24,26);
	printf("[T]");*/
	gotoxy(14,25);
	printf("? EM BREVE ?");
	
	Moldura(30, 24, 48, 27);/*
	gotoxy(34,25);
	printf("ESTATISTICAS");
	gotoxy(36,26);
	printf("POR TIME [G]");*/
	gotoxy(34,25);
	printf("? EM BREVE ?");
	
	Moldura(51, 24, 69, 27);/*
	gotoxy(57,25);
	printf("CARTAS");
	gotoxy(66,26);
	printf("[C]");*/
	gotoxy(55,25);
	printf("? EM BREVE ?");
	
	Moldura(72, 24, 90, 27);/*
	gotoxy(78,25);
	printf("OUTRAS");
	gotoxy(75,26);
	printf("KL - LIGAS");
	gotoxy(87,26);
	printf("[L]");*/
	gotoxy(76,25);
	printf("? EM BREVE ?");
	
	MolduraColorida(93, 24, 111, 27,14,14,14,14);
	textcolor(14);
	gotoxy(97,25);
	printf("JOGAR AGORA");
	gotoxy(108,26);
	printf("[J]");
	textcolor(15);
	
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
	
	exibirTabela(lista, 8);
	exibirSemana(campeonato,rodada);
	
	gotoxy(119,29);
	return toupper(getch());
}

void gerenciarElenco(listaDupla **lista, tree *resultado) {
    clrscr();
    textcolor(12);
    gotoxy(7,3);
    printf("[ESC] VOLTAR");
    textcolor(15);
    int i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 14 : 2); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "#" : "$");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? "#" : "$");
	    
	    i++;
	}
	textcolor(15);
    MolduraColorida(1, 1, 120, 30, 2, 2, 14, 14);

    if (resultado->time.codigo == 1) {
        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, 2, resultado->time.cor2, resultado->time.cor2);
    } else if (resultado->time.codigo == 5) {
        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor2, 15, 15);
    } else if (resultado->time.codigo == 7) {
        MolduraColorida(6, 6, 82, 24, resultado->time.cor2, resultado->time.cor1, resultado->time.cor2, resultado->time.cor1);
    } else if (resultado->time.codigo == 8) {
        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, 1, resultado->time.cor2);
    } else {
        MolduraColorida(6, 6, 82, 24, resultado->time.cor1, resultado->time.cor1, resultado->time.cor2, resultado->time.cor2);
    }

    gotoxy(42, 5);
    printf("$: Valor de Mercado");
    gotoxy(65, 5);
    printf("[??]: Overall ");

    char tecla;
    int toggle = 0;
    listaDupla *temp = buscarTimeNaLista(*lista, resultado->time.codigo); // Usa temp, não muda *lista!
    listaDupla *aux;
	
	do{
		
		do{
	        if (toggle == 0)
	            textcolor(resultado->time.cor1);
	        else
	            textcolor(resultado->time.cor2);
	
	        gotoxy(9, 7);
	        printf("Time %s  [%d]", resultado->time.nomeEquipe,((resultado->time.jogador1.overall + resultado->time.jogador2.overall) + (resultado->time.jogador3.overall + resultado->time.jogador4.overall) + (resultado->time.jogador5.overall + resultado->time.goleiro1.overall))/6); 
	
	        gotoxy(51, 7);
	        printf("Presidente: %s [%d]", resultado->time.presida.nome, resultado->time.presida.overall);
	
	        // Cor dos jogadores e goleiro (invertida da do time)
	        if (toggle == 0)
	            textcolor(resultado->time.cor2);
	        else
	            textcolor(resultado->time.cor1);
	
	        gotoxy(13, 10);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador1.posicao, resultado->time.jogador1.nome, resultado->time.jogador1.overall, resultado->time.jogador1.valor/1000);
	
	        gotoxy(41, 12);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador2.posicao, resultado->time.jogador2.nome, resultado->time.jogador2.overall, resultado->time.jogador2.valor/1000);
	
	        gotoxy(13, 14);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador3.posicao, resultado->time.jogador3.nome, resultado->time.jogador3.overall, resultado->time.jogador3.valor/1000);
	
	        gotoxy(41, 16);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador4.posicao, resultado->time.jogador4.nome, resultado->time.jogador4.overall, resultado->time.jogador4.valor/1000);
	
	        gotoxy(13, 18);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.jogador5.posicao, resultado->time.jogador5.nome, resultado->time.jogador5.overall, resultado->time.jogador5.valor/1000);
	
	        gotoxy(41, 20);
	        printf("[%s] - %s [%d][$: %.3f]", resultado->time.goleiro1.posicao, resultado->time.goleiro1.nome, resultado->time.goleiro1.overall, resultado->time.goleiro1.valor/1000);
	
	        gotoxy(71, 23);
	        printf("$: %.3f", temp->info.elenco.valorMercado / 1000.0);
			
			gotoxy(93,9);
			printf("ORDEM PENALIDADES");
			gotoxy(94,12);
			printf("                  ");
			gotoxy(94,12);
			printf("[1] %s",temp->info.elenco.jogador1.nome);
			gotoxy(94,14);
			printf("                  ");
			gotoxy(94,14);
			printf("[2] %s",temp->info.elenco.jogador2.nome);
			gotoxy(94,16);
			printf("                  ");
			gotoxy(94,16);
			printf("[3] %s",temp->info.elenco.jogador3.nome);
			gotoxy(94,18);
			printf("                  ");
			gotoxy(94,18);
			printf("[4] %s",temp->info.elenco.jogador4.nome);
			gotoxy(94,20);
			printf("                  ");
			gotoxy(94,20);
			printf("[5] %s",temp->info.elenco.jogador5.nome);
			
			printCentralizado("ALTERAR ORDEM DAS PENALIDADE APERTE [Y]",29,15);
			
	        gotoxy(119, 29);
	        toggle = !toggle;
	
	        int tempoEspera = 1500; // em milissegundos
	        int tempoPassado = 0;
	        int passo = 10; // 10ms de cada vez
	
	        while (tempoPassado < tempoEspera) {
	            if (kbhit()) break; // Se alguma tecla for pressionada, sai na hora
	            Sleep(passo);
	            tempoPassado += passo;
	        }
	        
	    
	    } while(!kbhit());
	
	    // Aqui a parte de ler a tecla corretamente
	    tecla = getch();
	    tecla = toupper(tecla);
	
	    textcolor(15); // volta cor padrão
	    
	    if(tecla == 'Y')
	    {
	    	
			printCentralizado("                                                                                            ",29,15);
			printCentralizado("DIGITE OS NUMEROS DOS JOGADORES QUE DESEJAM TROCAR NA ORDEM DA PENALIDADE",26,15);
			printCentralizado("JOGADOR 1:     TROCAR COM JOGADOR 2:    ",27,15);
	    	gotoxy(53,27);
	    	int pronto = 0; 
			char jogador1, jogador2;
	    	do{
	    		gotoxy(53,27);
	    		jogador1 = getche();
	    		if( jogador1 >=49 && jogador1 <= 53)
	    			pronto++;
	    		else{
	    			gotoxy(53,27);
	    			printf("   ");
	    			printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [4] [5]",29,15);
	    			gotoxy(119,29);
	    			Sleep(1000);
	    			gotoxy(30,29);
	    			printf("                                                    ");
	    		}
	    		
	    	}while(pronto != 1);
	    	gotoxy(53,27);
	    	printf("%c",jogador1);
	    	
	    	do{
	    		pronto = 0;
	    		gotoxy(79,27);
	    		jogador2 = getche();
	    		if( jogador2 >=49 && jogador2 <= 53 && jogador2 != jogador1)
	    			pronto++;
	    		else{
	    			gotoxy(79,27);
	    			printf("   ");
	    			if(jogador1 == 49)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [2] [3] [4] [5]",29,15);
	    			if(jogador1 == 50)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [3] [4] [5]",29,15);
	    			if(jogador1 == 51)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [4] [5]",29,15);
	    			if(jogador1 == 52)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [5]",29,15);
	    			if(jogador1 == 53)
	    				printCentralizado("NUMERO INVALIDO! DIGITE [1] [2] [3] [4]",29,15);
	    			gotoxy(119,29);
	    			Sleep(1000);
	    			gotoxy(30,29);
	    			printf("                                                    ");
	    		}
	    		
	    	}while(pronto != 1);
	    	
	    	gotoxy(79,27);
	    	printf("%c",jogador2);
	    	
	    	if(pronto == 1){
	    		int jg1 = jogador1 - '0';
				int jg2 = jogador2 - '0';
				jogador *jogadores[5] = {
				    &temp->info.elenco.jogador1,
				    &temp->info.elenco.jogador2,
				    &temp->info.elenco.jogador3,
				    &temp->info.elenco.jogador4,
				    &temp->info.elenco.jogador5
				};
				jogador aux = *jogadores[jg1 - 1];
				*jogadores[jg1 - 1] = *jogadores[jg2 - 1];
				*jogadores[jg2 - 1] = aux;		
	    	}
	    
	    }
	    gotoxy(20,26);
		printf("                                                                                  ");
		gotoxy(20,27);
		printf("                                                                 ");
		gotoxy(119,29);
		
	}while(tecla != 27);
    
}


#endif
