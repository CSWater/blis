/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

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

#ifndef BLIS_KERNEL_MACRO_DEFS_H
#define BLIS_KERNEL_MACRO_DEFS_H


// -- Define default threading parameters --------------------------------------

#ifndef BLIS_DEFAULT_M_THREAD_RATIO
#define BLIS_DEFAULT_M_THREAD_RATIO 2
#endif

#ifndef BLIS_DEFAULT_N_THREAD_RATIO
#define BLIS_DEFAULT_N_THREAD_RATIO 1
#endif

#ifndef BLIS_DEFAULT_MR_THREAD_MAX
#define BLIS_DEFAULT_MR_THREAD_MAX 1
#endif

#ifndef BLIS_DEFAULT_NR_THREAD_MAX
#define BLIS_DEFAULT_NR_THREAD_MAX 4
#endif


// -- Memory allocation --------------------------------------------------------

// hbwmalloc.h provides hbw_malloc() and hbw_free() on systems with
// libmemkind. But disable use of libmemkind if BLIS_DISABLE_MEMKIND
// was explicitly defined.
#ifdef BLIS_DISABLE_MEMKIND
  #undef BLIS_ENABLE_MEMKIND
#endif
#ifdef BLIS_ENABLE_MEMKIND
  #include <hbwmalloc.h>
#endif

// Memory allocation functions. These macros define the three types of
// malloc()-style functions, and their free() counterparts: one for each
// type of memory to be allocated.
// NOTE: ANY ALTERNATIVE TO malloc()/free() USED FOR ANY OF THE FOLLOWING
// THREE PAIRS OF MACROS MUST USE THE SAME FUNCTION PROTOTYPE AS malloc()
// and free():
//
//   void* malloc( size_t size );
//   void  free( void* p );
//

// This allocation function is called to allocate memory for blocks within
// BLIS's internal memory pools.
#ifndef BLIS_MALLOC_POOL
  // If use of libmemkind was enabled at configure-time, the default
  // memory allocation function for memory pools should be hbw_malloc()
  // instead of malloc().
  #ifdef  BLIS_ENABLE_MEMKIND
  #define BLIS_MALLOC_POOL               hbw_malloc
  #else
  #define BLIS_MALLOC_POOL               malloc
  #endif
#endif

#ifndef BLIS_FREE_POOL
  // If use of libmemkind was enabled at configure-time, the default
  // memory deallocation function for memory pools should be hbw_free()
  // instead of free().
  #ifdef  BLIS_ENABLE_MEMKIND
  #define BLIS_FREE_POOL                 hbw_free
  #else
  #define BLIS_FREE_POOL                 free
  #endif
#endif

// This allocation function is called to allocate memory for internally-
// used objects and structures, such as control tree nodes.
#ifndef BLIS_MALLOC_INTL
#define BLIS_MALLOC_INTL                 malloc
#endif

#ifndef BLIS_FREE_INTL
#define BLIS_FREE_INTL                   free
#endif

// This allocation function is called to allocate memory for objects
// created by user-level API functions, such as bli_obj_create().
#ifndef BLIS_MALLOC_USER
#define BLIS_MALLOC_USER                 malloc
#endif

#ifndef BLIS_FREE_USER
#define BLIS_FREE_USER                   free
#endif

// -- Other system-related definitions -----------------------------------------

// Size of a virtual memory page. This is used to align blocks within the
// memory pools.
#ifndef BLIS_PAGE_SIZE
#define BLIS_PAGE_SIZE                   4096
#endif

// The maximum number of named SIMD vector registers available for use.
// When configuring with umbrella configuration families, this should be
// set to the maximum number of registers across all sub-configurations in
// the family.
#ifndef BLIS_SIMD_NUM_REGISTERS
#define BLIS_SIMD_NUM_REGISTERS          32
#endif

// The maximum size (in bytes) of each SIMD vector.
// When configuring with umbrella configuration families, this should be
// set to the maximum SIMD size across all sub-configurations in the family.
#ifndef BLIS_SIMD_SIZE
#define BLIS_SIMD_SIZE                   64
#endif

// Alignment size (in bytes) needed by the instruction set for aligned
// SIMD/vector instructions.
#ifndef BLIS_SIMD_ALIGN_SIZE
#define BLIS_SIMD_ALIGN_SIZE             BLIS_SIMD_SIZE
#endif

// The maximum size in bytes of local stack buffers within macro-kernel
// functions. These buffers are usually used to store a temporary copy
// of a single microtile. The reason we multiply by 2 is to handle induced
// methods, where we use real domain register blocksizes in units of
// complex elements. Specifically, the macro-kernels will need this larger
// micro-tile footprint, even though the virtual micro-kernels will only
// ever be writing to half (real or imaginary part) at a time.
#ifndef BLIS_STACK_BUF_MAX_SIZE
#define BLIS_STACK_BUF_MAX_SIZE          ( BLIS_SIMD_NUM_REGISTERS * \
                                           BLIS_SIMD_SIZE * 2 )
#endif

// Alignment size used to align local stack buffers within macro-kernel
// functions.
#define BLIS_STACK_BUF_ALIGN_SIZE        BLIS_SIMD_ALIGN_SIZE

// Alignment size used when allocating memory via BLIS_MALLOC_USER.
// To disable heap alignment, set this to 1.
#define BLIS_HEAP_ADDR_ALIGN_SIZE        BLIS_SIMD_ALIGN_SIZE

// Alignment size used when sizing leading dimensions of memory allocated
// via BLIS_MALLOC_USER.
#define BLIS_HEAP_STRIDE_ALIGN_SIZE      BLIS_SIMD_ALIGN_SIZE

// Alignment size used when allocating blocks to the internal memory
// pool, via BLIS_MALLOC_POOL.
#define BLIS_POOL_ADDR_ALIGN_SIZE        BLIS_PAGE_SIZE



#endif

