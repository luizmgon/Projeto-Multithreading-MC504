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

## Representação Gráfica

_completar com alguns prints e descrições da representação gráfica do problema_
