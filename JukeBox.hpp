#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
class JukeBox : public sf::Sound{

    sf::SoundBuffer clickSoundBuffer;
    sf::SoundBuffer pieceSoundBuffer;

public:

    enum soundSelect{CLICK,PIECE};
    JukeBox(){
        if(!clickSoundBuffer.loadFromFile("Resources/Audio/Click.wav")){
            cerr << "Couldn't load ClickSound" << endl;
            exit(-1);
        }

        if(!pieceSoundBuffer.loadFromFile("Resources/Audio/PlacePiece.wav")){
            cerr << "Couldn't load PieceSound" << endl;
            exit(-1);
        }


    }
    void playSound(int soundId){
        if(soundId == 0){
            setBuffer(clickSoundBuffer);
        }else if(soundId == 1){
            setBuffer(pieceSoundBuffer);
        }
        play();
    }
};
