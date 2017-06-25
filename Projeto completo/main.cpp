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
    string file_saida;
	if(argc>2){
		file=argv[1];
		file_saida=argv[2];
	}
    else if(argc>1){
        file=argv[1];
    }
    else
        cout<<"Usar construtor"<<endl;
    
    vector<Folha*> array=Gerar_Folhas(file);
    Node* root=Gerar_arvore(array);
    Codificar_Folhas(root,"");
    Gravar(array,file,file_saida);
    system("pause");
    return 0;
}

