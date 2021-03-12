/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    trajets = new Liste;
} //----- Fin de Catalogue (constructeur)

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete trajets;
} //----- Fin de ~Catalogue (destructeur)

//----------------------------------------------------- Méthodes publiques
void Catalogue::afficher() const
{
    trajets->afficher(false);
}

void Catalogue::ajouterTrajet(const Trajet *unTrajet)
{
    trajets->push(unTrajet, 1);
    cout << "Ajout réussi dans le catalogue du trajet : " << endl;
    unTrajet->afficher();
}

void Catalogue::rechercheSimple(const char *Start, const char *Goal) const
{
    int nombreParcours = 0;
    const Maillon *x = trajets->getPremier();
    while (x != nullptr)
    {

        if (strcmp(x->getTrajet()->getDepart(), Start) == 0 &&
            strcmp(x->getTrajet()->getArrivee(), Goal) == 0)
        {

            nombreParcours++;
            cout << "Parcours " << nombreParcours << " : " << endl;
            x->afficher();
        }
        x = x->getSuivant();
    }
    cout << "Nombre total de parcours possibles : " << nombreParcours << endl;
}

void Catalogue::rechercheAvancee(const char *Start, const char *Goal) const
{
    int nombreParcours = 0;
    const Maillon *x = trajets->getPremier();
    
    while (x != nullptr)
    {

        if (strcmp(x->getTrajet()->getDepart(), Start) == 0)
        {

            bool *visited = new bool[trajets->getSize()];
            for (int i = 0; i < trajets->getSize(); i++)
                visited[i] = 0;
            visited[trajets->getPosition(x)] = 1;

            int *A = new int[trajets->getSize()];
            for (int i = 0; i < trajets->getSize(); i++)
                A[i] = 0;

            int N = 0;
            A[N] = trajets->getPosition(x);

            DFS(x->getTrajet(), visited, Goal, A, N, nombreParcours);

            delete[] visited;
            delete[] A;
        }
        x = x->getSuivant();
    }
    cout << "Nombre total de parcours possibles : " << nombreParcours << endl;

}

void Catalogue::DFS(const Trajet *x, bool *v, const char *Goal,
                    int *Chemin, int &N, int &nbParcours) const
{
    if (strcmp(x->getArrivee(), Goal) == 0)
    {
        nbParcours++;
        cout << "#Parcours " << nbParcours << " : " << endl;
        for (int i = 0; i < N; i++)
        {
            cout << i + 1 << " : ";
            trajets->getMaillonAPosition(Chemin[i])->afficher();
        }
        cout << N + 1 << " : ";
        x->afficher();
    }
    else
    {
        const Maillon *y = trajets->getPremier();

        while (y != nullptr)
        {
            bool ok = true;
            for (int i = 0; i < N; i++) {
              if (strcmp(trajets->getMaillonAPosition(Chemin[i])->getTrajet()->getDepart(), y->getTrajet()->getDepart()) == 0 || strcmp(trajets->getMaillonAPosition(Chemin[i])->getTrajet()->getDepart(), y->getTrajet()->getArrivee()) == 0 || strcmp(trajets->getMaillonAPosition(Chemin[i])->getTrajet()->getArrivee(), y->getTrajet()->getArrivee()) == 0) {
                ok = false;
                break;
              }
            }
            if (ok && strcmp(x->getArrivee(), y->getTrajet()->getDepart()) == 0 &&
                v[trajets->getPosition(y)] == false)
            {

                v[trajets->getPosition(y)] = true;
                N++;
                Chemin[N] = trajets->getPosition(y);

                DFS(y->getTrajet(), v, Goal, Chemin, N, nbParcours);

                v[trajets->getPosition(y)] = false;
                N--;
            }

            y = y->getSuivant();
        }
    }
}

