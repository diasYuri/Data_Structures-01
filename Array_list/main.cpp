#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"
#include "listacont2.h"
#include "ListaPonto.h"
#include "ListaProva.h"

using namespace std;

int main()
{
    int n = 4;
    ListaPonto l1(n);


    for(int i=0; i<n; i++){
        l1.insereFinal(5, i*2);
    }

    l1.imprime();

    l1.imprimeDistancia();

    return 0;
}
