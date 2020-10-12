#ifndef __CRC32_H
#define __CRC32_H

unsigned long crc32stream( unsigned char c, unsigned long crc );    
unsigned long crc32( unsigned char * buf, unsigned long len, unsigned long crc );    

#endif // __CRC32_H
