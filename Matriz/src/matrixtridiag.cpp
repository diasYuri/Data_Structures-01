#include "matrixtridiag.h"
#include <iostream>

using namespace std;

MatrixTriDiag::MatrixTriDiag(int ordem)
{
    n = ordem;
    i = (n*3)-2;

    mat = new float[i];
}

MatrixTriDiag::~MatrixTriDiag()
{
    delete [] mat;
}

int MatrixTriDiag::DefineIndex(int l, int j){


    return (l*2)+j;


}


bool MatrixTriDiag::verifyIndex(int l, int j){

    if(l<n && l>=0 && j<n && j>=0){
        return true;
    }else{
        return false;
    }

}

void MatrixTriDiag::set(int l, int j, float value){

    if(verifyIndex(l,j)){
        if(verifyDiag(l,j)){
            mat[DefineIndex(l,j)] = value;
        }
    }else{
        exit(0);
    }

}

float MatrixTriDiag::get(int l, int j){

    if(verifyIndex(l, j)){
        if(verifyDiag(l,j)){
            return mat[DefineIndex(l,j)];
        }
        else{
            return 0;
        }
    }else{
        exit(0);
    }
}

bool MatrixTriDiag::verifyDiag(int l, int j){
    if(l==j || (l-j) == 1 || (l-j) == -1)
    {
       return true;
    }
    else
    {
        return false;
    }
}
