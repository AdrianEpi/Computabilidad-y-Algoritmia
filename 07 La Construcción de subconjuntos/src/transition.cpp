/*===================================================================================
=====================================================================================
		=                                                                           =
    =            Proyecto:      Práctica 07 La construcción de subconjuntos     =
		=            Archivo:       transition.cpp                                  =
		=            Autor:         Adrián Epifanio Rodríguez Hernández             =
		=            Fecha:         25/10/2019                                      =
		=            Asignatura:    Computabilidad y Algoritmia                     =
		=            Lenguaje:      C++                                             =
		=            Correo:        alu0101158280@ull.edu.es                        =
		=            Lugar:         Universidad De La Laguna                        =
		=                           Escuela Superior de Ingeniería y Tecnología     =
		=                                                                           =
=====================================================================================
===================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/transition.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           Transition Functions                    =
===================================================================*/
// Constructor de copia
transition::transition( const transition& actual )
{
  symbol_ = actual.get_Symbol();
  next_state_ = actual.get_NextState();
}

// Constructor paremtrizado (simbolo, siguiente estado)
transition::transition( char sym, unsigned int next ) 
{
  symbol_ = sym;
  next_state_ = next;
}

// Establece la siguiente transicion
void transition::set_NextTrans(transition& next) 
{
  this -> symbol_ = next.get_Symbol();
  this -> next_state_ = next.get_NextState();
}

// Sobrecarga del operador igual
transition transition::operator =( const transition actual ) 
{
  transition aux;
  aux.set_NextState(actual.get_NextState());
  aux.set_Symbol(actual.get_Symbol());
  return aux;
}

// Sobrecarga del operador ==
bool transition::operator ==( const transition& trans2 ) const 
{
  if ((this -> get_NextState() == trans2.get_NextState()) && (this -> get_Symbol() == trans2.get_Symbol()))
    return true;
  else
    return false;
}

// Sobrecarga del operador !=
bool transition::operator !=( const transition& trans2 ) const 
{
  if (this -> get_Symbol() == trans2.get_Symbol()) 
    if ((this -> get_NextState() != trans2.get_NextState()))
      return true;
    else
      return false;
  else
    return true;
}

// Sobrecarga del operador <
bool transition::operator <( const transition& trans2 ) const 
{
  if((this -> get_Symbol() == trans2.get_Symbol()) && (this -> get_NextState() < trans2.get_NextState()))
    return true;
  else if (this -> get_Symbol() < trans2.get_Symbol())
    return true;
  else
    return false;
}

// Imprime la transicion (hacia donde va y con que simbolo)
void transition::TransitionWrite( void ) const 
{
  cout << "Simbolo: " << symbol_ << "  Siguiente estado: " << next_state_ << endl;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 25/10/2019
 *
 *
**/

