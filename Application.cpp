#include "Application.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

Application::Application()
: mWindow( sf::VideoMode(60*8, 60*8), "E4E5", sf::Style::Close)
, mBoard(&mWindow, &mTextureHolder, 60)
{
}

void Application::run()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1/60.f);

	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

		}

		render();
	}
}

void Application::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            mWindow.close();
        mBoard.handleEvent(event);
    }
}

void Application::update(sf::Time)
{

}
void Application::render()
{
    mWindow.clear();
    mWindow.draw(mBoard);
    mWindow.display();
}