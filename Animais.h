#ifndef ANIMAIS_H_INCLUDED
#define ANIMAIS_H_INCLUDED

//Já cria a estrutura e nomeia a mesma
typedef struct animal
{
    //N° da pista em qual o animal está
    int casa;
    //Ponteiros para interligar a Lista-Duplamente-Encadeada
    struct animal *prox;
    struct animal *ant;
    //Novo nome da estrutura
}Animal;

//Cria a estrutura da qual os animais andarão
Animal* Criar_pista(Animal **move);

//Movimenta para frente
void Andar_para_frente(Animal **move, int n);

//Movimenta para trás
void Andar_para_tras(Animal **move, int n);

//Função para liberar a lista
void liberarLista(Animal *head);

#endif // LISTAS_H_INCLUDED
