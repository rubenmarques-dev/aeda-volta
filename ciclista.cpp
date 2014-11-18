/*
 * ciclista.cpp
 *
 *  Created on: 03/11/2014
 *      Author: ei10117
 */

#include "ciclista.h"

////////ID CLASS CICLISTA ////////////

int Ciclista::idUltimoCiclista { 0 };

Ciclista::Ciclista(string nome,string nacionalidade,char sexo,int idade):Membro(nome,nacionalidade,sexo,idade){
	id=++idUltimoCiclista;
	desistiu=false;
	Tempo tempoMontanha();
	Tempo tempoContraRelogio();
}

Ciclista::Ciclista(){

}


vector<TempoRef> Ciclista::getTemposCopy() const{
	return tempos;
}

vector<TempoRef> & Ciclista::getTempos(){
	return tempos;
}

void Ciclista::Ciclista::addTempo(){
	tempos.push_back(TempoRef(new TempoTemporario {0, 0, 0}));
}

void Ciclista::setTempo (TempoRef tempo1,int idEtapa){
	tempos[idEtapa-1]=tempo1;
}


Tempo Ciclista::getTempoTotal(){
	Tempo tempoTotal(0,0,0);
	vector<TempoRef>::iterator it;
	for(it=tempos.begin();it!=tempos.end();it++){

		tempoTotal=tempoTotal+*(*it).get();
	}
	return tempoTotal;
}


Tempo & Ciclista::getTempoEtapa(int idEtapa){

	return *tempos[idEtapa-1];

}


bool Ciclista::getDesistiu(){
	return desistiu;

}
void Ciclista::setDesistiu(bool desistiu){
	this->desistiu=desistiu;

}

Tempo Ciclista::getTempoMontanha(){
	Tempo tempoMontanha(0,0,0);
	Tempo auxiliar(0,0,0);
	vector<TempoRef>::iterator it;
	for( it=tempos.begin();it!=tempos.end();it++){
		auxiliar=(*it).get()->getTempoMontanha();
		tempoMontanha=tempoMontanha+auxiliar;
	}
	return tempoMontanha;
}


Tempo Ciclista::getTempoContraRelogio(){
	Tempo tempoContraRelogio(0,0,0);
	vector<TempoRef>::iterator it;
	for(it=tempos.begin();it!=tempos.end();it++){
		tempoContraRelogio=tempoContraRelogio+*(*it).get();
	}
	return tempoContraRelogio;
}


 int Ciclista::getUltimoCiclista(){
	 return idUltimoCiclista;
 }


 int Ciclista::getId(){
	 return id;
 }

 string Ciclista::info(){
 	return Membro::info();
 }

 string Ciclista::getTipo(){
	 return "ciclista";
 }



 void Ciclista::removeTempoEtapa(int idEtapa){
	 vector<TempoRef>::iterator it;

	 for(int i=0;i<idEtapa-1;i++){
	it++;
	 }
	tempos.erase(it);
 }

//////////FIM CLASS CICLISTA/////////////


