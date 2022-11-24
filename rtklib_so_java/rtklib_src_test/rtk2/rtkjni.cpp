#include "jni/jni.h"
#include "../src/rtklib.h"
#include "rtkjni.h"


const char *getStrParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
	// 获取字段id
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "Ljava/lang/String;");
	// 获取对象的字段
	jstring fieldValue = (jstring)(*env).GetObjectField(paramIn, fieldID);
	// 将jstring转char *
	const char *charValue = (*env).GetStringUTFChars(fieldValue, 0);

	(*env).ReleaseStringUTFChars(fieldValue, charValue);
	(*env).DeleteLocalRef(fieldValue);
	return charValue;
}

//env,参数字段名
void setStrParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, const char * value)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "Ljava/lang/String;");
	jstring str = env->NewStringUTF(value);
	(*env).SetObjectField(paramIn, fieldID, str);
}

int getIntParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
	// 获取字段id
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "I");
	// 获取对象的字段值
	jint fieldValue = (int)(*env).GetIntField(paramIn, fieldID);
	// 将jint转int
	int value = (int)fieldValue;
	return value;
}

void setIntParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int value)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "I");
	(*env).SetIntField(paramIn, fieldID, value);
}

//__int64 getLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
__int64_t getLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
	// 获取字段id
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "J");
	// 获取对象的字段值
	jlong fieldValue = (*env).GetLongField(paramIn, fieldID);
	
	// 将jint转int
	//__int64 value = (__int64)fieldValue;
	__int64_t value = (__int64_t)fieldValue;
	
	return value;
}

//void setLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, __int64 value)
void setLongParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, __int64_t value)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "J");
	(*env).SetLongField(paramIn, fieldID, value);
}

double getDoubleParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
	// 获取字段id
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "D");
	// 获取对象的字段值
	jdouble fieldValue = (*env).GetDoubleField(paramIn, fieldID);
	// 将jint转int
	double value = (double)fieldValue;
	return value;
}

void setDoubleParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double value)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "D");
	(*env).SetDoubleField(paramIn, fieldID, value);
}

float getFloatParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param) {
	// 获取字段id
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "F");
	// 获取对象的字段值
	jfloat fieldValue = (*env).GetFloatField(paramIn, fieldID);
	// 将jint转int
	float value = (float)fieldValue;
	return value;
}

void setFloatParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float value)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "F");
	(*env).SetFloatField(paramIn, fieldID, value);
}

void getIntArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (jintArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jint* jintarray = (jint*)malloc(sizeof(jint)*size);
	(*env).GetIntArrayRegion(jarray, 0, size, jintarray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jintarray[i];
	}
	free(jintarray);
	env->DeleteLocalRef(jarray);
	return;
}


void setIntArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);

	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getInt32ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (jintArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jint* jintarray = (jint*)malloc(sizeof(jint)*size);
	(*env).GetIntArrayRegion(jarray, 0, size, jintarray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jintarray[i];
	}
	env->DeleteLocalRef(jarray);
	free(jintarray);
	env->DeleteLocalRef(jarray);
	return;
}

void setInt32ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getInt16ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (jintArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jint* jintarray = (jint*)malloc(sizeof(jint)*size);
	(*env).GetIntArrayRegion(jarray, 0, size, jintarray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jintarray[i];
	}
	env->DeleteLocalRef(jarray);
	free(jintarray);
	env->DeleteLocalRef(jarray);
	return;
}

void setInt16ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getInt8ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (jintArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jint* jintarray = (jint*)malloc(sizeof(jint)*size);
	(*env).GetIntArrayRegion(jarray, 0, size, jintarray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jintarray[i];
	}
	free(jintarray);
	env->DeleteLocalRef(jarray);
	return;
}

