#include "matrixantisimetrica.h"

#include <iostream>

using namespace std;

MatrixAntiSimetrica::MatrixAntiSimetrica(int ordem)
{
    n = ordem;
    i = (1+n)*n/2;

    mat = new float[i];
}

MatrixAntiSimetrica::~MatrixAntiSimetrica()
{
    delete [] mat;
}

int MatrixAntiSimetrica::DefineIndex(int l, int j){


    return ((1+l)*l/2)+j;


}


bool MatrixAntiSimetrica::verifyIndex(int l, int j){

    if(l<n && l>=0 && j<n && j>=0){
        return true;
    }else{
        return false;
    }

}

void MatrixAntiSimetrica::set(int l, int j, float value){

    if(verifyIndex(l,j)){
        if(l>j){
            mat[DefineIndex(l,j)] = value;
        }
    }else{
        exit(0);
    }

}

float MatrixAntiSimetrica::get(int l, int j){

    if(verifyIndex(l, j)){
        if(l>j){
            return mat[DefineIndex(l,j)];
        }
        else if(j>l){
            return -1*(mat[DefineIndex(j,l)]);
        }
        else{
            return 0;
        }
    }else{
        exit(0);
    }
}
