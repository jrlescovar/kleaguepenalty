void dadosAutomaticosAmericas(tree **raiz){
    float valorMercado;
	// Muchacos
    jogador j6_1 = {"Pablo Gomez", 0, 0, 28000, 82, "ATA"};
    jogador j6_2 = {"Jair Pérez", 0, 0, 10000, 72, "ATA"};
    jogador j6_3 = {"Diego Martinez", 0, 0, 62000, 88, "MEI"};
    jogador j6_4 = {"C. Pedraza", 0, 0, 16000, 77, "MEI"};
    jogador j6_5 = {"George Coral", 0, 0, 32000, 84, "DEF"};
    goleiro g6 = {"Oscar Medina", 0, 0, 16000, 77, "GOL"};
    presidente p6 = {"Jero Freixas", 0, 0, 75};
    valorMercado = j6_1.valor + j6_2.valor + j6_3.valor + j6_4.valor + j6_5.valor + g6.valor;
    times team6 = {6, "Muchachos FC", j6_1, j6_2, j6_3, j6_4, j6_5, g6, p6, 9, 14, valorMercado};
    insereABBrecursivo(raiz, team6);
    

    //Cuervos
    jogador j2_1 = {"Askenazi", 0, 0, 48000, 87, "ATA"};
    jogador j2_2 = {"Adriano N.", 0, 0, 49000, 87, "ATA"};
    jogador j2_3 = {"Jose Nietto", 0, 0, 33000, 84, "ATA"};
    jogador j2_4 = {"Escamilla", 0, 0, 26000, 82,"MEI"};
    jogador j2_5 = {"Angel 'Curry'", 0, 0, 29000, 83, "MEI"};
    goleiro g2 = {"O. Lascari", 0, 0, 50000, 86, "GOL"};
    presidente p2 = {"NataliaMX", 0, 0, 79};
    valorMercado = j2_1.valor + j2_2.valor + j2_3.valor + j2_4.valor + j2_5.valor + g2.valor;
    times team2 = {2, "Clube Cuervos", j2_1, j2_2, j2_3, j2_4, j2_5, g2, p2, 8,15, valorMercado};
    insereABBrecursivo(raiz, team2);
	
	 // Lós Chamos FC
    jogador j5_1 = {"G. Castillo", 0, 0, 35000, 84, "ATA"};
    jogador j5_2 = {"J. Cisneros", 0, 0, 50000, 87, "MEI"};
    jogador j5_3 = {"Lagunas", 0, 0, 40000, 85, "MEI"};
    jogador j5_4 = {"Luis Ayala", 0, 0, 14000, 77, "MEI"};
    jogador j5_5 = {"Tona Mejia", 0, 0, 20000, 80, "DEF"};
    goleiro g5 = {"Edgar Alvarez", 0, 0, 40000, 85, "GOL"};
    presidente p5 = {"RdJavi", 0, 0, 75};
    valorMercado = j5_1.valor + j5_2.valor + j5_3.valor + j5_4.valor + j5_5.valor + g5.valor;
    times team5= {5,"Los Chamos FC", j5_1, j5_2, j5_3, j5_4, j5_5, g5, p5, 6, 15, valorMercado};
    insereABBrecursivo(raiz, team5);
    
     // Peluche 
    jogador j8_1 = {"S. Largade", 0, 0,32000 , 85, "ATA"};
    jogador j8_2 = {"H. Ciprian", 0, 0, 10000, 74, "MEI"};
    jogador j8_3 = {"Javier Galeno", 0, 0, 11000, 76, "MEI"};
    jogador j8_4 = {"Jorge ‘Russo’", 0, 0, 18000, 79, "DEF"};
    jogador j8_5 = {"J. Van Rakin", 0, 0, 12000, 76, "DEF"};
    goleiro g8 = {"Angel Rascon", 0, 0, 31000, 84, "GOL"};
    presidente p8 = {"Montiel", 0, 0, 82};
    valorMercado = j8_1.valor + j8_2.valor + j8_3.valor + j8_4.valor + j8_5.valor + g8.valor;
    times team8 = {8, "Peluche Caligari", j8_1, j8_2, j8_3, j8_4, j8_5, g8, p8, 14, 4, valorMercado};
    insereABBrecursivo(raiz, team8);

    // ATL. Parceros FC
    jogador j1_1 = {"Angellot Caro", 0, 0, 33000, 84, "ATA"};
    jogador j1_2 = {"Trevino", 0, 0, 10000, 72, "MEI"};
    jogador j1_3 = {"Vilanueva", 0, 0, 20000, 80, "MEI"};
    jogador j1_4 = {"S. Pascoe", 0, 0, 12000, 76, "MEI"};
    jogador j1_5 = {"D. Lobon", 0, 0, 14000, 77, "DEF"};
    goleiro g1 = {"Yoyan C.", 0, 0, 12000, 76, "GOL"};
    presidente p1 = {"J. Rodrigues", 0, 0, 83};
    valorMercado = j1_1.valor + j1_2.valor + j1_3.valor + j1_4.valor + j1_5.valor + g1.valor;
    times team1 = {1, "ATL. Parceros FC", j1_1, j1_2, j1_3, j1_4, j1_5, g1, p1, 12, 8, valorMercado};
    insereABBrecursivo(raiz, team1);


    //Los Aliens 
    jogador j4_1 = {"Edgar Martinez", 0, 0, 14000, 77, "ATA"};
    jogador j4_2 = {"Jorge Melendez", 0, 0, 29000, 83, "MEI"};
    jogador j4_3 = {"Bryan Nazarit", 0, 0, 50000, 87, "MEI"};
    jogador j4_4 = {"Alan Mendoza", 0, 0, 13000, 77, "DEF"};
    jogador j4_5 = {"Dani Mendoza", 0, 0, 10000, 75, "DEF"};
    goleiro g4 = {"Julio Torres", 0, 0, 47000, 86, "GOL"};
    presidente p4 = {"Castro1021", 0, 0, 70};
    valorMercado = j4_1.valor + j4_2.valor + j4_3.valor + j4_4.valor + j4_5.valor + g4.valor;
    times team4 = {4, "Los Aliens FC", j4_1, j4_2, j4_3, j4_4, j4_5, g4, p4, 9, 5, valorMercado};
    insereABBrecursivo(raiz, team4);

    

    // Olimpo 
    jogador j7_1 = {"Marco Bueno", 0, 0, 20000, 80, "ATA"};
    jogador j7_2 = {"Davidz Junco", 0, 0, 12000, 76, "ATA"};
    jogador j7_3 = {"Bryan H.", 0, 0, 14000, 77, "MEI"};
    jogador j7_4 = {"Gustavo Furby", 0, 0, 20000, 80, "MEI"};
    jogador j7_5 = {"Patricio Pato", 0, 0, 16000, 78, "DEF"};
    goleiro g7 = {"Tirso Trueba", 0, 0, 22000, 81, "GOL"};
    presidente p7 = {"Chicharito", 0, 0, 84};
    valorMercado = j7_1.valor + j7_2.valor + j7_3.valor + j7_4.valor + j7_5.valor + g7.valor;
    times team7 = {7, "Olimpo United", j7_1, j7_2, j7_3, j7_4, j7_5, g7, p7, 7, 6, valorMercado};
    insereABBrecursivo(raiz, team7);


    //Persas FC
    jogador j9_1 = {"Juan Celada", 0, 0, 10000, 72, "ATA"};
    jogador j9_2 = {"Yair Arias", 0, 0, 10000, 74, "MEI"};
    jogador j9_3 = {"J. Palácios", 0, 0, 20000, 81, "MEI"};
    jogador j9_4 = {"Obed Martinez", 0, 0, 70000, 88, "MEI"};
    jogador j9_5 = {"Kelvin Valdez", 0, 0, 15000, 77, "DEF"};
    goleiro g9 = {"A. Monterde", 0, 0, 23000, 81, "GOL"};
    presidente p9 = {"Zeiin", 0, 0, 61};
    valorMercado = j9_1.valor + j9_2.valor + j9_3.valor + j9_4.valor + j9_5.valor + g9.valor;
    times team9 = {9, "Persas FC", j9_1, j9_2, j9_3, j9_4, j9_5, g9, p9, 15, 12, valorMercado};
    insereABBrecursivo(raiz, team9);

    // RAniza 
    jogador j10_1 = {"Miguel Rebollo", 0, 0, 29000, 83, "ATA"};
    jogador j10_2 = {"Brihan G.", 0, 0, 15000, 77, "ATA"};
    jogador j10_3 = {"Axur Quinteto", 0, 0, 33000, 84, "MEI"};
    jogador j10_4 = {"Bryan G.", 0, 0, 15000, 77, "MEI"};
    jogador j10_5 = {"Alexis Silva", 0, 0, 70000, 87, "DEF"};
    goleiro g10 = {"Hugo Murga", 0, 0, 50000, 86, "GOL"};
    presidente p10 = {"Alana", 0, 0, 77};
    valorMercado = j10_1.valor + j10_2.valor + j10_3.valor + j10_4.valor + j10_5.valor + g10.valor;
    times team10 = {10, "Raniza FC", j10_1, j10_2, j10_3, j10_4, j10_5, g10, p10, 2, 8, valorMercado};
    insereABBrecursivo(raiz, team10);

    // Real Titan
    jogador j11_1 = {"Alberto Garcia", 0, 0, 20000, 80, "ATA"};
    jogador j11_2 = {"Jacob Lobo", 0, 0, 21000, 81, "ATA"};
    jogador j11_3 = {"Vidangossy", 0, 0, 35000, 84, "MEI"};
    jogador j11_4 = {"Pablo Samaro ", 0, 0, 13000, 77, "MEI"};
    jogador j11_5 = {"Martin Cani", 0, 0, 10000, 74, "MEI"};
    goleiro g11 = {"Erik Fraire", 0, 0, 14000, 77, "GOL"};
    presidente p11 = {"Conterstine", 0, 0, 67};
    valorMercado = j11_1.valor + j11_2.valor + j11_3.valor + j11_4.valor + j11_5.valor + g11.valor;
    times team11 = {11, "Real Titan FC", j11_1, j11_2, j11_3, j11_4, j11_5, g11, p11, 13, 8, valorMercado};
    insereABBrecursivo(raiz, team11);

    // West Santos
    jogador j12_1 = {"Alejandro Maro", 0, 0, 35000, 84, "ATA"};
    jogador j12_2 = {"Baruc Ochoa ", 0, 0, 33000, 84, "ATA"};
    jogador j12_3 = {"Jose Rochin", 0, 0, 22000, 81, "ATA"};
    jogador j12_4 = {"Jose Hernanez", 0, 0, 20000, 80, "MEI"};
    jogador j12_5 = {"F. Navarro", 0, 0, 16000, 78, "DEF"};
    goleiro g12 = {"Juan Ruiz", 0, 0, 18000, 79, "GOL"};
    presidente p12 = {"Arcangel", 0, 0, 78};
    valorMercado = j12_1.valor + j12_2.valor + j12_3.valor + j12_4.valor + j12_5.valor + g12.valor;
    times team12 = {12, "West Santos FC", j12_1, j12_2, j12_3, j12_4, j12_5, g12, p12, 15, 1, valorMercado};
    insereABBrecursivo(raiz, team12);
    
     // Galáticos Del Caribe
    jogador j3_1 = {"Kelvin Cardona", 0, 0, 65000, 88, "ATA"};
    jogador j3_2 = {"Morales", 0, 0, 23000, 82, "MEI"};
    jogador j3_3 = {"Pabel Montes", 0, 0,23000, 82, "MEI"};
    jogador j3_4 = {"Diego Franco", 0, 0, 24000, 82, "MEI"};
    jogador j3_5 = {"Shaggy", 0, 0, 20000, 80,"DEF"};
    goleiro g3 = {"Dabbah", 0, 0, 24000, 83, "GOL"};
    presidente p3 = {"Alofoke", 0, 0, 70};
    valorMercado = j3_1.valor + j3_2.valor + j3_3.valor + j3_4.valor + j3_5.valor + g3.valor;
    times team3 = {3, "Galatic Caribe", j3_1, j3_2, j3_3, j3_4, j3_5, g3, p3, 1, 4, valorMercado};
    insereABBrecursivo(raiz, team3);
}
