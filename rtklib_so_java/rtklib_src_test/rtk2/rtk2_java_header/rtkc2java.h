#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "rtkjni.h"

extern jobject convertJavaEphT(JNIEnv *env, eph_t epht);

extern jobject convertJavaGephT(JNIEnv *env, geph_t gepht);

extern jobject convertJavaSephT(JNIEnv *env, seph_t sepht);

extern jobject convertJavaPephT(JNIEnv *env, peph_t pepht);

extern jobject convertJavaPclkT(JNIEnv *env, pclk_t pclkt);

extern jobject convertJavaAlmT(JNIEnv *env, alm_t almt);

extern jobject convertJavaTecT(JNIEnv *env, tec_t tect);

extern jobject convertJavaErpT(JNIEnv *env, erp_t erp);

extern jobject convertJavaPcvT(JNIEnv *env, pcv_t pcv);

extern jobject convertJavaSbssatT(JNIEnv *env, sbssat_t sbssat);

extern jobject convertJavaSbsionT(JNIEnv *env, sbsion_t sbsion);

extern jobject convertJavaDgpsT(JNIEnv *env, dgps_t dgps);

extern jobject convertJavaSsrT(JNIEnv *env, ssr_t ssr); 

extern void convertJavaNavT(JNIEnv *env, nav_t nav, jobject j_nav_obj);

extern jobject convertJavaObsdT(JNIEnv *env, obsd_t obsd);

extern void convertJavaObsT(JNIEnv *env, obs_t obs, jobject j_obs_obj);

extern void convertJavaStaT(JNIEnv *env, sta_t sta, jobject sta_obj);

extern void convertJavaRtcmT(JNIEnv *env, jobject rtcm_obj, rtcm_t *rtcm);

