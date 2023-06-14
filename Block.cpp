#include "Block.h"
#include <Novice.h>
void Block::SetFlag1(bool x) {
	block_[0].blockHitFlag = x;
}

void Block::SetFlag2(bool x) {
	block_[1].blockHitFlag = x;
}

void Block::SetFlag3(bool x) {
	block_[2].blockHitFlag = x;
}

void Block::Initialize() {

	for (int i = 0; i < kBlockNum_; i++) {
		block_[0].pos.x = 300;
		block_[0].pos.y = 624;
		block_[0].size.x = 64;
		block_[0].size.y = 32;

		block_[1].pos.x = 364;
		block_[1].pos.y = 592;
		block_[1].size.x = 64;
		block_[1].size.y = 32;
		
		block_[2].pos.x = 428;
		block_[2].pos.y = 624;
		block_[2].size.x = 64;
		block_[2].size.y = 32;

		block_[i].blockHitFlag = false;
	}

}

void Block::Draw() {
	for (int i = 0; i < kBlockNum_; i++) {
		Novice::DrawBox(block_[i].pos.x, block_[i].pos.y, block_[i].size.x, block_[i].size.y, 0.0f, WHITE, kFillModeSolid);
	}
	Novice::DrawBox(underBlockPosX, underBlockPosY, underBlockSizeX, underBlockSizeY, 0.0f, BLACK, kFillModeSolid);
}