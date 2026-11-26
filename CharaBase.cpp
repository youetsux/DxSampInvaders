#include "CharaBase.h"
#include <DxLib.h>


CharaBase::CharaBase()
	:pos_(0.0f, 0.0f),
	dir_(NONE),
	width_(0), height_(0),
	speed_(0.0f),
	imageHandle_(-1)
{
	imageHandle_ = LoadGraph("Assets//batu.png");
}

CharaBase::~CharaBase()
{}

void CharaBase::Update()
{}

void CharaBase::Draw()
{
	int px = (int)pos_.x;
	int py = (int)pos_.y;

	DrawGraph(px, py, imageHandle_, TRUE);
}
