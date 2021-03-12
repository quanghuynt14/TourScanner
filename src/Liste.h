/*************************************************************************
                           Liste  -  description (Unsorted and Doubly Linked List)
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#if ! defined ( LISTE_H )
#define LISTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Maillon.h"

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Permet d'avoir une liste chainé et donc d'ajouter des trajets 
// sans limitation de taille
//------------------------------------------------------------------------

class Liste
{
//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Attributs protégés
    Maillon *premier; 
    int size;

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    Liste ( );
    // Mode d'emploi :
    // Construit une Liste vide.

    virtual ~Liste ( );
    // Mode d'emploi :
    // Détruit Liste

//----------------------------------------------------- Méthodes publiques
    void afficher (const bool tabulation ) const;
    // Mode d'emploi :
    // Prend en paramètre un booléen indiquant 
    // si il y aura une tabulation en début de ligne 


    Maillon *getPremier( ) const;
    // Mode d'emploi :
    // Renvoie le pointeur du premier maillon de la liste

    Maillon *getDernier( ) const;
    // Mode d'emploi :
    // Renvoie le pointeur du le dernier maillon de la liste

    void push ( const Trajet *unTrajet, const bool ordreAlphabet); 
    // Mode d'emploi :
    // Prend en paramètre un Trajet à ajouter dans la liste 
    // et un booléen indiquant s’il doit être rangé dans l’ordre alphabétique

    int getSize ( ) const;
    // Mode d'emploi :
    // Retourne la taille de la liste

    int getPosition ( const Maillon *unMaillon ) const;
    // Mode d'emploi :
    // Renvoie la position du maillon passé en paramètre dans la liste

    Maillon *getMaillonAPosition(const int position) const;
    // Mode d'emploi :
    // Prend en paramètre un int indiquant la position du Maillon 
    // recherchée dans la liste chaînée
    // Renvoie le maillon cherché ou nullptr
};


#endif // LISTE_H

