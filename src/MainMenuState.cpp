#include <cmath>
#include "../include/MainMenuState.hpp"
#include "iostream"
using namespace std;
MainMenuState::MainMenuState(StateManager* m, sf::RenderWindow &win) : State(m,win) , cursor(Piece::BLACK), cursor2(Piece::WHITE){

}

void MainMenuState::init(){

    if(!woodTexture.loadFromFile("Resources/PlainWood.png")){
        cerr << "Couldn't load wood texture" << endl;
        exit(-1);
    }
    woodSprite.setTexture(woodTexture);

    if(!titleTexture.loadFromFile("Resources/MenuItems/Title.png")){
        cerr << "Couldn't load title texture" << endl;
        exit(-1);
    }
    title.setTexture(titleTexture);
    title.setPosition(0,-220);

    /**Buttons*/
    onPlayButton = false;
    onQuitButton = false;
    if(!playButtonTexture.loadFromFile("Resources/MenuItems/PlayButton.png")){
        cerr << "Couldn't load play button texture" << endl;
        exit(-1);
    }
    playButton.setTexture(playButtonTexture);
    playButton.setOrigin(640,420);
    playButton.setPosition(640 ,420);


    if(!creditsButtonTexture.loadFromFile("Resources/MenuItems/CreditsButton.png")){
        cerr << "Couldn't load credits button texture" << endl;
        exit(-1);
    }
    creditsButton.setTexture(creditsButtonTexture);
    creditsButton.setOrigin(640,430);
    creditsButton.setPosition(640,550);
    creditsButton.setScale(.9f,.9f);



    if(!quitButtonTexture.loadFromFile("Resources/MenuItems/QuitButton.png")){
        cerr << "Couldn't load quit button texture" << endl;
        exit(-1);
    }
    quitButton.setTexture(quitButtonTexture);
    quitButton.setOrigin(640,420);
    quitButton.setPosition(640,690);

    /**cursor*/
    cursor.setPosition(460,410);

    hitQuit = false;

}
void MainMenuState::handleInput(sf::Event &event){
    if((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)){
        if(onPlayButton){
            manager->getJukeBox().playSound(JukeBox::CLICK);
            manager->stateEnded(PLAY, 0,0);
        }else if(onCreditsButton){
            manager->getJukeBox().playSound(JukeBox::CLICK);
            manager->stateEnded(CREDITS, 0,0);
        }else if(onQuitButton){
            hitQuit = true;
            waitToQuit.restart();
            manager->getJukeBox().playSound(JukeBox::CLICK);
        }
    }
}
void MainMenuState::update(sf::Time &deltaTime){

    sf::Vector2f mousePosition = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
    /**play button*/
    if(abs(mousePosition.x - playButton.getPosition().x) < 124 &&
       abs(mousePosition.y + 20 - playButton.getPosition().y) < 45){
        onPlayButton = true;
        playButton.setScale(1.1f,1.1f);
        cursor.setPosition(460, 410);
        cursor2.setPosition(820,410);
    }else{
        onPlayButton = false;
        playButton.setScale(1,1);
    }
    /**credits button*/
    if(abs(mousePosition.x - creditsButton.getPosition().x) < 124 &&
       abs(mousePosition.y - creditsButton.getPosition().y) < 45){
        onCreditsButton = true;
        creditsButton.setScale(1.1f,1.1f);
        cursor.setPosition(340, 550);
        cursor2.setPosition(940,550);
    }else{
        onCreditsButton = false;
        creditsButton.setScale(1,1);
    }

    /**quit button*/
    if(abs(mousePosition.x - quitButton.getPosition().x) < 124 &&
       abs(mousePosition.y + 20 - quitButton.getPosition().y) < 45){
        onQuitButton = true;
        quitButton.setScale(1.1f,1.1f);
        cursor.setPosition(460,690);
        cursor2.setPosition(820,690);
    }else{
        onQuitButton = false;
        quitButton.setScale(1,1);
    }

    sf::Time elapsed = waitToQuit.getElapsedTime();
    if(hitQuit && (elapsed.asSeconds() > .3)){
        manager->stateEnded(QUIT, 0,0);
    }

}
void MainMenuState::draw(sf::RenderWindow &window){


    window.draw(woodSprite);


    window.draw(title);
    window.draw(playButton);
    window.draw(creditsButton);
    window.draw(quitButton);

    if(onQuitButton || onCreditsButton || onPlayButton){
        window.draw(cursor);
        window.draw(cursor2);
    }

}
