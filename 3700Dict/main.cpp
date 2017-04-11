
#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "sorter.h"
#include <thread>

sf::RenderWindow* Graphics::window;
sf::Time Graphics::delta;
sf::Text  Graphics::text;


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

	BubbleSort bSort = BubbleSort();
	InsertionSort sSort = InsertionSort();

	Sorter* currentSorter = &bSort; //Reference to current selected algorithm, defaults to bubble sort


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
			currentSorter = &bSort;
		}
		if (ImGui::Button("Insertion Sort"))
		{
			currentSorter = &sSort;
		}
		ImGui::End(); 


		//Algorithm Actions
		
		ImGui::Begin("Actions");
	
		if (ImGui::Button("Randomize")) {
			currentSorter->randomize();
		}
		ImGui::SameLine();
		if (ImGui::Button("Sort")) {
			std::thread t(sortBackground, currentSorter);
			t.detach();		
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