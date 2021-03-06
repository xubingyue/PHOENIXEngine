// PX2CameraPlayerController.hpp

#ifndef PX2CAMERAPLAYERCONTROLLER_HPP
#define PX2CAMERAPLAYERCONTROLLER_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Controller.hpp"
#include "PX2CameraNode.hpp"

namespace PX2
{

	class PX2_ENGINE_ITEM CameraPlayController : public Controller
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(CameraPlayController);

	public:
		CameraPlayController();
		virtual ~CameraPlayController();

		void SetCameraNode(CameraNode *camNode);
		CameraNode *GetCameraNode();

		void SetCameraDistance(float dist);

		void SetCameraDist(float min, float max);
		void GetCameraDist(float &min, float &max);

		AVector GetCurDir();

		virtual void OnEvent(Event *ent);

		void UpdateCameraRot();
		void UpdateCameraPos();

	protected:
		virtual void _Update(double applicationTime, double elapsedTime);

		float mDistance;
		float mDegreeHor;
		float mDegreeVer;

		CameraNode *mCameraNode;
		float mCameraMin;
		float mCameraMax;

		bool mIsTouchDown;
		bool mIsTouchMoved;
		float mTouchUpMoveLength;
		APoint mStartPickPos_Touch;
		APoint mPickPos_Touch;
		APoint mLastPickPos_Touch;
		AVector mCurDir;

		bool mIsMiddleDown;
	};

	PX2_REGISTER_STREAM(CameraPlayController);
	typedef Pointer0<CameraPlayController> CameraPlayControllerPtr;

}

#endif