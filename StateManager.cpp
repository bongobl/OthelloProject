#include "StateManager.hpp"
#include "States/MainMenuState.hpp"
#include "States/PlayState.hpp"
#include "States/StatState.hpp"
#include "States/CreditsState.hpp"

#include <typeinfo>
StateManager::StateManager(sf::RenderWindow &win) : window(win){

}
void StateManager::init(){


    currState = new MainMenuState(this,window);
    currState->init();

    if(!backgroundMusic.openFromFile("Resources/Audio/Guitar_western_blues.wav")){
        cerr << "Couldn't load music" << endl;
        exit(-1);
    }
    backgroundMusic.setVolume(20);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

}
void StateManager::handleInput(sf::Event &event){


    currState->handleInput(event);
}

void StateManager::update(sf::Time &deltaTime){

    currState->update(deltaTime);
}

void StateManager::draw(sf::RenderWindow &window){

    currState->draw(window);

}

void StateManager::dispose(){
    backgroundMusic.stop();
    delete currState;
}

void StateManager::stateEnded(int d1, int d2, int d3){

    if(typeid(*currState) == typeid(PlayState)){
        delete currState;
        currState = new StatState(this,window,d1,d2);
        currState->init();
    }else if(typeid(*currState) == typeid(StatState)){
        delete currState;
        currState = new MainMenuState(this,window);
        currState->init();
    }else if(typeid(*currState) == typeid(MainMenuState)){

        if(d1 == MainMenuState::PLAY){
            delete currState;
            currState = new PlayState(this,window);
            currState->init();
        }else if(d1 == MainMenuState::CREDITS){
            delete currState;
            currState = new CreditsState(this,window);
            currState->init();
        }else if(d1 == MainMenuState::QUIT){
            window.close();
        }
    }else if(typeid(*currState) == typeid(CreditsState)){
        delete currState;
        currState = new MainMenuState(this,window);
        currState->init();
    }

}

JukeBox& StateManager::getJukeBox(){
    return jukeBox;
}
