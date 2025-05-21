SemanaBrasil* gerarPartidasAmericas() {
	 srand(time(NULL));
    char* allTimes1[12] = {
	    "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe", "Los Aliens FC",
	    "Los Chamos FC", "Muchachos FC", "Olimpo United", "Peluche Caligari",
	    "Persas FC", "Raniza FC", "Real Titan FC", "West Santos FC"
	};
	char* allTimes2[12] = {
	    "Clube Cuervos", "Galatic Caribe", "Los Aliens FC", "Los Chamos FC",
	    "Muchachos FC", "Olimpo United", "Peluche Caligari", "Persas FC",
	    "Raniza FC", "Real Titan FC", "West Santos FC", "ATL. Parceros FC"
	};
	
	char* allTimes3[12] = {
	    "Galatic Caribe", "Los Aliens FC", "Los Chamos FC", "Muchachos FC",
	    "Olimpo United", "Peluche Caligari", "Persas FC", "Raniza FC",
	    "Real Titan FC", "West Santos FC", "ATL. Parceros FC", "Clube Cuervos"
	};
	
	char* allTimes4[12] = {
	    "Los Aliens FC", "Los Chamos FC", "Muchachos FC", "Olimpo United",
	    "Peluche Caligari", "Persas FC", "Raniza FC", "Real Titan FC",
	    "West Santos FC", "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe"
	};
	
	char* allTimes5[12] = {
	    "Los Chamos FC", "Muchachos FC", "Olimpo United", "Peluche Caligari",
	    "Persas FC", "Raniza FC", "Real Titan FC", "West Santos FC",
	    "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe", "Los Aliens FC"
	};
	
	char* allTimes6[12] = {
	    "Muchachos FC", "Olimpo United", "Peluche Caligari", "Persas FC",
	    "Raniza FC", "Real Titan FC", "West Santos FC", "ATL. Parceros FC",
	    "Clube Cuervos", "Galatic Caribe", "Los Aliens FC", "Los Chamos FC"
	};
	
	char* allTimes7[12] = {
	    "Olimpo United", "Peluche Caligari", "Persas FC", "Raniza FC",
	    "Real Titan FC", "West Santos FC", "ATL. Parceros FC", "Clube Cuervos",
	    "Galatic Caribe", "Los Aliens FC", "Los Chamos FC", "Muchachos FC"
	};
	
	char* allTimes8[12] = {
	    "Peluche Caligari", "Persas FC", "Raniza FC", "Real Titan FC",
	    "West Santos FC", "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe",
	    "Los Aliens FC", "Los Chamos FC", "Muchachos FC", "Olimpo United"
	};
	
	char* allTimes9[12] = {
	    "Persas FC", "Raniza FC", "Real Titan FC", "West Santos FC",
	    "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe", "Los Aliens FC",
	    "Los Chamos FC", "Muchachos FC", "Olimpo United", "Peluche Caligari"
	};
	
	char* allTimes10[12] = {
	    "Raniza FC", "Real Titan FC", "West Santos FC", "ATL. Parceros FC",
	    "Clube Cuervos", "Galatic Caribe", "Los Aliens FC", "Los Chamos FC",
	    "Muchachos FC", "Olimpo United", "Peluche Caligari", "Persas FC"
	};
	
	char* allTimes11[12] = {
	    "Real Titan FC", "West Santos FC", "ATL. Parceros FC", "Clube Cuervos",
	    "Galatic Caribe", "Los Aliens FC", "Los Chamos FC", "Muchachos FC",
	    "Olimpo United", "Peluche Caligari", "Persas FC", "Raniza FC"
	};
	
	char* allTimes12[12] = {
	    "West Santos FC", "ATL. Parceros FC", "Clube Cuervos", "Galatic Caribe",
	    "Los Aliens FC", "Los Chamos FC", "Muchachos FC", "Olimpo United",
	    "Peluche Caligari", "Persas FC", "Raniza FC", "Real Titan FC"
	};
    // Lista de todas as tabelas
    char** allTimesList[12] = {allTimes1, allTimes2, allTimes3, allTimes4, allTimes5, allTimes6, allTimes7, allTimes8, allTimes9, allTimes10,allTimes11,allTimes12};


    int escolha = rand() % 12;
    char** allTimes = allTimesList[escolha];

    int tabela[12];
    for (int i = 0; i < 12; i++) {
        tabela[i] = i;
    }

    SemanaBrasil* primeiraSemana = NULL;
    SemanaBrasil* semanaAtual = NULL;

    for (int rodada = 0; rodada < 11; rodada++) {
        SemanaBrasil* novaSemana = criarSemana(rodada + 1);

        for (int i = 0; i < 12 / 2; i++) {
            int casa = tabela[i];
            int fora = tabela[12 - 1 - i];

            Confronto* novoConfronto = criarConfronto(allTimes[casa], allTimes[fora],4);
            
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
        int ultimo = tabela[12 - 1];
        for (int i = 12 - 1; i > 1; i--) {
            tabela[i] = tabela[i - 1];
        }
        tabela[1] = ultimo;
    }

    return primeiraSemana;
}

char telaAmericas(void){
	clrscr();
	MolduraColorida(1, 1, 120, 30,15,15,9,9);
	gotoxy(95,2);
	printf("[??]: Overall Equipe");
	
	textcolor(12);
    gotoxy(4,3);
    printf("[ESC] VOLTAR");
	printCentralizado("KL PENALTY - AMERICAS",3,9);
	gotoxy(42, 4);
	printf("SELECIONE A EQUIPE QUE DESEJA JOGAR");
	gotoxy(35, 29);
	printf("[APERTE] O NUMERO DA EQUIPE QUE DESEJA SELECIONAR");

	
	gotoxy(8,11);
    printf("[ APERTE  1 ]");
    gotoxy(7,8);
    textcolor(12);
    printf("ATL. PARCEROS FC");
    gotoxy(20,7);
    printf("[77]");
	MolduraColorida(4, 6, 24, 10, 12, 12, 8, 8);
	
	gotoxy(31,11);
    printf("[ APERTE  2 ]");
    gotoxy(31,8);
    textcolor(8);
    printf("CLUBE CUERVOS");
    gotoxy(43,7);
    printf("[84]");
	MolduraColorida(27, 6, 47, 10, 8, 8, 15, 15);
	
	gotoxy(54,11);
    printf("[ APERTE  3 ]");
    gotoxy(53,8);
    textcolor(1);
    printf("GALATIC CARIBE");
    gotoxy(66,7);
    printf("[82]");
	MolduraColorida(50, 6, 70, 10, 1, 1, 4, 4);
	
	gotoxy(77,11);
    printf("[ APERTE  4 ]");
    gotoxy(77,8);
    textcolor(9);
    printf("LOS ALIENS FC");
    gotoxy(89,7);
    printf("[80]");
	MolduraColorida(73, 6, 93, 10, 9, 9, 5, 5);
	
	gotoxy(101,11);
    printf("[ APERTE 5 ]");
    gotoxy(101,8);
    textcolor(6);
    printf("LOS CHAMOS FC");
    gotoxy(113,7);
    printf("[83]");
	MolduraColorida(96, 6, 117, 10, 6, 6, 15, 15);
	
	gotoxy(8,19);
    printf("[ APERTE  6 ]");
    gotoxy(9,16);
    textcolor(9);
    printf("MUCHACHOS FC");
    gotoxy(20,15);
    printf("[80]");
	MolduraColorida(4, 14, 24, 18, 9, 9, 14, 14);	
	
	gotoxy(31,19);
    printf("[ APERTE  7 ]");
    gotoxy(31,16);
    textcolor(6);
    printf("OLIMPO UNITED");
    gotoxy(43,15);
    printf("[78]");
	MolduraColorida(27, 14, 47, 18, 7, 7, 6, 6);
	
	gotoxy(54,19);
    printf("[ APERTE  8 ]");
    gotoxy(53,16);
    textcolor(14);
    printf("PELUCHE CALIGARI");
    gotoxy(66,15);
    printf("[79]");
	MolduraColorida(50, 14, 70, 18, 14, 14, 4, 4);
	
	gotoxy(77,19);
    printf("[ APERTE  9 ]");
    gotoxy(79,16);
    textcolor(12);
    printf("PERSAS FC");
    gotoxy(89,15);
    printf("[78]");
	MolduraColorida(73, 14, 93, 18, 15, 15,12,12);
	
	gotoxy(101,19);
    printf("[ APERTE 0 ]");
    gotoxy(103,16);
    textcolor(2);
    printf("RANIZA FC");
    gotoxy(113,15);
    printf("[82]");
	MolduraColorida(96, 14, 117, 18, 2, 2, 8,8);
		
	gotoxy(31,27);
    printf("[ APERTE  W ]");
    gotoxy(31,24);
    textcolor(13);
    printf("REAL TITAN FC");
    gotoxy(43,23);
    printf("[78]");
	MolduraColorida(27, 22, 47, 26, 13, 13, 8, 8);
	
	gotoxy(77,27);
    printf("[ APERTE  E ]");
    gotoxy(77,24);
    textcolor(15);
    printf("WEST SANTOS FC");
    gotoxy(89,23);
    printf("[81]");
	MolduraColorida(73, 22, 93, 26, 15, 15,1,1);

	gotoxy(119,29);
	fflush(stdin);
	return toupper(getch());
}

void criarPlayoffAmericas(playoffsConfrontos **qbr, listaDupla *listaEspanha, int play) {
    if (*qbr == NULL) {
        *qbr = malloc(sizeof(playoffsConfrontos));
        if (!(*qbr)) {
            printf("Erro: Falha ao alocar memória para playoffsConfrontos.\n");
            return;  // único return justificado aqui (memória não alocada)
        }
        memset(*qbr, 0, sizeof(playoffsConfrontos));
    }

    // PLAY 1 - criar play-ins e confrontos iniciais
    if (play == 1) {
        listaDupla *time3 = buscarTimeNaListaPOSI(listaEspanha, 3);
        listaDupla *time4 = buscarTimeNaListaPOSI(listaEspanha, 4);
        listaDupla *time5 = buscarTimeNaListaPOSI(listaEspanha, 5);
        listaDupla *time6 = buscarTimeNaListaPOSI(listaEspanha, 6);
        listaDupla *time7 = buscarTimeNaListaPOSI(listaEspanha, 7);
        listaDupla *time8 = buscarTimeNaListaPOSI(listaEspanha, 8);
        listaDupla *time9 = buscarTimeNaListaPOSI(listaEspanha, 9);
        listaDupla *time10 = buscarTimeNaListaPOSI(listaEspanha, 10);

        if (time7 && time10)
            (*qbr)->playin1Confronto = criarConfronto(time7->info.elenco.nomeEquipe, time10->info.elenco.nomeEquipe, 4);
        else
            printf("Erro ao criar playin1Confronto.\n");

        if (time8 && time9)
            (*qbr)->playin2Confronto = criarConfronto(time8->info.elenco.nomeEquipe, time9->info.elenco.nomeEquipe, 4);
        else
            printf("Erro ao criar playin2Confronto.\n");

        if (time4 && time5)
            (*qbr)->q1Confronto = criarConfronto(time4->info.elenco.nomeEquipe, time5->info.elenco.nomeEquipe, 4);
        else
            printf("Erro ao criar q1Confronto.\n");

        if (time3 && time6)
            (*qbr)->q2Confronto = criarConfronto(time3->info.elenco.nomeEquipe, time6->info.elenco.nomeEquipe, 4);
        else
            printf("Erro ao criar q2Confronto.\n");
    }

    // PLAY 2 - criar play-in final
    if (play == 2) {
        if (!(*qbr)->playin1Confronto || !(*qbr)->playin2Confronto) {
            printf("Erro: playins 1 ou 2 não definidos.\n");
        } else {
            listaDupla *vencedorQ1 = NULL;
            listaDupla *vencedorQ2 = NULL;

            for (int i = 1; i <= 10; i++) {
                listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
                if (!t) continue;

                if (!vencedorQ1) {
                    if (((*qbr)->playin1Confronto->placarCasa > (*qbr)->playin1Confronto->placarFora &&
                         (*qbr)->playin1Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->playin1Confronto->placarFora > (*qbr)->playin1Confronto->placarCasa &&
                         (*qbr)->playin1Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ1 = t;
                    }
                }

                if (!vencedorQ2) {
                    if (((*qbr)->playin2Confronto->placarCasa > (*qbr)->playin2Confronto->placarFora &&
                         (*qbr)->playin2Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->playin2Confronto->placarFora > (*qbr)->playin2Confronto->placarCasa &&
                         (*qbr)->playin2Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ2 = t;
                    }
                }

                if (vencedorQ1 && vencedorQ2) break;
            }

            if (vencedorQ1 && vencedorQ2)
                (*qbr)->playin3Confronto = criarConfronto(vencedorQ1->info.elenco.nomeEquipe, vencedorQ2->info.elenco.nomeEquipe, 4);
            else
                printf("Erro: Não foi possível determinar os vencedores dos play-ins.\n");
        }
    }

    // PLAY 3 - criar confronto q3 com time2 vs vencedor do play-in final
    if (play == 3) {
        if (!(*qbr)->playin3Confronto) {
            printf("Erro: playin3Confronto ainda não criado.\n");
        } else {
            listaDupla *vencedorQ1 = NULL;
            listaDupla *time2 = buscarTimeNaListaPOSI(listaEspanha, 2);
            if (!time2) printf("Erro: time2 não encontrado.\n");

            for (int i = 1; i <= 10; i++) {
                listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
                if (!t) continue;

                if (((*qbr)->playin3Confronto->placarCasa > (*qbr)->playin3Confronto->placarFora &&
                     (*qbr)->playin3Confronto->codigo1 == t->info.elenco.codigo) ||
                    ((*qbr)->playin3Confronto->placarFora > (*qbr)->playin3Confronto->placarCasa &&
                     (*qbr)->playin3Confronto->codigo2 == t->info.elenco.codigo)) {
                    vencedorQ1 = t;
                    break;
                }
            }

            if (time2 && vencedorQ1)
                (*qbr)->q3Confronto = criarConfronto(time2->info.elenco.nomeEquipe, vencedorQ1->info.elenco.nomeEquipe, 4);
            else
                printf("Erro ao criar q3Confronto.\n");
        }
    }

    // PLAY 4 - criar semifinais
    if (play == 4) {
        if (!(*qbr)->q1Confronto || !(*qbr)->q2Confronto || !(*qbr)->q3Confronto)
            printf("Erro: uma ou mais quartas não foram criadas.\n");
        else {
            listaDupla *vencedorQ1 = NULL;
            listaDupla *vencedorQ2 = NULL;
            listaDupla *vencedorQ3 = NULL;
            listaDupla *time1 = buscarTimeNaListaPOSI(listaEspanha, 1);
            if (!time1) printf("Erro: time1 não encontrado.\n");

            for (int i = 1; i <= 10; i++) {
                listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
                if (!t) continue;

                if (!vencedorQ1) {
                    if (((*qbr)->q1Confronto->placarCasa > (*qbr)->q1Confronto->placarFora &&
                         (*qbr)->q1Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q1Confronto->placarFora > (*qbr)->q1Confronto->placarCasa &&
                         (*qbr)->q1Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ1 = t;
                    }
                }

                if (!vencedorQ2) {
                    if (((*qbr)->q2Confronto->placarCasa > (*qbr)->q2Confronto->placarFora &&
                         (*qbr)->q2Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q2Confronto->placarFora > (*qbr)->q2Confronto->placarCasa &&
                         (*qbr)->q2Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ2 = t;
                    }
                }

                if (!vencedorQ3) {
                    if (((*qbr)->q3Confronto->placarCasa > (*qbr)->q3Confronto->placarFora &&
                         (*qbr)->q3Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->q3Confronto->placarFora > (*qbr)->q3Confronto->placarCasa &&
                         (*qbr)->q3Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorQ3 = t;
                    }
                }

                if (vencedorQ1 && vencedorQ2 && vencedorQ3) break;
            }

            if (time1 && vencedorQ1)
                (*qbr)->s1Confronto = criarConfronto(time1->info.elenco.nomeEquipe, vencedorQ1->info.elenco.nomeEquipe, 4);
            else
                printf("Erro ao criar s1Confronto.\n");

            if (vencedorQ2 && vencedorQ3)
                (*qbr)->s2Confronto = criarConfronto(vencedorQ2->info.elenco.nomeEquipe, vencedorQ3->info.elenco.nomeEquipe, 4);
            else
                printf("Erro ao criar s2Confronto.\n");
        }
    }

    // PLAY 5 - final
    if (play == 5) {
        listaDupla *vencedorS1 = NULL;
        listaDupla *vencedorS2 = NULL;

        if (!(*qbr)->s1Confronto || !(*qbr)->s2Confronto) {
            printf("Erro: semifinais não definidas.\n");
        } else {
            for (int i = 1; i <= 10; i++) {
                listaDupla *t = buscarTimeNaListaPOSI(listaEspanha, i);
                if (!t) continue;

                if (!vencedorS1) {
                    if (((*qbr)->s1Confronto->placarCasa > (*qbr)->s1Confronto->placarFora &&
                         (*qbr)->s1Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->s1Confronto->placarFora > (*qbr)->s1Confronto->placarCasa &&
                         (*qbr)->s1Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorS1 = t;
                    }
                }

                if (!vencedorS2) {
                    if (((*qbr)->s2Confronto->placarCasa > (*qbr)->s2Confronto->placarFora &&
                         (*qbr)->s2Confronto->codigo1 == t->info.elenco.codigo) ||
                        ((*qbr)->s2Confronto->placarFora > (*qbr)->s2Confronto->placarCasa &&
                         (*qbr)->s2Confronto->codigo2 == t->info.elenco.codigo)) {
                        vencedorS2 = t;
                    }
                }

                if (vencedorS1 && vencedorS2) break;
            }

            if (vencedorS1 && vencedorS2)
                (*qbr)->finalConfronto = criarConfronto(vencedorS1->info.elenco.nomeEquipe, vencedorS2->info.elenco.nomeEquipe, 4);
            else
                printf("Erro ao criar finalConfronto.\n");
        }
    }
}


char ligaAmericas(listaDupla *lista, listaDupla *lista2,int buscar,SemanaBrasil* campeonato,int rodada,int playoffJogos,int rodadaOficial){
	
	
	int jogador1, jogador2;
	clrscr();
	listaDupla *aux = buscarTimeNaLista(lista, buscar);
	int y,x,i;
	
	i = 0;
	while(i < 28) { // de 2 até 29 ? 28 posições
	    textcolor((i % 2 == 0) ? 8 : 9); // Alterna cores
	
	    gotoxy(2, 2 + i);  // Coluna fixa (X=17), linha variável
	    printf((i % 2 == 0) ? "<" : "?");
	
	    gotoxy(119, 2 + i);  // Exemplo: segunda linha vertical à direita
	    printf((i % 2 == 0) ? ">" : "?");
	    
	    i++;
	}
	textcolor(15);
	MolduraColorida(1, 1, 120, 30,15,15,9,9);
	
	Moldura(10, 5, 68, 20);
	
	gotoxy(12,4);
	printf("TABELA GERAL");
	textcolor(9);
	gotoxy(25,4);
	printf("KL - PENALTY AMERICAS");
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
	gotoxy(37,23);
	printf("TOP 10  [W]");

	
	
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
	
	Moldura(30, 25, 48, 28);
	gotoxy(34,26);
	printf("ESTATISTICAS");
	gotoxy(36,27);
	printf("POR TIME [G]");
	
	Moldura(51, 25, 69, 28);/*
	gotoxy(57,25);
	printf("CARTAS");
	gotoxy(66,26);
	printf("[C]");*/
	gotoxy(55,26);
	printf("? EM BREVE ?");
	
	Moldura(72, 25, 90, 28);
	gotoxy(78,26);
	printf("OUTRAS");
	gotoxy(75,27);
	printf("KL - LIGAS");
	gotoxy(87,27);
	printf("[L]");
	
	MolduraColorida(93, 25, 111, 28,14,14,14,14);
	textcolor(14);
	gotoxy(97,26);
	printf("JOGAR AGORA");
	gotoxy(108,27);
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
	
	if(rodadaOficial >= 12){
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





void exibirPlayoffsAmericas(int rodadaOficial, listaDupla *lista, playoffsConfrontos *jogo,int num) {
	
    listaDupla *time1 = buscarTimeNaListaPOSI(lista, 1);    
    listaDupla *time2 = buscarTimeNaListaPOSI(lista, 2);
    MolduraColorida(1, 1, 120, 30, 15, 15, 9, 9);
	
	if(num == 1){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");
	    gotoxy(6, 11); printf("P2");
	
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	    gotoxy(26,8);printf(" ");
	    gotoxy(30,8);printf(" ");
	    gotoxy(26,11);printf(" ");
	    gotoxy(30,11);printf(" ");
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    gotoxy(16,16);printf("VENCEDOR P1 X VENCEDOR P2");
	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    gotoxy(77,8);printf(" ");
	    gotoxy(81,8);printf(" ");
	    gotoxy(77,10);printf(" ");
	    gotoxy(81,10);printf(" ");
	    int nomeLen = strlen(time2->info.elenco.nomeEquipe);
	    if (nomeLen > 14) 
		    gotoxy(58, 12); 
		else if (nomeLen > 12) 
		    gotoxy(60, 12);
		else 
		    gotoxy(64, 12);
		textcolor(time2->info.elenco.cor1);
		printf("%s",time2->info.elenco.nomeEquipe);
	    gotoxy(79,12);textcolor(15);printf("X      VENCEDOR PLAY IN");
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(75,16);textcolor(9);
		printf("SEMI FINAL");textcolor(15);
	    int nomeLen2 = strlen(time1->info.elenco.nomeEquipe);
	    if (nomeLen2 > 14) 
		    gotoxy(57, 18); 
		else if (nomeLen2 > 12) 
		    gotoxy(60, 18);
		else 
		    gotoxy(63, 18);
		
		textcolor(time1->info.elenco.cor1);
		printf("%s", time1->info.elenco.nomeEquipe);
		textcolor(15);
		gotoxy(79, 18); printf("X");            
		gotoxy(83, 18); printf("VENCEDOR Q1");   
		gotoxy(65, 20); printf("VENCEDOR Q2");   
		gotoxy(79, 20); printf("X");           
		gotoxy(83, 20); printf("VENCEDOR Q3");  
		
		textcolor(9);
		gotoxy(86, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		gotoxy(83, 26); printf("VENC. SEMI1  X  VENC.SEMI2"); 	
	}
	if(num == 2){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");gotoxy(6, 11); printf("P2");
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    exibirConfronto4(jogo->playin3Confronto, 9, 16);
	    gotoxy(26,16);printf(" ");
	    gotoxy(30,16);printf(" ");


	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    gotoxy(77,8);printf(" ");
	    gotoxy(81,8);printf(" ");
	    gotoxy(77,10);printf(" ");
	    gotoxy(81,10);printf(" ");
	    int nomeLen = strlen(time2->info.elenco.nomeEquipe);
	    if (nomeLen > 14) 
		    gotoxy(58, 12); 
		else if (nomeLen > 12) 
		    gotoxy(60, 12);
		else 
		    gotoxy(64, 12);
		textcolor(time2->info.elenco.cor1);
		printf("%s",time2->info.elenco.nomeEquipe);
	    gotoxy(79,12);textcolor(15);printf("X      VENCEDOR PLAY IN");
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(75,16);textcolor(9);
		printf("SEMI FINAL");textcolor(15);
	    int nomeLen2 = strlen(time1->info.elenco.nomeEquipe);
	    if (nomeLen2 > 14) 
		    gotoxy(57, 18); 
		else if (nomeLen2 > 12) 
		    gotoxy(60, 18);
		else 
		    gotoxy(63, 18);
		
		textcolor(time1->info.elenco.cor1);
		printf("%s", time1->info.elenco.nomeEquipe);
		textcolor(15);
		gotoxy(79, 18); printf("X");            
		gotoxy(83, 18); printf("VENCEDOR Q1");   
		gotoxy(65, 20); printf("VENCEDOR Q2");   
		gotoxy(79, 20); printf("X");           
		gotoxy(83, 20); printf("VENCEDOR Q3");  
		
		textcolor(9);
		gotoxy(86, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		gotoxy(83, 26); printf("VENC. SEMI1  X  VENC.SEMI2"); 
	}
	if(num == 3){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");gotoxy(6, 11); printf("P2");
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    exibirConfronto4(jogo->playin3Confronto, 9, 16);


	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    exibirConfronto4(jogo->q3Confronto, 60, 12);
	    gotoxy(77,8);printf(" ");
	    gotoxy(81,8);printf(" ");
	    gotoxy(77,10);printf(" ");
	    gotoxy(81,10);printf(" ");
	    gotoxy(77,12);printf(" ");
	    gotoxy(81,12);printf(" ");
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(75,16);textcolor(9);
		printf("SEMI FINAL");textcolor(15);
	    int nomeLen2 = strlen(time1->info.elenco.nomeEquipe);
	    if (nomeLen2 > 14) 
		    gotoxy(57, 18); 
		else if (nomeLen2 > 12) 
		    gotoxy(60, 18);
		else 
		    gotoxy(63, 18);
		
		textcolor(time1->info.elenco.cor1);
		printf("%s", time1->info.elenco.nomeEquipe);
		textcolor(15);
		gotoxy(79, 18); printf("X");            
		gotoxy(83, 18); printf("VENCEDOR Q1");   
		gotoxy(65, 20); printf("VENCEDOR Q2");   
		gotoxy(79, 20); printf("X");           
		gotoxy(83, 20); printf("VENCEDOR Q3");  
		
		textcolor(9);
		gotoxy(86, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		gotoxy(83, 26); printf("VENC. SEMI1  X  VENC.SEMI2"); 
	}
	if(num == 4){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");gotoxy(6, 11); printf("P2");
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    exibirConfronto4(jogo->playin3Confronto, 9, 16);


	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    exibirConfronto4(jogo->q3Confronto, 60, 12);
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(74,16); textcolor(9);
		printf("SEMI FINAL"); textcolor(15);
		
		if (jogo->s1Confronto)
		    exibirConfronto4(jogo->s1Confronto, 59, 18);
		else
		    gotoxy(59, 18), printf("[SEMIFINAL 1 INDISPONÍVEL]");
		
		if (jogo->s2Confronto)
		    exibirConfronto4(jogo->s2Confronto, 59, 20);
		else
		    gotoxy(59, 20), printf("[SEMIFINAL 2 INDISPONÍVEL]");
		
		gotoxy(76,18); printf(" ");
		gotoxy(80,18); printf(" ");
		gotoxy(76,20); printf(" ");
		gotoxy(80,20); printf(" ");
	    
		
		textcolor(9);
		gotoxy(86, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		gotoxy(83, 26); printf("VENC. SEMI1  X  VENC.SEMI2"); 
	}
	if(num == 5){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");gotoxy(6, 11); printf("P2");
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    exibirConfronto4(jogo->playin3Confronto, 9, 16);


	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    exibirConfronto4(jogo->q3Confronto, 60, 12);
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(74,16);textcolor(9);
		printf("SEMI FINAL");textcolor(15);
		exibirConfronto4(jogo->s1Confronto, 59, 18);
	    exibirConfronto4(jogo->s2Confronto, 59, 20);

	    
		textcolor(9);
		gotoxy(87, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		exibirConfronto4(jogo->finalConfronto, 76, 26);
		gotoxy(93,26);printf(" ");
	    gotoxy(97,26);printf(" ");
	}
	if(num == 6){
		gotoxy(25, 5); textcolor(9);printf("PLAY IN");textcolor(15);
	    gotoxy(6, 8); printf("P1");gotoxy(6, 11); printf("P2");
	    exibirConfronto4(jogo->playin1Confronto, 9, 8);
	    exibirConfronto4(jogo->playin2Confronto, 9, 11);
	
		textcolor(9);
	    gotoxy(23, 14); printf("PLAY IN FINAL");textcolor(15);
	    exibirConfronto4(jogo->playin3Confronto, 9, 16);


	
		
		gotoxy(71,5);textcolor(9);
		printf("QUARTAS DE FINAIS");textcolor(15);
		exibirConfronto4(jogo->q1Confronto, 60, 8);
	    exibirConfronto4(jogo->q2Confronto, 60, 10);
	    exibirConfronto4(jogo->q3Confronto, 60, 12);
	    gotoxy(53,8);printf("Q1");
	    gotoxy(53,10);printf("Q2");
	    gotoxy(53,12);printf("Q3");
		
		
		gotoxy(74,16);textcolor(9);
		printf("SEMI FINAL");textcolor(15);
		exibirConfronto4(jogo->s1Confronto, 59, 18);
	    exibirConfronto4(jogo->s2Confronto, 59, 20);

	    
		textcolor(9);
		gotoxy(87, 24); printf("FINAL KL - AMERICAS"); 
		textcolor(15);
		exibirConfronto4(jogo->finalConfronto, 76, 26);

	}

    printCentralizado("PRESSIONE QUALQUER TECLA PARA CONTINUAR", 29, 15);
    gotoxy(119, 29);
    getch();
}
int exibeLigaAmericas(listaDupla *lista, listaDupla *lista2,SemanaBrasil* campeonato,int rodada,int rodadaOficial,int outrasliga,playoffsConfrontos *jogo,int liga){
	clrscr(); char passarPagina1;
	int y,x,i;
	char op;
	if(rodadaOficial >= 10)
		rodada = 11;
	do{	
		MolduraAmericas();
		Moldura(10, 5, 68, 20);	
		gotoxy(12,4);printf("TABELA GERAL");
		textcolor(9);gotoxy(25,4);printf("KL - PENALTY AMERICAS");textcolor(15);
		gotoxy(11,6);printf("POS");
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
		gotoxy(22,6);printf("EQUIPE");gotoxy(37,6);printf("PTS");gotoxy(43,6);printf("V");
		gotoxy(47,6);printf("E");gotoxy(51,6);printf("D");gotoxy(55,6);printf("GF");
		gotoxy(60,6);printf("GS");gotoxy(65,6);printf("GA");
		
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
		printCentralizado("APERTE [ESC] PARA SAIR DO MENU OUTRAS LIGAS",2,12);
	
		Moldura(30, 21, 48, 24);
		gotoxy(34,22);
		printf("ESTATISTICAS");
		gotoxy(36,23);
		printf("POR TIME [G]");
	
		Moldura(51, 21, 69, 24);
		gotoxy(55,22);
		printf("ESTATISTICAS");
		gotoxy(65,23);
		printf("[W]");
		
		Moldura(72, 21, 90, 24);
		gotoxy(76,22);
		printf("PLAY - OFFS");
		gotoxy(87,23);
		printf("[P]");
		
		if(outrasliga == 1){
			printCentralizado("        PROXIMA LIGA --> [D]",26,15);
		}
		if(outrasliga == 3){
			printCentralizado("[A] <-- PROXIMA LIGA        ",26,15);
		}else
			printCentralizado("[A] <-- PROXIMA LIGA --> [D]",26,15);
		
		if(liga == 1){
			if(rodadaOficial >= 10){
				exibirTabela(lista2,8);
			}else{
				exibirTabela(lista, 8);
			}	
		}
		else{
			if(rodadaOficial >= 12){
				exibirTabela(lista2,8);
			}else{
				exibirTabela(lista, 8);
			}
		}
		mudarcor();
		exibirSemana(campeonato,rodada);
		
		gotoxy(119,29);
		fflush(stdin);
		op = toupper(getch());
		limparBufferTeclado();
		switch(op){
			case 'W':
				passarPagina1 = 'A';
    			do{
    				if(passarPagina1 == 'A'){
    					passarPagina1 = exibirEstatisticas(lista,4);
    				}
    				if(passarPagina1 == 'G')
    				{
    					passarPagina1 = exibirTopGoleiros(lista,4);
    				}
    				if(passarPagina1 == 'P'){
    					passarPagina1 = exibirTopPresidentes(lista,4);
    				}
    			}while(passarPagina1 != 27);
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
			case 'D':
				if(outrasliga<3){
					op = 27;
					return outrasliga+1;
				} 
			break;
			case 'A':
				if(outrasliga>1)
				{
					op = 27;
					return outrasliga-1;
				}
			break;
			case 'P':
				if(liga == 1){
					if(rodadaOficial>9){
						clrscr();
						exibirPlayoffsAmericas(rodadaOficial, lista,jogo,(rodadaOficial + 4) - 11);
					}
					if(rodadaOficial < 9){
			       		printCentralizado("LOGO MAIS OS PLAYOFFS ESTARAO EM ANDAMENTO",28,15);
			        	gotoxy(119, 29);
			        	Sleep(1200);
			        	limparBufferTeclado();
			    	}
				}else{
					if(rodadaOficial < 12){
			       		printCentralizado("LOGO MAIS OS PLAYOFFS ESTARAO EM ANDAMENTO",28,15);
			        	gotoxy(119, 29);
			        	Sleep(1200);
			        	limparBufferTeclado();
			    	}else{
			    		clrscr();
			    		exibirPlayoffsAmericas(rodadaOficial, lista,jogo,rodadaOficial - 11);
			    	}
				}   
			break;
			case 'G':
				exibirEstatisticaTime(lista,12,4);
			break;
			case 27:
				Sleep(1);break;
			default:
    			printCentralizado("TECLA INVALIDA! TECLAS DISPONIVEIS [A] [D] [P] [M] [N] [W]",28,15);
    			gotoxy(119, 29);
	        	Sleep(1000);
	        	limparBufferTeclado();
		}
		
		clrscr();
	}while(op != 27);
	return 5;
}
