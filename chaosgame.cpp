// Include important C++ libraries here

// to do this, if you go into file explorer, you'll see that I added a bunch of stuff into the x64 folder (dlls and the text file went there lol) -- amrit : )
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
	/*
	// un comment this out to work on text font display -- AS
	// going to try to implement the font here -- Amrit
	Font font;
	if (!font.loadFromFile("arial.ttf")) // this is the exact name of what I downloaded and put into x64, I tried with a few different ones; ignore those if you see them -- AS
	{
		cout << "Error!! NOOOO" << endl;
		//want to keep the console open so I can read the error
		system("pause");
	}
	// there was an initial error in the config which was related to an unsupported font; it was running fine before I added this in, it should be fixed now -- amrit
	
	Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(24);
	instructions.setFillColor(Color::White);
	instructions.setPosition(10, 10);
	instructions.setString("Click 3 points to start the triangle!");
	*/
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

	// this is just the base stuff

	vector<Vector2f> vertices;
	vector<Vector2f> points;
	
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
						//???
					}
					else if (points.size() == 0)
					{
						///fourth click
						///push back to points vector
						/// david can figure out the vector stuff for the points, I got the three clicks working on my end -- Amrit
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

		if (points.size() > 0)
		{
			///generate more point(s)
			///select random vertex
			///calculate midpoint between random vertex and the last point in the vector
			///push back the newly generated coord.
		}

		/*
		****************************************
		Draw
		****************************************
		*/
		/*
		window.draw(instructions);
		//seems straightforward? -- amrit
*/
		window.clear();
		//hi -- test -- AS
		for (int i = 0; i < vertices.size(); i++)
		{
			RectangleShape rect(Vector2f(10, 10));
			//for an option of contributing, you could maybe change this to a circle if you want? -- Amrit
			/*for (int i = 0; i < points.size(); i++)
{
    CircleShape dot(1); 
    dot.setPosition(points[i]);
    dot.setFillColor(Color::Red); 
    window.draw(dot);
}*/
			rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
			rect.setFillColor(Color::Red);
			// changed the color just to test, you can change back if you want -- Amrit
			window.draw(rect);
		}
		///TODO:  Draw points
		window.display();
	}
}
