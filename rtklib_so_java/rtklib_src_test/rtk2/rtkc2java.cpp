#include "jni/jni.h"
#include "rtkjni.h"
#include "../src/rtklib.h"

jobject convertJavaEphT(JNIEnv *env, eph_t epht)
{
	jclass j_eph = (*env).FindClass("rtk/model/EphT");
	jmethodID jmethodID = (*env).GetMethodID(j_eph, "<init>", "()V");
	jobject epht_obj = (*env).NewObjectA(j_eph, jmethodID, 0);

	setIntParam(env, j_eph, epht_obj, "sat", epht.sat);
	setIntParam(env, j_eph, epht_obj, "iode", epht.iode);
	setIntParam(env, j_eph, epht_obj, "iodc", epht.iodc);
	setIntParam(env, j_eph, epht_obj, "sva", epht.sva);
	setIntParam(env, j_eph, epht_obj, "svh", epht.svh);
	setIntParam(env, j_eph, epht_obj, "week", epht.week);
	setIntParam(env, j_eph, epht_obj, "code", epht.code);
	setIntParam(env, j_eph, epht_obj, "flag", epht.flag);
	setGtime(env, j_eph, epht_obj, "toe", epht.toe);
	setGtime(env, j_eph, epht_obj, "toc", epht.toc);
	setGtime(env, j_eph, epht_obj, "ttr", epht.ttr);
	setDoubleParam(env, j_eph, epht_obj, "A", epht.A);
	setDoubleParam(env, j_eph, epht_obj, "e", epht.e);
	setDoubleParam(env, j_eph, epht_obj, "i0", epht.i0);
	setDoubleParam(env, j_eph, epht_obj, "OMG0", epht.OMG0);
	setDoubleParam(env, j_eph, epht_obj, "omg", epht.omg);
	setDoubleParam(env, j_eph, epht_obj, "M0", epht.M0);
	setDoubleParam(env, j_eph, epht_obj, "deln", epht.deln);
	setDoubleParam(env, j_eph, epht_obj, "OMGd", epht.OMGd);
	setDoubleParam(env, j_eph, epht_obj, "idot", epht.idot);
	setDoubleParam(env, j_eph, epht_obj, "crc", epht.crc);
	setDoubleParam(env, j_eph, epht_obj, "crs", epht.crs);
	setDoubleParam(env, j_eph, epht_obj, "cuc", epht.cuc);
	setDoubleParam(env, j_eph, epht_obj, "cus", epht.cus);
	setDoubleParam(env, j_eph, epht_obj, "cic", epht.cic);
	setDoubleParam(env, j_eph, epht_obj, "cis", epht.cis);
	setDoubleParam(env, j_eph, epht_obj, "toes", epht.toes);
	setDoubleParam(env, j_eph, epht_obj, "fit", epht.fit);
	setDoubleParam(env, j_eph, epht_obj, "f0", epht.f0);
	setDoubleParam(env, j_eph, epht_obj, "f1", epht.f1);
	setDoubleParam(env, j_eph, epht_obj, "f2", epht.f2);
	setDoubleArrayParam(env, j_eph, epht_obj, "tgd", 6, epht.tgd);
	setDoubleParam(env, j_eph, epht_obj, "Adot", epht.Adot);
	setDoubleParam(env, j_eph, epht_obj, "ndot", epht.ndot);
	env->DeleteLocalRef(j_eph);
	return epht_obj;
}

jobject convertJavaGephT(JNIEnv *env, geph_t gepht)
{
	jclass j_geph = (*env).FindClass("rtk/model/GephT");
	jmethodID jmethodID = (*env).GetMethodID(j_geph, "<init>", "()V");
	jobject gepht_obj = (*env).NewObjectA(j_geph, jmethodID, 0);

	setIntParam(env, j_geph, gepht_obj, "sat", gepht.sat);
	setIntParam(env, j_geph, gepht_obj, "iode", gepht.iode);
	setIntParam(env, j_geph, gepht_obj, "frq", gepht.frq);

	setIntParam(env, j_geph, gepht_obj, "svh", gepht.svh);
	setIntParam(env, j_geph, gepht_obj, "sva", gepht.sva);
	setIntParam(env, j_geph, gepht_obj, "age", gepht.age);

	setGtime(env, j_geph, gepht_obj, "toe", gepht.toe);
	setGtime(env, j_geph, gepht_obj, "tof", gepht.tof);
	setDoubleArrayParam(env, j_geph, gepht_obj, "pos", 3, gepht.pos);
	setDoubleArrayParam(env, j_geph, gepht_obj, "vel", 3, gepht.vel);
	setDoubleArrayParam(env, j_geph, gepht_obj, "acc", 3, gepht.acc);

	setDoubleParam(env, j_geph, gepht_obj, "taun", gepht.age);
	setDoubleParam(env, j_geph, gepht_obj, "gamn", gepht.gamn);
	setDoubleParam(env, j_geph, gepht_obj, "dtaun", gepht.dtaun);
	env->DeleteLocalRef(j_geph);
	return gepht_obj;
}

