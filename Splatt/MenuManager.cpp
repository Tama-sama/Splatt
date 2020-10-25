#include "MenuManager.h"
#include "StateManager.hpp"
#include "Controles.h"

#include "Aste_Manager.h"

std::vector<std::string> VecMenu;
int choice = 1;

void Menu_Init()
{
	VecMenu.push_back("Space Invader");
	VecMenu.push_back("PacMan");
	VecMenu.push_back("Lunar Lander");
	VecMenu.push_back("Asteroids");
	VecMenu.push_back("Tetris");
	VecMenu.push_back("Tron");
	VecMenu.push_back("KingKong");
	VecMenu.push_back("Option");
	VecMenu.push_back("Credits");
	VecMenu.push_back("Quit");
}

void Menu_Update()
{
	static bool onepass = false;
	static float menuTimer = 0.f;
	menuTimer += MainTime.GetTimeDeltaF();

	if (!onepass)
	{
		Menu_Init();
		onepass = true;
	}

	if (isButtonPressed(Action::Down) && menuTimer >= 0.3)
	{
		menuTimer = 0;

		if (choice < VecMenu.size())
			choice++;
		else
			choice = 1;
	}

	if (isButtonPressed(Action::UP) && menuTimer >= 0.3)
	{
		menuTimer = 0;

		if (choice > 1)
			choice--;
		else
			choice = VecMenu.size();
	}

	if (isButtonPressed(Action::Interact) && menuTimer >= 0.2)
	{
		menuTimer = 0;

		switch (choice)
		{
		case 1:
			ChangeState(State::SPACE_INVADER);
			break;
		case 2:
			ChangeState(State::PACMAN);
			break;
		case 3:
			ChangeState(State::LUNAR_LANDER);
			break;
		case 4:
			ChangeState(State::ASTEROID);
			break;
		case 5:
			ChangeState(State::TETRIS);
			break;
		case 6:
			ChangeState(State::TRON);
			break;
		case 7:
			//ChangeState(State::);  KingKong
			break;
		case 8:
			// Option
			break;
		case 9:
			// credits
			break;
		case 10:
			App.close();
			break;

		default:
			break;
		}
	}
}

void Menu_Display()
{
	sf::Text TMenu("", font, 60);

	int i = 0;
	for (std::string& actu : VecMenu)
	{
		i++;

		if (choice == i)
			TMenu.setFillColor(sf::Color::Red);
		else
			TMenu.setFillColor(sf::Color::White);
			
		TMenu.setString(actu);
		TMenu.setCharacterSize(60.f + (5.f * -abs(i - choice)));
		TMenu.setOrigin(getMidle(TMenu));
		TMenu.setPosition(300.f, 540.f + ((50.f - abs((i - choice)) * 2.75f) * (i - choice)));
		App.draw(TMenu);
	}

	static const unsigned short int BaseX = 750;

	switch (choice)
	{
	case 1:
		// space i
		break;
	case 2:
		// pacman
		break;
	case 3:
		// lunar
		break;
	case 4:
		Aste_Infos(BaseX);
		break;
	case 5:
		// tetris
		break;
	case 6:
		// tron
		break;
	case 7:
		// KingKong
		break;
	case 8:
		// Option
		break;
	case 9:
		// credits
		break;
	case 10:
		// idk what to do 
		break;

	default:
		break;
	}
}