#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "GtimeT.h"
class EphT
{
public:
	EphT();
	~EphT();
	static jclass cls;
	static jfieldID satID;
	static jfieldID iodeID;
	static jfieldID iodcID;
	static jfieldID svaID;
	static jfieldID svhID;
	static jfieldID weekID;
	static jfieldID codeID;
	static jfieldID flagID;
	static jfieldID toeID;
	static jfieldID tocID;
	static jfieldID ttrID;

	static jfieldID AID;
	static jfieldID eID;
	static jfieldID i0ID;
	static jfieldID OMG0ID;
	static jfieldID omgID;
	static jfieldID M0ID;
	static jfieldID delnID;
	static jfieldID OMGdID;
	static jfieldID idotID;

	static jfieldID crcID;
	static jfieldID crsID;
	static jfieldID cucID;
	static jfieldID cusID;
	static jfieldID cicID;
	static jfieldID cisID;
	static jfieldID toesID;
	static jfieldID fitID;

	static jfieldID f0ID;
	static jfieldID f1ID;
	static jfieldID f2ID;

	static jfieldID tgdID;
	static jfieldID AdotID;
	static jfieldID ndotID;

	static jmethodID j_eph_methodID;

	static int initEphT(JNIEnv *env);

	static eph_t convertCEphT(JNIEnv *env, jobject eph_obj);
};


