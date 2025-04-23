#ifndef DADOS_AUTOMATICOS_H
#define DADOS_AUTOMATICOS_H

#include "times.h"
void dadosAutomaticos(tree **raiz) {
    // G3X
    jogador j1_1 = {"Kelvin 'K9'", 0, 0, 100000, 95};
    jogador j1_2 = {"Andreas Vaz", 0, 0, 75000, 91};
    jogador j1_3 = {"Rufino", 0, 0, 50000, 82};
    jogador j1_4 = {"Kenu", 0, 0, 32000, 80};
    jogador j1_5 = {"Wembley", 0, 0, 40000, 84};
    goleiro g1 = {"Igor Rezende", 0, 30000, 81};
    presidente p1 = {"Gaules", 0, 0, 71};
    times t1 = {5, "G3X FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1};
    insereABBrecursivo(raiz, t1);

    // Furia
    jogador j2_1 = {"Leleti", 0, 0, 80000, 92};
    jogador j2_2 = {"Jefinho", 0, 0, 55000, 85};
    jogador j2_3 = {"Lipão", 0, 0, 60000, 87};
    jogador j2_4 = {"Dedo", 0, 0, 44000, 84};
    jogador j2_5 = {"Donato", 0, 0, 14000, 74};
    goleiro g2 = {"Victor Hugo", 0, 30000, 83};
    presidente p2 = {"Cris Guedes", 0, 0, 74};
    times t2 = {3, "Furia FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2};
    insereABBrecursivo(raiz, t2);

    // Capim
    jogador j3_1 = {"Negao", 0, 0, 40000, 84};
    jogador j3_2 = {"Henry Japa", 0, 0, 25000, 81};
    jogador j3_3 = {"GB Medeiros", 0, 0, 20000, 78};
    jogador j3_4 = {"?????", 0, 0, 0, 0};
    jogador j3_5 = {"?????", 0, 0, 0, 0};
    goleiro g3 = {"Barata", 0, 75000, 90};
    presidente p3 = {"Jon Vlogs", 0, 0, 69};
    times t3 = {7, "Capim FC", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3};
    insereABBrecursivo(raiz, t3);

    // Real Elite
    jogador j4_1 = {"Davi Ilario", 0, 0, 80000, 88};
    jogador j4_2 = {"Well", 0, 0, 35000, 83};
    jogador j4_3 = {"?????", 0, 0, 0, 0};
    jogador j4_4 = {"Matheus Bueno", 0, 0, 16000, 75};
    jogador j4_5 = {"Marlon Ribas", 0, 0, 1800, 75};
    goleiro g4 = {"Gustavo Rocha", 0, 14000, 76};
    presidente p4 = {"Allan Stag", 0, 0, 82};
    times t4 = {2, "FC Real Elite", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4};
    insereABBrecursivo(raiz, t4);

    // LOUD
    jogador j5_1 = {"Drope", 0, 0, 40000, 84};
    jogador j5_2 = {"?????", 0, 0, 0, 0};
    jogador j5_3 = {"Lukinhas", 0, 0, 42000, 82};
    jogador j5_4 = {"Luca Japa", 0, 0, 28000, 79};
    jogador j5_5 = {"Igor Rock", 0, 0, 1800, 77};
    goleiro g5 = {"Esau", 0, 39000, 80};
    presidente p5 = {"Loud Coringa", 0, 0, 77};
    times t5 = {4, "LOUD SC", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5};
    insereABBrecursivo(raiz, t5);

    // Dendele
    jogador j6_1 = {"Canhoto", 0, 0, 51000, 85};
    jogador j6_2 = {"Lyncoln", 0, 0, 40000, 84};
    jogador j6_3 = {"Lucas Hector", 0, 0, 49000, 86};
    jogador j6_4 = {"Assump", 0, 0, 15000, 76};
    jogador j6_5 = {"G. Carvalho", 0, 0, 8800, 74};
    goleiro g6 = {"Thales", 0, 19000, 75};
    presidente p6 = {"Luquet4", 0, 0, 65};
    times t6 = {6, "Dendele FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6};
    insereABBrecursivo(raiz, t6);

    // Funk
    jogador j7_1 = {"Douglinhas", 0, 0, 68000, 87};
    jogador j7_2 = {"Ibrahim", 0, 0, 30000, 84};
    jogador j7_3 = {"Davisson", 0, 0, 25000, 79};
    jogador j7_4 = {"MlkJhoow", 0, 0, 42000, 83};
    jogador j7_5 = {"Vitinho Ruas", 0, 0, 21000, 79};
    goleiro g7 = {"Gui Barros", 0, 19000, 76};
    presidente p7 = {"Mc Hariel", 0, 0, 68};
    times t7 = {9, "Funkbol Clube", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7};
    insereABBrecursivo(raiz, t7);

    // Fluxo
    jogador j8_1 = {"Boolt", 0, 0, 38000, 84};
    jogador j8_2 = {"Helber Jr", 0, 0, 30000, 81};
    jogador j8_3 = {"Chaveirinho", 0, 0, 25000, 80};
    jogador j8_4 = {"Victor Bueno", 0, 0, 21000, 79};
    jogador j8_5 = {"Melequinha", 0, 0, 17000, 75};
    goleiro g8 = {"Julio Carvalho", 0, 19000, 76};
    presidente p8 = {"Nobru", 0, 0, 76};
    times t8 = {8, "Fluxo FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8};
    insereABBrecursivo(raiz, t8);

    // Goti
    jogador j9_1 = {"Batman", 0, 0, 28000, 80};
    jogador j9_2 = {"Marcelin Jr", 0, 0, 33210, 83};
    jogador j9_3 = {"Thor", 0, 0, 25000, 79};
    jogador j9_4 = {"Bolt", 0, 0, 19000, 79};
    jogador j9_5 = {"Caio Miranda", 0, 0, 31000, 80};
    goleiro g9 = {"Joao Pedro", 0, 59000, 88};
    presidente p9 = {"Yuri 22", 0, 0, 65};
    times t9 = {10, "Desimpedidos Goti", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9};
    insereABBrecursivo(raiz, t9);

    // Nyvelado
    jogador j10_1 = {"Leo Gol", 0, 0, 58000, 88};
    jogador j10_2 = {"Breno Arantes", 0, 0, 18110, 79};
    jogador j10_3 = {"Klynsmann", 0, 0, 25000, 76};
    jogador j10_4 = {"Bruninho", 0, 0, 23200, 84};
    jogador j10_5 = {"Willin Jesus", 0, 0, 21000, 77};
    goleiro g10 = {"Ivo Alves", 0, 29000, 85};
    presidente p10 = {"Nyvi Estephan", 0, 0, 27};
    times t10 = {1, "Nyvelados FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10};
    insereABBrecursivo(raiz, t10);
}
#endif
