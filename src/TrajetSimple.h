/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//--- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -----
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Hérite de Trajet, sert à enregistrer un trajet direct d'une ville A
// à une ville B avec un moyen de transport C
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    char *moyen;   // moyen de transport

//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char *Start, const char *Goal, const char *Means);
    // Mode d'emploi :
    // Permet d'instancier un objet de type TrajetSimple 
    // Prend en paramètre trois pointeurs sur les chaines de caractères 
    // représentant la ville de départ (Start), d'arrivée(Goal) 
    // et le moyen de transport(Means)


    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Détruit TrajetSimple

//----------------------------------------------------- Méthodes publiques
    void afficher() const;
    // Mode d'emploi :
    // affiche les caractéristiques de TrajetSimple
    // spécialisation de la méthode Afficher de Trajet
    
    const string getType() const;

    const char* getMoyen() const;

    const string enregistrer() const;
};


#endif // TRAJET_SIMPLE_H

