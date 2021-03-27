#ifndef LISTAPONTO_H
#define LISTAPONTO_H
#include "Ponto.h"

class ListaPonto
{
    private:
        int max;
        int n;
        Ponto *vet;

    public:
        ListaPonto(int tam);
        ~ListaPonto();

        Ponto get(int k);
        void set(int k, float x, float y);
        void insereFinal(float x, float y);
        void insereK(int k, float x, float y);
        void insereInicio(float x, float y);
        void removeFinal();
        void removeK(int k);
        void removeInicio();
        void imprime();
        int numNos();
        void limpar();
        void imprimeDistancia();
};


#endif // LISTAPONTO_H
