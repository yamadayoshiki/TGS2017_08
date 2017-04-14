#include "PlayerState.h"

#include "../../../../World/World.h"
#include "../../../../Input/InputMgr.h"

// コンストラクタ
PlayerState::PlayerState(Vector3& pos, Matrix& mat):
mPosition(pos), mRotation(mat), mAngle(0), mVelocity(Vector3::Zero) {}

// パッド入力処理
void PlayerState::input(){}

// モーションの切り替え
void PlayerState::change_motion(Actor & actor, const PlayerMotionID id, const float speed){
	// モーションの切り替え
	actor.setMotion(static_cast<int>(id), speed);
}

// 移動処理
void PlayerState::move(Actor & actor, float deltaTime, float speed){
	// 入力がない場合はreturn
	if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0)return;

	// カメラを取得
	auto camera = actor.getWorld()->getCamera();
	// 取得できない場合はreturn
	if (camera == nullptr) return;

	// 入力情報を速度に変換
	mVelocity = (camera->getPose().Forward() * InputMgr::GetInstance().AnalogPadVectorL().z + camera->getPose().Right() * InputMgr::GetInstance().AnalogPadVectorL().x) * Vector3(1, 0, 1);

	// キャラクタの＋Z方向のベクトルと、入力の速度の正規化の外積
	Vector3 forward_cross_target = Vector3::Cross(mRotation.Forward(), -mVelocity.Normalize());
	// キャラクタの＋Y方向のベクトルと、forward_cross_targetの内積
	float up_dot_cross = Vector3::Dot(mRotation.Up(), forward_cross_target);
	// 回転角度を求める
	mAngle = Vector3::Angle(mRotation.Forward(), -mVelocity.Normalize()) * MathHelper::Sign(up_dot_cross);

	// キャラクタをY軸を中心に回転
	mRotation *= Matrix::CreateFromAxisAngle(mRotation.Up(), mAngle);
	// 回転行列の正規化
	mRotation.NormalizeRotationMatrix();

	// 速度を座標に加算
	mPosition += mVelocity * speed;
}

// 覚醒条件(パッド)
bool PlayerState::awake_pad(){
	bool r_1 = InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_R1);
	bool l_1 = InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1);
	return r_1 && l_1;
}





