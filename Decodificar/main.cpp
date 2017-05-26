/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gabri
 *
 * Created on 26 de Maio de 2017, 14:52
 */

#include <cstdlib>
#include "Folha.h" 
using namespace std;

int main(int argc, char** argv) {
    string file;
    if(argc>1){
        file=argv[1];
    }
    else{
        cout<<"File name:";
        cin>>file;
    }
    vector<Folha*> vec;
    string x=leitura(file,vec);
    
}
