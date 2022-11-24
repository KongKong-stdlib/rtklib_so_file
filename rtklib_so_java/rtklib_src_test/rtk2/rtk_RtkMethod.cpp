#include "jni/jni.h"
#include "rtk_RtkMethod.h"
#include "../src/rtklib.h"
#include "rtkjni.h"
#include "rtkc2java.h"
#include "rtkjava2c.h"
#include "GtimeT.h"
#include "ObsdT.h"
#include "EphT.h"
#include "GephT.h"
#include "NavT.h"
#include "SolT.h"
#include "SsatT.h"
#include "RtkT.h"
#include "PrcoptT.h"
#include <map>
using namespace std;

obsd_t *obs = NULL;
char* msg = (char*)malloc(sizeof(char)* 100);
nav_t *global_nav = NULL;
prcopt_t global_opt = prcopt_default;

jclass GtimeT::cls = NULL;
jfieldID GtimeT::timeID = NULL;
jfieldID GtimeT::secID = NULL;
jmethodID GtimeT::j_gtime_methodID = NULL;

jclass ObsdT::cls = NULL;
jfieldID ObsdT::timeID = NULL;
jfieldID ObsdT::satID = NULL;
jfieldID ObsdT::rcvID = NULL;
jfieldID ObsdT::SNRID = NULL;
jfieldID ObsdT::LLIID = NULL;
jfieldID ObsdT::codeID = NULL;
jfieldID ObsdT::LID = NULL;
jfieldID ObsdT::PID = NULL;
jfieldID ObsdT::DID = NULL;
jmethodID ObsdT::j_obsd_methodID = NULL;

jclass EphT::cls = NULL;
jfieldID EphT::satID = NULL;
jfieldID EphT::iodeID = NULL;
jfieldID EphT::iodcID = NULL;
jfieldID EphT::svaID = NULL;
jfieldID EphT::svhID = NULL;
jfieldID EphT::weekID = NULL;
jfieldID EphT::codeID = NULL;
jfieldID EphT::flagID = NULL;
jfieldID EphT::toeID = NULL;
jfieldID EphT::tocID = NULL;
jfieldID EphT::ttrID = NULL;
jfieldID EphT::AID = NULL;
jfieldID EphT::eID = NULL;
jfieldID EphT::i0ID = NULL;
jfieldID EphT::OMG0ID = NULL;
jfieldID EphT::omgID = NULL;
jfieldID EphT::M0ID = NULL;
jfieldID EphT::delnID = NULL;
jfieldID EphT::OMGdID = NULL;
jfieldID EphT::idotID = NULL;
jfieldID EphT::crcID = NULL;
jfieldID EphT::crsID = NULL;
jfieldID EphT::cucID = NULL;
jfieldID EphT::cusID = NULL;
jfieldID EphT::cicID = NULL;
jfieldID EphT::cisID = NULL;
jfieldID EphT::toesID = NULL;
jfieldID EphT::fitID = NULL;
jfieldID EphT::f0ID = NULL;
jfieldID EphT::f1ID = NULL;
jfieldID EphT::f2ID = NULL;
jfieldID EphT::tgdID = NULL;
jfieldID EphT::AdotID = NULL;
jfieldID EphT::ndotID = NULL;
jmethodID EphT::j_eph_methodID = NULL;

jclass GephT::cls = NULL;
jfieldID GephT::satID = NULL;
jfieldID GephT::iodeID = NULL;
jfieldID GephT::frqID = NULL;
jfieldID GephT::svaID = NULL;
jfieldID GephT::svhID = NULL;
jfieldID GephT::ageID = NULL;
jfieldID GephT::toeID = NULL;
jfieldID GephT::tofID = NULL;
jfieldID GephT::posID = NULL;
jfieldID GephT::velID = NULL;
jfieldID GephT::accID = NULL;
jfieldID GephT::taunID = NULL;
jfieldID GephT::gamnID = NULL;
jfieldID GephT::dtaunID = NULL;
jmethodID GephT::j_geph_methodID = NULL;

