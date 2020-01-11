/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         alphabet.hpp                                                 =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     alphabet class.
 *  \details   This class is used for saving the alphabet data.
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
#include <string>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#pragma once 
using namespace std;
/*------------------------------------------------*/


class Alphabet{

  private:
    set <char> alphabet_;

  public:
    // Constructor and Destructor
    Alphabet();
    Alphabet(string&);
    Alphabet(const Alphabet&);
    ~Alphabet() {};

    // Getters
    const set<char>& get_Alphabet(void) const;

    // Functions
    void Alphabet_Create(string);
    int size(void) const;

    // Read and Write
    void Alphabet_Write(void) const;

};