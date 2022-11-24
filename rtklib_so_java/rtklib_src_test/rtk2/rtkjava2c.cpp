#include "jni/jni.h"
#include "rtkjni.h"
#include "../src/rtklib.h"

obsd_t convertCObsd(JNIEnv *env, jobject j_obsd_obj)
{
	obsd_t obsd = { 0 };
	jclass j_obsd = (*env).FindClass("rtk/model/ObsdT");
	jfieldID time_field_id = (*env).GetFieldID(j_obsd, "time", "Lrtk/model/GtimeT;");

	jclass j_gtime = (*env).FindClass("rtk/model/GtimeT");
	jobject time_obj = (*env).GetObjectField(j_obsd_obj, time_field_id);
	gtime_t gtime = { 0 };
	gtime.time = getLongParam(env, j_gtime, time_obj, "time");
	gtime.sec = getDoubleParam(env, j_gtime, time_obj, "sec");
	obsd.time = gtime;
	obsd.sat = getIntParam(env, j_obsd, j_obsd_obj, "sat");
	obsd.rcv = getIntParam(env, j_obsd, j_obsd_obj, "rcv");
	getInt16ArrayParam(env, j_obsd, j_obsd_obj, "SNR", NFREQ + NEXOBS, obsd.SNR);
	getInt8ArrayParam(env, j_obsd, j_obsd_obj, "LLI", NFREQ + NEXOBS, obsd.LLI);
	getInt8ArrayParam(env, j_obsd, j_obsd_obj, "code", NFREQ + NEXOBS, obsd.code);
	getDoubleArrayParam(env, j_obsd, j_obsd_obj, "L", NFREQ + NEXOBS, obsd.L);
	getDoubleArrayParam(env, j_obsd, j_obsd_obj, "P", NFREQ + NEXOBS, obsd.P);
	getFloatArrayParam(env, j_obsd, j_obsd_obj, "D", NFREQ + NEXOBS, obsd.D);

	env->DeleteLocalRef(j_obsd);
	env->DeleteLocalRef(j_gtime);
	env->DeleteLocalRef(j_gtime);
	return obsd;
}


//传参过来的java obs赋值给obs
void convertCObsT(JNIEnv *env, obs_t *obs, jobject j_obs_obj)
{
	jclass j_obst = (*env).FindClass("rtk/model/ObsT");
	jfieldID n_field_id = (*env).GetFieldID(j_obst, "n", "I");
	jfieldID nmax_field_id = (*env).GetFieldID(j_obst, "nmax", "I");
	jfieldID data_field_id = (*env).GetFieldID(j_obst, "data", "[Lrtk/model/ObsdT;");

	jint jn = (*env).GetIntField(j_obs_obj, n_field_id);
	obs->n = jn;
	jint jnmax = (*env).GetIntField(j_obs_obj, nmax_field_id);
	obs->nmax = jnmax;
	jobjectArray jdata = (jobjectArray)(*env).GetObjectField(j_obs_obj, data_field_id);
	jobject jobsd = NULL;
	for (int i = 0; i < jn; i++)
	{
		jobsd = env->GetObjectArrayElement(jdata, i);
		if (jobsd != NULL)
		{
			obsd_t obsd = convertCObsd(env, jobsd);
			obs->data[i] = obsd;
		}
		
	}
	env->DeleteLocalRef(jobsd);
	env->DeleteLocalRef(jdata);
	env->DeleteLocalRef(j_obst);
}

eph_t convertCEphT(JNIEnv *env, jobject epht_obj)
{
	eph_t epht = { 0 };
	jclass j_eph = (*env).FindClass("rtk/model/EphT");
	epht.sat = getIntParam(env, j_eph, epht_obj, "sat");
	epht.iode = getIntParam(env, j_eph, epht_obj, "iode");
	epht.iodc = getIntParam(env, j_eph, epht_obj, "iodc");
	epht.sva = getIntParam(env, j_eph, epht_obj, "sva");
	epht.svh = getIntParam(env, j_eph, epht_obj, "svh");
	epht.week = getIntParam(env, j_eph, epht_obj, "week");
	epht.code = getIntParam(env, j_eph, epht_obj, "code");
	epht.flag = getIntParam(env, j_eph, epht_obj, "flag");
	epht.toe = getGtime(env, j_eph, epht_obj, "toe");
	epht.toc = getGtime(env, j_eph, epht_obj, "toc");
	epht.ttr = getGtime(env, j_eph, epht_obj, "ttr");
	epht.A = getDoubleParam(env, j_eph, epht_obj, "A");
	epht.e = getDoubleParam(env, j_eph, epht_obj, "e");
	epht.i0 = getDoubleParam(env, j_eph, epht_obj, "i0");
	epht.OMG0 = getDoubleParam(env, j_eph, epht_obj, "OMG0");
	epht.omg = getDoubleParam(env, j_eph, epht_obj, "omg");
	epht.M0 = getDoubleParam(env, j_eph, epht_obj, "M0");
	epht.deln = getDoubleParam(env, j_eph, epht_obj, "deln");
	epht.OMGd = getDoubleParam(env, j_eph, epht_obj, "OMGd");
	epht.idot = getDoubleParam(env, j_eph, epht_obj, "idot");

	epht.crc = getDoubleParam(env, j_eph, epht_obj, "crc");
	epht.crs = getDoubleParam(env, j_eph, epht_obj, "crs");
	epht.cuc = getDoubleParam(env, j_eph, epht_obj, "cuc");
	epht.cus = getDoubleParam(env, j_eph, epht_obj, "cus");
	epht.cic = getDoubleParam(env, j_eph, epht_obj, "cic");
	epht.cis = getDoubleParam(env, j_eph, epht_obj, "cis");

	epht.toes = getDoubleParam(env, j_eph, epht_obj, "toes");
	epht.fit = getDoubleParam(env, j_eph, epht_obj, "fit");
	epht.f0 = getDoubleParam(env, j_eph, epht_obj, "f0");
	epht.f1 = getDoubleParam(env, j_eph, epht_obj, "f1");
	epht.f2 = getDoubleParam(env, j_eph, epht_obj, "f2");

	getDoubleArrayParam(env, j_eph, epht_obj, "tgd", 6, epht.tgd);
	epht.Adot = getDoubleParam(env, j_eph, epht_obj, "Adot");
	epht.ndot = getDoubleParam(env, j_eph, epht_obj, "ndot");
	env->DeleteLocalRef(j_eph);
	return epht;
}

