#pragma once
#include "NewVector2.h"
class Block;

class Player;

enum class Phase {
	FirstBlock,
	SecondBlock,
	ThirdBlock,
};

class PlayerState {

protected:
	Block* block_ = nullptr;
	Player* player_ = nullptr;

public:

	virtual void SetPlayer(Player* player) { player_ = player; }
	virtual void Update() {};
	void SetBlock(Block* block) {
		block_ = block;
	}

};

class PlayerStateFirstBlock : public PlayerState {

public:

	//左上のXY
	int CheakLeftPosX_;
	int CheakLeftPosY_;

	//右下のXY
	int CheakRightPosX_;
	int CheakRightPosY_;

	void Update() override;

};

class PlayerStateSecondBlock : public PlayerState {

public:

	//左上のXY
	int CheakLeftPosX_;
	int CheakLeftPosY_;

	//右下のXY
	int CheakRightPosX_;
	int CheakRightPosY_;

	void Update() override;

};

class PlayerStateThirdBlock : public PlayerState {
public:

	//左上のXY
	int CheakLeftPosX_;
	int CheakLeftPosY_;

	//右下のXY
	int CheakRightPosX_;
	int CheakRightPosY_;

	void Update() override;

};

class Player
{

public:

	~Player() { delete state; }

	void Initialize();

	void Update(char* keys, Block* block);

	void Draw();

	void ChangeState(PlayerState* newPlayerState);

	int GetPosX() { return pos_.x; }
	int GetPosY() { return pos_.y; }

	void SetPosY(int y);

private:

	Vector2Int pos_;

	int size_;

	int speed_;

	const int setPosY_ = 624;

	Phase phase_ = Phase::FirstBlock;

	PlayerState* state;

	//左上のXY
	int CheakLeftPosX_;
	int CheakLeftPosY_;

	//右下のXY
	int CheakRightPosX_;
	int CheakRightPosY_;

};

