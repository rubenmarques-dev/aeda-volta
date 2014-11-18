/*
 * ciclista.h
 *
 *  Created on: 03/11/2014
 *      Author: ei10117
 */

#ifndef CICLISTA_H_
#define CICLISTA_H_

#include "membro.h"
#include "tempo.h"
#include "tempoMontanha.h"
#include "tempoContraRelogio.h"
#include "tempoTemporario.h"
#include "string"
#include "tempoNormal.h"


class Ciclista:public Membro{

private:
	int id;
	static int idUltimoCiclista;
	bool desistiu;
	vector<TempoRef> tempos;

public:
	Ciclista(string nome,string nacionalidade,char sexo,int idade);
	string info();
	static int getUltimoCiclista();
	vector<TempoRef> getTemposCopy() const;
	vector<TempoRef> & getTempos();
	void addTempo();
	void setTempo(TempoRef tempo1,int idEtapa);
	Tempo getTempoTotal();
	Tempo & getTempoEtapa(int idEtapa);
	bool getDesistiu();
	void setDesistiu(bool desistiu);
	Tempo getTempoMontanha();
	Tempo getTempoContraRelogio();
	int getId();
	void setID(int ciclistaId){id=ciclistaId;}
	string getTipo();
	void removeTempoEtapa(int idEtapa);



};

#endif /* CICLISTA_H_ */
