#include "sorter.h"
#include <iostream>

#define BAR_WIDTH 17

void swap(int* num1, int* num2)
{
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}



Sorter::Sorter()
{
	//Initialize array with random numbers for sorting
	for (int i = 0; i < DATA_SIZE; i++)
	{
		data[i].value = std::rand() % 1024;
	}
}


//Bubble Sort
void BubbleSort::draw()
{

	sf::RectangleShape rect;
	for (int i = 0; i < DATA_SIZE; i++)
	{
		if(data[i].recentSwap == 1)
			rect.setFillColor(sf::Color(0,255,0,255));
		else if(data[i].recentSwap == 0)
			rect.setFillColor(sf::Color(i % 2 == 0 ? 255 : 150, 0, 0, 255));

		rect.setPosition(i * BAR_WIDTH + 64, Y_RES - 64);
		rect.setSize(sf::Vector2f(BAR_WIDTH, -data[i].value * 128 / 1024));
		Graphics::window->draw(rect);

		if (data[i].timer > 0)
			data[i].timer -= Graphics::delta.asSeconds();
		else
			data[i].recentSwap = 0;
	}


	//Draw tracer/current array access index
	sf::RectangleShape tracer;
	tracer.setFillColor(sf::Color(255, 255, 0, 255));
	tracer.setPosition(tracerValue * BAR_WIDTH + 64, Y_RES);
	tracer.setSize(sf::Vector2f(BAR_WIDTH, -32));
	Graphics::window->draw(tracer);


}

void BubbleSort::sort()
{
	for (int i = 0; i < DATA_SIZE - 1; i++)
	{
		for (int j = 0; j < DATA_SIZE - 1; j++)
		{

			if (data[j].value > data[j + 1].value)
			{
				swap(&data[j].value, &data[j + 1].value);

				data[j].recentSwap = 1;
				data[j + 1].recentSwap = 1;

				data[j].timer = 0.024f;
				data[j + 1].timer = 0.024f;
			}

			tracerValue = j;

			Sleep(25);
		}
	}

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::cout << data[i].value << " ";
	}

	std::cout << "\n";
}