geph_t convertCGephT(JNIEnv *env, jobject gepht_obj)
{
	jclass j_geph = (*env).FindClass("rtk/model/GephT");
	geph_t gepht = { 0 };
	gepht.sat = getIntParam(env, j_geph, gepht_obj, "sat");
	gepht.iode = getIntParam(env, j_geph, gepht_obj, "iode");
	gepht.frq = getIntParam(env, j_geph, gepht_obj, "frq");

	gepht.svh = getIntParam(env, j_geph, gepht_obj, "svh");
	gepht.sva = getIntParam(env, j_geph, gepht_obj, "sva");
	gepht.age = getIntParam(env, j_geph, gepht_obj, "age");

	gepht.toe = getGtime(env, j_geph, gepht_obj, "toe");
	gepht.tof = getGtime(env, j_geph, gepht_obj, "tof");
	getDoubleArrayParam(env, j_geph, gepht_obj, "pos", 3, gepht.pos);
	getDoubleArrayParam(env, j_geph, gepht_obj, "vel", 3, gepht.vel);
	getDoubleArrayParam(env, j_geph, gepht_obj, "acc", 3, gepht.acc);

	gepht.taun = getDoubleParam(env, j_geph, gepht_obj, "taun");
	gepht.gamn = getDoubleParam(env, j_geph, gepht_obj, "gamn");
	gepht.dtaun = getDoubleParam(env, j_geph, gepht_obj, "dtaun");
	env->DeleteLocalRef(j_geph);
	return gepht;
}


seph_t convertCSephT(JNIEnv *env, jobject sepht_obj)
{
	jclass j_seph = (*env).FindClass("rtk/model/SephT");
	seph_t sepht = { 0 };
	sepht.sat = getIntParam(env, j_seph, sepht_obj, "sat");

	sepht.t0 = getGtime(env, j_seph, sepht_obj, "t0");
	sepht.tof = getGtime(env, j_seph, sepht_obj, "tof");
	sepht.sva = getIntParam(env, j_seph, sepht_obj, "sva");
	sepht.svh = getIntParam(env, j_seph, sepht_obj, "svh");

	getDoubleArrayParam(env, j_seph, sepht_obj, "pos", 3, sepht.pos);
	getDoubleArrayParam(env, j_seph, sepht_obj, "vel", 3, sepht.vel);
	getDoubleArrayParam(env, j_seph, sepht_obj, "acc", 3, sepht.acc);

	sepht.af0 = getDoubleParam(env, j_seph, sepht_obj, "af0");
	sepht.af1 = getDoubleParam(env, j_seph, sepht_obj, "af1");
	env->DeleteLocalRef(j_seph);
	return sepht;
}

peph_t convertCPephT(JNIEnv *env, jobject pepht_obj)
{
	jclass j_peph = (*env).FindClass("rtk/model/PephT");
	peph_t pepht = { 0 };

	pepht.time = getGtime(env, j_peph, pepht_obj, "time");
	pepht.index = getIntParam(env, j_peph, pepht_obj, "index");
	getDoubleArrayParam22(env, j_peph, pepht_obj, "pos", pepht.pos);
	getFloatArrayParam21(env, j_peph, pepht_obj, "std",pepht.std);

	getDoubleArrayParam22(env, j_peph, pepht_obj, "vel",pepht.vel);

	getFloatArrayParam21(env, j_peph, pepht_obj, "vst", pepht.vst);
	getFloatArrayParam22(env, j_peph, pepht_obj, "cov", pepht.cov);
	getFloatArrayParam22(env, j_peph, pepht_obj, "vco", pepht.vco);
	env->DeleteLocalRef(j_peph);
	return pepht;

}

pclk_t convertCPclkT(JNIEnv *env, jobject pclk_obj)
{
	jclass j_pclk = (*env).FindClass("rtk/model/PclkT");
	pclk_t pclkt = { 0 };

	pclkt.time = getGtime(env, j_pclk, pclk_obj, "time");
	pclkt.index = getIntParam(env, j_pclk, pclk_obj, "index");
	getDoubleArrayParam23(env, j_pclk, pclk_obj, "clk", pclkt.clk);
	getFloatArrayParam23(env, j_pclk, pclk_obj, "std",pclkt.std);
	env->DeleteLocalRef(j_pclk);
	return pclkt;
}

alm_t convertCAlmT(JNIEnv *env, jobject alm_obj)
{
	jclass j_alm = (*env).FindClass("rtk/model/AlmT");
	alm_t almt = { 0 };
	almt.sat = getIntParam(env, j_alm, alm_obj, "sat");
	almt.svh = getIntParam(env, j_alm, alm_obj, "svh");
	almt.svconf = getIntParam(env, j_alm, alm_obj, "svconf");
	almt.week = getIntParam(env, j_alm, alm_obj, "week");
	almt.toa = getGtime(env, j_alm, alm_obj, "toa");

	almt.A = getDoubleParam(env, j_alm, alm_obj, "A");
	almt.e = getDoubleParam(env, j_alm, alm_obj, "e");
	almt.i0 = getDoubleParam(env, j_alm, alm_obj, "i0");

	almt.OMG0 = getDoubleParam(env, j_alm, alm_obj, "OMG0");
	almt.omg = getDoubleParam(env, j_alm, alm_obj, "omg");
	almt.M0 = getDoubleParam(env, j_alm, alm_obj, "M0");
	almt.OMGd = getDoubleParam(env, j_alm, alm_obj, "OMGd");
	almt.toas = getDoubleParam(env, j_alm, alm_obj, "toas");
	almt.f0 = getDoubleParam(env, j_alm, alm_obj, "f0");
	almt.f1 = getDoubleParam(env, j_alm, alm_obj, "f1");
	env->DeleteLocalRef(j_alm);
	return almt;
}

