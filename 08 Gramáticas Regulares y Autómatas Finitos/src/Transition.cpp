/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         transition.cpp                                               =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     transition class.
 *  \details   This class is used for saving the transition data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "../class/Transition.hpp"
/*------------------------------------------------*/
/**
 * @brief Constructor por defecto
 */
Transition::Transition () :
symbol_(),
next_state_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param actual Hace referencia a la transicion que se quiere inicializar
 */
Transition::Transition (const Transition& actual) :
symbol_(),
next_state_()
{
  symbol_ = actual.get_Symbol();
  next_state_ = actual.get_Next_State();
}

/**
 * @brief Constructor creado con parametros
 * @param symbol symbolo que se necesita para transitar 
 * @param nex_state Estado al que se transita con el symbolo determinado
 */
Transition::Transition (char symbol, unsigned int next_state) {
  symbol_ = symbol;
  next_state_ = next_state;
}

/**
 * @brief Destructor por defecto
 */
Transition::~Transition () {}

/**
 * @return Atributo símbolo
 */
char Transition::get_Symbol (void) const {
  return symbol_;
}

/**
 * @brief Establece el atributo símbolo
 */
void Transition::set_Symbol (char symbol) {
  symbol_ = symbol;
}

/**
 * @return Atributo siguiente estado
 */
unsigned int Transition::get_Next_State (void) const {
  return next_state_;
}

/**
 * @brief Esablece el siguiente estado
 */
void Transition::set_Next_State (unsigned int next_state){
  next_state_ = next_state;
}

/**
 * @brief Saturacion del operador =
 * @note Útil para igualar dos objetos
 */
Transition Transition::operator = (const Transition actual) {

  Transition aux;
  aux.set_Next_State(actual.get_Next_State());
  aux.set_Symbol(actual.get_Symbol());

  return aux;
}

/**
 * @brief Saturacion del operador ==
 * @note Necesario para la creación de conjuntos
 */
bool Transition::operator == (const Transition& trans2) const {
  
  if ((this -> get_Next_State() == trans2.get_Next_State()) && (this -> get_Symbol() == trans2.get_Symbol()))
    return true;
  else
    return false;
}

/**
 * @brief Saturacion del operador !=
 * @note Necesario para la creación de conjuntos
 */
bool Transition::operator != (const Transition& trans2) const {
  
  if (this -> get_Symbol() == trans2.get_Symbol()) 
    if ((this -> get_Next_State() != trans2.get_Next_State()))
      return true;
    else
      return false;
  else
    return true;
}

/**
 * @brief Saturacion del operador <
 * @note Necesario para la creación de conjuntos
 */
bool Transition::operator < (const Transition& trans2) const {

  if((this -> get_Symbol() == trans2.get_Symbol()) && (this -> get_Next_State() < trans2.get_Next_State()))
    return true;
  else if (this -> get_Symbol() < trans2.get_Symbol())
    return true;
  else
    return false;
}

/**
 * @brief  Imprime la transicion (hacia donde va y con que symbolo)
 */
void Transition::Write (void) const {
  cout << "symbolo: " << symbol_ << "  Siguiente estado: " << next_state_ << "\n";
}