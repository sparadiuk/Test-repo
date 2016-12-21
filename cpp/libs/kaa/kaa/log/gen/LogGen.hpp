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


#ifndef KAA_LOG_GEN_LOGGEN_HPP_371313235__H_
#define KAA_LOG_GEN_LOGGEN_HPP_371313235__H_


#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace kaa_log {
struct VoltageSample {
    int32_t zoneId;
    int32_t panelId;
    double voltage;
};

struct VoltageReport {
    int64_t timestamp;
    std::vector<VoltageSample > samples;
};

}
namespace avro {
template<> struct codec_traits<kaa_log::VoltageSample> {
    static void encode(Encoder& e, const kaa_log::VoltageSample& v) {
        avro::encode(e, v.zoneId);
        avro::encode(e, v.panelId);
        avro::encode(e, v.voltage);
    }
    static void decode(Decoder& d, kaa_log::VoltageSample& v) {
        avro::decode(d, v.zoneId);
        avro::decode(d, v.panelId);
        avro::decode(d, v.voltage);
    }
};

template<> struct codec_traits<kaa_log::VoltageReport> {
    static void encode(Encoder& e, const kaa_log::VoltageReport& v) {
        avro::encode(e, v.timestamp);
        avro::encode(e, v.samples);
    }
    static void decode(Decoder& d, kaa_log::VoltageReport& v) {
        avro::decode(d, v.timestamp);
        avro::decode(d, v.samples);
    }
};

}
#endif