void Catalogue::enregistrer(int Option, const string NomFichier, const char *villeA, const char *villeB) const
{
    ofstream writeFile;
    try
    {
        writeFile.open(NomFichier);
    }
    catch (ofstream::failure &writeErr)
    {
        cerr << "Exception occured when writing to a file" << endl
             << writeErr.what() << endl;
        return;
    }
    Maillon *x = trajets->getPremier();
    
    switch (Option)
    {
    case 0:
    {

        while (x != nullptr)
        {
            writeFile << x->getTrajet()->enregistrer() << endl;
            x = x->getSuivant();
        }
        break;
    }
    case 1:

        while (x != nullptr)
        {
            if (x->getTrajet()->getType() == "TrajetSimple")
            {
                writeFile << x->getTrajet()->enregistrer() << endl;
            }
            x = x->getSuivant();
        }
        break;
    case 2:

        while (x != nullptr)
        {
            if (x->getTrajet()->getType() == "TrajetCompose")
            {
                writeFile << x->getTrajet()->enregistrer() << endl;
            }
            x = x->getSuivant();
        }
        break;
    case 3:

        while (x != nullptr)
        {
            if (strcmp(x->getTrajet()->getDepart(), villeA) == 0)
            {
                writeFile << x->getTrajet()->enregistrer() << endl;
            }
            x = x->getSuivant();
        }
        break;
    case 4:

        while (x != nullptr)
        {
            if (strcmp(x->getTrajet()->getArrivee(), villeA) == 0)
            {
                writeFile << x->getTrajet()->enregistrer() << endl;
            }
            x = x->getSuivant();
        }
        break;
    case 5:

        while (x != nullptr)
        {
            if (strcmp(x->getTrajet()->getDepart(), villeA) == 0 &&
                strcmp(x->getTrajet()->getArrivee(), villeB) == 0)
            {
                writeFile << x->getTrajet()->enregistrer() << endl;
            }
            x = x->getSuivant();
        }
        break;
    default:
        break;
    }

    cout << "Le fichier est chargé." <<endl;
    writeFile.close();
}

bool check_string(const string s) {
    if (s.empty()) {
        cout << "Les données ne sont pas valides." << endl;
        return false;
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
            cout << "Les données ne sont pas valides." << endl;
            return false;
        }
    }
    return true;
}

