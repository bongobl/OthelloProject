#include <sstream>
#include <cmath>
#include <StatState.hpp>

StatState::StatState(StateManager* m, sf::RenderWindow &win, int whiteChips, int blackChips) : State(m,win), whitePiece(Piece::WHITE) ,blackPiece(Piece::BLACK){
    this->whiteChips = whiteChips;
    this->blackChips = blackChips;

}

void StatState::init(){
    if(!woodTexture.loadFromFile("Resources/PlainWood.png")){
        cerr << "Couldn't load PlainWood.png" << endl;
        exit(-1);
    }
    woodSprite.setTexture(woodTexture);

    /**results*/
    if(!resultsTexture.loadFromFile("Resources/ResultsTexture.png")){
        cerr << "Couldn't load ResultsTexture" << endl;
        exit(-1);
    }
    resultsSprite.setTexture(resultsTexture);
    resultsSprite.move(0,-260);

    /**main menu button*/
    isOnMMButton = false;
    if(!mmButtonOff.loadFromFile("Resources/ToMainOff.png")){
        cerr << "couldn't load ToMainOff.png" << endl;
        exit(-1);
    }
    if(!mmButtonOn.loadFromFile("Resources/ToMainOn.png")){
        cerr << "couldn't load ToMainOn.png" << endl;
        exit(-1);
    }
    mainMenuButton.setTexture(mmButtonOff);
    mainMenuButton.setOrigin(640,430);
    mainMenuButton.setScale(.5f,.50f);
    mainMenuButton.setPosition(650,760);


    /**Text*/
    if(!simpleFont.loadFromFile("Resources/ArielFont/Arial.ttf")){
        exit(-1);
    }

    ostringstream stream1;
    stream1 << "Player 1 Score: " << whiteChips;
    player1Score.setString(stream1.str());
    player1Score.setFont(simpleFont);
    player1Score.setCharacterSize(51);
    player1Score.setStyle(sf::Text::Bold);
    player1Score.setFillColor(sf::Color::White);
    player1Score.setPosition(27, 210);

    ostringstream stream2;
    stream2 << "Player 2 Score: " <<blackChips;
    player2Score = player1Score;
    player2Score.setString(stream2.str());
    player2Score.setPosition(27,400);

    winner = player1Score;
    winner.setPosition(320,550);
    winner.setCharacterSize(100);
    if(whiteChips > blackChips)
        winner.setString("Player 1 Wins!!!");
    else if(whiteChips < blackChips)
        winner.setString("Player 2 Wins!!!");
    else{
        winner.setString("Tie!");
        winner.move(250,0);
    }


}
void StatState::handleInput(sf::Event &event){

    if((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && isOnMMButton){
        manager->getJukeBox().playSound(JukeBox::CLICK);
        manager->stateEnded(0,0,0);
    }
}
void StatState::update(sf::Time &deltaTime){
    sf::Vector2f mousePosition = sf::Vector2f((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);

    if(abs(mousePosition.x - mainMenuButton.getPosition().x) < 150 &&
       abs(mousePosition.y - mainMenuButton.getPosition().y) < 30){
        mainMenuButton.setTexture(mmButtonOn);
        isOnMMButton = true;
    }else{
        mainMenuButton.setTexture(mmButtonOff);
        isOnMMButton = false;
    }

}
void StatState::draw(sf::RenderWindow &window){

    window.draw(woodSprite);
    window.draw(resultsSprite);

    window.draw(player1Score);

    whitePiece.setPosition(27, 320);
    for(int i = 0; i < min(chipClock.getElapsedTime().asSeconds() * 15,(float)whiteChips); ++i){
        whitePiece.move(18,0);
        window.draw(whitePiece);
    }

    window.draw(player2Score);

    blackPiece.setPosition(27, 510);
    for(int i = 0; i < min(chipClock.getElapsedTime().asSeconds() * 15,(float)blackChips); ++i){
        blackPiece.move(18,0);
        window.draw(blackPiece);
    }

    window.draw(winner);
    window.draw(mainMenuButton);

}
