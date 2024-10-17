#ifndef ANIMAIS_H_INCLUDED
#define ANIMAIS_H_INCLUDED

//J� cria a estrutura e nomeia a mesma
typedef struct animal
{
    //N� da pista em qual o animal est�
    int casa;
    //Ponteiros para interligar a Lista-Duplamente-Encadeada
    struct animal *prox;
    struct animal *ant;
    //Novo nome da estrutura
}Animal;

//Cria a estrutura da qual os animais andar�o
Animal* Criar_pista(Animal **move);

//Movimenta para frente
void Andar_para_frente(Animal **move, int n);

//Movimenta para tr�s
void Andar_para_tras(Animal **move, int n);

//Fun��o para liberar a lista
void liberarLista(Animal *head);

#endif // LISTAS_H_INCLUDED