tec_t convertCTecT(JNIEnv *env, jobject tec_obj)
{
	jclass j_tec = (*env).FindClass("rtk/model/TecT");
	tec_t tect = { 0 };
	int n = tect.ndata[0] * tect.ndata[1] * tect.ndata[2];
	tect.time = getGtime(env, j_tec, tec_obj, "time");
	getIntArrayParam(env, j_tec, tec_obj, "ndata", 3, tect.ndata);
	tect.rb = getDoubleParam(env, j_tec, tec_obj, "rb");

	getDoubleArrayParam(env, j_tec, tec_obj, "lats", 3, tect.lats);
	getDoubleArrayParam(env, j_tec, tec_obj, "lons", 3, tect.lons);
	getDoubleArrayParam(env, j_tec, tec_obj, "hgts", 3, tect.hgts);

	getDoubleArrayParam(env, j_tec, tec_obj, "data", n, tect.data);
	getFloatArrayParam(env, j_tec, tec_obj, "rms", n, tect.rms);

	env->DeleteLocalRef(j_tec);
	return tect;
}

erpd_t convertCErpdT(JNIEnv *env, jobject erpd_obj)
{
	jclass j_erpd = (*env).FindClass("rtk/model/ErpdT");
	erpd_t erpd = { 0 };
	erpd.mjd = getDoubleParam(env, j_erpd, erpd_obj, "mjd");
	erpd.xp = getDoubleParam(env, j_erpd, erpd_obj, "xp");
	erpd.yp = getDoubleParam(env, j_erpd, erpd_obj, "yp");
	erpd.xpr = getDoubleParam(env, j_erpd, erpd_obj, "xpr");

	erpd.ypr = getDoubleParam(env, j_erpd, erpd_obj, "ypr");
	erpd.ut1_utc = getDoubleParam(env, j_erpd, erpd_obj, "ut1_utc");
	erpd.lod = getDoubleParam(env, j_erpd, erpd_obj, "lod");

	env->DeleteLocalRef(j_erpd);
	return erpd;
}


erp_t convertCErpT(JNIEnv *env, jobject erp_obj)
{
	jclass j_erp = (*env).FindClass("rtk/model/ErpT");
	erp_t erp = { 0 };
	erp.n = getIntParam(env, j_erp, erp_obj, "n");
	erp.nmax = getIntParam(env, j_erp, erp_obj, "nmax");

	jfieldID data_field_id = (*env).GetFieldID(j_erp, "data", "[Lrtk/model/ErpT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(erp_obj, data_field_id);
	for (int i = 0; i < erp.n; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			erpd_t ephd = convertCErpdT(env, jdata);
			erp.data[i] = ephd;
		}
		
	}
	env->DeleteLocalRef(j_erp);
	env->DeleteLocalRef(jdataArray);
	return erp;
}


pcv_t convertCPcvT(JNIEnv *env, jobject pcv_obj)
{
	jclass j_pcv = (*env).FindClass("rtk/model/PcvT");
	pcv_t pcv = { 0 };
	pcv.sat = getIntParam(env, j_pcv, pcv_obj, "sat");
	getCharArrayParam(env, j_pcv, pcv_obj, "type", MAXANT, pcv.type);
	getCharArrayParam(env, j_pcv, pcv_obj, "code", MAXANT, pcv.code);
	pcv.ts = getGtime(env, j_pcv, pcv_obj, "ts");
	pcv.te = getGtime(env, j_pcv, pcv_obj, "te");
	getDoubleArrayParam24(env, j_pcv, pcv_obj, "off", pcv.off);
	getDoubleArrayParam25(env, j_pcv, pcv_obj, "var", pcv.var);
	env->DeleteLocalRef(j_pcv);
	return pcv;
}
sbsfcorr_t convertCSbsfcorrT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsfcorrT");
	sbsfcorr_t sbsfcorr = { 0 };
	sbsfcorr.t0 = getGtime(env, j_c, obj, "t0");
	sbsfcorr.prc = getDoubleParam(env, j_c, obj, "prc");
	sbsfcorr.rrc = getDoubleParam(env, j_c, obj, "rrc");
	sbsfcorr.dt = getDoubleParam(env, j_c, obj, "dt");
	sbsfcorr.iodf = getIntParam(env, j_c, obj, "iodf");
	sbsfcorr.udre = getIntParam(env, j_c, obj, "udre");
	sbsfcorr.ai = getIntParam(env, j_c, obj, "ai");
	env->DeleteLocalRef(j_c);
	return sbsfcorr;
}

sbslcorr_t convertCSbslcorrT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbslcorrT");
	sbslcorr_t sbslcorr = { 0 };
	sbslcorr.t0 = getGtime(env, j_c, obj, "t0");
	sbslcorr.iode = getIntParam(env, j_c, obj, "iode");
	getDoubleArrayParam(env, j_c, obj, "dpos", 3, sbslcorr.dpos);
	getDoubleArrayParam(env, j_c, obj, "dvel", 3, sbslcorr.dvel);

	sbslcorr.daf0 = getDoubleParam(env, j_c, obj, "daf0");
	sbslcorr.daf1 = getDoubleParam(env, j_c, obj, "daf1");
	env->DeleteLocalRef(j_c);
	return sbslcorr;
}

sbssatp_t convertCSbssatpT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbssatpT");
	sbssatp_t sbssap = { 0 };
	sbssap.sat = getIntParam(env, j_c, obj, "sat");
	jfieldID data_field_id = (*env).GetFieldID(j_c, "fcorr", "Lrtk/model/SbsfcorrT;");
	jobject jdata = (*env).GetObjectField(obj, data_field_id);
	sbsfcorr_t fcorr = convertCSbsfcorrT(env, jdata);
	sbssap.fcorr = fcorr;

	data_field_id = (*env).GetFieldID(j_c, "lcorr", "Lrtk/model/SbslcorrT;");
	jdata = (*env).GetObjectField(obj, data_field_id);
	sbslcorr_t lcorr = convertCSbslcorrT(env, jdata);
	sbssap.lcorr = lcorr;

	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(jdata);
	return sbssap;

}

