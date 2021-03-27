#include <iostream>
#include "PilhaCont.h"
#include "FilaCont.h"

using namespace std;

void montaFilas(PilhaCont *p, FilaCont *f1, FilaCont *f2)
{
    while(!p->vazia())
        if(p->getTopo() < 0)
            f1->enfileira(p->desempilha());
        else
            f2->enfileira(p->desempilha());
}

int main()
{
    PilhaCont p(100);
    FilaCont f1(100), f2(100);

    for(int i = 1; i <= 10; i++)
        p.empilha(i);
    p.empilha(-4);
    p.empilha(4);
    p.empilha(-5);
    p.empilha(0);
    p.imprime();

    montaFilas(&p, &f1, &f2);

    p.imprime();
    f1.imprime();
    f2.imprime();

    return 0;
}
