
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "sorter.h"
#include <thread>

sf::RenderWindow* Graphics::window;
sf::Time Graphics::delta;
sf::Text  Graphics::text;
float Settings::sleepTime = 0.5f; 
int Settings::dataSize = 20;    //Default array size

void sortBackground(Sorter* sorter)
{
	sorter->sort();
}

int main()
{
	//Init Window
	Graphics::window = new sf::RenderWindow(sf::VideoMode(X_RES, Y_RES), "3700");
	Graphics::window->setVerticalSyncEnabled(true);

	//Init Gui
	ImGui::SFML::Init(*Graphics::window);
	Graphics::window->resetGLStates();

	//Utils / Graphics
	sf::Clock deltaClock;
	sf::Font font;
	font.loadFromFile("FreeSans.ttf");
	Graphics::text.setFont(font);
	Graphics::text.setCharacterSize(24);

	//Sorting algorithm objects
	BubbleSort bSort = BubbleSort();
	InsertionSort sSort = InsertionSort();
	QuickSort qSort = QuickSort();


	//Reference to current selected algorithm, defaults to bubble sort
	Sorter* currentSorter = &bSort; 

	//Main Loop
	while (Graphics::window->isOpen()) {
		sf::Event event;

		while (Graphics::window->pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed) {
				Graphics::window->close();
			}
		}

		Graphics::delta = deltaClock.restart();
		ImGui::SFML::Update(*Graphics::window, Graphics::delta);

		//Algorithm Selector
		ImGui::Begin("Algorithms"); 
		if (ImGui::Button("Bubble Sort")) {
			bSort.initiate();
			currentSorter = &bSort;
		}
		if (ImGui::Button("Insertion Sort"))
		{
			sSort.initiate();
			currentSorter = &sSort;
		}
		if (ImGui::Button("Quick Sort"))
		{
			qSort.initiate();
			currentSorter = &qSort;
		}

	
		ImGui::End(); 

		//Algorithm Actions	
		ImGui::Begin("Actions");	
		if (ImGui::Button("Randomize")) {
			currentSorter->initiate();
		}
		ImGui::SameLine();
		if (ImGui::Button("Sort")) {
			//Start sorting the array in a new thread
			std::thread t(sortBackground, currentSorter);
			t.detach();		
		}

		ImGui::SliderFloat("Delay", &Settings::sleepTime, 0.f, 2.f);
		if (ImGui::SliderInt("Data Size", &Settings::dataSize, 8, 128))
		{
			currentSorter->initiate();
		}

		ImGui::End();

		Graphics::window->clear(sf::Color(55,65,74,255));
	
		currentSorter->draw();

		ImGui::Render();

		Graphics::window->display();
	}


	//Shut down
	ImGui::SFML::Shutdown();

	delete Graphics::window;

	return 0;

}