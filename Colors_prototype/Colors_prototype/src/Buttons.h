#pragma once
#include "ofApp.h"
#include "ofSoundPlayer.h"

#include <string>

#define SIZEX 156
#define SIZEY 120

class Button {

private:

	ofVec2f position;
	ofImage colorNotClicked;
	ofImage colorClicked;
	ofSoundPlayer sound;
	float clickTime = 0;
	bool IsClicked;

public: 

	Button(const ofVec2f& pos, string clicked, string notClicked);
	const bool Check(const ofVec2f& posMouse) const;
	bool SetClick();
	void Update(float secs);
	void Draw() const;
	void Update();
	~Button();


};
