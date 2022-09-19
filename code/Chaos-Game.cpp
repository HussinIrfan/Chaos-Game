// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector> 

using namespace sf;
using namespace std;

void returnTriangle(vector<Vector2f>& vertices, vector<Vector2f>& midpoint); //Triangle: Creates midpoint and updates point vector
void returnSquare(vector<Vector2f>& vertices, vector<Vector2f>& midpoint, int& tempNum); //Square: Creates midpoint and updates point vector
void returnPentagon(vector<Vector2f>& vertices, vector<Vector2f>& midpoint, int& tempNum); //Square: Creates midpoint and updates point vector

int main()
{
	srand((int)time(0));
	int width = 1920;
	int height = 1080;
	VideoMode vm(width, height); // Create a video mode object
	RenderWindow window(vm, "Sierpinksi Triangle!!", Style::Default); // Create and open a window for the game
	RectangleShape rect(Vector2f{ 1,1 }); //Set the size of rectangles and color
	rect.setFillColor(Color::White);

	vector<Vector2f> vertices;//First 3 clicks
	vector<Vector2f> point; //4th click and beyond

	Vector2f clicked; //User clicks
	Event event;

	bool endClicks = true; //Flips to stop user input after maxClicks
	bool endShape = true; //Flips after user chooses shape

	int userClicks = 0; //increments based on users Clicks
	int maxClicks = 0; //Sets max number of clicks based on fractal choice
	int tempNum = 10; //Used for functions Square and Pentagon, makes sure random num isn't same as last random num
	int speed = 1000;

	Font font; //load text, set font
	if (!font.loadFromFile("Font/KOMIKAX.ttf"))
	{
	    cout << "Error loading font";
	}
	Text text;
	text.setFont(font);
	text.setString("Welcome To The Chaos Game!\nClick 1 To Draw Triangle\nClick 2 To Draw Rectangle\nClick 3 To Draw Pentagon\nClick ESC To Exit Program");
	text.setCharacterSize(25);
	text.setFillColor(Color::White);
	

	while (window.isOpen())  //Main Loop
	{
		window.clear(); //Clear screen every frame

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //Esc closes Program
		{
			window.close();
		}

		while (window.pollEvent(event)) //Gets user input for clicks and shape
		{
			if (event.type == Event::KeyPressed && endShape == true)
			{
				if (event.key.code == Keyboard::Num1)
				{
					cout << "User entered 1" << endl;
					maxClicks = 3;
					endShape = false;
					text.setString("Click 3 points, then 4th to draw fractal\nClick ESC To Exit Program");
				}
				if (event.key.code == Keyboard::Num2)
				{
					cout << "User entered 2" << endl;
					maxClicks = 4;
					endShape = false;
					text.setString("Click 4 points, then 5th to draw fractal\nClick ESC To Exit Program");
				}
				if (event.key.code == Keyboard::Num3)
				{
					cout << "User entered 3" << endl;
					maxClicks = 5;
					endShape = false;
					text.setString("Click 5 points, then 6th to draw fractal\nClick ESC To Exit Program");
				}
					
			}
			if (event.type == Event::MouseButtonPressed && endClicks == true && endShape == false)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
						clicked.x = event.mouseButton.x;
						clicked.y = event.mouseButton.y;

					if (userClicks < maxClicks) //Three or Four Clicks, stores in two seperate vectors
					{
						vertices.push_back(Vector2f(clicked.x, clicked.y));
						point.push_back(Vector2f(clicked.x, clicked.y));
						userClicks++; //Increment towards maxClicks
					}
					else //Fourth or Fifth Click, bool value flips so algorithm starts and user can no longer click
					{
						point.push_back(Vector2f(clicked.x, clicked.y));
						endClicks = false;
					}
				}
			}
		}

		if (endClicks == false) //Calls algorithm functions after user done inputting
		{
			if (maxClicks == 3)
			{
				for (int i = 0; i <= speed; i++)
					returnTriangle(vertices, point);
			}
			else if (maxClicks == 4)
			{
				for (int i = 0; i <= speed; i++)
					returnSquare(vertices, point, tempNum);
			}
			else if (maxClicks == 5)
			{
				for (int i = 0; i <= speed; i++)
					returnPentagon(vertices, point, tempNum);
			}
		}

		for (int i = 0; i < point.size(); i++) //Draws every point stored in point vector
		{
			rect.setPosition(point[i].x, point[i].y);
			window.draw(rect);
		}

		window.draw(text); //Draw text 
		window.display(); //Display 

	}
	return 0;
}

void returnTriangle(vector<Vector2f>& vertices, vector<Vector2f>& midpoint) //Triangle: Creates midpoint and updates point vector
{
	int randNum = rand() % 3;
	Vector2f temp;

	temp.x = (midpoint[midpoint.size() - 1].x + vertices[randNum].x) / 2;
	temp.y = (midpoint[midpoint.size() - 1].y + vertices[randNum].y) / 2;
	midpoint.push_back(Vector2f(temp.x, temp.y));
};

void returnSquare(vector<Vector2f>& vertices, vector<Vector2f>& midpoint, int& tempNum) //Square: Creates midpoint and updates point vector
{
	int randNum = rand() % 4;
	Vector2f temp;

	while (tempNum == randNum) //ensures random num isnt same as last random num
		randNum = rand() % 4;

	tempNum = randNum; //updates new random num, passed by reference so saves globally

	temp.x = (midpoint[midpoint.size() - 1].x + vertices[randNum].x) / 2;
	temp.y = (midpoint[midpoint.size() - 1].y + vertices[randNum].y) / 2;
	midpoint.push_back(Vector2f(temp.x, temp.y));
};

void returnPentagon(vector<Vector2f>& vertices, vector<Vector2f>& midpoint, int& tempNum) //Square: Creates midpoint and updates point vector
{
	int randNum = rand() % 5;
	Vector2f temp;

	while (tempNum == randNum) //ensures random num isnt same as last random num
		randNum = rand() % 5;

	tempNum = randNum; //updates new random num, passed by reference so saves globally
	temp.x = (midpoint[midpoint.size() - 1].x + vertices[randNum].x) / 2;
	temp.y = (midpoint[midpoint.size() - 1].y + vertices[randNum].y) / 2;
	midpoint.push_back(Vector2f(temp.x, temp.y));
};