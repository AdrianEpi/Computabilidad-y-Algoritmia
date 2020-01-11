/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguajes   =
    =            Archivo:       calculator.hpp                        =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         02/10/2019                            =
    =            Asignatura:    Computabilidad y Algoritmia           =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
#include <cassert>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           Calculator Class                        =
===================================================================*/
class calculator 
{
  private:
    set<string> result_;
  public: 
    calculator(){};
    ~calculator(){};
    //Functions
    set<string> Concatenacion(set<string> language_A, set<string> language_B);
    set<string> Union(set<string> language_A, set<string> language_B);
    set<string> Interseccion(set<string> language_A, set<string> language_B);
    set<string> Diferencia(set<string> language_A, set<string> language_B);
    bool Igualdad(set<string> language_A, set<string> language_B);
    bool Sublenguajes(set<string> language_A, set<string> language_B);
    set<string> Inversa(set<string> language_A);
    string Potencia(set<string> language_A, const string iterator, int num);
    string Cierre_Positivo(set<string> language_A, const string iterator, int num);
    void Cierre_Kleene(set<string> language_A, const string iterator, int num);
    //Get & Set
    set<string> get_Result() const { return result_; }
    //Read & Write
    void Write(ostream& os) const;
    void Read(istream& is = cin);
};
/*=================================================================*/
/*=========================  End of Class  ========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 02/10/2019
 *
 *
**/

