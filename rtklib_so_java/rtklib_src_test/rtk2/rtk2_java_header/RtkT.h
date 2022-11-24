#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "SolT.h"
#include "SsatT.h"
class RtkT
{
public:
	RtkT();
	~RtkT();

	static jclass cls;
	static jfieldID solID;
	static jfieldID rbID;
	static jfieldID nxID;
	static jfieldID naID;
	static jfieldID ttID;
	static jfieldID xID;
	static jfieldID PID;
	static jfieldID xaID;
	static jfieldID PaID;
	static jfieldID nfixID;
	static jfieldID ambcID;
	static jfieldID ssatID;
	static jfieldID nebID;
	static jfieldID errbufID;
	static jfieldID optID;

	static int initRtkT(JNIEnv *env);
	static void convertJavaRtk(JNIEnv *env, rtk_t rtk, jobject j_rtk_obj);
	static void convertCRtk(JNIEnv *env, jobject j_rtk_obj, rtk_t* rtk);

};


