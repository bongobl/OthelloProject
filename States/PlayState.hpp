#ifndef PLAY_STATE
#define PLAY_STATE
#include "State.hpp"
#include "../GameObjects/Board.hpp"
#include "../GameObjects/Piece.hpp"
#include "../GameObjects/Slot.hpp"


class PlayState : public State{

    Board othelloBoard;
    Piece cursorPiece;

    sf::Texture titleTexture;
    sf::Sprite title;

    sf::Font simpleFont;
    sf::Text currPlayerText;


    int turn;
    int turnsLeft;

    sf::Clock endClock;

    sf::Texture quitButtonOff;
    sf::Texture quitButtonOn;
    sf::Sprite quitButtonSprite;

    int isOnQuitButton;



public:
    PlayState(StateManager* m, sf::RenderWindow &win);

    ~PlayState() {}

    void init();
    void handleInput(sf::Event &event);
    void update(sf::Time &deltaTime);
    void draw(sf::RenderWindow &window);
    void dispose();

};

#endif // PLAY_STATE
