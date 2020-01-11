/*===================================================================================
=====================================================================================
	=                                                                           =
    =            Proyecto:      Práctica 12 Algoritmos Voraces (Greedy)         =
	=            Archivo:       Greedy.cpp                                      =
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
#include <stdio.h>
#include <stdlib.h>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/MoneyChanger.hpp"
/*------------------------------------------------*/
/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
int main (void){
	double money = 0.00f;
	std::cout << "Type the ammount of money you want to change in €: ";
	std::cin >> money;
	if (0 <= money)
	{
		MoneyChanger change(money);
		if (money == change.get_Calculated())
			change.Write();
		else
			std::cout << "No existe solución" << std::endl;
	}
	else
	{
		std::cout << std::endl << "Error, money must be bigger than price." << std::endl;
		exit(1);
	}
	return 0;
}
/*=================================================================*/
/*========================= End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 12/12/2019
 *
 *
**/


