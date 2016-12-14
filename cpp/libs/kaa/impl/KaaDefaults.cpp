/*
 * Copyright 2014-2016 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * NOTE: This is a auto-generated file. Do not edit it.
 */

#include "kaa/KaaDefaults.hpp"

#include <algorithm>
#include <cstdint>
#include <sstream>

#include "kaa/channel/GenericTransportInfo.hpp"

namespace kaa {

const char * const BUILD_VERSION = "0.10.0";

const char * const BUILD_COMMIT_HASH = "";

const char * const SDK_TOKEN = "enCarMNX_7EImkCEXHsFPUVvkgU";

const std::uint32_t POLLING_PERIOD_SECONDS = 5;

const char * const CLIENT_PUB_KEY_LOCATION = "key.public";

const char * const CLIENT_PRIV_KEY_LOCATION = "key.private";

const char * const CLIENT_STATUS_FILE_LOCATION = "kaa.status";

const char * const DEFAULT_USER_VERIFIER_TOKEN = "";

ITransportConnectionInfoPtr createTransportInfo(const std::int32_t& accessPointId
                                              , const std::int32_t& protocolId
                                              , const std::int32_t& protocolVersion
                                              , const std::string& encodedConnectionData)
{
    auto buffer = Botan::base64_decode(encodedConnectionData);
    ITransportConnectionInfoPtr connectionInfo(
            new GenericTransportInfo(ServerType::BOOTSTRAP
                                   , accessPointId
                                   , TransportProtocolId(protocolId, protocolVersion)
                                   , std::vector<std::uint8_t>(buffer.begin(), buffer.end())));

    return connectionInfo;
}

const BootstrapServers& getBootstrapServers() 
{
    static BootstrapServers listOfServers;
    if (listOfServers.empty()) {
        listOfServers.push_back(createTransportInfo(0xe808e9b2, 0xfb9a3cf0, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAIpT006SSrVHJVEQ8Op2jFniLojPTF9lYv0advgIeV1ZnNEIsBpYupKTrbahjbHsiColN2clYfviwo7cAn2hRceHEA0kLxpP6gkhdosYdvSFxONYbn4aPmveonzgaNbEUowv+yyuzMelOb9UaaxPTqzYmK7sLgGb44eX5axn5O9E4MKeS62buybBCqihjguyOujMaZNHFXomSuoPI0GNl5rVDwIa4IcZqKiVaebvr8mbnk2gk2eC9dotJvcK5IHpj5tT+3+LyNE0LhB4kdjXqm6E+2NyJjGzcZbD8j4I4byOnIF4P4thawGTHoXrk3op344lqDJuaGllLEQuMY/L2psCAwEAAQAAAAwxOTIuMTY4LjEuMTMAACah"));
listOfServers.push_back(createTransportInfo(0xe808e9b2, 0x56c8ff92, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAIpT006SSrVHJVEQ8Op2jFniLojPTF9lYv0advgIeV1ZnNEIsBpYupKTrbahjbHsiColN2clYfviwo7cAn2hRceHEA0kLxpP6gkhdosYdvSFxONYbn4aPmveonzgaNbEUowv+yyuzMelOb9UaaxPTqzYmK7sLgGb44eX5axn5O9E4MKeS62buybBCqihjguyOujMaZNHFXomSuoPI0GNl5rVDwIa4IcZqKiVaebvr8mbnk2gk2eC9dotJvcK5IHpj5tT+3+LyNE0LhB4kdjXqm6E+2NyJjGzcZbD8j4I4byOnIF4P4thawGTHoXrk3op344lqDJuaGllLEQuMY/L2psCAwEAAQAAAAwxOTIuMTY4LjEuMTMAACag"));
listOfServers.push_back(createTransportInfo(0x6e9c9b1c, 0xfb9a3cf0, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKasWi38ngt9U9exz6XR9Iofj3uRF+eJcIDLlRojT4eg2vE0BJLrRKmXRvYB5HXlo2taAGaN/zKplAqZHRBqsQ/KrzqaK5kFp+kF3rNIQrYN1CLufnwfCCPS5FMzz6D5pnacPuiDeK/U3hn/MYtITnSuXL/18TNwVyQGrt8i5gECZK6VPfOlZtCStF+YHEaMQOJzA+aU0hK7MIonfUKv9lsDLgsCNzl7CrEX//WmoPQzTopDnA2pa9sgcGJNE+bfNIVRZpznTl6EgQl0t9A5nap0UkohFKnDYSGBBqY7QJPSyFgN/1iPIxBYZ+SkryX5t7tDggZSpZAkcAXo7elSH5UCAwEAAQAAAAwxOTIuMTY4LjEuMTAAACah"));
listOfServers.push_back(createTransportInfo(0x6e9c9b1c, 0x56c8ff92, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKasWi38ngt9U9exz6XR9Iofj3uRF+eJcIDLlRojT4eg2vE0BJLrRKmXRvYB5HXlo2taAGaN/zKplAqZHRBqsQ/KrzqaK5kFp+kF3rNIQrYN1CLufnwfCCPS5FMzz6D5pnacPuiDeK/U3hn/MYtITnSuXL/18TNwVyQGrt8i5gECZK6VPfOlZtCStF+YHEaMQOJzA+aU0hK7MIonfUKv9lsDLgsCNzl7CrEX//WmoPQzTopDnA2pa9sgcGJNE+bfNIVRZpznTl6EgQl0t9A5nap0UkohFKnDYSGBBqY7QJPSyFgN/1iPIxBYZ+SkryX5t7tDggZSpZAkcAXo7elSH5UCAwEAAQAAAAwxOTIuMTY4LjEuMTAAACag"));
listOfServers.push_back(createTransportInfo(0x23543a17, 0xfb9a3cf0, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAI5s0e9fimeitiFSjnM1MP+Oe7FbFmC14jKjSoEYFynuTBrnH66BmqWUTdhDP/WZBhRkEty0X8NQW1dNyjqTVpCqI1DVQGDijZCamMkcuTREnXFMbT1ZrURf6HeCB0URFGq6oo8twOdyNt12cUwxLGj7/oLBfBvdNsivv7X04WBJHnkRZUNfinSyVZiv8hMZuOUMVgU3YUpOxdoT2r8ljK55Bd5PASWYB8FMxRb7aqVch97w3lxWgHj78cdITHROs7QauJ2xMSxNkTf0tVZ51egKNmKCr5OE7coXArCAQ7aBO5oPSxYPDwvR8w+EN8l9HtlCBPzB1jpxEjEhc3X8lmkCAwEAAQAAAAwxOTIuMTY4LjEuMTIAACah"));
listOfServers.push_back(createTransportInfo(0x23543a17, 0x56c8ff92, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAI5s0e9fimeitiFSjnM1MP+Oe7FbFmC14jKjSoEYFynuTBrnH66BmqWUTdhDP/WZBhRkEty0X8NQW1dNyjqTVpCqI1DVQGDijZCamMkcuTREnXFMbT1ZrURf6HeCB0URFGq6oo8twOdyNt12cUwxLGj7/oLBfBvdNsivv7X04WBJHnkRZUNfinSyVZiv8hMZuOUMVgU3YUpOxdoT2r8ljK55Bd5PASWYB8FMxRb7aqVch97w3lxWgHj78cdITHROs7QauJ2xMSxNkTf0tVZ51egKNmKCr5OE7coXArCAQ7aBO5oPSxYPDwvR8w+EN8l9HtlCBPzB1jpxEjEhc3X8lmkCAwEAAQAAAAwxOTIuMTY4LjEuMTIAACag"));
listOfServers.push_back(createTransportInfo(0xa5c048b9, 0xfb9a3cf0, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJyBLy844T081m1Lwr5ljf5QlEGKNnpPI/PO3eeuHzfU7iwa0Vs/SdVhAZD9kOizrdBOCxghYMRjYWYo9qQ5Wkm8RBYDAXOZRVsHXyov/Q2VjVjVlDldtw/h/M2LBy5RCHCNjnCISeKKtH/pgG9sdUgj7QgeoYYnMn2VIthh+ZEfucmnsvFHFuWS+k0PBvkBGAKXZGhyxjkVw/PqurF9zlttJZiPQdDCjbpjzEibHUqtcYqbzCQoIRuvF95ufgEINdoS7zL/u8fvBGLsTJ6rHX+v5Dng/lQFx8I/k7f8ledow2BCDhVnFaXoPR8QWauc+WyefI4ihbIjln5XAE+cULMCAwEAAQAAAAwxOTIuMTY4LjEuMTEAACah"));
listOfServers.push_back(createTransportInfo(0xa5c048b9, 0x56c8ff92, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJyBLy844T081m1Lwr5ljf5QlEGKNnpPI/PO3eeuHzfU7iwa0Vs/SdVhAZD9kOizrdBOCxghYMRjYWYo9qQ5Wkm8RBYDAXOZRVsHXyov/Q2VjVjVlDldtw/h/M2LBy5RCHCNjnCISeKKtH/pgG9sdUgj7QgeoYYnMn2VIthh+ZEfucmnsvFHFuWS+k0PBvkBGAKXZGhyxjkVw/PqurF9zlttJZiPQdDCjbpjzEibHUqtcYqbzCQoIRuvF95ufgEINdoS7zL/u8fvBGLsTJ6rHX+v5Dng/lQFx8I/k7f8ledow2BCDhVnFaXoPR8QWauc+WyefI4ihbIjln5XAE+cULMCAwEAAQAAAAwxOTIuMTY4LjEuMTEAACag"));
listOfServers.push_back(createTransportInfo(0xf50dd90a, 0xfb9a3cf0, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAK7UXGWbpifFj5WjP4UgYCjzXhZpnzuuNuBYz9+8fjC6NqeG9Ws1NiNo/1fnIAW0EevgmKWoPJdzBJaLs1vEHQIDn46muEIIM0+0txbFwyrHOl/1X//vWqIvaog8NtyASRaXVjqgr2yT9ZK4lOeDTxZZp+h3cdjHuk/mQK72qT9XTTguy/eT4NaoHPKbZkMh51/86+6qDAeskYxrjUMqeODOP5RLtWjHJrLfnjmMuOAAWC/DsaHcdD8SNVnZeiyon2koCNZu0GQkZ7pbfPjYyxH5ByDU0izwWaat7JTYPQWA3v74BlchUBLiMzDTzvOWEPVqYQ/ZThQKwPlFnTv6J/8CAwEAAQAAAAwxOTIuMTY4LjEuMTQAACah"));
listOfServers.push_back(createTransportInfo(0xf50dd90a, 0x56c8ff92, 1, "AAABJjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAK7UXGWbpifFj5WjP4UgYCjzXhZpnzuuNuBYz9+8fjC6NqeG9Ws1NiNo/1fnIAW0EevgmKWoPJdzBJaLs1vEHQIDn46muEIIM0+0txbFwyrHOl/1X//vWqIvaog8NtyASRaXVjqgr2yT9ZK4lOeDTxZZp+h3cdjHuk/mQK72qT9XTTguy/eT4NaoHPKbZkMh51/86+6qDAeskYxrjUMqeODOP5RLtWjHJrLfnjmMuOAAWC/DsaHcdD8SNVnZeiyon2koCNZu0GQkZ7pbfPjYyxH5ByDU0izwWaat7JTYPQWA3v74BlchUBLiMzDTzvOWEPVqYQ/ZThQKwPlFnTv6J/8CAwEAAQAAAAwxOTIuMTY4LjEuMTQAACag"));
;
        std::random_shuffle(listOfServers.begin(), listOfServers.end());
    }
    return listOfServers;
}

const Botan::secure_vector<std::uint8_t>& getDefaultConfigData() 
{
    static const Botan::secure_vector<std::uint8_t> configData = Botan::base64_decode("AJzbAprbAs7QlgM=");
    return configData;
}

HashDigest getPropertiesHash()
{
    std::ostringstream ss;

    ss << SDK_TOKEN;
    ss << POLLING_PERIOD_SECONDS;
    ss << CLIENT_PUB_KEY_LOCATION;
    ss << CLIENT_PRIV_KEY_LOCATION;
    ss << CLIENT_STATUS_FILE_LOCATION;

    for (const auto& server : getBootstrapServers()) {
        const auto& connectionInfo = server->getConnectionInfo();
        ss.write(reinterpret_cast<const char*>(connectionInfo.data()), connectionInfo.size());
    }

    ss.write(reinterpret_cast<const char*>(
            getDefaultConfigData().data()), getDefaultConfigData().size());

    return EndpointObjectHash(ss.str()).getHashDigest();
}

}
