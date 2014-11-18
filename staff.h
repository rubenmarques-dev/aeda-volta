/*
 * staff.h
 *
 *  Created on: 08/11/2014
 *      Author: Carlos Lucas
 */

#ifndef STAFF_H_
#define STAFF_H_

#include "membro.h"

//**********************************************************//
//						TREINADOR							//
//**********************************************************//

class Treinador:public Membro{

public:
	Treinador(string nome,string nacionalidade,char sexo,int idade);
	string info();
	string getTipo();
};

//**********************************************************//
//						MECANICO							//
//**********************************************************//

class Mecanico:public Membro{

public:
	Mecanico(string nome,string nacionalidade,char sexo,int idade);
	string info();
	string getTipo();
};

//**********************************************************//
//						MASSAGISTA							//
//**********************************************************//

class Massagista:public Membro{

public:
	Massagista(string nome,string nacionalidade,char sexo,int idade);
	string info();
	string getTipo();
};

#endif /* STAFF_H_ */
