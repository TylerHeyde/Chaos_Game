
/*
	Group members:
		- David: create the code that generates the points
		- Tyler: Managed the gihub, Merged everyones code, debugged everyones code, cleaned code, implemented all text, added comments where needed
		- Amrit: Created main structure of the code, created the code to track the vertices of the triangle, delegated tasks
*/


// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>


//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	bool started = false;
	Font font;
	font.loadFromFile("Fonts\\orange juice 2.0.ttf");
	if (!font.loadFromFile("Fonts\\orange juice 2.0.ttf"))
	{
		cout << "Error!! NOOOO" << endl;
		//want to keep the console open so I can read the error
		system("pause");
	}

	// sets the text at the top of the screen to the proper font, size, color, and position -- Tyler
	Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(60);
	instructions.setFillColor(Color::White);
	instructions.setPosition(450, 10);
	instructions.setString("Click 3 points to shape the triangle!");

	Text generationtext;
	generationtext.setFont(font);
	generationtext.setCharacterSize(60);
	generationtext.setFillColor(Color::White);
	generationtext.setPosition(700, 10);
	generationtext.setString("Generating points...");

	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;
	Vector2f currentPoint;
	// vectors

	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}



			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					if (vertices.size() < 3)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
						//pushes the first 3 points into the vertices vector, which will be used to draw the triangle and generate the points -- David
					}
					else if (vertices.size() == 3)
					{
						currentPoint = vertices[0];
					}
				}
			}


		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/
		if (vertices.size() == 3)
		{
			started = true;
			//creates 100 points before advancing to the next frame, which makes the points appear faster -- David
			for (int i = 0; i < 100; i++)
			{
				int target = rand() % 3;
				currentPoint.x = (currentPoint.x + vertices[target].x) / 2.0f;
				currentPoint.y = (currentPoint.y + vertices[target].y) / 2.0f;
				points.push_back(currentPoint);
			}
		}
		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();

		//draws the dots for the triangle
		for (const auto& p : points)
		{
			CircleShape dot(1);
			dot.setPosition(p);
			dot.setFillColor(Color::Red);
			window.draw(dot);
		}

		//draws the instructions at the top of the screen and the vertices of the triangle -- Tyler
		if (!started){
			window.draw(instructions);
		}
		else {
			window.draw(generationtext);
		}
		//draws the vertices of the triangle as red squares -- Amrit
		for (int i = 0; i < vertices.size(); i++)
		{
			RectangleShape rect(Vector2f(10, 10));
			rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
			rect.setFillColor(Color::Red);
			window.draw(rect);
		}



		window.display();

	}
}
