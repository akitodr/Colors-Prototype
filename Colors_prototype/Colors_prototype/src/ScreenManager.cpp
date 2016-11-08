#include "ScreenManager.h"

void ScreenManager::init(Screen* first) {
    current = first;
    current->init();
}

void ScreenManager::update() {
	Screen* next = current->nextScreen();
	if (next != current) {
		next->init();
		delete current;
		current = next;
	}
    current->update(ofGetLastFrameTime(), mouse);
}

void ScreenManager::draw() {
    current->draw();
}


void ScreenManager::mouseMoved(int x, int y )
{
    mouse.pos.set(x, y);
}

void ScreenManager::mouseDragged(int x, int y, int button)
{
    mouse.pos.set(x, y);
}

void ScreenManager::mousePressed(int x, int y, int button)
{
    mouse.pressedPos.set(x, y);
    mouse.pos.set(x, y);
    mouse.clicked = true;
}

void ScreenManager::mouseReleased(int x, int y, int button)
{
    mouse.clicked = false;
}
