#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
class PrcoptT
{
public:
	PrcoptT();
	~PrcoptT();

	static jclass cls;
	static jfieldID navsysID;
	static jfieldID ionooptID;
	static jfieldID tropoptID;
	static jfieldID elminID;
	static jfieldID nfID;
	static jfieldID satephID;
	static jfieldID modeID;
	static jfieldID modearID;
	static jfieldID refposID;
	static jfieldID rbID;
	static jfieldID bdsmodearID;
	static jfieldID glomodearID;
	static jfieldID soltypeID;
	static jfieldID validThresARID;

	static int initPrcoptT(JNIEnv *env);
	static prcopt_t convertCPrcoptT(JNIEnv *env, jobject opt_obj);
};


