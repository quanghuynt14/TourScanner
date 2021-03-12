/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Maillon.h"
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Maillon::Maillon ( Maillon *maillonAvant, const Trajet *unTrajet, Maillon *mailllonApres ) : 
    trajetActuel(unTrajet), suivant(mailllonApres)
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
    if (maillonAvant != nullptr) {
        maillonAvant->suivant = this;
    }
} //----- Fin de Maillon


Maillon::~Maillon ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
    if (trajetActuel != nullptr) {
        delete trajetActuel;
        trajetActuel = nullptr;
    }
} //----- Fin de ~Maillon


//----------------------------------------------------- Méthodes publiques

void Maillon::afficher () const
{
	trajetActuel->afficher();
}

const Trajet *Maillon::getTrajet() const 
{
    return trajetActuel;
}

Maillon *Maillon::getSuivant() const
{
    return suivant;
}






