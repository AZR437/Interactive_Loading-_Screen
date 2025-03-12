#include "Runner.h"
using namespace systems;
using namespace userinterface;
Runner* Runner::sharedInstance = NULL;
Runner::Runner():window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arquillo - Interactive Loading Screen",
    sf::Style::Default)
{
    sharedInstance = this;
    this->window.setFramerateLimit(FRAME_RATE);
    //load assets
    TextureManager::getInstance()->loadFromAssetList();
    SoundManager::getInstance()->loadLoadingScreenSFX();
    //bg
    Background* background = new Background("Background");
    GameObjectManager::getInstance()->addObject(background);
    //Loading Screen
    LoadingScreen* loadingScreen = new LoadingScreen("LoadingScreen", &this->window);
    GameObjectManager::getInstance()->addObject(loadingScreen);
    //images
    TexDisplay* display = new TexDisplay("TextureDisplay");
    GameObjectManager::getInstance()->addObject(display);
    //FPS
    FPSDisplay* fpsDisplay = new FPSDisplay("FPSDisplay");
    GameObjectManager::getInstance()->addObject(fpsDisplay);

    NextButton* nextButton = new NextButton("NextButton", &this->window);
    nextButton->setEnabled(false);
    GameObjectManager::getInstance()->addObject(nextButton);

   
}
void Runner::run()
{
    srand(time(0));
    sf::Clock clock;
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;
    while (this->window.isOpen())
    {
        currentTime = clock.getElapsedTime();
        float deltaTime = currentTime.asSeconds() - previousTime.asSeconds();
        this->fps = floor(1.0f / deltaTime);

        processEvents();
        update(sf::seconds(1.0f / this->fps));
        render();

        previousTime = currentTime;


    }
}

Runner* Runner::getInstance()
{
    return sharedInstance;
}

float Runner::getFPS() const
{
    return this->fps;
}

void Runner::processEvents()
{
    sf::Event event;
    if (this->window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {

            }
            break;
        case sf::Event::Closed:
            SoundManager::getInstance()->deleteAllSounds();
            this->window.close();
            break;
        default:
            GameObjectManager::getInstance()->processInput(event);
            break;
        }
    }
}

void Runner::update(sf::Time elapsedTime)
{
    GameObjectManager::getInstance()->update(elapsedTime);
}

void Runner::render()
{
    this->window.clear();
    GameObjectManager::getInstance()->draw(&this->window);
    this->window.display();
}








