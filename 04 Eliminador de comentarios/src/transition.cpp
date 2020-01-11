/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios =
  =            Archivo:       transition.cpp                        =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         09/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/transition.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           Transition Functions                    =
===================================================================*/
transition::transition( unsigned actual, unsigned next, char symbol )
{
  actual_state = actual;
  next_state = next;
  symbol_ = symbol;
}

transition::transition( const transition &old_transition )
{
  actual_state = old_transition.get_ActualState();
  next_state = old_transition.get_NextState();
  symbol_ = old_transition.get_Symbol();
}

transition& transition::operator=( transition& trans_ )
{
  this -> actual_state = trans_.get_ActualState();
  this -> next_state = trans_.get_NextState();
  this -> symbol_ = trans_.get_Symbol();
  return *this;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 09/10/2019
 *
 *
**/

