#!/bin/bash
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


RUN_DIR=`pwd`

function help {
    echo "Choose one of the following: {build|run|deploy|clean}"
    exit 1
}

if [ $# -eq 0 ]
then
    help
fi

# NOTE: The $APP_NAME value should match the one in the powerplant.sh script.
APP_NAME="powerplant_demo"
STARTUP_SCRIPT="powerplant.service"

PROJECT_HOME=$(pwd)
BUILD_DIR="build"
LIBS_PATH="libs"
KAA_LIB_PATH="$LIBS_PATH/kaa"
KAA_C_LIB_HEADER_PATH="$KAA_LIB_PATH/src"
KAA_CPP_LIB_HEADER_PATH="$KAA_LIB_PATH/kaa"
KAA_SDK_TAR="kaa-c*.tar.gz"

function build {
    mkdir -p "$PROJECT_HOME/$BUILD_DIR" &&
    cd "$PROJECT_HOME/$BUILD_DIR" &&
    cmake -DAPP_NAME=$APP_NAME \
          -DPOWER_PLANT_STARTUP_WORKAROUND=1 \
          -DPOWER_PLANT_RANDOMIZER=0 \
          -DPOWER_PLANT_DEBUG_LOGGING=1 \
          -DKAA_WITHOUT_EVENTS=1 \
          -DKAA_WITHOUT_NOTIFICATIONS=1 \
          -DKAA_WITHOUT_OPERATION_LONG_POLL_CHANNEL=1 \
          -DKAA_WITHOUT_OPERATION_HTTP_CHANNEL=1 \
          -DKAA_MAX_LOG_LEVEL=0 \
          ..
    make -j2
}

function clean {
    rm -rf "$KAA_LIB_PATH/$BUILD_DIR"
    rm -rf "$PROJECT_HOME/$BUILD_DIR"
}

function run {
    cd "$PROJECT_HOME/$BUILD_DIR"
    ./$APP_NAME
}

for cmd in $@
do

case "$cmd" in
    build)
        build
    ;;

    run)
        run
    ;;

    deploy)
        clean
        build
        run
    ;;

    clean)
        clean
    ;;

    *)
        help
    ;;
esac

done



