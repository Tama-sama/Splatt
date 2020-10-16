#include "SI_Manager.h"
#include "SI_Collision.h"
#include "SI_Joueur.h"
#include "SI_Ennemi.h"
#include "SI_Tir.h"

vector <SI_Joueur> V_joueur;
vector <SI_Ennemi> EnnemyList;

void SI_Update()
{
	static bool Load = false;
	if (!Load)
	{
		Color Couleur;
		for (int i = 0; i < Nombre_Joueur; i++)
		{
			if (i == 0)
				Couleur = Color::Red;
			if (i == 1)
				Couleur = Color::Blue;

			V_joueur.push_back(SI_Joueur(Vector2f(((1920 / (Nombre_Joueur + 1)) * (i + 1)), 1080 - 105), i + 1, Couleur));
		}
		
		App_Ennemis(10, 4, 2, 4);

		Load = true;
	}


	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		Collision();
		Suppression();

		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullUpdate(Actual_Joueur);

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullUpdate(Actual_Ennemy);

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Update();
	}
	else if (Etat == State_SI::Menu)
	{

	}
}

void SI_Display()
{
	if (Etat == State_SI::Niveau1 || Etat == State_SI::Niveau2 || Etat == State_SI::Niveau3)
	{
		for (SI_Joueur& Actual_Joueur : V_joueur)
			FullDraw_Perso(Actual_Joueur);

		for (SI_Ennemi& Actual_Ennemy : EnnemyList)
			FullDraw_Perso(Actual_Ennemy);

		for (SI_Tir& Actual_Tir : Tir_Joueur)
			Actual_Tir.Draw();
	}
	else if (Etat == State_SI::Menu)
	{

	}
	else if (Etat == State_SI::Intro)
	{

	}
}

void Intro()
{

}

void Menu()
{
	static Text Play("Play", font, 20);
	static Text Play("Quit", font, 20);
}


void App_Ennemis(int _rangeX, int _rangeY, int _typeMin, int _typeMax)
{
	int Rand = 0;
	for (int y = 0; y < _rangeY; y++)
	{
		for (int x = 0; x < _rangeX; x++)
		{
			Rand = irandom(_typeMin, _typeMax);
			EnnemyList.push_back(SI_Ennemi(Vector2f((1920 / 11 * (x + 1)), 105 + (120 * y)), Rand));
		}
	}
}