#include "sorter.h"
#include <iostream>

#define BAR_WIDTH 64

void swap(int* num1, int* num2)
{
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

void Sorter::printArray()
{
	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::cout << data[i].value << " ";
	}

	std::cout << "\n";
}

Sorter::Sorter()
{
	//Initialize array with random numbers for sorting
	randomize();
}

void Sorter::randomize()
{
	for (int i = 0; i < DATA_SIZE; i++)
	{
		data[i].value = std::rand() % 1024;
	}
}


void Sorter::draw()
{
	sf::RectangleShape rect;
	for (int i = 0; i < DATA_SIZE; i++)
	{
		if (data[i].recentSwap == 1)
			rect.setFillColor(sf::Color(0, 255, 0, 255));
		else if (data[i].recentSwap == 0)
			rect.setFillColor(sf::Color(i % 2 == 0 ? 255 : 150, 0, 0, 255));

		rect.setPosition(i * BAR_WIDTH, Y_RES - 64);
		rect.setSize(sf::Vector2f(BAR_WIDTH, -data[i].value * 256 / 1024));
		Graphics::window->draw(rect);

		if (data[i].timer > 0)
			data[i].timer -= Graphics::delta.asSeconds();
		else
			data[i].recentSwap = 0;

		//Draw debug array values
		Graphics::text.setString(std::to_string(data[i].value));
		Graphics::text.setPosition(i * 64 + 8, 660);
		Graphics::window->draw(Graphics::text);
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
		for (int j = 0; j < DATA_SIZE - 1; j++)
		{
			if (data[j].value > data[j + 1].value)
			{
				swap(&data[j].value, &data[j + 1].value);
				swapped = 1;

				//Update to display recently swapped values as green
				data[j].recentSwap = 1;
				data[j + 1].recentSwap = 1;
				data[j].timer = 0.024f;
				data[j + 1].timer = 0.024f;	
			}

			tracerValue = j; //update current visual index

			Sleep(25);
		}
	}

	std::cout << "Sorted: ";
	printArray();

}

//Insertion Sort
void InsertionSort::sort()
{
	int i, j, temp;
	for (i = 1; i < DATA_SIZE; i++)
	{
		j = i;
		while (j > 0 && data[j].value <  data[j - 1].value)
		{
			temp = data[j].value;
			data[j].value = data[j - 1].value;
			data[j - 1].value = temp;
			j--;
			Sleep(25);


			data[j].timer = 0.024f;
			data[j].recentSwap = 1;
		
		}

		tracerValue = i;

		Sleep(25);
	}
}