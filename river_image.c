#include <stdio.h>
#include <ncurses.h>
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
        printw("="); 
    }
    printw("|\n");

    //título
    int espac_serf = ((ESPACOS-11)/2);
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("Microsofter"); 
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("|\n");

    //cabeças
    int espac_cabeca = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        printw("   ");
        attron(COLOR_PAIR(2));
        printw("O"); 
        attroff(COLOR_PAIR(2));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        if(i==0){
            printw("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printw(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
        attroff(COLOR_PAIR(2));
        
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<ESPACOS+4;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    //pernas
    int espac_pernas = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        if(i==0){
            printw("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printw(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
        attroff(COLOR_PAIR(2));
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<ESPACOS+3;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //caminho pro barco
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("|____");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS-2;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<2*ESPACOS+2;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw(" ____");
    for(int i=0;i<ESPACOS-4;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<ESPACOS-1;i++){
        attron(COLOR_PAIR(4));
        printw("_");
        attroff(COLOR_PAIR(4));
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //título
    int espac_hackers = ((ESPACOS-7)/2);
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("Hackers"); 
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("|");
    attron(COLOR_PAIR(1));
    //rio
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //cabeças
    espac_cabeca = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        attron(COLOR_PAIR(3));
        printw("   O"); 
        attroff(COLOR_PAIR(3));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 

    //corpinho
    espac_corpinho = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            attron(COLOR_PAIR(3));
            printw("  -|-"); 
            attroff(COLOR_PAIR(3));
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            attron(COLOR_PAIR(3));
            printw(" -|-"); 
            attroff(COLOR_PAIR(3));
            espac_corpinho = espac_corpinho - 4;
        }
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");

    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //pernas
    espac_pernas = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            attron(COLOR_PAIR(3));
            printw("  / \\"); 
            attroff(COLOR_PAIR(3));
            espac_pernas = espac_pernas - 5;
        }
        else{
            attron(COLOR_PAIR(3));
            printw(" / \\"); 
            attroff(COLOR_PAIR(3));
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //base
    for(int i = 0;i<ESPACOS;i++){
        printw("="); 
    }
    printw("|\n");
}

void remando(int nhackers, int nserfs, int hackers_barco, int serfs_barco, int estagio){
    //topo
    for(int i = 0;i<ESPACOS;i++){
        printw("="); 
    }
    printw("|\n");

    //título
    int espac_serf = ((ESPACOS-11)/2);
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("Microsofter"); 
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("|\n");

    //cabeças
    int espac_cabeca = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        printw("   O"); 
        attroff(COLOR_PAIR(2));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i=0;i<nserfs;i++){
        if(i==0){
            printw("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printw(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
        
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<estagio*ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS+4;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    //pernas
    int espac_pernas = ESPACOS;
    for(int i=0;i<nserfs;i++){
        if(i==0){
            printw("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printw(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("| ");
    for(int i=0;i<estagio*ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS+2;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //caminho pro barco
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw("|__");
    for(int i=0;i<estagio*ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS+2;i++){
        printw(" ");
    }
    printw(" |");
    for(int i=0;i<estagio*ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    int barco_cabeca = ESPACOS - 2;
    //cabeças hackers dentro
    for(int i=0;i<hackers_barco;i++){
        attron(COLOR_PAIR(3));
        printw("   O");
        attroff(COLOR_PAIR(3));
        barco_cabeca = barco_cabeca - 4;
    }
    //cabeças serfs dentro
    for(int i=0;i<serfs_barco;i++){
        attron(COLOR_PAIR(2));
        printw("   O");
        attroff(COLOR_PAIR(2));
        barco_cabeca = barco_cabeca - 4;
    }
    for(int i=0;i<barco_cabeca;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw(" __| ");
    for(int i=0;i<estagio*ESPACOS;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    int barco_corpinhos = ESPACOS - 4;
    //corpinho hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printw(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    //corpinho serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printw(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    for(int i=0;i<barco_corpinhos;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<(5 + estagio*ESPACOS);i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("\\");
    attroff(COLOR_PAIR(4));
    int barco_pernas = ESPACOS - 6;
    //pernas hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printw("/ \\");
        attron(COLOR_PAIR(4));
        printw("_");
        attroff(COLOR_PAIR(4));
        barco_pernas = barco_pernas - 4;
    }
    //pernas serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printw("/ \\");
        printw("_");
        barco_pernas = barco_pernas - 4;
    }
    for(int i=0;i<barco_pernas;i++){
        attron(COLOR_PAIR(4));
        printw("_");
        attroff(COLOR_PAIR(4));
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //título
    int espac_hackers = ((ESPACOS-7)/2);
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("Hackers"); 
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //cabeças
    espac_cabeca = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        attron(COLOR_PAIR(3));
        printw("   O"); 
        attroff(COLOR_PAIR(3));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 

    //corpinho
    espac_corpinho = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printw("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printw(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");

    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //pernas
    espac_pernas = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printw("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printw(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //base
    for(int i = 0;i<ESPACOS;i++){
        printw("="); 
    }
    printw("|\n");
}

void embarca(int nhackers, int nserfs, int hackers_barco, int serfs_barco, int estagio){
    //topo
    for(int i = 0;i<ESPACOS;i++){
        printw("="); 
    }
    printw("|\n");

    //título
    int espac_serf = ((ESPACOS-11)/2);
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("Microsofter"); 
    for(int i=0;i<espac_serf;i++){
        printw(" ");
    }
    printw("|\n");

    //cabeças
    int espac_cabeca = ESPACOS;
    for(int i = 0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        printw("   O"); 
        attroff(COLOR_PAIR(2));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|\n");

    //corpinho
    int espac_corpinho = ESPACOS;
    for(int i=0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        if(i==0){
            printw("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printw(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
        attroff(COLOR_PAIR(2));
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");
    for(int i=0;i<ESPACOS + 5;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    //pernas
    int espac_pernas = ESPACOS;
    for(int i=0;i<nserfs;i++){
        attron(COLOR_PAIR(2));
        if(i==0){
            printw("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printw(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
        attroff(COLOR_PAIR(2));
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("| ");
    for(int i=0;i<ESPACOS+3;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //caminho pro barco
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw("|____");
    for(int i=0;i<ESPACOS-1;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS+5;i++){
        printw(" ");
    }
    int barco_cabeca = ESPACOS - 2;
    //cabeças hackers dentro
    for(int i=0;i<hackers_barco;i++){
        attron(COLOR_PAIR(2));
        printw("   O");
        attroff(COLOR_PAIR(2));
        barco_cabeca = barco_cabeca - 4;
    }
    //cabeças serfs dentro
    for(int i=0;i<serfs_barco;i++){
        attron(COLOR_PAIR(3));
        printw("   O");
        attroff(COLOR_PAIR(3));
        barco_cabeca = barco_cabeca - 4;
    }
    for(int i=0;i<barco_cabeca;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }
    printw(" ____ ");
    int barco_corpinhos = ESPACOS - 4;
    //corpinho hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printw(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    //corpinho serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printw(" -|-");
        barco_corpinhos = barco_corpinhos - 4;
    }
    for(int i=0;i<barco_corpinhos;i++){
        printw(" ");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));
    for(int i=0;i<ESPACOS;i++){
        printw(" ");
    }

    printw("|______");
    int barco_pernas = ESPACOS - 6;
    //pernas hackers dentro
    for(int i=0;i<hackers_barco;i++){
        printw("/ \\");
        printw("_");
        barco_pernas = barco_pernas - 4;
    }
    //pernas serfs dentro
    for(int i=0;i<serfs_barco;i++){
        printw("/ \\");
        printw("_");
        barco_pernas = barco_pernas - 4;
    }
    for(int i=0;i<barco_pernas;i++){
        printw("_");
    }
    attron(COLOR_PAIR(4));
    printw("/\n");
    attroff(COLOR_PAIR(4));

    //título
    int espac_hackers = ((ESPACOS-7)/2);
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("Hackers"); 
    for(int i=0;i<espac_hackers;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //cabeças
    espac_cabeca = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        attron(COLOR_PAIR(3));
        printw("   O"); 
        attroff(COLOR_PAIR(3));
        espac_cabeca = espac_cabeca - 4;
    }
    for(int i=0;i<espac_cabeca;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 

    //corpinho
    espac_corpinho = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printw("  -|-"); 
            espac_corpinho = espac_corpinho - 5;
        }
        else{
            printw(" -|-"); 
            espac_corpinho = espac_corpinho - 4;
        }
    }
    for(int i=0;i<espac_corpinho;i++){
        printw(" ");
    }
    printw("|");

    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //pernas
    espac_pernas = ESPACOS;
    for(int i = 0;i<nhackers;i++){
        if(i==0){
            printw("  / \\"); 
            espac_pernas = espac_pernas - 5;
        }
        else{
            printw(" / \\"); 
            espac_pernas = espac_pernas - 4;
        }
    }
    for(int i=0;i<espac_pernas;i++){
        printw(" ");
    }
    printw("|");
    //rio
    attron(COLOR_PAIR(1));
    for(int i=0;i<RIO;i++){
        printw("~");
    }
    attroff(COLOR_PAIR(1));
    printw("\n"); 
    //base
    for(int i = 0;i<ESPACOS;i++){
        printw("="); 
    }
    printw("|\n");
}