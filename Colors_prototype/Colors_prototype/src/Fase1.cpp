#include "Fase1.h"
#include "Fase2.h"
#include "Portal.h"
#include "Sprite.h"

void Fase1::init() {
    GAMEMANAGER.clear();
    player = new Player();
    switchLevel = false;
    
	background.load("img/background.jpg");
	camera.Init(ofVec2f(background.getWidth(), background.getHeight()));
	sound.load("audio/valse_of_the_forest.wav");
    sound.play();

	for (int i = 0; i < 20; i++) {
        GAMEMANAGER.add(new Circle());
	}
    
    GAMEMANAGER.add(player);
	player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
    backgroundColor = ofVec3f(150, 200, 150);
    
    GAMEMANAGER.add(new Portal(this, ofVec2f(200,400), ofVec3f(0, 0, 255)));
    GAMEMANAGER.add(new Sprite(ofVec2f(200,200), "img/nuvem.png"));
}

void Fase1::interpolateColor(const ofVec3f& color){
    ofVec3f newColor = color;
    
    if(newColor.x >= 150 && newColor.y >= 200 && newColor.z >= 150)
    {
        indoOuVoltano = 0;
    }
    
    if(newColor.x <= 0 && newColor.y <= 150 && newColor.z <=0)
    {
        indoOuVoltano = 1;
    }
    
    if (indoOuVoltano == 0)
    {
        if(newColor.x >= 0 && newColor.z >= 0)
        {
            newColor.x -= 0.5;
            newColor.z -= 0.5;
        }
        else if(newColor.y >= 150)
        {
            newColor.y -= 0.5;
        }
    }
    else if(indoOuVoltano == 1)
    {
        if(newColor.y <= 200)
        {
            newColor.y += 0.5;
            
        }
        else if (newColor.x <= 150 && newColor.z <= 150)
        {
            newColor.x += 0.5;
            newColor.z += 0.5;
        }
        
    }
    backgroundColor = newColor;
}

void Fase1::onPortal(){
    switchLevel = true;
}

Screen* Fase1::nextScreen() {
    if (switchLevel) {
		sound.stop();
        return new Fase2();
    }
    return this;
}
