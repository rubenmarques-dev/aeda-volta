#include "menu.h"



string str_to_upper(string str){
	char ch;
	for(unsigned int i=0;i<str.size();i++){
		ch=str[i];
		str[i]=toupper(ch);
	}
	return str;
}

void Menu::menuInicial(Volta v1){
		string opt;

		cout << "\t0 - Sair" << endl
				<< "\t1 - Gestao de equipas"<< endl
				<< "\t2 - Gestao de etapas" << endl
				<< "\t3 - Gestao de tempos" << endl;
		cout << "\tOpção: ";
		cin >> opt;
		char ch;
		try {
			for (unsigned int i = 0; i < opt.size(); i++) {
				ch=opt[i];
				if (!isdigit(ch)) {
					throw OpcaoIncorrecta();
					//opti = 0;
				}
			}
		} catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
			menuInicial(v1);
		}
		int opti;
		opti = atoi(opt.c_str());
		switch (opti) {
		case 0:
			cout << "\nObrigado por utilizar o programa!";
			saveEquipas(v1.getEquipas());
			exit(0);
			break;
		case 1:
			gestaoEquipas(v1);
			break;
		case 2:
			gestaoEtapas(v1);
			break;
		case 3:
			//gestaoTempos();
			break;
		default:
			try {
				throw OpcaoIncorrecta();
			}
			catch (OpcaoIncorrecta) {
				cout << endl << "\tOpcao que seleccionou nao esta correcta!"
						<< endl << endl;
				menuInicial(v1);
			}
		}
}


void Menu::gestaoEquipas(Volta v1){
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE EQUIPAS    	 ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
		cout << "\t0 - Voltar atras" << endl
				<< "\t1 - Gestão de equipa"<< endl
				<< "\t2 - Gestao de ciclistas" << endl
				<< "\t3 - Gestão de staff" << endl;
		string opt;
		cout << "\tOpção: ";
		cin >> opt;
		char ch;
		try {
			for (unsigned int i = 0; i < opt.size(); i++) {
				ch=opt[i];
				if (!isdigit(ch)) {
					throw OpcaoIncorrecta();
					//opti = 0;
				}
			}
		} catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
			gestaoEquipas(v1);
		}
		int opti;
		opti = atoi(opt.c_str());
		switch (opti) {
		case 0:
			menuInicial(v1);
			break;
		case 1:
			gestaoEquipa(v1);
			break;
		case 2:
			gestaoCiclistas(v1);
			break;
		case 3:
			gestaoStaff(v1);
			break;
		default:
			try {
				throw OpcaoIncorrecta();
			}
			catch (OpcaoIncorrecta) {
				cout << endl << "\tOpcao que seleccionou nao esta correcta!"
						<< endl << endl;
				gestaoEquipas(v1);
			}
		}
}

void Menu::gestaoEquipa(Volta v1){
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE EQUIPA	 ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
	cout << "\t0 - Voltar atras" << endl
			<< "\t1 - Adicionar Equipa"<< endl
			<< "\t2 - Modificar Equipa" << endl
			<< "\t3 - Remover Equipa" << endl
			<< "\t4 - Listar equipas" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	char ch;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			ch=opt[i];
			if (!isdigit(ch)
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoEquipa(v1);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoEquipas(v1);
		break;
	case 1:
		adicionaEquipa(v1);
		break;
	case 2:
		modificaEquipa(v1);
		break;
	case 3:
		removeEquipa(v1);
		break;
	case 4:
		listarEquipas(v1);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoEquipa(v1);
		}
	}
}

void Menu::adicionaEquipa(Volta v1){
	string designacao, pais, patrocinador;
	Equipa equipa;
	vector<Equipa> equipas=v1.getEquipas();
	cout << "\tInsira os dados da nova equipa.\nDesignacao: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,designacao);
	cout << "\nPais: ";
	getline(cin,pais);
	cout << "\nPatrocinador: ";
	getline(cin,patrocinador);
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getDesignacao() == designacao){
			cout << "\n\tJa existe uma equipa com esta designacao!\n\n";
			gestaoEquipa(v1);
		}
	}
	Patrocinador p1(patrocinador);
	Equipa e1(designacao, pais, p1);
	v1.addEquipa(e1);
	cout << "\n\tEquipa adicionada com exito!\n\n";
	gestaoEquipa(v1);
}

