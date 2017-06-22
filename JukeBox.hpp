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
            cerr << "Couldn't load BoardSound" << endl;
            exit(-1);
        }

        if(!pieceSoundBuffer.loadFromFile("Resources/Audio/PlacePiece.wav")){
            cerr << "Couldn't load BoardSound" << endl;
            exit(-1);
        }

    }
    void playSound(int soundId){
        if(soundId == CLICK){
            setBuffer(clickSoundBuffer);
        }else if(soundId == PIECE){
            setBuffer(pieceSoundBuffer);
        }
        play();
    }
};
