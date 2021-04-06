#include <stdio.h>
#include "./TAD.h"

int main() {
    FilaEnc *q = new FilaEnc;

    for (char i = 'a'; i < 'e'; i++) {
        q->enfilera(i);
    }   

    Pilha *s = new Pilha;

    for (char i = 'a'; i < 'e'; i++) 
    {
        s->empilha(q->desenfilera());
    }

    for (char i = 'a'; i < 'e'; i++) 
    {
        q->enfilera(s->desempilha());
    }
    
    delete s;
    delete q;

    return 0;
}

//----------------------------//B
int main() {
    FilaEnc *q = new FilaEnc;

    for (char i = 'a'; i < 'e'; i++) 
    {
        q->enfilera(i);
    }

    FilaEnc *q1 = new FilaEnc;
    FilaEnc *q2 = new FilaEnc;
    int size = 4;
    
    for (size_t i = 0; i < 5; i++)
    {
        q1->enfilera(q->desenfilera());
    }
    

    while (size != -1) {
        for (size_t i = 0; i < size; i++) 
        {
            q2->enfilera(q1->desenfilera());
        }
        q->enfilera(q1->desenfilera());
        q1 = q2;

        size--;
    }

    delete q;
    return 0;
}