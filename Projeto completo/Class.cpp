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
      for(int i=0;i<(int)array.size();i++){
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
    myfile.close();
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
    for(i=0; i < (int)vetorFolha.size(); i++){
        vetorNode.push_back(new Node(vetorFolha[i]));
    }
    
    if(vetorNode.size() == 1){
        return vetorNode[0];
    }
    else{
        while((int)vetorNode.size() > 1){
            Node* no = new Node (vetorNode[vetorNode.size()-2], vetorNode[vetorNode.size()-1]);
            vetorNode.pop_back();    
            vetorNode.pop_back();
            int i=0;
            while(i<(int)vetorNode.size() && vetorNode[i]->getFrequencia() >= no->getFrequencia()){
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
char stringToBit(string code){
    int c=0;
    for(int i=0;i<(int)code.size();i++){
        if(code[i]=='1'){
            c=c+(1<<(7-i));
        }
    }
    return c;
}
void Gravar(vector<Folha*> vec, string file)
{
    ofstream myfile;
    string file2=file+"coded";
    myfile.open(file2.c_str());
    for(int i=0;i<(int)vec.size();i++){
        myfile<<vec[i]->getC()<<stringToBit(vec[i]->getCode())<<(char)vec[i]->getCode().size();
    }
    ifstream myfile2;
	myfile2.open(file.c_str(),ios_base::in);
        
    char c;
    myfile<<"**";
	string temp;
        temp="";
        c=myfile2.get();
        while(myfile2.good()){
            
            temp+=coded(vec,c);
            c=myfile2.get();
        }
        myfile2.close();
        cout<<temp<<" "<<temp.size();
        if(temp.size()){
            int xzx=temp.size()%8;
            char xcx=xzx;
            myfile<<xcx;        
        }
        while(temp.size()>=8){
            myfile<<stringToBit(temp.substr(0,8));
            temp=temp.substr(8);
        }
        if(temp.size()){
            myfile<<stringToBit(temp);
        }
    myfile.close();
    
    
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