void Menu::modificaEquipa(Volta v1){
	string id;
	cout << "\tInsira o numero da equipa que pretende alterar informacao.\nID: ";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhuma equipa com o ID indicado!" << endl << endl;
		gestaoEquipa(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 1 || idint > v1.getEquipas().size()){
		cout << endl << "\tNao existe nenhuma equipa com o ID indicado!" << endl << endl;
		gestaoEquipa(v1);
	}
	cout << "\n\t que pretende alterar na equipa?\n\n"
					<< "\t1 - Designacao da equipa"<< endl
					<< "\t2 - Pais de origem da equipa" << endl
					<< "\t3 - Patrocinador da equipa" << endl;
	string opt;
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoEquipa(v1);
	}
	int opti;
	opti = atoi(opt.c_str());
	string novoDado;
	cout << "\n\tIntroduza o novo elemento: \n";
	cin >> novoDado;
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idint){
			switch (opti) {
			case 1:
				v1.getEquipas()[i].setDesignacao(novoDado);
				break;
			case 2:
				v1.getEquipas()[i].setPais(novoDado);
				break;
			case 3:{
				Patrocinador p1(novoDado);
				v1.getEquipas()[i].setPatrocinador(p1);
				break;}
			default:
				try {
					throw OpcaoIncorrecta();
				}
				catch (OpcaoIncorrecta) {
					cout << endl << "\tOpcao que seleccionou nao esta correcta!"
							<< endl << endl;
					gestaoEquipa(v1);
				}
			}
		}
	}
	gestaoEquipa(v1);
}

void Menu::removeEquipa(Volta v1){
	string id;
	cout << "\tInsira o numero da equipa que pretende remover.\nID: ";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhuma equipa com o ID indicado!" << endl << endl;
		gestaoEquipa(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 1 || idint > v1.getEquipas().size()){
		cout << endl << "\tNao existe nenhuma equipa com o ID indicado!" << endl << endl;
		gestaoEquipa(v1);
	}
	v1.removeEquipa(idint);
	cout << "\n\tEquipa removida com exito!\n\n";
}

void Menu::listarEquipas(Volta v1){
	for (unsigned int i=0;i<v1.getEquipas().size();i++)
		v1.showEquipa(i+1);
	gestaoEquipas(v1);
}

void Menu::gestaoCiclistas(Volta v1){
	if (v1.getEquipas().size() == 0){
		cout << "\tNao existe nenhuma equipa inscrita na Volta!\n";
		gestaoEquipas(v1);
	}
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE CICLISTAS	 ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;

	string id;
	cout << "\n\tA qual equipa(ID) pretende gerir os ciclistas? Selecione '0' para  listar todas as equipas.\n";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoCiclistas(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 0 ){
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoCiclistas(v1);
	}
	if (idint == 0){
		listarEquipas(v1);
		gestaoCiclistas(v1);
	}
	cout << "\t0 - Voltar atras" << endl
				<< "\t1 - Adicionar Ciclista"<< endl
				<< "\t2 - Modificar Ciclista" << endl
				<< "\t3 - Remover Ciclista" << endl
				<< "\t4 - Listar Ciclistas" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoCiclistas(v1);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoEquipas(v1);
		break;
	case 1:
		adicionaCiclista(v1,idint);
		break;
	case 2:
		modificaCiclista(v1,idint);
		break;
	case 3:
		removeCiclista(v1,idint);
		break;
	case 4:
		listarCiclistas(v1,idint);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoEquipa(v1);
		}
	}
}

