#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
class SsatT
{
public:
	SsatT();
	~SsatT();
	static jclass cls;
	static jfieldID sysID;
	static jfieldID vsID;
	static jfieldID azelID;
	static jfieldID respID;
	static jfieldID rescID;
	static jfieldID vsatID;
	static jfieldID snrID;
	static jfieldID fixID;
	static jfieldID slipID;
	static jfieldID halfID;
	static jfieldID lockID;
	static jfieldID outcID;
	static jfieldID slipcID;
	static jfieldID rejcID;
	static jfieldID gfID;
	static jfieldID mwID;
	static jfieldID phwID;
	static jfieldID ptID;
	static jfieldID phID;
	static jmethodID j_ssat_methodID;

	static int initSsatT(JNIEnv *env);
	static void convertJavaSsat(JNIEnv *env, ssat_t ssat, jobject j_ssat_obj);
	static ssat_t convertCSsat(JNIEnv *env, jobject j_ssat_obj);
};



