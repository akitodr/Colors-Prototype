#include "ScreenManager.h"

ScreenManager::ScreenManager(Screen& screen) {
	*current = screen;
}

void ScreenManager::update() {
	Screen* next = current->nextScreen();
	if (next != current) {
		next->init();
		delete current;
		current = next;
	}
}
