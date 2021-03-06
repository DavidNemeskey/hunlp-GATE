/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.5
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package hu.rilmta.gate.tokenizers.dummyctokenizer;

public class IntArray {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected IntArray(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(IntArray obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        DummyCTokenizerWrapperJNI.delete_IntArray(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public IntArray(int nelements) {
    this(DummyCTokenizerWrapperJNI.new_IntArray(nelements), true);
  }

  public int getitem(int index) {
    return DummyCTokenizerWrapperJNI.IntArray_getitem(swigCPtr, this, index);
  }

  public void setitem(int index, int value) {
    DummyCTokenizerWrapperJNI.IntArray_setitem(swigCPtr, this, index, value);
  }

  public SWIGTYPE_p_int cast() {
    long cPtr = DummyCTokenizerWrapperJNI.IntArray_cast(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_int(cPtr, false);
  }

  public static IntArray frompointer(SWIGTYPE_p_int t) {
    long cPtr = DummyCTokenizerWrapperJNI.IntArray_frompointer(SWIGTYPE_p_int.getCPtr(t));
    return (cPtr == 0) ? null : new IntArray(cPtr, false);
  }

}
