#include "RtkT.h"
#include "rtkjni.h"
#include "PrcoptT.h"

RtkT::RtkT()
{
}


RtkT::~RtkT()
{
}

int RtkT::initRtkT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/RtkT");

	solID = (*env).GetFieldID(cls, "sol", "Lrtk/model/SolT;");
	rbID = (*env).GetFieldID(cls, "rb", "[D");
	nxID = (*env).GetFieldID(cls, "nx", "I");
	naID = (*env).GetFieldID(cls, "na", "I");
	ttID = (*env).GetFieldID(cls, "tt", "D");

	xID = (*env).GetFieldID(cls, "x", "[D");
	PID = (*env).GetFieldID(cls, "P", "[D");
	xaID = (*env).GetFieldID(cls, "xa", "[D");
	PaID = (*env).GetFieldID(cls, "Pa", "[D");

	nfixID = (*env).GetFieldID(cls, "nfix", "I");
	ambcID = (*env).GetFieldID(cls, "ambc", "[Lrtk/model/AmbcT;");
	ssatID = (*env).GetFieldID(cls, "ssat", "[Lrtk/model/SsatT;");

	nebID = (*env).GetFieldID(cls, "neb", "I");
	errbufID = (*env).GetFieldID(cls, "errbuf", "[C");

	optID = (*env).GetFieldID(cls, "opt", "Lrtk/model/PrcoptT;");
	return 0;
}

void RtkT::convertJavaRtk(JNIEnv *env, rtk_t rtk, jobject j_rtk_obj)
{
	static jobject j_sol_obj;
	static jobject j_opt_obj;
	static jobjectArray ssatArray;
	j_sol_obj = env->GetObjectField(j_rtk_obj, solID);
	SolT::convertJavaSol(env, rtk.sol, j_sol_obj);

	setDoubleArray(env, cls, j_rtk_obj, "rb", 6, rtk.rb, rbID);
	(*env).SetIntField(j_rtk_obj, nxID, rtk.nx);
	(*env).SetIntField(j_rtk_obj, naID, rtk.na);

	(*env).SetDoubleField(j_rtk_obj, ttID, rtk.tt);

	setDoubleArray(env, cls, j_rtk_obj, "x", rtk.nx, rtk.x, xID);
	setDoubleArray(env, cls, j_rtk_obj, "P", rtk.nx, rtk.P, PID);

	setDoubleArray(env, cls, j_rtk_obj, "xa", rtk.na, rtk.xa, xaID);
	setDoubleArray(env, cls, j_rtk_obj, "Pa", rtk.na, rtk.Pa, PaID);

	(*env).SetIntField(j_rtk_obj, nfixID, rtk.nfix);
	ssatArray = (jobjectArray)env->GetObjectField(j_rtk_obj, ssatID);
	
	for (int j = 0; j < MAXSAT; j++)
	{
		jobject ssat_obj = (*env).GetObjectArrayElement(ssatArray, j);
		SsatT::convertJavaSsat(env, rtk.ssat[j], ssat_obj);
	}
	//ambc处理
	//opt处理

	(*env).SetIntField(j_rtk_obj, nebID, rtk.neb);
	setCharArray(env, cls, j_rtk_obj, "errbuf", MAXERRMSG, rtk.errbuf, errbufID);

}

void RtkT::convertCRtk(JNIEnv *env, jobject j_rtk_obj, rtk_t* rtk)
{
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[400];
	static jobject opt_obj;
	int i = 0;
	if (j_rtk_obj != NULL)
	{
		/*sol_obj = env->GetObjectField(j_rtk_obj, solID);
		rtk->sol = SolT::convertCSol(env, sol_obj);*/

		tempJdoubleArray = (jdoubleArray)env->GetObjectField(j_rtk_obj, RtkT::rbID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0,6, tempBuf);
		for (i = 0; i < 6; i++)
		{
			rtk->rb[i] = tempBuf[i];
		}

		
		opt_obj = env->GetObjectField(j_rtk_obj, optID);
		rtk->opt = PrcoptT::convertCPrcoptT(env, opt_obj);
	}

	
	return ;
}


