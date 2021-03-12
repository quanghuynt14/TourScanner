/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Liste.h"
#include "Maillon.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Liste::Liste() : premier(nullptr), size(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
}

Liste::~Liste()
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
    Maillon *x = premier;
    while(x != nullptr)
    {
        Maillon *suivante = x->getSuivant();
        delete x;
        x = suivante;
    }
} 


//----------------------------------------------------- Méthodes publiques
void Liste::afficher(const bool tabulation) const
{
	const Maillon *x = premier;
    if (x == nullptr) {
        cout << "There is nothing in the list."<<endl;
    } else {
        int i = 1;
        while (x != nullptr) {
            if (tabulation == true) {
                cout << "     ";
            }
            cout << i << " : ";
            x->afficher();
            x = x->getSuivant();
            i++;
        }
    }
} //----- Fin de Afficher

// Add unTrajet to the end of the list
// Par défaut, ajouter non ordre
void Liste::push(const Trajet *unTrajet, const bool ordreAlphabet)
{
    if (premier == nullptr) {
        premier = new Maillon(premier, unTrajet, nullptr);
        ++size;
    } else if (ordreAlphabet == true) {
        Maillon *x = premier;
        Maillon *precedent = nullptr;
        while (x != nullptr && (strcmp(x->getTrajet()->getDepart(), unTrajet->getDepart()) < 0
                || (strcmp(x->getTrajet()->getDepart(), unTrajet->getDepart()) == 0
                    && strcmp(x->getTrajet()->getArrivee(), unTrajet->getArrivee()) < 0))) {
            precedent = x;
            x = x->getSuivant();
        }

        if (x == nullptr) {
            new Maillon(getDernier(), unTrajet, nullptr);
        } else if (precedent == nullptr) {
            premier = new Maillon(precedent, unTrajet, x);
        } else {
            new Maillon(precedent, unTrajet, x);
        }
        ++size;
    } else {
        if (strcmp(getDernier()->getTrajet()->getArrivee(), unTrajet->getDepart()) == 0) {
            new Maillon(getDernier(), unTrajet, nullptr);
            ++size;
        } else {
            cout << "Trajet pas valide!" << endl;
        }
    }
} //----- Fin de PushBack



Maillon *Liste::getPremier() const 
{
    return premier;
} //----- Fin de getPremiere

Maillon *Liste::getDernier( ) const
{
    Maillon *x = premier;
    while (x->getSuivant() != nullptr) {
        x = x->getSuivant();
    }
    return x;
}

int Liste::getSize() const 
{
    return size;
} //----- Fin de getSize

int Liste::getPosition(const Maillon *uneMaillon) const 
{
    int pos = 0;
    const Maillon *x = premier;

    while (x != uneMaillon) {
        pos++;
        if (x != NULL) {
            x = x->getSuivant();
        }
    }

    if (x == nullptr) {
        return -1;
    } else {
        return pos;
    }
} //----- Fin de getPosition

Maillon *Liste::getMaillonAPosition(const int position) const 
{
    int h = 0;
    if (premier == nullptr)
        return premier;
    Maillon *x = premier;
    while (h != position && x != nullptr) {
        h++;
        x = x->getSuivant();
    }

    return x;
} //----- Fin de getMaillonAPosition


