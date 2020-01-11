/*===================================================================================
=====================================================================================
    =                                                                           =
    =            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
    =            Archivo:       transition.hpp                                  =
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
    char symbol_;       // Símbolo de la transicion
    unsigned int next_state_;   // Estado siguiente

  public:
    //Builders & Destroyer
    transition() {};
    transition( const transition& );
    transition( char a, unsigned int b );
    ~transition() {};
    //Getters
    char get_Symbol( void ) const { return symbol_; }
    unsigned int get_NextState( void ) const { return next_state_; }
    //Setters
    void set_Symbol( char a) { symbol_ = a; }
    void set_NextState(unsigned int a ) { next_state_ = a; } 
    //Sobrecarga de operadores
    transition operator =( const transition a );
    bool operator ==( const transition& a )const;
    bool operator !=( const transition& a ) const;
    bool operator <( const transition& a ) const;
    //Functions
    void set_NextTrans(transition& a );   
    //Read & Write
    void TransitionWrite( void ) const;
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