jclass NavT::cls = NULL;
jfieldID NavT::nID = NULL;
jfieldID NavT::nmaxID = NULL;
jfieldID NavT::ngID = NULL;
jfieldID NavT::ngmaxID = NULL;
jfieldID NavT::ephID = NULL;
jfieldID NavT::gephID = NULL;
jfieldID NavT::utc_gpsID = NULL;
jfieldID NavT::utc_gloID = NULL;
jfieldID NavT::utc_galID = NULL;
jfieldID NavT::utc_qzsID = NULL;
jfieldID NavT::utc_cmpID = NULL;
jfieldID NavT::utc_irnID = NULL;
jfieldID NavT::utc_sbsID = NULL;
jfieldID NavT::ion_gpsID = NULL;
jfieldID NavT::ion_galID = NULL;
jfieldID NavT::ion_qzsID = NULL;
jfieldID NavT::ion_cmpID = NULL;
jfieldID NavT::ion_irnID = NULL;
jfieldID NavT::glo_fcnID = NULL;
jmethodID NavT::j_nav_methodID = NULL;

jclass SolT::cls = NULL;
jfieldID SolT::timeID = NULL;
jfieldID SolT::rrID = NULL;
jfieldID SolT::qrID = NULL;
jfieldID SolT::qvID = NULL;
jfieldID SolT::dtrID = NULL;
jfieldID SolT::typeID = NULL;
jfieldID SolT::statID = NULL;
jfieldID SolT::nsID = NULL;
jfieldID SolT::ageID = NULL;
jfieldID SolT::ratioID = NULL;
jfieldID SolT::thresID = NULL;
jmethodID SolT::j_sol_methodID = NULL;

jclass SsatT::cls = NULL;
jfieldID SsatT::sysID = NULL;
jfieldID SsatT::vsID = NULL;
jfieldID SsatT::azelID = NULL;
jfieldID SsatT::respID = NULL;
jfieldID SsatT::rescID = NULL;
jfieldID SsatT::vsatID = NULL;
jfieldID SsatT::snrID = NULL;
jfieldID SsatT::fixID = NULL;
jfieldID SsatT::slipID = NULL;
jfieldID SsatT::halfID = NULL;
jfieldID SsatT::lockID = NULL;
jfieldID SsatT::outcID = NULL;
jfieldID SsatT::slipcID = NULL;
jfieldID SsatT::rejcID = NULL;
jfieldID SsatT::gfID = NULL;
jfieldID SsatT::mwID = NULL;
jfieldID SsatT::phwID = NULL;
jfieldID SsatT::ptID = NULL;
jfieldID SsatT::phID = NULL;
jmethodID SsatT::j_ssat_methodID = NULL;

jclass RtkT::cls = NULL;
jfieldID RtkT::solID = NULL;
jfieldID RtkT::rbID = NULL;
jfieldID RtkT::nxID = NULL;
jfieldID RtkT::naID = NULL;
jfieldID RtkT::ttID = NULL;
jfieldID RtkT::xID = NULL;
jfieldID RtkT::PID = NULL;
jfieldID RtkT::xaID = NULL;
jfieldID RtkT::PaID = NULL;
jfieldID RtkT::nfixID = NULL;
jfieldID RtkT::ambcID = NULL;
jfieldID RtkT::ssatID = NULL;
jfieldID RtkT::nebID = NULL;
jfieldID RtkT::errbufID = NULL;
jfieldID RtkT::optID = NULL;

jclass PrcoptT::cls = NULL;
jfieldID PrcoptT::navsysID = NULL;
jfieldID PrcoptT::ionooptID = NULL;
jfieldID PrcoptT::tropoptID = NULL;
jfieldID PrcoptT::elminID = NULL;
jfieldID PrcoptT::nfID = NULL;
jfieldID PrcoptT::satephID = NULL;
jfieldID PrcoptT::modeID = NULL;
jfieldID PrcoptT::modearID = NULL;
jfieldID PrcoptT::refposID = NULL;
jfieldID PrcoptT::rbID = NULL;
jfieldID PrcoptT::bdsmodearID = NULL;
jfieldID PrcoptT::glomodearID = NULL;
jfieldID PrcoptT::soltypeID = NULL;
jfieldID PrcoptT::validThresARID = NULL;
rnxopt_t* rnxopt = NULL;

//C++内部控制一个rtk结构用来存储
map<int, rtk_t*> rtkMap;

//建立连接时向map中添加一个rtk_t

JNIEXPORT void JNICALL Java_rtk_RtkMethod_addRtkMap
(JNIEnv *env, jobject jobj, jint id)
{
	rtk_t* rtk = (rtk_t*)malloc(sizeof(rtk_t)*MAXOBS);
	rtkinit(rtk, &global_opt);
	rtkMap.insert(pair<int, rtk_t*>(id, rtk));
}

