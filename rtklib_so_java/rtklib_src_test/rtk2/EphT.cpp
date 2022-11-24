//#include "EphT.h"
#include "rtklib_java.h"

EphT::EphT()
{
}


EphT::~EphT()
{
}

int EphT::initEphT(JNIEnv *env)
{
	cls = (*env).FindClass("rtk/model/EphT");
	satID = (*env).GetFieldID(cls, "sat", "I");
	iodeID = (*env).GetFieldID(cls, "iode", "I");
	iodcID = (*env).GetFieldID(cls, "iodc", "I");
	svaID = (*env).GetFieldID(cls, "sva", "I");
	svhID = (*env).GetFieldID(cls, "svh", "I");
	weekID = (*env).GetFieldID(cls, "week", "I");
	codeID = (*env).GetFieldID(cls, "code", "I");
	flagID = (*env).GetFieldID(cls, "flag", "I");

	toeID = (*env).GetFieldID(cls, "toe", "Lrtk/model/GtimeT;");
	tocID = (*env).GetFieldID(cls, "toc", "Lrtk/model/GtimeT;");
	ttrID = (*env).GetFieldID(cls, "ttr", "Lrtk/model/GtimeT;");

	AID = (*env).GetFieldID(cls, "A", "D");
	eID = (*env).GetFieldID(cls, "e", "D");
	i0ID = (*env).GetFieldID(cls, "i0", "D");
	OMG0ID = (*env).GetFieldID(cls, "OMG0", "D");
	omgID = (*env).GetFieldID(cls, "omg", "D");
	M0ID = (*env).GetFieldID(cls, "M0", "D");
	delnID = (*env).GetFieldID(cls, "deln", "D");
	OMGdID = (*env).GetFieldID(cls, "OMGd", "D");
	idotID = (*env).GetFieldID(cls, "idot", "D");
	crcID = (*env).GetFieldID(cls, "crc", "D");
	crsID = (*env).GetFieldID(cls, "crs", "D");
	cucID = (*env).GetFieldID(cls, "cuc", "D");
	cusID = (*env).GetFieldID(cls, "cus", "D");
	cicID = (*env).GetFieldID(cls, "cic", "D");
	cisID = (*env).GetFieldID(cls, "cis", "D");
	toesID = (*env).GetFieldID(cls, "toes", "D");
	fitID = (*env).GetFieldID(cls, "fit", "D");
	f0ID = (*env).GetFieldID(cls, "f0", "D");
	f1ID = (*env).GetFieldID(cls, "f1", "D");
	f2ID = (*env).GetFieldID(cls, "f2", "D");

	tgdID = (*env).GetFieldID(cls, "tgd", "[D");
	AdotID = (*env).GetFieldID(cls, "Adot", "D");
	ndotID = (*env).GetFieldID(cls, "ndot", "D");


	j_eph_methodID = (*env).GetMethodID(cls, "<init>", "()V");
	return 0;
}

eph_t EphT::convertCEphT(JNIEnv *env, jobject eph_obj)
{
	eph_t eph = { 0 };
	static jobject time_obj;
	static jdoubleArray tempJdoubleArray;
	static jdouble tempBuf[6];
	if (eph_obj != NULL)
	{
		eph.sat = env->GetIntField(eph_obj, satID);
		eph.iode = env->GetIntField(eph_obj, iodeID);
		eph.iodc = env->GetIntField(eph_obj, iodcID);
		eph.sva = env->GetIntField(eph_obj, svaID);
		eph.svh = env->GetIntField(eph_obj, svhID);
		eph.week = env->GetIntField(eph_obj, weekID);
		eph.code = env->GetIntField(eph_obj, codeID);
		eph.flag = env->GetIntField(eph_obj, flagID);

		time_obj = env->GetObjectField(eph_obj, toeID);
		eph.toe = GtimeT::convertCGtimeT(env, time_obj);

		time_obj = env->GetObjectField(eph_obj, tocID);
		eph.toc = GtimeT::convertCGtimeT(env, time_obj);

		time_obj = env->GetObjectField(eph_obj, ttrID);
		eph.ttr = GtimeT::convertCGtimeT(env, time_obj);

		eph.A = env->GetDoubleField(eph_obj, AID);
		eph.e = env->GetDoubleField(eph_obj, eID);
		eph.i0 = env->GetDoubleField(eph_obj, i0ID);
		eph.OMG0 = env->GetDoubleField(eph_obj, OMG0ID);
		eph.omg = env->GetDoubleField(eph_obj, omgID);

		eph.M0 = env->GetDoubleField(eph_obj, M0ID);
		eph.deln = env->GetDoubleField(eph_obj, delnID);
		eph.OMGd = env->GetDoubleField(eph_obj, OMGdID);
		eph.idot = env->GetDoubleField(eph_obj, idotID);
		eph.crc = env->GetDoubleField(eph_obj, crcID);
		eph.crs = env->GetDoubleField(eph_obj, crsID);

		eph.cuc = env->GetDoubleField(eph_obj, cucID);
		eph.cus = env->GetDoubleField(eph_obj, cusID);
		eph.cic = env->GetDoubleField(eph_obj, cicID);
		eph.cis = env->GetDoubleField(eph_obj, cisID);

		eph.toes = env->GetDoubleField(eph_obj, toesID);
		eph.fit = env->GetDoubleField(eph_obj, fitID);
		eph.f0 = env->GetDoubleField(eph_obj, f0ID);
		eph.f1 = env->GetDoubleField(eph_obj, f1ID);
		eph.f2 = env->GetDoubleField(eph_obj, f2ID);
		int i = 0;
		tempJdoubleArray = (jdoubleArray)env->GetObjectField(eph_obj, tgdID);
		if (tempJdoubleArray != NULL)
			env->GetDoubleArrayRegion(tempJdoubleArray, 0, 6, tempBuf);
		for (i = 0; i < 6; i++)
		{
			eph.tgd[i] = tempBuf[i];
		}

		eph.Adot = env->GetDoubleField(eph_obj, AdotID);
		eph.ndot = env->GetDoubleField(eph_obj, ndotID);

	}
	return eph;

}

