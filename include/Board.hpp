#ifndef BOARD
#define BOARD
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Slot.hpp"
using namespace std;


class Board : public sf::Sprite {
    sf::Texture boardTexture;
    Slot allSlots[8][8];
public:



    Board(){

        if(!boardTexture.loadFromFile("Resources/OthelloBoard.png")){
            cerr << "Couldn't load file" << endl;
            exit(-1);
        }
        setTexture(boardTexture);

        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                allSlots[i][j].setPosition( 497 + 95.5f * i,85 + 95.5f * j);
            }

        }
    }

    Slot& slotAt(int x, int y){
        return allSlots[x][y];
    }

    bool insertPiece(int x, int y, int type){

        return allSlots[x][y].setPiece(type);
    }

    bool flankPieces(const int x, const int y){

        bool hasFlanks = false;

        int type = allSlots[x][y].getPiece().getType();
        vector<Piece*> flanks;
        int currX = x;
        int currY = y;
        bool shouldFlank;



        /**Traverse up*/
        shouldFlank = false;
        --currY;
        while(currY >= 0){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            --currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse up-right*/
        currX = x;
        currY = y;
        shouldFlank = false;
        ++currX;
        --currY;
        while(currX <= 7 && currY >= 0){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            ++currX;
            --currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse right*/
        currX = x;
        currY = y;
        shouldFlank = false;
        ++currX;
        while(currX <= 7){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            ++currX;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse down-right*/
        currX = x;
        currY = y;
        shouldFlank = false;
        ++currX;
        ++currY;
        while(currX <= 7 && currY <= 7){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            ++currX;
            ++currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse down*/
        currX = x;
        currY = y;
        shouldFlank = false;
        ++currY;
        while(currY <= 7){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            ++currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse down-left*/

        currX = x;
        currY = y;
        shouldFlank = false;
        --currX;
        ++currY;
        while(currX >= 0 && currY <= 7){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            --currX;
            ++currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse left*/
        currX = x;
        currY = y;
        shouldFlank = false;
        --currX;
        while(currX >= 0){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            --currX;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        /**Traverse up-left*/

        currX = x;
        currY = y;
        shouldFlank = false;
        --currX;
        --currY;
        while(currX >= 0 && currY >= 0){
            if(allSlots[currX][currY].isEmpty())
                break;
            else if(allSlots[currX][currY].getPiece().getType() != type){
                flanks.push_back(allSlots[currX][currY].addressOfPiece());
            }else if(allSlots[currX][currY].getPiece().getType() == type){
                shouldFlank = true;
                break;
            }
            --currX;
            --currY;
        }

        if(shouldFlank){
            for(vector<Piece*>::iterator iter = flanks.begin(); iter < flanks.end(); ++iter){
                (*iter)->setType(type);
                hasFlanks = true;
            }
        }
        flanks.clear();

        return hasFlanks;
    }
};
#endif // BOARD