void Catalogue::charger(int Option, const string NomFichier, const char *villeA, const char *villeB)
{
    ifstream readFile;
    try
    {
        readFile.open(NomFichier);
    }
    catch (ifstream::failure &readErr)
    {
        cerr << "Exception occured when open the file" << endl
             << readErr.what() << endl;
        return;
    }
    string line;
    int t;

    switch (Option)
    {
    case 0:
        while (getline(readFile, line))
        {
            stringstream ss(line); 
            ss >> t;

            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t == 1)
            {
                string start, goal, moyen;
                getline(ss, start, ','); ok &= check_string(start); 
                getline(ss, goal, ',');  ok &= check_string(goal); 
                getline(ss, moyen, ','); ok &= check_string(moyen); 
                
                if (ok) {
                    TrajetSimple *newTS = new TrajetSimple(start.c_str(), goal.c_str(), moyen.c_str());
                    ajouterTrajet(newTS);
                } 
            }
            else
            {
                Liste *newListe = new Liste;
                string start, goal, moyenGoal;
                getline(ss, start, ',');           ok &= check_string(start); 
                getline(ss, goal, ',');            ok &= check_string(goal); 
                getline(ss, moyenGoal, ',');       ok &= check_string(moyenGoal); 
                for (int i = 0; i < t - 1; i++)
                {
                    string next, moyenNext;
                    getline(ss, next, ',');        ok &= check_string(next); 
                    getline(ss, moyenNext, ',');   ok &= check_string(moyenNext); 
                    TrajetSimple *nextTS = new TrajetSimple(start.c_str(), next.c_str(), moyenNext.c_str());
                    newListe->push(nextTS, 0);
                    start = next;
                }
                
                if (ok) {
                    TrajetSimple *endTS = new TrajetSimple(start.c_str(), goal.c_str(), moyenGoal.c_str());
                    newListe->push(endTS, 0);
                    TrajetCompose *newTC = new TrajetCompose(newListe);
                    ajouterTrajet(newTC);
                } else {
                    delete newListe;
                }
                
            }
        }
        break;
    case 1:
        while (getline(readFile, line))
        {
            stringstream ss(line);
            ss >> t;
            
            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t == 1)
            {
                string start, goal, moyen;
                getline(ss, start, ',');    ok &= check_string(start); 
                getline(ss, goal, ',');     ok &= check_string(goal);   
                getline(ss, moyen, ',');    ok &= check_string(moyen); 

                if (ok) {
                    TrajetSimple *newTS = new TrajetSimple(start.c_str(), goal.c_str(), moyen.c_str());
                    ajouterTrajet(newTS);
                }
            }
        }
        break;
    case 2:
        while (getline(readFile, line))
        {
            stringstream ss(line);
            ss >> t;

            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t > 1)
            {
                Liste *newListe = new Liste;
                string start, goal, moyenGoal;
                getline(ss, start, ',');           ok &= check_string(start);
                getline(ss, goal, ',');            ok &= check_string(goal);
                getline(ss, moyenGoal, ',');       ok &= check_string(moyenGoal);
                for (int i = 0; i < t - 1; i++)
                {
                    string next, moyenNext;
                    getline(ss, next, ',');        ok &= check_string(next);
                    getline(ss, moyenNext, ',');   ok &= check_string(moyenNext);
                    TrajetSimple *nextTS = new TrajetSimple(start.c_str(), next.c_str(), moyenNext.c_str());
                    newListe->push(nextTS, 0);
                    start = next;
                }
                
                if (ok) {
                    TrajetSimple *endTS = new TrajetSimple(start.c_str(), goal.c_str(), moyenGoal.c_str());
                    newListe->push(endTS, 0);
                    TrajetCompose *newTC = new TrajetCompose(newListe);
                    ajouterTrajet(newTC);
                } else {
                    delete newListe;
                }
            }
        }
        break;
    case 3:
        while (getline(readFile, line))
        {
            stringstream ss(line);
            ss >> t;
            
            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t == 1)
            {
                string start, goal, moyen;
                getline(ss, start, ',');           ok &= check_string(start);

                if (strcmp(villeA, start.c_str()) == 0)
                {
                    getline(ss, goal, ',');        ok &= check_string(goal);
                    getline(ss, moyen, ',');       ok &= check_string(moyen);

                    if (ok) {
                        TrajetSimple *newTS = new TrajetSimple(start.c_str(), goal.c_str(), moyen.c_str());
                        ajouterTrajet(newTS);
                    }
                }
            }
            else
            {
                Liste *newListe = new Liste;
                string start, goal, moyenGoal;
                getline(ss, start, ',');                ok &= check_string(start); 
                if (strcmp(villeA, start.c_str()) == 0)
                {
                    getline(ss, goal, ',');             ok &= check_string(goal);
                    getline(ss, moyenGoal, ',');        ok &= check_string(moyenGoal);
                    for (int i = 0; i < t - 1; i++)
                    {
                        string next, moyenNext;
                        getline(ss, next, ',');         ok &= check_string(next);
                        getline(ss, moyenNext, ',');    ok &= check_string(moyenNext);
                        TrajetSimple *nextTS = new TrajetSimple(start.c_str(), next.c_str(), moyenNext.c_str());
                        newListe->push(nextTS, 0);
                        start = next;
                    }

                    if (ok) {
                        TrajetSimple *endTS = new TrajetSimple(start.c_str(), goal.c_str(), moyenGoal.c_str());
                        newListe->push(endTS, 0);
                        TrajetCompose *newTC = new TrajetCompose(newListe);
                        ajouterTrajet(newTC);
                    } else {
                        delete newListe;
                    }
                }
            }
        }
        break;
    case 4:
        while (getline(readFile, line))
        {
            stringstream ss(line);
            ss >> t;

            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t == 1)
            {
                string start, goal, moyen;
                getline(ss, start, ',');               ok &= check_string(start);

                getline(ss, goal, ',');                ok &= check_string(goal);
                if (strcmp(villeA, goal.c_str()) == 0)
                {
                    getline(ss, moyen, ',');           ok &= check_string(moyen);

                    if (ok) {
                        TrajetSimple *newTS = new TrajetSimple(start.c_str(), goal.c_str(), moyen.c_str());
                        ajouterTrajet(newTS);
                    }
                }
            }
            else
            {
                Liste *newListe = new Liste;
                string start, goal, moyenGoal;
                getline(ss, start, ',');           ok &= check_string(start);

                getline(ss, goal, ',');            ok &= check_string(goal);
                if (strcmp(villeA, goal.c_str()) == 0)
                {
                    getline(ss, moyenGoal, ',');   ok &= check_string(moyenGoal);
                    for (int i = 0; i < t - 1; i++)
                    {
                        string next, moyenNext;
                        getline(ss, next, ',');        ok &= check_string(next);
                        getline(ss, moyenNext, ',');   ok &= check_string(moyenNext);
                        TrajetSimple *nextTS = new TrajetSimple(start.c_str(), next.c_str(), moyenNext.c_str());
                        newListe->push(nextTS, 0);
                        start = next;
                    }

                    if (ok) {
                        TrajetSimple *endTS = new TrajetSimple(start.c_str(), goal.c_str(), moyenGoal.c_str());
                        newListe->push(endTS, 0);
                        TrajetCompose *newTC = new TrajetCompose(newListe);
                        ajouterTrajet(newTC);
                    } else {
                        delete newListe;
                    }
                }
            }
        }
        break;
    case 5:
        while (getline(readFile, line))
        {
            stringstream ss(line);
            ss >> t;
            
            bool ok = true;
            if (ss.peek() == ',') 
                ss.ignore();
            else 
                t = 0;
            
            if (t == 0) {
                cout << "Pas valide" << endl;
            }
            else if (t == 1)
            {
                string start, goal, moyen;
                getline(ss, start, ',');          ok &= check_string(start);

                if (strcmp(villeA, start.c_str()) == 0)
                {
                    getline(ss, goal, ',');       ok &= check_string(goal);
                    if (strcmp(villeB, goal.c_str()) == 0)
                    {
                        getline(ss, moyen, ',');  ok &= check_string(moyen);

                        if (ok) {
                            TrajetSimple *newTS = new TrajetSimple(start.c_str(), goal.c_str(), moyen.c_str());
                            ajouterTrajet(newTS);
                        }
                    }
                }
            }
            else
            {
                Liste *newListe = new Liste;
                string start, goal, moyenGoal;
                getline(ss, start, ',');              ok &= check_string(start);
                if (strcmp(villeA, start.c_str()) == 0)
                {
                    getline(ss, goal, ',');           ok &= check_string(goal);
                    if (strcmp(villeB, goal.c_str()) == 0)
                    {
                        getline(ss, moyenGoal, ',');  ok &= check_string(moyenGoal);
                        for (int i = 0; i < t - 1; i++)
                        {
                            string next, moyenNext;
                            getline(ss, next, ',');         ok &= check_string(next);
                            getline(ss, moyenNext, ',');    ok &= check_string(moyenNext);
                            TrajetSimple *nextTS = new TrajetSimple(start.c_str(), next.c_str(), moyenNext.c_str());
                            newListe->push(nextTS, 0);
                            start = next;
                        }

                        if (ok) {
                            TrajetSimple *endTS = new TrajetSimple(start.c_str(), goal.c_str(), moyenGoal.c_str());
                            newListe->push(endTS, 0);
                            TrajetCompose *newTC = new TrajetCompose(newListe);
                            ajouterTrajet(newTC);
                        } else {
                            delete newListe;
                        }
                    }
                }
            }
        }
        break;
    default:
        break;
    }
    cout << "Le fichier est chargé." <<endl;
    readFile.close();
}




