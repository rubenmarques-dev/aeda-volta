/*
 * TempoTemporario.h
 *
 *  Created on: 14/11/2014
 *      Author: ei10117
 */

#ifndef TEMPOTEMPORARIO_H_
#define TEMPOTEMPORARIO_H_
#include "tempo.h"

class TempoTemporario:public Tempo{

public:
	TempoTemporario(int hora,int minuto,int segundo);
	string getTipo(){return "Temporario";}
	Tempo getTempoMontanha() {Tempo t1(0,0,0); return t1;}
	Tempo getTempoContraRelogio() {Tempo t1(0,0,0); return t1;}
};



#endif /* TEMPOTEMPORARIO_H_ */
