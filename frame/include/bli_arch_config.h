/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin
   Copyright (C) 2016 Hewlett Packard Enterprise Development LP

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef BLIS_ARCH_CONFIG_H
#define BLIS_ARCH_CONFIG_H

//
// -- Context initialization prototypes ----------------------------------------
//

// -- Intel64 architectures --

#ifdef BLIS_CONFIG_KNL
CNTX_INIT_PROTS( knl )
#endif
#ifdef BLIS_CONFIG_KNC
CNTX_INIT_PROTS( knc )
#endif
#ifdef BLIS_CONFIG_HASWELL
CNTX_INIT_PROTS( haswell )
#endif
#ifdef BLIS_CONFIG_SANDYBRIDGE
CNTX_INIT_PROTS( sandybridge )
#endif
#ifdef BLIS_CONFIG_PENRYN
CNTX_INIT_PROTS( penryn )
#endif

// -- AMD64 architectures --

#ifdef BLIS_CONFIG_ZEN
CNTX_INIT_PROTS( zen )
#endif
#ifdef BLIS_CONFIG_EXCAVATOR
CNTX_INIT_PROTS( excavator )
#endif
#ifdef BLIS_CONFIG_STEAMROLLER
CNTX_INIT_PROTS( steamroller )
#endif
#ifdef BLIS_CONFIG_PILEDRIVER
CNTX_INIT_PROTS( piledriver )
#endif
#ifdef BLIS_CONFIG_BULLDOZER
CNTX_INIT_PROTS( bulldozer )
#endif

// -- ARM architectures --

#ifdef BLIS_CONFIG_CORTEXA57
CNTX_INIT_PROTS( cortexa57 )
#endif
#ifdef BLIS_CONFIG_CORTEXA15
CNTX_INIT_PROTS( cortexa15 )
#endif
#ifdef BLIS_CONFIG_CORTEXA9
CNTX_INIT_PROTS( cortexa9 )
#endif

// -- IBM BG/Q --

#ifdef BLIS_CONFIG_POWER7
CNTX_INIT_PROTS( power7 )
#endif
#ifdef BLIS_CONFIG_BGQ
CNTX_INIT_PROTS( bgq )
#endif

// -- Generic --

#ifdef BLIS_CONFIG_GENERIC
CNTX_INIT_PROTS( generic )
#endif


//
// -- Architecture family-specific headers -------------------------------------
//

// -- x86_64 families --

#ifdef BLIS_FAMILY_INTEL64
#include "bli_family_intel64.h"
#endif
#ifdef BLIS_FAMILY_AMD64
#include "bli_family_amd64.h"
#endif
#ifdef BLIS_FAMILY_X86_64
#include "bli_family_x86_64.h"
#endif

// -- Intel64 architectures --

#ifdef BLIS_FAMILY_KNL
#include "bli_family_knl.h"
#endif
#ifdef BLIS_FAMILY_KNC
#include "bli_family_knc.h"
#endif
#ifdef BLIS_FAMILY_HASWELL
#include "bli_family_haswell.h"
#endif
#ifdef BLIS_FAMILY_SANDYBRIDGE
#include "bli_family_sandybridge.h"
#endif
#ifdef BLIS_FAMILY_PENRYN
#include "bli_family_penryn.h"
#endif

// -- AMD64 architectures --

#ifdef BLIS_FAMILY_ZEN
#include "bli_family_zen.h"
#endif
#ifdef BLIS_FAMILY_EXCAVATOR
#include "bli_family_excavator.h"
#endif
#ifdef BLIS_FAMILY_STEAMROLLER
#include "bli_family_steamroller.h"
#endif
#ifdef BLIS_FAMILY_PILEDRIVER
#include "bli_family_piledriver.h"
#endif
#ifdef BLIS_FAMILY_BULLDOZER
#include "bli_family_bulldozer.h"
#endif

// -- ARM architectures --

#ifdef BLIS_FAMILY_CORTEXA57
#include "bli_family_cortexa57.h"
#endif
#ifdef BLIS_FAMILY_CORTEXA15
#include "bli_family_cortexa15.h"
#endif
#ifdef BLIS_FAMILY_CORTEXA9
#include "bli_family_cortexa9.h"
#endif

// -- IBM BG/Q --

#ifdef BLIS_FAMILY_POWER7
#include "bli_family_power7.h"
#endif
#ifdef BLIS_FAMILY_BGQ
#include "bli_family_bgq.h"
#endif

// -- Generic --

#ifdef BLIS_FAMILY_GENERIC
#include "bli_family_generic.h"
#endif


//
// -- kernel set prototypes ----------------------------------------------------
//

// -- Intel64 architectures --

#ifdef BLIS_KERNELS_KNL
#include "bli_kernels_knl.h"
#endif
#ifdef BLIS_KERNELS_KNC
#include "bli_kernels_knc.h"
#endif
#ifdef BLIS_KERNELS_HASWELL
#include "bli_kernels_haswell.h"
#endif
#ifdef BLIS_KERNELS_SANDYBRIDGE
#include "bli_kernels_sandybridge.h"
#endif
#ifdef BLIS_KERNELS_PENRYN
#include "bli_kernels_penryn.h"
#endif

// -- AMD64 architectures --

//#ifdef BLIS_KERNELS_ZEN
//#include "bli_kernels_zen.h"
//#endif
//#ifdef BLIS_KERNELS_EXCAVATOR
//#include "bli_kernels_excavator.h"
//#endif
//#ifdef BLIS_KERNELS_STEAMROLLER
//#include "bli_kernels_steamroller.h"
//#endif
#ifdef BLIS_KERNELS_PILEDRIVER
#include "bli_kernels_piledriver.h"
#endif
#ifdef BLIS_KERNELS_BULLDOZER
#include "bli_kernels_bulldozer.h"
#endif

// -- ARM architectures --

#ifdef BLIS_KERNELS_ARMV8A
#include "bli_kernels_armv8a.h"
#endif
#ifdef BLIS_KERNELS_ARMV7A
#include "bli_kernels_armv7a.h"
#endif

// -- IBM BG/Q --

#ifdef BLIS_KERNELS_POWER7
#include "bli_kernels_power7.h"
#endif
#ifdef BLIS_KERNELS_BGQ
#include "bli_kernels_bgq.h"
#endif



#endif
