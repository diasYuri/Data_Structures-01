#include "matrixtritop.h"
#include <iostream>

using namespace std;

MatrixTriTop::MatrixTriTop(int ordem)
{
    n = ordem;
    i = (1+n)*n/2;

    mat = new float[i];
}

MatrixTriTop::~MatrixTriTop()
{
    delete [] mat;
}

int MatrixTriTop::DefineIndex(int l, int j){


    return ((1+l)*l/2)+j;


}


bool MatrixTriTop::verifyIndex(int l, int j){

    if(l<n && l>=0 && j<n && j>=0){
        return true;
    }else{
        return false;
    }

}

void MatrixTriTop::set(int l, int j, float value){

    if(verifyIndex(l,j)){
        if(l<=j){
            mat[DefineIndex(l,j)] = value;
        }
    }else{
        exit(0);
    }

}

float MatrixTriTop::get(int l, int j){

    if(verifyIndex(l, j)){
        if(l<=j){
            return mat[DefineIndex(l,j)];
        }
        else{
            return 0;
        }
    }else{
        exit(0);
    }
}
