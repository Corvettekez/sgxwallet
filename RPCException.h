//
// Created by skale on 9/8/19.
//

#ifndef SGXD_RPCEXCEPTION_H
#define SGXD_RPCEXCEPTION_H


#include <string>
#include <exception>

class RPCException : public std::exception {
    int32_t status;
    std::string errString;

    RPCException(int32_t _status, std::string& _errString) : status(_status), errString(_errString) {}

};


#endif //SGXD_RPCEXCEPTION_H
