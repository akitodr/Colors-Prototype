#include "Fase1.h"

void Fase1::init() {
	background.load("img/cenario_cinza_2.jpg");
	camera.Init(ofVec2f(background.getWidth(), background.getHeight()));
	player.setup();

	for (int i = 0; i < 20; i++) {
		objects.push_back(new Circle());
	}

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] != nullptr)
			objects[i]->init();
	}
	player.setPosition(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
}

void Fase1::update(float secs, ofVec2f& mousePos, ofVec2f& mousePressedPos, bool mouseDown) {
	camera.Update(player.getPosition());
	player.update(secs);

	//interpolação de cor do objeto
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] && objects[i]->collided(&player)) {
			player.interpolateColor(objects[i]->color, 50);
			objects[i] = nullptr;
		}
	}

	//movimentando o player com o mouse clicado
	if (mouseDown) {
		player.setDirection(mousePos - mousePressedPos);
	}
	else {
		player.setDirection(ofVec2f());
	}
}

void Fase1::draw() {
	background.draw(-camera.getPosition());

	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]) { //se o circulo estiver ativo
			objects[i]->draw(camera.getPosition()); //desenha
		}
	}
	player.draw(camera.getPosition());
}
