#pragma once
#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "GtimeT.h"
class NavT
{
public:
	NavT();
	~NavT();
	static jclass cls;

	static jfieldID nID;
	static jfieldID nmaxID;
	static jfieldID ngID;
	static jfieldID ngmaxID;
	static jfieldID ephID;
	static jfieldID gephID;

	static jfieldID utc_gpsID;
	static jfieldID utc_gloID;
	static jfieldID utc_galID;
	static jfieldID utc_qzsID;
	static jfieldID utc_cmpID;
	static jfieldID utc_irnID;
	static jfieldID utc_sbsID;
	static jfieldID ion_gpsID;
	static jfieldID ion_galID;
	static jfieldID ion_qzsID;
	static jfieldID ion_cmpID;
	static jfieldID ion_irnID;
	static jfieldID glo_fcnID;

	static jmethodID j_nav_methodID;

	static int initNavT(JNIEnv *env);

	//static void NavT::convertCNavT(JNIEnv *env, jobject nav_obj, nav_t* nav);
	static void convertCNavT(JNIEnv *env, jobject nav_obj, nav_t* nav);

};


