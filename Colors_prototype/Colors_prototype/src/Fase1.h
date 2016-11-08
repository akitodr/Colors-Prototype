#pragma once

#include "ofMain.h"
#include "Fase.h"


class Fase1 : public Fase {
    private:
        bool switchLevel;

	public:
		void init();
        void interpolateColor (const ofVec3f& color);
        void onPortal();
        Screen* nextScreen();
};
