#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <Windows.h>


#define DATA_SIZE 64
#define X_RES 1280
#define Y_RES 720


class Graphics {
public :
	static sf::RenderWindow* window;
	static sf::Time delta; //delta frame time
};




struct dataContainer
{
	int value; 
	int recentSwap;
	float timer;
};

//Base sorting class
class Sorter
{
	
public: 
	Sorter();
	~Sorter() {}
	dataContainer data[DATA_SIZE];	
	virtual void draw() {}
	virtual void sort() {}
};

class BubbleSort : public Sorter
{
public :
	void draw() override;
	void sort() override;
	int tracerValue;
};