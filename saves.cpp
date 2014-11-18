/*
 * saves.cpp
 *
 *  Created on: 09/11/2014
 *      Author: Admin
 */
#include"saves.h"
#include <sstream>


string ficheiroEquipa(int idEquipa){
	stringstream ss;
	if(idEquipa<10)
		ss << "equipa0" << idEquipa << ".txt";
	else
		ss << "equipa" << idEquipa << ".txt";
	return ss.str();
}

string ficheiroCiclista(int id){
	stringstream ss;
	if(id>=100)
		ss << "ciclista" << id;
	else if(id>=10)
		ss << "ciclista0" << id;
	else
		ss << "ciclista00" << id;


	return ss.str();
}




void saveEquipas(vector<Equipa> equipas){
	ofstream doc;


	doc.open("equipas.txt", ofstream::out);
	Equipa equipa;
	vector<Ciclista> ciclistas;
	vector<Membro *> membros;
	Membro* membro;
	TempoRef tempoRef;
	Tempo tempoMontanha;
	Ciclista ciclista;
	vector<TempoRef> tempos;
	if (doc.is_open())
	{
			for(unsigned int eq=0;eq<equipas.size();eq++){
				equipa=equipas[eq];
				ciclistas=equipa.getCiclistasCopy();
				membros=equipa.getMembrosCopy();


			doc << equipa.getIdEquipa() << endl;
			doc << equipa.getDesignacao() << endl;
			doc << equipa.getPais() << endl;
			doc << equipa.getPatrocinador().getNome() << endl;
			for(unsigned int c=0;c<ciclistas.size();c++){
				ciclista=ciclistas[c];

				doc << ciclista.getId() << endl;
				doc << ciclista.getNome() << endl;
				doc << ciclista.getNacionalidade() << endl;
				doc << ciclista.getSexo() << endl;
				doc << ciclista.getIdade() << endl;

				tempos=ciclista.getTemposCopy();
				for(unsigned int t=0;t<tempos.size();t++){
					tempoRef=tempos[t];
					doc << tempoRef.get()->getTipo() << endl;
					doc << tempoRef.get()->tempo() << endl;
					if(tempoRef.get()->getTipo() == "montanha"){
						doc << tempoRef.get()->getTempoMontanha().tempo() << endl;
					}
				}
				doc << "endCiclista" << endl;
			}
			membros=equipa.getMembrosCopy();
			for(unsigned int m=0;m<membros.size();m++){
				membro=membros[m];
				doc << membro->getNome() << endl;
				doc << membro->getNacionalidade() << endl;
				doc << membro->getSexo() << endl;
				doc << membro->getIdade() << endl;
				doc << membro->getTipo();
			}



			}
	}
	doc.close();


}




/*

vector<Membro*> loadMembro(string ficheiro)
{
	vector<Membro*> membrotemp;
	ifstream doc;

	int SizeInt = 0;
	Membro* a1;

	string emBranco;
	string size;
	string nome;
	string nacionalidade;
	string tipo;
	string sexo;
	string ddn;
	int idade = 0;

	doc.open(ficheiro.c_str(), ifstream::in);

	if (doc.is_open())
	{
		getline(doc, size);
		SizeInt = atoi(size.c_str());
		getline(doc, emBranco);
		for (unsigned int i = 0; i < SizeInt; i++)
		{
			getline(doc, tipo);
			getline(doc, nome);
			getline(doc, nacionalidade);
			getline(doc, sexo);
			char s = sexo[0];
			getline(doc, ddn);
			idade = atoi(ddn.c_str());
			if(tipo=="massagista")
				a1= new Massagista(nome , nacionalidade , s , idade);
			if(tipo=="mecanico")
				a1= new Mecanico(nome , nacionalidade , s , idade);
			if(tipo=="treinador")
				a1= new Treinador(nome , nacionalidade , s , idade);

			cout<<a1->getTipo()<<endl;
			membrotemp.push_back(a1);
		}
	}
	return membrotemp;
}

/*
vector<Ciclista> loadCiclista(string ficheiro)
{
	vector<Ciclista> ciclistatemp;
	ifstream doc;

	int SizeInt = 0;
	Membro* a1;

	string emBranco;
	string size;
	string nome;
	string nacionalidade;
	string sexo;
	string ddn;
	string id;
	string idUltimoCiclista;
	string desistiu;
	string tipo;
	string hora;
	string minuto;
	string segundo;
	int idade = 0;

	doc.open(ficheiro.c_str(), ifstream::in);

	if (doc.is_open())
	{
		getline(doc, size);
		SizeInt = atoi(size.c_str());
		getline(doc, emBranco);
		for (unsigned int i = 0; i < SizeInt; i++)
		{
			getline(doc, nome);
			getline(doc, nacionalidade);
			getline(doc, sexo);
			char s = sexo[0];
			getline(doc, ddn);
			idade = atoi(ddn.c_str());
			getline(doc, id);
			getline(doc, idUltimoCiclista);
			getline(doc, desistiu);

			cout<<a1->getTipo()<<endl;
			ciclistatemp.push_back(a1);
		}

	}
	return ciclistatemp;
}
*/

