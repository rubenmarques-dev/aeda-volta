/*
 * ciclista.cpp
 *
 *  Created on: 30/10/2014
 *      Author: ei10117
 */
#include "membro.h"





///// INICIO CLASS MEMBRO //////////
Membro::Membro(string nome,string nacionalidade,char sexo,int idade){
	this->nome=nome;
	this->nacionalidade=nacionalidade;
	this->sexo=sexo;
	this->idade=idade;
}

Membro::Membro(){

}

string Membro::getNome(){
	return nome;
}
string Membro::getNacionalidade(){
	return nacionalidade;
}
char Membro::getSexo(){
	return sexo;
}
int Membro::getIdade(){
	return idade;
}

string Membro::info(){
		stringstream ss;
		ss << nome << "/" << nacionalidade << "/"<<sexo<< "/"<< idade;
		return ss.str();
}


void Membro::setNome(string nome){
	this->nome=nome;
}
void Membro::setNaciondalidade(string nacionalidade){
	this->nacionalidade=nacionalidade;
}
void Membro::setIdade(int idade){
	this->idade=idade;
}
void Membro::setSexo(char sexo){
	this->sexo=sexo;
}




/////////FIM CLASS MEMBRO ////////////





