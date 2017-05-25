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

using namespace std;

class Folha {
public:
    Folha(char);
    ~Folha();
    void add();
private:
    int frequencia;
    char caracter;
};


class Node{
public:
    Node();
    
private:
    Node *left;
    Node *right;
    Folha folha;
};
vector<Folha*> Gerar_Folhas(string file);
Node* Gerar_arvore(vector<Folha*>);
void Codificar_Folhas(Node*);
void Gravar(vector<Folha*>,string file);
#endif /* CLASS_H */

