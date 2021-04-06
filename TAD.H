#ifndef TAD_H

#define TAD_H
#define MAX 5

#include <stdio.h>
#include <string.h>

class No {
    public:
        char dado;
        No *prevReferencia;
        No *nextReferencia;

        No(char e){
            dado = e;
            prevReferencia = nullptr;
            nextReferencia = nullptr;
        }
};

class FilaSeq {
    public:
        int N;
        char itens[MAX];

        void cria() {
            this->N = 0;
            this->itens = 0;
        };

        void enfilera(char dado) {
            this->itens[N] = dado;
            this->N++;
        };

        char desenfilera() {
            char c = this->front();

            for (int i = 0; i < N-1 ; i++) {
                this->itens[i] = this->itens[i + 1];
                this->N--;
            };
            return c;
        };

        char front() {
            return this->itens[0];
        };
};

class DeckEnc {
    public:
        No *firstIdx;
        No *lastIdx;

        DeckEnc(){
            firstIdx = nullptr;
            lastIdx = nullptr;
        };

        void insereFim(char dado) {
            No *novo = new No{dado};

            if(firstIdx == nullptr && lastIdx == nullptr) {
                firstIdx = novo;
                lastIdx = novo;

                return;
            }
            else {
                novo->prevReferencia = lastIdx;
                lastIdx->nextReferencia = novo;

                lastIdx = novo;
            }
        };

        void insereInicio(char dado) {
            No *novo = new No{dado};

            if(firstIdx == nullptr && lastIdx == nullptr) {
                firstIdx = novo;
                lastIdx = novo;

                return;
            }
            else {
                novo->nextReferencia = firstIdx;
                firstIdx->prevReferencia = novo;

                firstIdx = novo;
            }
        };

        char removeFim() {
            if (lastIdx == firstIdx) {
                char c = lastIdx->dado;

                delete lastIdx;
                delete firstIdx;

                firstIdx = nullptr;
                lastIdx = nullptr;

                return c;
            }
            else {
                No *novo_ultimo = lastIdx->prevReferencia;
                char c = lastIdx->dado;

                delete lastIdx;
                lastIdx = novo_ultimo;

                return c;
            }
        };

        char removeInicio() {
            if (lastIdx == firstIdx) {
                char c = firstIdx->dado;

                delete lastIdx;
                delete firstIdx;

                firstIdx = nullptr;
                lastIdx = nullptr;

                return c;
            }
            else {
                No *novo_inicio = firstIdx->nextReferencia;
                char c = firstIdx->dado;

                delete firstIdx;
                firstIdx = novo_inicio;

                return c;
            }
        };

        char buscaInicio () {
            int i = firstIdx->dado;
            return i;
        }

        char buscaFim () {
            int i = lastIdx->dado;
            return i;
        }
};

class FilaEnc {
    public:
        DeckEnc d;

        void enfilera(char dado) {
            d.insereFim(dado);
        }

        char desenfilera() {
            return d.removeInicio();
        }

        char front() {
            return d.buscaInicio();
        }

        void destroi() {
            while (this->front() != '\0') {
                d.removeInicio();
            }
            
        }
};

class DequeSeq {
    public:
        unsigned int N;
        char itens[MAX];

        void novo() {
            this->N = 0;
            this->itens = 0;
        };

        void insereFim(char dado) {
            this->itens[tam] = dado;
            this->tam++;
        };

        void insereInicio(char dado) {
            if (this->itens[0] == '\0') {
                printf("primeiro elemento era nulo");
                this->itens[0] = dado;
            }
            else {
                char temp[MAX] = 0;
                temp[0] = dado;
                
                for (size_t i = 1; i < this->tam + 1; i++) {
                    temp[i] = this->itens[i - 1];
                };

                memcpy(itens, temp, MAX * sizeof(char));
            }

            this->tam++;
        };

        void removeFim() {
            this->itens[tam - 1] = '\0';
            this->tam--;
        };

        void removeInicio() {
            for (size_t i = 0; i < tam; i++) {
                this->itens[i] = this->itens[i + 1];
            };

            this->tam--;
        };

        char buscaInicio () {
            char c = this->itens[0];
            return c;
        }

        char buscaFim () {
            char c = this->itens[tam - 1];
            return c;
        }

        
};

class Pilha {
    public:
        DeckEnc d;

        void empilha(char dado) {
            d.insereFim(dado);
        }

        char topo() {
            return d.buscaFim();
        }

        char desempilha() {
            return d.removeFim();
        }
};

#endif