void setInt8ArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[I");
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getDoubleArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[D");
	jdoubleArray jarray = (jdoubleArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdouble* jdoublearray = (jdouble*)malloc(sizeof(jdouble)*size);
	(*env).GetDoubleArrayRegion(jarray, 0, size, jdoublearray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jdoublearray[i];
	}
	free(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void setDoubleArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double * buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[D");
	jdoubleArray jarray = (*env).NewDoubleArray(size);
	jdouble* jarray2 = (jdouble*)malloc(sizeof(jdouble)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetDoubleArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getCharArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[C");
	jcharArray jarray = (jcharArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jchar* jchararray = (jchar*)malloc(sizeof(jchar)*size);
	(*env).GetCharArrayRegion(jarray, 0, size, jchararray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jchararray[i];
	}
	env->DeleteLocalRef(jarray);
	free(jchararray);
	return;
}
void setCharArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char * buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[C");
	jcharArray jarray = (*env).NewCharArray(size);
	jchar* jarray2 = (jchar*)malloc(sizeof(jchar)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetCharArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

jobject convertJavaGtimeT(JNIEnv *env, gtime_t gtime)
{
	jclass j_gtime = (*env).FindClass("rtk/model/GtimeT");
	jmethodID jmethodID = (*env).GetMethodID(j_gtime, "<init>", "()V");
	jobject obj = (*env).NewObjectA(j_gtime, jmethodID, 0);
	setLongParam(env, j_gtime, obj, "time", gtime.time);
	setDoubleParam(env, j_gtime, obj, "sec", gtime.sec);
	env->DeleteLocalRef(j_gtime);
	return obj;

}

gtime_t convertCGtimeT(JNIEnv *env, jobject gtime_obj)
{
	gtime_t gtime = { 0 };
	if (gtime_obj != NULL)
	{
		jclass j_gtime = (*env).FindClass("rtk/model/GtimeT");
		jfieldID time_field_id = (*env).GetFieldID(j_gtime, "time", "J");
		jfieldID sec_field_id = (*env).GetFieldID(j_gtime, "sec", "D");
		gtime.time = getLongParam(env, j_gtime, gtime_obj, "time");
		gtime.sec = getDoubleParam(env, j_gtime, gtime_obj, "sec");
		env->DeleteLocalRef(gtime_obj);
		env->DeleteLocalRef(j_gtime);
	}
	
	return gtime;

}
gtime_t getGtime(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "Lrtk/model/GtimeT;");
	jobject gtime_obj = (*env).GetObjectField(paramIn, fieldID);
	return convertCGtimeT(env, gtime_obj);
}

void setGtime(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t value)
{
	jclass j_gtime = (*env).FindClass("rtk/model/GtimeT");
	jmethodID j_gtime_methodID = (*env).GetMethodID(j_gtime, "<init>", "()V");
	jobject j_gtime_obj = (*env).NewObjectA(j_gtime, j_gtime_methodID, 0);
	jfieldID time_field_id = (*env).GetFieldID(j_gtime, "time", "J");
	jfieldID sec_field_id = (*env).GetFieldID(j_gtime, "sec", "D");
	(*env).SetLongField(j_gtime_obj, time_field_id, value.time);
	(*env).SetDoubleField(j_gtime_obj, sec_field_id, value.sec);
	jfieldID obsd_time_field_id = (*env).GetFieldID(paramInClass, param, "Lrtk/model/GtimeT;");
	(*env).SetObjectField(paramIn, obsd_time_field_id, j_gtime_obj);
	env->DeleteLocalRef(j_gtime);
}

void getDoubleArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 3; j++)
		{
			buf[i][j] = testP[j];
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][4])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 4; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][1])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 1; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam24(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < NFREQ; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 3; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}


void getDoubleArrayParam25(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][19])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < NFREQ; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 19; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam26(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][9])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < NFREQ; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 9; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam27(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < 2; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 3; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam28(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][66])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < 2; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < 66; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getDoubleArrayParam29(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][NFREQ])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < 2; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < NFREQ; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

// 获取java 中三维数组的值
void getDoubleArrayParam31(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXRCV][2][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jobjectArray jarray2;
	jdoubleArray jarray3;
	for (int i = 0; i < MAXRCV; i++)
	{
		jarray2 = (jobjectArray)(*env).GetObjectArrayElement(jarray, i);
		for (int j = 0; j < 2; j++)
		{
			jarray3 = (jdoubleArray)(*env).GetObjectArrayElement(jarray, j);
			jdouble *testP = (*env).GetDoubleArrayElements(jarray3, NULL);
			for (int k = 0; k < 3; k++)
			{
				buf[i][j][k] = *(testP + k);
			}
			env->ReleaseDoubleArrayElements(jarray3, testP, 0);
		}
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jarray2);
	env->DeleteLocalRef(jarray3);
	return;
}


void getFloatArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[F");
	jfloatArray jarray = (jfloatArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jfloat* jfloatarray = (jfloat*)malloc(sizeof(jfloat)*size);
	(*env).GetFloatArrayRegion(jarray, 0, size, jfloatarray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jfloatarray[i];
	}
	free(jfloatarray);
	env->DeleteLocalRef(jarray);
	return;
}

void setFloatArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float * buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[F");
	jfloatArray jarray = (*env).NewFloatArray(size);
	jfloat* jarray2 = (jfloat*)malloc(sizeof(jfloat)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetFloatArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void getFloatArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][4])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jfloatArray jfloatarray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jfloatarray = (jfloatArray)(*env).GetObjectArrayElement(jarray, i);
		jfloat *testP = (*env).GetFloatArrayElements(jfloatarray, NULL);
		for (int j = 0; j < 4; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseFloatArrayElements(jfloatarray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jfloatarray);
	return;
}

void getFloatArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jfloatArray jfloatarray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jfloatarray = (jfloatArray)(*env).GetObjectArrayElement(jarray, i);
		jfloat *testP = (*env).GetFloatArrayElements(jfloatarray, NULL);
		for (int j = 0; j < 3; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseFloatArrayElements(jfloatarray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jfloatarray);
	return;
}

void getFloatArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][1])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jfloatArray jfloatarray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jfloatarray = (jfloatArray)(*env).GetObjectArrayElement(jarray, i);
		jfloat *testP = (*env).GetFloatArrayElements(jfloatarray, NULL);
		for (int j = 0; j < 1; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseFloatArrayElements(jfloatarray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jfloatarray);
	return;
}


void setDoubleArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)*3);
	for (int i = 0; i < MAXSAT; i++){
		jdoubleArray colArr = env->NewDoubleArray(3);
		for (int j = 0; j < 3; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, 3, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void setDoubleArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][4])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* 4);
	for (int i = 0; i < MAXSAT; i++){
		jdoubleArray colArr = env->NewDoubleArray(4);
		for (int j = 0; j < 4; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, 4, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void setDoubleArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][1])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");

	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* 1);
	for (int i = 0; i < MAXSAT; i++){
		jdoubleArray colArr = env->NewDoubleArray(1);
		for (int j = 0; j < 1; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, 1, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void setDoubleArrayParam24(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");

	//jobjArr = env->NewObjectArray(NFREQ, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(NFREQ, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* 3);
	for (int i = 0; i < NFREQ; i++){
		jdoubleArray colArr = env->NewDoubleArray(3);
		for (int j = 0; j < 3; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, 3, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void setDoubleArrayParam25(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[NFREQ][19])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(NFREQ, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(NFREQ, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* 19);
	for (int i = 0; i < NFREQ; i++){
		jdoubleArray colArr = env->NewDoubleArray(19);
		for (int j = 0; j < 19; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, 19, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}


void setDoubleArrayParam29(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[2][NFREQ])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(2, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(2, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* NFREQ);
	for (int i = 0; i < 2; i++){
		jdoubleArray colArr = env->NewDoubleArray(NFREQ);
		for (int j = 0; j < NFREQ; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, NFREQ, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void setFloatArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][4])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[F");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jfloat* temp = (jfloat*)malloc(sizeof(jfloat)*4);
	for (int i = 0; i < MAXSAT; i++){
		jfloatArray colArr = env->NewFloatArray(4);
		for (int j = 0; j < 4; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetFloatArrayRegion(colArr, 0, 4, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);

	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);

	return;
}

void setFloatArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[F");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jfloat* temp = (jfloat*)malloc(sizeof(jfloat)* 3);
	for (int i = 0; i < MAXSAT; i++){
		jfloatArray colArr = env->NewFloatArray(3);
		for (int j = 0; j < 3; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetFloatArrayRegion(colArr, 0, 3, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);

	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);

	return;
}

void setFloatArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, float buf[MAXSAT][1])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[F");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[F");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jfloat* temp = (jfloat*)malloc(sizeof(jfloat)* 1);
	for (int i = 0; i < MAXSAT; i++){
		jfloatArray colArr = env->NewFloatArray(1);
		for (int j = 0; j < 1; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetFloatArrayRegion(colArr, 0, 1, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);

	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);

	return;
}

void setDoubleArrayParam31(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXRCV][2][3])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[[D");

	jclass doubleArr2 = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(MAXRCV, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXRCV, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)*3);
	for (int i = 0; i < MAXRCV; i++){
		//jobjectArray jobjArr2 = env->NewObjectArray(2, doubleArr2, nullptr);
		jobjectArray jobjArr2 = env->NewObjectArray(2, doubleArr2, NULL);
		
		for (int j = 0; j < 2; j++)
		{
			jdoubleArray colArr = env->NewDoubleArray(3);
			for (int k = 0; k < 3; k++)
			{
				temp[k] = buf[i][j][k];
			}
			env->SetDoubleArrayRegion(colArr, 0, 3, temp);
			env->SetObjectArrayElement(jobjArr2, j, colArr);
			env->DeleteLocalRef(colArr);
		}
		env->SetObjectArrayElement(jobjArr, i, jobjArr2);
		env->DeleteLocalRef(jobjArr2);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	env->DeleteLocalRef(doubleArr2);
	free(temp);
	return;
}

void getCharArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[2][MAXANT])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[C");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jcharArray jchararray;
	for (int i = 0; i < 2; i++)
	{
		jchararray = (jcharArray)(*env).GetObjectArrayElement(jarray, i);
		jchar *testP = (*env).GetCharArrayElements(jchararray, NULL);
		for (int j = 0; j < MAXANT; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseCharArrayElements(jchararray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jchararray);
	return;
}

void getCharArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[2][256])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[C");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jcharArray jchararray;
	for (int i = 0; i < 2; i++)
	{
		jchararray = (jcharArray)(*env).GetObjectArrayElement(jarray, i);
		jchar *testP = (*env).GetCharArrayElements(jchararray, NULL);
		for (int j = 0; j < 256; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseCharArrayElements(jchararray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jchararray);
	return;
}

void getCharArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[7][128])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[C");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jcharArray jchararray;
	for (int i = 0; i < 7; i++)
	{
		jchararray = (jcharArray)(*env).GetObjectArrayElement(jarray, i);
		jchar *testP = (*env).GetCharArrayElements(jchararray, NULL);
		for (int j = 0; j < 128; j++)
		{
			buf[i][j] = *(testP + j);
		}
		env->ReleaseCharArrayElements(jchararray, testP, 0);
	}
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(jchararray);
	return;
}

void setCharArrayParam23(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, char buf[7][128])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[C");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[C");
	
	//jobjArr = env->NewObjectArray(7, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(7, doubleArr, NULL);
	
	jchar* temp = (jchar*)malloc(sizeof(jchar)* 128);
	for (int i = 0; i < 7; i++){
		jcharArray colArr = env->NewCharArray(128);
		for (int j = 0; j < 128; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetCharArrayRegion(colArr, 0, 128, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);

	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);

	return;
}


void getGtimeArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[2][NFREQ])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[Lrtk/model/GtimeT;");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jobjectArray jarray2;
	for (int i = 0; i < 2; i++)
	{
		jarray2 = (jobjectArray)(*env).GetObjectArrayElement(jarray, i);
		for (int j = 0; j < NFREQ; j++)
		{
			jobject time_obj = (*env).GetObjectArrayElement(jarray2, j);
			gtime_t time = convertCGtimeT(env, time_obj);
			buf[i][j].sec = time.sec;
			buf[i][j].time = time.time;
		}
	}
	env->DeleteLocalRef(jarray2);
	env->DeleteLocalRef(jarray);
	return;
}


void setGtimeArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[2][NFREQ])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[Lrtk/model/GtimeT;");
	jclass j_time = env->FindClass("rtk/model/GtimeT");
	jfieldID time_field_id = (*env).GetFieldID(j_time, "time", "J");
	jfieldID sec_field_id = (*env).GetFieldID(j_time, "sec", "D");

	jclass doubleArr = env->FindClass("[Lrtk/model/GtimeT;");
	
	jobjectArray jobjArr;
	jobjectArray colArr = env->NewObjectArray(2, doubleArr, NULL);
	jmethodID jmethodID = (*env).GetMethodID(j_time, "<init>", "()V");

	for (int i = 0; i < 2; i++){
		jobjArr = env->NewObjectArray(NFREQ, j_time, NULL);
		for (int j = 0; j < NFREQ; j++)
		{
			jobject time_obj = (*env).NewObjectA(j_time, jmethodID, 0);
			env->SetDoubleField(time_obj, sec_field_id, buf[i][j].sec);
			env->SetLongField(time_obj, time_field_id, buf[i][j].time);
			env->SetObjectArrayElement(jobjArr, j, time_obj);
		}	
		env->SetObjectArrayElement(colArr, i, jobjArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(colArr);
	env->DeleteLocalRef(doubleArr);
	env->DeleteLocalRef(j_time);
	return;
}

void setGtimeArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, gtime_t * buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[Lrtk/model/GtimeT;");
	jclass j_time = env->FindClass("rtk/model/GtimeT");
	jfieldID time_field_id = (*env).GetFieldID(j_time, "time", "J");
	jfieldID sec_field_id = (*env).GetFieldID(j_time, "sec", "D");
	jmethodID jmethodID = (*env).GetMethodID(j_time, "<init>", "()V");

	jobjectArray jarray = env->NewObjectArray(size, j_time, NULL);
	for (int i = 0; i < size; i++){
		jobject time_obj = (*env).NewObjectA(j_time, jmethodID, 0);
		env->SetDoubleField(time_obj, sec_field_id, buf[i].sec);
		env->SetLongField(time_obj, time_field_id, buf[i].time);
		env->SetObjectArrayElement(jarray, i, time_obj);
	}
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	env->DeleteLocalRef(j_time);
	return;
}

void getGtimeArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, gtime_t* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[Lrtk/model/GtimeT;");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	jclass j_time = env->FindClass("rtk/model/GtimeT");

	if (jarray == NULL)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		jobject time_obj = env->GetObjectArrayElement(jarray, i);
		double sec = getDoubleParam(env, j_time, time_obj, "sec");
		
		//__int64 time = getLongParam(env, j_time, time_obj, "time");
		__int64_t time = getLongParam(env, j_time, time_obj, "time");
		
		buf[i].sec = sec;
		buf[i].time = time;
	}
	env->DeleteLocalRef(j_time);
	env->DeleteLocalRef(jarray);
	return;
}

void setDoubleArrayParam210(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[D");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jdouble* temp = (jdouble*)malloc(sizeof(jdouble)* NFREQ + NEXOBS);
	for (int i = 0; i < MAXSAT; i++){
		jdoubleArray colArr = env->NewDoubleArray(NFREQ + NEXOBS);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetDoubleArrayRegion(colArr, 0, NFREQ + NEXOBS, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void getDoubleArrayParam210(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, double buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[D");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jdoubleArray jdoublearray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jdoublearray = (jdoubleArray)(*env).GetObjectArrayElement(jarray, i);
		jdouble *testP = (*env).GetDoubleArrayElements(jdoublearray, NULL);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			double temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseDoubleArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}


void setInt16ArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, uint16_t buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[I");
	jobjectArray jobjArr;
	jclass doubleArr = env->FindClass("[I");
	
	//jobjArr = env->NewObjectArray(MAXSAT, doubleArr, nullptr);
	jobjArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	
	jint* temp = (jint*)malloc(sizeof(jint)* NFREQ + NEXOBS);
	for (int i = 0; i < MAXSAT; i++){
		jintArray colArr = env->NewIntArray(NFREQ + NEXOBS);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			temp[j] = buf[i][j];
		}
		env->SetIntArrayRegion(colArr, 0, NFREQ + NEXOBS, temp);
		env->SetObjectArrayElement(jobjArr, i, colArr);
		env->DeleteLocalRef(colArr);
	}

	(*env).SetObjectField(paramIn, fieldID, jobjArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(doubleArr);
	free(temp);
	return;
}

void getInt16ArrayParam21(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, uint16_t buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[I");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jintArray jdoublearray;
	for (int i = 0; i < MAXSAT; i++)
	{
		jdoublearray = (jintArray)(*env).GetObjectArrayElement(jarray, i);
		jint *testP = (*env).GetIntArrayElements(jdoublearray, NULL);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			int temp = testP[j];
			buf[i][j] = temp;
		}
		env->ReleaseIntArrayElements(jdoublearray, testP, 0);
	}
	env->DeleteLocalRef(jdoublearray);
	env->DeleteLocalRef(jarray);
	return;
}

void getGtimeArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[Lrtk/model/GtimeT;");
	jobjectArray jarray = (jobjectArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jobjectArray jarray2;
	for (int i = 0; i < MAXSAT; i++)
	{
		jarray2 = (jobjectArray)(*env).GetObjectArrayElement(jarray, i);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			jobject time_obj = (*env).GetObjectArrayElement(jarray2, j);
			gtime_t time = convertCGtimeT(env, time_obj);
			buf[i][j].sec = time.sec;
			buf[i][j].time = time.time;
		}
	}
	env->DeleteLocalRef(jarray2);
	env->DeleteLocalRef(jarray);
	return;
}


void setGtimeArrayParam22(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, gtime_t buf[MAXSAT][NFREQ + NEXOBS])
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[[Lrtk/model/GtimeT;");
	jclass j_time = env->FindClass("rtk/model/GtimeT");
	jfieldID time_field_id = (*env).GetFieldID(j_time, "time", "J");
	jfieldID sec_field_id = (*env).GetFieldID(j_time, "sec", "D");

	jclass doubleArr = env->FindClass("[Lrtk/model/GtimeT;");

	jobjectArray jobjArr;
	jobjectArray colArr = env->NewObjectArray(MAXSAT, doubleArr, NULL);
	jmethodID jmethodID = (*env).GetMethodID(j_time, "<init>", "()V");

	for (int i = 0; i < MAXSAT; i++){
		jobjArr = env->NewObjectArray(NFREQ + NEXOBS, j_time, NULL);
		for (int j = 0; j < NFREQ + NEXOBS; j++)
		{
			jobject time_obj = (*env).NewObjectA(j_time, jmethodID, 0);
			
			env->SetDoubleField(time_obj, sec_field_id, buf[i][j].sec);
			env->SetLongField(time_obj, time_field_id, buf[i][j].time);
			env->SetObjectArrayElement(jobjArr, j, time_obj);
			
		}
		env->SetObjectArrayElement(colArr, i, jobjArr);
	}

	(*env).SetObjectField(paramIn, fieldID, colArr);
	env->DeleteLocalRef(jobjArr);
	env->DeleteLocalRef(colArr);
	env->DeleteLocalRef(doubleArr);
	env->DeleteLocalRef(j_time);
	return;
}

void getByteArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf)
{
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[B");
	jbyteArray jarray = (jbyteArray)(*env).GetObjectField(paramIn, fieldID);
	if (jarray == NULL)
	{
		return;
	}
	jbyte* jchararray = (jbyte*)malloc(sizeof(jbyte)*size);
	(*env).GetByteArrayRegion(jarray, 0, size, jchararray);
	for (int i = 0; i < size; i++)
	{
		buf[i] = jchararray[i];
	}
	env->DeleteLocalRef(jarray);
	free(jchararray);
	return;
}
void setByteArrayParam(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t * buf)
{
	if (size == 0)
		return;
	jfieldID fieldID = (*env).GetFieldID(paramInClass, param, "[B");
	jbyteArray jarray = (*env).NewByteArray(size);
	jbyte* jarray2 = (jbyte*)malloc(sizeof(jbyte)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetByteArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}



void setInt16Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint16_t* buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setInt8Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint8_t* buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setInt32Array(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, uint32_t* buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jlongArray jarray = (*env).NewLongArray(size);
	jlong* jarray2 = (jlong*)malloc(sizeof(jlong)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetLongArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setDoubleArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, double * buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jdoubleArray jarray = (*env).NewDoubleArray(size);
	jdouble* jarray2 = (jdouble*)malloc(sizeof(jdouble)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetDoubleArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setFloatArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, float * buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jfloatArray jarray = (*env).NewFloatArray(size);
	jfloat* jarray2 = (jfloat*)malloc(sizeof(jfloat)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetFloatArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setIntArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, int* buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jintArray jarray = (*env).NewIntArray(size);
	jint* jarray2 = (jint*)malloc(sizeof(jint)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetIntArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}

void setCharArray(JNIEnv *env, jclass paramInClass, jobject paramIn, char *param, int size, char* buf, jfieldID fieldID)
{
	if (size == 0)
		return;
	jcharArray jarray = (*env).NewCharArray(size);
	jchar* jarray2 = (jchar*)malloc(sizeof(jchar)*size);
	for (int i = 0; i < size; i++){
		jarray2[i] = buf[i];
	}
	env->SetCharArrayRegion(jarray, 0, size, jarray2);
	(*env).SetObjectField(paramIn, fieldID, jarray);
	env->DeleteLocalRef(jarray);
	free(jarray2);
	return;
}
