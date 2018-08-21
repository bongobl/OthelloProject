#ifndef MAIN_MENU
#define MAIN_MENU
#include "State.hpp"
#include "Piece.hpp"
class MainMenuState : public State{

    sf::Texture woodTexture;
    sf::Sprite woodSprite;

    sf::Texture titleTexture;
    sf::Sprite title;

    sf::Texture playButtonTexture;
    sf::Sprite playButton;

    sf::Texture creditsButtonTexture;
    sf::Sprite creditsButton;

    sf::Texture quitButtonTexture;
    sf::Sprite quitButton;

    Piece cursor;
    Piece cursor2;

    bool onPlayButton;
    bool onCreditsButton;
    bool onQuitButton;

    bool hitQuit;
    sf::Clock waitToQuit;

public:

    enum menuItem{PLAY, CREDITS, QUIT};
    MainMenuState(StateManager* m, sf::RenderWindow &win);
    ~MainMenuState() {}

    void init();
    void handleInput(sf::Event &event);
    void update(sf::Time &deltaTime);
    void draw(sf::RenderWindow &window);

};

#endif // MAIN_MENU
