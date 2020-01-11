/*===================================================================================
=====================================================================================
		=                                                                           =
		=            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
		=            Archivo:       state.cpp                                       =
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
#include <sstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/state.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           state Functions                         =
===================================================================*/

// Constructor creado con un objeto
state::state(const state& aux)
{
  num_trans_ = aux.get_NumTrans();
  id_ = aux.get_StateID();
  transitions_ = aux.get_Trans();
  name_= aux.get_StateName();
}

// Establece todas las tranciones junto con el numero de la transicion
void state::set_AllTrans(unsigned int number, set <transition>& transitions) 
{
  num_trans_ = number;
  transitions_ = transitions;
}

// Añade una transicion al conjunto e incrementa 1 al numero de transiciones total
void state::set_Trans(transition aux) 
{
  transitions_.insert(aux);
  num_trans_++;
}

// Sobrecarga del operador =
state& state::operator = (const state& state2) 
{
  num_trans_ = state2.get_NumTrans();
  id_ = state2.get_StateID();
  transitions_ = state2.get_Trans();
  name_ = state2.get_StateName();
  return *this;
}

// Sobrecarga del operador !=
bool state::operator != (const state& state2) const 
{
  // Comprueba si son iguales
  if (id_ == state2.get_StateID()  && num_trans_ == state2.get_NumTrans() && transitions_.size() == state2.get_Trans().size())
    if (transitions_ == state2.get_Trans())
      return false;
    else
      return true;
  else
    return true;
}

// Sobrecarga del operador ==
bool state::operator == (const state& state2) const 
{
  // Comprueba si son iguales
  if (id_ == state2.get_StateID() && num_trans_ == state2.get_NumTrans() && transitions_.size() == state2.get_Trans().size())
    if (transitions_ == state2.get_Trans())
      return true;
    else
      return false;
  else
    return false;
}

// Sobrecarga del operador <
bool state::operator < (const state& state2) const
{
  if (id_ < state2.get_StateID())
    return true;
  else
    return false;
} 

// Restablece a 0 los valores del estado 
void state::Erase_State (void)
{
  num_trans_ = 0;
  id_ = 0;
  name_ = "";
  transitions_.clear();
}

// Añade una nueva transición
void state::Add_Trans (const transition& aux) 
{
  if (transitions_.find(aux) == transitions_.end())
  {
    num_trans_++;
    transitions_.insert(aux);
  }
}

// Imprime los datos del estado (ID, Nombre y transiciones)
void state::StateWrite (void) const 
{ 
  cout << "Identificador" << name_ << endl;
  cout << "Identificador numerico: "<< id_ << endl;
  cout << "Numero de transiciones: " << num_trans_ << endl;
  set <transition>::iterator it = transitions_.begin();
  for (; it !=  transitions_.end(); it++) // implementacion de for de c++11
  {
    cout << " ";
    it -> TransitionWrite();
  }   
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

