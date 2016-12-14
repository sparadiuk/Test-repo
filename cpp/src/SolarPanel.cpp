/**
 *  Copyright 2014-2016 CyberVision, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "SolarPanel.hpp"

#include <string>

namespace power_plant {

SolarPanel::SolarPanel(std::int32_t zoneId, std::int32_t panelId)
    : zoneId_(zoneId), panelId_(panelId)
{
#if !POWER_PLANT_RANDOMIZER
    if (zoneId_ >= POWER_PLANT_MAX_SOLAR_PANEL_COUNT) {
        throw std::invalid_argument("Zone id number must be less than " + std::to_string(POWER_PLANT_MAX_SOLAR_PANEL_COUNT));
    }

//    panelConnection_ = std::make_shared<mraa::Aio>(zoneId_);
#endif
}

 

} /* namespace power_plant */
