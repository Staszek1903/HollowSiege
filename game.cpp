#include "game.h"

Game::Game()
    :scroll(0.0f), time(sf::Time::Zero), temp_nut(scroll), scroll_state(0), nut_amount(0)
{
    window.create(sf::VideoMode(800,600), "./squirrel");
    window.setFramerateLimit(60);
    //e1.SetSpriteTexture("./gfx/wor_sqr.png");

    bg_tex.loadFromFile("./gfx/background.png");
    nut_tex.loadFromFile("./gfx/nut.png");
    nut.setTexture(nut_tex);
    background.setTexture(bg_tex);
    background.setScale(sf::Vector2f(1.6f,1.2f));

    comic.loadFromFile("./gfx/COMIC.TTF");
    nut_am.setFont(comic);
    nut_am.setString("0");
    nut_am.setCharacterSize(64);
    nut_am.setPosition(50,50);
    nut_am.setFillColor(sf::Color::Black);

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

void Game::spawnR()
{
	WorkerSquirrel wo1(scroll);
	workSqrVec.push_back(wo1);
	workSqrVec[workSqrVec.size() - 1].SetSpriteTexture("./gfx/wor_sqr.png");
	workSqrVec[workSqrVec.size() - 1].sprite.setPosition(400, 2);
	workSqrVec[workSqrVec.size() - 1].sprite.setScale(0.7, 0.7);
}
void Game::spawnT()
{
	WarriorSquirrel wo1(scroll);
	warSqrVec.push_back(wo1);
	warSqrVec[warSqrVec.size() - 1].SetSpriteTexture("./gfx/atk_sqr.png");
	warSqrVec[warSqrVec.size() - 1].sprite.setPosition(400, 2);
	warSqrVec[warSqrVec.size() - 1].sprite.setScale(0.7, 0.7);
}
void Game::input()
{
    sf::Event ev;
    while(window.pollEvent(ev))
    {
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::R)
			{
				
				spawnR();
			}
			if (ev.key.code == sf::Keyboard::T)
			{
				spawnT();
			}
		}

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
	

    for(auto & work: workSqrVec)
    {
        if(work.update(nuts))
        {
            nut_amount++;
            std::stringstream ss;
            ss<<nut_amount;
            nut_am.setString(ss.str());
        }

    }

	iter = 0;
	iterToRem = -1;
	for (auto &worm : workSqrVec)
	{
		std::cout << worm.HP << " ";
		//worm.update();
		if (worm.HP < 0)
		{
			iterToRem = iter;
		}
		++iter;
	}
	std::cout <<std::endl;
	if (iterToRem > -1)
	{
		std::cout << " kill " << iterToRem << std::endl;
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
		warSqrVec.erase(warSqrVec.end() + iterToRem);
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
	for (auto &nazwa : warSqrVec)
	{
		nazwa.Draw(window);
	}
    for(auto &nut: nuts)
    {
        nut.Draw(window);
    }
    window.draw(nut);
    window.draw(nut_am);

   // e1.Draw(window);
    window.display();
}
