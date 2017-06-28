#pragma once

class Player {
    private:
        float pos_x;
        float pos_y;
        
        bool rightPressed;
        bool leftPressed;
        bool upPressed;
        bool downPressed;

        float speed;

    public:
        // Constrcutor
        Player();
        
        // Movement
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();

        void stopRight();
        void stopLeft();
        void stopUp();
        void stopDown();

        // Update
        void update(double seconds);
};
