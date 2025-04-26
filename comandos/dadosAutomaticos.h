#ifndef DADOS_AUTOMATICOS_H
#define DADOS_AUTOMATICOS_H

#include "times.h"
void dadosAutomaticos(tree **raiz) {
	
    // Fluxo{"Victor Bueno", 0, 0, 21000, 79,"ATA"}
    jogador j8_1 = {"Boolt", 0, 0, 38000, 84,"ATA"};
    jogador j8_2 = {"Helber Jr", 0, 0, 30000, 81,"ATA"};
    jogador j8_3 = {"Victor Bueno", 0, 0, 21000, 79,"ATA"};
    jogador j8_4 = {"Chaveirinho", 0, 0, 25000, 80,"MEI"};
    jogador j8_5 = {"Melequinha", 0, 0, 17000, 75,"DEF"};
    goleiro g8 = {"Julio Carvalho", 0, 19000, 76,"GOL"};
    presidente p8 = {"Nobru", 0, 0, 76};
    times t8 = {5, "Fluxo FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8,8,4};
    insereABBrecursivo(raiz, t8);
    
    // Goti
    jogador j9_1 = {"Marcelin Jr", 0, 0, 33210, 83,"ATA"};
    jogador j9_2 = {"Caio Miranda", 0, 0, 31000, 80,"ATA"};
    jogador j9_3 = {"Thor", 0, 0, 25000, 79,"ATA"};
    jogador j9_4 = {"Bolt", 0, 0, 19000, 79,"MEI"};
    jogador j9_5 = {"Batman", 0, 0, 28000, 80,"MEI"};
    goleiro g9 = {"Joao Pedro", 0, 59000, 88,"GOL"};
    presidente p9 = {"Yuri 22", 0, 0, 65};
    times t9 = {3, "Desimpedidos Goti", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9,2,1};
    insereABBrecursivo(raiz, t9);
    
    
    // Furia
    jogador j2_1 = {"Leleti", 0, 0, 80000, 92,"ATA"};
    jogador j2_2 = {"Lipao", 0, 0, 60000, 87,"ATA"};
    jogador j2_3 = {"Donato", 0, 0, 14000, 75,"ATA"};
    jogador j2_4 = {"Jefinho", 0, 0, 55000, 85,"MEI"};
    jogador j2_5 = {"Dedo", 0, 0, 44000, 84,"DEF"};
    goleiro g2 = {"Victor Hugo", 0, 30000, 83,"GOL"};
    presidente p2 = {"Cris Guedes", 0, 0, 74};
    times t2 = {7, "Furia FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2,7,15};
    insereABBrecursivo(raiz, t2);
	
	 // Dendele
    jogador j6_1 = {"Canhoto", 0, 0, 51000, 85,"MEI"};
    jogador j6_2 = {"Lyncoln", 0, 0, 40000, 84,"MEI"};
    jogador j6_3 = {"Lucas Hector", 0, 0, 49000, 86,"MEI"};
    jogador j6_4 = {"Assump", 0, 0, 15000, 76,"MEI"};
    jogador j6_5 = {"G. Carvalho", 0, 0, 8800, 74,"DEF"};
    goleiro g6 = {"Thales", 0, 19000, 75,"GOL"};
    presidente p6 = {"LuquEt4", 0, 0, 65};
    times t6 = {2, "Dendele FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6,1,14};
    insereABBrecursivo(raiz, t6);
    
    // Real Elite
    jogador j4_1 = {"Marlon Ribas", 0, 0, 1800, 75,"ATA"};
    jogador j4_2 = {"Davi Ilario", 0, 0, 80000, 89,"MEI"};
    jogador j4_3 = {"Well", 0, 0, 35000, 83,"MEI"};
    jogador j4_4 = {"Matheus Bueno", 0, 0, 16000, 75,"MEI"};
    jogador j4_5 = {"?????", 0, 0, 0, 0,"???"};
    goleiro g4 = {"Gustavo Rocha", 0, 14000, 76,"GOL"};
    presidente p4 = {"Allan Stag", 0, 0, 82};
    times t4 = {4, "FC Real Elite", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4,13,9};
    insereABBrecursivo(raiz, t4);
    
    // Funk
    jogador j7_1 = {"Douglinhas", 0, 0, 68000, 87,"ATA"};
    jogador j7_2 = {"Ibrahim", 0, 0, 30000, 84,"MEI"};
    jogador j7_3 = {"Davisson", 0, 0, 25000, 79,"MEI"};
    jogador j7_4 =  {"Vitinho Ruas", 0, 0, 21000, 79,"MEI"};
    jogador j7_5 = {"MlkJhoow", 0, 0, 42000, 83,"DEF"};
    goleiro g7 = {"Gui Barros", 0, 19000, 76,"GOL"};
    presidente p7 = {"Mc Hariel", 0, 0, 68};
    times t7 = {6, "Funkbol Clube", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7,5,14};
    insereABBrecursivo(raiz, t7);
    
    // LOUD
    jogador j5_1 = {"Drope", 0, 0, 40000, 84,"ATA"};
    jogador j5_2 = {"Igor Rock", 0, 0, 1800, 77,"ATA"};
    jogador j5_3 = {"Lukinhas", 0, 0, 42000, 82,"MEI"};
    jogador j5_4 = {"?????", 0, 0, 0, 0,"????"};
    jogador j5_5 = {"?????", 0, 0, 0, 0,"????"};
    goleiro g5 = {"Esau", 0, 39000, 82,"GOL"};
    presidente p5 = {"Loud Coringa", 0, 0, 77};
    times t5 = {9, "LOUD SC", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5,2,10};
    insereABBrecursivo(raiz, t5);
    
    // Capim
    jogador j3_1 = {"Negao", 0, 0, 40000, 84,"ATA"};
    jogador j3_2 = {"Briquinho", 0, 0, 22000, 77,"ATA"};
    jogador j3_3 = {"Henry Japa", 0, 0, 25000, 81,"MEI"};
    jogador j3_4 = {"GB Medeiros", 0, 0, 20000, 78,"DEF"};
    jogador j3_5 = {"?????", 0, 0, 0, 0,"???"};
    goleiro g3 = {"Barata", 0, 75000, 90,"GOL"};
    presidente p3 = {"Jon Vlogs", 0, 0, 69};
    times t3 = {1, "Capim FC", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3,11,8};
    insereABBrecursivo(raiz, t3);
	
    // G3X{"Ton", 0, 0, 50000, 85,"ATA"};
    jogador j1_1 = {"Kelvin 'K9'", 0, 0, 100000, 95,"ATA"};
    jogador j1_2 = {"Ton", 0, 0, 50000, 85,"ATA"};
    jogador j1_3 = {"Andreas Vaz", 0, 0, 75000, 91,"MEI"};
    jogador j1_4 = {"Kenu", 0, 0, 32000, 80,"MEI"};
    jogador j1_5 = {"Wembley", 0, 0, 40000, 84,"DEF"};
    goleiro g1 = {"Igor Rezende", 0, 30000, 81,"GOL"};
    presidente p1 = {"Gaules", 0, 0, 71};
    times t1 = {8, "G3X FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1,15,14};
    insereABBrecursivo(raiz, t1);

    // Nyvelado{"Choco", 0, 0, 25000, 76,"ATA"};
    jogador j10_1 = {"Leo Gol", 0, 0, 58000, 88,"ATA"};
    jogador j10_2 = {"Choco", 0, 0, 25000, 76,"ATA"};
    jogador j10_3 = {"Breno Arantes", 0, 0, 18110, 79,"MEI"};
    jogador j10_4 = {"Bruninho", 0, 0, 23200, 84,"MEI"};
    jogador j10_5 = {"Willin Jesus", 0, 0, 21000, 77,"DEF"};
    goleiro g10 = {"Ivo Alves", 0, 29000, 85,"GOL"};
    presidente p10 = {"Nyvi Estephan", 0, 0, 27};
    times t10 = {10, "Nyvelados FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10,8,15};
    insereABBrecursivo(raiz, t10);
}
#endif
