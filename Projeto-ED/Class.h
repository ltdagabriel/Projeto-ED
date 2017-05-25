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

using namespace std;

class Folha {
public:
    Folha(char);
    ~Folha();
    void add();
private:
    int size;
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

#endif /* CLASS_H */

