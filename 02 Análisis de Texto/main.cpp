/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 2 Análisis de Texto          =
    =            Archivo:       main.cpp                              =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         27/09/2019                            =
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
#include "analizador.hpp"
#define MAX_WORDS 100
/*------------------------------------------------*/
/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
int main(int argc, char *argv[])
{
  word a[MAX_WORDS];
  string palabra;
  set<string> reserved_s;
  int i = 0, k = 0,sentinela = 0;
  char filename[85], output[30];
  string filename2;
  if (argc == 1)
    cout << "Entrada sin comandos...\n Por favor escriba como primer argumento el nombre de fichero de texto .txt de entrada y como segundo argumento el nombre del fichero de text .txt de salida. En caso de solo introducir el fichero de entrada o de no introducir ningún fichero se creará un fichero de salida \"./Outputs.Output.txt\" en el que se guardarán los datos." << endl << endl << "Un ejemplo sería:\n ./prueba entrada.txt salida.txt" << endl << endl;
  else if (argc == 2)
  {
    filename2 = argv[1];
    strcpy(filename, filename2.c_str()); //strcpy para pasar un string a cadena de char
    sentinela = 1;
  }
  else if (argc == 3)
  {
    filename2 = argv[1];
    strcpy(filename, filename2.c_str());
    sentinela = 2;
    filename2 = argv[2];
    strcpy(output, filename2.c_str());
  }
  ifstream textfile;
  textfile.open("./Inputs/Reserved.txt");
  if (textfile.is_open())
  {
    while (!textfile.eof())
    {
      textfile >> palabra;
      reserved_s.insert(palabra);
    }
    textfile.close();
    for (int k = 0; k < MAX_WORDS; k++)
      a[k].Reserved_List(reserved_s);
  }
  textfile.open(filename);
  if (textfile.is_open()){
    while(!textfile.eof())
    {
      textfile >> palabra;
      a[k].Update(palabra);
      i++;
      k++;
    }
    textfile.close();
  }
  ofstream file;
  if (sentinela == 1)
    file.open("./Outputs/Output.txt", ios::out);
  else
    file.open(output, ios::out);
  if (file.fail())
  {
    cout << "Error al abrir el archivo" << endl;
    exit(1);
  }
  else
  {
    int mode0 = 0, mode1 = 1;
    for (int k = 0; k < i; k++ )
    {
      a[k].Write(file, mode0);
      if ((k -1) < 0)
        file << " -";
      else
        a[k-1].Write(file, mode1);
      a[k+1].Write(file, 1);
      file << endl;
    }

    file.close();
  }
}
/*=================================================================*/
/*=========================  End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 27/09/2019
 *
 *
**/