//断开连接时向map移除一个rtk_t
JNIEXPORT void JNICALL Java_rtk_RtkMethod_delRtkMap
(JNIEnv *env, jobject jobj, jint id)
{
	if (rtkMap.count(id) > 0)
	{
		rtk_t* rtk = rtkMap[id];
		rtkfree(rtk);
		free(rtk);
		rtkMap.erase(id);
	}
}

rtk_t*  findRtk(int id)
{
	if (rtkMap.count(id) > 0)
	{
		return rtkMap[id];
	}
	return NULL;
}

void init_rnxopt(rnxopt_t* opt)
{
	gtime_t t = { 0 };
	t.time = 0;
	t.sec = 0;
	opt->ts = t;
	opt->te = t;
	memset(opt->marker, 0, 64);
	memset(opt->markerno, 0, 32);
	memset(opt->markertype, 0, 32);
	memset(opt->name[0], 0, 32);
	memset(opt->name[1], 0, 32);
	memset(opt->rec[0], 0, 32);
	memset(opt->rec[1], 0, 32);
	memset(opt->rec[2], 0, 32);
	memset(opt->ant[0], 0, 32);
	memset(opt->ant[1], 0, 32);
	memset(opt->ant[2], 0, 32);
	for (int i = 0; i < 100; i++)
	{
		memset(opt->comment[i], 0, 64);
	}
	memset(opt->exsats, 0, 32);
	memset(opt->runby, 0, 32);
	memset(opt->prog, 0, 32);
	opt->sep_nav = 0;
	opt->tunit = 0;
	opt->rnxver = 303;
	opt->navsys = 0xFF;
	opt->freqtype = 0x7;
	opt->obstype = 0xF;
	opt->autopos = 0;
	opt->outiono = 0;
	opt->outtime = 0;
	opt->outleaps = 0;
	opt->phshift = 0;
	opt->halfcyc = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < MAXOBSTYPE; j++)
		{
			opt->shift[i][j] = 0;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			opt->mask[i][j] = 1;
		}
	}

	for (int i = 0; i < MAXSAT; i++)
	{
		opt->exsats[i] = 0;
	}
	opt->staid[0] = '0';
	opt->staid[1] = '0';
	opt->staid[2] = '0';
	opt->staid[3] = '0';
	opt->staid[4] = 0;
	opt->apppos[0] = 0;
	opt->apppos[1] = 0;
	opt->apppos[2] = 0;
	opt->antdel[0] = 0;
	opt->antdel[1] = 0;
	opt->antdel[2] = 0;
	opt->ttol = 0.005;
}
rtk_t* global_rtk;
JNIEXPORT jint JNICALL Java_rtk_RtkMethod_loadRtkJni
(JNIEnv * env, jobject jobj, jobject opt_obj)
{
	GtimeT::initGtimeT(env);
	ObsdT::initObsdT(env);
	EphT::initEphT(env);
	GephT::initGephT(env);
	NavT::initNavT(env);
	SsatT::initSsatT(env);
	SolT::initSolT(env);
	RtkT::initRtkT(env);
	PrcoptT::initPrcoptT(env);

	obs = (obsd_t*)malloc(sizeof(obsd_t)*MAXOBS*2);
	msg = (char*)malloc(sizeof(char)* 100);

	eph_t  eph0 = { 0, -1, -1 };
	geph_t geph0 = { 0, -1 };
	global_nav = (nav_t  *)malloc(sizeof(nav_t));
	memset(global_nav, 0, sizeof(nav_t));
	if (
		!(global_nav->eph = (eph_t  *)malloc(sizeof(eph_t)*MAXSAT * 2)) ||
		!(global_nav->geph = (geph_t *)malloc(sizeof(geph_t)*MAXPRNGLO))) {

		return 0;
	}
	global_nav->erp.n = 0;
	global_nav->n = 0;
	global_nav->n = MAXSAT * 2;
	global_nav->ng = MAXPRNGLO;
	int ii = 0;
	for (ii = 0; ii<MAXSAT * 2; ii++) global_nav->eph[ii] = eph0;
	for (ii = 0; ii<MAXPRNGLO; ii++) global_nav->geph[ii] = geph0;

	global_opt = PrcoptT::convertCPrcoptT(env, opt_obj);
	rnxopt = (rnxopt_t  *)malloc(sizeof(rnxopt_t));
	init_rnxopt(rnxopt);

	global_rtk = (rtk_t*)malloc(sizeof(rtk_t)*MAXOBS);
	rtkinit(global_rtk, &global_opt);

	return 1;
}


