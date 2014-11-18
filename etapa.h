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
};

class Normal:public Etapa{
public:
	Normal(string nome,string local,Data data, int distancia);
	string getTipo();
};


//uma prova genérica de ciclismo, em pelotão, onde é possível que exista uma secçao montanhosa

class Montanha:public Etapa{
	int montanhaKmInicio;  //km aonde a montanha começa na prova
	int montanhaKmFim;		//km aonde a montanha acaba na prova
	//vector<Classificacao> temposMontanha;
public:
	Montanha(string nome,string local,Data data, int distancia,int montanhaKmInicio,int montanhaKmFim);
	int getKMInicio();
	int getKMFim();
	int getDistanciaMontanha();
	string getTipo();
	//vector<Classificacao> getTemposMontanha();


};

//uma prova mais curta, aonde os concorrentes fazem as provas sozinhos,partindo 1 de cada vez com 2 ou 3 minutos de diferença

class ContraRelogio:public Etapa{
public:
	ContraRelogio(string nome,string local,Data data, int distancia);
	string getTipo();
};

#endif /* ETAPA_H_ */
