/*===================================================================================
=====================================================================================
    =                                                                           =
    =            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
    =            Archivo:       DFA.hpp                                         =
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
#pragma once
#include <iostream>
#include <set>
#include <utility>
#include <fstream>
#include <stack>
#include <vector>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "state.hpp"
#include "alphabet.hpp"
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                          DFA       Class                          =
===================================================================*/
class DFA 
{

  private:
    alphabet alphabet_;     //Objeto afabeto
    set<state> states_;     //Conjunto de estados
    unsigned int states_num;  //Número total de estados
    set<state> acepted_states;  //Conjunto de estados de aceptación
    state initial_state_;   //Estado inicial
    string input_file;      //Nombre fichero de entrada "input.dfa"

  public:
    //Buiders & Destroyer
    DFA() {};
    DFA( const DFA& a );
    ~DFA() {};
    //Getters
    alphabet get_Alphabet(void ) const { return alphabet_; }
    set<state> get_States( void ) const { return states_; }
    unsigned int get_StatesNum( void ) const { return states_num; }
    set<state> get_AcceptedStates( void ) const { return acepted_states; }
    state get_InitialState( void ) const { return initial_state_; }
    string get_InputFile( void ) const { return input_file; }
    //Setters
    void set_DFA( void );
    void set_Alphabet( alphabet a ) { alphabet_ = a; };
    void set_States( set<state>& a ) { states_ = a; }
    void set_StatesNum( unsigned int a ) { states_num = a; }
    void set_AcceptedStates( set <state>& a ) { acepted_states = a; } 
    void set_InitialState( state a ) { initial_state_ = a; }
    void set_InputFile( string& a ) { input_file = a; }
    //Functions
    unsigned int NextTransition( state, char ) const;
    void AddState( state );
    bool Es_DFA( void );
    //Read & Write    
    void WriteScreenDFA( void ) const;
    state FindState( unsigned int a ) const;
      void WriteFileDFA( ofstream& );

  private:
    void ReadFile( void );
};
/*=================================================================*/
/*=========================  End of Class  ========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 25/10/2019
 *
 *
**/


