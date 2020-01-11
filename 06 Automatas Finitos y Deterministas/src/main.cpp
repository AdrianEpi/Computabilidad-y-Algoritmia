/*===================================================================================
=====================================================================================
		=                                                                           =
		=            Proyecto:      Práctica 06 Autómatas Finitos y Deterministas   =
		=            Archivo:       main.cpp                                        =
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
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/reader.hpp"
#include "../class/DFA.hpp"
#include "../class/state.hpp"
#include "../class/transition.hpp"
#include "../class/alphabet.hpp"
/*------------------------------------------------*/
/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
void grep(void);

int main (int argc, char* argv[]) {

  string ayuda = "--help";
  system("clear");
  if (argc == 1)
    cout << endl << " Modo de empleo: ./prueba Inputs/Input.dfa Outputs/Output.gv " << endl << " Pruebe './prueba --help' para mas informacion." << endl << endl;
  else if (argc == 2 && argv[1] == ayuda) 
    grep();
  else if (argc == 3) 
  {
    string name_file_in = argv[1];
    string name_file_out = argv[2];
    reader fich_transf (name_file_in, name_file_out);
    fich_transf.RunProgram();   
  }
  else
    cout << "Se ha introducido un numero invalido o erroneo de argumentos, porfavor vuelva a intentarlo o ejecute ./prueba --help para más información." << endl << endl;
  
  /*string aux = "dot −Tsvg < ";
  aux += argv[2];
  aux += " > DFA.svg";
  char sentinel[aux.size()];
  strcpy(sentinel, aux.c_str());
  system(sentinel);*/
}

// Descripcion de como funciona el programa 
void grep(void) 
{
  cout << " ============================================ MAN DFA ============================================" << endl << endl << " Para la correcta ejecucion del programa debemos seguir los siguientes pasos:" << endl << endl << "  1. Se debe pasar como parametros al ejecutar el programa, el nombre del fichero del que desea leer y en el que se va a guardar." << endl << endl << "     - Se hara de la siguiente forma: \n\t\t./prueba Inputs/Input.dfa Outputs/Output.gv" <<endl << endl << "  2. El programa se encargara de analizar los comentarios del fichero de entrada, y mientras, procedera a su eliminacion en el fichero de salida." << endl << endl << "  3. El fichero de entrada debe seguir el formato siguiente y ante cualquier posible error pues no se obtendrá una buena salida:" << endl << "      - Primera linea: numero de simbolos del alfabeto." << endl << "      - N lineas: simbolos del alfabeto." << endl << "      - Siguiente linea: numero de estados del alfabeto." << endl << "      - M lineas: nombre de cada estado." << endl << "      - Siguiente linea: nombre del estado inicial." << endl << "      - Siguiente linea: numero de estados de aceptacion." << endl << "      - F lineas: nombre de los estados de aceptacion." << endl << "      - Siguiente linea: numero de transiciones de estados." << endl << "      - T lineas: transiciones, donde se debe especificar con que simbolo la realizara y hacia que estado pasara." << endl; 
}

/*=================================================================*/
/*========================= End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 25/10/2019
 *
 *
**/


