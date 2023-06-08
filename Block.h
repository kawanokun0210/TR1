#pragma once
#include "NewVector2.h"


struct BLOCK
{
	Vector2Int pos;
	Vector2Int size;
	bool blockHitFlag;

};

class Block
{

public:

	void Initialize();

	void Draw();

	int GetFirstPosX() { return block_[0].pos.x; }
	int GetFirstPosY() { return block_[0].pos.y; }
	int GetFirstSizeX() { return block_[0].size.x; }
	int GetFirstSizeY() { return block_[0].size.y; }

	int GetSecondPosX() { return block_[1].pos.x; }
	int GetSecondPosY() { return block_[1].pos.y; }
	int GetSecondSizeX() { return block_[1].size.x; }
	int GetSecondSizeY() { return block_[1].size.y; }

	int GetThirdPosX() { return block_[2].pos.x; }
	int GetThirdPosY() { return block_[2].pos.y; }
	int GetThirdSizeX() { return block_[2].size.x; }
	int GetThirdSizeY() { return block_[2].size.y; }

	int GetFlag1() { return block_[0].blockHitFlag; }
	int GetFlag2() { return block_[1].blockHitFlag; }
	int GetFlag3() { return block_[2].blockHitFlag; }

	void SetFlag1(bool x);
	void SetFlag2(bool x);
	void SetFlag3(bool x);

private:

	static const int kBlockNum_ = 3;

	BLOCK block_[kBlockNum_];

	int underBlockPosX = 0;
	int underBlockPosY = 656;
	int underBlockSizeX = 1280;
	int underBlockSizeY = 64;

};

