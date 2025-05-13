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
void dadosAutomaticosItalia(tree **raiz){
    float valorMercado;
	// FC Zeta
    jogador j6_1 = {"M. Perrotti", 0, 0, 110000, 93, "ATA"};
    jogador j6_2 = {"T. Bernardi", 0, 0, 40000, 84, "MEI"};
    jogador j6_3 = {"Montagna", 0, 0, 20000, 81, "MEI"};
    jogador j6_4 = {"Elhamadi K.", 0, 0, 18000, 79, "DEF"};
    jogador j6_5 = {"Manzoni", 0, 0, 12000, 76, "DEF"};
    goleiro g6 = {"Alesio Buono", 0, 0, 40000, 84, "GOL"};
    presidente p6 = {"Luca Toni", 0, 0, 68};
    valorMercado = j6_1.valor + j6_2.valor + j6_3.valor + j6_4.valor + j6_5.valor + g6.valor;
    times team6 = {6, "FC Zeta", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6, 4, 8, valorMercado};
    insereABBrecursivo(raiz, team6);
    

    // Black Lótus
    jogador j2_1 = {"Off Samuel", 0, 0, 33000, 84, "ATA"};
    jogador j2_2 = {"A. Filipi", 0, 0, 26000, 82, "ATA"};
    jogador j2_3 = {"Fatjon Suma", 0, 0, 10000, 75, "MEI"};
    jogador j2_4 = {"Marco Baioni", 0, 0, 28000, 83,"MEI"};
    jogador j2_5 = {"M. Citerrio", 0, 0, 20000, 80, "DEF"};
    goleiro g2 = {"Simoni Pequini", 0, 0, 25000, 83, "GOL"};
    presidente p2 = {"Sergio Cruz", 0, 0, 74};
    valorMercado = j2_1.valor + j2_2.valor + j2_3.valor + j2_4.valor + j2_5.valor + g2.valor;
    times team2 = {2, "Black Lotus FC", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2, 1, 8, valorMercado};
    insereABBrecursivo(raiz, team2);
	
	 // Circus FC
    jogador j4_1 = {"Bertocchi", 0, 0, 50000, 87, "ATA"};
    jogador j4_2 = {"Fichera", 0, 0, 37000, 85, "ATA"};
    jogador j4_3 = {"Giulio Uras", 0, 0, 27000, 81, "ATA"};
    jogador j4_4 = {"Tommaso C.", 0, 0, 40000, 85, "MEI"};
    jogador j4_5 = {"Mantovani", 0, 0, 10000, 75, "DEF"};
    goleiro g4 = {"Marenco", 0, 0, 21000, 82, "GOL"};
    presidente p4 = {"GrenBaud", 0, 0, 61};
    valorMercado = j4_1.valor + j4_2.valor + j4_3.valor + j4_4.valor + j4_5.valor + g4.valor;
    times team4 = {4,"Circus FC", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4, 7, 5, valorMercado};
    insereABBrecursivo(raiz, team4);
    
     // Punchers FC
    jogador j8_1 = {"Patacchini", 0, 0,14000 , 77, "ATA"};
    jogador j8_2 = {"Giacchino", 0, 0, 22000, 80, "ATA"};
    jogador j8_3 = {"Kalaja", 0, 0, 21000, 80, "ATA"};
    jogador j8_4 = {"Mihaylov", 0, 0, 11000, 76, "MEI"};
    jogador j8_5 = {"Stemmi", 0, 0, 10000, 73, "MEI"};
    goleiro g8 = {"Fumagalli", 0, 0, 20000, 81, "GOL"};
    presidente p8 = {"Pirlas V", 0, 0, 70};
    valorMercado = j8_1.valor + j8_2.valor + j8_3.valor + j8_4.valor + j8_5.valor + g8.valor;
    times team8 = {8, "Punchers FC", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8, 6, 8, valorMercado};
    insereABBrecursivo(raiz, team8);

    // ALPAK FC
    jogador j1_1 = {"D. Rossi", 0, 0, 78000, 89, "ATA"};
    jogador j1_2 = {"J. Henrique", 0, 0, 29000, 83, "ATA"};
    jogador j1_3 = {"Benedetti", 0, 0, 25000, 80, "ATA"};
    jogador j1_4 = {"Lorenzani", 0, 0, 34000, 80, "MEI"};
    jogador j1_5 = {"Vlad Marin", 0, 0, 27000, 82, "DEF"};
    goleiro g1 = {"Luigi Castelli", 0, 0, 12000, 76, "GOL"};
    presidente p1 = {"Frenezy", 0, 0, 65};
    valorMercado = j1_1.valor + j1_2.valor + j1_3.valor + j1_4.valor + j1_5.valor + g1.valor;
    times team1 = {1, "Alpak FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1, 13, 8, valorMercado};
    insereABBrecursivo(raiz, team1);


    //FC Caesar
    jogador j5_1 = {"A. Picci", 0, 0, 36000, 84, "ATA"};
    jogador j5_2 = {"Loiodice", 0, 0, 50000, 86, "ATA"};
    jogador j5_3 = {"Nainggolan", 0, 0, 30000, 82, "MEI"};
    jogador j5_4 = {"Praglia", 0, 0, 10000, 75, "DEF"};
    jogador j5_5 = {"Dell Acqua", 0, 0, 10000, 75, "DEF"};
    goleiro g5 = {"Mazzaglia", 0, 0, 10000, 75, "GOL"};
    presidente p5 = {"En3rix", 0, 0, 66};
    valorMercado = j5_1.valor + j5_2.valor + j5_3.valor + j5_4.valor + j5_5.valor + g5.valor;
    times team5 = {5, "FC Caesar", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5, 4, 8, valorMercado};
    insereABBrecursivo(raiz, team5);

    

    // Gear 7 FC
    jogador j7_1 = {"Fran Hernadez", 0, 0, 78000, 90, "ATA"};
    jogador j7_2 = {"De la Cruz", 0, 0, 31000, 82, "ATA"};
    jogador j7_3 = {"Ale. Gelsi", 0, 0, 50000, 87, "MEI"};
    jogador j7_4 = {"David Lopez", 0, 0, 17000, 78, "MEI"};
    jogador j7_5 = {"Ciceri", 0, 0, 10000, 75, "DEF"};
    goleiro g7 = {"Bernardo Leka", 0, 0, 50000, 87, "GOL"};
    presidente p7 = {"Manuuxo", 0, 0, 70};
    valorMercado = j7_1.valor + j7_2.valor + j7_3.valor + j7_4.valor + j7_5.valor + g7.valor;
    times team7 = {7, "Gear 7 FC", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7, 1, 4, valorMercado};
    insereABBrecursivo(raiz, team7);


    // Stalions
    jogador j9_1 = {"Stojkovic", 0, 0, 39500, 85, "ATA"};
    jogador j9_2 = {"Altamura", 0, 0, 21000, 82, "ATA"};
    jogador j9_3 = {"S. Solda", 0, 0, 33000, 84, "ATA"};
    jogador j9_4 = {"Brusadelli", 0, 0, 19000, 79, "MEI"};
    jogador j9_5 = {"Evangelisti", 0, 0, 18000, 79, "DEF"};
    goleiro g9 = {"G. Bressan", 0, 0, 50000, 86, "GOL"};
    presidente p9 = {"Blur", 0, 0, 78};
    valorMercado = j9_1.valor + j9_2.valor + j9_3.valor + j9_4.valor + j9_5.valor + g9.valor;
    times team9 = {9, "Stalions", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9, 9, 1, valorMercado};
    insereABBrecursivo(raiz, team9);

    // TRM FC
    jogador j10_1 = {"A. Colombo", 0, 0, 104000, 92, "ATA"};
    jogador j10_2 = {"Caputo", 0, 0, 50000, 87, "ATA"};
    jogador j10_3 = {"M. Rossoni", 0, 0, 20000, 79, "ATA"};
    jogador j10_4 = {"Salvaterra", 0, 0, 21000, 81, "DEF"};
    jogador j10_5 = {"Andrea Fillipi", 0, 0, 19000, 79, "DEF"};
    goleiro g10 = {"A. Vagge", 0, 0, 49000, 86, "GOL"};
    presidente p10 = {"TRealMarzaa", 0, 0, 69};
    valorMercado = j10_1.valor + j10_2.valor + j10_3.valor + j10_4.valor + j10_5.valor + g10.valor;
    times team10 = {10, "TRM FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10, 14, 8, valorMercado};
    insereABBrecursivo(raiz, team10);

    // Underdogs FC 
    jogador j11_1 = {"Mattia Pesca", 0, 0, 17000, 78, "ATA"};
    jogador j11_2 = {"Ronchi", 0, 0, 21000, 80, "MEI"};
    jogador j11_3 = {"M. Tempera", 0, 0, 10000, 74, "MEI"};
    jogador j11_4 = {"Ruggieri", 0, 0, 25000, 81, "MEI"};
    jogador j11_5 = {"A. Ghiorghies", 0, 0, 10000, 72, "DEF"};
    goleiro g11 = {"Casapieri", 0, 0, 10000, 76, "GOL"};
    presidente p11 = {"Mirko Cisco", 0, 0, 67};
    valorMercado = j11_1.valor + j11_2.valor + j11_3.valor + j11_4.valor + j11_5.valor + g11.valor;
    times team11 = {11, "Underdogs FC", j11_1, j11_2, j11_3, j11_4, j11_5, g11, p11, 10, 4, valorMercado};
    insereABBrecursivo(raiz, team11);

    // zebrafc 
    jogador j12_1 = {"Lorenzo Berra", 0, 0, 101000, 91, "ATA"};
    jogador j12_2 = {"G. Pelli ", 0, 0, 17000, 78, "MEI"};
    jogador j12_3 = {"Luca Bonzi", 0, 0, 18000, 79, "MEI"};
    jogador j12_4 = {"Ricardo Villa", 0, 0, 21000, 81, "MEI"};
    jogador j12_5 = {"Tarasco", 0, 0, 22000, 80, "DEF"};
    goleiro g12 = {"A. Luliano", 0, 0, 40000, 85, "GOL"};
    presidente p12 = {"L. Campolunghi", 0, 0, 78};
    valorMercado = j12_1.valor + j12_2.valor + j12_3.valor + j12_4.valor + j12_5.valor + g12.valor;
    times team12 = {12, "Zebras FC", j12_1, j12_2, j12_3, j12_4, j12_5, g12, p12, 15, 8, valorMercado};
    insereABBrecursivo(raiz, team12);
    
     // Boomers
    jogador j3_1 = {"D. Santoro", 0, 0, 50000, 87, "ATA"};
    jogador j3_2 = {"S. Lo Faso", 0, 0, 76000, 89, "ATA"};
    jogador j3_3 = {"Giannace", 0, 0, 20000, 80, "ATA"};
    jogador j3_4 = {"Bryan Mecca", 0, 0, 19000, 79, "MEI"};
    jogador j3_5 = {"Bonucci", 0, 0, 40000, 84,"DEF"};
    goleiro g3 = {"Vlad Caprianu", 0, 0, 21000, 80, "GOL"};
    presidente p3 = {"Fedez", 0, 0, 72};
    valorMercado = j3_1.valor + j3_2.valor + j3_3.valor + j3_4.valor + j3_5.valor + g3.valor;
    times team3 = {3, "Boomers", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3, 14, 12, valorMercado};
    insereABBrecursivo(raiz, team3);
}
