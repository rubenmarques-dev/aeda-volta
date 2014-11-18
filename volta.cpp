/*
 * volta.cpp
 *
 *  Created on: 06/11/2014
 *      Author: ei11140
 */

#include "volta.h"

using namespace std;

vector<Etapa*> Volta::getEtapas() {
	return etapas;
}

bool Volta::addEtapa(Etapa *e1) {
	/*int ano,mes,dia;
	cout << "Introduza a data da nova etapa.\n" << "Ano?\n ";
	cin >> ano;
	cout << "Mes? \n";
	cin >> mes;
	cout << "Dia? \n";
	cin >> dia;
	Data d1(ano,mes,dia);
	for (unsigned int i=0;i<etapas.size();i++){
		if (etapas[i]->getData() == d1){
			cout << "A data escolhida já existe.\n";
			return false;
		}
	}
	string nome, local;
	int distancia;
	cout << "Nome da etapa?\n";
	cin >> nome;
	cout << "Local da etapa?\n";
	cin >> local;
	cout << "Distância da etapa?\n";
	cin >> distancia;
	Etapa *e1 = new Etapa(nome,local,d1,distancia);*/
	etapas.push_back(e1);
	return true;
}

void Volta::showEtapas(){
	for (unsigned int i=0;i<etapas.size();i++){
		cout << "Etapa " << etapas[i]->getIdEtapa() << ":\n\n";
		cout << "Nome: " << etapas[i]->getNome() << "\n";
		cout << "Local: " << etapas[i]->getLocal() << "\n";
		cout << "Data: " << etapas[i]->getData().getAno() << "/" << etapas[i]->getData().getMes() << "/" << etapas[i]->getData().getDia() << endl;
		cout << "Distancia: " << etapas[i]->getDistancia() << endl << endl;
	}
}

bool Volta::showEtapa(int idEtapa){
	for (unsigned int i=0;i<etapas.size();i++){
		if (etapas[i]->getIdEtapa() == idEtapa){
			cout << "Etapa " << etapas[i]->getIdEtapa() << ":\n";
			cout << "Nome: " << etapas[i]->getNome() << "\n";
			cout << "Local: " << etapas[i]->getLocal() << "\n";
			cout << "Data: " << etapas[i]->getData().getAno() << "/" << etapas[i]->getData().getMes() << "/" << etapas[i]->getData().getDia() << endl;
			cout << "Distancia: " << etapas[i]->getDistancia() << "\n\n";
			return true;
		}
	}
	return false;
}

bool Volta::removeEtapa(int idEtapa){
	for (unsigned int i = 0;i < etapas.size();i++){
		if (etapas[i]->getIdEtapa() == idEtapa){
			etapas.erase(etapas.begin() + i);
			//removeTemposCiclistas(idEtapa);
			for (unsigned int k=i;k<etapas.size();k++){
				etapas[k]->setIdEtapa(etapas[k]->getIdEtapa()-1);
			}
			return true;
		}
	}
	return false;
}

vector<Equipa>& Volta::getEquipas() {
	return equipas;
}

bool Volta::addEquipa(Equipa e1){
	for (unsigned int i=0;i<equipas.size();i++){
		if (equipas[i].getDesignacao() == e1.getDesignacao())
			return false;
	}
	equipas.push_back(e1);
	return true;
}

bool Volta::removeEquipa(int idEquipa){
	for (unsigned int i=0;i<equipas.size();i++){
		if (equipas[i].getIdEquipa() == idEquipa){
			equipas.erase(equipas.begin() + i);
			//removeCiclistas(idEquipa);
			for (unsigned int k=i;k<equipas.size();k++){
				equipas[k].setIdEquipa(equipas[k].getIdEquipa()-1);
			}
			return true;
		}

	}
	return false;
}

bool Volta::showEquipa(int idEquipa){
	for (unsigned int i=0;i<equipas.size();i++){
		if (equipas[i].getIdEquipa() == idEquipa){
			cout << "Equipa " << equipas[i].getIdEquipa() << ":\n";
			cout << "Nome: " << equipas[i].getDesignacao() << "\n";
			cout << "Pais: " << equipas[i].getPais() << "\n";
			cout << "Staff: " << equipas[i].getMembros().size() << " pessoas.\n";
			cout << "Atletas: " << equipas[i].getCiclistas().size() << " ciclistas.\n\n";
			return true;
		}
	}
	return false;
}

/////////////FIM CLASS VOLTA //////////////////////



