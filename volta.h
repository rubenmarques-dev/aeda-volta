/*
 * volta.h
 *
 *  Created on: 06/11/2014
 *      Author: ei11140
 */

#ifndef VOLTA_H_
#define VOLTA_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "membro.h"
#include "tempo.h"
#include "equipa.h"
#include "data.h"
#include "etapa.h"
#include "staff.h"

class Volta{
	vector<Etapa*> etapas;
	vector<Equipa> equipas;
	//listas
public:
	Volta(){}
	bool addEtapa(Etapa *e1);
	bool removeEtapa(int idEtapa);
	vector<Etapa*> getEtapas();
	void showEtapas(); ///////TEMPORARIO/////////
	bool showEtapa(int idEtapa);
	bool addEquipa(Equipa e1);
	bool removeEquipa(int idEquipa);
	vector<Equipa> & getEquipas();
	vector<Equipa> getEquipas() const;
	bool showEquipa(int idEquipa);
	void addTempoToEtapa(int EtapaId,int idCiclista);
};



#endif /* VOLTA_H_ */
