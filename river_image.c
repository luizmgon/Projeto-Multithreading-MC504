#include <stdio.h>
#define ESPACOS 25
#define RIO 100


/* O desenho deve ter o seguinte formato:
  Esperando
======================|
    Microsofter       |
   O   O              |                                       
  -|- -|-             |                            /
  / \ / \             |                           /
                      |____                      /
                                                /
                       ____                    /
                      |	______________________/
      Hackers         |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   O   O              |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  -|-  -|-           |
  / \  / \           |
======================|

Barquinho em movimento
======================|
    Microsofter       |
                      |                                       
                      |\                                /
                      | \                              /
                      |__\        M   H   M   H       /
                         |\       O   O   O   O      /
                       __| \     -|- -|- -|- -|-    /
                      |	    \____/ \_/ \_/ \_/ \___/
      Hackers         |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      |
                      |
======================|
 **/


void estado_atual_chegada(int nhackers, int nserfs){
    //topo
    for(int i = 0;i<ESPACOS;i++){
        printf("="); 
    }
    printf("|\n");

    //título
    int espac_serf = ((ESPACOS-11)/2);
    for(int i=0;i<espac_serf;i++){
        printf(" ");
    }
    printf("Microsofter"); 
    for(int i=0;i<espac_serf;i++){
        printf(" ");
    }
    printf("|\n");

    //cabeças
    int espac_cabeca = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        printf("   O"); 
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printf(" ");
    }
    printf("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        if(i==0){
            printf("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printf(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
        
    }
    for(int i=0;i<espac_corpinho;i++){
        printf(" ");
    }
    printf("|");
    for(int i=0;i<ESPACOS+4;i++){
        printf(" ");
    }
    printf("/\n");
    //pernas
    int espac_pernas = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        if(i==0){
            printf("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printf(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printf(" ");
    }
    printf("|");
    for(int i=0;i<ESPACOS+3;i++){
        printf(" ");
    }
    printf("/\n");

    //caminho pro barco
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf("|____");
    for(int i=0;i<ESPACOS-2;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<2*ESPACOS+2;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf(" ____");
    for(int i=0;i<ESPACOS-4;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf("|");
    for(int i=0;i<ESPACOS-1;i++){
        printf("_");
    }
    printf("/\n");

    //título
    int espac_hackers = ((ESPACOS-7)/2);
    for(int i=0;i<espac_hackers;i++){
        printf(" ");
    }
    printf("Hackers"); 
    for(int i=0;i<espac_hackers;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //cabeças
    espac_cabeca = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        printf("   O"); 
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 

    //corpinho
    espac_corpinho = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printf("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printf(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
    }
    for(int i=0;i<espac_corpinho;i++){
        printf(" ");
    }
    printf("|");

    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //pernas
    espac_pernas = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printf("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printf(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //base
    for(int i = 0;i<ESPACOS;i++){
        printf("="); 
    }
    printf("|\n");
}

void remando(int nhackers, int nserfs, int hackers_barco, int serfs_barco, int estagio){
    //topo
    for(int i = 0;i<ESPACOS;i++){
        printf("="); 
    }
    printf("|\n");

    //título
    int espac_serf = ((ESPACOS-11)/2);
    for(int i=0;i<espac_serf;i++){
        printf(" ");
    }
    printf("Microsofter"); 
    for(int i=0;i<espac_serf;i++){
        printf(" ");
    }
    printf("|\n");

    //cabeças
    int espac_cabeca = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        printf("   O"); 
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printf(" ");
    }
    printf("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i=0;i<nserfs;i++){
        if(i==0){
            printf("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printf(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
        
    }
    for(int i=0;i<espac_corpinho;i++){
        printf(" ");
    }
    printf("|");
    for(int i=0;i<estagio*ESPACOS;i++){
        printf(" ");
    }
    printf("\\");
    for(int i=0;i<ESPACOS+4;i++){
        printf(" ");
    }
    printf("/\n");
    //pernas
    int espac_pernas = ESPACOS;
    for(int i=0;i<nserfs;i++){
        if(i==0){
            printf("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printf(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printf(" ");
    }
    printf("| ");
    for(int i=0;i<estagio*ESPACOS;i++){
        printf(" ");
    }
    printf("\\");
    for(int i=0;i<ESPACOS+2;i++){
        printf(" ");
    }
    printf("/\n");

    //caminho pro barco
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf("|__");
    for(int i=0;i<estagio*ESPACOS;i++){
        printf(" ");
    }
    printf("\\");
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<ESPACOS+2;i++){
        printf(" ");
    }
    printf(" |");
    for(int i=0;i<estagio*ESPACOS;i++){
        printf(" ");
    }
    printf("\\");
    int barco_cabeca = ESPACOS - 2;
    //cabeças hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printf("   O");
        barco_cabeca = barco_cabeca - 4;
    }
    //cabeças serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printf("   O");
        barco_cabeca = barco_cabeca - 4;
    }
    for(int i=0;i<barco_cabeca;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf(" __| ");
    for(int i=0;i<estagio*ESPACOS;i++){
        printf(" ");
    }
    printf("\\");
    int barco_corpinhos = ESPACOS - 4;
    //corpinho hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printf(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    //corpinho serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printf(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    for(int i=0;i<barco_corpinhos;i++){
        printf(" ");
    }
    printf("/\n");
    for(int i=0;i<ESPACOS;i++){
        printf(" ");
    }
    printf("|");
    for(int i=0;i<(5 + estagio*ESPACOS);i++){
        printf(" ");
    }
    printf("\\");
    int barco_pernas = ESPACOS - 6;
    //pernas hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printf("/ \\");
        printf("_");
        barco_pernas = barco_pernas - 4;
    }
    //pernas serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printf(" -|-");
        barco_pernas = barco_pernas - 4;
    }
    for(int i=0;i<barco_pernas;i++){
        printf("_");
    }
    printf("/\n");

    //título
    int espac_hackers = ((ESPACOS-7)/2);
    for(int i=0;i<espac_hackers;i++){
        printf(" ");
    }
    printf("Hackers"); 
    for(int i=0;i<espac_hackers;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //cabeças
    espac_cabeca = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        printf("   O"); 
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 

    //corpinho
    espac_corpinho = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printf("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printf(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
    }
    for(int i=0;i<espac_corpinho;i++){
        printf(" ");
    }
    printf("|");

    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //pernas
    espac_pernas = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printf("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printf(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printf(" ");
    }
    printf("|");
    //rio
    for(int i=0;i<RIO;i++){
        printf("~");
    }
    printf("\n"); 
    //base
    for(int i = 0;i<ESPACOS;i++){
        printf("="); 
    }
    printf("|\n");
}