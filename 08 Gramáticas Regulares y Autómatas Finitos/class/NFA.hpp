/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         NFA.hpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     NFA class.
 *  \details   This class is used for saving the NFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#pragma once 
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <fstream>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
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
    unsigned int states_num_;

  public:
    // Constructor and Destructor
    NFA();
    NFA (NFA&);
    NFA (string&);
    ~NFA();

    // Setters
    void set_Alphabet (const Alphabet&);
    void set_States (const set <State>&);
    void set_Initial (const State&);
    void set_acept (const set <State>&);

    // Getters
    Alphabet get_Alphabet (void) const;
    set <State> get_States (void) const;
    State get_Initial (void) const;
    set <State> get_Acepted (void) const;
    unsigned int get_States_Num (void) const;

    // Functions
    void Generate_NFA (string&);
    set <State> EPSILON_Clausure (set<State>&);
    set <State> Move (set<State>&, char);
    DFA Build_DFA(void);
    void Unmark (set<State>&);
    bool Is_In (State, set<State>) const;
    bool Mark (State, set<State>) const;
    void Create_NFA_file (string&) const;

    // Read and Write
    void Write_NFA (void) const;
    void WriteDFA (DFA&, string&);
    void WriteDFA (DFA, string&);
    
};