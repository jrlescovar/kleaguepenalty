#ifndef DADOS_AUTOMATICOS_H
#define DADOS_AUTOMATICOS_H

#include "times.h"
void dadosAutomaticos(tree **raiz) {
	float valorMercado;
    // Fluxo
    jogador j8_1 = {"Boolt", 0, 0, 39000, 85,"ATA"};
    jogador j8_2 = {"Helber Jr", 0, 0, 30000, 83,"ATA"};
    jogador j8_3 = {"Victor Bueno", 0, 0, 21000, 80,"ATA"};
    jogador j8_4 = {"Chaveirinho", 0, 0, 28000, 80,"MEI"};
    jogador j8_5 = {"Melequinha", 0, 0, 28000, 81,"DEF"};
    goleiro g8 = {"Julio Carvalho", 0, 19000, 78,"GOL"};
    presidente p8 = {"Nobru", 0, 0, 76};
    valorMercado = j8_1.valor + j8_2.valor + j8_3.valor + j8_4.valor + j8_5.valor + g8.valor;
    times t8 = {5, "Fluxo FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8,8,4,valorMercado};
    insereABBrecursivo(raiz, t8);
    
    // Goti
    jogador j9_1 = {"Marcelin Jr", 0, 0, 33200, 83,"ATA"};
    jogador j9_2 = {"Luisinho Alves", 0, 0, 31000, 82,"ATA"};
    jogador j9_3 = {"Batman", 0, 0, 28000, 82,"MEI"};
    jogador j9_4 = {"Victor Bolt", 0, 0, 19000, 79,"MEI"};
    jogador j9_5 = {"Bernardinello", 0, 0, 22000, 77,"DEF"};
    goleiro g9 = {"Joao Pedro", 0, 59000, 90,"GOL"};
    presidente p9 = {"Yuri 22", 0, 0, 65};
    valorMercado = j9_1.valor + j9_2.valor + j9_3.valor + j9_4.valor + j9_5.valor + g9.valor;
    times t9 = {3, "DesimpedidosGoti", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9,2,1,valorMercado};
    insereABBrecursivo(raiz, t9);
    
    
    // Furia
    jogador j2_1 = {"Leleti", 0, 0, 80000, 92,"ATA"};
    jogador j2_2 = {"Lipao", 0, 0, 60000, 87,"ATA"};
    jogador j2_3 = {"Donato", 0, 0, 18000, 76,"ATA"};
    jogador j2_4 = {"Jefinho", 0, 0, 55000, 85,"MEI"};
    jogador j2_5 = {"Dedo", 0, 0, 44000, 84,"DEF"};
    goleiro g2 = {"Victor Hugo", 0, 30000, 83,"GOL"};
    presidente p2 = {"Cris Guedes", 0, 0, 74};
    valorMercado = j2_1.valor + j2_2.valor + j2_3.valor + j2_4.valor + j2_5.valor + g2.valor;
    times t2 = {7, "Furia FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2,7,15,valorMercado};
    insereABBrecursivo(raiz, t2);
	
	 // Dendele
    jogador j6_1 = {"Canhoto", 0, 0, 51000, 85,"MEI"};
    jogador j6_2 = {"Lucas Hector", 0, 0, 49000, 86,"MEI"};
    jogador j6_3 = {"Assump", 0, 0, 15000, 76,"MEI"};
    jogador j6_4 = {"Lyncoln", 0, 0, 40000, 85,"DEF"};
    jogador j6_5 = {"G. Carvalho", 0, 0, 9800, 74,"DEF"};
    goleiro g6 = {"Thales", 0, 24000, 80,"GOL"};
    presidente p6 = {"LuquEt4", 0, 0, 65};
    valorMercado = j6_1.valor + j6_2.valor + j6_3.valor + j6_4.valor + j6_5.valor + g6.valor;
    times t6 = {2, "Dendele FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6,1,14,valorMercado};
    insereABBrecursivo(raiz, t6);
    
    // Real Elite
    jogador j4_1 = {"Marlon Ribas", 0, 0, 18000, 75,"ATA"};
    jogador j4_2 = {"Davi Ilario", 0, 0, 80000, 89,"MEI"};
    jogador j4_3 = {"Well", 0, 0, 30000, 81,"MEI"};
    jogador j4_4 = {"Matheus Bueno", 0, 0, 16000, 75,"MEI"};
    jogador j4_5 = {"Vassoura", 0, 0, 35000, 84,"MEI"};
    goleiro g4 = {"Gustavo Rocha", 0, 14000, 75,"GOL"};
    presidente p4 = {"Allan Stag", 0, 0, 82};
    valorMercado = j4_1.valor + j4_2.valor + j4_3.valor + j4_4.valor + j4_5.valor + g4.valor;
    times t4 = {4, "FC Real Elite", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4,13,9,valorMercado};
    insereABBrecursivo(raiz, t4);
    
    // Funk
    jogador j7_1 = {"Douglinhas", 0, 0, 68000, 87,"ATA"};
    jogador j7_2 = {"Ibrahim", 0, 0, 30000, 84,"MEI"};
    jogador j7_3 = {"Betao Ribeiro", 0, 0, 27000, 80,"MEI"};
    jogador j7_4 =  {"Vitinho Ruas", 0, 0, 21000, 79,"MEI"};
    jogador j7_5 = {"MlkJhoow", 0, 0, 42000, 83,"DEF"};
    goleiro g7 = {"Gui Barros", 0, 13000, 75,"GOL"};
    presidente p7 = {"Michel Elias", 0, 0, 68};
    valorMercado = j7_1.valor + j7_2.valor + j7_3.valor + j7_4.valor + j7_5.valor + g7.valor;
    times t7 = {6, "Funkbol Clube", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7,5,14,valorMercado};
    insereABBrecursivo(raiz, t7);
    
    // LOUD
    jogador j5_1 = {"Drope", 0, 0, 30000, 83,"ATA"};
    jogador j5_2 = {"Igor Rock", 0, 0, 18000, 80,"ATA"};
    jogador j5_3 = {"Lukinhas", 0, 0, 48000, 85,"MEI"};
    jogador j5_4 = {"Matheuszin", 0, 0, 22000, 81,"MEI"};
    jogador j5_5 = {"Lucas Caroco", 0, 0, 27000, 82,"MEI"};
    goleiro g5 = {"Gabriel Kawa", 0, 21000, 82,"GOL"};
    presidente p5 = {"Loud Coringa", 0, 0, 77};
	valorMercado = j5_1.valor + j5_2.valor + j5_3.valor + j5_4.valor + j5_5.valor + g5.valor;
    times t5 = {9, "LOUD SC", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5,2,10,valorMercado};
    insereABBrecursivo(raiz, t5);
    
    // Capim
    jogador j3_1 = {"Igo Caninde", 0, 0, 30000, 82,"ATA"};
    jogador j3_2 = {"Briquinho", 0, 0, 23000, 79,"ATA"};
    jogador j3_3 = {"Henry Japa", 0, 0, 26000, 81,"MEI"};
    jogador j3_4 = {"Neto Show", 0, 0, 38000, 84,"MEI"};
    jogador j3_5 = {"GB Medeiros", 0, 0, 28000, 82,"DEF"};
    goleiro g3 = {"Barata", 0, 84000, 93,"GOL"};
    presidente p3 = {"Jon Vlogs", 0, 0, 69};
    valorMercado = j3_1.valor + j3_2.valor + j3_3.valor + j3_4.valor + j3_5.valor + g3.valor;
    times t3 = {1, "Capim FC", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3,11,8,valorMercado};
    insereABBrecursivo(raiz, t3);
	
    // G3X
    jogador j1_1 = {"Kelvin 'K9'", 0, 0, 120000, 95,"ATA"};
    jogador j1_2 = {"Ton", 0, 0, 69000, 87,"ATA"};
    jogador j1_3 = {"Andreas Vaz", 0, 0, 75000, 90,"MEI"};
    jogador j1_4 = {"Kenu", 0, 0, 34000, 83,"MEI"};
    //jogador j1_4 = {"Rufino", 0, 0, 54000, 86,"MEI"};
    jogador j1_5 = {"Wembley", 0, 0, 40000, 84,"DEF"};
    goleiro g1 = {"Igor Rezende", 0, 50000, 88,"GOL"};
    presidente p1 = {"Gaules", 0, 0, 73};
    valorMercado = j1_1.valor + j1_2.valor + j1_3.valor + j1_4.valor + j1_5.valor + g1.valor;
    times t1 = {8, "G3X FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1,15,14,valorMercado};
    insereABBrecursivo(raiz, t1);

    // Nyvelado{"Bruninho", 0, 0, 23200, 84,"MEI"};
    jogador j10_1 = {"Leo Gol", 0, 0, 58000, 88,"ATA"};
    jogador j10_2 = {"Bruninho", 0, 0, 23200, 84,"MEI"};
    jogador j10_3 = {"Breno Arantes", 0, 0, 18110, 79,"MEI"};
    jogador j10_4 = {"Klynsmann", 0, 0, 20000, 77,"MEI"};
    jogador j10_5 = {"Willin Jesus", 0, 0, 21000, 77,"DEF"};
    goleiro g10 = {"Ivo Alves", 0, 29000, 85,"GOL"};
    presidente p10 = {"Nyvi Estephan", 0, 0, 60};
    valorMercado = j10_1.valor + j10_2.valor + j10_3.valor + j10_4.valor + j10_5.valor + g10.valor;
    times t10 = {10, "Nyvelados FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10,8,15,valorMercado};
    insereABBrecursivo(raiz, t10);
}
#endif
