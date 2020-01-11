/*===================================================================================
=====================================================================================
	=                                                                           =
	=            Proyecto:      Práctica 12 Algoritmos Voraces (Greedy)         =
	=            Archivo:       MoneyChanger.cpp                                =
	=            Autor:         Adrián Epifanio Rodríguez Hernández             =
	=            Fecha:         12/12/2019                                      =
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
#include <vector>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/MoneyChanger.hpp"
/*------------------------------------------------*/

/*===================================================================
=                            Class PROGRAM                          =
===================================================================*/

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  money  The money
 */
MoneyChanger::MoneyChanger( double money )
{
	money_ = 0.00f;
	Generate_Possible_Candidates();
	money = money * 100;
	money_ = (int) money; //This converses the money in € to cents
	int position = 0;
	int temp = money;
	while(temp != 0)
	{
		int temp_ammount = Candidate_Selector(temp, position);
		if (temp_ammount != 0)
			result_vector_.push_back(temp_ammount);
		else
			temp=0;
	}
}


/**
 * @brief      Gets the calculated.
 *
 * @return     The calculated.
 */
double MoneyChanger::get_Calculated( void )
{
	double ammount = 0;
	for (int i = 0; i < result_vector_.size(); i++)
	{
		ammount += result_vector_[i] * 0.01 * ammount_vector_[i];
	}
	return ammount;

}
/**
 * @brief      Prints the solution on screen
 */
void MoneyChanger::Write( void )
{
	int billetes = 0, monedas = 0;
	std::cout << "The best solution is: \n{\t";
	for (int i = 0; i < result_vector_.size(); i++)
	{
		if (result_vector_[i] >= 100)
		{
			std::cout << (result_vector_[i] * 0.01) << "€x" << ammount_vector_[i] << "    ";
			billetes++;
		}
		else
		{
			std::cout << (result_vector_[i]) << "¢x" << ammount_vector_[i] << "    ";
			monedas++;
		}
	}
	std::cout << "\t}" << std::endl << std::endl;
	std::cout << "Se han utilizado " << billetes << " billetes y " << monedas << " monedas." << std::endl;
}


/**
 * @brief      Calculates the best candidate for the received ammount of money
 *
 * @param      new_money  The new money
 * @param      position   The position
 *
 * @return     The best candidate selected
 */
int MoneyChanger::Candidate_Selector( int &new_money, int &position )
{
	int divide;
	int candidate;
	for (int i = position; i < possible_candidates_.size(); i++)
	{
		divide = new_money / possible_candidates_[i];
		if (divide > 0)
		{
			candidate = possible_candidates_[i];
			new_money -= candidate * divide;
			position = i+1;
			ammount_vector_.push_back(divide);
			return candidate;
		}
	}
}


/**
 * @brief      Generates the possible cadidate vector from an array
 */
void MoneyChanger::Generate_Possible_Candidates()
{
	int m[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	std::vector<int> v( m, m + sizeof(m) / sizeof (*m) );
	set_Possible_Candidates(v);
}
/*=================================================================*/
/*========================= End of Class  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 12/12/2019
 *
 *
**/