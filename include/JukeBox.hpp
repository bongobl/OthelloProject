#ifndef JUKE_BOX
#define JUKE_BOX

#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class JukeBox : public sf::Sound{

    sf::SoundBuffer clickSoundBuffer;
    sf::SoundBuffer pieceSoundBuffer;
    sf::SoundBuffer errorSoundBuffer;

public:

    enum soundSelect{CLICK,PIECE,ERROR};
    JukeBox();
    void playSound(int soundId);

};
#endif // JUKE_BOX
