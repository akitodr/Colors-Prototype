//
//  Fase2.h
//  colors
//
//  Created by BEPID on 08/11/16.
//
//

#ifndef Fase2_h
#define Fase2_h

#include "Fase.h"

class Fase2 : public Fase {
    private:
        bool switchLevel;
    
    public:
        void init();
        void interpolateColor(const ofVec3f& color);
        void onPortal();
        Screen* nextScreen();
};


#endif /* Fase2_h */
