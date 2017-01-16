
#ifndef CRC32_H
#define CRC32_H
#include "defines.h"

#ifdef  __cplusplus
extern  "C" {
#endif 

u_int32_t	 crc32(u_int32_t crc, const u_char *buf, u_int32_t size);

#ifdef  __cplusplus
}
#endif 

#endif
