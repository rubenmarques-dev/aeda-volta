
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
}