jobject convertJavaSephT(JNIEnv *env, seph_t sepht)
{
	jclass j_seph = (*env).FindClass("rtk/model/SephT");
	jmethodID jmethodID = (*env).GetMethodID(j_seph, "<init>", "()V");
	jobject sepht_obj = (*env).NewObjectA(j_seph, jmethodID, 0);

	setIntParam(env, j_seph, sepht_obj, "sat", sepht.sat);

	setGtime(env, j_seph, sepht_obj, "t0", sepht.t0);
	setGtime(env, j_seph, sepht_obj, "tof", sepht.tof);
	setIntParam(env, j_seph, sepht_obj, "sva", sepht.sva);
	setIntParam(env, j_seph, sepht_obj, "svh", sepht.svh);

	setDoubleArrayParam(env, j_seph, sepht_obj, "pos", 3, sepht.pos);
	setDoubleArrayParam(env, j_seph, sepht_obj, "vel", 3, sepht.vel);
	setDoubleArrayParam(env, j_seph, sepht_obj, "acc", 3, sepht.acc);

	setDoubleParam(env, j_seph, sepht_obj, "af0", sepht.af0);
	setDoubleParam(env, j_seph, sepht_obj, "af1", sepht.af1);
	env->DeleteLocalRef(j_seph);
	return sepht_obj;
}

jobject convertJavaPephT(JNIEnv *env, peph_t pepht)
{
	jclass j_peph = (*env).FindClass("rtk/model/PephT");
	jmethodID jmethodID = (*env).GetMethodID(j_peph, "<init>", "()V");
	jobject pepht_obj = (*env).NewObjectA(j_peph, jmethodID, 0);

	setGtime(env, j_peph, pepht_obj, "time", pepht.time);
	setIntParam(env, j_peph, pepht_obj, "index", pepht.index);
	setDoubleArrayParam22(env, j_peph, pepht_obj, "pos",pepht.pos);
	setFloatArrayParam21(env, j_peph, pepht_obj, "std",pepht.std);
	setDoubleArrayParam22(env, j_peph, pepht_obj, "vel", pepht.vel);
	setFloatArrayParam21(env, j_peph, pepht_obj, "vst", pepht.vst);
	setFloatArrayParam22(env, j_peph, pepht_obj, "cov",pepht.cov);
	setFloatArrayParam22(env, j_peph, pepht_obj, "vco", pepht.vco);
	env->DeleteLocalRef(j_peph);
	return pepht_obj;
}

jobject convertJavaPclkT(JNIEnv *env, pclk_t pclkt)
{
	jclass j_pclk = (*env).FindClass("rtk/model/PclkT");
	jmethodID jmethodID = (*env).GetMethodID(j_pclk, "<init>", "()V");
	jobject pclk_obj = (*env).NewObjectA(j_pclk, jmethodID, 0);

	setGtime(env, j_pclk, pclk_obj, "time", pclkt.time);
	setIntParam(env, j_pclk, pclk_obj, "index", pclkt.index);
	setDoubleArrayParam23(env, j_pclk, pclk_obj, "clk", pclkt.clk);
	setFloatArrayParam23(env, j_pclk, pclk_obj, "std", pclkt.std);
	env->DeleteLocalRef(j_pclk);
	return pclk_obj;
}

jobject convertJavaAlmT(JNIEnv *env, alm_t almt)
{
	jclass j_alm = (*env).FindClass("rtk/model/AlmT");
	jmethodID jmethodID = (*env).GetMethodID(j_alm, "<init>", "()V");
	jobject alm_obj = (*env).NewObjectA(j_alm, jmethodID, 0);

	setIntParam(env, j_alm, alm_obj, "sat", almt.sat);
	setIntParam(env, j_alm, alm_obj, "svh", almt.svh);
	setIntParam(env, j_alm, alm_obj, "svconf", almt.svconf);
	setIntParam(env, j_alm, alm_obj, "week", almt.week);
	setGtime(env, j_alm, alm_obj, "toa", almt.toa);

	setDoubleParam(env, j_alm, alm_obj, "A", almt.A);
	setDoubleParam(env, j_alm, alm_obj, "e", almt.e);
	setDoubleParam(env, j_alm, alm_obj, "i0", almt.i0);

	setDoubleParam(env, j_alm, alm_obj, "OMG0", almt.OMG0);
	setDoubleParam(env, j_alm, alm_obj, "omg", almt.omg);
	setDoubleParam(env, j_alm, alm_obj, "M0", almt.M0);
	setDoubleParam(env, j_alm, alm_obj, "OMGd", almt.OMGd);
	setDoubleParam(env, j_alm, alm_obj, "toas", almt.toas);
	setDoubleParam(env, j_alm, alm_obj, "f0", almt.f0);
	setDoubleParam(env, j_alm, alm_obj, "f1", almt.f1);
	env->DeleteLocalRef(j_alm);
	return alm_obj;
}

jobject convertJavaTecT(JNIEnv *env, tec_t tect)
{
	jclass j_tec = (*env).FindClass("rtk/model/TecT");
	jmethodID jmethodID = (*env).GetMethodID(j_tec, "<init>", "()V");
	jobject tec_obj = (*env).NewObjectA(j_tec, jmethodID, 0);

	int n = tect.ndata[0] * tect.ndata[1] * tect.ndata[2];

	setGtime(env, j_tec, tec_obj, "time", tect.time);
	setIntArrayParam(env, j_tec, tec_obj, "ndata", 3, tect.ndata);
	setDoubleParam(env, j_tec, tec_obj, "rb", tect.rb);

	setDoubleArrayParam(env, j_tec, tec_obj, "lats", 3, tect.lats);
	setDoubleArrayParam(env, j_tec, tec_obj, "lons", 3, tect.lons);
	setDoubleArrayParam(env, j_tec, tec_obj, "hgts", 3, tect.hgts);

	setDoubleArrayParam(env, j_tec, tec_obj, "data", n, tect.data);
	setFloatArrayParam(env, j_tec, tec_obj, "rms", n, tect.rms);
	env->DeleteLocalRef(j_tec);
	return tec_obj;
}

