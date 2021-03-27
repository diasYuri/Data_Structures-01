#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();

    void insereInicio(int val);
    void insereFinal(int val);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    void imprime();
    int contaNos();
    int contaNos2();
    void insereK(int val, int pos);
    bool verificaPos(int pos);
    void removeK(int pos);

private:
    No *primeiro; // ponteiro para o primeiro nó
    No *ultimo; // ponteiro para o último nó
    int n;
};

#endif // LISTAENCAD_H_INCLUDED
