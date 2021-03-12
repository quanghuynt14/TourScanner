/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe stocke tous les trajets crées dans une Liste 
// et permet à l’utilisateur de les manipuler
//------------------------------------------------------------------------

class Catalogue
{
//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Attributs protégés
    Liste *trajets;

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeur - Destructeur
    Catalogue();
    // Mode d'emploi :
    // Constructeur de Catalogue

    virtual ~Catalogue();
    // Mode d'emploi :
    // Destructeur de Catalogue 

//----------------------------------------------------- Méthodes publiques
    void afficher() const;
    // Mode d'emploi :
    // affiche tous les trajets présents dans trajets

    void ajouterTrajet(const Trajet *UnTrajet);
    // Mode d'emploi :
    // Prend en paramètre un pointeur sur un Trajet et l'ajoute dans trajets

    void rechercheSimple(const char *Start, const char *Goal) const;
    // Mode d'emploi :
    // Prend en paramètre deux pointeurs de char (Start et Goal) pour chercher
    // les trajets correspondants sans escales dans Catalogue

    void rechercheAvancee(const char *Start, const char *Goal) const;
    // Mode d'emploi :
    // Prend en paramètre deux pointeurs de char (Start et Goal) pour chercher
    // les trajets correspondants avec ou sans escales dans Catalogue

    void DFS(const Trajet *x, bool *v, const char *Goal, 
             int *Chemin, int &N, int &nbParcours) const;
    // Mode d'emploi :
    //

    void enregistrer(int Option, const string NomFichier, const char *villeA = nullptr, const char *villeB = nullptr) const;

    void charger(int Option, const string NomFichier, const char *villeA = nullptr, const char *villeB = nullptr);

};


#endif // CATALOGUE_H

