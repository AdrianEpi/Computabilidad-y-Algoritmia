/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares      =
  =            Archivo:       alphabet.hpp                           =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         16/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
#include <set>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                        Alphabet Class                             =
===================================================================*/
class alphabet 
{
  private:
    set<char> alphabet_;
  public: 
    alphabet();
    ~alphabet(){};
    //Get & Set
    set<char> get_Alphabet() const { return alphabet_; }
    void set_Alphabet( const set<char> a ) { alphabet_ = a; }
    //Read & Write
    void Write();
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

