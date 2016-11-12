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
	sound.setLoop(true);
	backgroundColor = ofVec3f(150, 200, 150);

	for (int i = 0; i < 20; i++) {
		GAMEMANAGER.add(new Circle());
	}

	GAMEMANAGER.add(player);
	player->setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
	

	GAMEMANAGER.add(new Portal(this, ofVec2f(background.getWidth() - 80, 300), ofVec3f(0, 0, 255)));
	GAMEMANAGER.add(new Sprite(ofVec2f(2130, 185), "img/arvore3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 470), "img/rocha4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 570), "img/rocha5.png"));

	
	GAMEMANAGER.add(new Sprite(ofVec2f(500, 33), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(900, 76), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1300, 41), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1700, 85), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2100, 39), "img/nuvem2.png"));
	
	GAMEMANAGER.add(new Sprite(ofVec2f(70, 0), "img/tronco.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(155, 500), "img/pinheiros.png"));
	
	GAMEMANAGER.add(new Sprite(ofVec2f(0, 700), "img/rocha.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(395, 300), "img/arvore4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(250, 700), "img/rocha2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(520, 700), "img/rocha3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(860, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1210, 0), "img/tronco2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1430, 320), "img/arvore2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1160, 700), "img/rocha3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1020, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1950, 680), "img/pedra.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1550, 680), "img/pedra2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1460, 680), "img/pedra.png"));
	

}

void Fase1::interpolateColor(const ofVec3f& color) {
	ofVec3f newColor = color;

	if (newColor.x >= 120 && newColor.y >= 210 && newColor.z >= 120)
	{
		indoOuVoltano = 0;
	}

	if (newColor.x <= 0 && newColor.y <= 120 && newColor.z <= 0)
	{
		indoOuVoltano = 1;
	}

	if (indoOuVoltano == 0)
	{
		if (newColor.x >= 0 && newColor.z >= 0)
		{
			newColor.x -= 0.5;
			newColor.z -= 0.5;
		}
		else if (newColor.y >= 120)
		{
			newColor.y -= 0.5;
		}
	}
	else if (indoOuVoltano == 1)
	{
		if (newColor.y <= 210)
		{
			newColor.y += 0.5;

		}
		else if (newColor.x <= 120 && newColor.z <= 120)
		{
			newColor.x += 0.5;
			newColor.z += 0.5;
		}

	}
	backgroundColor = newColor;
}

void Fase1::onPortal() {
	switchLevel = true;
}

Screen* Fase1::nextScreen() {
	if (switchLevel) {
		sound.stop();
		return new Fase2();
	}
	return this;
}