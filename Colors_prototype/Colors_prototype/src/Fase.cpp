//
//  Fase.cpp
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#include "Fase.h"

void Fase::update(float secs, const MouseInfo& mouse){
    camera.Update(player->getPosition());
    
    //movimentando o player com o mouse clicado
    if (mouse.clicked) {
        player->setDirection(mouse.pos - mouse.pressedPos);
    }
    else {
        player->setDirection(ofVec2f());
    }
    GAMEMANAGER.update(secs);
}

void Fase::draw(){
    interpolateColor(backgroundColor);
    ofSetColor(backgroundColor.x, backgroundColor.y, backgroundColor.z);
    background.draw(-camera.getPosition());
    GAMEMANAGER.draw(camera.getPosition());
}



