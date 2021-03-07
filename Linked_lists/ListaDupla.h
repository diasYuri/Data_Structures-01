#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val);
    void removeFinal();
    void imprime();
    void imprimeReverso();
    ListaDupla* concatena(ListaDupla *l2);
    ListaDupla* partir(int x);
    void removeOcorrencias(int val);
    void inserek(int val, int k);
    void removek(int k);
    void trocaKProximo(int k);
    ListaDupla* maiorMenor();
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
    void removeNo(NoDuplo *p);
};

#endif // LISTADUPLA_H_INCLUDED
