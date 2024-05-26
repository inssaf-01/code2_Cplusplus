#include <iostream>
#include <string>
using namespace std;

int code = 0; // Initialisation de la variable code

class personne
{
protected:
    int matricule;
    string nom;
    string prenom;
    int annee_naissance;
    string profession;

public:
    personne()
    {
        nom = " ";
        prenom = " ";
        annee_naissance = 0;
        code++; // Incrémentation de la variable code
        profession = " ";
    }
    personne(int m, string n, string p, int an)
    {
        matricule = m;
        nom = n;
        prenom = p;
        annee_naissance = an;
        code++; // Incrémentation de la variable code
    }
    int get_matricule()
    {
        return matricule;
    }
    virtual void afficher()
    {
        cout << "Matricule : " << matricule << " | "
             << "Nom : " << nom << " | "
             << "Prenom : " << prenom << " | "
             << "Annee de naissance : " << annee_naissance << endl;
    }
};

class etudiant : public personne
{
protected:
    string filiere;
    float note;
    int promotion;

public:
    etudiant()
    {
        filiere = " ";
        note = 0;
        promotion = 2023;
        profession = "etudiant"; // Initialisation de la profession
    }
    etudiant(int m, string n, string p, int an, string f, float no, int pro) : personne(m, n, p, an)
    {
        filiere = f;
        note = no;
        promotion = pro;
        profession = "etudiant"; // Initialisation de la profession
    }
    float get_note()
    {
        return note;
    }
    void afficher() override
    {
        personne::afficher();
        cout << "Filiere : " << filiere << " | "
             << "Note : " << note << " | "
             << "Promotion : " << promotion << endl;
    }
};

class prof : public personne
{
protected:
    string matiere;
    int salaire;

public:
    prof(int m, string n, string p, int an, string mat, int s) : personne(m, n, p, an)
    {
        matiere = mat;
        salaire = s;
        profession = "professeur"; // Initialisation de la profession
    }
    string get_matiere()
    {
        return matiere;
    }
    void afficher() override
    {
        personne::afficher();
        cout << "Matiere : " << matiere << " | "
             << "Salaire : " << salaire << endl;
    }
};

template <typename P>
class classe
{
protected:
    string n_classe;
    P *p_classe[50]; // Tableau pour stocker les personnes
    int n;

public:
    classe()
    {
        n = 0;
    }
    void ajouter_per(P *per)
    {
        if (n < 50) // Vérification pour éviter le dépassement de tableau
        {
            p_classe[n] = per;
            n++;
        }
        else
        {
            cout << "La classe est pleine." << endl;
        }
    }
    void afficher_personnes()
    {
        for (int i = 0; i < n; ++i)
        {
            p_classe[i]->afficher();
        }
    }
};

int main()
{
    // Création d'instances de la classe etudiant et prof
    etudiant etud1(101, "AN", "Lina", 2000, "Computer Science", 85.5, 2023);
    prof prof1(201, "La", "Souad", 1980, "Mathematics", 5000);

    // Création d'une instance de la classe classe
    classe<personne> myClass;

    // Ajout des instances à la classe
    myClass.ajouter_per(&etud1);
    myClass.ajouter_per(&prof1);

    // Affichage des informations sur les personnes dans la classe
    myClass.afficher_personnes();

    return 0;
}
