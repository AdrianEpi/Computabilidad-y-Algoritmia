/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguages   =
    =            Archivo:       language.cpp                          =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         02/10/2019                            =
    =            Asignatura:    Computabilidad y Algoritmia           =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <set>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "language.hpp"
#define MAX_LENGTH 30
/*------------------------------------------------*/
/*===================================================================
=                           Language Functions                      =
===================================================================*/
bool language::Empty_language()
{
  set<string>::iterator it = language_.find("&");
  if(it != language_.end())
    return true;
  else
    return false;
}

void language::Erase()
{
  set<string>::iterator it = language_.begin();
  set<string>::iterator it_end = language_.end();
  language_.erase(it, it_end);
  counter_ = 0;
}

void language::Update(set<string> lenguaje)
{
  Erase();
  language_ = lenguaje; 
}

void language::Add_string(string a)
{
  language_.insert(a);
}

void language::Remove_string(string a)
{
  language_.erase(a);
}

void language::Write(ostream& os) const
{
  for (set<string>::iterator it=language_.begin(); it!=language_.end(); ++it)
    os << ' ' << *it;
  os << endl;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 02/10/2019
 *
 *
**/

