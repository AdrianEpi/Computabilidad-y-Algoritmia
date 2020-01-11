/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguajes   =
    =            Archivo:       reader.hpp                            =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         02/10/2019                            =
    =            Asignatura:    Computabilidad y Algoritmia           =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <cassert>
#include <iostream>
#include <set>
using namespace std;
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "calculator.hpp"
#define MAX_LANGUAGES 50
/*------------------------------------------------*/
/*===================================================================
=                             Reader Class                          =
===================================================================*/
class reader 
{
  private:
    set<string> alphabet_tmp[MAX_LANGUAGES];
    int counter_;
  public: 
    reader(){};
    reader(string filename);
    ~reader(){};
    void Erase();
    void Update(string filename);
    //Get & Set
    int get_Counter() const { return counter_; }
    set<string> get_Languages_tmp(int mode) const { return alphabet_tmp[mode]; }  //Cada modo sera un lenguaje del
    void set_Counter(const int a) { counter_ = a; }
    void set_Languages_tmp(const set<string> a, const int mode) { alphabet_tmp[mode] = a; }
    //Read & Write
    void Write(ostream& os) const;
    void Read(istream& is = cin);
};
/*=================================================================*/
/*=========================  End of Class  ========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 02/10/2019
 *
 *
**/

