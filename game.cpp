#include "game.h"

Game::Game()
    :scroll(0.0f)
{
    window.create(sf::VideoMode(800,600), "./squirrel");
    window.setFramerateLimit(60);
    //e1.SetSpriteTexture("./gfx/wor_sqr.png");

    bg_tex.loadFromFile("./gfx/background.png");
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6f,1.2f));

    std::cout<<"debug"<<std::endl;

    TreePart temp(scroll);
    for (int i = 0; i < 5; ++i)
        treeParts.push_back(temp);



	for (int i = 0; i < 4; ++i)
	{
        treeParts[i].setPosition(sf::Vector2f(400.0f,512.0f*i));
        treeParts[i].SetSpriteTexture("./gfx/pien.png");
	}
	treeParts[4].setPosition({ 0,2048 });
    treeParts[4].SetSpriteTexture("./gfx/dziupla.png");

    std::cout<<"debug2"<<std::endl;
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

        if(ev.type == sf::Event::MouseMoved)
        {
            int my = ev.mouseMove.y;
            if(my < 100)
                scroll+=10;
            if(my > 500)
                scroll-=10;
        }
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
   // e1.Draw(window);
    window.display();
}
