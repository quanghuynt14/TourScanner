/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Liste.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Permet d'enregistrer un trajet composé de plusieurs trajets
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet 
{
//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Attributs protégés
    const Liste *etapes; // liste des trajets/escales composant le trajet

//----------------------------------------------------------------- PUBLIC
public:
//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const Liste *UneListe);
    // Mode d'emploi : 
    // Permet d'instancier un objet de type TrajetCompose
    // Prend en paramètre trois pointeurs sur les chaines de caractères 
    // représentant la ville de départ (Start), d'arrivée(Goal) 
    // et le moyen de transport(Means)


    virtual ~TrajetCompose();
    // Mode d'emploi : 
    // Détruit TrajetCompose

//----------------------------------------------------- Méthodes publiques
    void afficher() const;
    // Mode d'emploi : 
    // Affiche toutes les informations des trajets contenus dans etapes

    const string getType() const;

    const string enregistrer() const;

    const char* getMoyen() const;
};


#endif // TRAJET_COMPOSE_H

