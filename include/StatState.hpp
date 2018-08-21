#ifndef STAT_STATE
#define STAT_STATE
#include "State.hpp"
#include "Piece.hpp"


class StatState : public State{

    int whiteChips;
    int blackChips;

    sf::Texture resultsTexture;
    sf::Sprite resultsSprite;

    sf::Texture woodTexture;
    sf::Sprite woodSprite;

    sf::Font simpleFont;
    sf::Text player1Score;
    sf::Text player2Score;

    sf::Text winner;

    Piece whitePiece;
    Piece blackPiece;

    sf::Clock chipClock;

    sf::Texture mmButtonOff;
    sf::Texture mmButtonOn;
    sf::Sprite mainMenuButton;

    bool isOnMMButton;



public:

    StatState(StateManager* m, sf::RenderWindow &win, int whiteChips, int blackChips);
    ~StatState(){ }

    void init();
    void handleInput(sf::Event &event);
    void update(sf::Time &deltaTime);
    void draw(sf::RenderWindow &window);

};
#endif // STAT_STATE
