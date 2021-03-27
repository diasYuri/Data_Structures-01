#include <iostream>
#include <cstdlib>
#include "FilaCont.h"

using namespace std;

FilaCont::FilaCont(int tam)
{
    max = tam;
    inicio = 0;
    fim = 0;
    vet = new int[max];
}
FilaCont::~FilaCont()
{
    delete [] vet;
}
int FilaCont::getInicio()
{
    if(inicio < fim)
        return vet[inicio];
    else
    {
        cout << "Fila vazia" << endl;
        exit(1);
    }
}
void FilaCont::enfileira(int val)
{
    if(fim == max)
        cout << "Fila cheia" << endl;
    else
        vet[fim++] = val;
}
int FilaCont::desenfileira()
{
    if(inicio < fim)
    {
        inicio++;
        return vet[inicio-1];
    }
    else
    {
        cout << "Fila vazia" << endl;
        exit(1);
    }
}
bool FilaCont::vazia()
{
    if(inicio == fim);
}
void FilaCont::imprime()
{
    cout << "Fila: ";
    for(int i = inicio; i < fim; i++)
        cout << vet[i] << " ";
    cout << endl;
}
