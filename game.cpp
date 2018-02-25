#include "game.h"

Game::Game()
    :scroll(0.0f), time(sf::Time::Zero), temp_nut(scroll), scroll_state(0)
{
    window.create(sf::VideoMode(800,600), "./squirrel");
    window.setFramerateLimit(60);
    //e1.SetSpriteTexture("./gfx/wor_sqr.png");

    bg_tex.loadFromFile("./gfx/background.png");
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6f,1.2f));

   //std::cout<< "debug" <<std::endl;

    TreePart temp(scroll);
    for (int i = 0; i < 6; ++i)
        treeParts.push_back(temp);



	for (int i = 0; i < 4; ++i)
	{
        treeParts[i].setPosition(sf::Vector2f(400.0f,512.0f*i));
        treeParts[i].SetSpriteTexture("./gfx/pien.png");
	}
    treeParts[4].setPosition({ 400,0 });
    treeParts[4].SetSpriteTexture("./gfx/dziupla.png");

	treeParts[5].setPosition({ 390,2188 });
	treeParts[5].SetSpriteTexture("./gfx/korzen.png");
    //std::cout<< "debug2" <<std::endl;



	/////
	Worm w1(std::pair<float,float>(400,300),scroll);
	wormVec.push_back(w1);
	wormVec[0].SetSpriteTexture("./gfx/chroboq.png");
	wormVec[0].sprite.setScale(0.25, 0.25);


	////

	WorkerSquirrel wo1(scroll);
	workSqrVec.push_back(wo1);
	workSqrVec[0].SetSpriteTexture("./gfx/wor_sqr.png");
	workSqrVec[0].sprite.setPosition(500, 200);


    temp_nut.SetSpriteTexture("./gfx/nut.png");
    temp_nut.setPosition(sf::Vector2f(400,2048));
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
                scroll_state = 1;
            else if(my > 500)
                scroll_state = -1;
            else
                scroll_state = 0;
        }
    }
}

void Game::update()
{
    scroll += 10 * scroll_state;

    if(scroll < -2000)
        scroll = -2000;
    else if(scroll > 100)
        scroll = 100;

	int iter = 0, iterToRem =-1 ;

    while (nuts.size() < 10) {
        int x = engine()%600 +100;
        int y = engine()%100 + 2300;
        temp_nut.setPosition(sf::Vector2f(x,y));
        nuts.push_back(temp_nut);
    }
	for (auto & work : workSqrVec)
	{
		work.update(nuts);
	}


	for (auto &worm : wormVec)
	{
		worm.update(workSqrVec);
		if (worm.HP < 0.0f)
		{
			iterToRem = iter;
			
		}
		++iter;
	}
	if (iterToRem > -1)
	{
		wormVec.erase(wormVec.begin() + iterToRem);
	}
	
	iter = 0;
	iterToRem = -1;
	for (auto &worm : workSqrVec)
	{
		//worm.update();
		if (worm.HP < 0.f)
		{
			iterToRem = iter;
		}
		++iter;
	}
	if (iterToRem > -1)
	{
		workSqrVec.erase(workSqrVec.begin() + iterToRem);
	}

	iter = 0;
	iterToRem = -1;
	for (auto &worm : warSqrVec)
	{
		//worm.update();
		if (worm.HP < 0.f)
		{
			iterToRem = iter;
		}
		++iter;
	}
	if (iterToRem > -1)
	{
		warSqrVec.erase(warSqrVec.begin() + iterToRem);
	}
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
    for(auto &nut: nuts)
    {
        nut.Draw(window);
    }

   // e1.Draw(window);
    window.display();
}