JNIEXPORT jint JNICALL Java_rtk_RtkMethod_pntpos
(JNIEnv *env, jobject jobj,jobjectArray obsds, jint n, jobject nav_obj)
{
	ssat_t ssat[MAXSAT];
	rtk_t rtkt = { 0 };
	prcopt_t prcopt = prcopt_default; /* 默认处理选项设置 */
	prcopt.sateph = EPHOPT_BRDC; /* 使用广播星历 */
	prcopt.navsys = SYS_GPS | SYS_CMP; /* 处理的导航系统 */

	prcopt.ionoopt = IONOOPT_BRDC;  /* 使用广播电离层模型 */
	prcopt.tropopt = TROPOPT_SAAS;  /* 使用萨斯坦莫宁模型 */
	//prcopt.navsys = SYS_CMP; /* 处理的导航系统 */
	prcopt.elmin = 10.0 * D2R;/* 卫星截止高度角 */
	prcopt.nf = 2;
	
	jobject obj;
	//对Obsd赋值
	for (int i = 0; i < n; i++)
	{
		obj = env->GetObjectArrayElement(obsds, i);
		obsd_t obsdt = ObsdT::convertCObsdT(env, obj);
		obs[i] = obsdt;
	}
	NavT::convertCNavT(env, nav_obj, global_nav);
	
	int ret = pntpos(obs, n, global_nav, &prcopt, &rtkt.sol, NULL, ssat, msg);
	return ret;

}

JNIEXPORT void JNICALL Java_rtk_RtkMethod_testSsat(JNIEnv *env, jobject jobj, jobject ssat_obj)
{
	ssat_t ssat = { 0 };
	ssat.ph[0][0] = 1;
	ssat.ph[1][1] = 3;

	gtime_t time1;
	time1.time = 1000;
	time1.sec = 0.1;

	gtime_t time2;
	time2.time = 2000;
	time2.sec = 0.2;

	ssat.pt[0][0] = time1;
	ssat.pt[1][1] = time2;

	SsatT::convertJavaSsat(env, ssat, ssat_obj);

}

JNIEXPORT void JNICALL Java_rtk_RtkMethod_rtkinit
(JNIEnv *env, jobject jobj, jobject rtk_obj)
{
	rtk_t* rtk = (rtk_t*)malloc(sizeof(rtk_t)*MAXOBS);
	rtkinit(rtk, &global_opt);
	RtkT::convertJavaRtk(env, *rtk, rtk_obj);
	rtkfree(rtk);
	free(rtk);
}

jobject obsd_obj = NULL;
JNIEXPORT jint JNICALL Java_rtk_RtkMethod_rtkpos
(JNIEnv *env, jobject jobj, jobject rtk_obj, jobjectArray obsds, jint n, jobject nav_obj,jint id)
{
	rtk_t *rtk = findRtk(id);
	if (rtk == NULL)
		return 0;
	RtkT::convertCRtk(env, rtk_obj, rtk);
	for (int i = 0; i < n; i++)
	{
		obsd_obj = env->GetObjectArrayElement(obsds, i);
		obsd_t obsdt = ObsdT::convertCObsdT(env, obsd_obj);
		obs[i] = obsdt;
	}
	NavT::convertCNavT(env, nav_obj, global_nav);
	int ret = rtkpos(rtk, obs, n, global_nav);
	RtkT::convertJavaRtk(env, *rtk, rtk_obj);
	return ret;
}

JNIEXPORT void JNICALL Java_rtk_RtkMethod_convrnx
(JNIEnv *env, jobject jobj, jstring rtcmFileName, jstring oFileName, jstring nFileName, jlong gpsTime)
{
	const char* rtcmFileNameStr;
	//rtcmFileNameStr = env->GetStringUTFChars(rtcmFileName, false);
	rtcmFileNameStr = env->GetStringUTFChars(rtcmFileName, 0 );
	
	const char* oFileNameStr;
	//oFileNameStr = env->GetStringUTFChars(oFileName, false);
	oFileNameStr = env->GetStringUTFChars(oFileName, 0);

	const char* nFileNameStr;
	//nFileNameStr = env->GetStringUTFChars(nFileName, false);
	nFileNameStr = env->GetStringUTFChars(nFileName, 0);
	
	

	char* infile_[9] = { /* 前面观测值为移动站,后面观测值为基准站 */
		"E:\\code\\1.obs",
		"E:\\code\\1.nav",
		"",
		"",
		""
		"",
		"",
		"",
		"",
		""
	};
	infile_[0] = (char*)oFileNameStr;
	infile_[1] = (char*)nFileNameStr;
	
	gtime_t gpsNow = { 0 };
	gpsNow.time = gpsTime;
	gpsNow.sec = 0;
	rnxopt->trtcm = gpsNow;
	convrnx(1, rnxopt, rtcmFileNameStr, infile_);

	env->ReleaseStringUTFChars(rtcmFileName, rtcmFileNameStr);
	env->ReleaseStringUTFChars(oFileName, oFileNameStr);
	env->ReleaseStringUTFChars(nFileName, nFileNameStr);
}

