#include <iostream>
#include "matrix2d.h"
#include "matrixtritop.h"
#include "matrixsimetrica.h"
#include "matrixantisimetrica.h"
#include "matrixtridiag.h"

using namespace std;


int main()
{
    /*int n = 5;
    MatrixTriDiag m(n);

    for(int l=0; l<n; l++)
    {
        for(int j=0; j<n; j++)
        {
            m.set(l, j, l+j);
        }
    }

    //cout<<m.get(1,3);

    for(int l=0; l<n; l++)
    {
        cout<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<m.get(l,j)<<" ";
        }
    }*/

    Matrix2D m(5, 5);
    int l, j;
    float n;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<"enter the number of the "<<i+1<<" row and the "<<j+1<<" column: ";
            cin>>n;
            m.set(i, j, n);
        }
    }

    for(int l=0; l<5; l++){
        cout<<endl;
        for(int j=0; j<5; j++){
            cout<<m.get(l,j)<<" ";
        }
    }

    cout<<endl;
    for(int j=0; j<5; j++){
        cout<<m.get(3, j)<<" ";
    }

    cout<<endl;
    cout<<"enter the number of line: ";
    cin>>l;
    cout<<"enter the number of column: ";
    cin>>j;
    cout<<"enter the value: ";
    cin>>n;
    m.set(l-1, j-1, n);

    for(int j=0; j<5; j++){
        cout<<endl;
        for(int l=0; l<5; l++){
            cout<<m.get(l,j)<<" ";
        }
    }


    float soma[5] = {0,0,0,0,0};
    for(int i=1; i<=5; i++){

        for(int l=i, j=5; j>0; l++,j--){
            if(l>5)
                l=1;

            soma[i-1] = soma[i-1] + m.get(l-1,j-1);
        }

    }

}
