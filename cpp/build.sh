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

function build_thirdparty {
    if [[ ! -d "$KAA_C_LIB_HEADER_PATH" &&  ! -d "$KAA_CPP_LIB_HEADER_PATH" ]]
    then
        KAA_SDK_TAR_NAME=$(find $PROJECT_HOME -iname $KAA_SDK_TAR)

        if [ -z "$KAA_SDK_TAR_NAME" ]
        then
            echo "Please, put the generated C/C++ SDK tarball into the libs/kaa folder and re-run the script."
            exit 1
        fi

        mkdir -p $KAA_LIB_PATH &&
        tar -zxf $KAA_SDK_TAR_NAME -C $KAA_LIB_PATH
    fi

    if [ ! -d "$KAA_LIB_PATH/$BUILD_DIR" ]
    then
        cd $KAA_LIB_PATH &&
        chmod 755 ./avrogen.sh &&
        ./avrogen.sh && 
        mkdir -p $BUILD_DIR && cd $BUILD_DIR &&
        cmake -DCMAKE_BUILD_TYPE=Debug \
              -DKAA_WITHOUT_EVENTS=1 \
              -DKAA_WITHOUT_NOTIFICATIONS=1 \
              -DKAA_WITHOUT_OPERATION_LONG_POLL_CHANNEL=1 \
              -DKAA_WITHOUT_OPERATION_HTTP_CHANNEL=1 \
              -DKAA_MAX_LOG_LEVEL=3 \
              ..
    fi

    cd "$PROJECT_HOME/$KAA_LIB_PATH/$BUILD_DIR"
    make -j2 &&
    cd $PROJECT_HOME
}

function build_app {
    mkdir -p "$PROJECT_HOME/$BUILD_DIR" &&
    cd "$PROJECT_HOME/$BUILD_DIR" &&
    cmake -DAPP_NAME=$APP_NAME \
          -DPOWER_PLANT_STARTUP_WORKAROUND=1 \
          -DPOWER_PLANT_RANDOMIZER=0 \
          -DPOWER_PLANT_DEBUG_LOGGING=0 \
          ..
    make -j2
}

# Need root privileges
function install_app {
    cd "$PROJECT_HOME/$BUILD_DIR" &&
    make install &&
    cp "$PROJECT_HOME/$STARTUP_SCRIPT" /etc/systemd/system &&
    systemctl enable /etc/systemd/system/$STARTUP_SCRIPT
}

function clean {
    rm -rf "$KAA_LIB_PATH/$BUILD_DIR"
    rm -rf "$PROJECT_HOME/$BUILD_DIR"
}

function run_as_service {
    systemctl restart powerplant.service
}

function run {
    cd "$PROJECT_HOME/$BUILD_DIR"
    ./$APP_NAME
}

function check_root {
    if [ "$(id -u)" != "0" ]; then
        echo "This command must be run as root!"
        exit 1
    fi
}

for cmd in $@
do

case "$cmd" in
    build)
        build_thirdparty &&
        build_app
    ;;

    run)
        run
    ;;

    deploy)
        check_root
        build_thirdparty
        build_app
        install_app
        run_as_service
    ;;

    clean)
        clean
    ;;

    *)
        help
    ;;
esac

done
