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

void Folha::setCode(string code){
    this->code=code;
}

void Folha::add(){
    frequencia+=1;
 }
char Folha::getC(){
    return caracter;
}

int Folha::getFrequenciaFolha()
{
    return frequencia;
}
string Folha::getCode()
{
    return code;
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
    frequencia = 0;
    folha = NULL;
    left = NULL;
    right = NULL;
}

Node::Node(Folha* a)
{
    frequencia = a->getFrequenciaFolha();
    folha = a;
    left = NULL;
    right = NULL;
}

Node::Node(Node* a, Node* b)
{
    folha = NULL;
    left = a;
    right = b;
    frequencia = a->getFrequencia() + b->getFrequencia();
}


Node* Gerar_arvore(vector<Folha*>vetorFolha)
{
    int i=0;
    vector<Node*> vetorNode;
    /** CRIAR UM VECTOR DO TIPO NODE **/
    for(i=0; i < vetorFolha.size(); i++){
        vetorNode.push_back(new Node(vetorFolha[i]));
    }
    
    if(vetorNode.size() == 1){
        return vetorNode[0];
    }
    else{
        while(vetorNode.size() > 1){
            Node* no = new Node (vetorNode[vetorNode.size()-2], vetorNode[vetorNode.size()-1]);
            vetorNode.pop_back();    
            vetorNode.pop_back();
            int i=0;
            while(i<vetorNode.size() && vetorNode[i]->getFrequencia() >= no->getFrequencia()){
                i++;
            }
            vetorNode.insert(vetorNode.begin()+i,no);
        }
    }
    
    return vetorNode[0];
}

void Codificar_Folhas(Node* no,string code)
{
    if(no){
        Codificar_Folhas(no->getL(),code+"0");
        Codificar_Folhas(no->getR(),code+"1");
    
        if(no->isFolha()){
            Folha* folha=no->getFolha();
            folha->setCode(code);
        }
    }
}

void Gravar(vector<Folha*> vec, string file)
{
    ofstream myfile;
    string file2=file+"coded";
    myfile.open(file2.c_str());
    for(int i=0;i<vec.size();i++){
        myfile<<vec[i]->getC()<<" "<<vec[i]->getCode()<<endl;
    }
    myfile<<"- ----"<<endl;
    ifstream fi;
    fi.open(file.c_str(),ios_base::in);
    char c = fi.get();

    while (fi.good()) {
        myfile<<coded(vec,c);
    c = fi.get();
  }
}
string coded(vector<Folha*> vec,char letra){
    int i=0;
    while( vec[i]->getC()!=letra){
        i++;
    }
    return vec[i]->getCode();
}
int Node::getFrequencia()
{
    return frequencia;
}
int Node::isFolha()
{
    return (folha!=NULL);
}
Node* Node::getL()
{
    return left;
}

Node* Node::getR()
{
    return right;
}
Folha* Node::getFolha()
{
    return folha;
}