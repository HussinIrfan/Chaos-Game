// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 

using namespace sf;
using namespace std;


Vector2f returnPoint(vector<Vector2f> v, Vector2f midpoint) //Function Returns midpoint between 2 random points
{
	int randNum = rand() % 3 + 0;
	midpoint.x = (midpoint.x + v[randNum].x)/2;
	midpoint.y = (midpoint.y + v[randNum].y)/2;

	return midpoint;
};

int main()
{
	srand((int)time(0));
  
	VideoMode vm(1920/2, 1080/2); // Create a video mode object

	RenderWindow window(vm, "Sierpinksi Triangle!!", Style::Default); // Create and open a window for the game

	RectangleShape rect(Vector2f{2,2}); //Set the size of rectangles and color
	rect.setFillColor(Color::White);

	vector<Vector2f> vertices;//First 3 clicks

	Vector2f point; //4th click

	Vector2f clicked; //User clicks
	Event event;

	bool endClicks = true; //Make sure user clicks a max of 4 times
	int userClicks = 0;
	int maxClicks = 3;

    while (window.isOpen())  //Main Loop
	{

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //Esc closes Program
		{
			window.close();
		}

   		while (window.pollEvent(event))
   		{
 
       		if (event.type == sf::Event::Closed)
           		window.close();

			//Checks for a max of 4 user clicks
			if (event.type == Event::MouseButtonPressed && endClicks == true) 
			{
				if (event.mouseButton.button == Mouse::Left) 
				{
					cout << "mouse x: " << event.mouseButton.x << endl;
					cout << "mouse y: " << event.mouseButton.y << endl;
					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;

					if (userClicks < maxClicks)
					{
						vertices.push_back(Vector2f(clicked.x, clicked.y));
						rect.setPosition(vertices[userClicks].x, vertices[userClicks].y);
						userClicks++;
					}
					else
					{
						point = Vector2f(clicked.x, clicked.y);
						endClicks = false;
					}
				}
				
			}
   		}

		if (endClicks == false) //Calls function after user done inputting
		{
			rect.setPosition(point.x, point.y);
			point = returnPoint(vertices, point);
		}

		//Clear the scene
		//window.clear();
		
		//Draw the Scene:
		window.draw(rect);
		window.display();

    }

    return 0;
}