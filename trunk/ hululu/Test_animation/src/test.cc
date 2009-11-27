#include <SFML/System.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{

	    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Graphics");

	    // Load the sprite image from a file
	    sf::Image Image;
	    if (!Image.LoadFromFile("Test_animation/src/sprite_g_walk.png"))
	        return EXIT_FAILURE;
	    // Create the sprite
	    sf::Sprite Sprite(Image);

	    // Change its properties
	    Sprite.SetColor(sf::Color(0, 255, 255, 128));
	    Sprite.SetPosition(200.f, 100.f);
	    Sprite.SetScale(2.f, 2.f);

	    // Start game loop
	    while (App.IsOpened())
	    {
	        // Process events
	        sf::Event Event;
	        while (App.GetEvent(Event))
	        {
	            // Close window : exit
	            if (Event.Type == sf::Event::Closed)
	                App.Close();
	        }

	        // Get elapsed time
	        float ElapsedTime = App.GetFrameTime();

	        // Clear screen
	        App.Clear();

	        // Display sprite in our window
	        App.Draw(Sprite);

	        // Display window contents on screen
	        App.Display();
	    }

	    return EXIT_SUCCESS;
	}
