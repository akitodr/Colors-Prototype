#include "Fase1.h"
#include "GameManager.hpp"

void Fase1::init() {
    player = new Player();
    
	background.load("img/cenario_cinza_2.jpg");
	camera.Init(ofVec2f(background.getWidth(), background.getHeight()));

	for (int i = 0; i < 20; i++) {
        GAMEMANAGER.add(new Circle());
	}
    
    GAMEMANAGER.add(player);
	player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
}

void Fase1::update(float secs, const MouseInfo& mouse) {
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

void Fase1::draw() {
	background.draw(-camera.getPosition());
    GAMEMANAGER.draw(camera.getPosition());
}

Screen* Fase1::nextScreen() {
    return this;
}
