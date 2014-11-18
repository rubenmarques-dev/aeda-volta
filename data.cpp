/*
 * data.cpp
 *
 *  Created on: 06/11/2014
 *      Author: ei11140
 */

#include "data.h"
#include <iostream>

Data::Data(int ano, int mes, int dia){
	this->ano = ano;
	this->mes = mes;
	this->dia = dia;
}

int Data::getAno() const{
	return ano;
}

int Data::getMes() const{
	return mes;
}

int Data::getDia() const{
	return dia;
}

void Data::setAno(int ano) {
	this->ano = ano;
}

void Data::setMes(int mes) {
	this->mes = mes;
}

void Data::setDia(int dia) {
	this->dia = dia;
}

bool Data::operator<(const Data & data1){
	if (ano > data1.getAno())
		return false;
	if (ano < data1.getAno())
		return true;
	if (mes > data1.getMes())
		return false;
	if (mes < data1.getMes())
		return true;
	if (dia > data1.getDia())
		return false;
	else
		return true;
}

bool Data::operator==(const Data & data1){
	if (ano == data1.getAno()){
		if (mes == data1.getMes()){
			if (dia == data1.getDia())
				return true;
		}
	}
	return false;
}

void Data::showData(){
	cout << ano << "/" << mes << "/" << dia;
}

string Data::info(){
	stringstream ss;
	ss << ano << "/" << mes << "/" << dia;
	return ss.str();

}

///////////////// FIM CLASS DATA /////////////////////////

