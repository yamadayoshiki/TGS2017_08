#include "Player.h"

#include "../../../ResourceLoader/ResourceLoader.h"
#include "../../../Math/Vector3.h"
#include "../../Body/BoundingCapsule.h"
#include "../../../Scene/Base/SceneData.h"
#include "../../../Define.h"
#include "State/PlayerState_Enum.h"

#include <memory>

// コンストラクタ
Player::Player(IWorld * world, const Vector3 & position) :
	Actor(world, "Player", position, std::make_shared<BoundingCapsule>(Vector3::Up * PERSON_CENTER_HEIGHT, Matrix::Identity, PERSON_CENTER_HEIGHT, PERSON_RADIUS)),
	mStateMgr(new PlayerStateMgr(mPosition, mRotation)){

	// モデルの読み込み
	mModelHandle = MV1DuplicateModel(ResourceLoader::GetInstance().getModelHandle(ModelID::PLAYER));
	mAnimation = Animation(mModelHandle);
	
	//初期状態を正面に設定
	mRotation *= Matrix::CreateFromAxisAngle(mRotation.Up(), 180);
	mRotation.NormalizeRotationMatrix();

	// 初期Stateの指定
	mStateMgr->change(*this, PlayerState_Enum::N_IDLE);
}

// デストラクタ
Player::~Player(){
	delete mStateMgr;
}

// 更新処理
void Player::onUpdate(float deltaTime) {
	// 状態管理の更新処理
	mStateMgr->action(*this, deltaTime);

	// アニメーション再生
	mAnimation.changeAnim(mMotionID, mMotionSpeed);
	mAnimation.update(deltaTime);

	// 地形との衝突判定
	field();

	// 行動制限
	mPosition = Vector3::Clamp(mPosition, mWorld->getSceneData()->getCurData().status.mParams.pos_min, mWorld->getSceneData()->getCurData().status.mParams.pos_max);

	// 変換行列をモデルに代入
	MV1SetMatrix(mModelHandle, Matrix::MatrixToMATRIX(getPose()));
}

// 描画処理
void Player::onDraw() const{
	// プレイヤーモデルの描画
	MV1DrawModel(mModelHandle);
	// ステータスの描画（メーター）
	mWorld->getSceneData()->getCurData().status.draw();
}

// 衝突判定
void Player::onCollide(Actor & other){
	// 状態ごとの衝突判定
	mStateMgr->collide(*this, other);
}


