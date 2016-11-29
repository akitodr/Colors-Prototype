//
//  Fase.cpp
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#include "Fase.h"


ofVec2f Fase::convertPoint(ofVec2f from, ofVec2f to, ofVec2f position)
{
	//Essa fun��o pega como par�metros o sistema de coordenadas para onde se est�, o para onde se quer converter e o ponto a se converter. Ele faz tudo isso magicamente, at� explicaria como funciona, mas eu n�o lembro.
	ofVec2f aux = ofVec2f(to.x / (from.x / position.x), to.y / (from.y / position.y));

	return aux;
}

void Fase::update(float secs, const MouseInfo& mouse){
    camera.Update(player->getPosition());
    
	player->setPosition(convertPoint(ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(background.getWidth(), background.getHeight()), mouse.pos));

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
	background2.draw(background.getWidth() - camera.getPosition());
    GAMEMANAGER.draw(camera.getPosition());
}



