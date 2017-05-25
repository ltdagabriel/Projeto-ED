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
    size=1;
}

void Folha::add(){
    size+=1;
 }

Folha::~Folha() {
}