jobject convertJavaErpdT(JNIEnv *env, erpd_t erpd)
{
	jclass j_erpd = (*env).FindClass("rtk/model/ErpdT");
	jmethodID jmethodID = (*env).GetMethodID(j_erpd, "<init>", "()V");
	jobject erpd_obj = (*env).NewObjectA(j_erpd, jmethodID, 0);

	setDoubleParam(env, j_erpd, erpd_obj, "mjd", erpd.mjd);
	setDoubleParam(env, j_erpd, erpd_obj, "xp", erpd.xp);
	setDoubleParam(env, j_erpd, erpd_obj, "yp", erpd.yp);
	setDoubleParam(env, j_erpd, erpd_obj, "xpr", erpd.xpr);

	setDoubleParam(env, j_erpd, erpd_obj, "ypr", erpd.ypr);
	setDoubleParam(env, j_erpd, erpd_obj, "ut1_utc", erpd.ut1_utc);
	setDoubleParam(env, j_erpd, erpd_obj, "lod", erpd.lod);
	env->DeleteLocalRef(j_erpd);
	return erpd_obj;
}


jobject convertJavaErpT(JNIEnv *env, erp_t erp)
{
	if (erp.n <= 0)
		return NULL;
	jclass j_erp = (*env).FindClass("rtk/model/ErpT");
	jmethodID jmethodID = (*env).GetMethodID(j_erp, "<init>", "()V");
	jobject erp_obj = (*env).NewObjectA(j_erp, jmethodID, 0);
	
	setIntParam(env, j_erp, erp_obj, "n", erp.n);
	setIntParam(env, j_erp, erp_obj, "nmax", erp.nmax);

	jfieldID field_id = (*env).GetFieldID(j_erp, "data", "[Lrtk/model/ErpdT;");
	jclass j_erpd = (*env).FindClass("rtk/model/ErpdT");
	jobjectArray jarray;
	
	jarray = (*env).NewObjectArray(erp.n, j_erpd, NULL);
	for (int i = 0; i < erp.n; i++)
	{
		(*env).SetObjectArrayElement(jarray, i, convertJavaErpdT(env, erp.data[i]));
	}
	
	(*env).SetObjectField(erp_obj, field_id, jarray);
	env->DeleteLocalRef(j_erp);
	env->DeleteLocalRef(j_erpd);
	env->DeleteLocalRef(jarray);
	
	return erp_obj;
}

jobject convertJavaPcvT(JNIEnv *env, pcv_t pcv)
{
	jclass j_pcv = (*env).FindClass("rtk/model/PcvT");
	jmethodID jmethodID = (*env).GetMethodID(j_pcv, "<init>", "()V");
	jobject pcv_obj = (*env).NewObjectA(j_pcv, jmethodID, 0);
	
	setIntParam(env, j_pcv, pcv_obj, "sat", pcv.sat);
	setCharArrayParam(env, j_pcv, pcv_obj, "type", MAXANT, pcv.type);
	setCharArrayParam(env, j_pcv, pcv_obj, "code", MAXANT, pcv.code);
	setGtime(env, j_pcv, pcv_obj, "ts", pcv.ts);
	setGtime(env, j_pcv, pcv_obj, "te", pcv.te);
	setDoubleArrayParam24(env, j_pcv, pcv_obj, "off", pcv.off);
	setDoubleArrayParam25(env, j_pcv, pcv_obj, "var", pcv.var);

	env->DeleteLocalRef(j_pcv);
	return pcv_obj;
}

jobject convertJavaSbsfcorrT(JNIEnv *env, sbsfcorr_t sbsfcorr)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsfcorrT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);

	setGtime(env, j_c, obj, "t0", sbsfcorr.t0);
	setDoubleParam(env, j_c, obj, "prc", sbsfcorr.prc);
	setDoubleParam(env, j_c, obj, "rrc", sbsfcorr.rrc);
	setDoubleParam(env, j_c, obj, "dt", sbsfcorr.dt);
	setIntParam(env, j_c, obj, "iodf", sbsfcorr.iodf);
	setIntParam(env, j_c, obj, "udre", sbsfcorr.udre);
	setIntParam(env, j_c, obj, "ai", sbsfcorr.ai);

	env->DeleteLocalRef(j_c);
	return obj;
}

