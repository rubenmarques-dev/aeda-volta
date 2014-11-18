/*
 * staff.cpp
 *
 *  Created on: 08/11/2014
 *      Author: Carlos Lucas
 */


#include "staff.h"

//**********************************************************//
//						TREINADOR							//
//**********************************************************//

Treinador::Treinador(string nome,string nacionalidade,char sexo,int idade):Membro(nome,nacionalidade,sexo,idade){

}

string Treinador::info(){
	return Membro::info();

}

string Treinador::getTipo(){
	return "treinador";
}

//**********************************************************//
//						MECANICO							//
//**********************************************************//

Mecanico::Mecanico(string nome,string nacionalidade,char sexo,int idade):Membro(nome,nacionalidade,sexo,idade){

}

string Mecanico::info(){
	Membro::info();
}

string Mecanico::getTipo(){
	return "mecanico";
}

//**********************************************************//
//						MASSAGISTA							//
//**********************************************************//

Massagista::Massagista(string nome,string nacionalidade,char sexo,int idade):Membro(nome,nacionalidade,sexo,idade){

}

string Massagista::info(){
	return Membro::info();
}

string Massagista::getTipo(){
	return "massagista";
}

