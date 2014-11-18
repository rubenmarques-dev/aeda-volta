/*
 * tempoMontanha.h
 *
 *  Created on: 08/11/2014
 *      Author: Ruben
 */

#ifndef TEMPOMONTANHA_H_
#define TEMPOMONTANHA_H_

#include "tempo.h"

class TempoMontanha:public Tempo{
	Tempo tempoMontanha;


public:
	TempoMontanha(int hora,int minuto,int segundo,Tempo tempoMontanha);
	Tempo getTempoMontanha(){return tempoMontanha;}
	Tempo getTempoContraRelogio() {Tempo t1(0,0,0); return t1;}
	string getTipo(){return "montanha";}



};


#endif /* TEMPOMONTANHA_H_ */
