#include <iostream>
#include "ListaDupla.h"
#include <cstdlib> ///rand()
#include <ctime>   ///time()

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;
    cout<<"Deletando ListaDupla"<<endl;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

void ListaDupla::imprime()
{
    if(primeiro != NULL)
    {
        cout << "Lista: ";
        for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
            cout << p->getInfo() << " ";
    }
    else
        cout << "Lista Vazia";
    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    cout << "Lista Reversa: ";
    for(NoDuplo *p = ultimo; p != NULL; p = p->getAnt())
        cout << p->getInfo() << " ";
    cout << endl;
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setAnt(NULL);
    p->setProx(primeiro);
    if(primeiro == NULL)
        ultimo = p;
    else
        primeiro->setAnt(p);
    primeiro = p;
    n++;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);
    if(primeiro == NULL)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n++;
}

void ListaDupla::inserek(int val, int k)
{

    if(k>=0 && k<=n)
    {
        NoDuplo *p = new NoDuplo();
        NoDuplo *a = primeiro;

        if(a == NULL || k == 0)
        insereInicio(val);
        else if(n == k)
            insereFinal(val);
        else
        {
            p->setInfo(val);

            while(k!=0)
            {
                k--;
                a = a->getProx();
            }

            p->setAnt(a->getAnt());
            p->setProx(a);

            a->getAnt()->setProx(p);
            a->setAnt(p);
        }
    }
    else
        cout<<"indice K fora da lista"<<endl;

}

void ListaDupla::removek(int k)
{
    if(k>=0 && k<n)
    {
        NoDuplo *p = primeiro;

        while(k!=0)
        {
            k--;
            p = p->getProx();
        }

        removeNo(p);
    }
    else
        cout<<"Indice K fora da lista"<<endl;

}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        if(primeiro == NULL)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
        n--;
    }
    else
        cout << "ERRO: Lista vazia" << endl;
}

void ListaDupla::removeFinal()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = ultimo;
        ultimo = p->getAnt();
        delete p;
        if(ultimo == NULL)
            primeiro = NULL;
        else
            ultimo->setProx(NULL);
        n--;
    }
    else
        cout << "ERRO: Lista vazia" << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    ListaDupla* lres = new ListaDupla;

    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    {
        lres->insereFinal(p->getInfo());
    }

    for(NoDuplo *p = l2->primeiro; p != NULL; p = p->getProx())
    {
        lres->insereFinal(p->getInfo());
    }

    return lres;
}

void ListaDupla::removeNo(NoDuplo *p)
{
    if (p == NULL || n == 0)
        return;

    if (p == primeiro)
    {
        removeInicio();
    }
    else if (p == ultimo)
    {
        removeFinal();
    }
    else
    {
        NoDuplo *ant = p->getAnt();
        NoDuplo *prox = p->getProx();
        ant->setProx(p->getProx());
        prox->setAnt(p->getAnt());

        n = n - 1;
        delete p;
    }
}

ListaDupla* ListaDupla::partir(int x)
{
    ListaDupla* lres = new ListaDupla;
    NoDuplo *p = primeiro;
    NoDuplo *a = primeiro;

    if(p != NULL)
    {
        int aux = 0;
        for(p = primeiro; p->getInfo() != x; p = p->getProx())
        {
            aux++;
        }

        lres->ultimo = ultimo;

        if(p->getAnt() != NULL)
        {
            a = p->getAnt();
            a->setProx(NULL);
            ultimo = a;
        }
        else
        {
            primeiro = NULL;
            ultimo = NULL;
        }

        lres->primeiro = p;
        p->setAnt(NULL);

        return lres;
    }
    else
        cout<<"Lista vazia"<<endl;
}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p = primeiro;

    int i=0;

    while(p!=NULL)
    {

        if(p->getInfo() == val)
        {
            if(i>0)
            {
                NoDuplo *a = p;
                p = p->getProx();
                removeNo(a);
            }
            else
                p = p->getProx();
            i++;
        }
        else
            p = p->getProx();
    }

}




/*void ListaDupla::trocaKProximo(int k)
{
    if(k>=0 && k<n)
    {
        if(k<n-1)
        {
            NoDuplo *p = primeiro;
            NoDuplo *aux = p;
            int a = k;

            while(a!=0)
            {
                p = p->getProx();
                a--;
            }

            aux = p->getProx();
            aux->setAnt(p->getAnt());

            if(p->getAnt() != NULL)
                p->getAnt()->setProx(aux);
            else
                primeiro = aux;

            p->setProx(aux->getProx());

            //Lista com 2 nos
            if(aux->getProx() != NULL)
                aux->getProx()->setAnt(p);
            else
                ultimo = aux;

            p->setAnt(aux);
            aux->setProx(p);
        }

        // Tratamento de erro
        else if(n==1)
            cout<<"ERRO: Nao e possivel trocar o unico valor da lista"<<endl;
        else
            cout<<"ERRO: Nao e possivel trocar o ultimo valor da lista"<<endl;

    }
    else
        cout<<"Indice fora da lista"<<endl;

}*/




ListaDupla* ListaDupla::maiorMenor()
{
    ListaDupla* lres = new ListaDupla;
    NoDuplo *p = primeiro;

    int maior, menor;
    maior = primeiro->getInfo();
    menor = primeiro->getInfo();

    NoDuplo *maiorP;
    NoDuplo *menorP;

    if(p != NULL)
    {
        while(p != NULL)
        {
            if(p->getInfo() > maior)
            {
                 maior = p->getInfo();
                 maiorP = p;
            }
            if(p->getInfo() < menor)
            {
                 menor = p->getInfo();
                 menorP = p;
            }

            p = p->getProx();
        }

        lres->insereInicio(maior);
        lres->insereInicio(menor);
        removeNo(maiorP);
        removeNo(maiorP);


        return lres;
    }

}

