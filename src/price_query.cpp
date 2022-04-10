//
// Created by ben on 10/04/2022.
//

#include "../includes/price_query.h"

namespace price_query {

    CryptoCompareResponse CryptoCompareRequest::send_request() const {
        return (is_valid() ? CryptoCompareResponse(std::move(cpr::Get(request))) : CryptoCompareResponse(cpr::Response()));
    }
    bool CryptoCompareRequest::construct_request(const std::unordered_map<RequestParam, std::string>& url_params) { return false; }
    bool CryptoCompareRequest::is_valid() const { return false; }

}