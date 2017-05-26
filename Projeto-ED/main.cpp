/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gabriel Choptian
 * Author: Caio Cesar Hideo Nakai
 *
 * Created on 25 de Maio de 2017, 01:54
 */

#include <cstdlib>
#include "Class.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string file;
    if(argc>1){
        file=argv[1];
    }
    else
        cin>>file;
    vector<Folha*> array=Gerar_Folhas(file);
    Codificar_Folhas(Gerar_arvore(array),"");
    Gravar(array,file+".coded");
    return 0;
}

