#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct Jogador {
    char nome[18];
    int gols;
    int errou;
    float valor;
    int overall;
    char posicao[5];
} jogador;

typedef struct Presidente {
    char nome[18];
    int gols;
    int errou;
    int overall;
} presidente;

typedef struct Goleiro {
    char nome[18];
    int defesa;
    float valor;
    int overall;
    char posicao[4];
} goleiro;

typedef struct Times {
    int codigo;
    char nomeEquipe[20];
    jogador jogador1;
    jogador jogador2;
    jogador jogador3;
    jogador jogador4;
    jogador jogador5;
    goleiro goleiro1;
    presidente presida;
    int cor1;
    int cor2;
    float valorMercado;
} times;

typedef struct tree {
    times time;
    struct tree *esq;
    struct tree *dir;
} tree;

typedef struct inGame {
    times elenco;
    int partidas;
    int pontos;
    int vitoria;
    int derrota;
    int empate;
    int golsFeitos;
    int golsSofridos;
    int saldoDegols;
} ingame;

tree* criaNo(times time) {
    tree* novoNo = (tree*)malloc(sizeof(tree));
    if (novoNo) {
        novoNo->time = time;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    }
    return novoNo;
}
void insereABBrecursivo(tree **raiz, times time) {
    if (*raiz == NULL) {  // Se o n� est� vazio
        *raiz = criaNo(time);  // Cria o novo n� com os dados do time
    } else {
        if (time.codigo < (*raiz)->time.codigo)  // Se o c�digo � menor que o c�digo do n� atual
            insereABBrecursivo(&(*raiz)->esq, time);  // Insere � esquerda
        else  // Se o c�digo � maior ou igual ao c�digo do n� atual
            insereABBrecursivo(&(*raiz)->dir, time);  // Insere � direita
    }
}

tree* buscaPorCodigo(tree* raiz, int codigo) {
    if (codigo == raiz->time.codigo) {
        return raiz; // Encontrado!
    }

    if (codigo < raiz->time.codigo) {
        return buscaPorCodigo(raiz->esq, codigo); // Busca na sub�rvore esquerda
    } else {
        return buscaPorCodigo(raiz->dir, codigo); // Busca na sub�rvore direita
    }
}



/*
				5
				
		3				7
		
	2		4		6		9
	
1						8		10   */
						
void imprimeEmOrdem(tree *raiz) {
    if (raiz != NULL) {
        imprimeEmOrdem(raiz->esq);
        printf("Time %s (Cod: %d)\n", raiz->time.nomeEquipe, raiz->time.codigo);
        printf("  Presidente: %s | Gol: %d | Errou: %d\n", raiz->time.presida.nome, raiz->time.presida.gols,raiz->time.presida.errou);
        printf("  Goleiro: %s | Defesas: %d | Overall: %d\n", raiz->time.goleiro1.nome, raiz->time.goleiro1.defesa, raiz->time.goleiro1.overall);
        printf("  Jogadores:\n");
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", raiz->time.jogador1.nome, raiz->time.jogador1.gols,raiz->time.jogador1.errou, raiz->time.jogador1.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", raiz->time.jogador2.nome, raiz->time.jogador2.gols,raiz->time.jogador2.errou,raiz->time.jogador2.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n", raiz->time.jogador3.nome, raiz->time.jogador3.gols,raiz->time.jogador3.errou, raiz->time.jogador3.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt %d\n", raiz->time.jogador4.nome, raiz->time.jogador4.gols,raiz->time.jogador4.errou, raiz->time.jogador4.overall);
        printf("    %s | Gols: %d | Errou: %d | Rt: %d\n\n", raiz->time.jogador5.nome, raiz->time.jogador5.gols,raiz->time.jogador5.errou,raiz->time.jogador5.overall);
        imprimeEmOrdem(raiz->dir);
    }
}						



#endif
		
