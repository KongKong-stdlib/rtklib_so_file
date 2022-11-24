#include "NavT.h"
#include "EphT.h"
#include "GephT.h"
NavT::NavT()
{
}


NavT::~NavT()
{
}


int NavT::initNavT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/NavT");
	nID = (*env).GetFieldID(cls, "n", "I");
	nmaxID = (*env).GetFieldID(cls, "nmax", "I");
	ngID = (*env).GetFieldID(cls, "ng", "I");
	ngmaxID = (*env).GetFieldID(cls, "ngmax", "I");

	ephID = (*env).GetFieldID(cls, "eph", "[Lrtk/model/EphT;");
	gephID = (*env).GetFieldID(cls, "geph", "[Lrtk/model/GephT;");
	
	utc_gpsID = (*env).GetFieldID(cls, "utc_gps", "[D");
	utc_gloID = (*env).GetFieldID(cls, "utc_glo", "[D");
	utc_galID = (*env).GetFieldID(cls, "utc_gal", "[D");
	utc_qzsID = (*env).GetFieldID(cls, "utc_qzs", "[D");
	utc_cmpID = (*env).GetFieldID(cls, "utc_cmp", "[D");
	utc_irnID = (*env).GetFieldID(cls, "utc_irn", "[D");
	utc_sbsID = (*env).GetFieldID(cls, "utc_sbs", "[D");


	ion_gpsID = (*env).GetFieldID(cls, "ion_gps", "[D");
	ion_galID = (*env).GetFieldID(cls, "ion_gal", "[D");
	ion_qzsID = (*env).GetFieldID(cls, "ion_qzs", "[D");
	ion_cmpID = (*env).GetFieldID(cls, "ion_cmp", "[D");
	ion_irnID = (*env).GetFieldID(cls, "ion_irn", "[D");
	glo_fcnID = (*env).GetFieldID(cls, "glo_fcn", "[I");
	
	j_nav_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

void NavT::convertCNavT(JNIEnv *env, jobject nav_obj,nav_t *nav)
{
	static jobject time_obj;
	static jdoubleArray tempJdoubleArray;
	static jintArray tempJintArray;
	static jdouble tempBuf[9];
	static jint tempBuf2[32];
	static jobjectArray jdataArray;
	static jobject jdata;
	if (nav_obj != NULL)
	{
		nav->n = env->GetIntField(nav_obj, nID);
		nav->nmax = env->GetIntField(nav_obj, nmaxID);
		nav->ng = env->GetIntField(nav_obj, ngID);
		nav->ngmax = env->GetIntField(nav_obj, ngmaxID);

		jdataArray = (jobjectArray)(*env).GetObjectField(nav_obj, ephID);
		for (int i = 0; i < nav->n; i++)
		{
			jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				eph_t eph = EphT::convertCEphT(env, jdata);
				nav->eph[i] = eph;
			}

		}

		jdataArray = (jobjectArray)(*env).GetObjectField(nav_obj, gephID);
		for (int i = 0; i < nav->ng; i++)
		{
			jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				geph_t geph = GephT::convertCGephT(env, jdata);
				nav->geph[i] = geph;
			}
		}

		/*int i = 0;
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_gpsID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->utc_gps[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_gloID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->utc_glo[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_galID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->utc_gal[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_qzsID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->utc_qzs[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_cmpID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->utc_cmp[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_irnID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 9, tempBuf);
		for (i = 0; i < 9; i++)
		{
			nav->utc_irn[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, utc_sbsID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 4, tempBuf);
		for (i = 0; i < 4; i++)
		{
			nav->utc_sbs[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, ion_gpsID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->ion_gps[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, ion_galID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 4, tempBuf);
		for (i = 0; i < 4; i++)
		{
			nav->ion_gal[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, ion_qzsID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->ion_qzs[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, ion_cmpID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->ion_cmp[i] = tempBuf[i];
		}

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(nav_obj, ion_irnID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 8, tempBuf);
		for (i = 0; i < 8; i++)
		{
			nav->ion_irn[i] = tempBuf[i];
		}

		tempJintArray = (jintArray)env->GetObjectField(nav_obj, glo_fcnID);
		if (tempJintArray != NULL)
			env->GetIntArrayRegion(tempJintArray, 0, 32, tempBuf2);
		for (i = 0; i < 8; i++)
		{
			nav->glo_fcn[i] = tempBuf2[i];
		}*/

	}
	return ;

}
