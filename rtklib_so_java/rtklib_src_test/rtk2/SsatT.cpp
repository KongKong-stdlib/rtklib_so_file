#include "SsatT.h"
#include "rtkjni.h"
#include "GtimeT.h"

SsatT::SsatT()
{
}


SsatT::~SsatT()
{
}

int SsatT::initSsatT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/SsatT");
	sysID = (*env).GetFieldID(cls, "sys", "I");
	vsID = (*env).GetFieldID(cls, "vs", "I");

	azelID = (*env).GetFieldID(cls, "azel", "[D");
	respID = (*env).GetFieldID(cls, "resp", "[D");
	rescID = (*env).GetFieldID(cls, "resc", "[D");

	vsatID = (*env).GetFieldID(cls, "vsat", "[I");
	snrID = (*env).GetFieldID(cls, "snr", "[I");
	fixID = (*env).GetFieldID(cls, "fix", "[I");
	slipID = (*env).GetFieldID(cls, "slip", "[I");
	halfID = (*env).GetFieldID(cls, "half", "[I");
	lockID = (*env).GetFieldID(cls, "lock", "[I");

	outcID = (*env).GetFieldID(cls, "outc", "[J");
	slipcID = (*env).GetFieldID(cls, "slipc", "[J");
	rejcID = (*env).GetFieldID(cls, "rejc", "[J");
	gfID = (*env).GetFieldID(cls, "gf", "[D");
	mwID = (*env).GetFieldID(cls, "mw", "[D");
	phwID = (*env).GetFieldID(cls, "phw", "D");
	ptID = (*env).GetFieldID(cls, "pt", "[[Lrtk/model/GtimeT;");
	phID = (*env).GetFieldID(cls, "ph", "[[D");

	j_ssat_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

