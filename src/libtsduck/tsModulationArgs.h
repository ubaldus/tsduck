//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2019, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Modulation parameters for tuners and their command-line definitions.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsArgsSupplierInterface.h"
#include "tsVariable.h"
#include "tsModulation.h"
#include "tsLNB.h"

namespace ts {
    //!
    //! Modulation parameters for tuners and their command-line definitions.
    //! @ingroup hardware
    //!
    //! All values may be "set" or "unset", depending on command line arguments.
    //! All options for all types of tuners are included here.
    //!
    class TSDUCKDLL ModulationArgs : public ArgsSupplierInterface
    {
    public:
        //!
        //! Delivery system (DS_DVB_*).
        //! Applies to all tuners. When unset, the default delivery system for that tuner is used.
        //!
        Variable<DeliverySystem> delivery_system;
        //!
        //! Frequency in Hz.
        //! Applies to all tuners. This is a mandatory parameter.
        //!
        Variable<uint64_t> frequency;
        //!
        //! Polarity.
        //! Applies to: DVB-S/S2, ISDB-S.
        //!
        Variable<Polarization> polarity;
        //!
        //! Default value for polarity.
        //!
        static constexpr Polarization DEFAULT_POLARITY = POL_VERTICAL;
        //!
        //! Local dish LNB for frequency adjustment.
        //! Applies to: DVB-S/S2, ISDB-S.
        //!
        Variable<LNB> lnb;
        //!
        //! Spectral inversion.
        //! Applies to: DVB-T/T2, DVB-S/S2, DVB-C (A,B,C), ISDB-T, ISDB-S.
        //!
        Variable<SpectralInversion> inversion;
        //!
        //! Default value for inversion.
        //!
        static constexpr SpectralInversion DEFAULT_INVERSION = SPINV_AUTO;
        //!
        //! Symbol rate.
        //! Applies to: DVB-S/S2, DVB-C (A,C), ISDB-S.
        //!
        Variable<uint32_t> symbol_rate;
        //!
        //! Default value for symbol_rate on satellite.
        //!
        static constexpr uint32_t DEFAULT_SYMBOL_RATE_DVBS = 27500000;
        //!
        //! Default value for symbol_rate on cable.
        //!
        static constexpr uint32_t DEFAULT_SYMBOL_RATE_DVBC = 6900000;
        //!
        //! Error correction.
        //! Applies to: DVB-S/S2, DVB-C (A,C), ISDB-S.
        //!
        Variable<InnerFEC> inner_fec;
        //!
        //! Default value for inner_fec.
        //!
        static constexpr InnerFEC DEFAULT_INNER_FEC = FEC_AUTO;
        //!
        //! For DiSeqC (usually 0).
        //! Applies to: DVB-S/S2, ISDB-S.
        //!
        Variable<size_t> satellite_number;
        //!
        //! Default value for satellite_number.
        //!
        static constexpr size_t DEFAULT_SATELLITE_NUMBER = 0;
        //!
        //! Constellation or modulation type.
        //! Applies to: DVB-T/T2, DVB-S2/Turbo, DVB-C (A,B,C), ATSC.
        //!
        Variable<Modulation> modulation;
        //!
        //! Default value for modulation on satellite.
        //!
        static constexpr Modulation DEFAULT_MODULATION_DVBS = QPSK;
        //!
        //! Default value for modulation on cable.
        //!
        static constexpr Modulation DEFAULT_MODULATION_DVBC = QAM_64;
        //!
        //! Bandwidth.
        //! Applies to: DVB-T/T2, ATSC, ISDB-T.
        //!
        Variable<BandWidth> bandwidth;
        //!
        //! High priority stream code rate.
        //! Applies to: DVB-T/T2.
        //!
        Variable<InnerFEC> fec_hp;
        //!
        //! Low priority stream code rate.
        //! Applies to: DVB-T/T2.
        //!
        Variable<InnerFEC> fec_lp;
        //!
        //! Transmission mode.
        //! Applies to: DVB-T/T2, ISDB-T.
        //!
        Variable<TransmissionMode> transmission_mode;
        //!
        //! Guard interval.
        //! Applies to: DVB-T/T2, ISDB-T.
        //!
        Variable<GuardInterval> guard_interval;
        //!
        //! Hierarchy.
        //! Applies to: DVB-T/T2.
        //!
        Variable<Hierarchy> hierarchy;
        //!
        //! Presence of pilots.
        //! Applies to: DVB-S2.
        //!
        Variable<Pilot> pilots;
        //!
        //! Default value for pilots.
        //!
        static constexpr Pilot DEFAULT_PILOTS = PILOT_OFF;
        //!
        //! Roll-off factor.
        //! Applies to: DVB-S2.
        //!
        Variable<RollOff> roll_off;
        //!
        //! Default value for roll_off.
        //! Implied value in DVB-S, default for DVB-S2.
        //!
        static constexpr RollOff DEFAULT_ROLL_OFF = ROLLOFF_35;
        //!
        //! Physical Layer Pipe (PLP) identification.
        //! Applies to: DVB-T2.
        //!
        Variable<uint32_t> plp;
        //!
        //! Input Stream Id (ISI) (DVB-S2 only).
        //! Applies to: DVB-S2.
        //!
        Variable<uint32_t> isi;
        //!
        //! Default value for input stream id.
        //!
        static constexpr uint32_t DEFAULT_ISI = ISI_DISABLE;
        //!
        //! Physical Layer Scrambling (PLS) code (DVB-S2 only).
        //! Applies to: DVB-S2.
        //!
        Variable<uint32_t> pls_code;
        //!
        //! Default value for PLS code.
        //!
        static constexpr uint32_t DEFAULT_PLS_CODE = 0;
        //!
        //! Physical Layer Scrambling (PLS) mode (DVB-S2 only).
        //! Applies to: DVB-S2.
        //!
        Variable<PLSMode> pls_mode;
        //!
        //! Default value for PLS mode.
        //!
        static constexpr PLSMode DEFAULT_PLS_MODE = PLS_ROOT;

