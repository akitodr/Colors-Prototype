#pragma once

#include "GameObject.h"
#include <vector>

#define GAMEMANAGER GameManager::instance()

class GameManager {
    private:
        std::vector<GameObject*> objects;
        std::vector<GameObject*> dead;
        GameManager();
    
    public:
        static GameManager& instance();
        void clear();
        void add(GameObject* object);
        void update(float secs);
        void draw(const ofVec2f& camera);
        ~GameManager();
};
