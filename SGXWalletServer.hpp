#ifndef SGXWALLET_SGXWALLETSERVER_HPP
#define SGXWALLET_SGXWALLETSERVER_HPP




#include "abstractstubserver.h"
#include <mutex>


using namespace jsonrpc;
using namespace std;

class SGXWalletServer : public AbstractStubServer {


    SGXWalletServer* server = nullptr;
    std::recursive_mutex m;

public:
    SGXWalletServer(AbstractServerConnector &connector, serverVersion_t type);

    virtual Json::Value importBLSKeyShare(int index, const std::string& keyShare, const std::string& keyShareName, int n, int t);
    virtual Json::Value blsSignMessageHash(const std::string& keyShareName, const std::string& messageHash, int n, int t, int signerIndex);

    virtual Json::Value importECDSAKey(const std::string& key, const std::string& keyName);
    virtual Json::Value generateECDSAKey(const std::string& keyName);
    virtual Json::Value ecdsaSignMessageHash(int base, const std::string& keyShareName, const std::string& messageHash);
    virtual Json::Value getPublicECDSAKey(const std::string& keyName);

    virtual Json::Value generateDKGPoly(const std::string& polyName, int t);
    virtual Json::Value getVerificationVector(const std::string& polyName, int n, int t);
    virtual Json::Value getSecretShare(const std::string& polyName, const std::string& publicKeys, int n, int t);
    virtual Json::Value DKGVerification(const std::string& polyName, const std::string& EthKeyName, const std::string& SecretShare, int t, int n, int index);
    virtual Json::Value CreateBLSPrivateKey(const std::string & BLSKeyName, const std::string& EthKeyName, const Json::Value& SecretShare, int t, int n);

};

shared_ptr<string> readFromDb(const string & name, const string & prefix);
void writeDataToDB(const string & Name, const string &value);

void writeKeyShare(const string &_keyShareName, const string &value, int index, int n, int t);
shared_ptr<std::string> readKeyShare(const string& _keyShare);

void writeECDSAKey(const string& _keyName, const string& value);
shared_ptr<std::string> readECDSAKey(const string& _key);

void writeDKGPoly(const string &_polyName, const string &value);


Json::Value importBLSKeyShareImpl(int index, const std::string& keyShare, const std::string& keyShareName, int n, int t);
Json::Value blsSignMessageHashImpl(const std::string& keyShareName, const std::string& messageHash, int n, int t, int signerIndex);

Json::Value importECDSAKeyImpl(const std::string& key, const std::string& keyName);
Json::Value generateECDSAKeyImpl(const std::string& keyName);
Json::Value ecdsaSignMessageHashImpl(int base, const std::string& keyName, const std::string& messageHash);
Json::Value getPublicECDSAKeyImpl(const std::string& keyName);

Json::Value generateDKGPolyImpl(const std::string& polyName, int t);
Json::Value getVerificationVectorImpl(const std::string& polyName, int n, int t);
Json::Value getSecretShareImpl(const std::string& polyName, const std::string& publicKeys, int n, int t);
Json::Value DKGVerificationImpl(const std::string& polyName, const std::string& EthKeyName, const std::string& SecretShare, int t, int n, int index);
Json::Value CreateBLSPrivateKeyImpl(const std::string & BLSKeyName, const std::string& EthKeyName, const Json::Value& SecretShare, int t, int n);

#endif //SGXWALLET_SGXWALLETSERVER_HPP