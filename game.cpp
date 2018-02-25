#include "game.h"

Game::Game()
    :scroll(0.0f), time(sf::Time::Zero)
{
    window.create(sf::VideoMode(800,600), "./squirrel");
    window.setFramerateLimit(60);
    //e1.SetSpriteTexture("./gfx/wor_sqr.png");

    bg_tex.loadFromFile("./gfx/background.png");
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6f,1.2f));

    std::cout<< "debug" <<std::endl;

    TreePart temp(scroll);
    for (int i = 0; i < 6; ++i)
        treeParts.push_back(temp);



	for (int i = 0; i < 4; ++i)
	{
        treeParts[i].setPosition(sf::Vector2f(400.0f,512.0f*i));
        treeParts[i].SetSpriteTexture("./gfx/pien.png");
	}
	treeParts[4].setPosition({ 0,2048 });
    treeParts[4].SetSpriteTexture("./gfx/dziupla.png");

	treeParts[5].setPosition({ 390,2188 });
	treeParts[5].SetSpriteTexture("./gfx/korzen.png");
    std::cout<< "debug2" <<std::endl;



	/////
	Worm w1(std::pair<float,float>(400,300),scroll);
	wormVec.push_back(w1);
	wormVec[0].SetSpriteTexture("./gfx/chroboq.png");
	wormVec[0].sprite.setScale(0.25, 0.25);


	////

	WorkerSquirrel wo1(scroll);
	workSqrVec.push_back(wo1);
	workSqrVec[0].SetSpriteTexture("./gfx/wor_sqr.png");
	workSqrVec[0].sprite.setScale(0.25, 0.25);
	workSqrVec[0].sprite.setPosition(500, 200);


}

void Game::run()
{
    while(window.isOpen())
    {
		time += clk.restart();
		if (time.asMilliseconds() > 1000/60)
		{
			input();
			update();
			render();
			time = sf::Time::Zero;
		}
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
	int iter = 0;
	for (auto &worm : wormVec)
	{
		worm.update(workSqrVec);
		if (worm.HP < 0.0f)
		{
			
		}
		//++iter;
	}
	wormVec.erase(wormVec.begin() + iter);
	
	/*
	iter = 0;
	for (auto &worm : workSqrVec)
	{
		//worm.update();
		if (worm.HP < 0.f)
		{
			workSqrVec.erase(workSqrVec.begin() + iter);
		}
		++iter;
	}

	iter = 0;
	for (auto &worm : warSqrVec)
	{
		//worm.update();
		if (worm.HP < 0.f)
		{
			warSqrVec.erase(warSqrVec.begin() + iter);
		}
		++iter;
	}*/
}

void Game::render()
{
    window.clear(sf::Color::Blue);
    window.draw(background);
	for (auto &nazwa : treeParts)
	{
		nazwa.Draw(window);
	}
	for (auto &nazwa : workSqrVec)
	{
		nazwa.Draw(window);
	}
	for (auto &nazwa : wormVec)
	{
		nazwa.Draw(window);
	}

   // e1.Draw(window);
    window.display();
}
