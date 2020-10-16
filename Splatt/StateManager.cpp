#include "StateManager.hpp"
#include "Aste_Manager.h"
#include "Pac_Manager.h"
#include "Lunar_manager.h"
#include "SI_Manager.h"
#include "SoundManager.hpp"
#include "Texture_SpriteManager.hpp"
#include "Controles.h"

State state = State::MENU;

Lunar_manager* l_manager = new Lunar_manager;

void EventsManager()
{
	while (App.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			App.close();


		if (event.type == sf::Event::KeyPressed)
			PressedKey.push_back(event.key.code);

		if (event.type == sf::Event::KeyReleased)
			PressedKey.remove(event.key.code);

		for (int i = 0; i < 8; i++)
			GamepadManager(i, event);
	}
}

void ChangeState(State NextState)
{
	RemoveAllSounds();
	RemoveAllSprites();

	state = NextState;

	LoadSounds(NextState);
	LoadSprite(NextState);
}

void UpdateManager()
{
	//restart of the clock (time per frame)
	MainTime.RestartClock();

	switch (state)
	{
	case State::RTNULL:
		break;
	case State::MENU:
		break;
	case State::SPACE_INVADER:
		SI_Update();
		break;
	case State::PACMAN:
		Pac_Update();
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_update();
		break;
	case State::ASTEROID:
		Aste_Update();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		break;

	default:
		break;
	}
}


void DisplayManager()
{
	// Clear the Window
	App.clear(sf::Color::Black);

	switch (state)
	{
	case State::RTNULL:
		break;
	case State::MENU:
		break;
	case State::SPACE_INVADER:
		SI_Display();
		break;
	case State::PACMAN:
		Pac_Display();
		break;
	case State::LUNAR_LANDER:
		l_manager->Lunar_display(App);
		break;
	case State::ASTEROID:
		Aste_Display();
		break;
	case State::TETRIS:
		break;
	case State::TRON:
		break;

	default:
		break;
	}

	// Display on window
	App.display();
}