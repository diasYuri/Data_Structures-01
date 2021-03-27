#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED
#include "No.h"

class PilhaEncad
{
public:
    PilhaEncad();
    ~PilhaEncad();
    int getTopo();
    void empilha(int val);
    int desempilha();
    bool vazia();
    void imprime();
    int tamanho();
private:
    No *topo;
    int n;
};

#endif // PILHAENCAD_H_INCLUDED
