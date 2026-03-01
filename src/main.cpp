#include "factories/LabFactory.h"
#include "graphics/Decart.h"
#include "graphics/Scene.h"
#include "graphics/render/SFMLRender.h"
#include "fstream/csv/Fcsv.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <iostream>

int main()
{
    for(int i = 1; i <= 3; ++i)
    {
        pl::Fcsv reader;

        std::shared_ptr<pl::LabToken> token;
        try {
            token = reader.read("data/raw-data"+std::to_string(i)+".csv");
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
        std::cout << "read successful " << i << std::endl;

        std::shared_ptr<LabStruct> lab = LabFactory::create(LabType::LAB2, token);
        std::cout << "create lab successful\n";

        lab->calculateLab();
        std::cout << "calculate lab successful\n";

        try {
            reader.write(lab->getToken(), "data/calc-data"+std::to_string(i)+".csv");
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
    pl::Fcsv reader;

    std::shared_ptr<pl::LabToken> token;
    try {
        token = reader.read("data/raw-data1.csv");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    std::cout << "read successful\n";

    /*sf::RenderWindow window(sf::VideoMode({640,800}),"TEST");

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color(100, 149, 237, 255));
        window.display();
    }*/

    pl::Scene scene;
    scene.render = std::make_shared<pl::SFMLRender>();
    scene.add(std::make_unique<pl::Decart>(token, "U", "I"));
    
    std::cout << "create window\n";
    scene.draw();
}
