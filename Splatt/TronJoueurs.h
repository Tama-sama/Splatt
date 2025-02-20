#pragma once
#include "TronTools.h"

class Joueurs
{
private:
	int x;
	int y;
	int direction;
	sf::Color color;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string path;
	sf::Vector2f origin;
	unsigned short TronNBdeVies;
public:
	Joueurs(sf::Color _color);
	~Joueurs();
	sf::Vector3f getVecColor();
	sf::Color getColor();
	sf::Sprite& getSprite();
	sf::Texture getTexture();
	sf::Vector2f getOrigin();
	int getDir();
	void setDir(int _direction);
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	void setPosition(float _x, float _y);
	void setSprite(sf::Texture _texture);
	void setTexture(std::string _path);
	void setOrigin(sf::Vector2f _origin);
	void Zuse();
	unsigned short getNbdeVies();
	void setNbdeVies();
	void setAddVies();
	bool TronVerif;
};

extern Joueurs joueur1;
extern Joueurs joueur2;


