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
	bool IsOutScreen() const;
private:
    int length_;
    unsigned int color_;
    int thickness_;
};

