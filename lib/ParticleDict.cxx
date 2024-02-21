// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuboonedIappdIusersdInlanedINeutralKaonAnalysisdIdIlibdIParticleDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "SimParticle.h"
#include "RecoParticle.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SimParticle_Dictionary();
   static void SimParticle_TClassManip(TClass*);
   static void *new_SimParticle(void *p = 0);
   static void *newArray_SimParticle(Long_t size, void *p);
   static void delete_SimParticle(void *p);
   static void deleteArray_SimParticle(void *p);
   static void destruct_SimParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SimParticle*)
   {
      ::SimParticle *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SimParticle));
      static ::ROOT::TGenericClassInfo 
         instance("SimParticle", "SimParticle.h", 15,
                  typeid(::SimParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SimParticle_Dictionary, isa_proxy, 4,
                  sizeof(::SimParticle) );
      instance.SetNew(&new_SimParticle);
      instance.SetNewArray(&newArray_SimParticle);
      instance.SetDelete(&delete_SimParticle);
      instance.SetDeleteArray(&deleteArray_SimParticle);
      instance.SetDestructor(&destruct_SimParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SimParticle*)
   {
      return GenerateInitInstanceLocal((::SimParticle*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SimParticle*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SimParticle_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SimParticle*)0x0)->GetClass();
      SimParticle_TClassManip(theClass);
   return theClass;
   }

   static void SimParticle_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RecoParticle_Dictionary();
   static void RecoParticle_TClassManip(TClass*);
   static void *new_RecoParticle(void *p = 0);
   static void *newArray_RecoParticle(Long_t size, void *p);
   static void delete_RecoParticle(void *p);
   static void deleteArray_RecoParticle(void *p);
   static void destruct_RecoParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RecoParticle*)
   {
      ::RecoParticle *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RecoParticle));
      static ::ROOT::TGenericClassInfo 
         instance("RecoParticle", "RecoParticle.h", 16,
                  typeid(::RecoParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RecoParticle_Dictionary, isa_proxy, 4,
                  sizeof(::RecoParticle) );
      instance.SetNew(&new_RecoParticle);
      instance.SetNewArray(&newArray_RecoParticle);
      instance.SetDelete(&delete_RecoParticle);
      instance.SetDeleteArray(&deleteArray_RecoParticle);
      instance.SetDestructor(&destruct_RecoParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RecoParticle*)
   {
      return GenerateInitInstanceLocal((::RecoParticle*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RecoParticle*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RecoParticle_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RecoParticle*)0x0)->GetClass();
      RecoParticle_TClassManip(theClass);
   return theClass;
   }

   static void RecoParticle_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_SimParticle(void *p) {
      return  p ? new(p) ::SimParticle : new ::SimParticle;
   }
   static void *newArray_SimParticle(Long_t nElements, void *p) {
      return p ? new(p) ::SimParticle[nElements] : new ::SimParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_SimParticle(void *p) {
      delete ((::SimParticle*)p);
   }
   static void deleteArray_SimParticle(void *p) {
      delete [] ((::SimParticle*)p);
   }
   static void destruct_SimParticle(void *p) {
      typedef ::SimParticle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SimParticle

namespace ROOT {
   // Wrappers around operator new
   static void *new_RecoParticle(void *p) {
      return  p ? new(p) ::RecoParticle : new ::RecoParticle;
   }
   static void *newArray_RecoParticle(Long_t nElements, void *p) {
      return p ? new(p) ::RecoParticle[nElements] : new ::RecoParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_RecoParticle(void *p) {
      delete ((::RecoParticle*)p);
   }
   static void deleteArray_RecoParticle(void *p) {
      delete [] ((::RecoParticle*)p);
   }
   static void destruct_RecoParticle(void *p) {
      typedef ::RecoParticle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RecoParticle

namespace ROOT {
   static TClass *vectorlESimParticlegR_Dictionary();
   static void vectorlESimParticlegR_TClassManip(TClass*);
   static void *new_vectorlESimParticlegR(void *p = 0);
   static void *newArray_vectorlESimParticlegR(Long_t size, void *p);
   static void delete_vectorlESimParticlegR(void *p);
   static void deleteArray_vectorlESimParticlegR(void *p);
   static void destruct_vectorlESimParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<SimParticle>*)
   {
      vector<SimParticle> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<SimParticle>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<SimParticle>", -2, "vector", 216,
                  typeid(vector<SimParticle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlESimParticlegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<SimParticle>) );
      instance.SetNew(&new_vectorlESimParticlegR);
      instance.SetNewArray(&newArray_vectorlESimParticlegR);
      instance.SetDelete(&delete_vectorlESimParticlegR);
      instance.SetDeleteArray(&deleteArray_vectorlESimParticlegR);
      instance.SetDestructor(&destruct_vectorlESimParticlegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<SimParticle> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<SimParticle>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlESimParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<SimParticle>*)0x0)->GetClass();
      vectorlESimParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlESimParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlESimParticlegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<SimParticle> : new vector<SimParticle>;
   }
   static void *newArray_vectorlESimParticlegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<SimParticle>[nElements] : new vector<SimParticle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlESimParticlegR(void *p) {
      delete ((vector<SimParticle>*)p);
   }
   static void deleteArray_vectorlESimParticlegR(void *p) {
      delete [] ((vector<SimParticle>*)p);
   }
   static void destruct_vectorlESimParticlegR(void *p) {
      typedef vector<SimParticle> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<SimParticle>

namespace ROOT {
   static TClass *vectorlERecoParticlegR_Dictionary();
   static void vectorlERecoParticlegR_TClassManip(TClass*);
   static void *new_vectorlERecoParticlegR(void *p = 0);
   static void *newArray_vectorlERecoParticlegR(Long_t size, void *p);
   static void delete_vectorlERecoParticlegR(void *p);
   static void deleteArray_vectorlERecoParticlegR(void *p);
   static void destruct_vectorlERecoParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RecoParticle>*)
   {
      vector<RecoParticle> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RecoParticle>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RecoParticle>", -2, "vector", 216,
                  typeid(vector<RecoParticle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERecoParticlegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RecoParticle>) );
      instance.SetNew(&new_vectorlERecoParticlegR);
      instance.SetNewArray(&newArray_vectorlERecoParticlegR);
      instance.SetDelete(&delete_vectorlERecoParticlegR);
      instance.SetDeleteArray(&deleteArray_vectorlERecoParticlegR);
      instance.SetDestructor(&destruct_vectorlERecoParticlegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RecoParticle> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RecoParticle>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERecoParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RecoParticle>*)0x0)->GetClass();
      vectorlERecoParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERecoParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERecoParticlegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RecoParticle> : new vector<RecoParticle>;
   }
   static void *newArray_vectorlERecoParticlegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RecoParticle>[nElements] : new vector<RecoParticle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERecoParticlegR(void *p) {
      delete ((vector<RecoParticle>*)p);
   }
   static void deleteArray_vectorlERecoParticlegR(void *p) {
      delete [] ((vector<RecoParticle>*)p);
   }
   static void destruct_vectorlERecoParticlegR(void *p) {
      typedef vector<RecoParticle> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RecoParticle>

namespace {
  void TriggerDictionaryInitialization_ParticleDict_Impl() {
    static const char* headers[] = {
0
    };
    static const char* includePaths[] = {
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_12_06a/Linux64bit+3.10-2.17-e17-prof/include",
"/uboone/app/users/nlane/NeutralKaonAnalysis/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ParticleDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$RecoParticle.h")))  RecoParticle;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$SimParticle.h")))  SimParticle;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ParticleDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include <vector>
#include "SimParticle.h"
#include "RecoParticle.h"

#ifdef __ROOTCLING__
#pragma link C++ class SimParticle+;
#pragma link C++ class RecoParticle+;
#pragma link C++ class vector<SimParticle>+;
#pragma link C++ class vector<RecoParticle>+;

#endif
#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"RecoParticle", payloadCode, "@",
"SimParticle", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ParticleDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ParticleDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ParticleDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ParticleDict() {
  TriggerDictionaryInitialization_ParticleDict_Impl();
}
