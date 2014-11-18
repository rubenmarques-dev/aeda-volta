/*
 * membro.h
 *
 *  Created on: 13/10/2014
 *      Author: ei10117
 */

#ifndef MEMBRO_H_
#define MEMBRO_H_

#include <vector>
#include <string>
#include <sstream>


using namespace std;



class Membro{
protected:
	string nome;
	string nacionalidade;
	char sexo;
	int idade;

public:
	Membro(string nome,string nacionalidade,char sexo,int idade);
	string getNome();
	string getNacionalidade();
	char getSexo();
	int getIdade();
	void setNome(string nome);
	void setNaciondalidade(string nacionalidade);
	void setIdade(int idade);
	void setSexo(char sexo);




	virtual string info()=0;
	virtual string getTipo()=0;




};







#endif /* MEMBRO_H_ */
