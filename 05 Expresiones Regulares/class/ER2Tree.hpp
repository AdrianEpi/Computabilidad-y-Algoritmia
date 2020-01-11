/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares      =
  =            Archivo:       ER2Tree.hpp                            =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         16/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "infix.hpp"
#include "alphabet.hpp"
using namespace std;
#define MAX_ER 10
/*------------------------------------------------*/
/*===================================================================
=                          ER2Tree Class                            =
===================================================================*/
class ER2Tree 
{
  private:
    alphabet alphabet_;
    infix infix_[MAX_ER];
    int counter_;
  public: 
    ER2Tree( string input, string output );
    ~ER2Tree(){};
    //Get & Set
    set<char> get_Alphabet() const { return alphabet_.get_Alphabet(); }
    infix get_Infix( int a ) const { return infix_[a]; }
    int get_Counter() const { return counter_; }
    void set_Alphabet( const set<char> a ) { alphabet_.set_Alphabet(a); }
    void set_Infix( infix aux, int a ) { infix_[a] = aux; }
    void set_Counter( int a ) { counter_ = a; }
    //Read & Write
    void Write( ostream& os ) const;
    void Read( istream& is = cin );
};
/*=================================================================*/
/*=========================  End of Class  ========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 16/10/2019
 *
 *
**/