sbssat_t convertCSbssatT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbssatT");
	sbssat_t sbssat = { 0 };
	sbssat.iodp = getIntParam(env, j_c, obj, "iodp");
	sbssat.nsat = getIntParam(env, j_c, obj, "nsat");
	sbssat.tlat = getIntParam(env, j_c, obj, "tlat");

	jfieldID data_field_id = (*env).GetFieldID(j_c, "sat", "[Lrtk/model/SbssatpT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(obj, data_field_id);
	for (int i = 0; i < MAXSAT; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			sbssatp_t sbssatp = convertCSbssatpT(env, jdata);
			sbssat.sat[i] = sbssatp;
		}	
	}
	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(jdataArray);
	return sbssat;
}


sbsigp_t convertCSbsigpT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsigpT");
	sbsigp_t sbsigp = { 0 };
	sbsigp.t0 = getGtime(env, j_c, obj, "t0");
	sbsigp.lat = getIntParam(env, j_c, obj, "lat");
	sbsigp.lon = getIntParam(env, j_c, obj, "lon");
	sbsigp.give = getIntParam(env, j_c, obj, "give");
	sbsigp.delay = getFloatParam(env, j_c, obj, "delay");
	env->DeleteLocalRef(j_c);
	return sbsigp;
}

sbsion_t convertCSbsionT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SbsionT");
	sbsion_t sbsion = { 0 };
	sbsion.iodi = getIntParam(env, j_c, obj, "iodi");
	sbsion.nigp = getIntParam(env, j_c, obj, "nigp");
	jfieldID data_field_id = (*env).GetFieldID(j_c, "igp", "[Lrtk/model/SbsigpT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(obj, data_field_id);
	for (int i = 0; i < MAXNIGP; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			sbsigp_t sbsigp = convertCSbsigpT(env, jdata);
			sbsion.igp[i] = sbsigp;
		}
		
	}
	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(jdataArray);
	return sbsion;
}

dgps_t convertCDgpsT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/DgpsT");
	dgps_t dgps = { 0 };
	dgps.t0 = getGtime(env, j_c, obj, "t0");
	dgps.prc = getDoubleParam(env, j_c, obj, "prc");
	dgps.rrc = getDoubleParam(env, j_c, obj, "rrc");
	dgps.iod = getIntParam(env, j_c, obj, "iod");
	dgps.udre = getDoubleParam(env, j_c, obj, "udre");
	env->DeleteLocalRef(j_c);
	return dgps;
}

