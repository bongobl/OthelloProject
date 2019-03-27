#include <cmath>
#include "../include/CreditsState.hpp"

CreditsState::CreditsState(StateManager* m, sf::RenderWindow &win) : State(m,win){

}
void CreditsState::init(){

    /**wood background*/
    if(!woodTexture.loadFromFile("Resources/PlainWood.png")){
        cerr << "couldn't load plain wood texture" << endl;
        exit(-1);
    }
    background.setTexture(woodTexture);

    /**Text*/
    if(!creditsTexture.loadFromFile("Resources/CreditItems/AllCreditsText.png")){
        cerr << "couldn't load credits texture" << endl;
        exit(-1);
    }
    creditsSprite.setTexture(creditsTexture);

    /**back button*/
    if(!backButtonOff.loadFromFile("Resources/CreditItems/BackButtonOff.png")){
        cerr << "Couldn't load back button off texture" << endl;
        exit(-1);
    }
    if(!backButtonOn.loadFromFile("Resources/CreditItems/BackButtonOn.png")){
        cerr << "Couldn't load back button on texture" << endl;
        exit(-1);
    }
    backButton.setTexture(backButtonOff);
    backButton.setOrigin(640,430);
    backButton.setPosition(640,720);
    backButton.setScale(.7f,.7f);

    isOnBackButton = false;
}
void CreditsState::handleInput(sf::Event &event){
    if((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)){
        if(isOnBackButton){
            manager->getJukeBox().playSound(JukeBox::CLICK);
            manager->stateEnded(0,0,0);
            return;
        }
    }
}
void CreditsState::update(sf::Time &deltaTime){
    sf::Vector2f mousePosition = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);

    if(abs(mousePosition.x - backButton.getPosition().x) < 100 &&
       abs(mousePosition.y - backButton.getPosition().y) < 30){
        backButton.setTexture(backButtonOn);
        isOnBackButton = true;
    }else{
        backButton.setTexture(backButtonOff);
        isOnBackButton = false;
    }
}
void CreditsState::draw(sf::RenderWindow &window){
    window.draw(background);
    window.draw(creditsSprite);
    window.draw(backButton);
}
