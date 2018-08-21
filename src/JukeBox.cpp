#include "../include/JukeBox.hpp"
JukeBox::JukeBox(){
    if(!clickSoundBuffer.loadFromFile("Resources/Audio/Click.wav")){
        cerr << "Couldn't load ClickSound" << endl;
        exit(-1);
    }

    if(!pieceSoundBuffer.loadFromFile("Resources/Audio/PlacePiece.wav")){
        cerr << "Couldn't load PieceSound" << endl;
        exit(-1);
    }

    if(!errorSoundBuffer.loadFromFile("Resources/Audio/ErrorSound.wav")){
        cerr << "Couldn't load ErrorSound" << endl;
        exit(-1);
    }

}

void JukeBox::playSound(int soundId){
    setVolume(100);
    if(soundId == CLICK){
        setBuffer(clickSoundBuffer);
    }else if(soundId == PIECE){
        setBuffer(pieceSoundBuffer);
    }else if(soundId == ERROR){
        setVolume(20);
        setBuffer(errorSoundBuffer);
    }
    play();
}

