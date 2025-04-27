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
    if (*raiz == NULL) {  // Se o nó está vazio
        *raiz = criaNo(time);  // Cria o novo nó com os dados do time
    } else {
        if (time.codigo < (*raiz)->time.codigo)  // Se o código é menor que o código do nó atual
            insereABBrecursivo(&(*raiz)->esq, time);  // Insere à esquerda
        else  // Se o código é maior ou igual ao código do nó atual
            insereABBrecursivo(&(*raiz)->dir, time);  // Insere à direita
    }
}

tree* buscaPorCodigo(tree* raiz, int codigo) {
    if (codigo == raiz->time.codigo) {
        return raiz; // Encontrado!
    }

    if (codigo < raiz->time.codigo) {
        return buscaPorCodigo(raiz->esq, codigo); // Busca na subárvore esquerda
    } else {
        return buscaPorCodigo(raiz->dir, codigo); // Busca na subárvore direita
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
		
