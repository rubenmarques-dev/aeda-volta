/*
 * tempo.cpp
 *
 *  Created on: 03/11/2014
 *      Author: ei10117
 */
#include "tempo.h"

Tempo::Tempo(int hora,int minuto,int segundo){
	this->hora=hora;
	this->minuto=minuto;
	this->segundo=segundo;
}
Tempo::Tempo(){
	hora=0;
	minuto=0;
	segundo=0;


}
int Tempo::getHora(){
	return hora;
}
void Tempo::setHora(int hora){
	this->hora=hora;
}
int Tempo::getMinuto(){
	return minuto;
}
void Tempo::setMinuto(int minuto){
	this->minuto=minuto;
}
int Tempo::getSegundo(){
	return segundo;
}
void Tempo::setSegundo(int segundo){
	this->segundo=segundo;
}

Tempo  Tempo::operator+(Tempo  tempo1){

	segundo+=tempo1.getSegundo();
	if(segundo>=60){
		segundo-=60;
		minuto++;
		}
	minuto+=getMinuto();
	if(minuto>=60)
	{
		minuto-=60;
		hora++;
	}

	hora+=tempo1.getHora();
	Tempo t1(hora,minuto,segundo);
	return t1;
}




bool Tempo::operator<(Tempo  tempo1){
	if(hora>tempo1.getHora())
		return false;
	if(hora<tempo1.getHora())
		return true;
	if(minuto>tempo1.getMinuto())
		return false;
	if(minuto<tempo1.getMinuto())
		return true;
	if(segundo>tempo1.getSegundo())
		return false;
	else
		return true;
}

Tempo  Tempo::operator/(int num){
	hora=hora/num;
	minuto=minuto/num;
	segundo=segundo/num;
	Tempo t1(hora,minuto,segundo);
	return t1;
}


string Tempo::tempo(){
	stringstream ss;
	if(hora < 10)
		ss <<"0"<<  hora << ":";
	else
		ss << hora << ":";
	if(minuto < 10)
		ss << "0" << minuto << ":";
	else
		ss<< minuto << ":";
	if(segundo < 10)
		ss << "0" << segundo;
	else
		ss << segundo;
	return ss.str();

}




