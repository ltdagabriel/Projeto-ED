/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Class.h
 * Author: Gabriel Choptian
 * Author: Caio Cesar Hideo Nakai
 *
 * Created on 25 de Maio de 2017, 01:59
 */

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Folha {
public:
    Folha(char);
    ~Folha();
    void add();
    char getC();
    void setCode(string);
    int getFrequenciaFolha();
    string getCode();
private:
    int frequencia;
    char caracter;
    string code;
};


class Node{
public:
    Node();
    Node(Node*, Node*);
    Node(Folha*);
    int getFrequencia();
    int isFolha();
    Node* getL();
    Node* getR();
    Folha* getFolha();

private:
    Node *left;
    Node *right;
    Folha *folha;
    int frequencia;
};
vector<Folha*> Gerar_Folhas(string file);
Node* Gerar_arvore(vector<Folha*>);
void Codificar_Folhas(Node*,string);
void Gravar(vector<Folha*>,string file);
char stringToBit(string);
void Decodificar();
void sortVectorFrequencia(vector<Node*>);
string coded(vector<Folha*>,char);
#endif /* CLASS_H */

