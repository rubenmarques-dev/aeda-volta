/*
 * menu.h
 *
 *  Created on: 07/11/2014
 *      Author: ei10117
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale>
#include <algorithm>
#include "Volta.h"
#include "saves.h"

using namespace std;

class Menu{
private:

public:
	class OpcaoIncorrecta{};

	void menuInicial(Volta v1);

	void gestaoEquipas(Volta v1);
	void gestaoEquipa(Volta v1);
	void adicionaEquipa(Volta v1);
	void modificaEquipa(Volta v1);
	void removeEquipa(Volta v1);
	void listarEquipas(Volta v1);

	void gestaoCiclistas(Volta v1);
	void adicionaCiclista(Volta v1, int idEquipa);
	void modificaCiclista(Volta v1, int idEquipa);
	void removeCiclista(Volta v1, int idEquipa);
	void listarCiclistas(Volta v1, int idEquipa);

	void gestaoStaff(Volta v1);
	void gestaoTreinadores(Volta v1, int idEquipa);
	void adicionaTreinador(Volta v1, int idEquipa);
	void removeTreinador(Volta v1, int idEquipa);
	void listarTreinadores(Volta v1, int idEquipa);

	void gestaoMassagistas(Volta v1, int idEquipa);
	void adicionaMassagista(Volta v1, int idEquipa);
	void removeMassagista(Volta v1, int idEquipa);
	void listarMassagistas(Volta v1, int idEquipa);

	void gestaoMecanicos(Volta v1, int idEquipa);
	void adicionaMecanico(Volta v1, int idEquipa);
	void removeMecanico(Volta v1, int idEquipa);
	void listarMecanicos(Volta v1, int idEquipa);

	void gestaoEtapas(Volta v1);
	void criarEtapa(Volta v1);
	void listarEtapas(Volta v1);


	/*void printMenuCiclistas();


	void printMenuMembros();
	void printOpcoesMembros();
	void printMenuGestaoEquipa();


	void modificaEtapa();
	void removeEtapa();
	void gestaoTempos();*/

};



#endif /* MENU_H_ */
