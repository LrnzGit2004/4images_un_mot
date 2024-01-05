#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//Fonction qui vérifie si un mot correspond aux lettres données
bool lettersCorrespond(const string& mot, const string& lettres)
{
    string templettres = lettres;
    for (char lettre : mot)
    {
        size_t trouve = templettres.find(lettre);
        if (trouve != string::npos)
        {
            templettres.erase(trouve, 1);
        }
        else
        {
            return false;
        }
    }
    return true;
}

//fonction qui trouve les mots correspondants aux lettres sans le dictionnaire et à une certaine longueur
vector<string> trouveMots(const string& lettres, const vector<string>& dicos, int longeur)
{
    vector<string> motsCorrespondants;
    for (const string& mot : dicos)
    {
        if (mot.length() == longeur && lettersCorrespond(mot, lettres))
        {
            motsCorrespondants.push_back(mot);
        }
    }
    return motsCorrespondants;
}

//corps du programme
int main ()
{
    ifstream fichierDicos("liste_francais.txt");

    if(!fichierDicos)
    {
        cout<<"Erreur lors de l'ouverture du fichier du dictionnaire"<<endl;
        return 1;
    }

    vector<string> dicos;
    string mot;
    while(getline(fichierDicos, mot))
    {
        dicos.push_back(mot);
    }

    string lettres;
    cout<<"Entrez les lettres disponibles : ";
    cin>> lettres;

    int longeur;
    cout<<"Entrez la longeur du mot souhaité : ";
    cin>>longeur;

    vector<string> motsTrouves = trouveMots(lettres, dicos, longeur);

    cout<<"Mots correspondants : "<<endl;
    for (const string& motsTrouves : motsTrouves)
    {
        cout<<motsTrouves<<endl;
    }
    return 0;
}