jobject convertCSbslcorrT(JNIEnv *env, sbslcorr_t sbslcorr)
{
	jclass j_c = (*env).FindClass("rtk/model/SbslcorrT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);
	
	setGtime(env, j_c, obj, "t0", sbslcorr.t0);
	setIntParam(env, j_c, obj, "iode", sbslcorr.iode);
	setDoubleArrayParam(env, j_c, obj, "dpos", 3, sbslcorr.dpos);
	setDoubleArrayParam(env, j_c, obj, "dvel", 3, sbslcorr.dvel);

	setDoubleParam(env, j_c, obj, "daf0", sbslcorr.daf0);
	setDoubleParam(env, j_c, obj, "daf1", sbslcorr.daf1);
	env->DeleteLocalRef(j_c);
	return obj;
}

jobject convertJavaSbssatpT(JNIEnv *env, sbssatp_t sbssap)
{
	jclass j_c = (*env).FindClass("rtk/model/SbssatpT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);

	setIntParam(env, j_c, obj, "sat", sbssap.sat);

	jfieldID data_field_id = (*env).GetFieldID(j_c, "fcorr", "Lrtk/model/SbsfcorrT;");
	(*env).SetObjectField(obj, data_field_id, convertJavaSbsfcorrT(env, sbssap.fcorr));

	data_field_id = (*env).GetFieldID(j_c, "lcorr", "Lrtk/model/SbslcorrT;");
	(*env).SetObjectField(obj, data_field_id, convertCSbslcorrT(env, sbssap.lcorr));

	env->DeleteLocalRef(j_c);
	return obj;

}

jobject convertJavaSbssatT(JNIEnv *env, sbssat_t sbssat)
{
	jclass j_c = (*env).FindClass("rtk/model/SbssatT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);
	
	setIntParam(env, j_c, obj, "iodp", sbssat.iodp);
	setIntParam(env, j_c, obj, "nsat", sbssat.nsat);
	setIntParam(env, j_c, obj, "tlat", sbssat.tlat);

	jfieldID data_field_id = (*env).GetFieldID(j_c, "sat", "[Lrtk/model/SbssatpT;");
	jclass j_Sbssatp = (*env).FindClass("rtk/model/SbssatpT");
	jobjectArray jarray = (*env).NewObjectArray(MAXSAT, j_Sbssatp, NULL);
	for (int i = 0; i < MAXSAT; i++)
	{
		(*env).SetObjectArrayElement(jarray, i, convertJavaSbssatpT(env, sbssat.sat[i]));
	}
	(*env).SetObjectField(obj, data_field_id, jarray);
	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(j_Sbssatp);
	env->DeleteLocalRef(jarray);

	return obj;
}

jobject convertJavaSbsigpT(JNIEnv *env, sbsigp_t sbsigp)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsigpT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);
	
	setGtime(env, j_c, obj, "t0", sbsigp.t0);
	setIntParam(env, j_c, obj, "lat", sbsigp.lat);
	setIntParam(env, j_c, obj, "lon", sbsigp.lon);
	setIntParam(env, j_c, obj, "give", sbsigp.give);
	setFloatParam(env, j_c, obj, "delay", sbsigp.delay);
	return obj;
}

jobject convertJavaSbsionT(JNIEnv *env, sbsion_t sbsion)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsionT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);

	setIntParam(env, j_c, obj, "iodi", sbsion.iodi);
	setIntParam(env, j_c, obj, "nigp", sbsion.nigp);

	jfieldID data_field_id = (*env).GetFieldID(j_c, "igp", "[Lrtk/model/SbsigpT;");
	jclass j_Sbssatp = (*env).FindClass("rtk/model/SbsigpT");
	jobjectArray jarray = (*env).NewObjectArray(MAXNIGP, j_Sbssatp, NULL);
	for (int i = 0; i < MAXNIGP; i++)
	{
		(*env).SetObjectArrayElement(jarray, i, convertJavaSbsigpT(env, sbsion.igp[i]));
	}
	(*env).SetObjectField(obj, data_field_id, jarray);
	env->DeleteLocalRef(jarray);
	return obj;
}

