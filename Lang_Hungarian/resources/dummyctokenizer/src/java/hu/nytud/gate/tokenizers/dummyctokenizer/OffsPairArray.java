/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.5
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package hu.nytud.gate.tokenizers.dummyctokenizer;

public class OffsPairArray {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected OffsPairArray(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(OffsPairArray obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        DummyCTokenizerWrapperJNI.delete_OffsPairArray(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public OffsPairArray(int nelements) {
    this(DummyCTokenizerWrapperJNI.new_OffsPairArray(nelements), true);
  }

  public OffsPair getitem(int index) {
    return new OffsPair(DummyCTokenizerWrapperJNI.OffsPairArray_getitem(swigCPtr, this, index), true);
  }

  public void setitem(int index, OffsPair value) {
    DummyCTokenizerWrapperJNI.OffsPairArray_setitem(swigCPtr, this, index, OffsPair.getCPtr(value), value);
  }

  public OffsPair cast() {
    long cPtr = DummyCTokenizerWrapperJNI.OffsPairArray_cast(swigCPtr, this);
    return (cPtr == 0) ? null : new OffsPair(cPtr, false);
  }

  public static OffsPairArray frompointer(OffsPair t) {
    long cPtr = DummyCTokenizerWrapperJNI.OffsPairArray_frompointer(OffsPair.getCPtr(t), t);
    return (cPtr == 0) ? null : new OffsPairArray(cPtr, false);
  }

}
