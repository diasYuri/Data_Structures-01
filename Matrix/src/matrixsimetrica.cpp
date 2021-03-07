#include "matrixsimetrica.h"
#include <iostream>

using namespace std;

MatrixSimetrica::MatrixSimetrica(int ordem)
{
    n = ordem;
    i = (1+n)*n/2;

    mat = new float[i];
}

MatrixSimetrica::~MatrixSimetrica()
{
    delete [] mat;
}

int MatrixSimetrica::DefineIndex(int l, int j){


    return ((1+l)*l/2)+j;


}


bool MatrixSimetrica::verifyIndex(int l, int j){

    if(l<n && l>=0 && j<n && j>=0){
        return true;
    }else{
        return false;
    }

}

void MatrixSimetrica::set(int l, int j, float value){

    if(verifyIndex(l,j)){
        if(l<=j){
            mat[DefineIndex(l,j)] = value;
        }
    }else{
        exit(0);
    }

}

float MatrixSimetrica::get(int l, int j){

    if(verifyIndex(l, j)){
        if(l<=j){
            return mat[DefineIndex(l,j)];
        }
        else{
            return mat[DefineIndex(j,l)];
        }
    }else{
        exit(0);
    }
}
