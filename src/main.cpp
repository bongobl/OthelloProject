#include <SFML/Graphics.hpp>
#include <iostream>
#include <StateManager.hpp>

using namespace std;
int main(void){


    sf::RenderWindow window(sf::VideoMode(1280, 860), "Othello", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(false);

    StateManager stateManager(window);
    stateManager.init();    /**Init*/
    sf::Clock clock;
    while(window.isOpen()){
        sf::Time deltaTime = clock.restart();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            stateManager.handleInput(event);    /**Handle Input*/
        }
        stateManager.update(deltaTime);     /**Update*/

        window.clear();
        stateManager.draw(window);      /**Draw*/
        window.display();
    }

    stateManager.dispose(); /**Dispose*/
    return EXIT_SUCCESS;

}
