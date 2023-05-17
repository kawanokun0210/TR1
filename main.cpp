#include <Novice.h>

const char kWindowTitle[] = "LE2B_09_カワノ_ユウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//宣言

	int playerPosX = 0;
	int playerPosY = 592;
	const int setPlayerPosY = 624;
	int playerSize =32;
	int playerSpeed = 4;

	//ブロック
	int blockPosX = 300;
	int blockPosY = 624;
	int blockSizeX = 64;
	int blockSizeY = 32;
	bool blockHitFlag = false;

	//ブロック2
	int blockPosX2 = 364;
	int blockPosY2 = 592;
	int blockSizeX2 = 64;
	int blockSizeY2 = 32;
	bool blockHitFlag2 = false;

	//ブロック3
	int blockPosX3 = 428;
	int blockPosY3 = 624;
	int blockSizeX3 = 64;
	int blockSizeY3 = 32;
	bool blockHitFlag3 = false;

	int underBlockPosX = 0;
	int underBlockPosY = 656;
	int underBlockSizeX = 1280;
	int underBlockSizeY = 64;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//移動処理
		if (keys[DIK_D]) {
			playerPosX += playerSpeed;
		}
		if (keys[DIK_A]) {
			playerPosX -= playerSpeed;
		}

		if (blockHitFlag == false && blockHitFlag2 == false && blockHitFlag3 == false) {
			playerPosY = setPlayerPosY;
		}

		//当たり判定
		if (playerPosX >= blockPosX - blockSizeX / 2 + 4&&
			playerPosY >= blockPosY - blockSizeY / 2 &&
			playerPosX <= blockPosX + blockSizeX - 32&&
			playerPosY <= blockPosY + blockSizeY && blockHitFlag == false)
		{
			playerPosY -= 32;
			blockHitFlag = true;
		}
		else {
			blockHitFlag = false;
		}

		//当たり判定

		if (playerPosX >= blockPosX2 - blockSizeX2 / 2 &&
			playerPosY >= blockPosY2 - blockSizeY2 / 2 + 32&&
			playerPosX <= blockPosX2 + blockSizeX2 - 4 &&
			playerPosY <= blockPosY2 + blockSizeY2 && blockHitFlag2 == false)
		{
			playerPosY -= 64;
			blockHitFlag2 = true;
		}
		else {
			blockHitFlag2 = false;
		}

		//当たり判定
		if (playerPosX >= blockPosX3 - blockSizeX3 / 2 &&
			playerPosY >= blockPosY3 - blockSizeY3 / 2 &&
			playerPosX <= blockPosX3 + blockSizeX3 - 4 &&
			playerPosY <= blockPosY3 + blockSizeY3 && blockHitFlag3 == false)
		{
			playerPosY -= 32;
			blockHitFlag3 = true;
		}
		else {
			blockHitFlag3 = false;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(playerPosX, playerPosY, playerSize, playerSize, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(blockPosX, blockPosY, blockSizeX, blockSizeY, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(blockPosX2, blockPosY2, blockSizeX2, blockSizeY2, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(blockPosX3, blockPosY3, blockSizeX3, blockSizeY3, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(underBlockPosX, underBlockPosY, underBlockSizeX, underBlockSizeY, 0.0f, BLACK, kFillModeSolid);
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
