/*===================================================================================
=====================================================================================
  =                                                                           =
  =            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
  =            Archivo:       alphabet.hpp                                    =
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
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           Alphabet Class                          =
===================================================================*/
class alphabet
{
  private:
  set<char> alphabet_;  //Conjunto de caracteres del alfabeto

  public:
  //Builder & Destroyer
  alphabet(){};
  alphabet( string& );
  alphabet( const alphabet& );
  ~alphabet(){};
  //Get & Set
  const set<char>& get_Alphabet( void ) const { return alphabet_; };
  void set_Alphabet( set<char> a ) { alphabet_ = a; }
  //Functions
  void Create_Alphabet( string ); //sdas
  //Read & Write
  void Alphabet_Write( void ) const;
  
  private:
  int Alphabet_Size( void ) const;
  
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


