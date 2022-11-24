#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "GtimeT.h"
class ObsdT
{
public:
	ObsdT();
	~ObsdT();
	static jclass cls;
	static jfieldID timeID;
	static jfieldID satID;
	static jfieldID rcvID;

	static jfieldID SNRID;
	static jfieldID LLIID;
	static jfieldID codeID;
	static jfieldID LID;
	static jfieldID PID;
	static jfieldID DID;


	static int initObsdT(JNIEnv *env);
	static obsd_t convertCObsdT(JNIEnv *env, jobject obsd_obj);
	static void convertJavaObsd(JNIEnv *env, obsd_t obsd, jobject j_obsd_obj);

	static jmethodID j_obsd_methodID;

	
};


