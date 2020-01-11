/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         grammar.hpp                                                  =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     grammar class.
 *  \details   This class is used for saving the grammar data.
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
#include <utility>
#include <sstream>
#include <vector>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "Alphabet.hpp"
#include "State.hpp"
#include "NFA.hpp"
using namespace std;
/*------------------------------------------------*/


class Grammar {

  private:
    set <char> V_;
    Alphabet g_alphabet_;
    char S_;
    set <pair <char, vector <char> > > P_;

  public:
    // Constructor and Destructor
    Grammar();
    Grammar(Grammar&);
    Grammar(string&);
    ~Grammar();

    // Functions
    NFA ConvertToNFA(void);
    void Generate_Grammar (string&);
    void Modificacion(string&);

    // Read and Write
     void Write_Grammar (void) const;

};