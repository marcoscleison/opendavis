#include "opendavis/ui/application.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <functional>
using namespace opendavis::ui;

class Application::impl
{
public:
    impl()
    {
        this->window.create(sf::VideoMode(this->width, this->height), "OpenDaVis");
    }
    ~impl()
    {
    }
    
    void run()
    {
        while (window.isOpen())
        {
     
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);


            window.display();
        }
    }

private:
    sf::RenderWindow window;
    int width = 800;
    int height = 600;
};

Application::Application() : pimpl(std::make_unique<Application::impl>())
{
}

Application::~Application() = default;
Application::Application(Application &&) = default;
Application &Application::operator=(Application &&) = default;

void Application::run()
{
    this->pimpl->run();
}

void Application::addDom(Dom::Ptr dom){
    this->docs.push_back(dom);
}