void Menu::adicionaCiclista(Volta v1, int idEquipa){
	string nome, pais, idade;
	cout << "\tInsira os dados do novo ciclista.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	cout << "\nPais: ";
	getline(cin,pais);
	cout << "\nIdade: ";
	cin.clear();
	getline(cin,idade);

	try {
		for (unsigned int i = 0; i < idade.size(); i++) {
			if (!isdigit(idade[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tA idade inserida está incorreta!" << endl << endl;
		gestaoCiclistas(v1);
	}

	int idadei;
	idadei = atoi(idade.c_str());
	Ciclista c1(nome, pais, 'm', idadei);
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa)
			v1.getEquipas()[i].addCiclista(c1);
	}
	cout << "\n\tCiclista adicionada com exito!\n\n";
	gestaoCiclistas(v1);
}

void Menu::modificaCiclista(Volta v1, int idEquipa){
	string id;
	cout << "\tInsira o numero do Ciclista que pretende alterar informacao.\nID: ";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhum ciclista com o ID indicado!" << endl << endl;
		gestaoCiclistas(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 1){
		cout << endl << "\tNao existe nenhum ciclista com o ID indicado!" << endl << endl;
		gestaoCiclistas(v1);
	}
	bool existe = false;
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
			for (unsigned int k=0;k<v1.getEquipas()[i].getCiclistas().size();k++){
				if (v1.getEquipas()[i].getCiclistas()[k].getId() == idint)
					existe = true;
			}
		}
	}
	if (!existe){
		cout << endl << "\tNao existe nenhum ciclista com o ID indicado!" << endl << endl;
		gestaoCiclistas(v1);
	}

	cout << "\n\tO que pretende alterar no ciclista?\n\n"
			<< "\t1 - Nome do Ciclista"<< endl
			<< "\t2 - Pais de origem do Ciclista" << endl
			<< "\t3 - Idade do Ciclista" << endl;
	string opt;
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoCiclistas(v1);
	}
	int opti;
	opti = atoi(opt.c_str());
	string novoDado;
	cout << "\n\tIntroduza o novo elemento: \n";
	cin >> novoDado;
	if (opti == 3){
		try {
			for (unsigned int i = 0; i < novoDado.size(); i++) {
				if (!isdigit(novoDado[i]))
					throw OpcaoIncorrecta();
			}
		} catch (OpcaoIncorrecta) {
			cout << endl << "\tO dado introduzido esta incorrecto!" << endl << endl;
			modificaCiclista(v1, idEquipa);
		}
	}
	int novoDadoInt = atoi(novoDado.c_str());
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			for (unsigned int k=0;k<v1.getEquipas()[i].getCiclistas().size();k++){
				if (v1.getEquipas()[i].getCiclistas()[k].getId() == idint){
					switch (opti) {
					case 1:
						v1.getEquipas()[i].getCiclistas()[k].setNome(novoDado);
						break;
					case 2:
						v1.getEquipas()[i].getCiclistas()[k].setNaciondalidade(novoDado);
						break;
					case 3:
						v1.getEquipas()[i].getCiclistas()[k].setIdade(novoDadoInt);
						break;
					default:
						try {
							throw OpcaoIncorrecta();
						}
						catch (OpcaoIncorrecta) {
							cout << endl << "\tOpcao que seleccionou nao esta correcta!"
									<< endl << endl;
							gestaoCiclistas(v1);
						}
					}
				}
			}
		}
	}

	cout << "\nNovo dado introduzido com exito!";
	gestaoCiclistas(v1);
}

void Menu::removeCiclista(Volta v1, int idEquipa){
	string id;
	cout << "\tInsira o numero do Ciclista que pretende remover.\nID: ";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhum Ciclista com o ID indicado!" << endl << endl;
		gestaoCiclistas(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 1 ){
		cout << endl << "\tNao existe nenhum Ciclista com o ID indicado!" << endl << endl;
		gestaoCiclistas(v1);
	}
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			v1.getEquipas()[i].removeCiclista(idint);
		}
	}

	cout << "\nCiclista removido com exito!\n\n";
	gestaoCiclistas(v1);
}

void Menu::listarCiclistas(Volta v1, int idEquipa){
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			cout << "\n\tCiclistas da equipa " << v1.getEquipas()[i].getDesignacao()
					<< "(" << v1.getEquipas()[i].getCiclistas().size() <<" ciclistas): \n";
			v1.getEquipas()[i].showCiclistas();
		}
	}
	gestaoCiclistas(v1);
}

