//
// Created by kladko on 8/14/19.
//

#ifndef SGXD_BLSUTILS_H
#define SGXD_BLSUTILS_H



#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC bool check_key(const char* _keyString);


#endif //SGXD_BLSUTILS_H