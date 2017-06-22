#include "PlayState.hpp"

#include <cmath>

float getDistance(sf::Vector2f v1, sf::Vector2f v2){

    sf::Vector2f result = v1 - v2;
    return sqrt(result.x * result.x +  result.y * result.y);

}

PlayState::PlayState(StateManager* m, sf::RenderWindow &win) : State(m,win), cursorPiece(Piece::BLACK) {

}
void PlayState::init(){

    /**Title Text*/
    if(!titleTexture.loadFromFile("Resources/SilverTitleText.png")){
            cerr << "Couldn't load file" << endl;
            exit(-1);
    }
    title.setTexture(titleTexture);
    title.setScale(.37f,.37f);
    title.setPosition(-14.f,-70.f);


    /**Initial Pieces*/
    othelloBoard.insertPiece(3,3,Piece::WHITE);
    othelloBoard.insertPiece(3,4,Piece::BLACK);
    othelloBoard.insertPiece(4,3,Piece::BLACK);
    othelloBoard.insertPiece(4,4,Piece::WHITE);

    turn = Piece::WHITE;
    cursorPiece.setType(turn);
    turnsLeft = 60;

    /**PlayerText*/
    if(!simpleFont.loadFromFile("Resources/ArielFont/Arial.ttf")){
        exit(-1);
    }

    currPlayerText.setString("Your move, \nPlayer 1...");
    currPlayerText.setFont(simpleFont);
    currPlayerText.setCharacterSize(51);
    currPlayerText.setStyle(sf::Text::Bold);
    currPlayerText.setFillColor(sf::Color::White);
    currPlayerText.setPosition(27, 300);

    /**quit button*/
    if(!quitButtonOff.loadFromFile("Resources/EndGameTexture.png")){
        cerr << "Couldn't load EndGameTexture.png" << endl;
            exit(-1);
    }
    if(!quitButtonOn.loadFromFile("Resources/EndGameTexture2.png")){
        cerr << "Couldn't load EndGameTexture2.png" << endl;
            exit(-1);
    }
    quitButtonSprite.setOrigin(640,430);
    quitButtonSprite.setPosition(210,700);
    quitButtonSprite.setScale(.5,.5);

    quitButtonSprite.setTexture(quitButtonOff);



}
void PlayState::handleInput(sf::Event &event){

    if((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)){

        if(isOnQuitButton){
            manager->getJukeBox().playSound(JukeBox::CLICK);
            this->dispose();
            return;
        }
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(  getDistance( othelloBoard.slotAt(i,j).getPosition() ,  cursorPiece.getPosition()) < 30 && othelloBoard.slotAt(i,j).isEmpty() ){

                    //insert piece
                    othelloBoard.insertPiece(i,j,turn);

                    //check for flanks
                    if(!othelloBoard.flankPieces(i,j)){
                        othelloBoard.slotAt(i,j).removePiece();
                        break;
                    }
                    manager->getJukeBox().playSound(1);

                    //switch turns
                    if(turn == Piece::WHITE){
                        turn = Piece::BLACK;
                        currPlayerText.setString("Your move, \nPlayer 2...");
                        currPlayerText.setFillColor(sf::Color::Black);
                    }else{
                        turn = Piece::WHITE;
                        currPlayerText.setString("Your move, \nPlayer 1...");
                        currPlayerText.setFillColor(sf::Color::White);
                    }
                    cursorPiece.setType(turn);


                    //update turn left
                    --turnsLeft;

                    //check for finished game
                    if(turnsLeft == 0){
                        currPlayerText.setString("Game Over!");
                        endClock.restart();
                    }
                    break;
                }

            }
        }

    }
}
void PlayState::update(sf::Time &deltaTime){

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    cursorPiece.setPosition(mousePosition.x, mousePosition.y);
    sf::Time timeAfterEnd = endClock.getElapsedTime();


    if(timeAfterEnd.asSeconds() >= 2 && turnsLeft == 0){
        this->dispose();
        return;
    }
    if(abs(cursorPiece.getPosition().x - quitButtonSprite.getPosition().x) < 100  &&
       abs(cursorPiece.getPosition().y - quitButtonSprite.getPosition().y) < 60){
        quitButtonSprite.setTexture(quitButtonOn);
        isOnQuitButton = true;
    }else{
        quitButtonSprite.setTexture(quitButtonOff);
        isOnQuitButton = false;
    }
}
void PlayState::draw(sf::RenderWindow &window){

    this->window.draw(othelloBoard);
    this->window.draw(cursorPiece);


    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            //window.draw(othelloBoard.slotAt(i, j));
            if(!othelloBoard.slotAt(i, j).isEmpty()){
                window.draw(othelloBoard.slotAt(i,j).getPiece());
            }
        }
    }
    this->window.draw(title);
    this->window.draw(currPlayerText);
    this->window.draw(quitButtonSprite);

}

void PlayState::dispose(){

        int numBlacks = 0;
        int numWhites = 0;
        //count pieces
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(!othelloBoard.slotAt(i,j).isEmpty()){
                    if(othelloBoard.slotAt(i,j).getPiece().getType() == Piece::BLACK){
                        ++numBlacks;
                    }else{
                        ++numWhites;
                    }
                }
            }
        }

        //exit state
        manager->stateEnded(numWhites, numBlacks, 0);
}



