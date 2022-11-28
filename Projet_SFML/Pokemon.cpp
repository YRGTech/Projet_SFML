#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
	this->m_numero = 0;
	this->m_exp = 0;
	this->m_lvl = 1;
	this->m_nom = "None";
	this->m_type1 = "None";
	this->m_type2 = "None";
	this->m_pvMax = 0;
	this->m_pv = 0;
	this->m_attaque = 0;
	this->m_attaqueSpe = 0;
	this->m_defense = 0;
	this->m_defenseSpe = 0;
	this->m_vitesse = 0;
	m_capacite1 = new Capacite;
	m_capacite2 = new Capacite;

	this->m_pvBase = 0;
	this->m_attaqueBase = 0;
	this->m_attaqueSpeBase = 0;
	this->m_defenseBase = 0;
	this->m_defenseSpeBase = 0;
	this->m_vitesseBase = 0;
}

void Pokemon::creationPokemon(int numeroPokemon) //Inclure attaque sp� et d�fense sp�
{
	switch (numeroPokemon)
	{

	case(155): //H�ricendre 40 et 30
		m_numero = numeroPokemon;
		m_nom = "H�ricendre";
		m_type1 = "Fire";
		m_pvBase = m_pvMax = m_pv = 39;
		m_attaqueBase = m_attaque = 52;
		m_attaqueBase = m_attaqueSpe = 43;
		m_defenseBase = m_defense = 60;
		m_defenseSpeBase = m_defenseSpe = 50;
		m_vitesseBase = m_vitesse = 35;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(393):	//Tiplouf 40 et 40
		m_numero = numeroPokemon;
		m_nom = "Tiplouf";
		m_type1 = "Water";
		m_pvBase = m_pvMax = m_pv = 53;
		m_attaqueBase = m_attaque = 51;
		m_attaqueBase = m_attaqueSpe = 61;
		m_defenseBase = m_defense = 53;
		m_defenseSpeBase = m_defenseSpe = 56;
		m_vitesseBase = m_vitesse = 40;
		m_capacite1->capaciteCreation(numeroPokemon,1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(406):	//Rozbouton 25 et 40
		m_numero = numeroPokemon;
		m_nom = "Rozbouton";
		m_type1 = "Grass";
		m_pvBase = m_pvMax = m_pv = 40;
		m_attaqueBase = m_attaque = 30;
		m_attaqueSpeBase = m_attaqueSpe = 35;
		m_defenseBase = m_defense = 50;
		m_defenseSpeBase = m_defenseSpe = 70;
		m_vitesseBase = m_vitesse = 55;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	case(443):	//Griknot 40 et 35 CHECK
		m_numero = numeroPokemon;
		m_nom = "Griknot";
		m_type1 = "Ground";
		m_type2 = "Dragon";
		m_pvBase = m_pvMax = m_pv = 58;
		m_attaqueBase = m_attaque = 70;
		m_attaqueSpeBase = m_attaqueSpe = 45;
		m_defenseBase = m_defense = 40;
		m_defenseSpeBase = m_defenseSpe = 45;
		m_vitesseBase = m_vitesse = 42;
		m_capacite1->capaciteCreation(numeroPokemon, 1);
		m_capacite2->capaciteCreation(numeroPokemon, 2);
		break;

	default:
		break;
	}
}

void Pokemon::evolutionPokemon(int numeroPokemon)
{
	switch (numeroPokemon)
	{
	case(443):
		numeroPokemon = 444;
		break;

	default:
		break;
	}
}

void Pokemon::expUp(int exp)
{
	m_exp += exp;
	if (m_exp >= m_lvl ^ 3)
	{
		m_exp -= m_lvl ^ 3;
		lvlUp();
	}
}

void Pokemon::lvlUp()
{
	m_lvl++;

	m_pv += ((2*m_pvBase*m_lvl)/100) + m_lvl + 10;
	m_attaque += ((2*m_attaqueBase*m_lvl)/100) + 5;
	m_attaqueSpe += ((2 * m_attaqueSpeBase * m_lvl) / 100) + 5;
	m_defense += ((2 * m_defenseBase * m_lvl) / 100) + 5;
	m_defenseSpe += ((2 * m_defenseSpeBase * m_lvl) / 100) + 5;
	m_vitesse += ((2 * m_vitesseBase * m_lvl) / 100) + 5;
}

void Pokemon::attaquer(Pokemon& victime, int numeroCapacite)
{
	switch (numeroCapacite)
	{
	case(1):
		if (m_capacite1->getSpe() == true)
		{
			victime.recevoirDegats(resistance(victime, *m_capacite1) * (m_attaqueSpe + m_capacite1->getPuissance() - victime.getDefenseSpe()));
		}
		else
		{
			victime.recevoirDegats(m_attaque + m_capacite1->getPuissance() - victime.getDefense());
		}
		break;

	case(2):
		if (m_capacite2->getSpe() == true)
		{
			victime.recevoirDegats(resistance(victime, *m_capacite2) * (m_attaqueSpe + m_capacite2->getPuissance() - victime.getDefenseSpe()));
		}
		else
		{
			victime.recevoirDegats(m_attaque + m_capacite2->getPuissance() - victime.getDefense());
		}
		break;

	default:
		break;
	}
}

void Pokemon::recevoirDegats(int degats)
{
	if (degats< 0)
	{
		std::cout << "L'attaque est negatif" << std::endl;
		m_pv--;
	}
	else
	{
		m_pv -= (degats);
	}
}

//Get

std::string Pokemon::getNom()
{
	return m_nom;
}

int Pokemon::getPv()
{
	return m_pv;
}

int Pokemon::getDefense()
{
	return m_defense;
}

int Pokemon::getDefenseSpe()
{
	return m_defenseSpe;
}

int Pokemon::getVitesse()
{
	return m_vitesse;
}

std::string Pokemon::getType1()
{
	return m_type1;
}
std::string Pokemon::getType2()
{
	return m_type2;
}

std::string Pokemon::getCapacite1()
{
	return m_capacite1->getNom();
}

std::string Pokemon::getCapacite2()
{
	return m_capacite2->getNom();
}

//Set
void Pokemon::healMax()
{
	m_pv = m_pvMax;
}

//checkResistance
float Pokemon::resistance(Pokemon& victime, Capacite& Capacity)
{
	if (victime.getType1() == "Fire")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Ground" || Capacity.getType() == "Rock")
		{
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Fairy" || Capacity.getType() == "Fire" || Capacity.getType() == "Ice" || Capacity.getType() == "Grass" || Capacity.getType() == "Bug")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Water")
	{
		if (Capacity.getType() == "Grass" || Capacity.getType() == "Electric")
		{
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Water" || Capacity.getType() == "Fire" || Capacity.getType() == "Ice")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Grass")
	{
		if (Capacity.getType() == "Fire" || Capacity.getType() == "Poison" || Capacity.getType() == "Ice" || Capacity.getType() == "Fly" || Capacity.getType() == "Bug")
		{
			return 2;
		}
		else if (Capacity.getType() == "Grass" || Capacity.getType() == "Water" || Capacity.getType() == "Electric" || Capacity.getType() == "Ground")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Electric")
	{
		if (Capacity.getType() == "Ground")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fly" || Capacity.getType() == "Steel" || Capacity.getType() == "Electric")
			return 0.5;
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Rock")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Grass" || Capacity.getType() == "Fighting" || Capacity.getType() == "Ground" || Capacity.getType() == "Steel")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fire" || Capacity.getType() == "Normal" || Capacity.getType() == "Poison" || Capacity.getType() == "Fly")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Ground")
	{
		if (Capacity.getType() == "Water" || Capacity.getType() == "Ice" || Capacity.getType() == "Grass")
		{
			return 2;
		}
		else if (Capacity.getType() == "Poison" || Capacity.getType() == "Rock")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Eletric")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Steel")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Ground")
		{
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice" || Capacity.getType() == "Bug" || Capacity.getType() == "Normal" || Capacity.getType() == "Grass" || Capacity.getType() == "Psy" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Poison")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Steel")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Ground")
		{
			return 2;
		}
		else if (Capacity.getType() == "Steel" || Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice" || Capacity.getType() == "Bug" || Capacity.getType() == "Normal" || Capacity.getType() == "Grass" || Capacity.getType() == "Psy" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Poison")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Ice")
	{
		if (Capacity.getType() == "Steel" || Capacity.getType() == "Fighting" || Capacity.getType() == "Fire" || Capacity.getType() == "Rock")
		{
			return 2;
		}
		else if (Capacity.getType() == "Ice")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Psy")
	{
		if (Capacity.getType() == "Bug" || Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Psy")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Dark")
	{
		if (Capacity.getType() == "Fighting" || Capacity.getType() == "Fairy" || Capacity.getType() == "Bug")
		{
			return 2;
		}
		else if (Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Psy")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fairy")
	{
		if (Capacity.getType() == "Steel" || Capacity.getType() == "Poison")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Bug" || Capacity.getType() == "Dark")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Dragon")
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}
	if (victime.getType1() == "Ghost")
	{
		if (Capacity.getType() == "Ghost" || Capacity.getType() == "Dark")
		{
			return 2;
		}
		else if (Capacity.getType() == "Bug" || Capacity.getType() == "Poison")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Normal")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fighting")
	{
		if (Capacity.getType() == "Psy" || Capacity.getType() == "Fairy" || Capacity.getType() == "Fly")
		{
			return 2;
		}
		else if (Capacity.getType() == "Bug" || Capacity.getType() == "Rock" || Capacity.getType() == "Dark")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Dragon")
	{
		if (Capacity.getType() == "Dragon" || Capacity.getType() == "Fairy" || Capacity.getType() == "Ice")
		{
			return 2;
		}
		else if (Capacity.getType() == "Water" || Capacity.getType() == "Fire" || Capacity.getType() == "Grass" || Capacity.getType() == "Electric")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Bug")
	{
		if (Capacity.getType() == "Fire" || Capacity.getType() == "Rock" || Capacity.getType() == "Fly")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Grass" || Capacity.getType() == "Ground")
		{
			return 0.5;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Normal")
	{
		if (Capacity.getType() == "Fighting")
		{
			return 2;
		}
		else if (Capacity.getType() == "Ghost")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (victime.getType1() == "Fly")
	{
		if (Capacity.getType() == "Electric" || Capacity.getType() == "Ice" || Capacity.getType() == "Rock")
		{
			return 2;
		}
		else if (Capacity.getType() == "Fighting" || Capacity.getType() == "Bug" || Capacity.getType() == "Grass")
		{
			return 0.5;
		}
		else if (Capacity.getType() == "Ground")
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}