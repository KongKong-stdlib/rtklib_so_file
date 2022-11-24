#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "GtimeT.h"
class GephT
{
public:
	GephT();
	~GephT();

	static jclass cls;
	static jfieldID satID;
	static jfieldID iodeID;
	static jfieldID frqID;
	static jfieldID svaID;
	static jfieldID svhID;
	static jfieldID ageID;

	static jfieldID toeID;
	static jfieldID tofID;


	static jfieldID posID;
	static jfieldID velID;
	static jfieldID accID;

	static jfieldID taunID;
	static jfieldID gamnID;
	static jfieldID dtaunID;

	static jmethodID j_geph_methodID;

	static int initGephT(JNIEnv *env);

	static geph_t convertCGephT(JNIEnv *env, jobject geph_obj);
};

