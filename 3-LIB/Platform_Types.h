#ifndef    PLATFORM_TYPES_H_
#define    PLATFORM_TYPES_H_

typedef signed char           sint8;
typedef unsigned char         uint8;
typedef signed short          sint16;
typedef unsigned short        uint16;
typedef signed int            sint32;
typedef unsigned int          uint32;
typedef signed long long      sint64;
typedef unsigned long long    uint64;
typedef  float                float32;
typedef double                float64;



typedef volatile sint8      vint8_t;
typedef volatile uint8    vuint8_t;
typedef volatile sint16  vint16_t;
typedef volatile uint16  vuint16_t;
typedef volatile sint32  vint32_t;
typedef volatile uint32  vuint32_t;
typedef volatile sint64  vint64_t;
typedef volatile uint64  vuint64_t;
typedef volatile float32 vfloat32_t;
typedef volatile float64 vfloat64_t;

#define  NULL            0

#define NOK              0
#define OK               1
#define NULL_pointer     2







#endif