ssr_t convertCSsrT(JNIEnv *env, jobject obj)
{
	jclass j_c = (*env).FindClass("rtk/model/SsrT");
	ssr_t ssr = { 0 };
	jfieldID data_field_id = (*env).GetFieldID(j_c, "t0", "[Lrtk/model/GtimeT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(obj, data_field_id);
	for (int i = 0; i < 6; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		ssr.t0[i] = convertCGtimeT(env, jdata);
	}
	getDoubleArrayParam(env, j_c, obj, "udi", 6, ssr.udi);
	getIntArrayParam(env, j_c, obj, "iod", 6, ssr.iod);
	ssr.iode = getIntParam(env, j_c, obj, "iode");
	ssr.iodcrc = getIntParam(env, j_c, obj, "iodcrc");
	ssr.ura = getIntParam(env, j_c, obj, "ura");
	ssr.refd = getIntParam(env, j_c, obj, "refd");

	getDoubleArrayParam(env, j_c, obj, "deph", 3, ssr.deph);
	getDoubleArrayParam(env, j_c, obj, "ddeph", 3, ssr.ddeph);
	getDoubleArrayParam(env, j_c, obj, "dclk", 3, ssr.dclk);
	ssr.hrclk = getDoubleParam(env, j_c, obj, "hrclk");

	getFloatArrayParam(env, j_c, obj, "cbias", MAXCODE, ssr.cbias);
	getDoubleArrayParam(env, j_c, obj, "pbias", MAXCODE, ssr.pbias);
	getFloatArrayParam(env, j_c, obj, "stdpb", MAXCODE, ssr.stdpb);

	ssr.yaw_ang = getDoubleParam(env, j_c, obj, "yaw_ang");
	ssr.yaw_rate = getDoubleParam(env, j_c, obj, "yaw_rate");

	ssr.update = getIntParam(env, j_c, obj, "update");

	env->DeleteLocalRef(j_c);
	env->DeleteLocalRef(jdataArray);
	return ssr;
}

//给nav_t结构体赋值
void convertCNavT(JNIEnv *env, jobject navt_obj, nav_t *navt)
{
	jclass j_nav = (*env).FindClass("rtk/model/NavT");
	navt->n = getIntParam(env, j_nav, navt_obj, "n");
	navt->nmax = getIntParam(env, j_nav, navt_obj, "nmax");
	navt->ng = getIntParam(env, j_nav, navt_obj, "ng");
	navt->ngmax = getIntParam(env, j_nav, navt_obj, "ngmax");
	navt->ns = getIntParam(env, j_nav, navt_obj, "ns");
	navt->nsmax = getIntParam(env, j_nav, navt_obj, "nsmax");
	navt->ne = getIntParam(env, j_nav, navt_obj, "ne");
	navt->nemax = getIntParam(env, j_nav, navt_obj, "nemax");
	navt->nc = getIntParam(env, j_nav, navt_obj, "nc");
	navt->ncmax = getIntParam(env, j_nav, navt_obj, "ncmax");
	navt->na = getIntParam(env, j_nav, navt_obj, "na");
	navt->namax = getIntParam(env, j_nav, navt_obj, "namax");
	navt->nt = getIntParam(env, j_nav, navt_obj, "nt");
	navt->ntmax = getIntParam(env, j_nav, navt_obj, "ntmax");
	navt->eph = (eph_t*)malloc(sizeof(eph_t)*navt->n);
	jfieldID data_field_id = (*env).GetFieldID(j_nav, "eph", "[Lrtk/model/EphT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->n; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			eph_t eph = convertCEphT(env, jdata);
			navt->eph[i] = eph;
		}
		
	}
	navt->geph = (geph_t*)malloc(sizeof(geph_t)*navt->ng);
	data_field_id = (*env).GetFieldID(j_nav, "geph", "[Lrtk/model/GephT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->ng; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			geph_t geph = convertCGephT(env, jdata);
			navt->geph[i] = geph;
		}
		
	}

	navt->seph = (seph_t*)malloc(sizeof(seph_t)*navt->ns);
	data_field_id = (*env).GetFieldID(j_nav, "seph", "[Lrtk/model/SephT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->ns; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			seph_t seph = convertCSephT(env, jdata);
			navt->seph[i] = seph;
		}
		
	}
	navt->peph = (peph_t*)malloc(sizeof(peph_t)*navt->ne);
	data_field_id = (*env).GetFieldID(j_nav, "peph", "[Lrtk/model/PephT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->ne; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			peph_t peph = convertCPephT(env, jdata);
			navt->peph[i] = peph;
		}
		
	}
	navt->pclk = (pclk_t*)malloc(sizeof(pclk_t)*navt->nc);
	data_field_id = (*env).GetFieldID(j_nav, "pclk", "[Lrtk/model/PclkT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->nc; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			pclk_t pclk = convertCPclkT(env, jdata);
			navt->pclk[i] = pclk;
		}
		
	}
	navt->alm = (alm_t*)malloc(sizeof(alm_t)*navt->na);
	data_field_id = (*env).GetFieldID(j_nav, "alm", "[Lrtk/model/AlmT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->na; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			alm_t alm = convertCAlmT(env, jdata);
			navt->alm[i] = alm;
		}
		
	}
	navt->tec = (tec_t*)malloc(sizeof(tec_t)*navt->nt);
	data_field_id = (*env).GetFieldID(j_nav, "tec", "[Lrtk/model/TecT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->nt; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			tec_t tec = convertCTecT(env, jdata);
			navt->tec[i] = tec;
		}
		
	}

	/*data_field_id = (*env).GetFieldID(j_nav, "erp", "Lrtk/model/ErpT;");
	jobject jdata = (*env).GetObjectField(navt_obj, data_field_id);
	if (jdata != NULL)
		navt->erp = convertCErpT(env, jdata);*/

	//navt.utc_gps
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_gps", 8, navt->utc_gps);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_glo", 8, navt->utc_glo);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_gal", 8, navt->utc_gal);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_qzs", 8, navt->utc_qzs);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_cmp", 8, navt->utc_cmp);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_irn", 9, navt->utc_irn);
	getDoubleArrayParam(env, j_nav, navt_obj, "utc_sbs", 4, navt->utc_sbs);

	getDoubleArrayParam(env, j_nav, navt_obj, "ion_gps", 8, navt->ion_gps);
	getDoubleArrayParam(env, j_nav, navt_obj, "ion_gal", 4, navt->ion_gal);
	getDoubleArrayParam(env, j_nav, navt_obj, "ion_qzs", 8, navt->ion_qzs);
	getDoubleArrayParam(env, j_nav, navt_obj, "ion_cmp", 8, navt->ion_cmp);
	getDoubleArrayParam(env, j_nav, navt_obj, "ion_irn", 8, navt->ion_irn);

	getIntArrayParam(env, j_nav, navt_obj, "glo_fcn", 32, navt->glo_fcn);

	getDoubleArrayParam21(env, j_nav, navt_obj, "cbias", navt->cbias);
	getDoubleArrayParam31(env, j_nav, navt_obj, "rbias", navt->rbias);

	data_field_id = (*env).GetFieldID(j_nav, "pcvs", "[Lrtk/model/PcvT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	for (int i = 0; i < navt->nt; i++)
	{
		jobject jdata = env->GetObjectArrayElement(jdataArray, i);
		if (jdata != NULL)
		{
			pcv_t pcv = convertCPcvT(env, jdata);
			navt->pcvs[i] = pcv;
		}
		
	}

	data_field_id = (*env).GetFieldID(j_nav, "sbssat", "Lrtk/model/SbssatT;");
	jobject jdata = (*env).GetObjectField(navt_obj, data_field_id);
	//youwenti
	if (jdata != NULL)
		navt->sbssat = convertCSbssatT(env, jdata);

	data_field_id = (*env).GetFieldID(j_nav, "sbsion", "[Lrtk/model/SbsionT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXBAND + 1; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				sbsion_t sbsion = convertCSbsionT(env, jdata);
				navt->sbsion[i] = sbsion;
			}
			
		}
	}
	

	data_field_id = (*env).GetFieldID(j_nav, "dgps", "[Lrtk/model/DgpsT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXSAT; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				dgps_t dgps = convertCDgpsT(env, jdata);
				navt->dgps[i] = dgps;
			}
			
		}
	}
	

	data_field_id = (*env).GetFieldID(j_nav, "ssr", "[Lrtk/model/SsrT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(navt_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXSAT; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				ssr_t ssr = convertCSsrT(env, jdata);
				navt->ssr[i] = ssr;
			}
			
		}
	}
	

	env->DeleteLocalRef(j_nav);
	env->DeleteLocalRef(jdataArray);
	env->DeleteLocalRef(jdata);

	return;
}
snrmask_t convertCSnrmaskT(JNIEnv *env, jobject snrmask_obj)
{
	snrmask_t snrmask = { 0 };
	jclass j_snrmask = (*env).FindClass("rtk/model/SnrmaskT");
	getIntArrayParam(env, j_snrmask, snrmask_obj, "ena", 2, snrmask.ena);
	getDoubleArrayParam26(env, j_snrmask, snrmask_obj, "mask", snrmask.mask);
	env->DeleteLocalRef(j_snrmask);
	return snrmask;
}


//配置文件java转C

