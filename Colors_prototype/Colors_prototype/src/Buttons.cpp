#include "Buttons.h"

Button::Button(const ofVec2f& pos, string clicked, string notClicked) { //construtor
	//da load nas parada
	//cria um botão com todos esses parâmetros
	position = pos;
	colorNotClicked.load(notClicked);
	colorClicked.load(clicked);
	//this->sound.load(sound);
	IsClicked = false;
}

const bool Button::Check(const ofVec2f& posMouse) const {//checa colisão do mouse com o botão
	return (posMouse.x > position.x && posMouse.x < (position.x + SIZEX)
		&& posMouse.y > position.y && posMouse.y < (position.y + SIZEY));

}

bool Button::SetClick() {
	IsClicked = !IsClicked;
	return IsClicked;
}

void Button::Update() {
	if (IsClicked) {
		//se tiver tocando não vai tocar de novo
		return;
	}
	//se não tiver tocando aí toca
	//sound.play();
	IsClicked = true;
	clickTime = 0;
}

void Button::Update(float secs) {
	if (IsClicked) {
		clickTime += secs;
		//a cada 4 segundos o botão "desliga"
		if (clickTime > 0.6) {
			IsClicked = false;
			//sound.stop();
		}
	}
}

void Button::Draw() const {
	if (!IsClicked) {
		colorClicked.draw(position.x, position.y);
	}
	else {
		colorNotClicked.draw(position.x, position.y);
	}
}

Button::~Button() {

}