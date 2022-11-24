#include "ObsdT.h"
#include "rtkjni.h"


ObsdT::ObsdT()
{
}


ObsdT::~ObsdT()
{
}

int ObsdT::initObsdT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/ObsdT");

	timeID = (*env).GetFieldID(cls, "time", "Lrtk/model/GtimeT;");
	satID = (*env).GetFieldID(cls, "sat", "I");
	rcvID = (*env).GetFieldID(cls, "rcv", "I");

	SNRID = (*env).GetFieldID(cls, "SNR", "[I");
	LLIID = (*env).GetFieldID(cls, "LLI", "[I");
	codeID = (*env).GetFieldID(cls, "code", "[I");

	LID = (*env).GetFieldID(cls, "L", "[D");
	PID = (*env).GetFieldID(cls, "P", "[D");
	DID = (*env).GetFieldID(cls, "D", "[F");

	j_obsd_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

void  ObsdT::convertJavaObsd(JNIEnv *env, obsd_t obsd, jobject j_obsd_obj)
{
	jobject time_obj = (*env).NewObjectA(GtimeT::cls, GtimeT::j_gtime_methodID, 0);
	GtimeT::convertJavaGtimeT(env, obsd.time, time_obj);
	(*env).SetObjectField(j_obsd_obj, timeID, time_obj);
	(*env).SetIntField(j_obsd_obj, satID, obsd.sat);
	(*env).SetIntField(j_obsd_obj, rcvID, obsd.rcv);
	setInt16Array(env, cls, j_obsd_obj, "SNR", NFREQ + NEXOBS, obsd.SNR, SNRID);
	//赋值LLI
	setInt8Array(env, cls, j_obsd_obj, "LLI", NFREQ + NEXOBS, obsd.LLI,LLIID);
	//赋值code
	setInt8Array(env, cls, j_obsd_obj, "code", NFREQ + NEXOBS, obsd.code,codeID);
	//赋值L
	setDoubleArray(env, cls, j_obsd_obj, "L", NFREQ + NEXOBS, obsd.L,LID);
	//赋值P
	setDoubleArray(env, cls, j_obsd_obj, "P", NFREQ + NEXOBS, obsd.P,PID);
	//赋值D
	setFloatArray(env, cls, j_obsd_obj, "D", NFREQ + NEXOBS, obsd.D,DID);
	
}

//
obsd_t ObsdT::convertCObsdT(JNIEnv *env, jobject obsd_obj)
{
	static jintArray tempJintArray;
	static jdoubleArray tempJdoubleArray;
	static jfloatArray tempJfloatArray;
	static jint tempSNRBuf[NFREQ + NEXOBS];
	static jint tempLLIBuf[NFREQ + NEXOBS];
	static jint tempCodeBuf[NFREQ + NEXOBS];
	static jdouble tempLBuf[NFREQ + NEXOBS];
	static jdouble tempPBuf[NFREQ + NEXOBS];
	static jfloat tempDBuf[NFREQ + NEXOBS];
	static jobject time_obj;
	int i = 0;
	obsd_t obsd = { 0 };
	if (obsd_obj != NULL)
	{
		time_obj = env->GetObjectField(obsd_obj, timeID);
		obsd.time = GtimeT::convertCGtimeT(env, time_obj);
		obsd.sat = env->GetIntField(obsd_obj, ObsdT::satID);
		obsd.rcv = env->GetIntField(obsd_obj, ObsdT::rcvID);

		tempJintArray = (jintArray)env->GetObjectField(obsd_obj, ObsdT::SNRID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ + NEXOBS, tempSNRBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.SNR[i] = tempSNRBuf[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(obsd_obj, ObsdT::LLIID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ + NEXOBS, tempLLIBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.LLI[i] = tempLLIBuf[i];
		}
		
		tempJintArray = (jintArray)env->GetObjectField(obsd_obj, ObsdT::codeID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ + NEXOBS, tempCodeBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.code[i] = tempCodeBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(obsd_obj, ObsdT::LID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ + NEXOBS, tempLBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.L[i] = tempLBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(obsd_obj, ObsdT::PID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ + NEXOBS, tempPBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.P[i] = tempPBuf[i];
		}

		tempJfloatArray = (jfloatArray)env->GetObjectField(obsd_obj, ObsdT::DID);
		if (tempJfloatArray != NULL)
			env->GetFloatArrayRegion(tempJfloatArray, 0, NFREQ + NEXOBS, tempDBuf);
		for (i = 0; i < NFREQ + NEXOBS; i++)
		{
			obsd.D[i] = tempDBuf[i];
		}
	
	}
	return obsd;

}
