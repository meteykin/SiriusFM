#pragma once

#include <stdexcept>
#include <cmath>
#include <cstring>
#include <utility>
#include <tuple>

#include "Time.h"

namespace SiriusFM
{
    template <class Diffusion1D,
              class AProvider,
              class BProvider,
              class AssetClassA,
              class AssetClassB,
              class PathEvaluator>
    class MCEngine1D
    {
    private:
        long const m_MaxL;          // Max PathLength
        long const m_MaxPM;         // Max Number of Stored
        double* const m_paths;      // Stored Paths
        double* const m_ts;         // Timeline
    public:
        MCEngine1D (long a_MaxL, long a_MaxPM)
        : m_MaxL (a_MaxL),
          m_MaxPM (a_MaxPM),
          m_paths(new double[m_MaxL * m_MaxPM]),
          m_ts   (new double[a_MaxL])
        {
            if (a_MaxL<=0) throw std::invalid_argument("non-positive a_MaxL in MCEngine1D constructor");
            if (a_MaxPM<=0) throw std::invalid_argument("non-positive a_MaxPM in MCEngine1D constructor");
            memset(m_paths, 0, sizeof(m_paths));
            memset(m_ts, 0, sizeof(m_ts));
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
                      int a_tauMins,
                      long a_P,
                      bool                a_useTimerSeed,
                		  Diffusion1D const*  a_diff,
                		  AProvider const*    a_rateA,
                		  BProvider const*    a_rateB,
                		  AssetClassA         a_assetA,
                		  AssetClassB         a_assetB,
                      PathEvaluator*      a_pathEval
                    );

        /*std::tuple<long, long, double const*, double const*> GetPaths() const
        {
            return (m_L <= 0 || m_P <= 0)
            ? std::make_tuple(0, 0, nullptr, nullptr)
            : std::make_tuple(m_L, m_P, m_paths, m_ts);
        }*/
    };
}