JNIEXPORT jint JNICALL Java_rtk_RtkMethod_postpos
(JNIEnv *env, jobject jobj, jstring baseObsFile, jstring roverObsFile, jstring navFile, jstring posFile, jdouble x, jdouble y, jdouble z, jobject opt_obj, jint tint)
{
	const char* baseObsFileStr;
	//baseObsFileStr = env->GetStringUTFChars(baseObsFile, false);
	baseObsFileStr = env->GetStringUTFChars(baseObsFile, 0);
	
	const char* roverObsFileStr;
	//roverObsFileStr = env->GetStringUTFChars(roverObsFile, false);
	roverObsFileStr = env->GetStringUTFChars(roverObsFile, 0);
	
	const char* navFileStr;
	//navFileStr = env->GetStringUTFChars(navFile, false);
	navFileStr = env->GetStringUTFChars(navFile, 0);
	
	const char* posFileStr;
	//posFileStr = env->GetStringUTFChars(posFile, false);
	posFileStr = env->GetStringUTFChars(posFile, 0);

	gtime_t ts = {0,0}, te = { 0,0 }; /* 历元时段始末控制变量 */
	
	solopt_t solopt = solopt_default; /* 默认求解格式设置 */
	filopt_t filopt = { /* 参数文件路径设置 */
		"", /* 卫星天线参数文件 */
		"", /* 接收机天线参数文件 */
		"", /* 测站位置文件 */
		"", /* 扩展大地水准面数据文件 */
		"", /* 电离层数据文件 */
		"", /* DCB数据文件 */
		"", /* 地球自转参数文件 */
		"", /* 海洋潮汐负荷文件 */
	};
	char* infile_[3] = { /* 前面观测值为移动站,后面观测值为基准站 */
		"E:\\code\\1.obs",
		"E:\\code\\1.nav",
		"",
	};
	infile_[0] = (char*)roverObsFileStr;
	infile_[1] = (char*)navFileStr;
	infile_[2] = (char*)baseObsFileStr;

	/* 自定义求解格式 --------------------------------------------------------*/
	solopt.timef = 1;       /* 时间格式(0:sssss.s, 1:yyyy/mm/dd hh:mm:ss.s) */
	solopt.outhead = 0;       /* 是否输出头文件(0:否,1:是) */
	solopt.posf = SOLF_XYZ;  /* 输出的坐标格式 */
	solopt.times = TIMES_UTC; /* 控制输出解的时间系统类型 */
	//solopt.degf  =0;         /* 输出经纬度格式(0:°, 1:°′″) */
	solopt.outopt = 0;         /* 是否输出prcopt变量(0:否,1:是) */
	solopt.height = 1;         /* 高程(0:椭球高,1:大地高) */
	solopt.sstat = 0;         /* 输出求解状态 */
	
	prcopt_t prcopt = PrcoptT::convertCPrcoptT(env, opt_obj);
	prcopt.rb[0] = x;
	prcopt.rb[1] = y;
	prcopt.rb[2] = z;
		
	//long t1 = clock();
	int ret = postpos(ts, te, tint, 0.0, &prcopt, &solopt, &filopt, infile_, 3, (char*)posFileStr, "", "");
	//long t2 = clock();
	//sprintf("\n * The total time for running the program: %6.3f seconds\n%c", (double)(t2 - t1) / CLOCKS_PER_SEC, '\0');

	env->ReleaseStringUTFChars(baseObsFile, baseObsFileStr);
	env->ReleaseStringUTFChars(roverObsFile, roverObsFileStr);
	env->ReleaseStringUTFChars(navFile, navFileStr);
	env->ReleaseStringUTFChars(posFile, posFileStr);
	return ret;
}
