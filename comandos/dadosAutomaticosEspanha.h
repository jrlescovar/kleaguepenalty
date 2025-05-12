
/*
				5
				
		3				7
		
	2		4		6		9
	
1						8		10   
							11		12

*/
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
void dadosAutomaticosEspanha(tree **raiz){
    float valorMercado;
	// Los Troncos FC
    jogador j6_1 = {"D. Jimenez", 0, 0, 12000, 76, "ATA"};
    jogador j6_2 = {"Joan Verdu", 0, 0, 20000, 80, "MEI"};
    jogador j6_3 = {"Jordi Gomez", 0, 0, 20000, 81, "MEI"};
    jogador j6_4 = {"A. Gutierrez", 0, 0, 18000, 79, "DEF"};
    jogador j6_5 = {"Carles Planas", 0, 0, 42000, 86, "DEF"};
    goleiro g6 = {"Eloy Amoedo", 0, 0, 40000, 85, "GOL"};
    presidente p6 = {"Perxitaa", 0, 0, 68};
    valorMercado = j6_1.valor + j6_2.valor + j6_3.valor + j6_4.valor + j6_5.valor + g6.valor;
    times team6 = {6, "Los Troncos FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6, 2, 7, valorMercado};
    insereABBrecursivo(raiz, team6);
    

    // Aniquiladores FC
    jogador j2_1 = {"Edgar Alvaro", 0, 0, 40000, 85, "ATA"};
    jogador j2_2 = {"Javi Espinosa", 0, 0, 40000, 84, "MEI"};
    jogador j2_3 = {"Hugo Fraile", 0, 0, 21000, 81, "MEI"};
    jogador j2_4 = {"Mantovani", 0, 0, 20000, 80, "DEF"};
    jogador j2_5 = {"Carlos Val", 0, 0, 20000, 80, "DEF"};
    goleiro g2 = {"Victor Cocera", 0, 0, 25000, 83, "GOL"};
    presidente p2 = {"Juan Guarnizo", 0, 0, 60};
    valorMercado = j2_1.valor + j2_2.valor + j2_3.valor + j2_4.valor + j2_5.valor + g2.valor;
    times team2 = {2, "Aniquiladores FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2, 4, 12, valorMercado};
    insereABBrecursivo(raiz, team2);
	
	 // Jijantes FC
    jogador j4_1 = {"Pol Ortega", 0, 0, 77000, 90, "ATA"};
    jogador j4_2 = {"C. Martinez", 0, 0, 10000, 75, "ATA"};
    jogador j4_3 = {"Nil Ayats", 0, 0, 35000, 84, "MEI"};
    jogador j4_4 = {"Daniel Plaza", 0, 0, 17000, 78, "MEI"};
    jogador j4_5 = {"Nico Pareja", 0, 0, 12000, 76, "DEF"};
    goleiro g4 = {"Victor Vidal", 0, 0, 50000, 87, "GOL"};
    presidente p4 = {"Gerad Romero", 0, 0, 75};
    valorMercado = j4_1.valor + j4_2.valor + j4_3.valor + j4_4.valor + j4_5.valor + g4.valor;
    times team4 = {4,"Jijantes FC", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4, 1, 4, valorMercado};
    insereABBrecursivo(raiz, team4);
    
     // Porcinos FC
    jogador j8_1 = {"Marc Pelaz", 0, 0, 50000, 86, "MEI"};
    jogador j8_2 = {"Gilles Videl", 0, 0, 26000, 81, "MEI"};
    jogador j8_3 = {"Gerad Nolla", 0, 0, 36000, 84, "MEI"};
    jogador j8_4 = {"Ivan Torres", 0, 0, 20000, 80, "DEF"};
    jogador j8_5 = {"Nadir Louah", 0, 0, 33000, 84, "DEF"};
    goleiro g8 = {"Adria 'Capi'", 0, 0, 24000, 82, "GOL"};
    presidente p8 = {"Ibai", 0, 0, 74};
    valorMercado = j8_1.valor + j8_2.valor + j8_3.valor + j8_4.valor + j8_5.valor + g8.valor;
    times team8 = {8, "Porcinos FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8, 13, 15, valorMercado};
    insereABBrecursivo(raiz, team8);

    // 1K FC
    jogador j1_1 = {"Nico Santos", 0, 0, 27000, 82, "ATA"};
    jogador j1_2 = {"Carlos Corvo", 0, 0, 29000, 83, "ATA"};
    jogador j1_3 = {"Gerad Verge", 0, 0, 25000, 80, "MEI"};
    jogador j1_4 = {"Feliu Torrus", 0, 0, 18000, 79, "MEI"};
    jogador j1_5 = {"Victor Mongi", 0, 0, 27000, 82, "DEF"};
    goleiro g1 = {"Pol Lechuga", 0, 0, 40000, 85, "GOL"};
    presidente p1 = {"Casillas", 0, 0, 85};
    valorMercado = j1_1.valor + j1_2.valor + j1_3.valor + j1_4.valor + j1_5.valor + g1.valor;
    times team1 = {1, "1K FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1, 5, 9, valorMercado};
    insereABBrecursivo(raiz, team1);


    // Kunisports
    jogador j5_1 = {"Facu Romero", 0, 0, 26000, 82, "ATA"};
    jogador j5_2 = {"Omabegho", 0, 0, 24000, 80, "ATA"};
    jogador j5_3 = {"Alvaro Arche", 0, 0, 18000, 79, "MEI"};
    jogador j5_4 = {"Franco Romero", 0, 0, 17000, 78, "MEI"};
    jogador j5_5 = {"G. Cichero", 0, 0, 40000, 85, "DEF"};
    goleiro g5 = {"Jorge Ibanez", 0, 0, 25000, 83, "GOL"};
    presidente p5 = {"Kun Aguero", 0, 0, 86};
    valorMercado = j5_1.valor + j5_2.valor + j5_3.valor + j5_4.valor + j5_5.valor + g5.valor;
    times team5 = {5, "Kunisports", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5, 8, 13, valorMercado};
    insereABBrecursivo(raiz, team5);

    

    // PIO FC
    jogador j7_1 = {"Lobato", 0, 0, 10000, 71, "ATA"};
    jogador j7_2 = {"Pablo F.", 0, 0, 29000, 81, "MEI"};
    jogador j7_3 = {"Luis Garcia", 0, 0, 24000, 80, "MEI"};
    jogador j7_4 = {"Iker G.", 0, 0, 10000, 72, "MEI"};
    jogador j7_5 = {"Banuls", 0, 0, 10000, 73, "DEF"};
    goleiro g7 = {"Dani Parra", 0, 0, 21000, 83, "GOL"};
    presidente p7 = {"Rivers", 0, 0, 70};
    valorMercado = j7_1.valor + j7_2.valor + j7_3.valor + j7_4.valor + j7_5.valor + g7.valor;
    times team7 = {7, "PIO FC", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7, 8, 15, valorMercado};
    insereABBrecursivo(raiz, team7);


    // Rayo Barcelona
    jogador j9_1 = {"Gerad Oliva", 0, 0, 27500, 83, "ATA"};
    jogador j9_2 = {"M. Boullouh", 0, 0, 29000, 83, "ATA"};
    jogador j9_3 = {"Alex Marti", 0, 0, 29000, 83, "ATA"};
    jogador j9_4 = {"Dani Perez", 0, 0, 10000, 75, "MEI"};
    jogador j9_5 = {"Pau 'ZZ'", 0, 0, 10000, 74, "DEF"};
    goleiro g9 = {"A. Arnalot", 0, 0, 20000, 80, "GOL"};
    presidente p9 = {"Spursito", 0, 0, 81};
    valorMercado = j9_1.valor + j9_2.valor + j9_3.valor + j9_4.valor + j9_5.valor + g9.valor;
    times team9 = {9, "Rayo Barcelona", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9, 14, 8, valorMercado};
    insereABBrecursivo(raiz, team9);

    // Saiyans FC
    jogador j10_1 = {"A. Espinar", 0, 0, 20000, 82, "ATA"};
    jogador j10_2 = {"Jero Martins", 0, 0, 28000, 82, "MEI"};
    jogador j10_3 = {"Aitor Vives", 0, 0, 20000, 79, "MEI"};
    jogador j10_4 = {"J. A. Gallego", 0, 0, 21000, 81, "MEI"};
    jogador j10_5 = {"Sergio Juste", 0, 0, 11000, 76, "DEF"};
    goleiro g10 = {"Marc Briones", 0, 0, 30000, 84, "GOL"};
    presidente p10 = {"TheGrefg", 0, 0, 65};
    valorMercado = j10_1.valor + j10_2.valor + j10_3.valor + j10_4.valor + j10_5.valor + g10.valor;
    times team10 = {10, "Saiyans FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10, 6, 1, valorMercado};
    insereABBrecursivo(raiz, team10);

    // Ult. Mostoles
    jogador j11_1 = {"Corominas", 0, 0, 16000, 78, "ATA"};
    jogador j11_2 = {"Linares", 0, 0, 18000, 79, "MEI"};
    jogador j11_3 = {"Marc Granero", 0, 0, 40000, 85, "DEF"};
    jogador j11_4 = {"de La bella", 0, 0, 38000, 84, "DEF"};
    jogador j11_5 = {"Diego la Mata", 0, 0, 49000, 86, "DEF"};
    goleiro g11 = {"Segovia", 0, 0, 29000, 82, "GOL"};
    presidente p11 = {"DjMaRiiO", 0, 0, 77};
    valorMercado = j11_1.valor + j11_2.valor + j11_3.valor + j11_4.valor + j11_5.valor + g11.valor;
    times team11 = {11, "Ult. Mostoles", j11_1, j11_2, j11_3, j11_4, j11_5, g11, p11, 8, 4, valorMercado};
    insereABBrecursivo(raiz, team11);

    // xBuyer Team
    jogador j12_1 = {"Victor Oribe", 0, 0, 27500, 82, "ATA"};
    jogador j12_2 = {"Juanma G.", 0, 0, 23000, 80, "ATA"};
    jogador j12_3 = {"Pablo Beguer", 0, 0, 29000, 83, "MEI"};
    jogador j12_4 = {"F. El Amrani", 0, 0, 40000, 85, "MEI"};
    jogador j12_5 = {"Gimeno", 0, 0, 12000, 76, "MEI"};
    goleiro g12 = {"Sergi Aguilar", 0, 0, 20000, 80, "GOL"};
    presidente p12 = {"Eric Ruiz", 0, 0, 78};
    valorMercado = j12_1.valor + j12_2.valor + j12_3.valor + j12_4.valor + j12_5.valor + g12.valor;
    times team12 = {12, "xBuryer Team", j12_1, j12_2, j12_3, j12_4, j12_5, g12, p12, 15, 8, valorMercado};
    insereABBrecursivo(raiz, team12);
    
     // El Barrio
    jogador j3_1 = {"Antoni H.", 0, 0, 10000, 72, "ATA"};
    jogador j3_2 = {"Cristian Ubon", 0, 0, 49000, 87, "MEI"};
    jogador j3_3 = {"R. Vallribera", 0, 0, 39000, 85, "MEI"};
    jogador j3_4 = {"Xavi Pluvins", 0, 0, 17000, 78, "MEI"};
    jogador j3_5 = {"Marc Valiente", 0, 0, 13000, 77, "DEF"};
    goleiro g3 = {"Rafa Leva", 0, 0, 21000, 80, "GOL"};
    presidente p3 = {"Adri Conteras", 0, 0, 84};
    valorMercado = j3_1.valor + j3_2.valor + j3_3.valor + j3_4.valor + j3_5.valor + g3.valor;
    times team3 = {3, "El Barrio", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3, 11, 8, valorMercado};
    insereABBrecursivo(raiz, team3);
}

