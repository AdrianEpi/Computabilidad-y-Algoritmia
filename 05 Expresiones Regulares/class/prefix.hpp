/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares      =
  =            Archivo:       prefix.hpp                             =
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
=                          Prefix Class                             =
===================================================================*/
class prefix 
{
  private:
    string prefix_;
    stack<char> aux, operator_aux;
    bool parentesis;
    int counter_;
  public: 
    prefix(){};
    prefix( string a );
    ~prefix(){};
    //Get & Set
    string get_Prefix() const { return prefix_; }
    bool get_Parentesis() const { return parentesis; }
    int get_Counter() const { return counter_; }
    void set_Prefix( const string a ) { prefix_ = a; }
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

