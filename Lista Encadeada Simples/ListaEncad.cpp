#include <iostream>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
    n = 0;
    ultimo = NULL;
}

ListaEncad::~ListaEncad()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *q = p->getProx();
        delete p;
        p = q;
    }
}

bool ListaEncad::verificaPos(int pos)
{
    if(pos<1 || pos>n+1)
        return false;
    return true;
}

void ListaEncad::insereInicio(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(primeiro);
    if(primeiro == NULL)
        ultimo = p;
    primeiro = p;
    n++;
}

void ListaEncad::insereFinal(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(primeiro == NULL)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n++;
}

void ListaEncad::insereK(int val, int pos)
{
    if(!verificaPos(pos))
    {
        cout<<"Posicao invalida"<<endl;
        return;
    }

    if(pos == 1 || n == 0)
        insereInicio(val);
    else if(pos == n+1)
        insereFinal(val);
    else
    {
        int i = 1;
        No *p = new No();
        p->setInfo(val);
        p->setProx(NULL);


        No *penultimoK = primeiro;
        while(i+1<pos)
        {
            penultimoK = penultimoK->getProx();
            i++;
        }

        p->setProx(penultimoK->getProx());
        penultimoK->setProx(p);
        n++;
    }
}

void ListaEncad::removeInicio()
{
    if(primeiro == NULL)
        cout << "ERRO: Lista vazia" << endl;
    else
    {
        No *p = primeiro;
        primeiro = p->getProx();
        delete p;
        if(primeiro == NULL)
            ultimo = NULL;
        n--;
    }
}

void ListaEncad::removeFinal()
{
    if(primeiro == NULL)
        cout << "ERRO: Lista vazia" << endl;
    else
    {
        No *penultimo = primeiro;
        if(penultimo->getProx() == NULL)
        {
            delete ultimo;
            primeiro = ultimo = NULL;
        }
        else
        {
            while(penultimo->getProx() != ultimo)
                penultimo = penultimo->getProx();
            penultimo->setProx(NULL);
            delete ultimo;
            ultimo = penultimo;
        }
        n--;
    }
}

void ListaEncad::removeK(int pos)
{
    if(!verificaPos(pos))
    {
        cout<<"Posicao invalida"<<endl;
        return;
    }

    if(pos <= 1)
        removeInicio();
    else if(pos == n)
        removeFinal();
    else
    {
        int i=1;

        No *penultimoK = primeiro;
        while(i+1<pos)
        {
            penultimoK = penultimoK->getProx();
            i++;
        }

        No *k = penultimoK->getProx();
        penultimoK->setProx(k->getProx());
        delete k;

    }

}

bool ListaEncad::busca(int val)
{
    for(No *p = primeiro; p != NULL; p = p->getProx()) //for(int i = 0; i < n; i++)
        if(p->getInfo() == val)
            return true;
    return false;
}

void ListaEncad::imprime()
{
    cout << "Lista: ";
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

int ListaEncad::contaNos()
{
    int cont = 0;
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cont++;
    return cont;
}

int ListaEncad::contaNos2()
{
    return n;
}