        //@@  Missing values for ISDB-T:
        //@@    DTV_ISDBT_LAYER_ENABLED
        //@@    DTV_ISDBT_PARTIAL_RECEPTION
        //@@    DTV_ISDBT_SOUND_BROADCASTING
        //@@    DTV_ISDBT_SB_SUBCHANNEL_ID
        //@@    DTV_ISDBT_SB_SEGMENT_IDX
        //@@    DTV_ISDBT_SB_SEGMENT_COUNT
        //@@    DTV_ISDBT_LAYERA_FEC
        //@@    DTV_ISDBT_LAYERA_MODULATION
        //@@    DTV_ISDBT_LAYERA_SEGMENT_COUNT
        //@@    DTV_ISDBT_LAYERA_TIME_INTERLEAVING
        //@@    DTV_ISDBT_LAYERB_FEC
        //@@    DTV_ISDBT_LAYERB_MODULATION
        //@@    DTV_ISDBT_LAYERB_SEGMENT_COUNT
        //@@    DTV_ISDBT_LAYERB_TIME_INTERLEAVING
        //@@    DTV_ISDBT_LAYERC_FEC
        //@@    DTV_ISDBT_LAYERC_MODULATION
        //@@    DTV_ISDBT_LAYERC_SEGMENT_COUNT
        //@@    DTV_ISDBT_LAYERC_TIME_INTERLEAVING
        //@@
        //@@  Missing values for ISDB-S:
        //@@    DTV_ISDBS_TS_ID

        //!
        //! Default constructor.
        //! @param [in] allow_short_options If true, allow short one-letter options.
        //!
        ModulationArgs(bool allow_short_options = true);

        // Implementation of ArgsSupplierInterface.
        virtual void defineArgs(Args& args) const override;
        virtual bool loadArgs(DuckContext& duck, Args& args) override;

        //!
        //! Reset all values, they become "unset"
        //!
        virtual void reset();

        //!
        //! Check if any modulation options is set.
        //! @return True if any modulation options is set.
        //!
        bool hasModulationArgs() const;

    protected:
        const bool _allow_short_options;
    };
}
