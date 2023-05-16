#include <stdio.h>
#define ESPACOS 25
#define RIO 75


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
                      |    \                                /
                      |     \                              /
                      |__    \        M   H   M   H       /
                         |    \       O   O   O   O      /
                       __|     \     -|- -|- -|- -|-    /
                      |	        \____/ \_/ \_/ \_/ \___/
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
    for(int i;i<nserfs;i++){
        printf("   O"); 
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printf(" ");
    }
    printf("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i;i<nserfs;i++){
        if(i==0){
            printf("  -|-"); 
        }
        else{
            printf(" -|-"); 
        }
        espac_corpinho = espac_corpinho - 5;
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
    for(int i;i<nserfs;i++){
        if(i==0){
            printf("  / \\"); 
        }
        else{
            printf(" / \\"); 
        }
        espac_pernas = espac_pernas - 5;
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
    for(int i;i<nhackers;i++){
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
    for(int i;i<nhackers;i++){
        if(i==0){
            printf("  -|-"); 
        }
        else{
            printf(" -|-"); 
        }
        espac_corpinho = espac_corpinho - 5;
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
    for(int i;i<nhackers;i++){
        if(i==0){
            printf("  / \\"); 
        }
        else{
            printf(" / \\"); 
        }
        espac_pernas = espac_pernas - 5;
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