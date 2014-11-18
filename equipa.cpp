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

Equipa::Equipa(){

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

vector<Membro *> Equipa::getMembrosCopy(){
	return membros;
}

vector<Ciclista> & Equipa::getCiclistas(){
	return ciclistas;
}

vector<Ciclista>  Equipa::getCiclistasCopy(){
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

	for(vector<Ciclista>::iterator it=ciclistas.begin();it!=ciclistas.end();it++){

		if((*it).getId()==idCiclista){
			ciclistas.erase(it);
			existe=true;
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
	for (vector<Membro*>::iterator it=membros.begin();it!=membros.end();it++){
		if ((*it)->getNome() == nome){
			membros.erase(it);
			return true;
		}
	}
	return false;
}

string  Equipa::listaMassagistas(){
	stringstream ss;
	Membro * membro;
	for(unsigned int i=0;i<membros.size();i++){
		membro=membros[i];
		if(membro->getTipo()=="massagista")
			ss << membro->info() << "\n";
	}
	return ss.str();
}

/*
void Equipa::addTempoProvaToCiclista(vector<TempoProva>){


}
*/
void Equipa::ciclistaDesistiu(int idCiclista){
	Ciclista  *ciclista;
	for(unsigned int i=0;i<ciclistas.size();i++){
		ciclista=&ciclistas[i];
		if(ciclista->getId()==idCiclista){
			ciclista->setDesistiu(true);

		}
	}
}

Tempo Equipa::tempoMedioDaEquipa(){
	Tempo tempoTotal(0,0,0);
	Tempo tempoAuxiliar(0,0,0);
	Ciclista ciclista;
	if(ciclistas.size()>0){
		for(unsigned int i=0;i<ciclistas.size();i++){
			ciclista=ciclistas[i];
			tempoAuxiliar=ciclista.getTempoTotal();
			tempoTotal=tempoTotal+tempoAuxiliar;
		}
		return tempoTotal/ciclistas.size();
	}
	return tempoTotal;
}

Ciclista Equipa::melhorClassificado() {
	Tempo melhorTempo(99,99,99);
	Tempo tempoAuxiliar(0,0,0);
	int melhorClassificado;
	Ciclista ciclista;

	for(unsigned int i=0;i<ciclistas.size();i++){
		ciclista=ciclistas[i];
		if(!ciclista.getDesistiu()){
			tempoAuxiliar=ciclista.getTempoTotal();
			if(melhorTempo<tempoAuxiliar){
				melhorClassificado=i;

			}
		}
	}

	return ciclistas[melhorClassificado];

}


vector<Ciclista> Equipa::ciclistasDesistentes() {
	vector<Ciclista> ciclistasDesistentes;
	Ciclista ciclista;
	if(ciclistas.size()>0){
		for(unsigned int i=0;i<ciclistas.size();i++){
			ciclista=ciclistas[i];
			if(ciclista.getDesistiu()){
				ciclistasDesistentes.push_back(ciclista);
			}
		}
	}
	return ciclistasDesistentes;
}

void Equipa::showCiclistas(){
	Ciclista ciclista;
	for (unsigned int i=0;i<ciclistas.size();i++){
		ciclista=ciclistas[i];
		cout << "Nome: " << ciclista.getNome() << "\n";
		cout << "ID: " << ciclista.getId() << "\n";
		cout << "Pais: " << ciclista.getNacionalidade() << "\n";
		cout << "Idade: " << ciclista.getIdade() << "\n\n";
	}
}

/////////FIM CLASS EQUIPA////////////



