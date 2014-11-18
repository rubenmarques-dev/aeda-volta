/*
 * etapa.cpp
 *
 *  Created on: 30/10/2014
 *      Author: ei10117
 */
#include "etapa.h"




//////////////// INICIO CLASS  ETAPA ////////////////////

int Etapa::ultimoIdEtapa { 0 };

Etapa::Etapa(string nome,string local,Data data, int distancia){
	this->nome=nome;
	this->local=local;
	this->data=data;
	this->distancia=distancia;
	idEtapa = ++ultimoIdEtapa;
	//finalizada=false;

}

/*Etapa::~Etapa(){
	delete this;
}*/

string Etapa::getNome() const{
	return nome;
}
string Etapa::getLocal() const{
	return local;
}
Data Etapa::getData() const{
	return data;
}
int Etapa::getDistancia() const{
	return distancia;
}

int Etapa::getIdEtapa() const{
	return idEtapa;
}

void Etapa::setNome(string nome) {
	this->nome = nome;
}

void Etapa::setLocal(string local) {
	this->local = local;
}

void Etapa::setData(Data data) {
	this->data = data;
}

void Etapa::setDistancia(int distancia) {
	this->distancia = distancia;
}

void Etapa::setIdEtapa(int idEtapa){
	this->idEtapa = idEtapa;
}

vector<int> Etapa::getDesistencias() {
	return desistencias;
}

bool Etapa::addDesistencia(int idCiclista){
	for (unsigned int i = 0;i<desistencias.size();i++){
		if (desistencias[i] == idCiclista)
			return false;
	}
	desistencias.push_back(idCiclista);
	return true;
}


///////////////// FIM CLASS ETAPA /////////////////////////////////


////////////////INICIO CLASS ETAPA NORMAL ////////////////////////

Normal::Normal(string nome,string local,Data data, int distancia):Etapa(nome,local,data,distancia){
}

string Normal::getTipo() {
	return "Normal";
}
///////////////FIM CLASS ETAPA NORMAL /////////////////////////

////////////////INICIO CLASS ETAPA MONTANHA ////////////////////////

Montanha::Montanha(string nome,string local,Data data, int distancia,int distanciaMontanha):Etapa(nome,local,data,distancia){
	this->distanciaMontanha=distanciaMontanha;
}

int Montanha::getKMInicio() {
	return montanhaKmInicio;
}

int Montanha::getKMFim() {
	return montanhaKmFim;
}

int Montanha::getDistanciaMontanha() {
	return distanciaMontanha;
}

string Montanha::getTipo() {
	return "montanha";
}

///////////////FIM CLASS ETAPA MONTANHA /////////////////////////

//////////////INICIO CLASS CONTRA RELOGIO ///////////////////////

ContraRelogio::ContraRelogio(string nome, string local, Data data,int distancia) :
				Etapa(nome, local, data, distancia) {
}

string ContraRelogio::getTipo() {
	return "Contra Relógio";
}

/////////////FIM CLASS CONTRA RELOGIO //////////////////////