void Menu::gestaoStaff(Volta v1){
	if (v1.getEquipas().size() == 0){
		cout << "\tNao existe nenhuma equipa inscrita na Volta!\n";
		gestaoEquipas(v1);
	}
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE STAFF	    ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
	string id;
	cout << "\n\tA qual equipa(ID) pretende gerir o staff? Selecione '0' para  listar todas as equipas.\n";
	cin >> id;
	try {
		for (unsigned int i = 0; i < id.size(); i++) {
			if (!isdigit(id[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoStaff(v1);
	}
	int idint;
	idint = atoi(id.c_str());
	if (idint < 0){
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoStaff(v1);
	}
	if (idint == 0){
		listarEquipas(v1);
		gestaoStaff(v1);
	}
	cout << "\t0 - Voltar atras" << endl
			<< "\t1 - Gestao Treinadores"<< endl
			<< "\t2 - Gestao Massagistas" << endl
			<< "\t3 - Gestao Mecanicos" << endl
			<< "\t4 - Listar todo o staff" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoStaff(v1);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoEquipas(v1);
		break;
	case 1:
		gestaoTreinadores(v1,idint);
		break;
	case 2:
		gestaoMassagistas(v1,idint);
		break;
	case 3:
		gestaoMecanicos(v1,idint);
		break;
	case 4:
		//listarStaff(v1,idint);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoStaff(v1);
		}
	}
}

void Menu::gestaoTreinadores(Volta v1, int idEquipa){
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE TREINADORES	   ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
	cout << "\t0 - Voltar atras" << endl
			<< "\t1 - Adicionar Treinador"<< endl
			<< "\t2 - Remover Treinador"<< endl
			<< "\t3 - Listar todos os Treinadores" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoTreinadores(v1,idEquipa);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoStaff(v1);
		break;
	case 1:
		adicionaTreinador(v1,idEquipa);
		break;
	case 2:
		removeTreinador(v1,idEquipa);
		break;
	case 3:
		listarTreinadores(v1,idEquipa);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoTreinadores(v1,idEquipa);
		}
	}
}
void Menu::adicionaTreinador(Volta v1, int idEquipa){
	string nome, pais, idade;
	char sexo;
	cout << "\tInsira os dados do novo treinador.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	cout << "\nPais: ";
	getline(cin,pais);
	cout << "\nIdade: ";
	getline(cin,idade);
	try {
		for (unsigned int i = 0; i < idade.size(); i++) {
			if (!isdigit(idade[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tA idade inserida está incorreta!" << endl << endl;
		gestaoTreinadores(v1,idEquipa);
	}
	cout << "\nSexo: (m/f)";
	cin >> sexo;
	if (sexo != 'm' && sexo != 'f'){
		cout << endl << "\tO sexo inserido está incorreto!" << endl << endl;
		gestaoTreinadores(v1,idEquipa);
	}
	int idadei;
	idadei = atoi(idade.c_str());
	Treinador t1(nome, pais, sexo, idadei);
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa)
			v1.getEquipas()[i].addMembro(&t1);
	}
	cout << "\n\tTreinador adicionado com exito!\n\n";
	gestaoTreinadores(v1,idEquipa);
}
void Menu::removeTreinador(Volta v1, int idEquipa){
	string nome;
	cout << "\tInsira o nome do Treinador que pretende remover.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	bool existe = false;
	try {
		for (unsigned int i = 0; i < v1.getEquipas().size(); i++) {
			if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
				for (unsigned int k = 0;k<v1.getEquipas()[i].getMembros().size();k++){
					if(v1.getEquipas()[i].getMembros()[k]->getTipo() == "treinador"){
						if(str_to_upper(v1.getEquipas()[i].getMembros()[k]->getNome()) == str_to_upper(nome))
							existe = true;
					}
				}
			}
		}
		if (!existe)
			throw OpcaoIncorrecta();
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhum Treinador com o nome indicado!" << endl << endl;
		gestaoTreinadores(v1,idEquipa);
	}
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			v1.getEquipas()[i].removeMembro(nome);
		}
	}
	cout << "\nTreinador removido com exito!\n\n";
	gestaoTreinadores(v1,idEquipa);
}
void Menu::listarTreinadores(Volta v1, int idEquipa){
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
			for (unsigned int k=0;k<v1.getEquipas()[i].getMembros().size();k++){
				if (v1.getEquipas()[i].getMembros()[k]->getTipo() == "treinador"){
					cout << "Nome; " << v1.getEquipas()[i].getMembros()[k]->getNome() << "\n";
					cout << "Pais: " << v1.getEquipas()[i].getMembros()[k]->getNacionalidade() << "\n";
					cout << "Idade: " << v1.getEquipas()[i].getMembros()[k]->getIdade() << "\n";
					cout << "Sexo: " << v1.getEquipas()[i].getMembros()[k]->getSexo() << endl;
				}
			}
		}
	}
	gestaoStaff(v1);
}

