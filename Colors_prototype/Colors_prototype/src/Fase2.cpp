//
//  Fase2.cpp
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#include "Fase2.h"
#include "Fase1.h"
#include "GameManager.h"
#include "Portal.h"
#include "Sprite.h"

void Fase2::init() {
    GAMEMANAGER.clear();
    player = new Player();
    switchLevel = false;
    
    background.load("img/backgroundmar.jpg");
    camera.Init(ofVec2f(background.getWidth(), background.getHeight()));
    sound.load("audio/valse_of_the_forest.wav");
    sound.play();
    sound.setLoop(true);
    backgroundColor = ofVec3f(150, 200, 150);
    
    for (int i = 0; i < 20; i++) {
        GAMEMANAGER.add(new Circle());
    }
    
    GAMEMANAGER.add(player);
    player->setPosition(ofVec2f(background.getWidth() / 7, background.getHeight() / 2));
    
    
    GAMEMANAGER.add(new Portal(this, ofVec2f(background.getWidth() - 80, 300), ofVec3f(0, 0, 255)));
    GAMEMANAGER.add(new Sprite(ofVec2f(9600, 445), "img/alga3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 470), "img/rocha4.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 570), "img/rocha5.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(20, 0), "img/bolha1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(230, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(340, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(445, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(490, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(540, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(635, 0), "img/alga6.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(40, 300), "img/peixe1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(260, 460), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(290, 470), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(325, 460), "img/bolha3.png"));
    
    
    GAMEMANAGER.add(new Sprite(ofVec2f(20, 700), "img/rocha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(20, 600), "img/alga3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(110, 600), "img/alga4.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(200, 600), "img/alga5.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(300, 500), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(430, 600), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(550, 500), "img/pedramar4.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(530, 600), "img/pedramar2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(550, 600), "img/pedramar2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(700, 400), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(750, 300), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(790, 300), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(900, 600), "img/pedramar.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1000, 480), "img/alga4.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1100, 480), "img/alga5.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1150, 420), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1190, 520), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1240, 490), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1350, 530), "img/alga2.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(1350, 100), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1550, 150), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(1800, 180), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2100, 600), "img/concha1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2500, 500), "img/peixe1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2760, 650), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2782, 500), "img/peixe.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(2600, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2710, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2755, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2795, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(2905, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(3010, 0), "img/alga6.png"));
    
    
    GAMEMANAGER.add(new Sprite(ofVec2f(3300, 0), "img/bolhas.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(3600, 0), "img/bolhas.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(3900, 0), "img/bolhas.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(3700, 710), "img/pedramar1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(3830, 600), "img/pedramar2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(4000, 600), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(3920, 710), "img/alga5.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(4000, 750), "img/pedramar3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(4800, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(4910, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5015, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5120, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5230, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5335, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5440, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5550, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5655, 630), "img/alga2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5100, 200), "img/peixe1.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(5700, 0), "img/bolha2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5900, 0), "img/peixe.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(5550, 630), "img/alga2.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(6100, 630), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6350, 700), "img/estrela.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6600, 630), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6600, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6645, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6690, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6730, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6770, 0), "img/alga1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6870, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(6980, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(7080, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(7190, 0), "img/alga6.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(7300, 250), "img/estrela.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(7450, 630), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(7640, 620), "img/concha1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(7950, 610), "img/concha.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(8085, 600), "img/concha1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(8085, 100), "img/peixe1.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(8345, 120), "img/peixe2.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(8545, 140), "img/peixe3.png"));
    
    GAMEMANAGER.add(new Sprite(ofVec2f(8600, 600), "img/pedramar.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(9265, 590), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(9290, 570), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(9315, 550), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(9340, 530), "img/bolha3.png"));
    GAMEMANAGER.add(new Sprite(ofVec2f(9365, 510), "img/bolha3.png"));
    
    
    
    
    
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
