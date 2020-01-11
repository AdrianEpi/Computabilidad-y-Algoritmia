/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         Grammar.cpp                                                  =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     Grammar class.
 *  \details   This class is used for saving the Grammar data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.3
 *  \date      16/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "Grammar.hpp"
#include <stdio.h>
#include <cstring>
/*------------------------------------------------*/

/**
 * @brief Constructor por defecto
 */
Grammar::Grammar () :
V_(),
g_alphabet_(),
S_(),
P_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param aux Nfa pasado por refencia
 */
Grammar::Grammar (Grammar& aux) :
V_(),
g_alphabet_(),
S_(),
P_()
{
  V_ = aux.V_;
  g_alphabet_ = aux.g_alphabet_;
  S_ = aux.S_;
  P_ = aux.P_;
}

/**
 * @brief Costruye el NFA a traves del nombre de un fichero de entrada
 * @param in_file 
 */
Grammar::Grammar (string& in_file):
V_(),
g_alphabet_(),
S_(),
P_()
{
  if (Modificacion(in_file))
  {
    cout << "Ya está en forma normal de Chomsky" << endl;
  }
  else
  {
    cout << "No está en forma normal de Chomsky" << endl;
    Grammar_Generator(in_file);
  }
}

/**
 * @brief Destructor por defecto
 */
Grammar::~Grammar () {}

/**
 * @brief Se encarga de convertir la gramatica de entrada en una gramactica que cumpla FNC ejecutando las dos partes del algoritmo por separado
 */
void Grammar::Convert_CNF (void) {

  New_No_Terminal_Symbol();
  Create_Group();
}

/**
 *
 * @brief Se encarga de hacer la modificacion cuya funcion es comprobar si la gramatica de entrada esta ya o no en forma normal de Chomsky
 *
 */

