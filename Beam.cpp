#include "Beam.h"
#include <DxLib.h>

Beam::Beam()
	:CharaBase(),
	length_(20),
	color_(GetColor(255, 255, 0)),
	thickness_(3)
{
	speed_ = 8.0f;
}

Beam::Beam(const Vec2 & pos)
	:CharaBase(),
	length_(20),
	color_(GetColor(255, 255, 0)),
	thickness_(3)
{
	pos_ = pos;
	speed_ = 8.0f;
}

Beam::~Beam()
{}

void Beam::Update()
{
	Vec2 moveVec(0.0f, -speed_);
	pos_ = pos_.AddVec(moveVec);
}

void Beam::Draw()
{
	DrawLine(
		(int)pos_.x,
		(int)pos_.y,
		(int)pos_.x,
		(int)pos_.y - length_,
		color_,
		thickness_
	);
}

bool Beam::IsOutScreen() const
{
	return pos_.y < 0;
}
