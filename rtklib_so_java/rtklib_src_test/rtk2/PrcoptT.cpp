#include "PrcoptT.h"


PrcoptT::PrcoptT()
{
}


PrcoptT::~PrcoptT()
{
}

int PrcoptT::initPrcoptT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/PrcoptT");

	navsysID = (*env).GetFieldID(cls, "navsys", "I");
	ionooptID = (*env).GetFieldID(cls, "ionoopt", "I");
	tropoptID = (*env).GetFieldID(cls, "tropopt", "I");
	elminID = (*env).GetFieldID(cls, "elmin", "D");
	satephID = (*env).GetFieldID(cls, "sateph", "I");
	nfID = (*env).GetFieldID(cls, "nf", "I");
	modeID = (*env).GetFieldID(cls, "mode", "I");
	modearID = (*env).GetFieldID(cls, "modear", "I");
	refposID = (*env).GetFieldID(cls, "refpos", "I");
	bdsmodearID = (*env).GetFieldID(cls, "bdsmodear", "I");
	glomodearID = (*env).GetFieldID(cls, "glomodear", "I");
	soltypeID = (*env).GetFieldID(cls, "soltype", "I");
	validThresARID = (*env).GetFieldID(cls, "validThresAR", "D");

	rbID = (*env).GetFieldID(cls, "rb", "[D");
	return 0;
}

prcopt_t PrcoptT::convertCPrcoptT(JNIEnv *env, jobject opt_obj)
{
	prcopt_t opt = prcopt_default;
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[3];
	if (opt_obj != NULL)
	{
		opt.navsys = env->GetIntField(opt_obj, navsysID);
		opt.ionoopt = env->GetIntField(opt_obj, ionooptID);
		opt.tropopt = env->GetIntField(opt_obj, tropoptID);
		opt.elmin = env->GetDoubleField(opt_obj, elminID);
		opt.sateph = env->GetIntField(opt_obj, satephID);

		opt.nf = env->GetIntField(opt_obj, nfID);
		opt.mode = env->GetIntField(opt_obj, modeID);
		opt.modear = env->GetIntField(opt_obj, modearID);

		opt.bdsmodear = env->GetIntField(opt_obj, bdsmodearID);
		opt.refpos = env->GetIntField(opt_obj, refposID);
		int i = 0;
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(opt_obj, rbID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 3, tempBuf);
		for (i = 0; i < 3; i++)
		{
			opt.rb[i] = tempBuf[i];
		}

		opt.glomodear = env->GetIntField(opt_obj, glomodearID);
		opt.soltype = env->GetIntField(opt_obj, soltypeID);
		opt.thresar[0] = env->GetDoubleField(opt_obj, validThresARID);
	}
	return opt;
}