void Menu::gestaoMassagistas(Volta v1, int idEquipa){
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE MASSAGISTAS	   ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
	cout << "\t0 - Voltar atras" << endl
			<< "\t1 - Adicionar Massagista"<< endl
			<< "\t2 - Remover Massagista"<< endl
			<< "\t3 - Listar todos os Massagistas" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoMassagistas(v1,idEquipa);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoStaff(v1);
		break;
	case 1:
		adicionaMassagista(v1,idEquipa);
		break;
	case 2:
		removeMassagista(v1,idEquipa);
		break;
	case 3:
		listarMassagistas(v1,idEquipa);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoMassagistas(v1,idEquipa);
		}
	}
}
void Menu::adicionaMassagista(Volta v1, int idEquipa){
	string nome, pais, idade;
	char sexo;
	cout << "\tInsira os dados do novo massagista.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	cout << "\nPais: ";
	getline(cin,pais);
	cout << "\nIdade: ";
	getline(cin,idade);
	try {
		for (unsigned int i = 0; i < idade.size(); i++) {
			if (!isdigit(idade[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tA idade inserida está incorreta!" << endl << endl;
		gestaoMassagistas(v1,idEquipa);
	}
	cout << "\nSexo: (m/f)";
	cin >> sexo;
	if (sexo != 'm' && sexo != 'f'){
		cout << endl << "\tO sexo inserido está incorreto!" << endl << endl;
		gestaoMassagistas(v1,idEquipa);
	}
	int idadei;
	idadei = atoi(idade.c_str());
	Massagista t1(nome, pais, sexo, idadei);
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa)
			v1.getEquipas()[i].addMembro(&t1);
	}
	cout << "\n\tTreinador adicionado com exito!\n\n";
	gestaoMassagistas(v1,idEquipa);
}
void Menu::removeMassagista(Volta v1, int idEquipa){
	string nome;
	cout << "\tInsira o nome do Massagista que pretende remover.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	bool existe = false;
	try {
		for (unsigned int i = 0; i < v1.getEquipas().size(); i++) {
			if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
				for (unsigned int k = 0;k<v1.getEquipas()[i].getMembros().size();k++){
					if(v1.getEquipas()[i].getMembros()[k]->getTipo() == "massagista"){
						if(str_to_upper(v1.getEquipas()[i].getMembros()[k]->getNome()) == str_to_upper(nome))
							existe = true;
					}
				}
			}
		}
		if (!existe)
			throw OpcaoIncorrecta();
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhum Massagista com o nome indicado!" << endl << endl;
		gestaoTreinadores(v1,idEquipa);
	}
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			v1.getEquipas()[i].removeMembro(nome);
		}
	}
	cout << "\nMassagista removido com exito!\n\n";
	gestaoMassagistas(v1,idEquipa);
}
void Menu::listarMassagistas(Volta v1, int idEquipa){
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
			for (unsigned int k=0;k<v1.getEquipas()[i].getMembros().size();k++){
				if (v1.getEquipas()[i].getMembros()[k]->getTipo() == "massagista"){
					cout << "Nome; " << v1.getEquipas()[i].getMembros()[k]->getNome() << "\n";
					cout << "Pais: " << v1.getEquipas()[i].getMembros()[k]->getNacionalidade() << "\n";
					cout << "Idade: " << v1.getEquipas()[i].getMembros()[k]->getIdade() << "\n";
					cout << "Sexo: " << v1.getEquipas()[i].getMembros()[k]->getSexo() << endl;
				}
			}
		}
	}
	gestaoStaff(v1);
}

