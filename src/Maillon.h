/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( ETAPE_H )
#define ETAPE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
// Elle est composée d'un pointeur sur Maillon 
// et d’un pointeur sur Trajet. C’est ce qui compose Liste.
//------------------------------------------------------------------------

class Maillon
{
//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Attributs protégés
    const Trajet *trajetActuel; 
    Maillon *suivant;

//----------------------------------------------------------------- PUBLIC
public:
//-------------------------------------------- Constructeurs - destructeur
    Maillon ( Maillon *maillonAvant, const Trajet *unTrajet, Maillon *mailllonApres );
    // Mode d'emploi :
    // Prend en paramètre deux Maillon (maillonAvant et mailllonApres) et un Trajet
    // maillonAvant pointe sur le maillon précédent dans Liste 
    // mailllonApres pointe sur le maillon suivant 

    virtual ~Maillon ( );
    // Mode d'emploi :
    // Détruit Maillon

//----------------------------------------------------- Méthodes publiques
    void afficher( ) const;
    // Mode d'emploi :
    // Affiche les caractéristiques du trajet actuel

    const Trajet *getTrajet ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur vers le trajet

    Maillon *getSuivant ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur vers le maillon suivant
 
};


#endif // ETAPE_H

