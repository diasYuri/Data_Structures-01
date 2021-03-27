#include "matrix2d.h"
#include <iostream>

using namespace std;

Matrix2D::Matrix2D(int l, int j)
{
    nc = j;
    nl = l;

    // allocate array of arrays (matrix)
    matrix = new float*[nl];

    // allocate each array
    for(int i = 0; i < nl; i++)
        matrix[i] = new float[nc];

}

Matrix2D::~Matrix2D()
{
    for(int i = 0; i < nl; i++)
        delete [] matrix[i];
    delete [] matrix;
}

bool Matrix2D::verifyIndex(int l, int j){

    if(l>=0 && l<=nl && j>=0 && j<=nc)
        return true;
    else
        return false;

}


float Matrix2D::get(int l, int j){

    if(verifyIndex(l,j))
    {
        return matrix[l][j];
    }
    else
    {
        cout << "Error: invalid index" << endl;
        exit(0);
    }

}


void Matrix2D::set(int l, int j, float valor){

    if(verifyIndex(l,j))
    {
        matrix[l][j] = valor ;
    }
    else
    {
        cout << "Error: invalid index" << endl;
        exit(0);
    }

}






/*

main

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


*/