void Menu::gestaoMecanicos(Volta v1, int idEquipa){
	cout << endl << "\t###################################" << endl
				<< "\t##                               ##" << endl
				<< "\t##       GESTAO DE MECANICOS	   ##" << endl
				<< "\t##                               ##" << endl
				<< "\t###################################" << endl;
	cout << "\t0 - Voltar atras" << endl
			<< "\t1 - Adicionar Mecanico"<< endl
			<< "\t2 - Remover Mecanico"<< endl
			<< "\t3 - Listar todos os Mecanicos" << endl;
	string opt;
	cout << "\tOpção: ";
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoMecanicos(v1,idEquipa);
	}
	int opti;
	opti = atoi(opt.c_str());
	switch (opti) {
	case 0:
		gestaoStaff(v1);
		break;
	case 1:
		adicionaMecanico(v1,idEquipa);
		break;
	case 2:
		removeMecanico(v1,idEquipa);
		break;
	case 3:
		listarMecanicos(v1,idEquipa);
		break;
	default:
		try {
			throw OpcaoIncorrecta();
		}
		catch (OpcaoIncorrecta) {
			cout << endl << "\tOpcao que seleccionou nao esta correcta!"
					<< endl << endl;
			gestaoMecanicos(v1,idEquipa);
		}
	}
}
void Menu::adicionaMecanico(Volta v1, int idEquipa){
	string nome, pais, idade;
	char sexo;
	cout << "\tInsira os dados do novo Mecanico.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	cout << "\nPais: ";
	getline(cin,pais);
	cout << "\nIdade: ";
	getline(cin,idade);
	try {
		for (unsigned int i = 0; i < idade.size(); i++) {
			if (!isdigit(idade[i]))
				throw OpcaoIncorrecta();
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tA idade inserida está incorreta!" << endl << endl;
		gestaoMecanicos(v1,idEquipa);
	}
	cout << "\nSexo: (m/f)";
	cin >> sexo;
	if (sexo != 'm' && sexo != 'f'){
		cout << endl << "\tO sexo inserido está incorreto!" << endl << endl;
		gestaoMecanicos(v1,idEquipa);
	}
	int idadei;
	idadei = atoi(idade.c_str());
	Mecanico t1(nome, pais, sexo, idadei);
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa)
			v1.getEquipas()[i].addMembro(&t1);
	}
	cout << "\n\tTreinador adicionado com exito!\n\n";
	gestaoMecanicos(v1,idEquipa);
}
void Menu::removeMecanico(Volta v1, int idEquipa){
	string nome;
	cout << "\tInsira o nome do Mecanico que pretende remover.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	bool existe = false;
	try {
		for (unsigned int i = 0; i < v1.getEquipas().size(); i++) {
			if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
				for (unsigned int k = 0;k<v1.getEquipas()[i].getMembros().size();k++){
					if(v1.getEquipas()[i].getMembros()[k]->getTipo() == "mecanico"){
						if(str_to_upper(v1.getEquipas()[i].getMembros()[k]->getNome()) == str_to_upper(nome))
							existe = true;
					}
				}
			}
		}
		if (!existe)
			throw OpcaoIncorrecta();
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tNao existe nenhum Mecanico com o nome indicado!" << endl << endl;
		gestaoMecanicos(v1,idEquipa);
	}
	for (unsigned int i=0;i<v1.getEquipas().size();i++){
		if (v1.getEquipas()[i].getIdEquipa() == idEquipa){
			v1.getEquipas()[i].removeMembro(nome);
		}
	}
	cout << "\nMecanico removido com exito!\n\n";
	gestaoMecanicos(v1,idEquipa);
}
void Menu::listarMecanicos(Volta v1, int idEquipa){
	for (unsigned int i=0;i< v1.getEquipas().size();i++){
		if(v1.getEquipas()[i].getIdEquipa() == idEquipa){
			for (unsigned int k=0;k<v1.getEquipas()[i].getMembros().size();k++){
				if (v1.getEquipas()[i].getMembros()[k]->getTipo() == "mecanico"){
					cout << "Nome; " << v1.getEquipas()[i].getMembros()[k]->getNome() << "\n";
					cout << "Pais: " << v1.getEquipas()[i].getMembros()[k]->getNacionalidade() << "\n";
					cout << "Idade: " << v1.getEquipas()[i].getMembros()[k]->getIdade() << "\n";
					cout << "Sexo: " << v1.getEquipas()[i].getMembros()[k]->getSexo() << endl;
				}
			}
		}
	}
	gestaoStaff(v1);
}

void Menu::gestaoEtapas(Volta v1){

	cout << endl << "\t###################################" << endl
		<< "\t##                               ##" << endl
		<< "\t##       GESTAO DE ETAPAS     ##" << endl
		<< "\t##                               ##" << endl
		<< "\t###################################" << endl;

	cout << "\t0 - Sair" << endl
			<< "\t1 - Adicionar etapa"<< endl
			<< "\t2 - Modificar etapa" << endl
			<< "\t3 - Remover etapa" << endl
			<< "\t4 - Listar todas as etapas" << endl;
	string opt;
	cin >> opt;
	try {
		for (unsigned int i = 0; i < opt.size(); i++) {
			if (!isdigit(opt[i])) {
				throw OpcaoIncorrecta();
			}
		}
	} catch (OpcaoIncorrecta) {
		cout << endl << "\tOpcao que seleccionou nao esta correcta!" << endl << endl;
		gestaoEtapas(v1);
	}
	int opti;
	opti = atoi(opt.c_str());

	switch (opti) {
	case 0:
		menuInicial(v1);
		break;
	case 1:
		criarEtapa(v1);
		break;
	case 2:
		//modificaEtapa();
		break;
	case 3:
		//removeEtapa();
		break;
	case 4:
		listarEtapas(v1);
		break;
	}


}

