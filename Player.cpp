#include "Player.h"
#include <Novice.h>
#include "Block.h"

void Player::Initialize() {

	pos_.x = 0;
	pos_.y = 624;
	size_ = 32;
	speed_ = 4;

	state = new PlayerStateSecondBlock();
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

void PlayerStateFirstBlock::Update() {
	
	CheakLeftPosX_ = player_->GetPosX() >= block_->GetFirstPosX() - block_->GetFirstSizeX() / 2 + 4;
	CheakLeftPosY_ = player_->GetPosY() >= block_->GetFirstPosY() - block_->GetFirstSizeY() / 2;
	CheakRightPosX_ = player_->GetPosX() <= block_->GetFirstPosX() + block_->GetFirstSizeX() - 32;
	CheakRightPosY_ = player_->GetPosY() <= block_->GetFirstPosY() + block_->GetFirstSizeY();


	if (CheakLeftPosX_ &&
		CheakLeftPosY_ &&
		CheakRightPosX_ &&
		CheakRightPosY_)
	{
		player_->SetPosY(-32);
		block_->SetFlag1(true);
		player_->ChangeState(new PlayerStateSecondBlock);
	}
	else {
		block_->SetFlag1(false);
	}

}

void PlayerStateSecondBlock::Update() {

	CheakLeftPosX_ = player_->GetPosX() >= block_->GetSecondPosX() - block_->GetSecondSizeX() / 2 + 4;
	CheakLeftPosY_ = player_->GetPosY() >= block_->GetSecondPosY() - block_->GetSecondSizeY() / 2;
	CheakRightPosX_ = player_->GetPosX() <= block_->GetSecondPosX() + block_->GetSecondSizeX() - 32;
	CheakRightPosY_ = player_->GetPosY() <= block_->GetSecondPosY() + block_->GetSecondSizeY();

	if (CheakLeftPosX_ &&
		CheakLeftPosY_ &&
		CheakRightPosX_ &&
		CheakRightPosY_)
	{
		player_->SetPosY(-64);
		block_->SetFlag2(true);
		player_->ChangeState(new PlayerStateThirdBlock);

	}
	else {
		block_->SetFlag2(false);
	}

}

void PlayerStateThirdBlock::Update() {
	CheakLeftPosX_ = player_->GetPosX() >= block_->GetThirdPosX() - block_->GetThirdSizeX() / 2 + 4;
	CheakLeftPosY_ = player_->GetPosY() >= block_->GetThirdPosY() - block_->GetThirdSizeY() / 2;
	CheakRightPosX_ = player_->GetPosX() <= block_->GetThirdPosX() + block_->GetThirdSizeX() - 32;
	CheakRightPosY_ = player_->GetPosY() <= block_->GetThirdPosY() + block_->GetThirdSizeY();

	if (CheakLeftPosX_ &&
		CheakLeftPosY_ &&
		CheakRightPosX_ &&
		CheakRightPosY_)
	{
		player_->SetPosY(-32);
		block_->SetFlag3(true);
	}
	else {
		block_->SetFlag3(false);
	}
}

void Player::Update(char* keys, Block* block) {

	//移動処理
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	state->SetBlock(block);
	state->Update();

}

void Player::Draw() {
	Novice::DrawBox(pos_.x, pos_.y, size_, size_, 0.0f, RED, kFillModeSolid);
}