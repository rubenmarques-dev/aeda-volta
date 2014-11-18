/*
 * tempoContraRelogio.h
 *
 *  Created on: 08/11/2014
 *      Author: Ruben
 */

#ifndef SRC_TEMPOCONTRARELOGIO_H_
#define SRC_TEMPOCONTRARELOGIO_H_

#include "tempo.h"

class TempoContraRelogio:public Tempo{

public:
	TempoContraRelogio(int hora,int minuto,int segundo);
	string getTipo(){return "contraRelogio";}
	Tempo getTempoMontanha() {Tempo t1(0,0,0); return t1;}
	Tempo getTempoContraRelogio() {Tempo t1(hora,minuto,segundo); return t1;}
};



#endif /* SRC_TEMPOCONTRARELOGIO_H_ */
