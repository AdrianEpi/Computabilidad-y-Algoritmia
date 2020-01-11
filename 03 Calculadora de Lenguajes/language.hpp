/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguajes   =
    =            Archivo:       language.hpp                          =
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
#include <cmath>
#include <set>
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           Language Class                          =
===================================================================*/
class language 
{
  private:
    set<string> language_;
    int counter_;
  public: 
    language(){};
    ~language(){};
    void Erase();
    void Update(set<string> a);
    void Add_string(string a);
    void Remove_string(string a);
    bool Empty_language();
    //Get & Set
    set<string> get_Language() const { return language_; }
    void set_Language(const set<string> a) { language_ = a;}
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

