/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios =
  =            Archivo:       state.cpp                             =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         09/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <sstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/state.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           State Functions                         =
===================================================================*/
state::state( int name, int num, transition transi )
{
  state_name_ = name;
  num_transition_ = num;
  trans_ = new transition[num_transition_];
}

state::state( const state &old_state )
{
  Update(old_state);
}

void state::set_Trans( char symbol, unsigned next_state, int sentinel ) //Sentinel para saber que transicion del estado
{
  trans_[sentinel].set_Symbol(symbol);
  trans_[sentinel].set_ActualState(state_name_);
  trans_[sentinel].set_NextState(next_state);
}

void state::set_Tran( int sentinel, char symbol, unsigned next_state )
{
  tran_[sentinel].set_Symbol(symbol);
  tran_[sentinel].set_ActualState(state_name_);
  tran_[sentinel].set_NextState(next_state);
}

state& state::operator=( const state &estado )
{
  this -> state_name_ = estado.state_name_;
  this -> num_transition_ = estado.num_transition_; 
  this -> trans_ = new transition[num_transition_];
  for (int i = 0; i < num_transition_; i++) 
    this -> trans_[i] = estado.trans_[i];

  return *this;
}

int state::operator==( const state &estado )
{
  return state_name_ == estado.state_name_;
}

int state::operator<( const state &estado )
{
  return state_name_ < estado.state_name_;
}

void state::Update( const state old_state )
{
  state_name_ = old_state.get_StateName();
  num_transition_ = old_state.get_NumTransition();
  trans_ = old_state.get_Trans();
}

void state::SetState( state old_state )
{
  state_name_ = old_state.get_StateName();
  num_transition_ = old_state.get_NumTransition();
  for (int i = 0; i < 5; i++)
  {
    tran_[i].set_ActualState(old_state.get_Tran(i).get_ActualState());
    tran_[i].set_NextState(old_state.get_Tran(i).get_NextState());
    tran_[i].set_Symbol(old_state.get_Tran(i).get_Symbol());
  }
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

