cmake_minimum_required(VERSION 3.22)
project(Arduino)

set(CMAKE_CXX_STANDARD 14)

include_directories(bluetooth-android)
include_directories(libs/Zumo)
include_directories(sketch_may02a)

add_executable(Arduino
        bluetooth-android/Async.h
        bluetooth-android/bluetooth-android.ino
        libs/Zumo/L3G.cpp
        libs/Zumo/L3G.h
        libs/Zumo/LSM303.cpp
        libs/Zumo/LSM303.h
        libs/Zumo/PololuBuzzer.h
        libs/Zumo/Pushbutton.cpp
        libs/Zumo/Pushbutton.h
        libs/Zumo/QTRSensors.cpp
        libs/Zumo/QTRSensors.h
        libs/Zumo/ZumoBuzzer.h
        libs/Zumo/ZumoIMU.cpp
        libs/Zumo/ZumoIMU.h
        libs/Zumo/ZumoMotors.cpp
        libs/Zumo/ZumoMotors.h
        libs/Zumo/ZumoReflectanceSensorArray.h
        libs/Zumo/ZumoShield.h
        sketch_may02a/sketch_may02a.ino)
