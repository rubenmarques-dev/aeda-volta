/*
 * saves.cpp
 *
 *  Created on: 09/11/2014
 *      Author: Admin
 */
#include"saves.h"
#include <sstream>






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

void saveEtapas(vector<Etapa*> etapas){
	ofstream doc;
	doc.open("etapas.txt", ofstream::out);
	Etapa* etapa;
	if (doc.is_open())
	{
		doc << etapas.size();
		for(unsigned int i=0;i<etapas.size();i++){
			etapa=etapas[i];
			doc << etapa->getTipo() << endl;
			doc << etapa->getIdEtapa() << endl;
			doc << etapa->getNome() << endl;
			doc << etapa->getLocal() << endl;
			doc << etapa->getData().info() << endl;
			doc << etapa->getDistancia() << endl;
			if(etapa->getTipo()=="montanha"){
				doc << etapa->getDistanciaMontanha();
			}

			doc << "endEtapa" << endl;

		}
	}
	doc.close();
}

vector<Etapa*>  loadEtapas(){
	vector<Membro*> membrotemp;
	ifstream doc;
	Etapa* etapa;
	string numEtapas;
	int size;
	string emBranco;
	string tipo;
	string idEtapa;
	string nome;
	string local;
	string data;
	string distancia;
	string distanciaMontanha;
	int distanciaInt;
	int distanciaMontanhaInt;
	int idEtapaInt;
	ifstream myfile ("etapas.txt");
	 if (myfile.is_open())
	  {
		 getline(doc, numEtapas);
		 size=atoi(numEtapas.c_str());

		 for(int i=0;i<size;i++){
			 getline(doc, tipo);
			 getline(doc, idEtapa);
			 getline(doc, nome);
			 getline(doc, local);
			 getline(doc, data);
			 getline(doc, distancia);
			 if(tipo=="montanha")
			 getline(doc, distanciaMontanha);
			 distanciaInt=atoi(distancia.c_str());
			 distanciaMontanhaInt=atoi(distanciaMontanha.c_str());
			 idEtapaInt=atoi(idEtapa.c_str());
			 if(tipo=="montanha")


		 }

	  }

}

Data getData(string data){
	char ch;
	stringstream ss;
	int ano, mes, dia;
	int contador=0;
	for(int i=0;i<data.size();i++){
		ch=data[i];
		if(ch != '/')
			ss << ch;
		else
		{
			if(contador == 0)
				ano=atoi(ss.str().c_str());
			if(contador == 1)
				mes=atoi(ss.str().c_str());
			ss.str("");
		}
	}
	dia=ano=atoi(ss.str().c_str());
	Data d(ano,mes,dia);
	return d;
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

