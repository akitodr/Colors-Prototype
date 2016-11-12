//
//  Sprite.h
//  colors
//
//  Created by BEPID on 11/11/16.
//
//

#ifndef Sprite_h
#define Sprite_h

#include "GameObject.h"
#include <string>

class Sprite : public GameObject {
private:
	ofVec2f position;
	ofImage image;
public:
	Sprite(const ofVec2f& pos, std::string img);
	void init();
	bool isAlive() const;
	void draw(const ofVec2f& camera);
	void update(float secs);
	ofRectangle bounds();
	void collidedWith(GameObject* other);

};


#endif /* Sprite_h */