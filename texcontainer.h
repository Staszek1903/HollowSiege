#ifndef TEXCONTAINER_H
#define TEXCONTAINER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <assert.h>

class TexContainer
{
    std::vector <sf::Texture> texs;
    std::map <std::string, int> names;

public:
    TexContainer();
    void loadFromFile(std::string dir);
    sf::Texture& getTexture(std::string name);
};

#endif // TEXCONTAINER_H
