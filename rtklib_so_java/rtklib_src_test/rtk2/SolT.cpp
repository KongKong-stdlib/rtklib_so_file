#include "SolT.h"
#include "rtkjni.h"


SolT::SolT()
{
}


SolT::~SolT()
{
}

int SolT::initSolT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/SolT");

	timeID = (*env).GetFieldID(cls, "time", "Lrtk/model/GtimeT;");
	rrID = (*env).GetFieldID(cls, "rr", "[D");
	qrID = (*env).GetFieldID(cls, "qr", "[F");
	qvID = (*env).GetFieldID(cls, "qv", "[F");
	dtrID = (*env).GetFieldID(cls, "dtr", "[D");

	typeID = (*env).GetFieldID(cls, "type", "I");
	statID = (*env).GetFieldID(cls, "stat", "I");
	nsID = (*env).GetFieldID(cls, "ns", "I");

	ageID = (*env).GetFieldID(cls, "age", "F");
	ratioID = (*env).GetFieldID(cls, "ratio", "F");
	thresID = (*env).GetFieldID(cls, "thres", "F");

	j_sol_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

void SolT::convertJavaSol(JNIEnv *env, sol_t sol, jobject j_sol_obj)
{
	jobject time_obj = (*env).GetObjectField(j_sol_obj, timeID);
	env->SetLongField(time_obj, GtimeT::timeID, sol.time.time);
	env->SetDoubleField(time_obj, GtimeT::secID, sol.time.sec);
	//GtimeT::convertJavaGtimeT(env, sol.time, time_obj);
	//(*env).SetObjectField(j_sol_obj, timeID, time_obj);

	(*env).SetIntField(j_sol_obj, typeID, sol.type);
	(*env).SetIntField(j_sol_obj, statID, sol.stat);
	(*env).SetIntField(j_sol_obj, nsID, sol.ns);

	setDoubleArray(env, cls, j_sol_obj, "rr", 6, sol.rr, rrID);
	setFloatArray(env, cls, j_sol_obj, "qr", 6, sol.qr, qrID);
	setFloatArray(env, cls, j_sol_obj, "qv", 6, sol.qv, qvID);
	setDoubleArray(env, cls, j_sol_obj, "dtr", 6, sol.dtr, dtrID);

	(*env).SetFloatField(j_sol_obj, ageID, sol.age);
	(*env).SetFloatField(j_sol_obj, ratioID, sol.ratio);
	(*env).SetFloatField(j_sol_obj, thresID, sol.thres);
}

sol_t SolT::convertCSol(JNIEnv *env,jobject j_sol_obj)
{
	sol_t sol = { 0 };
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[6];
	if (j_sol_obj != NULL)
	{
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_sol_obj, rrID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 6, tempBuf);
		for (int i = 0; i < 6; i++)
		{
			sol.rr[i] = tempBuf[i];
		}
	}
	return sol;
}