ssat_t SsatT::convertCSsat(JNIEnv *env, jobject j_ssat_obj)
{
	ssat_t ssat = { 0 };
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[NFREQ];

	static jintArray tempJintArray;
	static jint tempBuf2[NFREQ];

	static jlongArray tempJlongArray;
	static jlong tempBuf3[NFREQ];

	static jobjectArray timeArray;
	static jobjectArray timeArray2;
	static jobjectArray phArray;
	static jobject time_obj;

	static jdoubleArray phArray2;
	int i = 0;
	if (j_ssat_obj != NULL)
	{
		ssat.sys = env->GetIntField(j_ssat_obj, SsatT::sysID);
		ssat.vs = env->GetIntField(j_ssat_obj, SsatT::vsID);
		
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_ssat_obj, SsatT::azelID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 2, tempBuf);
		for (i = 0; i < 2; i++)
		{
			ssat.azel[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_ssat_obj, SsatT::respID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ, tempBuf);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.resp[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_ssat_obj, SsatT::rescID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ, tempBuf);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.resc[i] = tempBuf[i];
		}
		
		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::vsatID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.vsat[i] = tempBuf2[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::snrID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.snr[i] = tempBuf2[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::fixID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.fix[i] = tempBuf2[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::slipID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.slip[i] = tempBuf2[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::halfID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.half[i] = tempBuf2[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(j_ssat_obj, SsatT::lockID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, NFREQ, tempBuf2);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.lock[i] = tempBuf2[i];
		}

		tempJlongArray = (jlongArray)env->GetObjectField(j_ssat_obj, SsatT::outcID);
		if (tempJlongArray != NULL)
			env->GetLongArrayRegion(tempJlongArray, 0, NFREQ, tempBuf3);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.outc[i] = tempBuf3[i];
		}

		tempJlongArray = (jlongArray)env->GetObjectField(j_ssat_obj, SsatT::slipcID);
		if (tempJlongArray != NULL)
			env->GetLongArrayRegion(tempJlongArray, 0, NFREQ, tempBuf3);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.slipc[i] = tempBuf3[i];
		}

		tempJlongArray = (jlongArray)env->GetObjectField(j_ssat_obj, SsatT::rejcID);
		if (tempJlongArray != NULL)
			env->GetLongArrayRegion(tempJlongArray, 0, NFREQ, tempBuf3);
		for (i = 0; i < NFREQ; i++)
		{
			ssat.rejc[i] = tempBuf3[i];
		}


		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_ssat_obj, SsatT::gfID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ-1, tempBuf);
		for (i = 0; i < NFREQ-1; i++)
		{
			ssat.gf[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_ssat_obj, SsatT::mwID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, NFREQ-1, tempBuf);
		for (i = 0; i < NFREQ-1; i++)
		{
			ssat.mw[i] = tempBuf[i];
		}
		ssat.phw = env->GetDoubleField(j_ssat_obj, SsatT::phwID);

		timeArray = (jobjectArray)env->GetObjectField(j_ssat_obj, ptID);
		for (int i = 0; i < 2; i++)
		{
			timeArray2 = (jobjectArray)(*env).GetObjectArrayElement(timeArray, i);
			for (int j = 0; j < NFREQ; j++)
			{
				time_obj = (*env).GetObjectArrayElement(timeArray2, j);
				ssat.pt[i][j] = GtimeT::convertCGtimeT(env,time_obj);
			}
		}

		phArray = (jobjectArray)env->GetObjectField(j_ssat_obj, phID);
		for (int i = 0; i < 2; i++)
		{
			jdouble tempbuf[NFREQ];
			phArray2 = (jdoubleArray)env->GetObjectArrayElement(phArray, i);
			env->GetDoubleArrayRegion(phArray2, 0, NFREQ, tempbuf);
			for (int j = 0; j < NFREQ; j++)
			{
				ssat.ph[i][j] = tempbuf[j];
			}
			
		}
	}
	return ssat;
}


void  SsatT::convertJavaSsat(JNIEnv *env, ssat_t ssat, jobject j_ssat_obj)
{
	static jobjectArray timeArray;
	static jobjectArray timeArray2;
	static jobjectArray phArray;
	//static jdoubleArray phArray2;
	(*env).SetIntField(j_ssat_obj, sysID, ssat.sys);
	(*env).SetIntField(j_ssat_obj, vsID, ssat.vs);
	setDoubleArray(env, cls, j_ssat_obj, "azel", 2, ssat.azel, azelID);
	setDoubleArray(env, cls, j_ssat_obj, "resp", NFREQ, ssat.resp, respID);
	setDoubleArray(env, cls, j_ssat_obj, "resc", NFREQ, ssat.resc, rescID);
	setInt8Array(env, cls, j_ssat_obj, "vsat", NFREQ, ssat.vsat, vsatID);
	setInt16Array(env, cls, j_ssat_obj, "snr", NFREQ, ssat.snr, snrID);
	setInt8Array(env, cls, j_ssat_obj, "fix", NFREQ, ssat.fix, fixID);
	setInt8Array(env, cls, j_ssat_obj, "slip", NFREQ, ssat.slip, slipID);
	setInt8Array(env, cls, j_ssat_obj, "half", NFREQ, ssat.half, halfID);
	setIntArray(env, cls, j_ssat_obj, "v", NFREQ, ssat.lock, lockID);
	setInt32Array(env, cls, j_ssat_obj, "outc", NFREQ, ssat.outc, outcID);
	setInt32Array(env, cls, j_ssat_obj, "slipc", NFREQ, ssat.slipc, slipcID);
	setInt32Array(env, cls, j_ssat_obj, "rejc", NFREQ, ssat.rejc, rejcID);
	setDoubleArray(env, cls, j_ssat_obj, "gf", NFREQ - 1, ssat.gf, gfID);
	setDoubleArray(env, cls, j_ssat_obj, "mw", NFREQ - 1, ssat.mw, mwID);
	(*env).SetDoubleField(j_ssat_obj, phwID, ssat.phw);

	timeArray = (jobjectArray)env->GetObjectField(j_ssat_obj, ptID);
	for (int i = 0; i < 2; i++)
	{
		timeArray2 = (jobjectArray)(*env).GetObjectArrayElement(timeArray, i);
		for (int j = 0; j < NFREQ; j++)
		{
			jobject time_obj = (*env).GetObjectArrayElement(timeArray2, j);
			GtimeT::convertJavaGtimeT(env, ssat.pt[i][j], time_obj);
		}
	}

	phArray = (jobjectArray)env->GetObjectField(j_ssat_obj, phID);
	for (int i = 0; i < 2; i++)
	{
		jdouble tempbuf[NFREQ];
		jdoubleArray phArray2 = (jdoubleArray)env->GetObjectArrayElement(phArray, i);
		for (int j = 0; j < NFREQ; j++)
		{
			tempbuf[j] = ssat.ph[i][j];
		}
		env->SetDoubleArrayRegion(phArray2, 0, NFREQ, tempbuf);
	}

}


