#pragma once
#include "Vec2.h"

enum DIR;

class CharaBase
{
public:
    enum DIR {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
        MAX_DIR
    };
    CharaBase();
    ~CharaBase();

    void Update();
    void Draw();

    Vec2 GetPos() const { return pos_; }
    int GetX() const { return pos_.x; }
    int GetY() const { return pos_.y; }
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
protected:
    Vec2 pos_;
    DIR  dir_;
    int width_;
    int height_;
    float speed_;
    int imageHandle_;
};