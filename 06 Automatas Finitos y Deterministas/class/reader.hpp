/*===================================================================================
=====================================================================================
  =                                                                           =
  =            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
  =            Archivo:       reader.hpp                                      =
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
#include <string>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "DFA.hpp"
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                          Reader    Class                          =
===================================================================*/
class reader 
{
  private:
    string input_;    // Nombre fichero de entrada
    string output_;   // Nombre fichero de salida

  public:
    //Buiders & Destroyer
    reader (){};
    reader (string&, string&);
    ~reader (){};
    //Getters
    string get_Input( void ) const { return input_; }
    string get_Output( void ) const { return output_; }
    //Setters 
    void set_Intput( string a ) { input_ = a; }
    void set_Output( string a ) { output_ = a; }
    //Functions
    void RunProgram(void);

  private:
    ofstream OpenFile(void);
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


