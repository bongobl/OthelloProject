#ifndef STATE_MANAGER
#define STATE_MANAGER

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <State.hpp>
#include <JukeBox.hpp>

class State;
class StateManager {

    State* currState;

    sf::RenderWindow &window;

    JukeBox jukeBox;
    sf::Music backgroundMusic;
public:

    StateManager(sf::RenderWindow &win);
    void init();
    void handleInput(sf::Event &event);
    void update(sf::Time &deltaTime);
    void draw(sf::RenderWindow &window);
    void dispose();

    JukeBox& getJukeBox();

    //upcall
    void stateEnded(int d1, int d2, int d3);

};



#endif // STATE_MANAGER


