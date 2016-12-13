/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef KAA_CONFIGURATION_GEN_CONFIGURATIONGEN_HPP_293169158__H_
#define KAA_CONFIGURATION_GEN_CONFIGURATIONGEN_HPP_293169158__H_


#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace kaa_configuration {
struct ReportConfiguration {
    bool enableReporting;
    int32_t panelCount;
    int32_t samplingFrequency;
    int32_t reportingFrequency;
};

}
namespace avro {
template<> struct codec_traits<kaa_configuration::ReportConfiguration> {
    static void encode(Encoder& e, const kaa_configuration::ReportConfiguration& v) {
        avro::encode(e, v.enableReporting);
        avro::encode(e, v.panelCount);
        avro::encode(e, v.samplingFrequency);
        avro::encode(e, v.reportingFrequency);
    }
    static void decode(Decoder& d, kaa_configuration::ReportConfiguration& v) {
        avro::decode(d, v.enableReporting);
        avro::decode(d, v.panelCount);
        avro::decode(d, v.samplingFrequency);
        avro::decode(d, v.reportingFrequency);
    }
};

}
#endif
