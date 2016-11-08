#pragma once

#include "ofMain.h"
#include "Screen.h"

class ScreenManager {
	
	private:
		Screen* current;
        MouseInfo mouse;

	public:
        void init(Screen* first);
    
        void update();
        void draw();
    
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
};
