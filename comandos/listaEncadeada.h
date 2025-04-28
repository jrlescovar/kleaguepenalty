#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

void inserirLista(listaDupla **lista, tree *raiz) {
    // Alocação de memória para um novo nó
    listaDupla *novaLista = (listaDupla*)malloc(sizeof(listaDupla));
    if (novaLista == NULL) { //NUNCA ENTRAR AQUI AMEM!
        printf("Erro na alocação de memória.\n");
        return; // Se falhar na alocação, sai da função
    }
    // Inicializa o novo nó
    novaLista->prox = NULL;  // O próximo ainda não existe
    novaLista->ant = NULL;   // O anterior ainda não existe
    // Preenche os dados do time na nova lista
    novaLista->info.elenco.codigo = raiz->time.codigo;
    strcpy(novaLista->info.elenco.nomeEquipe, raiz->time.nomeEquipe);
    // Atribuindo os dados dos jogadores
    novaLista->info.elenco.jogador1 = raiz->time.jogador1;
    novaLista->info.elenco.jogador2 = raiz->time.jogador2;
    novaLista->info.elenco.jogador3 = raiz->time.jogador3;
    novaLista->info.elenco.jogador4 = raiz->time.jogador4;
    novaLista->info.elenco.jogador5 = raiz->time.jogador5;
    // Atribuindo o goleiro
    novaLista->info.elenco.goleiro1 = raiz->time.goleiro1;
    // Atribuindo o presidente
    novaLista->info.elenco.presida = raiz->time.presida;
    // Atribuindo outras informações
    novaLista->info.elenco.cor1 = raiz->time.cor1;
    novaLista->info.elenco.cor2 = raiz->time.cor2;
    novaLista->info.elenco.valorMercado = raiz->time.valorMercado;
    
    novaLista->info.pontos = 0;
    novaLista->info.saldo = 0;
    novaLista->info.vitoria = 0;
    novaLista->info.derrota = 0;
    novaLista->info.empate = 0;
    novaLista->info.golsFeitos = 0;
    novaLista->info.golsSofridos= 0;
    novaLista->info.saldoDegols = 0;
    // Verifica se a lista está vazia
    if (*lista == NULL) {
        *lista = novaLista; // Se estiver vazia, o novo nó é o primeiro
    } else {
        listaDupla *temp = *lista;
        // Percorre até o final da lista
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        // Adiciona o novo nó ao final
        temp->prox = novaLista;
        novaLista->ant = temp;
    }
}

listaDupla* buscarTimeNaLista(listaDupla *lista, int codigo) {
    listaDupla* temp = lista;  // Inicia com o primeiro nó da lista
    
    // Percorre a lista até encontrar o código ou chegar ao final da lista
    while (temp != NULL) {
        if (temp->info.elenco.codigo == codigo) {
            return temp;  // Se encontrar o time, retorna o nó
        }
        temp = temp->prox;  // Avança para o próximo nó
    }
    
    // Se não encontrar o time com o código informado
    return NULL;
} 

void centralizaTextoBrasil(int y, const char* texto, int cor) {
    int comprimentoTexto = strlen(texto);
    int espacos = (34 - 15 - comprimentoTexto) / 2; // Calcula os espaços necessários para centralizar
    
    // O valor de x deve ser entre 15 e 34
    int x = 15 + espacos; // Adiciona a quantidade de espaços à posição mínima (15)
    
    // Move o cursor para a posição calculada
    gotoxy(x, y);
    if(strcmp(texto, "Fluxo FC") == 0)
    	textcolor(4);
    else
    	textcolor(cor);
    // Exibe o texto
    printf("%s", texto);
    textcolor(15);
}

void exibirTabela(listaDupla *lista, int y) {
    listaDupla *temp = lista; // Começa no início da lista
    if (temp == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    while (temp != NULL) {
    	if(y-7 < 10)
    	{
    	
    		if(y-7 > 1 && y-7 <= 7)
    			textcolor(14);
    		else{
    			textcolor(12);
    		}
    		if(y-7 == 1)
    			textcolor(10);
    		gotoxy(13,y);
    		printf("%d", y-7);
    	}else{
    		textcolor(12);
    		gotoxy(12,y);
    		printf("%d", y-7);
    	
    	}
    	textcolor(15);

    	
        centralizaTextoBrasil(y, temp->info.elenco.nomeEquipe,temp->info.elenco.cor1);
        
		if(temp->info.pontos < 10){
			gotoxy(39,y);
			printf("%d",temp->info.pontos);
		}else{
			gotoxy(38,y);
			printf("%d",temp->info.pontos);
		}
		
		gotoxy(43,y);
		printf("%d",temp->info.vitoria);
		gotoxy(47,y);
		printf("%d",temp->info.empate);
		gotoxy(51,y);
		printf("%d",temp->info.derrota);
		if(temp->info.golsFeitos > 9){
			gotoxy(55,y);
			printf("%d",temp->info.golsFeitos);
		}else{
			gotoxy(56,y);
			printf("%d",temp->info.golsFeitos);
		}
		if(temp->info.golsSofridos > 9){
			gotoxy(60,y);
			printf("%d",temp->info.golsSofridos);
		}else{
			gotoxy(61,y);
			printf("%d",temp->info.golsSofridos);
		}
		if(temp->info.saldoDegols > 9){
			gotoxy(65,y);
			printf("%d",temp->info.saldoDegols);
		}else{
			gotoxy(66,y);
			printf("%d",temp->info.saldoDegols);
		}
	
		
        /*
        
        printf("  Presidente: %s | Gols: %d | Errou: %d\n", temp->info.elenco.presida.nome, temp->info.elenco.presida.gols, temp->info.elenco.presida.errou);
        printf("  Goleiro: %s | Defesas: %d | Valor: %.2f\n", temp->info.elenco.goleiro1.nome, temp->info.elenco.goleiro1.defesa, temp->info.elenco.goleiro1.valor);
        
        printf("  Jogadores:\n");
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", temp->info.elenco.jogador1.nome, temp->info.elenco.jogador1.gols, temp->info.elenco.jogador1.errou, temp->info.elenco.jogador1.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", temp->info.elenco.jogador2.nome, temp->info.elenco.jogador2.gols, temp->info.elenco.jogador2.errou, temp->info.elenco.jogador2.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", temp->info.elenco.jogador3.nome, temp->info.elenco.jogador3.gols, temp->info.elenco.jogador3.errou, temp->info.elenco.jogador3.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", temp->info.elenco.jogador4.nome, temp->info.elenco.jogador4.gols, temp->info.elenco.jogador4.errou, temp->info.elenco.jogador4.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n\n", temp->info.elenco.jogador5.nome, temp->info.elenco.jogador5.gols, temp->info.elenco.jogador5.errou, temp->info.elenco.jogador5.overall);
		*/
        temp = temp->prox; // Move para o próximo nó
        y++;
    }
}
#endif
