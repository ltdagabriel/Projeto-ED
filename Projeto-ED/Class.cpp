/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Class.cpp
 * Author: Gabriel Choptian
 * Author: Caio Cesar Hideo Nakai
 *
 * Created on 25 de Maio de 2017, 01:59
 */

#include "Class.h"

Folha::Folha(char letra) {
    caracter=letra;
    frequencia=1;
}

void Folha::add(){
    frequencia+=1;
 }
char Folha::getC(){
    return caracter;
}

Folha::~Folha() {
}
vector<Folha*> Gerar_Folhas(string file){
    ifstream myfile;
    vector<Folha*> array;
    myfile.open(file.c_str(),ios_base::in);

    char c = myfile.get();

  while (myfile.good()) {
      int ok=0;
      for(int i=0;i<array.size();i++){
          if(array[i]->getC()==c){
              array[i]->add();
              ok=1;
          }
      }
      if(!ok){
          array.push_back(new Folha(c));
      }

    c = myfile.get();
  }
    return array;
}

Node::Node()
{

}

Node* Gerar_arvore(vector<Folha*>vetor)
{

}

void Codificar_Folhas(Node*)
{

}

void Gravar(vector<Folha*>, string file)
{

}

Node::Node(Node* a, Node* b)
{
    folha = nullptr;
    left = a;
    right = b;
    frequencia = a.getFrequencia() + b.getFrequencia();
}
int Node::getFrequencia()
{
    return frequencia;
}
