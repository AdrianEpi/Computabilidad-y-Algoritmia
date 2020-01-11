/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares      =
  =            Archivo:       infix.hpp                              =
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
#include "prefix.hpp"
#include "postfix.hpp"
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                          Infix Class                              =
===================================================================*/
class infix 
{
  private:
    string infix_;
    prefix prefix_;
    postfix postfix_;
    set<char> alphabet_;
    int charcounter;
  public: 
    infix(){};
    infix( string cadena, set<char> alpha );
    ~infix(){};
    void Update( string cadena, set<char> alpha);
    //Get & Set
    string get_Infix() const { return infix_; }
    prefix get_Prefix() const { return prefix_; }
    postfix get_Postfix() const { return postfix_; }
    set<char> get_Alphabet() const { return alphabet_; }
    int get_Charcounter() const { return charcounter; }
    void set_Prefix( const prefix a ) { prefix_ = a; }
    void set_Postfix( const postfix a ) { postfix_ = a; }
    void set_Alphabet( const set<char> a ) { alphabet_ = a; }
    void set_Infix( const string a ) { infix_ = a; }
    void set_Charcounter( string a );
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

