/*
 * etapa.h
 *
 *  Created on: 13/10/2014
 *      Author: ei10117
 */

#ifndef ETAPA_H_
#define ETAPA_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "membro.h"
#include "tempo.h"
#include "equipa.h"
#include "data.h"

using namespace std;

class Classificacao{
	int idCiclista;
	Tempo tempo;
public:
};

class Etapa{
	string nome;
	string local;
	Data data;
	int distancia;
	int idEtapa;
	static int ultimoIdEtapa;
	vector<int> desistencias;
public:
	Etapa(string nome,string local,Data data, int distancia);
	string getNome() const;
	string getLocal() const;
	Data getData() const;
	int getDistancia() const;
	int getIdEtapa() const;
	void setNome(string nome);
	void setLocal(string local);
	void setData(Data data);
	void setDistancia(int distancia);
	void setIdEtapa(int idEtapa);
	vector<int> getDesistencias();
	//void alteraEtapa();
	virtual string getTipo()=0;
	bool addDesistencia(int idCiclista);
	virtual int getDistanciaMontanha()=0;
};

class Normal:public Etapa{
public:
	Normal(string nome,string local,Data data, int distancia);
	string getTipo();
	int getDistanciaMontanha(){}
};


//uma prova gen�rica de ciclismo, em pelot�o, onde � poss�vel que exista uma sec�ao montanhosa

class Montanha:public Etapa{
	int distanciaMontanha;
public:
	Montanha(string nome,string local,Data data, int distancia,int distanciaMontanha);
	int getKMInicio();
	int getKMFim();
	int getDistanciaMontanha();
	string getTipo();
	//vector<Classificacao> getTemposMontanha();



};

//uma prova mais curta, aonde os concorrentes fazem as provas sozinhos,partindo 1 de cada vez com 2 ou 3 minutos de diferen�a

class ContraRelogio:public Etapa{
public:
	ContraRelogio(string nome,string local,Data data, int distancia);
	string getTipo();
	int getDistanciaMontanha(){}
};

#endif /* ETAPA_H_ */
