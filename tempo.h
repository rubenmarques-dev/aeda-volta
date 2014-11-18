/*
 * tempo.h
 *
 *  Created on: 03/11/2014
 *      Author: ei10117
 */

#ifndef TEMPO_H_
#define TEMPO_H_

#include <iostream>
#include <sstream>
#include <memory>


using namespace std;

class Tempo{
protected:
	int hora;
	int minuto;
	int segundo;
public:
	Tempo(int hora,int minuto,int segundo);
	Tempo();
	int getHora();
	void setHora(int hora);
	int getMinuto();
	void setMinuto(int minuto);
	int getSegundo();
	void setSegundo(int segundo);
	string tempo();
	Tempo  operator+(Tempo  tempo1);
	bool operator<(Tempo  tempo1);
	Tempo  operator/(int num);
	virtual string getTipo(){return "base";}
	virtual Tempo getTempoMontanha() { Tempo t1(0,0,0); return t1;}
	virtual Tempo getTempoContraRelogio() {Tempo t1(0,0,0); return t1;}

};

typedef shared_ptr<Tempo> TempoRef;




#endif /* TEMPO_H_ */
