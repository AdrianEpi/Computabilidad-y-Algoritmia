/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios  =
  =            Archivo:       element.hpp                            =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         09/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           Element Class                           =
===================================================================*/
class element 
{
  private:
    string cadena_;
    int state_;   

  public: 
    element(){};
    element( string cad, int state );
    ~element(){};
    
    //Get & Set
    string get_Cadena() const { return cadena_; }
    int get_State() const { return state_; }
    void set_Cadena( string a ) { cadena_ = a; }
    void set_State( int a ) { state_ = a; }
    
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

