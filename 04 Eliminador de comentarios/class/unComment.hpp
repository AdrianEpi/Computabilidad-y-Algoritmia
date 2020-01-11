/*=========================================================================
===========================================================================
	=            Proyecto:      Práctica 04 Eliminador de comentarios  =
	=            Archivo:       unComment.hpp                          =
	=            Autor:         Adrián Epifanio R.H                    =
	=            Fecha:         09/10/2019                             =
	=            Asignatura:    Computabilidad y Algoritmia            =
	=            Lenguaje:      C++                                    = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <iostream>
#include <set>
#include <stack>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "state.hpp"
using namespace std;
#define MAX_STATES 5
/*------------------------------------------------*/
/*===================================================================
=                          UnComment Class                          =
===================================================================*/
class unComment 
{
	private:
		state actual_state, initial_state;
		set<state> states_;
		state estados_[MAX_STATES];
		int total_states;
		bool is_a_comment;
		bool final_line;
		int contador_;

	public: 
		unComment(){};
		unComment( string filename, string output );
		~unComment(){};

		//Get & Set
		state get_ActualState() const { return actual_state; }
		state get_InitialState() const { return initial_state; }
		set<state> get_States() const { return states_; }
		void set_ActualState( state a ) { actual_state = a; }
		void set_InitialState( state a ) { initial_state = a; }
		void set_States( set<state> a ) { states_ = a; }

		//Functions
		string Analizer( string a );
		state SendToState( int name, int num, transition trans );
		void CreateStates();
		
 		//Read & Write
		void Write( ostream& os, string input_line ) const;
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

