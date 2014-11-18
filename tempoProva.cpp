/*
 * tempoProva.cpp
 *
 *  Created on: 04/11/2014
 *      Author: ei10117
 */
#include "tempoProva.h"

/////////////////////Class TempoProva /////////////////////

TempoProva::TempoProva(int hora,int minuto,int segundo,int posicao,int idEtapa):Tempo(hora,minuto,segundo){
this->posicao=posicao;
this->idEtapa=idEtapa;
}

int TempoProva::getPosicao(){
	return posicao;
}
int TempoProva::getIdEtapa(){
	return idEtapa;
}





