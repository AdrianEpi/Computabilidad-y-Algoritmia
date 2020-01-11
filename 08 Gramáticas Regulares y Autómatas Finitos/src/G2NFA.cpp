/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         G2NFA.cpp                                                    =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     G2NFA class, main program.
 *  \details   This class is used for saving the G2NFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
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
#include "../class/NFA.hpp"
#include "../class/Grammar.hpp"
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
    system("clear");
    program_explication();
  } else if (argc == 3) {
    system("clear");
    string name_file_in = argv[1];
    string name_file_out = argv[2];
    Grammar grammar(name_file_in);
    NFA nfa;
    nfa = grammar.ConvertToNFA();
    nfa.Create_NFA_file(name_file_out);
    cout << "\n\n"<< "El fichero de salida ha sido escrito con exito."   << "\n\n";
  } else {
    system("clear");
    cout << "Se ha introducido un numero invalido o erroneo de argumentos, por favor vuelva a intentarlo"  << "\n\n";
  }
}

/**
 * @brief Funcion que se encarga de mostrar un mensaje como si se tratase de un greep
 */
void greep (void) {
  cout << "\n" << " Modo de empleo: ./G2NFA input.gra output.nfa " << "\n";
  cout << " Pruebe './G2NFA --help' para mas informacion." << "\n\n";
}

/**
 * @brief Descripcion de como funciona el programa 
 */
void program_explication(void) {

  system("clear");
  cout << " --------------------------------------------------- GUIA DE AYUDA AL USUARIO ----------------------------------------------------" << "\n\n\n";
  cout << "  Para la correcta ejecucion del programa debemos seguir los siguientes pasos:" << "\n\n";
  cout << "    1. Se debe pasar como parametros al ejecutar el programa, el nombre del fichero del que desea leer y en el que se va a guardar." << "\n\n";
  cout << "       - Se hara de la siguiente forma: ./program fichero_entrada.gra fichero_salida.nfa" <<"\n\n";
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
  cout << "      - F lineas: nombre de los estados de aceptacion." << "\n";
  cout << "      - Siguiente linea: symbolo no terminal -> symbolos_terminales o no terminales." << "\n";
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
  cout << "2\n0\n1\n2\nS\nA\nS\n3\n";
  cout << "S -> 0A\nA -> 10A\nA -> ~\n\n";
}