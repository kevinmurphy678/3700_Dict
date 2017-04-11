#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <Windows.h>


#define DATA_SIZE 20
#define X_RES 1280
#define Y_RES 720

class Graphics {
public :
	static sf::RenderWindow* window;
	static sf::Time delta; //delta frame time
	static sf::Text text;
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
	int tracerValue;
	void randomize();
	void printArray();
	virtual void draw();
	virtual void sort() {}
	std::string name; //name for visual drawing
};

class BubbleSort : public Sorter
{
public :
	void sort() override;
	BubbleSort() { name = std::string("Bubble Sort"); Sorter::Sorter(); }
};

class InsertionSort : public Sorter
{
public:
	void sort() override;
	InsertionSort() { name = std::string("Insertion Sort"); Sorter::Sorter(); }
};