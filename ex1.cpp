#include <stdio.h>
#include "./TAD.h"

int main() {
    DeckEnc *deck = new DeckEnc;

    deck->insereFim('x');

    deck->insereInicio('y');

    deck->removeInicio();

    deck->insereFim('z');

    deck->removeFim();

    deck->insereInicio('w');

    printf("%c", deck->buscaInicio());
    printf("%c", deck->buscaFim());

    delete deck;
}