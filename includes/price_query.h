//
// Created by ben on 10/04/2022.
//

#ifndef CRYPTOTRACKER_PRICE_QUERY_H
#define CRYPTOTRACKER_PRICE_QUERY_H

#include <map>
#include <unordered_map>
#include <string>
#include <initializer_list>

#include "cpr/cpr.h"

namespace price_query {

    enum CryptoSymbols {
        BTC,
        ETH
    };
    const char* crypto_symbols[] = {
            "BTC",
            "ETH"
    };
    enum FiatSymbols {
        USD,
        EUR,
        GBP
    };
    const char* fiat_symbols[] = {
            "USD",
            "EUR",
            "GBP"
    };

    enum class RequestParam {
        TRY_CONVERSION,
        FSYM,
        FYSMS,
        TYSM,
        TSYMS,
        RELAXED_VALIDATION,
        E,
        EXTRA_PARAMS,
        SIGN,
        API_KEY,
        AGGREGATE,
        AGGREGATE_PREDICTABLE_TIME_PERIODS,
        LIMIT,
        ALL_DATA,
        TO_T_S,
        EXPLAIN_PATH,
        DATE,
        TS,
        CALCULATION_TYPE,
        AVG_TYPE,
        UTC_HOUR_DIFF,
        PROVIDER,
        EXCHANGE_FSYM,
        PAGE,
        ASSET_CLASS,
        ASCENDING,
        DIRECTION,
        COIN_ID,
        FEEDS,
        CATEGORIES,
        EXCLUDE_CATEGORIES,
        IT_S,
        LANG,
        SORT_ORDER,
        TOP_TIER,
        INSTRUMENT,
        BUILT_ON,
        SUMMARY,
        INDEX_NAME,
        BASE,
        QUOTE,
        MARKET
    };
    const char* request_params[] = {
            "tryConversion",
            "fsym",
            "fsyms",
            "tysm",
            "tsyms",
            "relaxedValidation",
            "e",
            "extraParams",
            "sign",
            "api_key",
            "aggregate",
            "aggregatePredictableTimePeriods",
            "limit",
            "allData",
            "toTs",
            "explainPath",
            "date",
            "ts",
            "calculationType",
            "avgType",
            "UTCHourDiff",
            "provider",
            "exchangeFsym",
            "page",
            "assetClass",
            "ascending",
            "direction",
            "coinId",
            "feeds",
            "categories",
            "excludeCategories",
            "ITs",
            "lang",
            "sortOrder",
            "topTier",
            "instrument",
            "builtOn",
            "summary",
            "indexName",
            "base",
            "quote",
            "market"
    };

class InvalidRequestException : public std::runtime_error {
public:
    explicit InvalidRequestException(const std::string& message) : std::runtime_error(message) {}
};

class CryptoCompareResponse : public cpr::Response {
    private:
        cpr::Response response;
    public:
        explicit CryptoCompareResponse(cpr::Response&& new_response) : cpr::Response(new_response) {}
        /*[[nodiscard]] long status_code() const { return response.status_code; }
        [[nodiscard]] std::string text() const { return response.text; }
        [[nodiscard]] cpr::Header header() const { return response.header; }
        [[nodiscard]] cpr::Url url() const { return response.url; }
        [[nodiscard]] double elapsed() const { return response.elapsed; }
        [[nodiscard]] cpr::Cookies cookies() const { return response.cookies;}
        [[nodiscard]] cpr::Error error() const { return response.error; }
        [[nodiscard]] std::string raw_header() const { return response.raw_header; }
        [[nodiscard]] std::string status_line() const { return response.status_line; }
        [[nodiscard]] std::string reason() const { return response.reason; }
        [[nodiscard]] cpr::cpr_off_t uploaded_bytes() const { return response.uploaded_bytes; }
        [[nodiscard]] cpr::cpr_off_t downloaded_bytes() const { return response.downloaded_bytes; }
        [[nodiscard]] long redirect_count() const { return response.redirect_count; }
        [[nodiscard]] std::vector<std::string> GetCertInfo() { return response.GetCertInfo(); }*/
    };

    class CryptoCompareRequest {
    private:
        cpr::Url request;
        std::unordered_map<RequestParam, std::string> params;

    public:
        CryptoCompareRequest(const std::initializer_list<RequestParam>& ls) : request("") {
            for (const auto& param : ls) {
                params[param] = request_params[static_cast<int>(param)];
            }
        }
        explicit CryptoCompareRequest(const std::vector<RequestParam>& v) : request("") {
            for (const auto& param : v) {
                params[param] = request_params[static_cast<int>(param)];
            }
        }

        CryptoCompareResponse send_request() const;

        virtual bool construct_request(const std::unordered_map<RequestParam, std::string>& url_params);

        virtual bool is_valid() const;
    };

    class CCPriceRequest : public CryptoCompareRequest {
    public:
        CCPriceRequest(const std::initializer_list<RequestParam>& ls) : CryptoCompareRequest(ls) {}
    };
    class CCPriceReponse : public CryptoCompareResponse {

    };

    class CCHistoricalRequest : public CryptoCompareRequest {

    };
    class CCHistoricalResponse : public CryptoCompareResponse {

    };

    class CCBlockchainRequest : public CryptoCompareRequest {

    };
    class CCBlockchainResponse : public CryptoCompareResponse {

    };

    class CCTradingSignalsRequest : public CryptoCompareRequest {};
    class CCTradingSignalsResponse : public CryptoCompareResponse {};

    class CCPairMappingRequest : public CryptoCompareRequest {};
    class CCPairMappingResponse : public CryptoCompareResponse {};

} // namespace price_query

#endif //CRYPTOTRACKER_PRICE_QUERY_H
