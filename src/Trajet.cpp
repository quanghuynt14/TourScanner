/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ---------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------------ PRIVE

//-------------------------------------------- Constructeurs 
Trajet::Trajet (const char *Start, const char *Goal)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
	depart = new char[strlen(Start) + 1];
	strcpy(depart, Start);
	arrivee = new char[strlen(Goal) + 1];
	strcpy(arrivee, Goal);
} //----- Fin de Trajet (constructeur)

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------- Destructeur
Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	if (depart != nullptr) {
		delete [] depart;
		depart = nullptr;
	}
	if (arrivee != nullptr) {
		delete [] arrivee;
		arrivee = nullptr;
	}
} //----- Fin de ~Trajet (destructeur)


//----------------------------------------------------- Méthodes publiques
const char *Trajet::getDepart() const
{
	return depart;
} // ----- Fin de getDepart

const char *Trajet::getArrivee() const
{
	return arrivee;
} // ----- Fin de getArrivee





