/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char *Start, const char *Goal,
                           const char *Means) : Trajet(Start, Goal)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    moyen = new char[strlen(Means) + 1];
    strcpy(moyen, Means);
} //----- Fin de TrajetSimple (constructeur)

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    if (moyen != nullptr) {
	    delete [] moyen;
        moyen = nullptr;
    }
} //----- Fin de ~TrajetSimple (destructeur)

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::afficher() const
{
    cout << "From " << getDepart() 
         << " to " << getArrivee() 
         << " by " << moyen << " " << endl;
} //----- Fin de Afficher


const string TrajetSimple::getType() const 
{
    return "TrajetSimple";
}

const char* TrajetSimple::getMoyen() const
{
    return moyen;
}

const string TrajetSimple::enregistrer() const
{

    string c = "1,";
    c = c + getDepart() + ',' + getArrivee() + ',' + moyen;
    return c;
}
