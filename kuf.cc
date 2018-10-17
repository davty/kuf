#include <napi.h>

class Node {

};

class List : Napi::Object {
  //static 
};

Napi::Object CreateList(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object obj = Napi::Object::New(env);

  List list = List::New(env);

  obj.Set(Napi::String::New(env, "msg"), info[0].ToString());
  obj.Set(Napi::String::New(env, "length"), 0);
  obj.Set(Napi::String::New(env, "debug"), info.Length());

  return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  auto obj = Napi::Object::New(env);

  obj.Set("List", Napi::Function::New(env, CreateList, "createList"));

   return obj;
}

NODE_API_MODULE(addon, Init)