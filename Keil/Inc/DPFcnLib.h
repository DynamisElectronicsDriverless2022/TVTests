#ifndef DP_FCN_LIB
#define DP_FCN_LIB

void  dataPack4halfs_wrapper(unsigned short int half1,unsigned short int half2,unsigned short int half3,unsigned short int half4,unsigned char dataArray[],unsigned char  Format);
void  dataPack2words_wrapper(unsigned int word1,unsigned int word2,unsigned char dataArray[],unsigned char  Format);
void  dataPack2bytes3halfs_wrapper(unsigned char byte1,unsigned char byte2,unsigned short int half2,unsigned short int half3,unsigned short int half4,unsigned char dataArray[]);
void  dataPack8bytes_wrapper(unsigned char byte1,unsigned char byte2,unsigned char byte3,unsigned char byte4,unsigned char byte5,unsigned char byte6,unsigned char byte7,unsigned char byte8,unsigned char dataArray[]);
void  dataPack1word2halfs_wrapper(unsigned int word1,unsigned short int half3,unsigned short int half4,unsigned char dataArray[]);
#endif