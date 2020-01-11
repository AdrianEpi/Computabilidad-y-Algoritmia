/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         NFA.hpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     NFA class.
 *  \details   This class is used for saving the NFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.3
 *  \date      16/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <fstream>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#pragma once 
#include "Alphabet.hpp"
#include "State.hpp"
#include "DFA.hpp"
using namespace std;
/*------------------------------------------------*/

class NFA {

  private:
    Alphabet alphabet_;
    set <State> states_;
    State initial_;
    set <State> acept_;
    unsigned int States_num;

  public:
    // Constructor and Destructor
    NFA();
    NFA(NFA&);
    NFA(string&);
    ~NFA();

    // Getters and Setters
    Alphabet get_Alphabet(void) const;
    void set_Alphabet(const Alphabet&);
    set <State> get_States(void) const;
    void set_States(const set <State>&);
    State get_Initial(void) const;
    void set_Initial(const State&);
    set <State> get_Acepted(void) const;
    void set_Acepted(const set <State>&);
    unsigned int get_States_Num(void) const;

    // Functions
    void Generate_NFA(string&);
    set <State> Epsilon_Clausure(set<State>&);
    set <State> Move(set<State>&, char);
    void UnMark(set<State>&);
    bool Is_In(State, set<State>) const;
    bool Mark(State, set<State>) const;
    void Create_NFA_File(string&) const;

    // Read and Write
    void Write_DFA(DFA&, string&);
    void Write_DFA(DFA, string&);
    
  };