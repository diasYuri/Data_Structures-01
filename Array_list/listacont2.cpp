#include "listacont2.h"
#include <iostream>

using namespace std;

ListaCont2::ListaCont2(int tam, int init)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    inicio = init;
    vet = new int[max];

}

ListaCont2::~ListaCont2()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete [] vet;
}


int ListaCont2::get(int k)
{
    if(k >= inicio && k < n+inicio)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont2::set(int k, int val)
{
    if(k >= inicio && k < n+inicio)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont2::insereFinal(int val)
{
    if(n+inicio == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n+inicio] = val;
    n = n + 1;
}

void ListaCont2::removeFinal()
{
    if(n == inicio)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont2::removeInicio()
{
    if(inicio < max){
        inicio++;
        n--;
    }
}

void ListaCont2::insereAntesInicio(int val){
    if(inicio > 0){
        inicio--;
        n++;
        vet[inicio] = val;
    }
}


void ListaCont2::imprime()
{
    for(int i = inicio; i<n+inicio; i++){
        cout<<get(i)<<" ";
    }
}

void ListaCont2::insereK(int k, int val)
{
    if(n+inicio == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= inicio && k < n+inicio)
    {
        for(int i = n+inicio-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont2::removeK(int k)
{
    if(k >= inicio && k < n+inicio)
    {
        for(int i = k; i < n+inicio-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}
