#include "GephT.h"


GephT::GephT()
{
}


GephT::~GephT()
{
}

int GephT::initGephT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/GephT");
	satID = (*env).GetFieldID(cls, "sat", "I");
	iodeID = (*env).GetFieldID(cls, "iode", "I");
	frqID = (*env).GetFieldID(cls, "frq", "I");
	svaID = (*env).GetFieldID(cls, "sva", "I");
	svhID = (*env).GetFieldID(cls, "svh", "I");
	ageID = (*env).GetFieldID(cls, "age", "I");
	

	toeID = (*env).GetFieldID(cls, "toe", "Lrtk/model/GtimeT;");
	tofID = (*env).GetFieldID(cls, "tof", "Lrtk/model/GtimeT;");

	posID = (*env).GetFieldID(cls, "pos", "[D");
	velID = (*env).GetFieldID(cls, "vel", "[D");
	accID = (*env).GetFieldID(cls, "acc", "[D");


	taunID = (*env).GetFieldID(cls, "taun", "D");
	gamnID = (*env).GetFieldID(cls, "gamn", "D");
	dtaunID = (*env).GetFieldID(cls, "dtaun", "D");
	
	j_geph_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

geph_t GephT::convertCGephT(JNIEnv *env, jobject geph_obj)
{
	geph_t geph = { 0 };
	static jobject time_obj;
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[3];
	if (geph_obj != NULL)
	{
		geph.sat = env->GetIntField(geph_obj, satID);
		geph.iode = env->GetIntField(geph_obj, iodeID);
		geph.frq = env->GetIntField(geph_obj, frqID);
		geph.sva = env->GetIntField(geph_obj, svaID);
		geph.svh = env->GetIntField(geph_obj, svhID);
		geph.age = env->GetIntField(geph_obj, ageID);


		time_obj = env->GetObjectField(geph_obj, toeID);
		geph.toe = GtimeT::convertCGtimeT(env, time_obj);

		time_obj = env->GetObjectField(geph_obj, tofID);
		geph.tof = GtimeT::convertCGtimeT(env, time_obj);


		geph.taun = env->GetDoubleField(geph_obj, taunID);
		geph.gamn = env->GetDoubleField(geph_obj, gamnID);
		geph.dtaun = env->GetDoubleField(geph_obj, dtaunID);
		
		int i = 0;
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(geph_obj, posID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 3, tempBuf);
		for (i = 0; i < 3; i++)
		{
			geph.pos[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(geph_obj, velID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 3, tempBuf);
		for (i = 0; i < 3; i++)
		{
			geph.vel[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(geph_obj, accID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 3, tempBuf);
		for (i = 0; i < 3; i++)
		{
			geph.acc[i] = tempBuf[i];
		}



	}
	return geph;

}
