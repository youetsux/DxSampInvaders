#pragma once
#include "CharaBase.h"
class Beam :
    public CharaBase
{
public:
    Beam();
	Beam(const Vec2& pos);
	~Beam();
	void Update();
	void Draw();
	void Release();
	bool IsOutScreen();
private:
	unsigned int color_;//ƒr[ƒ€‚ÌF
	void Move();
};

