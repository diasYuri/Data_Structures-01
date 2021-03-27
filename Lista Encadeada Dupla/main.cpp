#include <iostream>
#include "ListaDupla.h"
#include <cstdlib> ///rand()
#include <ctime>   ///time()

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1);
}

int main()
{
    int NumNos = 10;
    srand(time(NULL));

    ListaDupla l;

    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val = numAleatorio(0, 50);;
        cout << val << ", ";
        //l.insereInicio(6);
        l.insereFinal(val);
    }
    cout << endl;

    l.imprime();


    ListaDupla *l2 = l.maiorMenor();

    l2->imprime();



    return 0;
}


















    //lnovo->imprime();

//    ListaDupla *lpartir = lnovo->partir(14);
//    lpartir->imprime();
//    lnovo->imprime();

//    lnovo->removeOcorrencias(0);
//    lnovo->imprime();

    //delete lpartir;
    //delete lnovo;
