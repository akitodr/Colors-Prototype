//
//  Portal.h
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#ifndef Portal_h
#define Portal_h

#include "GameObject.h"
#include "ofMain.h"
#include "Fase.h"

class Portal : public GameObject{
    private:
        ofImage image;
        Fase* fase;
        ofVec2f position;
        ofVec3f color;
    
    public:
        Portal(Fase* level, const ofVec2f& pos, const ofVec3f& _color);
        void init();
        bool isAlive() const;
        void draw(const ofVec2f& camera);
        void update(float secs);
        ofRectangle bounds();
        void collidedWith(GameObject* other);
};


#endif /* Portal_h */
