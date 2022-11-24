#include "../jni/jni.h"
#include "../../src/rtklib.h"
#include <stdint.h>

extern const char *getStrParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern void setStrParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, const char * value);
extern int getIntParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern void setIntParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int value);

//extern __int64 getLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern __int64_t getLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);

//extern void setLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, __int64 value);
extern void setLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, __int64_t value);

extern double getDoubleParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern void setDoubleParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double value);
extern float getFloatParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern void setFloatParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float value);
extern void getIntArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf);
extern void setIntArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf);
extern void getInt16ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf);
extern void setInt16ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf);
extern void getInt32ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf);
extern void setInt32ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf);

extern void getInt8ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf);
extern void setInt8ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf);
extern void getDoubleArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double* buf);
extern void setDoubleArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double * buf);
extern void getCharArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char* buf);
extern void setCharArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char * buf);
extern gtime_t convertCGtimeT(JNIEnv *env, jobject gtime_obj);
extern jobject convertJavaGtimeT(JNIEnv *env, gtime_t gtime);
extern gtime_t getGtime(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param);
extern void setGtime(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t value);
extern void getFloatArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float* buf);
extern void setFloatArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float * buf);

extern void getDoubleArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][3]);
extern void getDoubleArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][4]);
extern void getDoubleArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][1]);
extern void getDoubleArrayParam24(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][3]);
extern void getDoubleArrayParam25(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][19]);
extern void getDoubleArrayParam26(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][9]);
extern void getDoubleArrayParam27(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][3]);
extern void getDoubleArrayParam28(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][66]);
extern void getDoubleArrayParam29(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][NFREQ]);

extern void getDoubleArrayParam31(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXRCV][2][3]);

extern void getFloatArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][4]);
extern void getFloatArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][3]);
extern void getFloatArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][1]);

extern void setDoubleArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][3]);
extern void setDoubleArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][4]);
extern void setDoubleArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][1]);
extern void setDoubleArrayParam24(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][3]);
extern void setDoubleArrayParam25(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][19]);

extern void setDoubleArrayParam29(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][NFREQ]);

extern void getDoubleArrayParam210(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][NFREQ + NEXOBS]);
extern void setDoubleArrayParam210(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][NFREQ + NEXOBS]);
//extern void setDoubleArrayParam27(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][3]);
//extern void setDoubleArrayParam28(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][66]);

extern void setDoubleArrayParam31(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXRCV][2][3]);

extern void setFloatArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][4]);
extern void setFloatArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][3]);
extern void setFloatArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][1]);

extern void getCharArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[2][MAXANT]);
extern void getCharArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[2][256]);

extern void getGtimeArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[2][NFREQ]);
extern void setGtimeArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[2][NFREQ]);

extern void getGtimeArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, gtime_t* buf);
extern void setGtimeArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, gtime_t * buf);

extern void getCharArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[7][128]);
extern void setCharArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[7][128]);

extern void setInt16ArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, uint16_t buf[MAXSAT][NFREQ + NEXOBS]);
extern void getInt16ArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, uint16_t buf[MAXSAT][NFREQ + NEXOBS]);

extern void getGtimeArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[MAXSAT][NFREQ + NEXOBS]);
extern void setGtimeArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[MAXSAT][NFREQ + NEXOBS]);

extern void getByteArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf);
extern void setByteArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf);

extern void setInt16Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf, jfieldID fieldID);
extern void setInt8Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf, jfieldID fieldID);
extern void setDoubleArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double * buf, jfieldID fieldID);
extern void setFloatArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float * buf, jfieldID fieldID);
extern void setIntArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf, jfieldID fieldID);
extern void setInt32Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf, jfieldID fieldID);
extern void setCharArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char* buf, jfieldID fieldID);
