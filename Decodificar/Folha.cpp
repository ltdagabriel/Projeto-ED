/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Folha.cpp
 * Author: gabri
 * 
 * Created on 26 de Maio de 2017, 18:26
 */

#include <vector>

#include "Folha.h"

Folha::Folha(char c,string code) {
    this->letra=c;
    this->code=code;
}


Folha::~Folha() {
}
string leitura(string file,vector<Folha*> *vec){
    ifstream myfile;
    myfile.open(file.c_str(),ios_base::in);
    string line;
    string str;
    char c;
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            while(str.compare("----")!=0){

                getline (myfile,line);
                c=line[0];
                str=line.substr(2);
                if(str.compare("----")!=0){
                    vec->push_back(new Folha(c,str));
                }
                else{
                    getline (myfile,str);
                }
            }
            getline (myfile,line);
            str+=line;
            
        }
        myfile.close();
    }
    return str;
}
string Folha::getCode(){
    return code;
}
char Folha::getLetra(){
    return letra;
}
string decodificar(string str, vector<Folha*> vectorFolha)
{
    int troca = 0;
    int i, k;
    string frase;
    
    while(str.size() > 0){
        i = 1;
        while(troca != 1){
            string sub = str.substr(0, i);
            for(k = 0; k < vectorFolha.size(); k++){
                if(sub.compare(vectorFolha[k]->getCode()) == 0){
                    troca = 1;
                    frase += vectorFolha[k]->getLetra();
                }
            }
            i++;
        }
        troca = 0;
        str=str.substr(i);
        
    }
    return frase;
}