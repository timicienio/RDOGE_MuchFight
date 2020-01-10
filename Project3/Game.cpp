#include "Game.h"
#include "GameState.h"

//static functions

//initialize functions

void Game::initVariables()
{
    this->window = NULL;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow()
{
	
    /*cereate a sfml window using options from a window.init files*/
    std::ifstream ifs("Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "Hello World!";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }
    
    ifs.close();

    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasing_level;
    if(this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
        

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    
}

void Game::initKeys()
{
    
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("Left", sf::Keyboard::Key::Left);
    this->supportedKeys.emplace("Up", sf::Keyboard::Key::Up);
    this->supportedKeys.emplace("Down", sf::Keyboard::Key::Down);
    this->supportedKeys.emplace("Right", sf::Keyboard::Key::Right);
    

//DEBUG REMOVE LATER
    for (auto i : this->supportedKeys)
        std::cout << i.first << " " << i.second << "\n";

    std::cout << this->supportedKeys.at("A") << "\n";
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
//    this->states.push(new GameState(this->window, &this->supportedKeys));
}

//constructors/destructors
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
	delete [] window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


//functions
void Game::endApplication()
{
    std::cout << "ending application\n";

}

void Game::updateDt()
{
    /*updates the dt variable with the time it takes to update and render one frame.*/
    this->dt = this->dtClock.restart().asSeconds();
    if (dt > 1.f / 20.f) {
        dt = 1.f / 20.f;
    }

    //    system("cls");
    //    std::cout << this->dt << endl;
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
} 

void Game::render()
{
    this->window->clear();

    //render items
    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this-> dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //app end
    else
    {
        this->endApplication();
        this->window->close();


    }
}
