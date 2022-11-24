#include "GtimeT.h"


GtimeT::GtimeT()
{
}


GtimeT::~GtimeT()
{
}


int GtimeT::initGtimeT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/GtimeT");
	timeID = (*env).GetFieldID(cls, "time", "J");
	secID = (*env).GetFieldID(cls, "sec", "D");

	j_gtime_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

gtime_t GtimeT::convertCGtimeT(JNIEnv *env, jobject gtime_obj)
{
	gtime_t gtime = { 0 };
	if (gtime_obj != NULL)
	{
		gtime.time = env->GetLongField(gtime_obj, GtimeT::timeID);
		gtime.sec = env->GetLongField(gtime_obj, GtimeT::secID);

	}
	return gtime;

}

void GtimeT::convertJavaGtimeT(JNIEnv *env, gtime_t gtime, jobject j_time_obj)
{
	env->SetLongField(j_time_obj, GtimeT::timeID, gtime.time);
	env->SetDoubleField(j_time_obj, GtimeT::secID, gtime.sec);
}
