#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <fstream>
#include "rational.hpp"

#define DEFECT_PAIRS 5
rational a[DEFECT_PAIRS], b[DEFECT_PAIRS], c[DEFECT_PAIRS];
void send_to(int out, int var, string name);
void outputs(int var);

int main(int argc, char *argv[]){
	int menu=3,temp=0,i=0,j=0,aux=0,sentinela=0,MAX_PAIRS=DEFECT_PAIRS;
	char filename[85], sentinel[100], tmp[10], output[30];
	string filename2, testeo;
	if (argc == 1){
		cout << "Entrada sin comandos...\n Por favor escriba como primer argumento el nombre de fichero de texto .txt de entrada y como segundo argumento el nombre del fichero de text .txt de salida. En caso de solo introducir el fichero de entrada o de no introducir ningún fichero se creará un fichero de salida \"./Outputs.Output.txt\" en el que se guardarán los datos. \n Tambíen puede utilizar el menú listado a continuación:" << endl << endl << "Un ejemplo sería:\n ./prueba entrada.txt salida.txt" << endl << endl << "Seleccione una opcion:" << endl << "1 Introducir datos manualmente" << endl << "2 Leer datos de fichero" << endl << "0. Salir y finalizar el programa" << endl;
		cin >> menu;
	}
	else if (argc == 2){
		menu = 2;
		filename2 = argv[1];
		strcpy(filename,filename2.c_str()); //strcpy para pasar un string a cadena de char
		sentinela=1;

	}
	else if (argc == 3){
		menu = 2;
		filename2 = argv[1];
		strcpy(filename,filename2.c_str());
		sentinela=2;
		filename2 = argv[2];
	}
	while(menu != 999){
		if (menu == 0)
			return 0;
		else if (menu == 1){ //opcion de introducir datos manualmente
			for (int k=0; k < MAX_PAIRS; k++){
				cout << "Introducir los datos del " << k << "par de racionales." << endl;
				cout << "Introducir datos del número A:" << endl;
				a[k].read();	
				cout << "Introducir datos del número B:" << endl;
				b[k].read(); 
			}
			menu=999;
		}
		else if (menu == 2){//opcion de lectura desde fichero
			ifstream textfile;
			if(sentinela == 0){
				cout << "Introduce el nombre completo del fichero de datos:" << endl;
				cin >> filename;
			}
			textfile.open(filename);
			if (textfile.is_open()){//Recorremos el fichero una primera vez para saber la cantidad de pares de racionales que tenemos.
				while(!textfile.eof())				{
					textfile >> sentinel[i];
					if(sentinel[i] == '/')
						aux++;
					i++;
				}
				textfile.close();
				MAX_PAIRS=aux/2;
				aux=0;
			}
			textfile.open(filename);
			if (textfile.is_open()){
				while(!textfile.eof()){
					for (int k = 0; k < MAX_PAIRS; k++){ //usamos un for por cada par de numeros
						if ((a[k].get_num() == 0) && (a[k].get_den() == 1))
						do{//introducimos los datos de A
							textfile >> sentinel[i];
							if(isdigit(sentinel[i])){
								tmp[j] = sentinel[i];
								j++;
							}
							if(sentinel[i] == '/'){
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								a[k].set_num(temp);
								i++;
								textfile >> testeo;
								strcpy(tmp,testeo.c_str());
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								a[k].set_den(temp);
								for (j=0; j<10; j++)
									tmp[j] = '\0';
								j = 0;
								aux=1;
							}
							i++;
						}while(aux!=1);
						if ((b[k].get_num() == 0) && (b[k].get_den() == 1))
						do{//introducimos los datos de B
							textfile >> sentinel[i];
							if(isdigit(sentinel[i])){
								tmp[j] = sentinel[i];
								j++;
							}
							else if(sentinel[i] == '/'){
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								b[k].set_num(temp);
								i++;
								textfile >> testeo;
								strcpy(tmp,testeo.c_str());
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								b[k].set_den(temp);
								for (j=0; j<10; j++)
									tmp[j] = '\0';
								j = 0;
								aux=0;
							}
							i++;
						}while(aux!=0);

						if ((c[k].get_num() == 0) && (c[k].get_den() == 1))
						do{//introducimos los datos de C
							textfile >> sentinel[i];
							if(isdigit(sentinel[i])){
								tmp[j] = sentinel[i];
								j++;
							}
							if(sentinel[i] == '/'){
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								c[k].set_num(temp);
								i++;
								textfile >> testeo;
								strcpy(tmp,testeo.c_str());
								temp = atoi(tmp);//atoi para pasar cadenas a entero
								c[k].set_den(temp);
								for (j=0; j<10; j++)
									tmp[j] = '\0';
								j = 0;
								aux=3;
							}
							i++;
						}while(aux!=3);
					}
					textfile >> sentinel[i];
				}
				textfile.close();
				menu=999;
			}
			else{ //En caso de que no se encuentre el archivo nos da un error y nos sale del programa
				cout << "Error 404, file not found" << endl << endl;
				return 0;
			}
		}
	}
	if (sentinela !=2){		
		cout << "Seleccione tipo de salida: \n 1 Pantalla. \n 2. Archivo de texto." << endl;
		cin >> menu;
		if (menu == 1)
			outputs(MAX_PAIRS);
		else if (menu == 2)
			send_to(sentinela,MAX_PAIRS, filename2);
	}
	else
		send_to(sentinela,MAX_PAIRS, filename2);
	return 0;

}

