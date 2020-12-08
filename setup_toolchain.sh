#!/bin/bash

ELEC_PATH=/home/user/gits/351ELEC

BUILD_DIR=build-351elec
pushd $ELEC_PATH

export DISTRO=351ELEC
export PROJECT=Rockchip
export DEVICE=RG351P
export ARCH=aarch64

. config/options ""
. config/multithread
. config/path ""
# #. config/show_config


#show_config

# ${SCRIPTS}/checkdeps

setup_toolchain target

# export TOOLCHAIN_DIR=ELEC_PATH=

popd

set +e

# echo $CC

# rm -rf $BUILD_DIR
# mkdir -p $BUILD_DIR
# cd $BUILD_DIR
# cmake ..
# cmake --build .
