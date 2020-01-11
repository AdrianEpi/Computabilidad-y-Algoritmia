/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios  =
  =            Archivo:       state.hpp                              =
  =            Autor:         Adrián Epifanio R.H                    =
  =            Fecha:         09/10/2019                             =
  =            Asignatura:    Computabilidad y Algoritmia            =
  =            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
#include "transition.hpp"
using namespace std;
#define MAX_STATES 5
/*------------------------------------------------*/
/*===================================================================
=                           State Class                             =
===================================================================*/
class state 
{
  private:
    int state_name_, num_transition_;
    transition *trans_;
    transition tran_[MAX_STATES];
  public: 
    state(){};
    state( int name, int num, transition trans );
    state( const state &old_state );
    ~state(){};
    
    //Get & Set
    int get_StateName() const { return state_name_; }
    int get_NumTransition() const { return num_transition_; }
    transition* get_Trans() const { return trans_; }
    transition get_Tran(int a) const { return tran_[a]; }
    void set_StateName( int a ) { state_name_ = a; }
    void set_NumTransition( int a) { num_transition_ = a; }
    void set_Trans( char symbol, unsigned next_state, int sentinel); //Sentinel para saber que transicion del estado
    void set_Tran( int sentinel, char symbol, unsigned next_state );
  
    //Sobrecarga de operadores
    state& operator=( const state &estado );
    int operator==( const state &estado );
    int operator<( const state &estado );

    //Funciones
    void Update( state old_state );
    void SetState(state a);

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

