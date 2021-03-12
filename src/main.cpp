#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Maillon.h"
#include "Liste.h"
#include "Utilitaire.h"

void ajouterUnTrajet(Catalogue &UnCatalogue);

inline bool exists_file(const std::string &name)
{
	ifstream f(name.c_str());
	return f.good();
}

string& leftTrim(string& str, string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

string& rightTrim(string& str, string& chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

string& trimString(string& str, string& chars)
{
    return leftTrim(rightTrim(str, chars), chars);
}

bool check_number(string s) 
{
	string chars_to_trim = " \t";
	trimString(s, chars_to_trim);
	if (s.size() == 0) 
		return false;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}
	return true;
}

int main()
{
  cout << "Tour Scanner" << endl;
	Catalogue catalogue;

	string file;
	char villeDepart[64] = {};
	char villeArrivee[64] = {};
	int option, option2;
	bool fin = false;
	string input;

	while (!fin)
	{
		Utilitaire::afficherMenuPrincipal();
		getline(cin, input);
		while (input.size() == 0) getline(cin, input);
		if (check_number(input))
		{
			option = stoi(input);
			switch (option)
			{
			case 0:
				cout << "Name of backup file : france.csv" << endl;

				file = "france.csv";

				if (!exists_file(file))
				{
					cout << "File doesn't exist." << endl;
					break;
				}
				Utilitaire::afficherMenuLoadSave();

				getline(cin, input);
				while (input.size() == 0) getline(cin, input);
				if (check_number(input))
				{
					option2 = stoi(input);
					if (option2 >= 0 && option2 < 3)
					{
						catalogue.charger(option2, file);
					}
					else if (option2 == 3 || option2 == 4)
					{
						cout << "Name of the City : ";
						cin >> villeDepart;
						cout << villeDepart << endl;
						catalogue.charger(option2, file, villeDepart);
					}
					else if (option2 == 5)
					{
						cout << "Name of Departure City : ";
						cin >> villeDepart;
						cout << "Name of Arrival City : ";
						cin >> villeArrivee;
						catalogue.charger(option2, file, villeDepart, villeArrivee);
					}
					else
					{
						Utilitaire::afficherChoixInvalide(0, 5);
					}
				}

				break;
			case 1:
				ajouterUnTrajet(catalogue);
				break;
			case 2:
				catalogue.afficher();
				break;
			case 3:
				cout << "From : ";
				cin >> villeDepart;
				cout << "To : ";
				cin >> villeArrivee;

				catalogue.rechercheSimple(villeDepart, villeArrivee);

				break;
			case 4:
				cout << "From : ";
				cin >> villeDepart;
				cout << "To : ";
				cin >> villeArrivee;

				catalogue.rechercheAvancee(villeDepart, villeArrivee);

				break;
			case 5:
				cout << "Name of backup file : " << endl;
				cin >> file;
				Utilitaire::afficherMenuLoadSave();
        getline(cin, input);
				getline(cin, input);
				if (check_number(input))
				{
					option2 = stoi(input);
					if (option2 >= 0 && option2 < 3)
					{
						catalogue.enregistrer(option2, file);
					}
					else if (option2 == 3 || option2 == 4)
					{
						cout << "Name of the City : ";
						cin >> villeDepart;
						catalogue.enregistrer(option2, file, villeDepart);
					}
					else if (option2 == 5)
					{
						cout << "Name of Departure City : ";
						cin >> villeDepart;
						cout << "Name of Arrival City : ";
						cin >> villeArrivee;
						catalogue.enregistrer(option2, file, villeDepart, villeArrivee);
					}
					else
					{
						Utilitaire::afficherChoixInvalide(0, 5);
					}
				} else {
					cout << "This is not a number." << endl;
				}
				break;
			case 6:
				fin = true;
				break;
			default:
				Utilitaire::afficherChoixInvalide(0, 6);
				break;
			}
		}
		else
		{
			cout << "This is not a number." << endl;
		}
		cout << endl;
	}
	return 0;
}

void ajouterUnTrajet(Catalogue &UnCatalogue)
{
	cout << "Enter the number of steps on the route, "
		 << "1 if it's a direct route : ";
	int N;

	string input;
	getline(cin, input);
	if (check_number(input))
	{
		N = stoi(input);
		if (N <= 0) {
			cout << "This is not a positive number." << endl;
			return;
		}
		char villeDepart[64] = {};
		char villeSuivant[64] = {};
		char transport[64] = {};

		cout << "From : ";
		cin >> villeDepart;

		if (N == 1)
		{
			cout << "To : ";
			cin >> villeSuivant;

			cout << "By : ";
			cin >> transport;

			const TrajetSimple *unTrajetSimple =
				new TrajetSimple(villeDepart, villeSuivant, transport);

			UnCatalogue.ajouterTrajet(unTrajetSimple);
		}
		else
		{
			Liste *ListeDeTrajets = new Liste;

			for (int i = 1; i <= N; i++)
			{
				if (i < N)
				{
					cout << "Next : ";
				}
				else
				{
					cout << "To : ";
				}
				cin >> villeSuivant;

				cout << "By : ";
				cin >> transport;

				const TrajetSimple *trajet_simple =
					new TrajetSimple(villeDepart, villeSuivant, transport);

				ListeDeTrajets->push(trajet_simple, 0);

				strcpy(villeDepart, villeSuivant);
			}

			const TrajetCompose *unTrajetCompose =
				new TrajetCompose(ListeDeTrajets);

			UnCatalogue.ajouterTrajet(unTrajetCompose);
		}
	}
	else
	{
		cout << "This is not a number." << endl;
	}
}