void Menu::criarEtapa(Volta v1){

	cout << endl << "\t*********************************" << endl
			<< "\t**                             **" << endl
			<< "\t**     Registo de  Etapa      **" << endl
			<< "\t**                             **" << endl
			<< "\t*********************************" << endl;

	string nome,local;
	int distancia,dia,mes,ano;
	cout << "\tInsira os dados da nova Etapa.\nNome: ";
	cin.clear();
	cin.ignore(100, '\n');
	getline(cin,nome);
	cout << "\nLocal: ";
	getline(cin,local);
	cout << "\nDistancia: ";
	cin >> distancia;
	cout << "\nAno: ";
	cin >> ano;
	cout << "\nMes: ";
	cin >> mes;
	cout << "\nDia: ";
	cin >> dia;
	for (unsigned int i=0;i<v1.getEtapas().size();i++){
		if (v1.getEtapas()[i]->getNome() == nome){
			cout << "\n\tJa existe uma etapa com esta designacao!\n\n";
			gestaoEtapas(v1);
		}
	}
	int tipo;
	cout << "\nQual o tipo de etapa que pretende criar? (montanha - 1, contra-relogio - 2 , normal - 3)";
	cin >> tipo;
	Data d1(ano,mes,dia);
	switch (tipo){
	case 1:{
		int kmini, kmfim;
		cout << "Km inicio de montanha? \n";
		cin >> kmini;
		cout << "Km fim de montanha? \n";
		cin >> kmfim;
		Montanha e1(nome,local,d1,distancia,kmini,kmfim);
		v1.addEtapa(&e1);
		break;}
	case 2:{
		ContraRelogio c1(nome,local,d1,distancia);
		v1.addEtapa(&c1);
		break;}
	case 3:
		Normal n1(nome,local,d1,distancia);
		v1.addEtapa(&n1);
		break;
	}
	cout << "\n\tEtapa adicionada com exito!\n\n";
	gestaoEtapas(v1);
}

/*void Menu::modificaEtapa(){
	string opt;
	int opti1,opti2;
	int contador=-1;
	do{
		contador++;
		//showEtapa();
		cout << "\tOpção: ";
		cin >> opt;
		opti1 = atoi(opt.c_str());

	}while(opti1 != 3);

	cout << "O que pretende Modificar?\n";
	cout << "1- Nome \n 2-Local \n3-Distancia\n 4-Data\n";

	cin >> opt;
	opti1 = atoi(opt.c_str());
	cout << "\nNovo dado: ";
	cin >> opt;
	if(opti1==3)
		opti2 = atoi(opt.c_str());
	if(opti1==4){
		int dia,mes,ano;
		cout << "\nDia: ";
		cin >> dia;
		cout << "\nMes: ";
		cin >> mes;
		cout << "\nAno";
		cin >> ano;
		//Data data1(ano,mes,dia);
	}

	switch(opti1){
	case 1:
		//volta.getEtapas[contador].setNome(opti2);
		break;
	case 2:
		//volta.getEtapas[contador].setLocal(opti2);
		break;
	case 3:
		//volta.getEtapas[contador].setDistancia(opti2);
		break;
	case 4:
		//volta.getEtapas[contador].setData(data1);
		break;
	}

}*/

void Menu::listarEtapas(Volta v1){
	for (unsigned int i = 0;i<v1.getEtapas().size();i++){
		v1.showEtapa(v1.getEtapas()[i]->getIdEtapa());
	}
}

/*void Menu::showEtapa(Etapa & etapa1){
	cout <<

}*/

/*void Menu::gestaoTempos(){
	cout << endl << "\t###################################" << endl
		<< "\t##                               ##" << endl
		<< "\t##       GESTAO DE TEMPOS       ##" << endl
		<< "\t##                               ##" << endl
		<< "\t###################################" << endl;

		cout << "\t0 - Sair" << endl
				<< "\t1 - inserir tempos de etapa"<< endl
				<< "\t2 - modificar tempos" << endl;
}*/



