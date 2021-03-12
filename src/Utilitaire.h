/*************************************************************************
                           Utilitaire  -  description
                             -------------------
    d�but                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Utilitaire> (fichier Utilitaire.h) ----------
#if ! defined ( UTILITAIRE_H )
#define UTILITAIRE_H

//------------------------------------------------------------------------
// R�le de la classe <Utilitaire>
// Classe qui regroupe des fonctions g�n�rales utilies pour d'autres classes
//
//------------------------------------------------------------------------

class Utilitaire
{

//----------------------------------------------------------------- PUBLIC
public:

    static void afficherMenuPrincipal();
    static void afficherMenuLoadSave();
    static void afficherChoixInvalide(const int borneInf, const int borneSup);
    static inline bool exists_file (const std::string& name);

//----------------------------------------------------- M�thodes publiques

};


#endif // UTILITAIRE_H

