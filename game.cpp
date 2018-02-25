#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "squirrel");
    window.setFramerateLimit(60);
    e1.SetSpriteTexture("./squirrel.png");

    bg_tex.loadFromFile("./gfx/background.png");
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6,1.2));
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
    e1.Draw(window);
    window.display();
}
