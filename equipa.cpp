/////////INICIO CLASS EQUIPA//////////
#include "equipa.h"


Patrocinador::Patrocinador(string nome){
	this->nome=nome;
}

string Patrocinador::getNome() const{
	return nome;
}

int Equipa::ultimaEquipa { 0 };

Equipa::Equipa(string designacao, string pais, Patrocinador patrocinador){
	this->designacao=designacao;
	this->pais=pais;
	this->patrocinador=patrocinador;
	id=++ultimaEquipa;
}

int Equipa::getIdEquipa() const{
	return id;
}

string Equipa::getDesignacao() const{
	return designacao;
}

string Equipa::getPais() const{
	return pais;
}

Patrocinador Equipa::getPatrocinador() const{
	return patrocinador;
}

vector<Membro *> & Equipa::getMembros(){
	return membros;
}

vector<Ciclista> & Equipa::getCiclistas(){
	return ciclistas;
}

void Equipa::setIdEquipa(int idEquipa){
	id = idEquipa;
}

void Equipa::setPatrocinador(Patrocinador patrocinador){
	this->patrocinador = patrocinador;
}

void Equipa::setDesignacao(string designacao){
	this->designacao = designacao;
}

void Equipa::setPais(string pais){
	this->pais = pais;
}

bool Equipa::addCiclista(Ciclista ciclista1){
	ciclistas.push_back(ciclista1);
	return true;
}

bool Equipa::removeCiclista(int idCiclista){
	bool existe=false;
	for(unsigned int i=0;i<ciclistas.size();i++){
		if(ciclistas[i].getId()==idCiclista){
			ciclistas.erase(ciclistas.begin()+i);
			existe=true;
			for (unsigned int k=i;k<ciclistas.size();k++){
				ciclistas[k].setID((ciclistas[k].getId()-1));
			}
		}
		if(existe)
			break;
	}
	return existe;
}

bool Equipa::addMembro(Membro *membro1){
	membros.push_back(membro1);
	return true;
}

bool Equipa::removeMembro(string nome){
	for (unsigned int i=0;i<membros.size();i++){
		if (membros[i]->getNome() == nome){
			membros.erase(membros.begin() + i);
			return true;
		}
	}
	return false;
}

string  Equipa::listaMassagistas(){
	stringstream ss;
	for(unsigned int i=0;i<membros.size();i++){
		if(membros[i]->getTipo()=="massagista")
			ss << membros[i]->info() << "\n";
	}
	return ss.str();
}

/*
void Equipa::addTempoProvaToCiclista(vector<TempoProva>){


}
*/
void Equipa::ciclistaDesistiu(int idCiclista){
	for(unsigned int i=0;i<ciclistas.size();i++){
		if(ciclistas[i].getId()==idCiclista){
			ciclistas[i].setDesistiu(true);
		}
	}
}

Tempo Equipa::tempoMedioDaEquipa(){
	Tempo tempoTotal(0,0,0);
	Tempo tempoAuxiliar(0,0,0);
	if(ciclistas.size()>0){
		for(unsigned int i=0;i<ciclistas.size();i++){
			tempoAuxiliar=ciclistas[i].getTempoTotal();
			tempoTotal=tempoTotal+tempoAuxiliar;
		}
		return tempoTotal/ciclistas.size();
	}
	return tempoTotal;
}

Ciclista Equipa::melhorClassificado() {
	Tempo melhorTempo(99,99,99);
	Tempo tempoAuxiliar(0,0,0);
	char c;
	Ciclista vector_vazio("unknown","unknown",c,1);
	int melhorClassificado;


	if(ciclistas.size()>0){
	for(unsigned int i=0;i<ciclistas.size();i++){

		if(!ciclistas[i].getDesistiu()){
			tempoAuxiliar=ciclistas[i].getTempoTotal();
			if(melhorTempo<tempoAuxiliar){
				melhorClassificado=i;

			}
		}
	}
	}
	else
		return vector_vazio;

	return ciclistas[melhorClassificado];

}


vector<Ciclista> Equipa::ciclistasDesistentes() {
	vector<Ciclista> ciclistasDesistentes;
	if(ciclistas.size()>0){
		for(unsigned int i=0;i<ciclistas.size();i++){
			if(ciclistas[i].getDesistiu()){
				ciclistasDesistentes.push_back(ciclistas[i]);
			}
		}
	}
	return ciclistasDesistentes;
}

void Equipa::showCiclistas(){
	for (unsigned int i=0;i<ciclistas.size();i++){
		cout << "Nome: " << ciclistas[i].getNome() << "\n";
		cout << "ID: " << ciclistas[i].getId() << "\n";
		cout << "Pais: " << ciclistas[i].getNacionalidade() << "\n";
		cout << "Idade: " << ciclistas[i].getIdade() << "\n\n";
	}
}

/////////FIM CLASS EQUIPA////////////