jobject convertJavaDgpsT(JNIEnv *env, dgps_t dgps)
{
	jclass j_c = (*env).FindClass("rtk/model/DgpsT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);
	
	setGtime(env, j_c, obj, "t0", dgps.t0);
	setDoubleParam(env, j_c, obj, "prc", dgps.prc);
	setDoubleParam(env, j_c, obj, "rrc", dgps.rrc);
	setIntParam(env, j_c, obj, "iod", dgps.iod);
	setDoubleParam(env, j_c, obj, "udre", dgps.udre);
	env->DeleteLocalRef(j_c);
	return obj;
}

jobject convertJavaSsrT(JNIEnv *env, ssr_t ssr)
{
	jclass j_c = (*env).FindClass("rtk/model/SsrT");
	jmethodID jmethodID = (*env).GetMethodID(j_c, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_c, jmethodID, 0);

	jfieldID field_id = (*env).GetFieldID(j_c, "t0", "[Lrtk/model/GtimeT;");
	jclass j_class = (*env).FindClass("rtk/model/GtimeT");
	jobjectArray jarray_time = (*env).NewObjectArray(6, j_class, NULL);
	for (int i = 0; i < 6; i++)
	{
		(*env).SetObjectArrayElement(jarray_time, i, convertJavaGtimeT(env, ssr.t0[i]));
	}
	(*env).SetObjectField(obj, field_id, jarray_time);

	setDoubleArrayParam(env, j_c, obj, "udi", 6, ssr.udi);
	setIntArrayParam(env, j_c, obj, "iod", 6, ssr.iod);
	setIntParam(env, j_c, obj, "iode", ssr.iode);
	setIntParam(env, j_c, obj, "iodcrc", ssr.iodcrc);
	setIntParam(env, j_c, obj, "ura", ssr.ura);
	setIntParam(env, j_c, obj, "refd", ssr.refd);

	setDoubleArrayParam(env, j_c, obj, "deph", 3, ssr.deph);
	setDoubleArrayParam(env, j_c, obj, "ddeph", 3, ssr.ddeph);
	setDoubleArrayParam(env, j_c, obj, "dclk", 3, ssr.dclk);
	setDoubleParam(env, j_c, obj, "hrclk", ssr.hrclk);

	setFloatArrayParam(env, j_c, obj, "cbias", MAXCODE, ssr.cbias);
	setDoubleArrayParam(env, j_c, obj, "pbias", MAXCODE, ssr.pbias);
	setFloatArrayParam(env, j_c, obj, "stdpb", MAXCODE, ssr.stdpb);

	setDoubleParam(env, j_c, obj, "yaw_ang", ssr.yaw_ang);
	setDoubleParam(env, j_c, obj, "yaw_rate", ssr.yaw_rate);

	setIntParam(env, j_c, obj, "update", ssr.update);

	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(jarray_time);
	return obj;
}


void convertJavaNavT(JNIEnv *env, nav_t nav, jobject j_nav_obj)
{
	jclass j_nav = (*env).FindClass("rtk/model/NavT");

	setIntParam(env, j_nav, j_nav_obj, "n", nav.n);
	setIntParam(env, j_nav, j_nav_obj, "nmax", nav.nmax);
	setIntParam(env, j_nav, j_nav_obj, "ng", nav.ng);
	setIntParam(env, j_nav, j_nav_obj, "ngmax", nav.ngmax);
	setIntParam(env, j_nav, j_nav_obj, "ns", nav.ns);
	setIntParam(env, j_nav, j_nav_obj, "nsmax", nav.nsmax);

	setIntParam(env, j_nav, j_nav_obj, "ne", nav.nemax);
	setIntParam(env, j_nav, j_nav_obj, "ncmax", nav.ncmax);
	setIntParam(env, j_nav, j_nav_obj, "namax", nav.namax);
	setIntParam(env, j_nav, j_nav_obj, "ntmax", nav.ntmax);
	//赋值EphT
	jfieldID field_id = (*env).GetFieldID(j_nav, "eph", "[Lrtk/model/EphT;");
	jclass j_class = (*env).FindClass("rtk/model/EphT");
	jobjectArray jarray = (*env).NewObjectArray(nav.n, j_class, NULL);
	for (int i = 0; i < nav.n; i++)
	{
		(*env).SetObjectArrayElement(jarray, i, convertJavaEphT(env, nav.eph[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray);
	//赋值GephT
	field_id = (*env).GetFieldID(j_nav, "geph", "[Lrtk/model/GephT;");
	j_class = (*env).FindClass("rtk/model/GephT");
	jobjectArray jarray_GephT = (*env).NewObjectArray(nav.ng, j_class, NULL);
	for (int i = 0; i < nav.ng; i++)
	{
		(*env).SetObjectArrayElement(jarray_GephT, i, convertJavaGephT(env, nav.geph[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_GephT);
	//赋值SephT
	field_id = (*env).GetFieldID(j_nav, "seph", "[Lrtk/model/SephT;");
	j_class = (*env).FindClass("rtk/model/SephT");
	jobjectArray jarray_SephT = (*env).NewObjectArray(nav.ns, j_class, NULL);
	for (int i = 0; i < nav.ns; i++)
	{
		(*env).SetObjectArrayElement(jarray_GephT, i, convertJavaSephT(env, nav.seph[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_SephT);

	field_id = (*env).GetFieldID(j_nav, "peph", "[Lrtk/model/PephT;");
	j_class = (*env).FindClass("rtk/model/PephT");
	jobjectArray jarray_PephT = (*env).NewObjectArray(nav.ne, j_class, NULL);
	for (int i = 0; i < nav.ne; i++)
	{
		(*env).SetObjectArrayElement(jarray_PephT, i, convertJavaPephT(env, nav.peph[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_PephT);

	field_id = (*env).GetFieldID(j_nav, "pclk", "[Lrtk/model/PclkT;");
	j_class = (*env).FindClass("rtk/model/PclkT");
	jobjectArray jarray_PclkT = (*env).NewObjectArray(nav.nc, j_class, NULL);
	for (int i = 0; i < nav.nc; i++)
	{
		(*env).SetObjectArrayElement(jarray_PephT, i, convertJavaPclkT(env, nav.pclk[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_PclkT);

	field_id = (*env).GetFieldID(j_nav, "alm", "[Lrtk/model/AlmT;");
	j_class = (*env).FindClass("rtk/model/AlmT");
	jobjectArray jarray_AlmT = (*env).NewObjectArray(nav.na, j_class, NULL);
	for (int i = 0; i < nav.na; i++)
	{
		(*env).SetObjectArrayElement(jarray_AlmT, i, convertJavaAlmT(env, nav.alm[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_AlmT);

	field_id = (*env).GetFieldID(j_nav, "tec", "[Lrtk/model/TecT;");
	j_class = (*env).FindClass("rtk/model/TecT");
	jobjectArray jarray_TecT = (*env).NewObjectArray(nav.nt, j_class, NULL);
	for (int i = 0; i < nav.nt; i++)
	{
		(*env).SetObjectArrayElement(jarray_AlmT, i, convertJavaTecT(env, nav.tec[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_AlmT);

	//这里老是报错，不知道为什么，先注释
	//field_id = (*env).GetFieldID(j_nav, "erp", "Lrtk/model/ErpT;");
	//(*env).SetObjectField(j_nav_obj, field_id, convertJavaErpT(env, nav.erp));

	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_gps", 8, nav.utc_gps);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_glo", 8, nav.utc_glo);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_gal", 8, nav.utc_gal);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_qzs", 8, nav.utc_qzs);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_cmp", 8, nav.utc_cmp);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_irn", 9, nav.utc_irn);

	setDoubleArrayParam(env, j_nav, j_nav_obj, "utc_sbs", 4, nav.utc_sbs);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "ion_gps", 8, nav.ion_gps);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "ion_gal", 4, nav.ion_gal);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "ion_qzs", 8, nav.ion_qzs);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "ion_cmp", 8, nav.ion_cmp);
	setDoubleArrayParam(env, j_nav, j_nav_obj, "ion_irn", 8, nav.ion_irn);

	setIntArrayParam(env, j_nav, j_nav_obj, "glo_fcn", 32, nav.glo_fcn);
	setDoubleArrayParam21(env, j_nav, j_nav_obj, "cbias", nav.cbias);
	setDoubleArrayParam31(env, j_nav, j_nav_obj, "rbias",nav.rbias);
	
	field_id = (*env).GetFieldID(j_nav, "pcvs", "[Lrtk/model/PcvT;");
	j_class = (*env).FindClass("rtk/model/PcvT");
	jobjectArray jarray_PcvT = (*env).NewObjectArray(MAXSAT, j_class, NULL);
	for (int i = 0; i < MAXSAT; i++)
	{
		(*env).SetObjectArrayElement(jarray_PcvT, i, convertJavaPcvT(env, nav.pcvs[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_PcvT);

	field_id = (*env).GetFieldID(j_nav, "sbssat", "Lrtk/model/SbssatT;");
	j_class = (*env).FindClass("rtk/model/SbssatT");
	(*env).SetObjectField(j_nav_obj, field_id, convertJavaSbssatT(env, nav.sbssat));

	field_id = (*env).GetFieldID(j_nav, "sbsion", "[Lrtk/model/SbsionT;");
	j_class = (*env).FindClass("rtk/model/SbsionT");
	jobjectArray jarray_SbsionT = (*env).NewObjectArray(MAXBAND + 1, j_class, NULL);
	for (int i = 0; i < MAXBAND + 1; i++)
	{
		(*env).SetObjectArrayElement(jarray_SbsionT, i, convertJavaSbsionT(env, nav.sbsion[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_SbsionT);

	field_id = (*env).GetFieldID(j_nav, "dgps", "[Lrtk/model/DgpsT;");
	j_class = (*env).FindClass("rtk/model/DgpsT");
	jobjectArray jarray_DgpsT = (*env).NewObjectArray(MAXSAT, j_class, NULL);
	for (int i = 0; i < MAXSAT; i++)
	{
		(*env).SetObjectArrayElement(jarray_DgpsT, i, convertJavaDgpsT(env, nav.dgps[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_DgpsT);

	field_id = (*env).GetFieldID(j_nav, "ssr", "[Lrtk/model/SsrT;");
	j_class = (*env).FindClass("rtk/model/SsrT");
	jobjectArray jarray_SsrT = (*env).NewObjectArray(MAXSAT, j_class, NULL);
	for (int i = 0; i < MAXSAT; i++)
	{
		(*env).SetObjectArrayElement(jarray_SsrT, i, convertJavaSsrT(env, nav.ssr[i]));
	}
	(*env).SetObjectField(j_nav_obj, field_id, jarray_SsrT);



	env->DeleteLocalRef(j_nav);
	env->DeleteLocalRef(j_class);

	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jarray_GephT);
	env->DeleteLocalRef(jarray_SephT);
	env->DeleteLocalRef(jarray_PephT);
	env->DeleteLocalRef(jarray_PclkT);
	env->DeleteLocalRef(jarray_AlmT);
	env->DeleteLocalRef(jarray_TecT);

	env->DeleteLocalRef(jarray_PcvT);
	env->DeleteLocalRef(jarray_SbsionT);
	env->DeleteLocalRef(jarray_DgpsT);
	env->DeleteLocalRef(jarray_SsrT);

	return ;

}


jobject convertJavaObsdT(JNIEnv *env, obsd_t obsd)
{
	//new ObsdT
	jclass j_obsd = (*env).FindClass("rtk/model/ObsdT");
	jmethodID j_obsd_methodID = (*env).GetMethodID(j_obsd, "<init>", "()V");
	jobject j_obsd_obj = (*env).NewObjectA(j_obsd, j_obsd_methodID, 0);

	//赋值GtimeT
	setGtime(env, j_obsd, j_obsd_obj, "time", obsd.time);
	//赋值sat
	setIntParam(env, j_obsd, j_obsd_obj, "sat", obsd.sat);
	//赋值rcv
	setIntParam(env, j_obsd, j_obsd_obj, "rcv", obsd.rcv);
	//赋值SNR
	setInt16ArrayParam(env, j_obsd, j_obsd_obj, "SNR", NFREQ + NEXOBS, obsd.SNR);
	//赋值LLI
	setInt8ArrayParam(env, j_obsd, j_obsd_obj, "LLI", NFREQ + NEXOBS, obsd.LLI);
	//赋值code
	setInt8ArrayParam(env, j_obsd, j_obsd_obj, "code", NFREQ + NEXOBS, obsd.code);
	//赋值L
	setDoubleArrayParam(env, j_obsd, j_obsd_obj, "L", NFREQ + NEXOBS, obsd.L);
	//赋值P
	setDoubleArrayParam(env, j_obsd, j_obsd_obj, "P", NFREQ + NEXOBS, obsd.P);
	//赋值D
	setFloatArrayParam(env, j_obsd, j_obsd_obj, "D", NFREQ + NEXOBS, obsd.D);
	env->DeleteLocalRef(j_obsd);
	return j_obsd_obj;
}

/**
*
*
* @param env
* @param obs 解算出来的obs结果赋值给java
* @param obsJ java程序中的传参
* @return
*/
void convertJavaObsT(JNIEnv *env, obs_t obs, jobject j_obs_obj)
{
	jclass j_obst = (*env).FindClass("rtk/model/ObsT");
	jfieldID n_field_id = (*env).GetFieldID(j_obst, "n", "I");
	jfieldID nmax_field_id = (*env).GetFieldID(j_obst, "nmax", "I");

	(*env).SetIntField(j_obs_obj, n_field_id, obs.n);
	(*env).SetIntField(j_obs_obj, nmax_field_id, obs.nmax);

	jfieldID data_field_id = (*env).GetFieldID(j_obst, "data", "[Lrtk/model/ObsdT;");
	jclass j_obsd = (*env).FindClass("rtk/model/ObsdT");
	jobjectArray j_obsd_array = (*env).NewObjectArray(obs.n, j_obsd, NULL);
	for (int i = 0; i < obs.n; i++){
		jobject j_obsd_obj = convertJavaObsdT(env, obs.data[i]);
		(*env).SetObjectArrayElement(j_obsd_array, i, j_obsd_obj);
	}
	(*env).SetObjectField(j_obs_obj, data_field_id, j_obsd_array);
	env->DeleteLocalRef(j_obsd_array);
	env->DeleteLocalRef(j_obst);
	env->DeleteLocalRef(j_obsd);
}

void convertJavaStaT(JNIEnv *env, sta_t sta, jobject sta_obj)
{
	jclass j_sta = (*env).FindClass("rtk/model/StaT");
	setCharArrayParam(env, j_sta, sta_obj, "name", MAXANT, sta.name);
	setCharArrayParam(env, j_sta, sta_obj, "marker", MAXANT, sta.marker);
	setCharArrayParam(env, j_sta, sta_obj, "antdes", MAXANT, sta.antdes);
	setCharArrayParam(env, j_sta, sta_obj, "antsno", MAXANT, sta.antsno);
	setCharArrayParam(env, j_sta, sta_obj, "rectype", MAXANT, sta.rectype);
	setCharArrayParam(env, j_sta, sta_obj, "recver", MAXANT, sta.recver);
	setCharArrayParam(env, j_sta, sta_obj, "recsno", MAXANT, sta.recsno);
	setIntParam(env, j_sta, sta_obj, "antsetup", sta.antsetup);
	setIntParam(env, j_sta, sta_obj, "itrf", sta.itrf);
	setIntParam(env, j_sta, sta_obj, "deltype", sta.deltype);
	setDoubleArrayParam(env, j_sta, sta_obj, "pos", 3, sta.pos);
	setDoubleArrayParam(env, j_sta, sta_obj, "del", 3, sta.del);
	setDoubleParam(env, j_sta, sta_obj, "hgt", sta.hgt);
	setIntParam(env, j_sta, sta_obj, "glo_cp_align", sta.glo_cp_align);
	setDoubleArrayParam(env, j_sta, sta_obj, "glo_cp_bias", 4, sta.glo_cp_bias);
	env->DeleteLocalRef(j_sta);
}

void convertJavaSolT(JNIEnv *env, jobject sol_obj, sol_t sol)
{
	jclass j_sol = (*env).FindClass("rtk/model/SolT");
	setGtime(env, j_sol, sol_obj, "time", sol.time);
	setDoubleArrayParam(env, j_sol, sol_obj, "rr", 6, sol.rr);
	setFloatArrayParam(env, j_sol, sol_obj, "qr", 6, sol.qr);
	setFloatArrayParam(env, j_sol, sol_obj, "qv", 6, sol.qv);
	setDoubleArrayParam(env, j_sol, sol_obj, "dtr", 6, sol.dtr);

	setIntParam(env, j_sol, sol_obj, "type", sol.type);
	setIntParam(env, j_sol, sol_obj, "stat", sol.stat);
	setIntParam(env, j_sol, sol_obj, "ns", sol.ns);

	setFloatParam(env, j_sol, sol_obj, "age", sol.age);
	setFloatParam(env, j_sol, sol_obj, "ratio", sol.ratio);
	setFloatParam(env, j_sol, sol_obj, "thres", sol.thres);
	env->DeleteLocalRef(j_sol);

}

void convertJavaAmbcT(JNIEnv *env, jobject ambc_obj, ambc_t ambc)
{
	jclass j_ambc = (*env).FindClass("rtk/model/AmbcT");
	setGtimeArrayParam(env, j_ambc, ambc_obj, "epoch", 4, ambc.epoch);
	setIntArrayParam(env, j_ambc, ambc_obj, "n", 4, ambc.n);
	setDoubleArrayParam(env, j_ambc, ambc_obj, "LC", 4, ambc.LC);
	setDoubleArrayParam(env, j_ambc, ambc_obj, "LCv", 4, ambc.LCv);
	setIntParam(env, j_ambc, ambc_obj, "fixcnt", ambc.fixcnt);
	setCharArrayParam(env, j_ambc, ambc_obj, "flags", MAXSAT, ambc.flags);
	env->DeleteLocalRef(j_ambc);

	return ;
}

void convertJavaSsatT(JNIEnv *env, jobject ssat_obj, ssat_t ssat)
{
	jclass j_ssat = (*env).FindClass("rtk/model/SsatT");
	setIntParam(env, j_ssat, ssat_obj, "sys", ssat.sys);
	setIntParam(env, j_ssat, ssat_obj, "vs", ssat.vs);
	setDoubleArrayParam(env, j_ssat, ssat_obj, "azel", 2, ssat.azel);
	setDoubleArrayParam(env, j_ssat, ssat_obj, "resp", NFREQ, ssat.resp);
	setDoubleArrayParam(env, j_ssat, ssat_obj, "resc", NFREQ, ssat.resc);
	setInt8ArrayParam(env, j_ssat, ssat_obj, "vsat", NFREQ, ssat.vsat);
	setInt16ArrayParam(env, j_ssat, ssat_obj, "snr", NFREQ, ssat.snr);
	setInt8ArrayParam(env, j_ssat, ssat_obj, "fix", NFREQ, ssat.fix);
	setInt8ArrayParam(env, j_ssat, ssat_obj, "slip", NFREQ, ssat.slip);
	setInt8ArrayParam(env, j_ssat, ssat_obj, "half", NFREQ, ssat.half);
	setIntArrayParam(env, j_ssat, ssat_obj, "lock", NFREQ, ssat.lock);

	setInt32ArrayParam(env, j_ssat, ssat_obj, "outc", NFREQ, ssat.outc);
	setInt32ArrayParam(env, j_ssat, ssat_obj, "slipc", NFREQ, ssat.slipc);
	setInt32ArrayParam(env, j_ssat, ssat_obj, "rejc", NFREQ, ssat.rejc);

	setDoubleArrayParam(env, j_ssat, ssat_obj, "gf", NFREQ - 1, ssat.gf);
	setDoubleArrayParam(env, j_ssat, ssat_obj, "mw", NFREQ - 1, ssat.mw);
	setDoubleParam(env, j_ssat, ssat_obj, "phw", ssat.phw);
	setGtimeArrayParam21(env, j_ssat, ssat_obj, "pt", ssat.pt);
	setDoubleArrayParam29(env, j_ssat, ssat_obj, "ph", ssat.ph);
	env->DeleteLocalRef(j_ssat);
	return ;
}

void convertJavaRtcmT(JNIEnv *env, jobject rtcm_obj, rtcm_t *rtcm)
{
	jclass j_class = (*env).FindClass("rtk/model/RtcmT");
	setIntParam(env, j_class, rtcm_obj, "staid", rtcm->staid);
	setIntParam(env, j_class, rtcm_obj, "stah", rtcm->stah);
	setIntParam(env, j_class, rtcm_obj, "seqno", rtcm->seqno);
	setIntParam(env, j_class, rtcm_obj, "outtype", rtcm->outtype);
	setGtime(env, j_class, rtcm_obj, "time", rtcm->time);
	setGtime(env, j_class, rtcm_obj, "time_s", rtcm->time_s);
	jfieldID data_field_id = (*env).GetFieldID(j_class, "obs", "Lrtk/model/ObsT;");
	jclass j_class2 = (*env).FindClass("rtk/model/ObsT");
	jmethodID jmethodID = (*env).GetMethodID(j_class2, "<init>", "()V");
	jobject obs_obj = (*env).NewObjectA(j_class2, jmethodID, 0);
	convertJavaObsT(env, rtcm->obs, obs_obj);
	(*env).SetObjectField(rtcm_obj, data_field_id, obs_obj);

	data_field_id = (*env).GetFieldID(j_class, "nav", "Lrtk/model/NavT;");
	j_class2 = (*env).FindClass("rtk/model/NavT");
	jmethodID = (*env).GetMethodID(j_class2, "<init>", "()V");
	jobject nav_obj = (*env).NewObjectA(j_class2, jmethodID, 0);
	convertJavaNavT(env, rtcm->nav, nav_obj);
	(*env).SetObjectField(rtcm_obj, data_field_id, nav_obj);

	data_field_id = (*env).GetFieldID(j_class, "sta", "Lrtk/model/StaT;");
	j_class2 = (*env).FindClass("rtk/model/StaT");
	jmethodID = (*env).GetMethodID(j_class2, "<init>", "()V");
	jobject sta_obj = (*env).NewObjectA(j_class2, jmethodID, 0);
	convertJavaStaT(env, rtcm->sta, sta_obj);
	(*env).SetObjectField(rtcm_obj, data_field_id, sta_obj);

	data_field_id = (*env).GetFieldID(j_class, "ssr", "[Lrtk/model/SsrT;");
	j_class2 = (*env).FindClass("rtk/model/SsrT");
	jobjectArray jarray_SsrT = (*env).NewObjectArray(MAXSAT, j_class2, NULL);
	for (int i = 0; i < MAXSAT; i++)
	{
		(*env).SetObjectArrayElement(jarray_SsrT, i, convertJavaSsrT(env, rtcm->ssr[i]));
	}
	(*env).SetObjectField(rtcm_obj, data_field_id, jarray_SsrT);

	
	setCharArrayParam(env, j_class, rtcm_obj, "msg", 128, rtcm->msg);
	setCharArrayParam(env, j_class, rtcm_obj, "msgtype", 256, rtcm->msgtype);
	setCharArrayParam23(env, j_class, rtcm_obj, "msmtype", rtcm->msmtype);

	setIntParam(env, j_class, rtcm_obj, "obsflag", rtcm->obsflag);
	setIntParam(env, j_class, rtcm_obj, "ephsat", rtcm->ephsat);
	setIntParam(env, j_class, rtcm_obj, "ephset", rtcm->ephset);
	setDoubleArrayParam210(env, j_class, rtcm_obj, "cp", rtcm->cp);
	setInt16ArrayParam21(env, j_class, rtcm_obj, "lock", rtcm->lock);
	setInt16ArrayParam21(env, j_class, rtcm_obj, "loss", rtcm->loss);
	setGtimeArrayParam22(env, j_class, rtcm_obj, "lltime", rtcm->lltime);

	setIntParam(env, j_class, rtcm_obj, "nbyte", rtcm->nbyte);
	setIntParam(env, j_class, rtcm_obj, "nbit", rtcm->nbit);
	setIntParam(env, j_class, rtcm_obj, "len", rtcm->len);
	setByteArrayParam(env, j_class, rtcm_obj, "buff", 1200, rtcm->buff);
	setIntParam(env, j_class, rtcm_obj, "word", rtcm->word);
	setInt32ArrayParam(env, j_class, rtcm_obj, "nmsg2", 100, rtcm->nmsg2);
	setInt32ArrayParam(env, j_class, rtcm_obj, "nmsg3", 400, rtcm->nmsg3);
	setCharArrayParam(env, j_class, rtcm_obj, "opt", 256, rtcm->opt);

	env->DeleteLocalRef(j_class);
	env->DeleteLocalRef(j_class2);
	env->DeleteLocalRef(jarray_SsrT);
}

