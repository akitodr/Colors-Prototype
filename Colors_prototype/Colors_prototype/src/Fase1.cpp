#include "Fase1.h"
#include "Fase2.h"
#include "Portal.h"

void Fase1::init() {
    GAMEMANAGER.clear();
    player = new Player();
    switchLevel = false;
    
	background.load("img/cenario_cinza_2.jpg");
	camera.Init(ofVec2f(background.getWidth(), background.getHeight()));

	for (int i = 0; i < 20; i++) {
        GAMEMANAGER.add(new Circle());
	}
    
    GAMEMANAGER.add(player);
	player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
    backgroundColor = ofVec3f(150, 255, 150);
    
    GAMEMANAGER.add(new Portal(this, ofVec2f(200,200)));
}

void Fase1::interpolateColor(const ofVec3f& color){
    ofVec3f newColor = color;
    
    if(newColor.x >= 150 && newColor.y >= 255 && newColor.z >= 150)
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
        if(newColor.y <= 255)
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
    cout << "Entrei!" << endl;
    switchLevel = true;
}

Screen* Fase1::nextScreen() {
    cout << "Entrei 2!" << endl;
    if (switchLevel) {
        return new Fase2();
    }
    return this;
}
