FROM debian:bullseye as basis
# RUN apk add --no-cache git cmake gcc-arm-none-eabi newlib-arm-none-eabi gcc g++ make libc-dev python3
RUN apt update
RUN apt install -y git cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential python3 libstdc++-arm-none-eabi-newlib
# RUN adduser builder -D  --shell /bin/sh
RUN adduser --quiet --shell /bin/sh --disabled-password builder
WORKDIR /home/builder
RUN git clone https://github.com/raspberrypi/pico-sdk.git --branch master
WORKDIR /home/builder/pico-sdk
RUN git submodule update --init
WORKDIR /home/builder
