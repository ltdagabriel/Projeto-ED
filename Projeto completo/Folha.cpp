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
 * Created on 26 de Maio de 2017, 18:26
 */

#include <vector>

#include "Folha.h"
#include <math.h>
#include <cstdlib>

Folha::Folha(char c,string code) {
    this->letra=c;
    this->code=code;
}


Folha::~Folha() {
}
string readFile(string file,vector<Folha*> *vec){
    ifstream myfile;
    myfile.open(file.c_str(),ios_base::binary);
    string answer;
    int code='x';
    char c='x';
	char size='x';
	int size2=0;
    if (myfile.is_open())
    {
        while(c!='*' && code!='*' && myfile.good()){
            myfile.read((char*)&c,sizeof(char));
            myfile.read((char*)&code,sizeof(int));
            myfile.read((char*)&size,sizeof(char));
            size2=size;
            if(c!='*' && code!='*'){
                vec->push_back(new Folha(c,BittoString(code,size2)));
            }
        }
		
        string temp;
        while (myfile.good() )
        {   
            myfile.read((char*)&c,sizeof(char));
            temp+=c;
        }

        temp=temp.substr(0,temp.size()-1);
		string temporaria= BittoString((char)temp[temp.size()-1],size2);
        answer=temporaria;
        temp=temp.substr(0,temp.size()-1);
        while(temp.size()){
			temporaria=BittoString((char)temp[temp.size()-1],8);
            answer=temporaria+answer;
            temp=temp.substr(0,temp.size()-1);
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
string BittoString(int Bit,int size){
    int c=Bit;
    string code;
    for(int i=1,j=0;j<size; j++,i=i<<1){
        if( ((c&i)>>j) ==1){
            code="1"+code;
        }
        else
            code="0"+code;
    }
    return code;
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
            for(k = 0; k < (int)vectorFolha.size(); k++){
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