/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------------------------------- Include système
#include "Trajet.h"
#include "TrajetCompose.h"
#include "Liste.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const Liste *UneListe) : 
        Trajet(UneListe->getPremier()->getTrajet()->getDepart(), 
               UneListe->getDernier()->getTrajet()->getArrivee())
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    etapes = UneListe;

} //----- Fin de TrajetCompose (constructeur)

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    //if (etapes->getPremier() != nullptr) {   
	    delete etapes;
        //etapes = nullptr;
    //}
} //----- Fin de ~TrajetCompose (destructeur)

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::afficher() const
{
    cout << "Multi-city travel. " 
         << "From : " << etapes->getPremier()->getTrajet()->getDepart() 
         << "     "
         << "To : " << etapes->getDernier()->getTrajet()->getArrivee() 
         << endl;

    etapes->afficher(true);
} //----- Fin de Afficher

const string TrajetCompose::getType() const 
{
    return "TrajetCompose";
}

const string TrajetCompose::enregistrer() const
{
    string c = to_string(etapes->getSize()) + ','; 
    c = c + etapes->getPremier()->getTrajet()->getDepart() + ',';
    c = c + etapes->getDernier()->getTrajet()->getArrivee() + ',';
    c = c + etapes->getDernier()->getTrajet()->getMoyen() + ',';
    Maillon *x = etapes->getPremier()->getSuivant();
    while(x != nullptr) {
        c = c + x->getTrajet()->getDepart()+ ',' ;
        c = c + x->getTrajet()->getMoyen();
        if (x->getSuivant() != nullptr) {
            c = c + ',';
        }
        x = x->getSuivant();
    }

    //c = c + ';';
    return c;

    //ajouter trajet -> 2 -> from -> next -> by -> to -> by
    // ajouter trajet -> 2 -> from -> to -> by -> next -> by -> next -> by;
}

const char* TrajetCompose::getMoyen() const {
    return nullptr;
}