void convertCPrcoptT(JNIEnv *env, jobject prcopt_obj, prcopt_t *prcopt)
{
	jclass j_prcopt = (*env).FindClass("rtk/model/PrcoptT");
	prcopt->mode = getIntParam(env, j_prcopt, prcopt_obj, "mode");
	prcopt->soltype = getIntParam(env, j_prcopt, prcopt_obj, "soltype");
	prcopt->nf = getIntParam(env, j_prcopt, prcopt_obj, "nf");
	prcopt->navsys = getIntParam(env, j_prcopt, prcopt_obj, "navsys");
	prcopt->elmin = getDoubleParam(env, j_prcopt, prcopt_obj, "elmin");
	jfieldID data_field_id = (*env).GetFieldID(j_prcopt, "snrmask", "Lrtk/model/SnrmaskT;");
	jobject jdata = (*env).GetObjectField(prcopt_obj, data_field_id);
	prcopt->snrmask = convertCSnrmaskT(env, jdata);
	prcopt->sateph = getIntParam(env, j_prcopt, prcopt_obj, "sateph");
	prcopt->modear = getIntParam(env, j_prcopt, prcopt_obj, "modear");
	prcopt->glomodear = getIntParam(env, j_prcopt, prcopt_obj, "glomodear");
	prcopt->bdsmodear = getIntParam(env, j_prcopt, prcopt_obj, "bdsmodear");
	prcopt->maxout = getIntParam(env, j_prcopt, prcopt_obj, "maxout");
	prcopt->minlock = getIntParam(env, j_prcopt, prcopt_obj, "minlock");
	prcopt->minfix = getIntParam(env, j_prcopt, prcopt_obj, "minfix");
	prcopt->armaxiter = getIntParam(env, j_prcopt, prcopt_obj, "armaxiter");
	prcopt->ionoopt = getIntParam(env, j_prcopt, prcopt_obj, "ionoopt");
	prcopt->tropopt = getIntParam(env, j_prcopt, prcopt_obj, "tropopt");
	prcopt->dynamics = getIntParam(env, j_prcopt, prcopt_obj, "dynamics");
	prcopt->tidecorr = getIntParam(env, j_prcopt, prcopt_obj, "tidecorr");
	prcopt->niter = getIntParam(env, j_prcopt, prcopt_obj, "niter");
	prcopt->codesmooth = getIntParam(env, j_prcopt, prcopt_obj, "codesmooth");
	prcopt->intpref = getIntParam(env, j_prcopt, prcopt_obj, "intpref");
	prcopt->sbascorr = getIntParam(env, j_prcopt, prcopt_obj, "sbascorr");
	prcopt->sbassatsel = getIntParam(env, j_prcopt, prcopt_obj, "sbassatsel");
	prcopt->rovpos = getIntParam(env, j_prcopt, prcopt_obj, "rovpos");
	prcopt->refpos = getIntParam(env, j_prcopt, prcopt_obj, "refpos");
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "eratio", NFREQ, prcopt->eratio);
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "err", 5, prcopt->err);
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "std", 3, prcopt->std);
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "prn", 6, prcopt->prn);
	prcopt->sclkstab = getDoubleParam(env, j_prcopt, prcopt_obj, "sclkstab");
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "thresar", 8, prcopt->thresar);
	prcopt->elmaskar = getDoubleParam(env, j_prcopt, prcopt_obj, "elmaskar");
	prcopt->elmaskhold = getDoubleParam(env, j_prcopt, prcopt_obj, "elmaskhold");
	prcopt->thresslip = getDoubleParam(env, j_prcopt, prcopt_obj, "thresslip");
	prcopt->maxtdiff = getDoubleParam(env, j_prcopt, prcopt_obj, "maxtdiff");
	prcopt->maxinno = getDoubleParam(env, j_prcopt, prcopt_obj, "maxinno");
	prcopt->maxgdop = getDoubleParam(env, j_prcopt, prcopt_obj, "maxgdop");
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "baseline", 2, prcopt->baseline);
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "ru", 3, prcopt->ru);
	getDoubleArrayParam(env, j_prcopt, prcopt_obj, "rb", 3, prcopt->rb);
	getCharArrayParam21(env, j_prcopt, prcopt_obj, "anttype", prcopt->anttype);
	getDoubleArrayParam27(env, j_prcopt, prcopt_obj, "antdel", prcopt->antdel);

	data_field_id = (*env).GetFieldID(j_prcopt, "pcvr", "[Lrtk/model/PcvT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(j_prcopt, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < 2; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				pcv_t pcv = convertCPcvT(env, jdata);
				prcopt->pcvr[i] = pcv;
			}
			env->DeleteLocalRef(jdata);
			
		}
	}
	
	getInt8ArrayParam(env, j_prcopt, prcopt_obj, "exsats", MAXANT, prcopt->exsats);
	prcopt->maxaveep = getIntParam(env, j_prcopt, prcopt_obj, "maxaveep");
	prcopt->initrst = getIntParam(env, j_prcopt, prcopt_obj, "initrst");
	prcopt->outsingle = getIntParam(env, j_prcopt, prcopt_obj, "outsingle");
	getCharArrayParam22(env, j_prcopt, prcopt_obj, "rnxopt", prcopt->rnxopt);
	getIntArrayParam(env, j_prcopt, prcopt_obj, "posopt", 6, prcopt->posopt);
	prcopt->syncsol = getIntParam(env, j_prcopt, prcopt_obj, "syncsol");
	getDoubleArrayParam28(env, j_prcopt, prcopt_obj, "odisp", prcopt->odisp);
	prcopt->freqopt = getIntParam(env, j_prcopt, prcopt_obj, "freqopt");
	getCharArrayParam(env, j_prcopt, prcopt_obj, "pppopt", 256, prcopt->pppopt);
	env->DeleteLocalRef(j_prcopt);
	env->DeleteLocalRef(jdata);
	env->DeleteLocalRef(jdataArray);

}

sol_t convertCSolT(JNIEnv *env, jobject sol_obj)
{
	sol_t sol = { 0 };
	jclass j_sol = (*env).FindClass("rtk/model/SolT");
	sol.time = getGtime(env, j_sol, sol_obj, "time");
	getDoubleArrayParam(env, j_sol, sol_obj, "rr", 6, sol.rr);
	getFloatArrayParam(env, j_sol, sol_obj, "qr", 6, sol.qr);
	getFloatArrayParam(env, j_sol, sol_obj, "qv", 6, sol.qv);
	getDoubleArrayParam(env, j_sol, sol_obj, "dtr", 6, sol.dtr);

	sol.type = getIntParam(env, j_sol, sol_obj, "type");
	sol.stat = getIntParam(env, j_sol, sol_obj, "stat");
	sol.ns = getIntParam(env, j_sol, sol_obj, "ns");

	sol.age = getFloatParam(env, j_sol, sol_obj, "age");
	sol.ratio = getFloatParam(env, j_sol, sol_obj, "ratio");
	sol.thres = getFloatParam(env, j_sol, sol_obj, "thres");
	env->DeleteLocalRef(j_sol);
	return sol;
}


