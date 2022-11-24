#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "GtimeT.h"
class SolT
{
public:
	SolT();
	~SolT();

	static jclass cls;
	static jfieldID timeID;
	static jfieldID rrID;
	static jfieldID qrID;

	static jfieldID qvID;
	static jfieldID dtrID;
	static jfieldID typeID;
	static jfieldID statID;
	static jfieldID nsID;
	static jfieldID ageID;
	static jfieldID ratioID;
	static jfieldID thresID;

	static jmethodID j_sol_methodID;

	static int initSolT(JNIEnv *env);
	static void convertJavaSol(JNIEnv *env, sol_t sol, jobject j_sol_obj);
	static sol_t convertCSol(JNIEnv *env, jobject j_sol_obj);

	
};

