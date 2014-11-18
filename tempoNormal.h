/*
 * tempoNormal.h
 *
 *  Created on: 08/11/2014
 *      Author: Ruben
 */

#ifndef SRC_TEMPONORMAL_H_
#define SRC_TEMPONORMAL_H_

#include "tempo.h"

class TempoNormal:public Tempo{

public:
	TempoNormal(int hora,int minuto,int segundo);
	string getTipo(){return "normal";}
	Tempo getTempoMontanha() {Tempo t1(0,0,0); return t1;}
	Tempo getTempoContraRelogio() {Tempo t1(0,0,0); return t1;}

};




#endif /* SRC_TEMPONORMAL_H_ */
