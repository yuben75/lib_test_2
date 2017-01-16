LOCAL_PATH := $(call my-dir)
    



include $(CLEAR_VARS)
LOCAL_TARGET := ARM

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../crc32/ $(LOCAL_PATH)/../cmdClient_9801x
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include/

LOCAL_MODULE    := cmd_9801x
LOCAL_SRC_FILES := server.cpp
LOCAL_SHARED_LIBRARIES += libcrc32
    
include $(BUILD_EXECUTABLE)





