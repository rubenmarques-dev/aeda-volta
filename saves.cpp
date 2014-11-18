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




void saveEquipa(Equipa equipa1){
	ofstream doc;

	string ficheiro=ficheiroEquipa(equipa1.getIdEquipa());
	doc.open(ficheiro.c_str(), ofstream::out);

	if (doc.is_open())
	{


			doc << equipa1.getDesignacao() << endl;
			doc << equipa1.getPais() << endl;
			doc << equipa1.getPatrocinador().getNome() << endl;




	}
	doc.close();
	//cout << "2";
	saveCiclistas(equipa1.getCiclistas());

}

void saveEquipas(vector<Equipa> equipas){

	for(int i=0;i<equipas.size();i++){
		saveEquipa(equipas[i]);
	}
}

void saveCiclistas(vector<Ciclista> ciclistas){
	//cout << "3";
	for(int i=0;i<ciclistas.size();i++){
			saveCiclista(ciclistas[i] );
		}
	//cout << "aa";
}

void saveCiclista(Ciclista ciclista){
	ofstream doc1;

	string ficheiro=ficheiroCiclista(ciclista.getId());
	//cout << "4";
	doc1.open(ficheiro.c_str(), ofstream::out);
	//cout << "5";
	if (doc1.is_open())
	{


			doc1 << ciclista.getNome() << endl;
			doc1 << ciclista.getNacionalidade() << endl;
			doc1 << ciclista.getSexo() << endl;
			doc1 << ciclista.getIdade() << endl;
			/*
			vector<Tempo *> tempos=ciclista.getTempos();

			for(unsigned int i=0;i<tempos.size();i++){
					if(tempos[i]->getTipo()=="normal")
						doc1<<"normal" << endl<<tempos[i]->tempo() << endl;
					else if(tempos[i]->getTipo()=="contraRelogio")
						doc1<<"contraRelogio" << endl<<tempos[i]->tempo() << endl;
					else if(tempos[i]->getTipo()=="montanha")
						doc1<<"normal" << endl<<tempos[i]->tempo() << endl<< tempos[i]->getTempoMontanha().tempo();
					}
		*/
	}
	doc1.close();


}





void guardarMembro(vector<Membro*>membro, string ficheiro)
{
	ofstream doc;

	doc.open("membros.txt", ofstream::out);

	if (doc.is_open())
	{
		doc<<membro.size()<<endl;
		vector<Membro*>::iterator it;
		doc << static_cast<int>(membro.size()) << endl;
		for (it = membro.begin(); it != membro.end(); it++)
		{
			doc << (*it)->getTipo() << endl;
			doc << (*it)->getNome() << endl;
			doc << (*it)->getNacionalidade() << endl;
			doc << (*it)->getSexo() << endl;
			doc << (*it)->getIdade() << endl;
		}
	}

	doc.close();
}

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
void guardarCiclista(vector<Ciclista*>ciclista, string ficheiro)
{
	ofstream doc;

	doc.open("ciclistas.txt", ofstream::out);

	if (doc.is_open())
	{

		doc<<ciclista.size()<<endl;
		vector<Ciclista*>::iterator it;
		doc << static_cast<int>(ciclista.size()) << endl;
		for (it = ciclista.begin(); it != ciclista.end(); it++)
		{

			doc << (*it)->getTipo() << endl;
			doc << (*it)->getNome() << endl;
			doc << (*it)->getNacionalidade() << endl;
			doc << (*it)->getSexo() << endl;
			doc << (*it)->getIdade() << endl;
			doc << (*it)->getId() << endl;
			doc << (*it)->getUltimoCiclista() << endl;
			doc << (*it)->getDesistiu() << endl;
			//guardar info de tempos do vetor ciclista
			doc << (*it)->getTempos().size() << endl;
			vector<Tempo*>::iterator itTempos= (*it)->getTempos().begin();
			for(; itTempos!= (*it)->getTempos().end(); itTempos++ )
			{
				doc << (*itTempos)->getTipo()<<endl;
				doc << (*itTempos)->getHora() << endl;
				doc << (*itTempos)->getMinuto() << endl;
				doc << (*itTempos)->getSegundo() << endl;
			}
		}

	}

	doc.close();
}

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

