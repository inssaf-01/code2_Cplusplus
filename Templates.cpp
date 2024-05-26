#include<iostream>
using namespace std;
int code;
class personne
{
	protected: 
	int matricule;
	string nom;
	string prenom;
    int anne_nai;
    string profession;
	public:
		personne()
		{
			nom=" ";
			prenom=" ";
			anne_nai=0;
			code++;
			profession=" ";
        }
	personne(int m,string n,string p,int an)
	{
		matricule=m;
		nom=n;
		prenom=p;
	    anne_nai=an;
	    code++;
	}
	int get_matricule()
	{
		return matricule;
	}
	virtual void afficher()
	{
	  cout<<"Matricule : "<<matricule <<" | "<<"Nom : "<<nom<<" | ";
	  cout<<"Prenom : "<<prenom<<" | ";
	  cout<<"Annee de naissance : "<<anne_nai<<endl;
	}	
};
class etudiant : public personne
{
	protected:
		string filiere;
		float note;
		int promotion;
		
	public : 
	etudiant()
	{
		filiere=" ";
		note=0;
		promotion=2023;
		profession="etudiant";
	}
	etudiant(int m,string n,string p,int an,string f,float no,int pro):personne(m,n,p,an)
	{
		filiere=f;
		note=no;
		promotion=pro;
		profession="etudiant";
	}
	 float get_note()
	 {
	 	return note;
	 }
	 
	 
};
class prof : public personne {
	protected: 
	  string matiere ;
	  int salaire;
	public : 
	prof(int m,string n,string p,int an,string mat,int s):personne(m,n,p,an)
	{
		matiere=mat;
		salaire=s;
		profession="professeur";
		
	}
	string get_matiere()
	{
		return matiere;
	}
	
};
template <typename P>
class classe
{
	protected : 
	string n_classe;
	P* p_classe[10];
	int n;
	public:
	classe()
	{
		n=0;
	}
	void ajouter_per(P* per)
	{
		p_classe[n]=per;
		n++;
	}
	void supprimer_per(int m)
	{
		for(int i=0;i<n;i++)
		{
			if(p_classe[i]->get_matricule()==m)
				for (int j=i;j<n-1;j++)
		     	{p_classe[j]=p_classe[j+1];}
		}
	}
	
};

main()
{
	
}
