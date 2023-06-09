#include "Player.h"
#include <Novice.h>
#include "Block.h"

void Player::Initialize() {

	pos_.x = 0;
	pos_.y = 624;
	size_ = 32;
	speed_ = 4;

	state = new PlayerStateNotBlock();
	state->SetPlayer(this);

}

void Player::ChangeState(PlayerState* newPlayerState) {
	delete state;

	state = newPlayerState;
	state->SetPlayer(this);

}

void Player::SetPosY(int y){

	pos_.y += y;

}

void Player::SetHitFlag(Block* block) {
	if (block->GetFlag1() == false && block->GetFlag2() == false && block->GetFlag3() == false) {
		pos_.y = setPosY_;
	}
}

void PlayerStateNotBlock::Update() {

	player_->SetHitFlag(block_);

}

void PlayerStateFirstBlock::Update() {
	
		player_->SetPosY(-32);
		block_->SetFlag1(true);

}

void PlayerStateSecondBlock::Update() {

		player_->SetPosY(-64);
		block_->SetFlag2(true);

}

void PlayerStateThirdBlock::Update() {

		player_->SetPosY(-32);
		block_->SetFlag3(true);
	
}

void Player::Update(char* keys, Block* block) {

	//移動処理
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	CheakLeftPosX1_ = pos_.x >= block->GetFirstPosX() - block->GetFirstSizeX() / 2 + 4;
	CheakLeftPosY1_ = pos_.y >= block->GetFirstPosY() - block->GetFirstSizeY() / 2;
	CheakRightPosX1_ = pos_.x <= block->GetFirstPosX() + block->GetFirstSizeX() - 32;
	CheakRightPosY1_ = pos_.y <= block->GetFirstPosY() + block->GetFirstSizeY();

	CheakLeftPosX2_ = pos_.x >= block->GetSecondPosX() - block->GetSecondSizeX() / 2 + 4;
	CheakLeftPosY2_ = pos_.y >= block->GetSecondPosY() - block->GetSecondSizeY() / 2;
	CheakRightPosX2_ = pos_.x <= block->GetSecondPosX() + block->GetSecondSizeX() - 32;
	CheakRightPosY2_ = pos_.y <= block->GetSecondPosY() + block->GetSecondSizeY();

	CheakLeftPosX3_ = pos_.x >= block->GetThirdPosX() - block->GetThirdSizeX() / 2 + 4;
	CheakLeftPosY3_ = pos_.y >= block->GetThirdPosY() - block->GetThirdSizeY() / 2;
	CheakRightPosX3_ = pos_.x <= block->GetThirdPosX() + block->GetThirdSizeX() - 32;
	CheakRightPosY3_ = pos_.y <= block->GetThirdPosY() + block->GetThirdSizeY();

	if (CheakLeftPosX1_ &&
		CheakLeftPosY1_ &&
		CheakRightPosX1_ &&
		CheakRightPosY1_ && block->GetFlag1() == false)
	{
		ChangeState(new PlayerStateFirstBlock);
	}
	else {
		block->SetFlag1(false);
	}

	if (CheakLeftPosX2_ &&
		CheakLeftPosY2_ &&
		CheakRightPosX2_ &&
		CheakRightPosY2_ && block->GetFlag2() == false)
	{
		ChangeState(new PlayerStateSecondBlock);
	}
	else {
		block->SetFlag2(false);
	}

	if (CheakLeftPosX3_ &&
		CheakLeftPosY3_ &&
		CheakRightPosX3_ &&
		CheakRightPosY3_ && block->GetFlag3() == false)
	{
		ChangeState(new PlayerStateThirdBlock);
	}
	else {
		block->SetFlag3(false);
	}

	SetHitFlag(block);

	state->SetBlock(block);
	state->Update();

}

void Player::Draw() {
	Novice::DrawBox(pos_.x, pos_.y, size_, size_, 0.0f, RED, kFillModeSolid);
}