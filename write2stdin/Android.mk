LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := write2stdin.cpp

LOCAL_MODULE := libwrite2stdin

LOCAL_CFLAGS := \
  -Wno-format

# frida needs to know address of function write2stdin
cmd-strip :=

include $(BUILD_SHARED_LIBRARY)
