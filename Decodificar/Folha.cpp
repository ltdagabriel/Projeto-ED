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
string readFile(string file,vector<Folha*> *vec){
    ifstream myfile;
    myfile.open(file.c_str(),ios_base::in);
    string line;
    string answer;
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
            }
            getline (myfile,line);
            answer+=line;
        }
        myfile.close();
    }
    return answer;
}
string Folha::getCode(){
    return code;
}
char Folha::getLetra(){
    return letra;
}
void Folha::print(){
    cout<<letra<<" "<<code<<endl;
}
string decodificar(string str, vector<Folha*> vectorFolha)
{
    int troca = 0;
    int i, k;
    string frase;
    
    while(!str.empty()){
        i = 0;
        while(troca != 1){
            string sub = str.substr(0, i+1);
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