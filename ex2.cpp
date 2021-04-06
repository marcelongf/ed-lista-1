#include <stdio.h>
#include "./TAD.h"

class PilhaFila {
    public:
        FilaEnc* fila1;
        FilaEnc* fila2;
        size_t N;

        PilhaFila(){
            N = 0;
        }

        char top(){
            for (size_t i = 0; i < N - 1; i++) 
            {
                fila2.enfilera(fila1.desenfilera());
            }

            char c = fila1.frente();
            fila2.enfilera(fila1.desenfilera());
            fila1 = fila2;
            
            return c;
        }

        void empilha (char dado) {
            fila1.enfilera(dado);
            N++;
        };

        char desempilha () {
            for (size_t i = 0; i < N - 1; i++) {
                fila2.enfilera(fila1.desenfilera());
            }

            N--;
            return fila1.desenfilera();
        };
    
};

int main() {
    PilhaFila *stack = new PilhaFila;

    stack->empilha('x');

    stack->empilha('y');

    printf("%c \n", stack->top());
    
    stack->desempilha();

    printf("%c \n", stack->top());

    delete stack;

    return 0;
}