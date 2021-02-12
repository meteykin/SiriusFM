#pragma once

#include <stdexcept>
#include <cmath>
#include <cstring>

namespace SiriusFM
{
    enum class CcyE
    {
        UNDEFINED = -1,
        USD = 0,
        EUR = 1,
        GBP = 2,
        CHF = 3,
        RUB = 4,
        N = 5
    };

    inline char const* CcyE2Str(CcyE a_ccy)
    {
        switch (a_ccy)
        {
            case CcyE::USD: return "USD";
            case CcyE::EUR: return "EUR";
            case CcyE::GBP: return "GBP";
            case CcyE::CHF: return "CHF";
            case CcyE::RUB: return "RUB";
            default: throw std::invalid_argument("invalid arg in CcyE2Str");
        }
    }

    inline CcyE Str2CcyE (char const* a_str)
        {
            if (strcmp(a_str, "USD") == 0)
                return CcyE::USD;
            else
            if (strcmp(a_str, "EUR") == 0)
                return CcyE::EUR;
            else
            if (strcmp(a_str, "GBP") == 0)
                return CcyE::GBP;
            else
            if (strcmp(a_str, "CHF") == 0)
                return CcyE::CHF;
            else
            if (strcmp(a_str, "RUB") == 0)
                return CcyE::RUB;
            else
                throw std::invalid_argument("invalid arg in Str2CcyE");
        }

    enum class IRModeE
    {
        Const = 0,
        FwdCurve = 1,
        Stoch = 2
    };

    template <IRModeE IRM>
    class IRProvider;
}
