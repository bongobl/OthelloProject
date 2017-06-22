#ifndef PIECE
#define PIECE
#include <iostream>
using namespace std;

class Piece : public sf::Sprite{

    int type;
    sf::Texture pieceTexture;


public:


    enum Type{WHITE, BLACK};
    Piece(int type){

        this->type = type;
        if(type == WHITE){
            if(!pieceTexture.loadFromFile("Resources/WhitePiece.png")){
                cerr << "Couldn't load file" << endl;
                exit(-1);
            }

        }else{
            if(!pieceTexture.loadFromFile("Resources/BlackPiece.png")){
                cerr << "Couldn't load file" << endl;
                exit(-1);
            }
        }
        setTexture(pieceTexture);
        setOrigin(640,430);
    }

    void setType(int type){

        this->type = type;
        if(this->type == WHITE){
            if(!pieceTexture.loadFromFile("Resources/WhitePiece.png")){
                cerr << "Couldn't load file" << endl;
                exit(-1);
            }

        }else{
            if(!pieceTexture.loadFromFile("Resources/BlackPiece.png")){
                cerr << "Couldn't load file" << endl;
                exit(-1);
            }
        }
        setTexture(pieceTexture);
    }

    int getType() const{
        return type;
    }


};
#endif // PIECE
