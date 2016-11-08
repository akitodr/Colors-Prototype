//
//  Fase.h
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#ifndef Fase_h
#define Fase_h

#include "Screen.h"
#include "Camera.h"
#include "Collectibles.h"
#include "player.h"
#include "GameManager.hpp"

class Fase : public Screen{
    protected:
        Player* player;
        ofImage background;
        Camera camera;
        int indoOuVoltano = 0;
        ofVec3f backgroundColor;

    
    public:
        void update(float secs, const MouseInfo& mouse);
        void draw();
    
        virtual void onPortal() = 0;
        virtual void interpolateColor(const ofVec3f& color) = 0;
};


#endif /* Fase_h */
