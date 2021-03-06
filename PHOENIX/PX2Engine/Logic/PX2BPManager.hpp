// PX2BPManager.hpp

#ifndef PX2BPMANAGER_HPP
#define PX2BPMANAGER_HPP

#include "PX2LogicPre.hpp"
#include "PX2BPFile.hpp"
#include "PX2BPPackage.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Polysegment.hpp"
#include "PX2BPEdit.hpp"

namespace PX2
{

	class PX2_ENGINE_ITEM BPManager : public Singleton<BPManager>
	{
	public:
		BPManager();
		virtual ~BPManager();

	public:
		// Compile
		const std::string &Compile(BPFile *file);
		int GetParamIndex();

		// Exe
		void Call(BPFile *file, bool alwaysCompile);
		void Call(BPPackage *group, bool alwaysCompile);
		void Call(const std::string &logicFilename);

		// Help
		bool CanLinkParam(PX2::BPParam *linkingParam, PX2::BPParam *linkedParam);
		PX2::Polysegment *CreatePoly(InterpCurveFloat *curve,
			const Float3 &color);
		void UpdatePoly(InterpCurveFloat *curve, PX2::Polysegment *p,
			const Float3 &color);

		// Operators
		AVector AVector_X_Float(const AVector &vec, float param);
		float Float_X_Float(float param0, float param1);

	protected:
		FunObject mCurAddFunObj;

		int mParamIndex;

		BPEdit *mBPEdit;

	public:
		void SetReleasedBut(UIButton *but);
		UIButton *GetReleasedBut();

	public:
		UIButtonPtr mReleasedBut;
	};

#define PX2_BPM BPManager::GetSingleton()
#include "PX2BPManager.inl"

}

#endif