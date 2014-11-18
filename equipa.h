/*
 * equipa.h
 *
 *  Created on: 03/11/2014
 *      Author: ei10117
 */

#ifndef EQUIPA_H_
#define EQUIPA_H_
#include "ciclista.h"
#include "sstream"
#include "tempoProva.h"

using namespace std;

class Patrocinador{
	string nome;
public:
	Patrocinador(string nome);
	Patrocinador(){}
	string getNome() const;
};

class Equipa{

private:
	string designacao;
	string pais;
	Patrocinador patrocinador;
	int id;
	static int ultimaEquipa;
	vector<Membro *> membros;
	vector<Ciclista > ciclistas;
public:
	Equipa(string designacao, string pais, Patrocinador patrocinador);
	Equipa();
	string getDesignacao() const;
	string getPais() const;
	int getIdEquipa() const;
	Patrocinador getPatrocinador() const;
	vector<Membro *> & getMembros();
	vector<Membro *> getMembrosCopy();
	vector<Ciclista> & getCiclistas();
	vector<Ciclista>  getCiclistasCopy();
	void setIdEquipa(int idEquipa);
	void setPatrocinador(Patrocinador patrocinador);
	void setDesignacao(string designacao);
	void setPais(string pais);
	bool addCiclista(Ciclista ciclista1);
	bool removeCiclista(int idCiclista);
	bool addMembro(Membro *membro1);
	bool removeMembro(string nome);
	string listaMassagistas();
	void listaConquistasCiclistas();
	void addTempoProvaToCiclista(TempoProva tempoProva1);
	void ciclistaDesistiu(int idCiclista);
	Tempo tempoMedioDaEquipa();
	Ciclista melhorClassificado();
	vector<Ciclista> ciclistasDesistentes();
	void showCiclistas();
};




#endif /* EQUIPA_H_ */
