#pragma once
#include "CharaBase.h"
class Player :
    public CharaBase
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
private:
	void Move();
	unsigned int color_;
};

