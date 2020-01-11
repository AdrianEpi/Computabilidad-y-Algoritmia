/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares      =
  =            Archivo:       postfix.hpp                            =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         16/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
#include <stack>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                          Postfix Class                            =
===================================================================*/
class postfix 
{
  private:
    string postfix_;
    stack<char> aux, operator_aux;
    bool parentesis;
    int counter_;
  public: 
    postfix(){};
    postfix( string a );
    ~postfix(){};
    //Get & Set
    string get_Postfix() const { return postfix_; }
    bool get_Parentesis() const { return parentesis; }
    int get_Counter() const { return counter_; }
    void set_Postfix( const string a ) { postfix_ = a; }
    void set_ParentesisTrue() { parentesis = true; }
    void set_ParentesisFalse() { parentesis = false; }
    void set_Counter( const int a ) { counter_ = a; }
    //Functions
    void Update( string a );
    void EmptyStacks();
    int get_Priority( char a );
    void ShowStack( int i );
    int CharacterCounter( string a );
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

