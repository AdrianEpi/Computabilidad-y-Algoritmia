/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 2 Análisis de Texto          =
    =            Archivo:       analizador.hpp                              =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         27/09/2019                            =
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
=                              Word Class                           =
===================================================================*/
class word 
{
  private:
    int integer_;
    float floating_;
    string cadena_, reserved_;
    char operator_[2], punctuation_;
    bool reservada_;
    set<string> reserved_l, operator_l;
    set<char> punctuation_l;
  public: 
    word();
    word(string sentinel);
    ~word(){};
    void Update(string sentinel);
    bool Reserved(string sentinel);
    //Conjuntos del set
    void Reserved_List(set<string> a) {reserved_l = a;}
    void Operator_List(set<string> a) {operator_l = a;}
    void Punctuation_List(set<char> a) {punctuation_l = a;}   
    //Get & Set
    int get_Integer() const {return integer_;}
    float get_Floating() const {return floating_;}
    string get_Cadena() const {return cadena_;}
    char get_Operator() const {return operator_[0];}
    char get_Operator2() const {return operator_[1];}
    char get_Punctuation() const {return punctuation_;}
    string get_Reserved() const {return reserved_;}
    void set_Integer(const int a) {integer_ = a;}
    void set_Floating(const float a) {floating_ = a;}
    void set_Cadena(const string a) {cadena_ = a;}
    void set_Operator(const char a) { operator_[0] = a;}
    void set_Operator2(const char a) { operator_[1] = a;}
    void set_Punctuation(const char a) { punctuation_ = a;}
    void set_Reserved(const string a) {reserved_ = a;}
    //Read & Write
    void Write(ostream& os, int mode) const;
    void Read(istream& is = cin);
};
/*=================================================================*/
/*=========================  End of Class  ========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 27/09/2019
 *
 *
**/

