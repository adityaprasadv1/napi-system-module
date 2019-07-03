#include <napi.h>
#include <windows.h>

using namespace Napi;

String moduleVersion(const CallbackInfo& info) {
  Env env = info.Env();
  return String::New(env, "0.1.0-alpha");
}

String moduleVersion1(const CallbackInfo& info) {
  Env env = info.Env();
  return String::New(env, "0.1.0-alpha1");
}

Object InitAll(Env env, Object exports) {
  exports.Set(String::New(env, "moduleVersion"), Function::New(env, moduleVersion));
  exports.Set(String::New(env, "moduleVersion1"), Function::New(env, moduleVersion1));
  return exports;
}

NODE_API_MODULE(system, InitAll)
