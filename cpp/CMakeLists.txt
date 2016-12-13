#
#  Copyright 2014-2016 CyberVision, Inc.
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

cmake_minimum_required(VERSION 2.8.8)

 

project (Cpp-SDK-logging-sample)
enable_language(CXX)

# Path to CMake's scripts.
set(CMAKE_MODULE_PATH
	 ${CMAKE_MODULE_PATH}
	 ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/Modules
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -I/usr/local/include")

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/lib/x86_64-linux-gnu -std=c++0x")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L/usr/local/lib -std=gnu++11 -stdlib=libc++")
endif()

 


 
add_definitions(-DPOWER_PLANT_STARTUP_WORKAROUND=${POWER_PLANT_STARTUP_WORKAROUND})
add_definitions(-DPOWER_PLANT_RANDOMIZER=${POWER_PLANT_RANDOMIZER})
add_definitions(-DPOWER_PLANT_DEBUG_LOGGING=${POWER_PLANT_DEBUG_LOGGING})
 
                   
                   
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa
                   )

                    
                    
                    

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build
                 ${CMAKE_CURRENT_SOURCE_DIR}/libs/kaa/build
                 )

set (DEMO_SOURCE_FILES
            src/KaaDemo.cpp
            src/PowerPlantController.cpp
            src/ReportingManager.cpp
            src/SolarPanel.cpp
)

add_executable(${APP_NAME} ${DEMO_SOURCE_FILES})

 
add_subdirectory(libs/kaa)
#add_executable(${APP_NAME} ${SAMPLE_SOURCE_FILES})
#install(TARGETS ${APP_NAME} DESTINATION bin)

if (CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(${APP_NAME} kaacpp ${BOTAN_LIBRARY} ${AVRO_LIBRARIES} ${Boost_LIBRARIES} pthread)
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_link_libraries(${APP_NAME} kaacpp ${BOTAN_LIBRARY} ${AVRO_LIBRARIES} ${Boost_LIBRARIES})
endif()

if (MSVC)
    target_link_libraries(${APP_NAME} kaacpp ${BOTAN_LIBRARY} ${AVRO_LIBRARIES} ${Boost_LIBRARIES} dbghelp)
endif()
 

if (NOT POWER_PLANT_RANDOMIZER)
 #   target_link_libraries(${APP_NAME} mraa)
endif()

install (TARGETS ${APP_NAME} DESTINATION /usr/local/sbin/)
