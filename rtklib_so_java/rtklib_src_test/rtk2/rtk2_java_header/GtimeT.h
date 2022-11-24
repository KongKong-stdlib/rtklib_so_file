#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
class GtimeT
{
public:
	GtimeT();
	~GtimeT();
	static jclass cls;
	static jfieldID timeID ;
	static jfieldID secID;
	static int initGtimeT(JNIEnv *env);
	static gtime_t convertCGtimeT(JNIEnv *env, jobject gtime_obj);
	static void convertJavaGtimeT(JNIEnv *env, gtime_t gtime, jobject j_time_obj);

	static jmethodID j_gtime_methodID;

};

