//
//  Flower.cpp
//  colors
//
//  Created by BEPID on 03/11/16.
//
//

#include "Flower.hpp"

void Flower::init(){
    
    position.set(200,200);
    
    animation.images = new ofImage[3];
    animation.images[0].load("img/a1.png");
    animation.images[0].setAnchorPercent(0.5, 0.5);
    animation.images[1].load("img/a2.png");
    animation.images[1].setAnchorPercent(0.5, 0.5);
    animation.images[2].load("img/a3.png");
    animation.images[2].setAnchorPercent(0.5, 0.5);
    animation.frame = 0;
    animation.count = 3;
    animation.repeat = true;
    animation.frameTime = 0.5;
    animation.time = 0;

}

void Flower::update(const ofVec2f& playerPos, float secs){
    ofVec2f path = playerPos - position;
    float dist = path.length();
    
    if (dist < 100){
        animation.update(secs);
    }
}

void Flower::draw(const ofVec2f& camera) {
    animation.draw(position - camera);
}
