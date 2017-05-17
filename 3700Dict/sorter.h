#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <math.h>
#include <Windows.h>


//#define DATA_SIZE 20		//Data/Array size
#define X_RES 1280			//X resolution in pixels	
#define Y_RES 720			//Y resolution in pixels

//#define BAR_WIDTH 64		//Visual bar width (in pixels) for displaying visual array
#define NUMBER_SCALE 512	//Scale of random numbers to generate

class Graphics {
public :
	static sf::RenderWindow* window;
	static sf::Time delta; //delta frame time
	static sf::Text text;
};

class Settings {
public:
	static float sleepTime;
	static int dataSize;
};



struct dataContainer
{
	int value; 
	int recentSwap;
	float timer;
};

//Base sorting / algorithm class
class Sorter
{
	
public: 
	Sorter();
	~Sorter() {}
	dataContainer* data;	
	int tracerValue;
	virtual void initiate();
	void printArray();
	virtual void draw();
	virtual void sort() {}
	std::string name; //name for visual drawing
};

class BubbleSort : public Sorter
{
public :
	void sort() override;
	BubbleSort() { name = "Bubble Sort"; Sorter(); }
};

class InsertionSort : public Sorter
{
public:
	void sort() override;
	InsertionSort() { name = "Insertion Sort"; Sorter(); }
};


class QuickSort : public Sorter
{
public:
	void sort() override;
	QuickSort() {name = "Quick Sort"; Sorter();}
};



//
////Dijkstra's algorithm
//class Dijkstra : public Sorter
//{
//public:
//	int nodeSize = 15;
//	struct Node {
//		float x, y; //Positions
//	};
//	Node* nodes;
//
//
//	void sort() override;
//	void draw() override;
//	void initiate() override;
//	int Dijkstra::findFirstNeighbor(Node node);
//
//	Dijkstra() { name = "Dijkstra"; }
//};