#include "game.h"

Game::Game()
    :scroll(0.0f), time(sf::Time::Zero), temp_nut(scroll), scroll_state(0), nut_amount(10), freqOfSpawningWorms(15)
{
    window.create(sf::VideoMode(800,600), "./squirrel");
    window.setFramerateLimit(60);
    //e1.SetSpriteTexture("./gfx/wor_sqr.png");

    cont.loadFromFile("./gfx/tex_dirs.conf");

    nut.setTexture(cont.getTexture("nut"));
    background.setTexture(cont.getTexture("background"));
    background.setScale(sf::Vector2f(1.6f,1.2f));

    wor_inst.setTexture(cont.getTexture("wor_inst"));
    wor_inst.setPosition(sf::Vector2f(0,150));
    wor_inst.setScale(sf::Vector2f(0.5f,0.5f));
    atk_inst.setTexture(cont.getTexture("atk_inst"));
    atk_inst.setPosition(sf::Vector2f(0,250));
    atk_inst.setScale(sf::Vector2f(0.5f,0.5f));

    comic.loadFromFile("./gfx/COMIC.TTF");
    nut_am.setFont(comic);
    nut_am.setString("10");
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
        treeParts[i].SetSpriteTexture(cont.getTexture("pien"));
	}
    treeParts[4].setPosition({ 400,0 });
    treeParts[4].SetSpriteTexture(cont.getTexture("dziupla"));

	treeParts[5].setPosition({ 390,2188 });
    treeParts[5].SetSpriteTexture(cont.getTexture("korzen"));
    //std::cout<< "debug2" <<std::endl;



	/////
	Worm w1(std::pair<float, float>(500, 800), scroll);
	wormVec.push_back(w1);
	wormVec[0].SetSpriteTexture(cont.getTexture("chroboq"));
	wormVec[0].sprite.setScale(0.25, 0.25);
	////




    temp_nut.SetSpriteTexture(cont.getTexture("nut"));
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
    if(nut_amount < 1)
        return;

    nut_update(-1);

	WorkerSquirrel wo1(scroll);
	workSqrVec.push_back(wo1);
    workSqrVec[workSqrVec.size() - 1].SetSpriteTexture(cont.getTexture("wor_sqr"));
	workSqrVec[workSqrVec.size() - 1].sprite.setPosition(400, 2);
	workSqrVec[workSqrVec.size() - 1].sprite.setScale(0.7, 0.7);
}
void Game::spawnT()
{
    if(nut_amount < 3)
        return;

    nut_update(-3);

    WarriorSquirrel wo1(scroll, wormVec);
	warSqrVec.push_back(wo1);
    warSqrVec[warSqrVec.size() - 1].SetSpriteTexture(cont.getTexture("atk_sqr"));
	warSqrVec[warSqrVec.size() - 1].sprite.setPosition(400, 2);
	warSqrVec[warSqrVec.size() - 1].sprite.setScale(0.7, 0.7);
}
void Game::input()
{
    sf::Event ev;
    while(window.pollEvent(ev))
    {
        for(auto &atk: warSqrVec)
            atk.Input(ev);

		if (ev.type == sf::Event::KeyPressed)
		{
            if(ev.key.code == sf::Keyboard::Escape)
                window.close();
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

void Game::spawnWorm()
{
	Worm w1(std::pair<float, float>(500, 800), scroll);
	wormVec.push_back(w1);
	wormVec[wormVec.size() - 1].SetSpriteTexture(cont.getTexture("chroboq"));
	wormVec[wormVec.size() - 1].sprite.setScale(0.25, 0.25);
}

void Game::manageWarmSpawn()
{
	timeWormResp += wormClk.restart();
	
	if (freqOfSpawningWorms > 1 && gameTimeWorm.getElapsedTime().asSeconds() > 20)
	{
		freqOfSpawningWorms /= 1.5;
		gameTimeWorm.restart();
	}

	if (timeWormResp.asSeconds() > freqOfSpawningWorms)
	{
		spawnWorm();
		timeWormResp = sf::Time::Zero;
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
        int x = engine() % 600 + 100;
        int y = engine() % 100 + 2300;
        temp_nut.setPosition(sf::Vector2f(x,y));
        nuts.push_back(temp_nut);
    }
	for (auto & work : workSqrVec)
	{
		work.update(nuts);
	}

    for(auto & atk: warSqrVec)
    {
       atk.Update();
    }


	for (auto &worm : wormVec)
	{
		worm.update(workSqrVec, base);
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
            std::cout<<"ack"<<std::endl;
            nut_update(1);
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
			std::cout << "tt";
			iterToRem = iter;
		}
		++iter;
	}
	std::cout << std::endl;
	if (iterToRem > -1)
	{
		std::cout << " kill " << iterToRem << std::endl;
		std::cout << workSqrVec[iterToRem].HP;
		for (auto &worm : workSqrVec)
		{
			std::cout << "ID:" << worm.id << " HP:" << worm.HP << ":::";
		}

		workSqrVec.erase(workSqrVec.begin() + iterToRem);

		for (auto &worm : workSqrVec)
		{
			std::cout << "ID:"<<worm.id << " HP:" << worm.HP << ":::";
		}
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
	manageWarmSpawn();
	std::cout << base.HP << std::endl;
	if (base.HP <= 0)
	{
		std::cout << "YOU HAVE LOST!" << std::endl;
		system("pause");
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

    window.draw(wor_inst);
    window.draw(atk_inst);
    window.draw(nut);
    window.draw(nut_am);

   // e1.Draw(window);
    window.display();
}

void Game::nut_update(int i)
{
    nut_amount+=i;
    std::stringstream ss;
    ss<<nut_amount;
    nut_am.setString(ss.str());
}
