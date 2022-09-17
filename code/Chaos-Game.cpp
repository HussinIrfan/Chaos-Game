// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 

using namespace sf;
using namespace std;


vector<Vector2f> returnPoint(vector<Vector2f> v, vector<Vector2f> midpoint) //Function Returns midpoint between 2 random points
{
	int randNum = rand() % 3;
	Vector2f temp;

	temp.x = (midpoint[midpoint.size() - 1].x + v[randNum].x) / 2;
	temp.y = (midpoint[midpoint.size() - 1].y + v[randNum].y)/2;
	midpoint.push_back(Vector2f(temp.x, temp.y));

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
	vector<Vector2f> point; //4th click

	Vector2f clicked; //User clicks
	Event event;

	bool endClicks = true; //Make sure user clicks a max of 4 times
	int userClicks = 0;
	int maxClicks = 3;
	//window.setVerticalSyncEnabled(true);
    while (window.isOpen())  //Main Loop
	{
		window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //Esc closes Program
		{
			window.close();
		}

   		while (window.pollEvent(event)) //Checks for a max of 4 user clicks
   		{
 
       		//if (event.type == sf::Event::Closed)  //Not sure what this does
           		//window.close();

			if (event.type == Event::MouseButtonPressed && endClicks == true) 
			{
				if (event.mouseButton.button == Mouse::Left) 
				{
					cout << "mouse x: " << event.mouseButton.x << endl;
					cout << "mouse y: " << event.mouseButton.y << endl;
					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;

					if (userClicks < maxClicks) //Three Clicks, stores in two seperate vectors
					{
						vertices.push_back(Vector2f(clicked.x, clicked.y));
						point.push_back(Vector2f(clicked.x, clicked.y));
						userClicks++;
					}
					else //Fourth Click, bool value flips so algorithm starts
					{
						point.push_back(Vector2f(clicked.x, clicked.y));
						endClicks = false;
					}
				}
				
			}
   		}

		if (endClicks == false) //Calls algorithm function after user done inputting
		{
			point = returnPoint(vertices, point);
		}

		for (int i = 0; i < point.size(); i++) //Draws every point stored in point vector
		{
			rect.setPosition(point[i].x, point[i].y);
			window.draw(rect);
		}

		window.display(); //Display 

    }

    return 0;
}