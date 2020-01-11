/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         G2CNF.cpp                                                    =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     G2CNF class.
 *  \details   This class is used for saving the G2CNF data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.3
 *  \date      16/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#include <iostream>
#include <string>
#include <cstdlib>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "NFA.hpp"
#include "Grammar.hpp"
using namespace std;
/*------------------------------------------------*/

void greep (void);
void program_explication(void);
void press_to_continue (void);
void example (void);

int main (int argc, char* argv[]) {

  string ayuda = "--help";

  if (argc == 1) {
    greep();
  } else if (argc == 2 && argv[1] == ayuda) {
   // system("clear");
    program_explication();
  } else if (argc == 3) {
  //  system("clear");
    string name_file_in = argv[1];
    string name_file_out = argv[2];
    Grammar grammar(name_file_in);
    grammar.Convert_CNF();
    grammar.Create_CNF_File(name_file_out);
    cout << "\n\n"<< "El fichero de salida ha sido escrito con exito."   << "\n\n";
  } else {
    //system("clear");
    cout << "Se ha introducido un numero invalido o erroneo de argumentos, por favor vuelva a intentarlo"  << "\n\n";
  }
}

/**
 * @brief Funcion que se encarga de mostrar un mensaje como si se tratase de un greep
 */
void greep (void) {
  
  cout << "\n" << " Modo de empleo: ./G2CNF input.gra output.nfa " << "\n";
  cout << " Pruebe './G2CNF --help' para mas informacion." << "\n\n";
}

/**
 * @brief Descripcion de como funciona el programa 
 */
void program_explication(void) {

  system("clear");
  cout << " --------------------------------------------------- GUIA DE AYUDA AL USUARIO ----------------------------------------------------" << "\n\n\n";
  cout << "  Para la correcta ejecucion del programa debemos seguir los siguientes pasos:" << "\n\n";
  cout << "    1. Se debe pasar como parametros al ejecutar el programa, el nombre del fichero del que desea leer y en el que se va a guardar." << "\n\n";
  cout << "       - Se hara de la siguiente forma: ./program fichero_entrada.gra fichero_salida.gra" <<"\n\n";
  cout << "    2. El programa se encargara de transformar el fichero de entrada en uno de salida reconocible por el programa Grammar, " << "\n";
  cout << "    por ello es de vital importancia que el fichero de salida termine en .gra en caso contrario no sera reconocido por " << "\n";
  cout << "    el otro programa." << "\n\n";
  cout << "    3. En cuanto al fichero de entrada se permitira una mayor flexibilidad ya que su entrada .gra pudiera ser tambien de " << "\n";
  cout << "    tipo .txt. " << "\n\n";
  cout << "    4. El fichero de entrada debe seguir el formato siguiente y ante cualquier posible error pues no se obtendrá una buena salida:" << "\n\n";
  cout << "      - Primera linea: numero de symbolos del alfabeto." << "\n";
  cout << "      - N lineas: symbolos del alfabeto." << "\n";
  cout << "      - Siguiente linea: numero de symbolos no terminales." << "\n";
  cout << "      - M lineas: nombre (symbolo) de cada estado." << "\n";
  cout << "      - Siguiente linea: nombre del symbolo inicial." << "\n";
  cout << "      - Siguiente linea: numero de reglas." << "\n";
  cout << "      - F lineas: reglas de producción de cada symbolo." << "\n";
  press_to_continue();
  example();
}

/**
 * @brief Pausa durante un instante el programa 
 */
void press_to_continue (void) {

  cout << "    Pulsa para ver un ejemplo : ";
  do {} while (cin.get() != '\n');
}

/**
 * @brief Despues de la pausa del program se muestra un ejemplo del mismo 
 */
void example (void) {
  
  cout << "\n\n";
  cout << "3\na\nb\nc\n3\nS\nX\nY\nS\n";
  cout << "13\nS -> aXbX\nS -> abX\nS -> aXb\nS -> ab\n";
  cout << "X -> aY\nX -> bY\nX -> a\nX -> b\nY -> aY\nY -> bY\nY -> a\n";
  cout << "Y -> b\nY -> c\n\n";
}