ambc_t convertCAmbcT(JNIEnv *env, jobject ambc_obj)
{
	ambc_t ambc = { 0 };
	jclass j_ambc = (*env).FindClass("rtk/model/AmbcT");
	getGtimeArrayParam(env, j_ambc, ambc_obj, "epoch", 4, ambc.epoch);
	getIntArrayParam(env, j_ambc, ambc_obj, "n", 4, ambc.n);
	getDoubleArrayParam(env, j_ambc, ambc_obj, "LC", 4, ambc.LC);
	getDoubleArrayParam(env, j_ambc, ambc_obj, "LCv", 4, ambc.LCv);
	ambc.fixcnt = getIntParam(env, j_ambc, ambc_obj, "fixcnt");
	getCharArrayParam(env, j_ambc, ambc_obj, "flags", MAXSAT, ambc.flags);
	env->DeleteLocalRef(j_ambc);
	return ambc;
}

ssat_t convertCSsatT(JNIEnv *env, jobject ssat_obj)
{
	ssat_t ssat = { 0 };
	jclass j_ssat = (*env).FindClass("rtk/model/SsatT");
	ssat.sys = getIntParam(env, j_ssat, ssat_obj, "sys");
	ssat.vs = getIntParam(env, j_ssat, ssat_obj, "vs");
	getDoubleArrayParam(env, j_ssat, ssat_obj, "azel", 2, ssat.azel);
	getDoubleArrayParam(env, j_ssat, ssat_obj, "resp", NFREQ, ssat.resp);
	getDoubleArrayParam(env, j_ssat, ssat_obj, "resc", NFREQ, ssat.resc);
	getInt8ArrayParam(env, j_ssat, ssat_obj, "vsat", NFREQ, ssat.vsat);
	getInt16ArrayParam(env, j_ssat, ssat_obj, "snr", NFREQ, ssat.snr);
	getInt8ArrayParam(env, j_ssat, ssat_obj, "fix", NFREQ, ssat.fix);
	getInt8ArrayParam(env, j_ssat, ssat_obj, "slip", NFREQ, ssat.slip);
	getInt8ArrayParam(env, j_ssat, ssat_obj, "half", NFREQ, ssat.half);
	getIntArrayParam(env, j_ssat, ssat_obj, "lock", NFREQ, ssat.lock);

	getInt32ArrayParam(env, j_ssat, ssat_obj, "outc", NFREQ, ssat.outc);
	getInt32ArrayParam(env, j_ssat, ssat_obj, "slipc", NFREQ, ssat.slipc);
	getInt32ArrayParam(env, j_ssat, ssat_obj, "rejc", NFREQ, ssat.rejc);

	getDoubleArrayParam(env, j_ssat, ssat_obj, "gf", NFREQ - 1, ssat.gf);
	getDoubleArrayParam(env, j_ssat, ssat_obj, "mw", NFREQ - 1, ssat.mw);
	ssat.phw = getDoubleParam(env, j_ssat, ssat_obj, "phw");
	getGtimeArrayParam21(env, j_ssat, ssat_obj, "pt", ssat.pt);
	getDoubleArrayParam29(env, j_ssat, ssat_obj, "ph", ssat.ph);
	env->DeleteLocalRef(j_ssat);
	return ssat;
}

rtk_t convertCRtkT(JNIEnv *env, jobject rtk_obj)
{
	rtk_t rtk = { 0 };
	jclass j_class = (*env).FindClass("rtk/model/RtkT");
	jfieldID data_field_id = (*env).GetFieldID(j_class, "sol", "Lrtk/model/SolT;");
	jobject jdata = (*env).GetObjectField(rtk_obj, data_field_id);
	if (jdata != NULL)
		rtk.sol = convertCSolT(env, jdata);
	getDoubleArrayParam(env, j_class, rtk_obj, "rb", 6, rtk.rb);
	rtk.nx = getIntParam(env, j_class, rtk_obj, "nx");
	rtk.na = getIntParam(env, j_class, rtk_obj, "na");
	rtk.tt = getDoubleParam(env, j_class, rtk_obj, "tt");

	getDoubleArrayParam(env, j_class, rtk_obj, "x", rtk.nx, rtk.x);
	getDoubleArrayParam(env, j_class, rtk_obj, "P", rtk.nx, rtk.P);
	getDoubleArrayParam(env, j_class, rtk_obj, "xa", rtk.na, rtk.xa);
	getDoubleArrayParam(env, j_class, rtk_obj, "Pa", rtk.na, rtk.Pa);
	rtk.nfix = getIntParam(env, j_class, rtk_obj, "nfix");

	data_field_id = (*env).GetFieldID(j_class, "ambc", "[Lrtk/model/AmbcT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(rtk_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXSAT; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				ambc_t ambc = convertCAmbcT(env, jdata);
				rtk.ambc[i] = ambc;
			}
		}
	}

	data_field_id = (*env).GetFieldID(j_class, "ssat", "[Lrtk/model/SsatT;");
	jdataArray = (jobjectArray)(*env).GetObjectField(rtk_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXSAT; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				ssat_t ssat = convertCSsatT(env, jdata);
				rtk.ssat[i] = ssat;
			}
		}
	}
	rtk.neb = getIntParam(env, j_class, rtk_obj, "neb");
	getCharArrayParam(env, j_class, rtk_obj, "errbuf", MAXERRMSG,rtk.errbuf);

	jfieldID data_field_id2 = (*env).GetFieldID(j_class, "sol", "Lrtk/model/PrcoptT;");
	jobject jdata2 = (*env).GetObjectField(rtk_obj, data_field_id);
	if (jdata != NULL)
		convertCPrcoptT(env, jdata2, &rtk.opt);

	env->DeleteLocalRef(j_class);
	env->DeleteLocalRef(jdata);
	env->DeleteLocalRef(jdata2);
	env->DeleteLocalRef(jdataArray);
	return rtk;
}

