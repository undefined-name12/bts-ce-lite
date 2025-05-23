#include "telecomparser.h"
#include "bodabulkcmparser.h"
#include "bodahuaweimmlparser.h"
#include "bodahuaweigexportparser.h"
#include "spdlog/spdlog.h"
#include "XmlInspector/XmlInspector.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <napi.h>

int bodastage::parse_bulkcm(string input_file, string output_dir, string multivalue_sep, string meta_fields, string extract_parametes, bool separate_vsdata)
{
    spdlog::info("Parsing bulkcm file: {}", input_file);

    bodastage::BodaBulkCmParser parser;
    parser.set_data_source(input_file);
    parser.set_output_directory(output_dir);
    parser.set_separate_vendor_attributes(false);
    parser.parse();
   
    return 0;
}

int bodastage::parse_huaweimml(string input_file, string output_dir, string multivalue_sep, string meta_fields, string extract_parametes)
{
    spdlog::info("Parsing huaweil MML file: {}", input_file);

    bodastage::BodaHuaweiMMLParser parser;
    parser.set_data_source(input_file);
    parser.set_output_directory(output_dir);
    parser.parse();
   
    return 0;
}

int bodastage::parse_huaweigexport(string input_file, string output_dir, string multivalue_sep, string meta_fields, string extract_parameters)
{
    spdlog::info("Parsing Huawei GExport file: {}", input_file);

    bodastage::BodaHuaweiGExportParser parser;
    parser.set_data_source(input_file);
    parser.set_output_directory(output_dir);
    parser.parse();
   
    return 0;
}

Napi::Boolean bodastage::parse_bulkcm_wrapper(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    //@todo: validate args 

    // convert javascripts datatype to c++
    Napi::String input_file = info[0].As<Napi::String>();
    Napi::String output_dir = info[1].As<Napi::String>();

    // run c++ function return value and return it in javascript
    Napi::Boolean returnValue = Napi::Boolean::New(env, bodastage::parse_bulkcm(input_file.Utf8Value(), output_dir.Utf8Value()));

    return returnValue;
}

Napi::Boolean bodastage::parse_huaweimml_wrapper(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    //@todo: validate args 

    // convert javascripts datatype to c++
    Napi::String input_file = info[0].As<Napi::String>();
    Napi::String output_dir = info[1].As<Napi::String>();

    // run c++ function return value and return it in javascript
    Napi::Boolean returnValue = Napi::Boolean::New(env, bodastage::parse_huaweimml(input_file.Utf8Value(), output_dir.Utf8Value()));

    return returnValue;
}

Napi::Boolean bodastage::parse_huaweigexport_wrapper(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    //@todo: validate args 

    // convert javascripts datatype to c++
    Napi::String input_file = info[0].As<Napi::String>();
    Napi::String output_dir = info[1].As<Napi::String>();

    // run c++ function return value and return it in javascript
    Napi::Boolean returnValue = Napi::Boolean::New(env, bodastage::parse_huaweigexport(input_file.Utf8Value(), output_dir.Utf8Value()));

    return returnValue;
}



TelecomParser::TelecomParser(Napi::Env env, Napi::Object exports) {
    DefineAddon(exports, {
        InstanceMethod("parse_bulkcm", &TelecomParser::parse_bulkcm),
        InstanceMethod("parse_huaweimml", &TelecomParser::parse_huaweimml),
        InstanceMethod("parse_huaweigexport", &TelecomParser::parse_huaweigexport),
    });

}

//bulkcm
Napi::Value TelecomParser::parse_bulkcm(const Napi::CallbackInfo& info) {
    return bodastage::parse_bulkcm_wrapper(info);
}

//Huawei CFGMML
Napi::Value TelecomParser::parse_huaweimml(const Napi::CallbackInfo& info) {
    return bodastage::parse_huaweimml_wrapper(info);
}

//Huawei GExport
Napi::Value TelecomParser::parse_huaweigexport(const Napi::CallbackInfo& info) {
    return bodastage::parse_huaweigexport_wrapper(info);
}

NODE_API_ADDON(TelecomParser)