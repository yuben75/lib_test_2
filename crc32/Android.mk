LOCAL_PATH := $(call my-dir)
    

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/src/include/
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/project2/src/include/

include $(CLEAR_VARS)
LOCAL_MODULE    := libcrc32
LOCAL_SRC_FILES := crc32.c
    
include $(BUILD_SHARED_LIBRARY)



include $(CLEAR_VARS)
LOCAL_MODULE    := libcrc32
LOCAL_SRC_FILES := crc32.c
    
include $(BUILD_STATIC_LIBRARY)