void convertCStaT(JNIEnv *env,jobject sta_obj, sta_t sta)
{
	jclass j_sta = (*env).FindClass("rtk/model/StaT");
	getCharArrayParam(env, j_sta, sta_obj, "name", MAXANT, sta.name);
	getCharArrayParam(env, j_sta, sta_obj, "marker", MAXANT, sta.marker);
	getCharArrayParam(env, j_sta, sta_obj, "antdes", MAXANT, sta.antdes);
	getCharArrayParam(env, j_sta, sta_obj, "antsno", MAXANT, sta.antsno);
	getCharArrayParam(env, j_sta, sta_obj, "rectype", MAXANT, sta.rectype);
	getCharArrayParam(env, j_sta, sta_obj, "recver", MAXANT, sta.recver);
	getCharArrayParam(env, j_sta, sta_obj, "recsno", MAXANT, sta.recsno);
	sta.antsetup = getIntParam(env, j_sta, sta_obj, "antsetup");
	sta.itrf = getIntParam(env, j_sta, sta_obj, "itrf");
	sta.deltype = getIntParam(env, j_sta, sta_obj, "deltype");
	getDoubleArrayParam(env, j_sta, sta_obj, "pos", 3, sta.pos);
	getDoubleArrayParam(env, j_sta, sta_obj, "del", 3, sta.del);
	sta.hgt = getDoubleParam(env, j_sta, sta_obj, "hgt");
	sta.glo_cp_align = getIntParam(env, j_sta, sta_obj, "glo_cp_align");
	getDoubleArrayParam(env, j_sta, sta_obj, "glo_cp_bias", 4, sta.glo_cp_bias);
	env->DeleteLocalRef(j_sta);
}

void convertCRtcmT(JNIEnv *env, jobject rtcm_obj, rtcm_t *rtcm)
{
	jclass j_class = (*env).FindClass("rtk/model/RtcmT");
	rtcm->staid = getIntParam(env, j_class, rtcm_obj, "staid");
	rtcm->stah = getIntParam(env, j_class, rtcm_obj, "stah");
	rtcm->seqno = getIntParam(env, j_class, rtcm_obj, "seqno");
	rtcm->outtype = getIntParam(env, j_class, rtcm_obj, "outtype");
	rtcm->time = getGtime(env, j_class, rtcm_obj, "time");
	rtcm->time_s = getGtime(env, j_class, rtcm_obj, "time_s");
	jfieldID data_field_id = (*env).GetFieldID(j_class, "obs", "Lrtk/model/ObsT;");
	jobject jdata = (*env).GetObjectField(rtcm_obj, data_field_id);
	if (jdata != NULL)
		convertCObsT(env, &rtcm->obs, jdata);
	data_field_id = (*env).GetFieldID(j_class, "nav", "Lrtk/model/NavT;");
	jdata = (*env).GetObjectField(rtcm_obj, data_field_id);
	if (jdata != NULL)
		convertCNavT(env, jdata, &rtcm->nav);

	data_field_id = (*env).GetFieldID(j_class, "sta", "Lrtk/model/StaT;");
	jdata = (*env).GetObjectField(rtcm_obj, data_field_id);
	if (jdata != NULL)
		convertCStaT(env, jdata, rtcm->sta);
	//dgps暂时不处理

	data_field_id = (*env).GetFieldID(j_class, "ssr", "[Lrtk/model/SsrT;");
	jobjectArray jdataArray = (jobjectArray)(*env).GetObjectField(rtcm_obj, data_field_id);
	if (jdataArray != NULL)
	{
		for (int i = 0; i < MAXSAT; i++)
		{
			jobject jdata = env->GetObjectArrayElement(jdataArray, i);
			if (jdata != NULL)
			{
				ssr_t ssr = convertCSsrT(env, jdata);
				rtcm->ssr[i] = ssr;
			}
		}
	}
	getCharArrayParam(env, j_class, rtcm_obj, "msg", 128, rtcm->msg);
	getCharArrayParam(env, j_class, rtcm_obj, "msgtype", 256, rtcm->msgtype);
	getCharArrayParam23(env, j_class, rtcm_obj, "msmtype", rtcm->msmtype);

	rtcm->obsflag = getIntParam(env, j_class, rtcm_obj, "obsflag");
	rtcm->ephsat = getIntParam(env, j_class, rtcm_obj, "ephsat");
	rtcm->ephset = getIntParam(env, j_class, rtcm_obj, "ephset");
	getDoubleArrayParam210(env, j_class, rtcm_obj, "cp", rtcm->cp);
	getInt16ArrayParam21(env, j_class, rtcm_obj, "lock", rtcm->lock);
	getInt16ArrayParam21(env, j_class, rtcm_obj, "loss", rtcm->loss);
	getGtimeArrayParam22(env, j_class, rtcm_obj, "lltime", rtcm->lltime);

	rtcm->nbyte = getIntParam(env, j_class, rtcm_obj, "nbyte");
	rtcm->nbit = getIntParam(env, j_class, rtcm_obj, "nbit");
	rtcm->len = getIntParam(env, j_class, rtcm_obj, "len");
	getByteArrayParam(env, j_class, rtcm_obj, "buff", 1200, rtcm->buff);
	rtcm->word = getIntParam(env, j_class, rtcm_obj, "word");
	getInt32ArrayParam(env, j_class, rtcm_obj, "nmsg2", 100, rtcm->nmsg2);
	getInt32ArrayParam(env, j_class, rtcm_obj, "nmsg3", 400, rtcm->nmsg3);
	getCharArrayParam(env, j_class, rtcm_obj, "opt", 256, rtcm->opt);

	env->DeleteLocalRef(j_class);
	env->DeleteLocalRef(jdata);
	env->DeleteLocalRef(jdataArray);
}

