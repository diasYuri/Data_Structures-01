#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = NULL;
    n = 0;
}

PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while(p != NULL)
    {
        No *t = p;
        p = p->getProx();
        delete t;
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}

void PilhaEncad::empilha(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
    n++;
}

int PilhaEncad::desempilha()
{
    if(topo != NULL)
    {
        No *p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        n--;
        return val;
    }
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}

bool PilhaEncad::vazia()
{
    if(topo == NULL)
        return true;
    else
        return false;
}


void PilhaEncad::imprime()
{
    if(topo != NULL)
    {
        No *p = topo;
        while(p != NULL)
        {
            cout<<p->getInfo()<<endl;
            p = p->getProx();
        }
    }
    else
        cout<<"Pilha vazia"<<endl;

}

int PilhaEncad::tamanho()
{
    return n;
}
