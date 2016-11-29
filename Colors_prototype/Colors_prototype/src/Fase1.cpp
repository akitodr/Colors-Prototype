#include "Fase1.h"
#include "Fase2.h"
#include "Portal.h"
#include "Sprite.h"

void Fase1::init() {
	GAMEMANAGER.clear();
	player = new Player();
	switchLevel = false;

	background.load("img/background01.jpg");
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
	GAMEMANAGER.add(new Sprite(ofVec2f(9566, 185), "img/arvore3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 470), "img/rocha4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(background.getWidth() - 350, 570), "img/rocha5.png"));


	/*GAMEMANAGER.add(new Sprite(ofVec2f(500, 33), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(900, 76), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1300, 41), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(1700, 85), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2100, 39), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2500, 39), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2900, 76), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3300, 76), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3700, 41), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4100, 41), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4500, 76), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4900, 85), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5300, 39), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5700, 41), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6100, 39), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6500, 41), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6900, 39), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7300, 85), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7700, 85), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8100, 76), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8500, 76), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8900, 76), "img/nuvem2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9300, 41), "img/nuvem.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9700, 39), "img/nuvem2.png"));

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
	GAMEMANAGER.add(new Sprite(ofVec2f(1650, 720), "img/rocha2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2110, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2270, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2300, 680), "img/pedra.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2488, 400), "img/arvore4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2641, 500), "img/arvore1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2650, 680), "img/pedra2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2815, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2870, 788), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2915, 780), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(2955, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3000, 680), "img/pedra.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3320, 60), "img/tronco.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3160, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3160, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3320, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3480, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3640, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3800, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3960, 550), "img/pinheiros.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(3830, 720), "img/rocha.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4180, 720), "img/rocha3png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4300, 60), "img/tronco.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4450, 60), "img/tronco2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4520, 60), "img/tronco2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4530, 720), "img/rocha4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4880, 720), "img/rocha.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4150, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4180, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4290, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4320, 740), "img/flor4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4390, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4470, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(4500, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5110, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5100, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5200, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5210, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5300, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5310, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5400, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5500, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5530, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5543, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5653, 740), "img/flor.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5740, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5786, 780), "img/flor4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5793, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5819, 780), "img/flor4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5830, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5852, 780), "img/flor4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5870, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5929, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5959, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5980, 740), "img/flor2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6000, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6085, 720), "img/planta2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6205, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6290, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6300, 60), "img/tronco.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6700, 60), "img/tronco2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6820, 60), "img/tronco2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6140, 570), "img/arvore1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6295, 570), "img/arvore1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6450, 570), "img/arvore1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6450, 720), "img/planta2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6535, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6620, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6590, 440), "img/arvore2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6590, 720), "img/planta2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6675, 780), "img/planta2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6795, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6915, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(6900, 440), "img/arvore2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7150, 400), "img/arvore4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7150, 720), "img/planta2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7270, 780), "img/planta.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7365, 430), "img/arvore3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7555, 400), "img/arvore4.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7735, 680), "img/pedra.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7915, 680), "img/pedra2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(7940, 440), "img/arvore2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8095, 680), "img/pedra.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8200, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8255, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(5265, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8295, 700), "img/leao3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8350, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8390, 700), "img/leao3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8405, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8450, 780), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8455, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8510, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8555, 780), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8595, 700), "img/leao3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8630, 780), "img/flor3.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8660, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8705, 780), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8770, 780), "img/cogumelo.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8815, 780), "img/cogumelo2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8870, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8930, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(8990, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9050, 720), "img/leao.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9090, 720), "img/leao2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9130, 660), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9155, 720), "img/leao2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9210, 640), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9235, 720), "img/leao2.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9290, 620), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9350, 560), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9400, 500), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9460, 460), "img/leao1.png"));
	GAMEMANAGER.add(new Sprite(ofVec2f(9520, 400), "img/leao1.png"));*/
}

void Fase1::interpolateColor(const ofVec3f& color) {
	ofVec3f newColor = color;

	if (newColor.x >= 120 && newColor.y >= 210 && newColor.z >= 120) {
		indoOuVoltano = 0;
	}
	if (newColor.x <= 0 && newColor.y <= 120 && newColor.z <= 0) {
		indoOuVoltano = 1;
	}
	if (indoOuVoltano == 0) {
		if (newColor.x >= 0 && newColor.z >= 0) {
			newColor.x -= 0.5;
			newColor.z -= 0.5;
		}
		else if (newColor.y >= 120) {
			newColor.y -= 0.5;
		}
	}
	else if (indoOuVoltano == 1) {
		if (newColor.y <= 210) {
			newColor.y += 0.5;
		}
		else if (newColor.x <= 120 && newColor.z <= 120) {
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