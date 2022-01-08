#include "DPFcnLib.h"

void dataPack4halfs_wrapper(unsigned short int half1,unsigned short int half2,unsigned short int half3,unsigned short int half4,unsigned char dataArray[],unsigned char Format){
    if(Format==0){
    dataArray[0]=half1>>8;
    dataArray[1]=half1;
    dataArray[2]=half2>>8;
    dataArray[3]=half2;
    dataArray[4]=half3>>8;
    dataArray[5]=half3;
    dataArray[6]=half4>>8;
    dataArray[7]=half4;
    return;
    }
    else if(Format==1){
    dataArray[0]=half1;
    dataArray[1]=half1>>8;
    dataArray[2]=half2;
    dataArray[3]=half2>>8;
    dataArray[4]=half3;
    dataArray[5]=half3>>8;
    dataArray[6]=half4;
    dataArray[7]=half4>>8;
    return;
    }
}

void dataPack2words_wrapper(unsigned int word1,unsigned int word2,unsigned char dataArray[],unsigned char Format){
    if(Format==0){
    dataArray[0]=word1>>24;
    dataArray[1]=word1>>16;
    dataArray[2]=word1>>8;
    dataArray[3]=word1;
    dataArray[4]=word2>>24;
    dataArray[5]=word2>>16;
    dataArray[6]=word2>>8;
    dataArray[7]=word2;
    return;
    }
    else if(Format==1){
    dataArray[0]=word1;
    dataArray[1]=word1>>8;
    dataArray[2]=word1>>16;
    dataArray[3]=word1>>24;
    dataArray[4]=word2;
    dataArray[5]=word2>>8;
    dataArray[6]=word2>>16;
    dataArray[7]=word2>>24;
    return;
    }
}

void  dataPack2bytes3halfs_wrapper(unsigned char byte1,unsigned char byte2,unsigned short int half2,unsigned short int half3,unsigned short int half4,unsigned char dataArray[]){
    dataArray[0]=byte1;
    dataArray[1]=byte2;
    dataArray[2]=half2>>8;
    dataArray[3]=half2;
    dataArray[4]=half3>>8;
    dataArray[5]=half3;
    dataArray[6]=half4>>8;
    dataArray[7]=half4;
    return;   
}
void  dataPack8bytes_wrapper(unsigned char byte1,unsigned char byte2,unsigned char byte3,unsigned char byte4,unsigned char byte5,unsigned char byte6,unsigned char byte7,unsigned char byte8,unsigned char dataArray[]){
    dataArray[0]=byte1;
    dataArray[1]=byte2;
    dataArray[2]=byte3;
    dataArray[3]=byte4;
    dataArray[4]=byte5;
    dataArray[5]=byte6;
    dataArray[6]=byte7;
    dataArray[7]=byte8;
    return; 
}

void  dataPack1word2halfs_wrapper(unsigned int word1,unsigned short int half3,unsigned short int half4,unsigned char dataArray[]){
    dataArray[0]=word1>>24;
    dataArray[1]=word1>>16;
    dataArray[2]=word1>>8;
    dataArray[3]=word1;
    dataArray[4]=half3>>8;
    dataArray[5]=half3;
    dataArray[6]=half4>>8;
    dataArray[7]=half4;
}


