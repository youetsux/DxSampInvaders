#include "Player.h"
#include <DxLib.h>
#include "globals.h"
#include "Input.h"
#include "Beam.h"

namespace {
	const unsigned int PLAYER_COLOR = GetColor(65, 105, 225);
	const float CENTER_X = WIN_WIDTH / 2.0f;
	const float GROUND_Y = WIN_HEIGHT - 100.0f;
	const float PLAYER_SPEED = 5.0f; // プレイヤーの移動速度
	const int PLAYER_WIDTH = 32; // プレイヤーの幅
	const int PLAYER_HEIGHT = 32; // プレイヤーの高さ
	//Beam* beam = nullptr;
}

Player::Player()
	:CharaBase()
{
	pos_ = Vec2(CENTER_X, GROUND_Y);//ｘ：画面の中央、ｙ：地面の高さ
	speed_ = PLAYER_SPEED;//プレイヤーの移動速度
	width_ = PLAYER_WIDTH;//プレイヤーの幅
	height_ = PLAYER_HEIGHT;//プレイヤーの高さ
	dir_ = DIR::NONE;
	imageHandle_ = -1;//画像ハンドルの初期化（今回は使わない）
	color_ = PLAYER_COLOR;

	//std::array<Beam*, 3>::iterator theI;
	//for (auto itr = beams_.begin(); itr != beams_.end(); itr++)
	//範囲for文
	for (auto& itr : beams_)
	{
		itr = nullptr;
	}

	//for (int i = 0; i < beams_.size(); i++)
	//	beams_[i] = nullptr;
}

Player::~Player()
{}

void Player::Update()
{
	Move();
	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{

		for (auto& itr : beams_) {
			if (itr == nullptr) {
				Vec2 initPos = Vec2(pos_.x + width_ / 2.0f,
					pos_.y);
				itr = new Beam(initPos);
				break;
			}
		}
		//ビームを発射する処理を書く
		//for (auto itr = beams_.begin(); itr != beams_.end(); itr++)
		//{
		//	if (*itr == nullptr) {
		//		Vec2 initPos = Vec2(pos_.x + width_ / 2.0f,
		//			pos_.y);
		//		*itr = new Beam(initPos);
		//		break;
		//	}
		//}
		//for (int i = 0; i < beams_.size(); i++) {
		//	if (beams_[i] == nullptr) {
		//		Vec2 initPos = Vec2(pos_.x + width_ / 2.0f, 
		//			                pos_.y);
		//		beams_[i] = new Beam(initPos);
		//		break;
		//	}
		//}
	}
	for (auto& itr : beams_) {
		if (itr) {
			itr->Update();
			// ビームが画面外に出たら削除する
			if (itr->IsOutScreen()) {
				delete itr;
				itr = nullptr;
			}
		}
	}
	//for (auto itr = beams_.begin(); itr != beams_.end(); itr++)
	//{
	//	if (*itr) {
	//		(*itr)->Update();
	//		// ビームが画面外に出たら削除する
	//		if ((*itr)->IsOutScreen()) {
	//			delete* itr;
	//			*itr = nullptr;
	//		}
	//	}
	//}
	//for (int i = 0; i < beams_.size(); i++) {
	//	if (beams_[i]) {
	//		beams_[i]->Update();
	//		// ビームが画面外に出たら削除する
	//		if (beams_[i]->IsOutScreen()) {
	//			delete beams_[i];
	//			beams_[i] = nullptr;
	//		}
	//	}
	//}
}

void Player::Draw()
{
	DrawBox((int)pos_.x, (int)pos_.y,
		    (int)pos_.x + width_, (int)pos_.y + height_,
		    color_, TRUE);
	for (auto itr = beams_.begin(); itr != beams_.end(); itr++)
	{
		if (*itr)
			(*itr)->Draw();
	}
	//for (int i = 0; i < beams_.size(); i++) {
	//	if (beams_[i])
	//		beams_[i]->Draw();
	//}
}

void Player::Release()
{}

void Player::Move()
{
	Vec2 moveVec[MAX_DIR] = {
		Vec2(0.0f, 0.0f), // UP
		Vec2(0.0f, 0.0f),  // DOWN
		Vec2(-speed_, 0.0f), // LEFT
		Vec2(speed_, 0.0f),   // RIGHT
		Vec2(0.0f, 0.0f)  // NONE
	};
	//DIR tmpDir = DIR::NONE;
	dir_ = DIR::NONE;
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		//tmpDir = DIR::LEFT;
		dir_ = DIR::LEFT;
	}
	else if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		//tmpDir = DIR::RIGHT;
		dir_ = DIR::RIGHT;
	}

	//if (tmpDir != DIR::NONE)
	//{
	//	dir_ = tmpDir;
	//}
	//else
	//{
	//	dir_ = DIR::NONE;
	//}


//入力処理を書く
	pos_ = pos_.AddVec(moveVec[dir_]);
	
	//pos_ = pos_ + move;
	//moveが移動方向のベクトル
}
