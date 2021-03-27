#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

void inverteFila(FilaEncad *f)
{
    PilhaEncad p;
    while(!f->vazia())
        p.empilha(f->desenfileira());
    while(!p.vazia())
        f->enfileira(p.desempilha());
}

int* inverte(int *vet, int n)
{
    int* ivet = new int [n];
    PilhaEncad p;

    for(int i=0; i<n; i++)
    {
        p.empilha(vet[i]);
    }

    for(int i=0; i<n; i++)
    {
        ivet[i] = p.desempilha();
    }

    return ivet;
}

FilaEncad* concatena(FilaEncad *f1, FilaEncad *f2)
{
    FilaEncad *fres = new FilaEncad;

    while(!f1->vazia())
    {
        fres->enfileira(f1->desenfileira());
    }
    while(!f2->vazia())
    {
        fres->enfileira(f2->desenfileira());
    }

    return fres;
}

void removeDaPilha(PilhaEncad *p, int x)
{
    PilhaEncad pAux;

    while(!p->vazia() && p->getTopo() != x)
    {
        pAux.empilha(p->desempilha());
    }

    if(p->vazia())
    {
        cout<<"Valor não encontrado na pilha"<<endl;
    }
    else
        p->desempilha();


    while(!pAux.vazia())
    {
        p->empilha(pAux.desempilha());
    }
}

void removeDaFila(FilaEncad *p, int x)
{
    FilaEncad fAux;
    bool encontrado = false;

    while(!p->vazia())
    {
        if(p->getInicio() == x)
        {
            p->desenfileira();
            encontrado = true;
        }
        else
        {
            fAux.enfileira(p->desenfileira());
        }
    }

    while(!fAux.vazia())
    {
        p->enfileira(fAux.desenfileira());
    }

    if(!encontrado)
        cout<<"Valor nao encontrado na fila"<<endl;
}


int contaPilha(PilhaEncad *p)
{
    PilhaEncad pAux;
    int n=0;

    while(!p->vazia())
    {
        pAux.empilha(p->desempilha());
        n++;
    }

    while(!pAux.vazia())
    {
        p->empilha(pAux.desempilha());
    }

    return n;
}

int contaFila(FilaEncad *p)
{
    FilaEncad fAux;
    int n = 0;

    while(!p->vazia())
    {
        fAux.enfileira(p->desenfileira());
        n++;
    }

    while(!fAux.vazia())
        p->enfileira(fAux.desenfileira());

    return n;
}

int main()
{
    /*PilhaEncad p;
    for(int i = 0; i <= 9; i++)
        p.empilha(i);
    p.imprime();

    cout<<"Nova Pilha"<<endl;
    //removeDaPilha(&p, 20);
    //p.imprime();

    cout<<"Valor de n: "<<contaPilha(&p)<<endl;
    cout<<endl;
    p.imprime();*/

    /**/FilaEncad f;
    FilaEncad f2;
    for(int i = 1; i <= 9; i++)
    {
        f.enfileira(i);
        f2.enfileira(i+2);
    }
    f.imprime();
    f2.imprime();


    FilaEncad *f3 = concatena(&f, &f2);
    cout<<"Lista 3"<<endl;
    f3->imprime();

    f.imprime();
    f2.imprime();

    removeDaFila(f3, 5);
    cout<<"Fila nova"<<endl;
    f3->imprime();/**/


    delete f3;
    return 0;
}
