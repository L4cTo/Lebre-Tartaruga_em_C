#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Animais.h"

//antes de tudo a expressão .c q vem acompanhado com o header não está funcionando em meu computador,
// por isso tive que usar tudo no main.

int giro_de_dados();

int main()
{
    //criando as variaveis tanto ponteiros quanto variaveis em si
    Animal *lebre, *tartaruga, *pista = NULL;
    int result_d;

    //cria a pista
    pista = Criar_pista(&pista);

    //a lebre e a tartaruga recebem a pista agora podendo andar sobre ela
    lebre = tartaruga = pista;

    //a casa da lebre e da tartaruga e inicializada com 1
    lebre->casa = 1;
    tartaruga->casa = 1;

    printf("\nCorredores na suas marcas\n(TARTARUGA/CASA :%d)\n", tartaruga->casa);
    printf("\nCorredores na suas marcas\n(LEBRE/CASA :%d)\n", lebre->casa);
    printf("\n\n-----------------INICIO-------------\n\n");

    //pequeno pause para fazer a função rand alterar o valor
    system("PAUSE");
    do
    {
        //gira o dado indo de 1 á 10
        result_d = giro_de_dados();

        //mostra o resultado do dado
        printf("\n%d\n", result_d);

        //pega o resultado
        switch (result_d)
        {
        case 1:
            //faz o comando de cada resultado, mostrando a casa e o animal a qual esse comando foi solicitado
            Andar_para_tras(&lebre, 2);
            printf("Escorregao!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            printf("Descanso!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);

            //logo após isso denovo pausa o comando e gira o dado mudando assim o resultado
            system("PAUSE");
            result_d = giro_de_dados();
            break;
        case 2:
            printf("Soneca!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            printf("Descanso!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 3:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            printf("Soneca!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");

            break;
        case 4:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_tras(&lebre, 1);
            printf("Pequeno Escorregao!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 5:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 1);
            printf("Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 6:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 1);
            printf("Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 7:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 1);
            printf("Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 8:
            Andar_para_frente(&tartaruga, 1);
            printf("Avanco!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 1);
            printf("Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 9:
            Andar_para_frente(&tartaruga, 2);
            printf("Avanco medio!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 3);
            printf("Grande Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        case 10:
            Andar_para_frente(&tartaruga, 2);
            printf("Avanco medio!!\t(TARTARUGA/CASA :%d)\n", tartaruga->casa);
            Andar_para_frente(&lebre, 3);
            printf("Grande Avanco!!\t(LEBRE/CASA :%d)\n", lebre->casa);
            result_d = giro_de_dados();
            system("PAUSE");
            break;
        }
        if (lebre->casa == 10)
        {
            //uma forma que achei de encerrar o programa de maneira rapida e também já libera a memoria criada com o malloc
            printf("\n----------------FIM-------------\n");
            printf("\nVencedor: LEBRE!!!!\n");
            liberarLista(pista);
            return 0;
        }
        else
        {
            if(tartaruga->casa == 10)
            {
                printf("\n----------------FIM-------------\n");
                printf("\nVencedor: TARTARUGA!!!!\n");
                liberarLista(pista);
                return 0;
            }
        }
    } while (lebre->casa <= 9 || tartaruga->casa <= 9);
    return 0;
}

int giro_de_dados()
{
    int i;

    //inicializa uma sementa com o comando rand de acordo com o timer do computador
    srand(time(NULL));

    //estabelece um limite (1-10) dentro dos numeros aleatorios
    i = rand() % 10 + 1;

    //retorna o resultado
    return i;
}

void liberarLista(Animal *move)
{
    //um ponteiro recee a pista
    Animal *atual = move;

    //ponteiro auxiliar para andar pela lista
    Animal *proximo;

    //enquanto a lista não for vazia
    while (atual != NULL)
    {
        //o auxiliar recebe o proximo valor da atual
        proximo = atual->prox;

        //a atual é liberada
        free(atual);

        //e a atual (agora vazia) recebe o valor do auxiliar logo dando 1 passo
        atual = proximo;
    }
}

Animal *Criar_pista(Animal **move)
{
    //criando indice
    int i;

    //criando ponteiro para criar a pista
    Animal *novo;

    //for para fixar o tamanho da pista
    for (i = 10; i > 0; i--)
    {
        //alocando memoria
        novo = (Animal *)malloc(sizeof(Animal));

        //se foi alocado a memoria de maneira correta
        if (novo)
        {
            //cada nó da lista recebe 1 valor de 1-10
            novo->casa = i;

            //faz o novo apontar para a antiga pista(inserir no inicio)
            novo->prox = *move;

            //faz o novo apontar para traz e esse nó é vazio(inserir no inicio)
            novo->ant = NULL;

            //se já existe um ou mais nós nessa pista o novo recebe o primeiro
            if (*move)
            {
                (*move)->ant = novo;
            }

            //a pista agora é tem o novo nó nela
            *move = novo;
        }
        //se não
        else
        {
            printf("Erro ao alocar memoria!!\n");
        }
    }
    //retorna a pista criada
    return *move;
}

void Andar_para_frente(Animal **move, int n)
{
    //cria um ponteiro para mover
    Animal *movimentos;

    //cria indice
    int i;

    //o ponteiro aponta na pista
    movimentos = *move;

    //fixa a quantidade de passos são precisos
    for (i = 0; i < n; i++)
    {
        //olha se a lista ainda existe
        if (movimentos->prox != NULL)
        {
            //anda para frente
            movimentos = movimentos->prox;

            //ponteiro (lebre/tartaruga) recebem esse passo
            *move = movimentos;
        }
        //se a lista acabou
        else
        {
            //termina a corrida
            printf("\nCorrida terminada!!\n");
            break;
        }
    }
}

void Andar_para_tras(Animal **move, int n)
{
    //cria um ponteiro para andar
    Animal *Movimentos;

    //cria o indice
    int i;

    //o ponteiro de andar recebe (lebre/tartaruga)
    Movimentos = *move;

    //olha se a pista anterior exite
    if (Movimentos->ant != NULL)
    {
        //faz os "passos" a quantidade exigida
        for (i = 0; i < n; i++)
        {
            //novamente olha se a pista existe
            if (Movimentos->ant != NULL)
            {
                //anda o ponteiro 1 passo para traz
                Movimentos = Movimentos->ant;

                //os ponteiros (lebre/tartaruga) recebem esse passo
                *move = Movimentos;
            }
            //se a pista não existe mais
            else
            {
                //avisa que a pista esta no seu 1° nó
                printf("\nO animal esta no inicio da pista\n");
                break;
            }
        }
    }
    //da mesma forma olha se a pista não existe mais
    else
    {
        //avisa que o animal está no seu 1° nó
        printf("\nO animal está no inicio da pista!!\n");
    }
}
