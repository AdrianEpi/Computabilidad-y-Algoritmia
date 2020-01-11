/*===================================================================================
=====================================================================================
    =                                                                           =
    =            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
    =            Archivo:       state.hpp                                       =
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
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "transition.hpp"
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           State Class                             =
===================================================================*/
class state 
{   
  private:
    unsigned int id_;              //Numero que identifica al estaod "0, 1, 2, ..."
    unsigned int num_trans_;       //Numero de trasiciones del estado
    string name_;                  //Nombre del estado
    set<transition> transitions_;  //Conjunto de transiciones del estado

  public:
    //Builders & Destroyer
    state() {};
    state( const state& );
    ~state() {};
    //Getters
    unsigned int get_StateID( void ) const { return id_; }
    unsigned int get_NumTrans( void ) const { return num_trans_; }
    string get_StateName( void ) const { return name_; }
    set<transition> get_Trans( void ) const { return transitions_; }
    //Setters
    void set_StateID( unsigned int a ) { id_ = a; }
    void set_NumTrans( unsigned int a ) { num_trans_ = a; }
    void set_StateName( string a ) { name_ = a; }
    void set_AllTrans( unsigned int a, set <transition>& b);
    void set_Trans( transition a );
    //Sobrecarga de operadores    
    state& operator =( const state& );
    bool operator !=( const state& ) const;
    bool operator ==( const state& ) const;
    bool operator <( const state& ) const;
    //Functions
    void Erase_State( void );
    void Add_Trans( const transition& );
    //Read & Write
    void StateWrite( void ) const;
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


