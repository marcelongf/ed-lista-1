#include <stdio.h>
#include "./TAD.h"

class No {
    public:
        int dado;
        No *prevReferencia;
        No *nextReferencia;

        No(int e){
            dado = e;
            prevReferencia = 0;
            nextReferencia = 0;
        }
};

class PilhaMin {
    public:
        Pilha p;
        No *min;
        No *prevMin;
        No *firstIdx;
        No *lastIdx;

        PilhaMin(){
            min = 0;
            prevMin = 0;
            firstIdx = 0;
            lastIdx = 0;
        };

        void empilha(char dado) {
            No *novo = new No{dado};

            if(firstIdx == 0 && lastIdx == 0) 
            {
                firstIdx = novo;
                lastIdx = novo;
                min = lastIdx;

                return;
            }
            else 
            {
                novo->prevReferencia = lastIdx;
                lastIdx->nextReferencia = novo;

                lastIdx = novo;

                if (lastIdx->dado < min->dado) {
                    prevMin = min;
                    min = lastIdx;
                }
            }

            return;
        }

        int topo() {
            int i = lastIdx->dado;
            return i;
        }

        int desempilha() {
            if (lastIdx == min) {
                min = prevMin;
            }
            
            if (lastIdx == firstIdx) {
                int c = lastIdx->dado;

                delete lastIdx;
                delete firstIdx;

                firstIdx = 0;
                lastIdx = 0;

                return c;
            }
            else {
                No *novo_ultimo = lastIdx->prevReferencia;
                int c = lastIdx->dado;

                delete lastIdx;
                lastIdx = novo_ultimo;

                return c;
            }
        }

        No *obterMinimo() {
            return min;
        }
};

int main() {
    PilhaMin *s = new PilhaMin;

    s->empilha(6);
    
    s->empilha(4);
    
    s->desempilha();

    delete s;
    return 0;
}