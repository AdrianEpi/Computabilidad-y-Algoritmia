/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios  =
  =            Archivo:       transition.hpp                         =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         09/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                          Transition Class                         =
===================================================================*/
class transition 
{
  private:
    unsigned actual_state, next_state;
    char symbol_;
  public: 
    transition(){};
    transition( unsigned actual, unsigned next, char symbol );
    transition( const transition &old_transition );
    ~transition(){};

    //Get & Set
    unsigned get_ActualState() const { return actual_state; }
    unsigned get_NextState() const { return next_state; }
    char get_Symbol() const { return symbol_; }
    void set_ActualState( unsigned a ) { actual_state = a; }
    void set_NextState( unsigned a ) { next_state = a; }
    void set_Symbol( char a ) { symbol_ = a; }

    //Sobrecarga de operadores
    transition& operator=( transition &trans_ ); 

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
 *   Fecha: 09/10/2019
 *
 *
**/

