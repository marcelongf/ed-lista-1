#include <stdio.h>
#include "./TAD.h"

class Fila {
    public:
        Pilha q1;
        Pilha q2;
        unsigned int N;


        void enfilera(char dado) {
            q1.empilha(dado);
            N++;
        }

        char desenfilera() {
            for (size_t i = 0; i < N - 1; i++) 
            {
                q2.empilha(q1.desempilha());
            }

            char c = q1.desempilha();

            for (size_t i = 0; i < N - 1; i++) 
            {
                q1.empilha(q2.desempilha());
            }
            
            N--;
            return c;
        }

        char frente() {
            for (size_t i = 0; i < N - 1; i++) {
                q2.empilha(q1.desempilha());
            }

            char c = q1.topo();
            for (size_t i = 0; i < N - 1; i++) {
                q1.empilha(q2.desempilha());
            }
            
            return c;
        }
};

int main() {
    Fila *q = new Fila;

    q->enfilera('x');

    q->enfilera('y');

    printf("%c", q->desenfilera());

    printf("%c", q->frente());

    printf("%c", q->desenfilera());

    delete q;
    return 0;
}