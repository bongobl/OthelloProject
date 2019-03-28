#ifndef SLOT
#define SLOT
#include <Piece.hpp>
class Slot : public sf::CircleShape{
    Piece* slotPiece;

public:
    Slot(){
        slotPiece = NULL;

        setRadius(10.f);
        setFillColor(sf::Color::Black);
        setOrigin(5.f,5.f);


    }
    ~Slot(){
        if(slotPiece != NULL)
            delete slotPiece;
    }

    bool setPiece(int type){

        if(!isEmpty()){
            return false;
        }
        slotPiece = new Piece(type);
        slotPiece->setPosition(getPosition() + sf::Vector2f(4.f,4.f));

        return true;
    }

    void removePiece(){
        if(isEmpty()){
            return;
        }
        delete slotPiece;
        slotPiece = NULL;
    }

    bool isEmpty() const{
        return slotPiece == NULL;
    }

    const Piece& getPiece() const{
        return *slotPiece;
    }
    Piece* addressOfPiece(){
        return slotPiece;
    }

};
#endif // SLOT
