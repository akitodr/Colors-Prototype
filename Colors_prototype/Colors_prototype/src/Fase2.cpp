//
//  Fase2.cpp
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#include "Fase2.h"
#include "Fase1.h"

void Fase2::init() {
    GAMEMANAGER.clear();
    player = new Player();
    
    background.load("img/cenario_cinza_2.jpg");
    camera.Init(ofVec2f(background.getWidth(), background.getHeight()));
    backgroundColor = ofVec3f(150, 150, 255);
	sound.load("audio/blue_dance.wav");
	sound.play();
    
    for (int i = 0; i < 20; i++) {
        GAMEMANAGER.add(new Circle());
    }
    
    GAMEMANAGER.add(player);
    player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
}

void Fase2::interpolateColor(const ofVec3f& color){
    
    ofVec3f newColor = color;
    
    if(newColor.x >= 150 && newColor.y >= 150 && newColor.z >= 255)
    {
        indoOuVoltano = 0;
    }
    
    if(newColor.x <= 0 && newColor.y <= 0 && newColor.z <=150)
    {
        indoOuVoltano = 1;
    }
    
    if (indoOuVoltano == 0)
    {
        if(newColor.x >= 0 && newColor.y >= 0)
        {
            newColor.x -= 0.5;
            newColor.y -= 0.5;
        }
        else if(newColor.z >= 150)
        {
            newColor.z -= 0.5;
        }
    }
    else if(indoOuVoltano == 1)
    {
        if(newColor.z <= 255)
        {
            newColor.z += 0.5;
            
        }
        else if (newColor.x <= 150 && newColor.y <= 150)
        {
            newColor.x += 0.5;
            newColor.y += 0.5;
        }
        
    }
    
    
    backgroundColor = newColor;
}

void Fase2::onPortal(){
    switchLevel = true;
}


Screen* Fase2::nextScreen() {
    if (switchLevel) {
        return new Fase1();
    }
    return this;
}
