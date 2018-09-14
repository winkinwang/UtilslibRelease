#ifndef _CRC_H_
#define _CRC_H_

//Define data type

#ifndef crc_uint8_t
typedef unsigned char crc_uint8_t;
#endif
#ifndef crc_uint16_t
typedef unsigned short crc_uint16_t;
#endif
#ifndef crc_uint32_t
typedef unsigned int crc_uint32_t;
#endif

#ifndef NULL
#define NULL 0
#endif

#if __cplusplus
extern "C"
{       
#endif  

crc_uint32_t calc_crc_normally(crc_uint8_t* mem, crc_uint32_t len, crc_uint32_t crc_initial, crc_uint32_t crc_type);
crc_uint32_t calc_crc_via_precalc_table(crc_uint8_t* mem, crc_uint32_t len,	crc_uint32_t crc_initial, crc_uint32_t crc_type);
crc_uint32_t crc_table_generate(crc_uint32_t crc_type);

#if __cplusplus
}
#endif

enum {	
		CRC_TYPE_DEFINITION_START,
			
		CRC_TYPE_CRC_4 = 0, 
		CRC_TYPE_CRC_12,
		CRC_TYPE_CRC_16,
		CRC_TYPE_CRC_ITU,
		CRC_TYPE_CRC_CCITT = CRC_TYPE_CRC_ITU,
		CRC_TYPE_CRC_32,
		CRC_TYPE_CRC_32c,
		
		CRC_TYPE_DEFINITION_END		
	};

#define CRC32_REMAINDER (0xCBF43926)
#define CRC32_INITIAL (~0)

#define DO_CRC_4(mem, len) ((crc_uint8_t)calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_4))
#define DO_CRC_12(mem, len) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_12))
#define DO_CRC_16(mem, len) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_16))
#define DO_CRC_ITU(mem, len) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_ITU))
#define DO_CRC_32(mem, len) calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_32)
#define DO_CRC_32c(mem, len) calc_crc_via_precalc_table(mem, len, CRC32_INITIAL, CRC_TYPE_CRC_32c)

#define DO_CRC_4_I(mem, len, init) ((crc_uint8_t)calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_4))
#define DO_CRC_12_I(mem, len, init) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_12))
#define DO_CRC_16_I(mem, len, init) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_16))
#define DO_CRC_ITU_I(mem, len, init) ((crc_uint16_t)calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_ITU))
#define DO_CRC_32_I(mem, len, init) calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_32)
#define DO_CRC_32c_I(mem, len, init) calc_crc_via_precalc_table(mem, len, init, CRC_TYPE_CRC_32c)

#endif /*CRC_H_INCLUDED_8972893hfkjsh9hjkcv98_njk93r_ABRAHAM_XU*/


