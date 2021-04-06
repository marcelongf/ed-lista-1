#include <stdio.h>
#include "./TAD.h"
//A
int main() {
    Pilha *s = new Pilha;

    for (char i = 'a'; i < 'e'; i++) 
    {
        s->empilha(i);
    }

    FilaEnc *fila = new FilaEnc;
    for (char i = 'a'; i < 'e'; i++) 
    {
        fila->enfilera(s->desempilha());
    }

    for (char i = 'a'; i < 'e'; i++) 
    {
        s->empilha(fila->desenfilera());
    }
    
    delete fila;
    delete s;

    return 0;
}

//B
int main() {
    Pilha *s = new Pilha;

    for (char i = 'a'; i < 'e'; i++) {
        s->empilha(i);
    }

    Pilha *pilha1 = new Pilha;
    Pilha *pilha2 = new Pilha;

    for (size_t i = 0; i < 5; i++) 
    {
        pilha1->empilha(s->desempilha());
    }

    for (size_t i = 0; i < 5; i++) 
    {
        pilha2->empilha(pilha1->desempilha());
    }

    for (size_t i = 0; i < 5; i++) 
    {
        s->empilha(pilha2->desempilha());
    }

    delete pilha1;
    delete pilha2;
    delete s;

    return 0;
}

//C
int main() {
    Pilha *s = new Pilha;
   
    for (char i = 'a'; i < 'e'; i++) 
    {
        s->empilha(i);
    }

    Pilha *aux = new Pilha;

    for (size_t i = 0; i < 5; i++) 
    {
        aux->empilha(s->desempilha());
    }

    s = aux;

    delete aux;
    delete s;

    return 0;
}