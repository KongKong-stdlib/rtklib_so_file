#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include "rtkjni.h"
extern obsd_t convertCObsd(JNIEnv *env, jobject j_obsd_obj);

//传参过来的java obs赋值给obs
extern void convertCObsT(JNIEnv *env, obs_t *obs, jobject j_obs_obj);

extern eph_t convertCEphT(JNIEnv *env, jobject epht_obj);


extern geph_t convertCGephT(JNIEnv *env, jobject gepht_obj);



extern seph_t convertCSephT(JNIEnv *env, jobject sepht_obj);


extern peph_t convertCPephT(JNIEnv *env, jobject pepht_obj);


extern pclk_t convertCPclkT(JNIEnv *env, jobject pclk_obj);


extern alm_t convertCAlmT(JNIEnv *env, jobject alm_obj);


extern tec_t convertCTecT(JNIEnv *env, jobject tec_obj);


extern erpd_t convertCErpdT(JNIEnv *env, jobject erpd_obj);



extern erp_t convertCErpT(JNIEnv *env, jobject erp_obj);



extern pcv_t convertCPcvT(JNIEnv *env, jobject pcv_obj);

extern sbsfcorr_t convertCSbsfcorrT(JNIEnv *env, jobject obj);


extern sbssatp_t convertCSbssatpT(JNIEnv *env, jobject obj);

extern sbssat_t convertCSbssatT(JNIEnv *env, jobject obj);

extern sbsigp_t convertCSbsigpT(JNIEnv *env, jobject obj);
extern sbsion_t convertCSbsionT(JNIEnv *env, jobject obj);


extern dgps_t convertCDgpsT(JNIEnv *env, jobject obj);

extern ssr_t convertCSsrT(JNIEnv *env, jobject obj);


//给nav_t结构体赋值
extern void convertCNavT(JNIEnv *env, jobject navt_obj, nav_t *navt);

extern void convertCPrcoptT(JNIEnv *env, jobject prcopt_obj, prcopt_t *prcopt);

extern void convertCRtcmT(JNIEnv *env, jobject rtcm_obj, rtcm_t *rtcm);

extern rtk_t convertCRtkT(JNIEnv *env, jobject rtk_obj);
