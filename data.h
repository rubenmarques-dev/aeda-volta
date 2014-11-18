/*
 * data.h
 *
 *  Created on: 06/11/2014
 *      Author: ei11140
 */

#ifndef DATA_H_
#define DATA_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Data{
	int ano;
	int mes;
	int dia;
public:
	Data(int ano, int mes, int dia);
	Data(){}
	int getAno() const;
	int getMes() const;
	int getDia() const;
	void setAno(int ano);
	void setMes(int mes);
	void setDia(int dia);
	bool operator<(const Data & data1);
	bool operator==(const Data & data1);
	void showData();
};


#endif /* DATA_H_ */
