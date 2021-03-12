/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite qui sert de classe mère à TrajetSimple et TrajetCompose
//
//------------------------------------------------------------------------

class Trajet
{
//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés

    char *depart;   //ville de départ
    char *arrivee;  //ville d'arrivée

protected:
//-------------------------------------------- Constructeurs 
    Trajet(const char *Start, const char *Goal);
    // Mode d'emploi :
    // Permet d'instancier un objet de type Trajet 
    // (ici, classe abstraite donc pas possible)
    // Prend en paramètre deux pointeurs sur les chaines de caractères 
    // représentant la ville de départ(Start) et d'arrivée(Goal)

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Destructeur
    virtual ~Trajet();
    // Mode d'emploi :
    // Détruit Trajet

//----------------------------------------------------- Méthodes publiques
    virtual void afficher() const = 0; 
    // Mode d'emploi :
    // Méthode virtuel : affiche les caractéristiques (déléguation) de Trajet

    const char *getDepart() const;
    // Mode d'emploi :
    // Retourne un pointeur sur la chaine de caractères représentant 
    // la ville de départ, sans effectuer de copie en profondeur

    const char *getArrivee() const;
    // Mode d'emploi :
    // Retourne un pointeur sur la chaine de caractères représentant
    // la ville de d'arrivée, sans effectuer de copie en profondeur

    virtual const string getType() const =0;

    virtual const string enregistrer() const =0;

    virtual const char* getMoyen() const =0;
};


#endif // TRAJET_H

