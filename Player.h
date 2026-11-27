#pragma once
#include "CharaBase.h"
#include <array>


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
private:
	void Move();
	unsigned int color_;//プレイヤーの色
	std::array<Beam*, 3> beams_;
	//Beam* beams_[10];といっしょ
};

