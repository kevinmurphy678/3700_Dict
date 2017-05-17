#include "sorter.h"
#include <iostream>
#include <random>
#include <math.h>

//Calculate sleep time, scaled with data size
#define SLEEP_TIME std::max(1.f, Settings::sleepTime / (float)Settings::dataSize * 1000.f)  


//Swap two numbers
void swap(int* num1, int* num2)
{
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

//Simple method to print the array
void Sorter::printArray()
{
	
	for (int i = 0; i < Settings::dataSize; i++)
		std::cout << data[i].value << " ";
	
	std::cout << "\n";
}

Sorter::Sorter()
{	
	initiate();
}

//Populate array with random numbers, scaling them with the max number scale
void Sorter::initiate()
{
	//Initiate data array with data size setting
	data = new dataContainer[Settings::dataSize];

	//https://www.securecoding.cert.org/confluence/display/cplusplus/MSC50-CPP.+Do+not+use+std%3A%3Arand%28%29+for+generating+pseudorandom+numbers
	std::uniform_int_distribution<int> dist (0, NUMBER_SCALE);
	std::random_device rd;
	std::mt19937 engine(rd());
	for (int i = 0; i < Settings::dataSize; i++)
		data[i].value = dist(engine);
}


void Sorter::draw()
{
	float BAR_WIDTH = (X_RES / (float)Settings::dataSize);
	//Draw current sorting algorithm name in middle of screen
	Graphics::text.setColor(sf::Color::White);
	Graphics::text.setString(name);
	Graphics::text.setPosition(X_RES/2 - Graphics::text.getGlobalBounds().width / 2, Y_RES / 2 - 128);
	Graphics::window->draw(Graphics::text);

	sf::RectangleShape rect;
	for (int i = 0; i < Settings::dataSize; i++)
	{
		if (data[i].recentSwap == 1)//Set recent swaps to display as green
			rect.setFillColor(sf::Color(0, i % 2 == 0 ? 255 : 150, 0, 255));
		else if (data[i].recentSwap == 0)
			rect.setFillColor(sf::Color(i % 2 == 0 ? 255 : 150, 0, 0, 255));

		rect.setPosition(i * BAR_WIDTH, Y_RES - 64);
		rect.setSize(sf::Vector2f(BAR_WIDTH, -data[i].value * (Y_RES / 2) / NUMBER_SCALE)); //Draw rectangles to represent array data value and scale the rectangles properly to fit the screen..
		Graphics::window->draw(rect);

		if (data[i].timer > 0)
			data[i].timer -= Graphics::delta.asMilliseconds();//Decrease timer
		else
			data[i].recentSwap = 0;

		//Draw debug array values but only for small data sizes
		if (Settings::dataSize < 30)
		{
			Graphics::text.setString(std::to_string(data[i].value));
			Graphics::text.setPosition(i * BAR_WIDTH + 8, 660);
			Graphics::window->draw(Graphics::text);
		}
	}

	//Draw tracer/current array access index
	rect.setFillColor(sf::Color(255, 255, 0, 255));
	rect.setPosition(tracerValue * BAR_WIDTH, Y_RES);
	rect.setSize(sf::Vector2f(BAR_WIDTH, -32));
	Graphics::window->draw(rect);
}

//Bubble sort
void BubbleSort::sort()
{
	std::cout << "Array: ";
	printArray();

	int swapped = 1;
	while (swapped)
	{
		swapped = 0;
		for (int j = 0; j < Settings::dataSize - 1; j++)
		{
			if (data[j].value > data[j + 1].value)
			{
				swap(&data[j].value, &data[j + 1].value);
				swapped = 1;

				//Update to display recently swapped values as green
				data[j].recentSwap = 1;
				data[j + 1].recentSwap = 1;
				data[j].timer = SLEEP_TIME;
				data[j + 1].timer = SLEEP_TIME;
			}

			tracerValue = j; //update current visual index

			Sleep(SLEEP_TIME);
		}
	}

	std::cout << "Sorted: ";
	printArray();

}

//Insertion Sort
void InsertionSort::sort()
{
	std::cout << "Array: ";
	printArray();

	int i, j, temp;
	for (i = 1; i < Settings::dataSize; i++)
	{
		j = i;
		while (j > 0 && data[j].value <  data[j - 1].value)
		{
			temp = data[j].value;
			data[j].value = data[j - 1].value;
			data[j - 1].value = temp;
			
			//Update to display recently swapped values as green
			data[j].timer = SLEEP_TIME;
			data[j].recentSwap = 1;		
			data[j - 1].timer = SLEEP_TIME;
			data[j-1].recentSwap = 1;
			Sleep(SLEEP_TIME);


			j--;
		}

		tracerValue = i;

		Sleep(SLEEP_TIME);
	}

	std::cout << "Sorted: ";
	printArray();
}

//Quick sort
int partition(dataContainer* data, int left, int right)
{
	int pivot = data[right].value;
	int i = left - 1; 

	for (int j = left; j <= right - 1; j++)
	{
		if (data[j].value <= pivot) 
		{
			i++;
			swap(&data[i].value, &data[j].value);


			data[j].timer = SLEEP_TIME;
			data[j].recentSwap = 1;
			data[i].timer = SLEEP_TIME;
			data[i].recentSwap = 1;

			Sleep(SLEEP_TIME);

		}
	}
	swap(&data[i + 1].value, &data[right].value);


	data[i + 1].timer = SLEEP_TIME;
	data[i + 1].recentSwap = 1;
	data[right].timer = SLEEP_TIME;
	data[right].recentSwap = 1;

	Sleep(SLEEP_TIME);

	return i + 1;
}

void quickSort(dataContainer* data, int left, int right)
{
	if (left < right)
	{
		int p = partition(data, left, right);
		quickSort(data, left, p - 1);
		quickSort(data, p + 1, right);
	}
}

void QuickSort::sort()
{
	std::cout << "Array: ";
	printArray();

	quickSort(data, 0, Settings::dataSize - 1);

	std::cout << "Sorted: ";
	printArray();
}