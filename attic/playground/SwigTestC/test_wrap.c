/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.5
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


/* Includes the header in the wrapper code */
#include "test.h"


typedef long longArray;

SWIGINTERN longArray *new_longArray(int nelements){
  return (long *) calloc(nelements,sizeof(long));
}
SWIGINTERN void delete_longArray(longArray *self){
  free(self);
}
SWIGINTERN long longArray_getitem(longArray *self,int index){
  return self[index];
}
SWIGINTERN void longArray_setitem(longArray *self,int index,long value){
  self[index] = value;
}
SWIGINTERN long *longArray_cast(longArray *self){
  return self;
}
SWIGINTERN longArray *longArray_frompointer(long *t){
  return (longArray *) t;
}

typedef OffsPair OffsPairArray;

SWIGINTERN OffsPairArray *new_OffsPairArray(int nelements){
  return (OffsPair *) calloc(nelements,sizeof(OffsPair));
}
SWIGINTERN void delete_OffsPairArray(OffsPairArray *self){
  free(self);
}
SWIGINTERN OffsPair OffsPairArray_getitem(OffsPairArray *self,int index){
  return self[index];
}
SWIGINTERN void OffsPairArray_setitem(OffsPairArray *self,int index,OffsPair value){
  self[index] = value;
}
SWIGINTERN OffsPair *OffsPairArray_cast(OffsPairArray *self){
  return self;
}
SWIGINTERN OffsPairArray *OffsPairArray_frompointer(OffsPair *t){
  return (OffsPairArray *) t;
}

#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_TestJNI_new_1longArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  longArray *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (longArray *)new_longArray(arg1);
  *(longArray **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_delete_1longArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  longArray *arg1 = (longArray *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(longArray **)&jarg1; 
  delete_longArray(arg1);
}


SWIGEXPORT jint JNICALL Java_TestJNI_longArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  jint jresult = 0 ;
  longArray *arg1 = (longArray *) 0 ;
  int arg2 ;
  long result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(longArray **)&jarg1; 
  arg2 = (int)jarg2; 
  result = (long)longArray_getitem(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_longArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3) {
  longArray *arg1 = (longArray *) 0 ;
  int arg2 ;
  long arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(longArray **)&jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (long)jarg3; 
  longArray_setitem(arg1,arg2,arg3);
}


SWIGEXPORT jlong JNICALL Java_TestJNI_longArray_1cast(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  longArray *arg1 = (longArray *) 0 ;
  long *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(longArray **)&jarg1; 
  result = (long *)longArray_cast(arg1);
  *(long **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_TestJNI_longArray_1frompointer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  long *arg1 = (long *) 0 ;
  longArray *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(long **)&jarg1; 
  result = (longArray *)longArray_frompointer(arg1);
  *(longArray **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_TestJNI_new_1OffsPairArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  OffsPairArray *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (OffsPairArray *)new_OffsPairArray(arg1);
  *(OffsPairArray **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_delete_1OffsPairArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  OffsPairArray *arg1 = (OffsPairArray *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(OffsPairArray **)&jarg1; 
  delete_OffsPairArray(arg1);
}


SWIGEXPORT jlong JNICALL Java_TestJNI_OffsPairArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  jlong jresult = 0 ;
  OffsPairArray *arg1 = (OffsPairArray *) 0 ;
  int arg2 ;
  OffsPair result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPairArray **)&jarg1; 
  arg2 = (int)jarg2; 
  result = OffsPairArray_getitem(arg1,arg2);
  {
    OffsPair * resultptr = (OffsPair *) malloc(sizeof(OffsPair));
    memmove(resultptr, &result, sizeof(OffsPair));
    *(OffsPair **)&jresult = resultptr;
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_OffsPairArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_) {
  OffsPairArray *arg1 = (OffsPairArray *) 0 ;
  int arg2 ;
  OffsPair arg3 ;
  OffsPair *argp3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  arg1 = *(OffsPairArray **)&jarg1; 
  arg2 = (int)jarg2; 
  argp3 = *(OffsPair **)&jarg3; 
  if (!argp3) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null OffsPair");
    return ;
  }
  arg3 = *argp3; 
  OffsPairArray_setitem(arg1,arg2,arg3);
}


SWIGEXPORT jlong JNICALL Java_TestJNI_OffsPairArray_1cast(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  OffsPairArray *arg1 = (OffsPairArray *) 0 ;
  OffsPair *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPairArray **)&jarg1; 
  result = (OffsPair *)OffsPairArray_cast(arg1);
  *(OffsPair **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_TestJNI_OffsPairArray_1frompointer(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  OffsPair *arg1 = (OffsPair *) 0 ;
  OffsPairArray *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  result = (OffsPairArray *)OffsPairArray_frompointer(arg1);
  *(OffsPairArray **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_doit(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg1, 0);
    if (!arg1) return ;
  }
  doit((char const *)arg1);
  if (arg1) (*jenv)->ReleaseStringUTFChars(jenv, jarg1, (const char *)arg1);
}


SWIGEXPORT jint JNICALL Java_TestJNI_doit2(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  long *arg1 = (long *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(long **)&jarg1; 
  result = (int)doit2(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_OffsPair_1start_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  OffsPair *arg1 = (OffsPair *) 0 ;
  long arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  arg2 = (long)jarg2; 
  if (arg1) (arg1)->start = arg2;
}


SWIGEXPORT jint JNICALL Java_TestJNI_OffsPair_1start_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  OffsPair *arg1 = (OffsPair *) 0 ;
  long result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  result = (long) ((arg1)->start);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_OffsPair_1end_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  OffsPair *arg1 = (OffsPair *) 0 ;
  long arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  arg2 = (long)jarg2; 
  if (arg1) (arg1)->end = arg2;
}


SWIGEXPORT jint JNICALL Java_TestJNI_OffsPair_1end_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  OffsPair *arg1 = (OffsPair *) 0 ;
  long result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  result = (long) ((arg1)->end);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_TestJNI_new_1OffsPair(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  OffsPair *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (OffsPair *)calloc(1, sizeof(OffsPair));
  *(OffsPair **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_delete_1OffsPair(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  OffsPair *arg1 = (OffsPair *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(OffsPair **)&jarg1; 
  free((char *) arg1);
}


SWIGEXPORT jint JNICALL Java_TestJNI_doit3(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  OffsPair *arg1 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(OffsPair **)&jarg1; 
  result = (int)doit3(arg1);
  jresult = (jint)result; 
  
  return jresult;
}


SWIGEXPORT void JNICALL Java_TestJNI_doit4(JNIEnv *jenv, jclass jcls, jintArray jarg1) {
  int *arg1 = (int *) 0 ;
  int temp1 ;
  
  (void)jenv;
  (void)jcls;
  {
    if (!jarg1) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return ;
    }
    if ((*jenv)->GetArrayLength(jenv, jarg1) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return ;
    }
    temp1 = (int)0;
    arg1 = &temp1; 
  }
  doit4(arg1);
  {
    jint jvalue = (jint)temp1;
    (*jenv)->SetIntArrayRegion(jenv, jarg1, 0, 1, &jvalue);
  }
  
}


#ifdef __cplusplus
}
#endif