bool Grammar::Modificacion (string& in_file) {
  ifstream ifs (in_file, ios::in);
  string aux;
  int counter = 0;
  if (ifs.fail()) {
    cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  }
  else
  {
    while (!ifs.eof())
    {
      ifs >> aux;
      if (aux == "->")
      {
        ifs >> aux;
        char sentinel[aux.size()];
        strcpy(sentinel, aux.c_str());
        for (int i = 0; i < aux.size(); i++)
        {
          if (aux.size() > 2)
            return false;
          else if (aux.size() == 2)
          {
            if ((sentinel[i] >= 'a' && sentinel[i] <= 'z') && (sentinel[i+1] >= 'a' && sentinel[i+1] <= 'z'))
            {
              return false;
            }
            else if ((sentinel[i] >= 'a' && sentinel[i] <= 'z') && (sentinel[i+1] >= 'A' && sentinel[i+1] <= 'Z'))
            {
              return false;
            }
            else if ((sentinel[i] >= 'A' && sentinel[i] <= 'Z') && (sentinel[i+1] >= 'a' && sentinel[i+1] <= 'z'))
            {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
}

/**
 * @brief Primera parte del alogritmo de FNC que se encarga de crear los nuevos estados no terminales y sustituir las reglas de produccion correspondientes
 */
void Grammar::New_No_Terminal_Symbol (void) {
 
  set <pair <string, vector <char>>> aux_new_no_ter;
  // Se crean los nuevos estados no terminales 
  for (pair <string, vector <char>> pai: P_) {
    if (pai.second.size() >= 2)
      for (char c: pai.second)
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
          pair <string, vector <char>> aux_pair;
          string aux_string = "Q";
          vector <char> aux_char;
          aux_string += c;
          aux_pair.first = aux_string;
          aux_char.push_back(c);
          aux_pair.second = aux_char;
          aux_new_no_ter.insert(aux_pair);  
        }
  }

  // Se añaden estos al conjunto de symbolos no terminales
  for (pair <string, vector <char>> pai: aux_new_no_ter)
    V_.insert(pai.first);

  // Se modifican las reglas de produccion que ya teniamos 
  for (pair <string, vector <char>> pai: P_) {
    if (pai.second.size() == 1) {
      aux_new_no_ter.insert(pai);
    } else if (pai.second.size() >= 2) {
      pair <string, vector <char>> aux_pair;
      aux_pair.first = pai.first;
      vector <char> aux_char;
      for (int i = 0; i < pai.second.size(); i++) {
        if ((pai.second[i] >= 'a' && pai.second[i] <= 'z') || (pai.second[i] >= '0' && pai.second[i] <= '9')) {
          string aux_string = "Q";
          aux_string += pai.second[i];
          for (string str: V_)
            if (str == aux_string) {
              aux_char.push_back(str[0]);
              aux_char.push_back(str[1]);
            }
        } else {
          aux_char.push_back(pai.second[i]);
        }
      }
      aux_pair.second = aux_char;
      aux_new_no_ter.insert(aux_pair);
    }
  }

  P_ = aux_new_no_ter;
}

/**
 * @brief Segundo parte del algortimo FNC que se encarga de crear agrupaciones de pares y crear sus producciones correspondientes
 */
void Grammar::Create_Group (void) {

  stack <string> aux_stack;
  set <pair <string, vector <char>>> aux_new_no_ter;
  int name_cont = 0;

  for (pair <string, vector <char>> pai: P_) {
    if (Size_Check(pai.second)) {
      aux_new_no_ter.insert(pai);
    } else {
      for (int i = 0; i < pai.second.size(); i++) {
        if (pai.second[i] == 'Q') {
          string aux_string;
          aux_string = pai.second[i];
          aux_string += pai.second[i + 1];
          aux_stack.push(aux_string);
          i++;
        } else {
          string aux_string;
          aux_string = pai.second[i];
          aux_stack.push(aux_string);
        }
      }
      bool first = true;
      while (!aux_stack.empty()) {
        if (first == true) {
          string aux_string1 = aux_stack.top();
          aux_stack.pop();
          string aux_string2 = aux_stack.top();
          aux_stack.pop();
          string new_Name = "Z";
          int sum = 97 + name_cont;
          new_Name += sum;
          name_cont++;
          aux_stack.push(new_Name);
          string production = aux_string2 + aux_string1;
          pair <string, vector <char>> aux_pair;
          aux_pair.first = new_Name;
          for (char c: production)
            aux_pair.second.push_back(c);
          aux_new_no_ter.insert(aux_pair);
          first = false;
        } else {
          string aux_string1 = aux_stack.top();
          aux_stack.pop();
          string aux_string2 = aux_stack.top();
          aux_stack.pop();
          if (aux_stack.empty()) {
            string production = aux_string2 + aux_string1;
            pair <string, vector <char>> aux_pair;
            aux_pair.first = pai.first;
            for (char c: production)
              aux_pair.second.push_back(c);
            aux_new_no_ter.insert(aux_pair);
          } else {
            string new_Name = "Z";
            int sum = 97 + name_cont;
            new_Name += sum;
            name_cont++;
            aux_stack.push(new_Name);
            string production = aux_string2 + aux_string1;  
            pair <string, vector <char>> aux_pair;
            aux_pair.first = new_Name;
            for (char c: production)
              aux_pair.second.push_back(c);
            aux_new_no_ter.insert(aux_pair);
          }
        }
      }    
    }
  }
  for (pair <string, vector <char>> pai: aux_new_no_ter)
    V_.insert(pai.first);

  P_ = aux_new_no_ter;
}

/**
 * @brief Metodo que se encarga de comprobar si la regla actual solamente tiene o una o dos symbolos terminales
 * @param check_string Contiene la palabra que vamos a analizar 
 */
bool Grammar::Size_Check (vector <char> check_string) const {
   
   if (check_string.size() == 1)
    return true;
  else if (check_string.size() == 2)
    return true;
  else if (check_string.size() == 3 && (check_string[0] == 'Q' || check_string[1] == 'Q'))
    return true;
  else if (check_string.size() == 4 && (check_string[0] == 'Q' && check_string[2] == 'Q'))
    return true;
  else 
    return false;
}

/**
 * @brief Metodo que se encarga de leer de un fichero de entrada la gramatica y detecta si es correcta y no y dice sus posibles fallos
 * @param in_file Cadena de caracteres que contiene el nombre del fichero de donde se leera la gramatica
 */
void Grammar::Grammar_Generator (string& in_file) {
  
  ifstream ifs (in_file, ios::in);

  if (ifs.fail()) {
    cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  } else { 
    string aux_string;
  
    do {
      getline(ifs, aux_string);
    } while ((aux_string[0] == '/' && aux_string[1] == '/'));

    int n_Symbol = stoi(aux_string);
    aux_string = "";
    string aux_chain;

    for (int i = 0; i < n_Symbol; i++) {
      ifs >> aux_string;
      aux_chain += aux_string;
    }
    g_alphabet_.Alphabet_Create(aux_chain);

    int n_states;
    ifs >> n_states;
    aux_string = "";

    for (int i = 0; i < n_states; i++) {
      ifs >> aux_string;
      V_.insert(aux_string);
    }

    aux_string = "";
    ifs >> aux_string;

    bool check = false;
    for (string est: V_)
      if (est == aux_string)
        check = true;
    
    if (check == true) {
      S_ = aux_string;
    } else {
      cout << " El symbolo inicial no pertenece al conjunto V, porfavor corrijalo." << "\n\n";
      exit(2);
    }

    int n_rules;
    ifs >> n_rules;
    string transition;
    check = false;
    aux_string = "";

    vector <char> aux_vector;

    for (int i = 0; i < n_rules; i++) {
      ifs >> aux_string; 
      for (string str: V_) 
        if (aux_string == str) {
          check = true;
          break;
        }
      if (check == false) {
          cout << " El symbolo no terminal es incorrecto por cantidad de caracteres que posee, por favor corrijalo." << "\n\n";
          exit(2);  
      } else {
          transition = aux_string;
      }
      check = false;
      ifs >> aux_string;
      if (aux_string[0] == '-' && aux_string[1] == '>') {
        ifs >> aux_string;
      } else {
        cout << " La forma de expresar la transicion no es la correcta, por favor corrijala." << "\n\n";
        exit(2);  
      }
      for (int j = 0; j < aux_string.size(); j++) {
        if ((aux_string[j] >= 'a' && aux_string[j] <= 'z') || (aux_string[j] >= '0' && aux_string[j] <= '9') || aux_string[j] == '~') {
          check = true;
        } else if ((aux_string[j] >= 'A' && aux_string[j] <= 'Z')) {
          for (string str: V_) {
            if (str[0] == aux_string[j]) {
              check = true;
            }
            if(str[0] == aux_string[j] && str[0] == aux_string[j + 1]) {
              check = true;
              j++;
              break;
            }
          }
        } else {
          check = false;
        }
        if (check == false) {
          cout << " Alguno de los symbolos que se quieren emplear como transición no pertencen a el conjunto de simolos terminales o no terminales," << "\n";
          cout << " por favor corrijalo." << "\n\n";
          exit(2);
        }
      }
      check = false;
      for(char est: aux_string)
        aux_vector.push_back(est);
      
    pair <string, vector <char>>  aux_pair (transition, aux_vector);
    P_.insert(aux_pair);
    aux_vector.clear();
    }
    aux_string = "";
    ifs >> aux_string;
    if (aux_string != "") {
      cout << "Error por introducir una cantidad invalida de elementos, por favor corrijalo para poder continuar. " << "\n\n";
      exit(2);
    }
  }
}

/**
 * @brief Metodo que se encarga de imprimir el fichero de salida de tipo .gra
 * @param out_file Nombre del fichero que se va a utilizar para gurardar la salida de datos
 */
void Grammar::Create_CNF_File (string& out_file) const {

  ofstream os (out_file, ios::out);

  if (os.fail()) {
    cout << "Error el documento que trata de usar para guardar no es valido, por favor introduzca uno que si lo sea."
         << "\n\n";
    exit(2);
  } else {

    int cont = 0;
    for (string str: V_) 
      if (str == S_) 
        Write(str, cont, os);

    cont = 0;
    for (string str: V_) 
      if (str.size() == 1 && str != S_) 
        Write(str, cont, os);

    cont = 0;
    for (string str: V_) 
      if (str[0] == 'Q') 
        Write(str, cont, os);

    cont = 0;
    for (string str: V_) 
      if (str[0] == 'Z') 
        Write(str, cont, os);
  }
}

/**
 * @brief Metodo que se encarga de imprimir las reglas de produccion de un symbolo concreto 
 * @param str symbolo del que se van a imprimir sus reglas de produccion
 * @param cont Numero de reglas hasta el momento para evitar imprimir la barra por ultima vez
 * @param os Fichero de salida donde se va a escribir las reglas de produccion
 */
void Grammar::Write (string& str, int& cont, ofstream& os) const {
  os << str <<  " -> ";
  for (pair <string, vector <char> > pai: P_) 
    if (str == pai.first) 
      cont++;
  int i = 0;
  for (pair <string, vector <char> > pai: P_) {
    if (str == pai.first) {
      for(char c: pai.second)
        os << c;
    i++;
    if (i != cont)
      os << " | ";
    }
  }
  cont = 0;
  os << "\n";
}