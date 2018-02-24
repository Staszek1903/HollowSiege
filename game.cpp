#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "squirrel");
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
    window.display();
}
