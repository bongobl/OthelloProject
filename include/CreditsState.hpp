#ifndef CREDITS_STATE
#define CREDITS_STATE
#include "State.hpp"
class CreditsState : public State{

    sf::Texture woodTexture;
    sf::Sprite background;

    sf::Texture creditsTexture;
    sf::Sprite creditsSprite;

    sf::Texture backButtonOff;
    sf::Texture backButtonOn;
    sf::Sprite backButton;

    bool isOnBackButton;
public:

    CreditsState(StateManager* m, sf::RenderWindow &win);
    ~CreditsState() {}

    void init();
    void handleInput(sf::Event &event);
    void update(sf::Time &deltaTime);
    void draw(sf::RenderWindow &window);
};
#endif // CREDITS_STATE
