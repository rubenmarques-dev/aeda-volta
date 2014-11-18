/*
 * tempoProva.h
 *
 *  Created on: 04/11/2014
 *      Author: ei10117
 */

#ifndef TEMPOPROVA_H_
#define TEMPOPROVA_H_

#include "tempo.h"


class TempoProva:public Tempo{
	int posicao;
	int idEtapa;
public:
	TempoProva(int hora,int minuto,int segundo,int posicao,int idEtapa);
	int getPosicao();
	int getIdEtapa();


};




#endif /* TEMPOPROVA_H_ */
