/*
Attaque.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la d�finition de la classe Attaque
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <iostream>
#include "../../utils/Utils.hpp"
#include "../enums/Enums.hpp"

class Pokemon;
/**
Repr�sente une attaque Pok�mon
*/
class Attaque{
public:
	virtual ~Attaque(){}
	Attaque(std::string nom, int puissance, int type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite);
	virtual int effetAvant(Pokemon &atk, Pokemon &def) = 0;
	virtual int effetApres(Pokemon &atk, Pokemon &def) = 0;
	void healPP(){pp = ppMax;}
	virtual int attack(Pokemon &atk, Pokemon &def) final;
	virtual void siEchoue(Pokemon &atk, Pokemon &def){}
protected:
	std::string nom;
	int puissance;
	int priorite;
	int precision;
	int type;
	bool special;
	bool status;
	int part = 0;
	int pp;
	int ppMax;
	int chanceDeCoups;
	bool rateJamais;
	int pvPerdus = 0;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */