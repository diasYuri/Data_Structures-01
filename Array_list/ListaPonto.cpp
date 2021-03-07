#include "ListaPonto.h"
#include <iostream>
#include <cstdlib>
#include "Ponto.h"


using namespace std;

ListaPonto::ListaPonto(int tam)
{
    cout << "Criando objeto ListaPonto" << endl;
    max = tam;
    n = 0;
    vet = new Ponto[max];
}

ListaPonto::~ListaPonto()
{
    cout << "Destruindo objeto ListaPonto" << endl;
    delete [] vet;
}

Ponto ListaPonto::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaPonto::set(int k, float x, float y)
{
    if(k >= 0 && k < n)
    {
        vet[k].setX(x);
        vet[k].setY(y);
    }

    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaPonto::insereFinal(float x, float y)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    Ponto val(x,y);
    vet[n] = val;
    n = n + 1;
}

void ListaPonto::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaPonto::insereK(int k, float x, float y)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n)
    {
        Ponto val(x,y);
        for(int i = n-1; i >= k; i--)
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

void ListaPonto::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaPonto::insereInicio(float x, float y)
{

    Ponto val(x, y);

    if(n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else
        insereK(0, x, y);
}

void ListaPonto::removeInicio()
{
    removeK(0);
}

void ListaPonto::imprime()
{
    if(n>0){
        for(int i=0; i<n; i++){
            cout<<"X: "<<vet[i].getX()<<" Y: "<<vet[i].getY()<<endl;
        }
    }
}

int ListaPonto::numNos(){
    return n;
}



void ListaPonto::limpar(){
    n=0;
}

void ListaPonto::imprimeDistancia(){

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){
            float dist = vet[i].distancia(&vet[j]);

            cout<<"Distancia entre P"<<i+1<<" e P"<<j+1<<": "<<dist<<endl;

        }
    }

}


