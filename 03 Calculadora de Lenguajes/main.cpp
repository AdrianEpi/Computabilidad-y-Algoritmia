/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 3 Calculadora de lenguajes   =
  =            Archivo:       main.cpp                              =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         02/09/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "calculator.hpp"
#include "language.hpp"
#include "reader.hpp"
#define MAX_WORDS 100
/*------------------------------------------------*/
/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
int main(int argc, char *argv[])
{
  int function = 0, potencia = 1;
  char function_char[5], output_char[30];
  string mode, input, output, empty;
  if (argc <= 3)
  {
    cout << "ERROR entrada erronea...\n Por favor escriba como primer argumento el nombre de fichero de texto .txt de entrada, como segundo argumento el nombre del fichero de texto .txt de salida, como tercer argumento la opción elegida, y en caso necesario, como 4 el exponente de la potencia, cierre positivo o cierre de Kleene." << endl << endl << "Un ejemplo sería:\n ./prueba entrada.txt salida.txt 1" << endl << endl << " 1. Concatenación\n 2. Unión\n 3. Intersección\n 4. Diferencia\n 5. Sublenguajes\n 6. Igualdad de lenguajes\n 7. Inversa\n 8. Potencia\n 9. Cierre Positivo\n 10. Cierre Kleene" << endl << endl;
    return 0;
  }
  else if ((argc == 4) || (argc == 5))
  {
    input = argv[1];
    output = argv[2];
    mode = argv[3];
    strcpy(function_char, mode.c_str());
    strcpy(output_char, output.c_str());
    function = atoi(function_char);
    if (argc == 5)
    {
      mode = argv[4];
      strcpy(function_char, mode.c_str());
      potencia = atoi(function_char);
    }
  }
  else
  {
    cout << "ERROR entrada erronea...\n Por favor escriba como primer argumento el nombre de fichero de texto .txt de entrada, como segundo argumento el nombre del fichero de texto .txt de salida, como tercer argumento la opción elegida, y en caso necesario, como 4 el exponente de la potencia, cierre positivo o cierre de Kleene." << endl << endl << "Un ejemplo sería:\n ./prueba entrada.txt salida.txt 1" << endl << endl << " 1. Concatenación\n 2. Unión\n 3. Intersección\n 4. Diferencia\n 5. Sublenguajes\n 6. Igualdad de lenguajes\n 7. Inversa\n 8. Potencia\n 9. Cierre Positivo\n 10. Cierre Kleene" << endl << endl;
    return 0;
  }
  reader read(input);
  int aux = read.get_Counter() + 1;
  language lang[aux]; //Creamos un vector de lenguajes de tamaño igual al leido del fichero de entrada.
  for (int i = 0; i <= read.get_Counter(); i++)
    lang[i].set_Language(read.get_Languages_tmp(i));
  ofstream file;
  file.open(output_char);
  if (file.is_open())
  {
    switch (function)
    {
      case 1:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          file << "L[" << i+1 << "]L[" << i+2 << "] :" << endl;
          calculator calculadora;
          calculadora.Concatenacion(lang[i].get_Language(), lang[i+1].get_Language());
          calculadora.Write(file);
          i++;
        }
        break;
      case 2:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          file << "L[" << i+1 << "] Union L[" << i+2 << "] :" << endl;
          calculator calculadora;
          calculadora.Union(lang[i].get_Language(), lang[i+1].get_Language());
          calculadora.Write(file);
          i++;
        }
        break;
      case 3:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          file << "L[" << i+1 << "] Interseccion L[" << i+2 << "] :" << endl;
          calculator calculadora;
          calculadora.Interseccion(lang[i].get_Language(), lang[i+1].get_Language());
          calculadora.Write(file);
          i++;
        }
        break;
      case 4:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          file << "L[" << i+1 << "] - L[" << i+2 << "] :" << endl;
          calculator calculadora;
          calculadora.Diferencia(lang[i].get_Language(), lang[i+1].get_Language());
          calculadora.Write(file);
          i++;
        }
        break;
      case 5:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          calculator calculadora;
          if (calculadora.Sublenguajes(lang[i].get_Language(), lang[i+1].get_Language()))
          {
            file << "L[" << i+1 << "]" << " es sublenguaje de " << "L[" << i+2 << "]";
            if (calculadora.Sublenguajes(lang[i+1].get_Language(), lang[i].get_Language()))
              file << " y L[" << i+2 << "]" << " es sublenguaje de " << "L[" << i+1 << "]";
            file << endl;
          }
          else if (calculadora.Sublenguajes(lang[i+1].get_Language(), lang[i].get_Language()))
            file << "L[" << i+2 << "]" << " es sublenguaje de " << "L[" << i+1 << "]" << endl;
          
          else
            file << "L[" << i+1 << "] no es sublenguaje de " << "L[" << i+2 << "] ni viceversa" << endl;
          i++;
        }
        break;
      case 6:
        for (int i = 0; i <= (read.get_Counter()/2); i++)
        {
          calculator calculadora;
          if (calculadora.Igualdad(lang[i].get_Language(), lang[i+1].get_Language()))
            file << "Los lenguages L[" << i+1 << "] y L[" << i+2 << "] son iguales" << endl;
          else
            file << "Los lenguages L[" << i+1 << "] y L[" << i+2 << "] no son iguales" << endl;
          i++;
        }
        break;
      case 7:
        for (int i = 0; i < read.get_Counter(); i++)
        {
          file << "Inversa de L[" << i+1 << "]" << endl;
          calculator calculadora;
          calculadora.Inversa(lang[i].get_Language());
          calculadora.Write(file);
        }
        break;
      case 8:
        for (int i = 0; i < read.get_Counter(); i++)
        {
          file << "L[" << i+1 << "]^" << potencia << endl;
          calculator calculadora;
          calculadora.Potencia(lang[i].get_Language(), empty, potencia);
          calculadora.Write(file);
        }
        break;
      case 9:
        for (int i = 0; i < read.get_Counter(); i++)
        {
          file << "L[" << i+1 << "]+" << endl;
          calculator calculadora;
          calculadora.Cierre_Positivo(lang[i].get_Language(), empty, potencia);
          calculadora.Write(file);
        }
        break;
      case 10:
        for (int i = 0; i < read.get_Counter(); i++)
        {
          file << "L[" << i+1 << "]*" << endl;
          calculator calculadora;
          calculadora.Cierre_Kleene(lang[i].get_Language(), empty, potencia);
          calculadora.Write(file);
        }
        break;
      default:
        break;
    }
    file.close();
  }
}
/*=================================================================*/
/*========================= End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 02/09/2019
 *
 *
**/

