#pragma once
#include "CharaBase.h"
#include <list>

class Beam;
class Player :
    public CharaBase
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Release();
	std::list<Beam*>& GetBeams() { return beams_; }
private:
	void Move();
	unsigned int color_;
	std::list<Beam*> beams_;
};

