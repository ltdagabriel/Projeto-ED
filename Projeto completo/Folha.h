/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Folha.h
 * Author: gabri
 *
 * Created on 26 de Maio de 2017, 18:26
 */

#ifndef FOLHA_H
#define FOLHA_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Folha {
public:
    Folha(char,string);
    virtual ~Folha();
    int verificar(string);
    string getCode();
    char getLetra();
    void print();
private:
    char letra;
    string code;
};
string readFile(string file,vector<Folha*>*);
string BittoString(int Bit,int size);
string decodificar(string,vector<Folha*>);

#endif /* FOLHA_H */

