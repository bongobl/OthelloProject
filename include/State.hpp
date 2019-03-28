#ifndef STATE
#define STATE
#include <StateManager.hpp>

class StateManager;
class State{

protected:
    StateManager* manager;

    sf::RenderWindow &window;

    State(StateManager* m, sf::RenderWindow &win) : window(win) {manager = m;}
public:


    virtual ~State(){}

    virtual void init() = 0;
    virtual void handleInput(sf::Event &event) = 0;
    virtual void update(sf::Time &deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};
#endif // STATE
