#pragma once

#include <stdexcept>
#include <cmath>
#include <cstring>
#include <utility>
#include <tuple>

namespace SiriusFM
{
    template <class Diffusion1D,
              class AProvider,
              class BProvider,
              class AssetClassA,
              class AssetClassB>
    class MCEngine1D
    {
    private:
        long const m_MaxL;          // Max PathLength
        long const m_MaxP;          // Max N Paths
        double* const m_paths;
        double* const m_ts;
        long m_L;                   //m_L <= m_MaxL
        long m_P;                   //m_P <= m_MaxP
        double m_tau;               // TimeStep as YearFraction
        double m_t0;                // 2021
        Diffusion1D const* m_diff;
        AProvider const* m_irp;
        BProvider const* m_drp;
        AssetClassA m_a;            // Asset A
        AssetClassB m_b;            // Asset B
        bool m_isRN;                // Risk-Neutral Trend
    public:
        MCEngine1D (long a_MaxL, long a_MaxP)
        : m_MaxL(a_MaxL),
          m_MaxP(a_MaxP),
          m_paths(new double[m_MaxL * m_MaxP]),
          m_ts(new double[a_MaxL]),
          m_L(0),
          m_P(0),
          m_tau(0),
          m_t0(0),
          m_diff(nullptr),
          m_irp(nullptr),
          m_drp(nullptr),
          m_a(AssetClassA::UNDEFINED),
          m_b(AssetClassB::UNDEFINED),
          m_isRN(false)
        {
            if (a_MaxL<=0) throw std::invalid_argument("non-positive arg a_MaxL in MCEngine1D constructor");
            if (a_MaxP<=0) throw std::invalid_argument("non-positive arg a_MaxP in MCEngine1D constructor");
            memset(m_paths, 0, sizeof(m_paths));
        }

        ~MCEngine1D()
        {
            delete[] m_paths;
            delete[] m_ts;
        }

        MCEngine1D  (const MCEngine1D &) = delete;

        MCEngine1D& operator= (const MCEngine1D &) = delete;

        template <bool IsRN>
        void Simulate(time_t a_t0,    // Current (pricing) Time
                      time_t a_T,      // Expiration Time
                      int a_tau_min,
                      long a_P,
                      Diffusion1D const* a_diff,
                      AProvider const* a_rateA,
                      BProvider const* a_rateB,
                      AssetClassA a_A,
                      AssetClassB a_B
                    );

        std::tuple<long, long, double const*, double const*> GetPaths() const
        {
            return (m_L <= 0 || m_P <= 0)
            ? std::make_tuple(0, 0, nullptr, nullptr)
            : std::make_tuple(m_L, m_P, m_paths, m_ts);
        }
    };
}
