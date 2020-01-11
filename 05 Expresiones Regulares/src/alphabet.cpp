/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares     =
  =            Archivo:       alphabet.cpp                          =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         16/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/alphabet.hpp"
#define MAX_LENGHT 50
/*------------------------------------------------*/
/*===================================================================
=                           Alphabet Functions                      =
===================================================================*/
alphabet::alphabet()
{
  string input = "Inputs/alphabet.txt";
  char inputname[MAX_LENGHT], sentinel;
  strcpy(inputname, input.c_str());
  ifstream file;
  file.open(inputname);
  if(file.fail())
  {
    cout << "Error en el fichero de alfabeto. Por favor compruebe que el fichero \"alphabet.txt\" de la carpeta Inputs no esta dañado." << endl;
    exit(1);
  }
  while (!file.eof())
  {
    file >> sentinel;
    if ((sentinel != '{') && (sentinel != '}') && (sentinel != ','))
      alphabet_.insert(sentinel);
  }
  file.close();
}

void alphabet::Write()
{
  for (set<char>::iterator it=alphabet_.begin(); it!=alphabet_.end(); ++it)
      cout << ' ' << *it;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 16/10/2019
 *
 *
**/

