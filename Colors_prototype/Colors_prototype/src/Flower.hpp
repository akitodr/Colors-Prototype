//
//  Flower.hpp
//  colors
//
//  Created by BEPID on 03/11/16.
//
//

#ifndef Flower_hpp
#define Flower_hpp

#include "ofMain.h"
#include "Animation.h"

class Flower {
    private:
    ofVec2f position;
    Animation animation;
    
    public:
    
    void init();
    void update(const ofVec2f& playerPos, float secs);
    void draw(const ofVec2f& camera);
};

#endif /* Flower_hpp */
