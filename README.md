# Projeto Multithreading - MC504 (1s2023)

Este projeto tem como objetivo a criação de uma visualização gráfica de um problema de sincronização de múltiplas threads. O problema escolhido é o problema _River Crossing_ disponível em [The Little Book of Semaphores](https://greenteapress.com/wp/semaphores/) e a implementação da lógica de sincronização foi baseada nas estratégias e no pseudo-código apresentado neste livro.

## Colaboradores

Cícero Pizzol Libardi - **RA: 168810**\
Isabella Garcia Fagioli - **RA: 173174**\
Jéssica da Silva de Oliveira - **RA: 173931**\
Luiz Henrique Marques Gonçalves - **RA: 183218**

## Descrição do Problema

Existe um barquinho a remo que é usado por funcionários da MIcrosoft e por hackers de Linux. O barquinho atravessa um rio. Mas ele só parte da margem co exatamente 4 pessoas, nem mais, nem menos. 
Para garantir a segurança de todos, a proporção de pessoa no barco não pode ser 3:1 ou 1:3. O seja,somente as seguintes situações são possíveis:
- todas as pessoas são hacker 
- todas as pessoas são os funcionários 
- metade do barco é de funcionários e a outra metade é de hacker. 

A medida que cada thread embarca no barco, ela deve chamar uma função de embarcar, `board`, de maneira que todas as 4 therads de cada barco cheio chame essa função antes que as threads que estão esperando a próxima embarcação façam. Ou seja, uma thread só acessa `board` se ela de fato embarcou. 

Depois que todas as threads embarcarem, apenas uma delas deve chamar uma função para "remar", `rowBoat`, indicando que ela tem os remos. Não importa com thread seja. 

Não importa a direção do barco, a preocupação é controlar o tráfico de pessoas que entra e sai dos barcos. 

## Instruções de Compilação

Para a representação grafica foi utilizada a biblioteca `ncurses`.

É preciso configurar seu ambiente de compilação, instalando a biblioteca:

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

Você pode conferir maiores detalhes da documentação [aqui](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)

Para compilar e executar, na raiz do projeto, faça:

```
make
./exe
```

Caso o sistema retorne um erro de acesso não permitido, faça `chmod +rwe ./exe`

Os arquivos binários gerados encontram-se no `.gitignore`, para que cada usuário faça sua compilação em seu ambiente de desenvolvimento. 

## Implementação

### Definições globais
As variáveis `N_HACKERS`  e `N_SERFS` definem quantos Hacker e Serfs chegarão à margem até o final da execução do problema. Sendo o número de vagas que o barco exige para atravessar o rio (`N_VAGAS`) e a porcentagem mínima de cada tipo de pessoa no barco (`N_PORCENTAGEM_MÍNIMA`) podem ser alterados para o caso da versão genérica do problema (`river_crossing_generic.c`). Na versão original, `river_crossing_problem.c`, somente a quantidade de hacker e serfs podem ser alteradas. 

Portanto, a versão final implementada é `river_crossing_generic.c`, uma vez que ela pode ser configurada para conter o caso original descrito em `river_crossing_problem.c`

### Uso dos semáfaros

Para a implementação das funcionalidades das threads, criamos os semáfaros:

```C
pthread_barrier_t barrier;
sem_t mutex;
sem_t serf_queue;
sem_t hacker_queue;
```

#### barrier

Espera até que o número `N_VAGAS` de threads estejam prontas para partir, ou seja, para que o capitão execute a função de remar. 

#### mutex

Controla as threads sassim que são criadas e passam a executar a respectiva função passada para `pthread_create`. Assim, uma thread por vez pode chegar à margem. 

#### queue

Controla a fila de pessoas que estão esperando para entrar no barco. Cada thread, antes de embarcar, espera esse semáfaro para chegar à função de embarque. 


### Funcionamento Geral do Código

A função `pthread_barrier_init` é inicializada com o valor de barreira igual ao número máximo de pessoas no barco. 

Os semáfaros são inicializados e dois vetores de threads (uma para serfs e outra para hackers) são criados. 

Para estabelecer uma aleatoriadade para o intervalo e o tipo de pessoa que chega à margem, as threads são criadas seguindo um padrão aleatório e com valores de `sleep` também aleatórios, simulando uma chegada diferente a cada execução. Elas são declaradas e inicializadas até que as quantidades `N_HACKERS`  e `N_SERFS` sejam atingidas.

As funções executadas por cada thread são:

```C
void *thread_hackers();
void *thread_serfs();
```
Elas apresentam implementações espelhadas. Por isso, explicamos com pseudocódigo uma versão genérica que funciona para as duas: 

```C
void *thread_hackers(){
    waitMutex();
    newHackerArrived();
    if("existe condições de embarque"){
        for("cada pessoa esperando para embarcar"){
            semPostQueue();
        }
    }
    else {
        semPostMutex();
    }
    waitFila();
    board();
    waitBarrier();

    if("é capitão"){
        rowBoat();
        semPostMutex();
    }
}

```

Assim, cada vez que um thread é criada, ela espera o mutex para chegar no porto.
    - Se há condições para embarcar, ou seja, o número e a configurações de pessoas esperando para embarcar é compatível com o embarque, as pessoas que estão o semáfaro para embarcar são liberadas.
    - Senão, o mutex é liberado para que outras pessoas cheguem ao porto
Após isso, a thread que chegou espera o semáfaro de fila liberar para que ela embarque. Após isso, esperamos a barreira atingir o número de vagas do barco para liberar a partida do barco, que ocorrer quando o capitão rema.  

## Representação Gráfica

A implementação é feita no arquivo `river_image.c`. Usamos "prints" para imprimir linha a linha o estado global da aplicação.

Para limpara o console e dar efeito de animação, bem como colorir a imagem, a biblioteca `ncurses` foi usada. 

A versão gráfica é disponível somente para o arquivo `river_crossing_generic.c`. 

Abaixo mostramos alguns exemplos da representação para diferentes configurações do problema. 

_colocar prints_




