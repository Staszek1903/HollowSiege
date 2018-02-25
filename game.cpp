#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "squirrel");
    window.setFramerateLimit(60);
    e1.SetSpriteTexture("/gfx/wor_sqr.png");

    bg_tex.loadFromFile("/gfx/background.png");
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6f,1.2f));

	for (int i = 0; i < 4; ++i)
	{
		treeParts[i].setPosition(sf::Vector2f(0.0f,512.0f*i));
		treeParts[i].SetSpriteTexture("/gfx/pien.png");
	}
	treeParts[4].setPosition({ 0,2048 });
	treeParts[4].SetSpriteTexture("/gfx/dziupla.png");
}

void Game::run()
{
    while(window.isOpen())
    {
        input();
        update();
        render();
    }
}

void Game::input()
{
    sf::Event ev;
    while(window.pollEvent(ev))
    {
        if(ev.type == sf::Event::KeyPressed)
            window.close();
    }
}

void Game::update()
{

}

void Game::render()
{
    window.clear(sf::Color::Blue);
    window.draw(background);
	for (auto &nazwa : treeParts)
	{
		nazwa.Draw(window);
	}
    e1.Draw(window);
    window.display();
}
