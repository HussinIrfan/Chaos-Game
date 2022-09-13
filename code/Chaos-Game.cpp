// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Sierpinksi Triangle!!", Style::Default);

	RectangleShape rect(Vector2f{20,20});

	vector<Vector2f> vertices;// first 3 clicks
	vector<Vector2f> points; // 4th click

	Vector2f clicked; //user clicks

    while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/		

	//Update the scene

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
			****************************************
			Update the scene
			****************************************
		*/
		Event event;
   		while (window.pollEvent(event))
   		{
       // Request for closing the window
       		if (event.type == sf::Event::Closed)
           		window.close();
   		}
	
		if (event.type == sf::Event::MouseButtonPressed)
		{	
    		if (event.mouseButton.button == sf::Mouse::Left)
    		{
        		std::cout << "the right button was pressed" << std::endl;
        		std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        		std::cout << "mouse y: " << event.mouseButton.y << std::endl;

				clicked.x = event.mouseButton.x;
				clicked.y = event.mouseButton.y;
    		}
		}

	rect.setPosition(clicked.x, clicked.y);
	rect.setFillColor(Color::Red);

	//Clear the scene
	window.clear();
	//Draw the Scene:
	window.draw(rect);
	window.display();


    }

    return 0;

}