void outputs(int var){//Funcion de salida por pantalla
	for (int k = 0; k < var; k++){
		cout << "A: ";
		a[k].write();
		cout << "B: ";
		b[k].write();	
		cout << "A + B: " << a[k].get_num() << "/" << a[k].get_den() << " + " << b[k].get_num() << "/" << b[k].get_den() << " = ";
		a[k].add(b[k]).write();
		cout << "A - B: " << a[k].get_num() << "/" << a[k].get_den() << " - " << b[k].get_num() << "/" << b[k].get_den() << " = ";
		a[k].substract(b[k]).write();
		cout << "A * B: " << a[k].get_num() << "/" << a[k].get_den() << " * " << b[k].get_num() << "/" << b[k].get_den() << " = ";
		a[k].multiply(b[k]).write();
		cout << "A / B: " << a[k].get_num() << "/" << a[k].get_den() << " / " << b[k].get_num() << "/" << b[k].get_den() << " = ";
		a[k].divide(b[k]).write();
		//cout << "Fracciónes con el MCM: " << endl;
		//a[k].mcm(b[k]);
		//b[k].mcm(a[k]);
		//cout << "A: ";
		//a[k].write();
		//cout << "B: ";
		//b[k].write();
		cout << "Comparación: ";
		if (a[k].equal(b[k]))
			cout << "A = B" << endl;
		else if (a[k].greater(b[k]))
			cout << "A > B" << endl;
		else 
			cout << "A < B" << endl;
	}
}

void send_to(int out, int var, string name){//funcion de salida por fichero
	char output[50];
	ofstream file;
	if (out != 2)
		file.open("./Outputs/Output.txt", ios::out);
	else{
		strcpy(output,name.c_str());
		file.open(output);
	}
	if(file.fail()){
		cout << "Error al abrir el archivo" << endl;
		exit(1);
	}
	else{
		for (int k = 0; k < var-1; k++){
			file << "A" << k+1 << ": ";
			a[k].write(file);
			file << "B" << k+1 << ": ";
			b[k].write(file);
			file << "C" << k+1 << ": ";
			c[k].write(file);
			file << "A + B: " << a[k].get_num() << "/" << a[k].get_den() << " + " << b[k].get_num() << "/" << b[k].get_den() << " = ";
			a[k].add(b[k]).write(file);
			//file << "A - B: " << a[k].get_num() << "/" << a[k].get_den() << " - " << b[k].get_num() << "/" << b[k].get_den() << " = ";
			//a[k].substract(b[k]).write(file);
			file << "A * B: " << a[k].get_num() << "/" << a[k].get_den() << " * " << b[k].get_num() << "/" << b[k].get_den() << " = ";
			a[k].multiply(b[k]).write(file);
			file << "A / B: " << a[k].get_num() << "/" << a[k].get_den() << " / " << b[k].get_num() << "/" << b[k].get_den() << " = ";
			a[k].divide(b[k]).write(file);
			//file << "Fracciones con el MCM: " << endl;
			//a[k].mcm(b[k]);
			//b[k].mcm(a[k]);
			file << "A: ";
			a[k].write(file);
			file << "B: ";
			b[k].write(file);
			file << "Comparacion: ";
			if (a[k].equal(b[k]))
				file << "A = B" << endl;
			else if (a[k].greater(b[k]))
				file << "A > B" << endl;
			else 
				file << "A < B" << endl;
			file << endl << endl;
			
		}
		file << endl << endl << endl;
		for (int h = 0; h<var-1; h++){
				if ((a[h].value() + a[h+1].value()) == a[h+2].value()){
					file << "A" << h+1 << " + A" << h+2 << " = A" << h+3 << "  " << a[h].get_num() << "/" << a[h].get_den() << " + " << a[h+1].get_num() << "/" << a[h+1].get_den() << " = " << a[h+2].get_num() << "/" << a[h+2].get_den() << endl;
				}
			}
	file.close();
	}
}
