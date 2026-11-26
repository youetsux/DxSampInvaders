#include "Player.h"
#include "Input.h"
#include <Dxlib.h>
#include "globals.h"
#include "Beam.h"


namespace {
	const float CENTER_X = WIN_WIDTH / 2;
	const float GROUND_Y = WIN_HEIGHT - 100;
	const int PLAYER_WIDTH = 32;
	const int PLAYER_HEIGHT = 32;
	const float PLAYER_SPEED = 4.0f;
	const unsigned int PLAYER_COLOR = GetColor(255, 0, 0);
}


Player::Player()
	:CharaBase()
{
	pos_ = Vec2((float)CENTER_X, (float)GROUND_Y);
	color_ = PLAYER_COLOR;
	speed_ = PLAYER_SPEED;
	width_ = PLAYER_WIDTH;
	height_ = PLAYER_HEIGHT;
	dir_ = DIR::NONE;
}

Player::~Player()
{}

void Player::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		Beam* beam = new Beam(Vec2(pos_.x + width_ / 2, pos_.y));
		beams_.push_back(beam);
	}
	Move();
	for (auto& itr : beams_)
	{
		itr->Update();
	}
}

void Player::Draw()
{
	DrawBox((int)pos_.x, (int)pos_.y, (int)pos_.x + width_, (int)pos_.y + height_, color_, TRUE);
	for (auto& itr : beams_)
	{
		itr->Draw();
	}
}

void Player::Move()
{
	Vec2 moveVec[MAX_DIR]{  { 0.0f, 0.0f },
							{ 0.0f, 0.0f },
							{ -speed_, 0.0f },
							{  speed_, 0.0f },
							{ 0.0f, 0.0f }
		                   };

	DIR tmpDir = DIR::NONE;
	if(Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		tmpDir = DIR::LEFT;
	}
	if(Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		tmpDir = DIR::RIGHT;
	}
	if (tmpDir != DIR::NONE)
	{
		dir_ = tmpDir;
	}
	else
	{
		dir_ = DIR::NONE;
	}

	pos_ = pos_.AddVec(moveVec[dir_]);
}
