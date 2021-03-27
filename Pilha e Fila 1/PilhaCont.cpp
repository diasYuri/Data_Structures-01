#include <iostream>
#include <cstdlib>
#include "PilhaCont.h"

using namespace std;

PilhaCont::PilhaCont(int tam)
{
    max = tam;
    topo = -1;
    vet = new int[max];
}
PilhaCont::~PilhaCont()
{
    delete [] vet;
}
int PilhaCont::getTopo()
{
    if(topo != -1)
        return vet[topo];
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}
void PilhaCont::empilha(int val)
{
    if(topo == max-1)
        cout << "Vetor cheio" << endl;
    else
        vet[++topo] = val;
}
int PilhaCont::desempilha()
{
    if(topo != -1)
    {
        topo--;
        return vet[topo+1];
    }
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}
bool PilhaCont::vazia()
{
    return topo == -1;
}
void PilhaCont::imprime()
{
    cout << "Pilha: ";
    for(int i = topo; i >= 0; i--)
        cout << vet[i] << " ";
    cout << endl;
}
