
#include "ciclista.h"
#include "staff.h"
#include "equipa.h"
#include "etapa.h"
#include "data.h"
#include "volta.h"
#include "tempoProva.h"
#include "tempo.h"
#include "membro.h"
#include "menu.h"
#include "saves.h"

using namespace std;

int main(){
	/*
	cout << endl << "\t###################################" << endl
			<< "\t##                               ##" << endl
			<< "\t##       VOLTA A PORTUGAL        ##" << endl
			<< "\t##                               ##" << endl
			<< "\t###################################" << endl;
	Volta v1;
	Patrocinador p1("BES");
	Equipa e1("Porto","Portugal",p1);
	Equipa e2("Moviflor","Brasil",p1);
	v1.addEquipa(e1);
	v1.addEquipa(e2);
    Menu menus;
    menus.menuInicial(v1);
    return 0;

    */

	Patrocinador p1("Revigres");
	vector<Equipa> equipas;
	Equipa equipa("Porto","fcp",p1);
	Ciclista c1("joao","Tuga",'m',23);
	Ciclista c2("Ruben","Portugues",'m',28);
	TempoRef t1(new TempoNormal(2,20,30));
	TempoRef t2(new TempoContraRelogio(1,25,34));
	Tempo t3(2,30,10);
	TempoRef t4(new TempoMontanha(2,30,30,t3));
	c1.addTempo();
	c1.setTempo(t1,1);
	c2.addTempo();
	c2.setTempo(t2,1);
	c2.addTempo();
	c2.setTempo(t4,2);
	equipa.addCiclista(c1);
	equipa.addCiclista(c2);
	equipas.push_back(equipa);
	saveEquipas(equipas);


	return 0;

}



