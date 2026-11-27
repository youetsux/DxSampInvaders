#include "Beam.h"
#include <DxLib.h>
namespace {
	const unsigned int BEAM_COLOR = GetColor(184,225,65);
	const float BEAM_SPEED = 8.0f; // ビームの移動速度
	const int BEAM_WIDTH = 3; // ビームの幅
	const int BEAM_HEIGHT = 20; // ビームの高さ

}

Beam::Beam()
	:CharaBase()
{
	speed_ = BEAM_SPEED;
	width_ = BEAM_WIDTH;
	height_ = BEAM_HEIGHT;
	color_ = BEAM_COLOR;
}

Beam::Beam(const Vec2& pos)
	:CharaBase()
{
	pos_ = pos;
	speed_ = BEAM_SPEED;
	width_ = BEAM_WIDTH;
	height_ = BEAM_HEIGHT;
	color_ = BEAM_COLOR;
}

Beam::~Beam()
{}

void Beam::Update()
{
	Move();
}

void Beam::Draw()
{
	DrawBox((int)pos_.x, (int)pos_.y,
		(int)pos_.x + width_, (int)pos_.y + height_,
		color_, TRUE);
}

void Beam::Release()
{}

bool Beam::IsOutScreen()
{
	bool isOut = false;
	if (pos_.y < 0)
		isOut = true;
	return isOut;
}

//ビームを上方向に移動させる処理
void Beam::Move()
{
	Vec2 moveVec(0.0f, -speed_); // 上方向に移動するベクトル
	pos_ = pos_.AddVec(moveVec);
}
