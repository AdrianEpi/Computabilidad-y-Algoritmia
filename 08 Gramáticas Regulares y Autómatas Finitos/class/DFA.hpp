/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         DFA.cpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     DFA class.
 *  \details   This class is used for saving the DFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#pragma once
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "Alphabet.hpp"
#include "State.hpp"
using namespace std;
/*------------------------------------------------*/
class DFA {

  private:
    Alphabet alpha_;
    set <State> states_;
    unsigned int states_num_; 
    set <State> acepted_states_;
    State  initial_state_;
    string in_file_;

  public:
    // Constructor and Destructor
    DFA ();
    DFA (const DFA&);
    ~DFA ();

    // Setters
    void set_DFA (string&);
    void set_Alphabet (void);
    void set_States (set <State>&);
    void set_States_Num (unsigned int);
    void set_Acepted_States (set <State>&);
    void set_In_File (string&);
    void set_Initial_State (State);

    // Getters
    Alphabet get_Alphabet (void) const;
    set <State> get_States (void) const;
    unsigned int get_States_Num (void) const;
    set <State> get_Acepted_States (void) const;
    State get_Initial_State (void) const;
    string get_in_file (void) const;

    // Read and Write
    void Write_DFA (void) const;
    void Read_File (void);
    void drawDFA(string&);

};
