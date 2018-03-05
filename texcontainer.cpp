#include "texcontainer.h"

TexContainer::TexContainer()
{

}

void TexContainer::loadFromFile(std::string dir)
{
    std::fstream file;
    file.open(dir, std::ios::in);
    assert(file.good());
    std::cout<<"loading textures from: "<<dir<<std::endl;

    do
    {
        std::string file_dir, name;
        file>>file_dir>>name;
        //std::cout<<file_dir<<" "<<name<<std::endl;
        if(file.eof())
            break;

        sf::Texture temp;
        //assert(temp.loadFromFile(file_dir));
		if (!temp.loadFromFile(file_dir))
		{
			std::cout << "not loaded: " + file_dir << std::endl;
		}
        texs.push_back(temp);
        names[name] = texs.size()-1;
    }while(true);

}

sf::Texture &TexContainer::getTexture(std::string name)
{
    assert(names.find(name) != names.end());
    return texs.at(names[name]);
}
