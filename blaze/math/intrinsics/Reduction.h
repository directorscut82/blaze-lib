//=================================================================================================
/*!
//  \file blaze/math/intrinsics/Reduction.h
//  \brief Header file for the intrinisc reduction functionality
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_INTRINSICS_REDUCTION_H_
#define _BLAZE_MATH_INTRINSICS_REDUCTION_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/intrinsics/BasicTypes.h>
#include <blaze/system/Vectorization.h>


namespace blaze {

//=================================================================================================
//
//  INTRINSIC SUM OPERATION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Returns the sum of all elements in the 16-bit integral intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline int16_t sum( const sse_int16_t& a )
{
#if BLAZE_AVX2_MODE
   const sse_int16_t b( _mm256_hadd_epi16( a.value, a.value ) );
   const sse_int16_t c( _mm256_hadd_epi16( b.value, b.value ) );
   const sse_int16_t d( _mm256_hadd_epi16( c.value, c.value ) );
   const sse_int16_t e( _mm256_hadd_epi16( d.value, d.value ) );
   return e[0];
#elif BLAZE_SSSE3_MODE
   const sse_int16_t b( _mm_hadd_epi16( a.value, a.value ) );
   const sse_int16_t c( _mm_hadd_epi16( b.value, b.value ) );
   const sse_int16_t d( _mm_hadd_epi16( c.value, c.value ) );
   return d[0];
#elif BLAZE_SSE2_MODE
   return a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7];
#else
   return a.value;
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the sum of all elements in the 32-bit integral intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline int32_t sum( const sse_int32_t& a )
{
#if BLAZE_MIC_MODE
   return _mm512_reduce_add_epi32( a.value );
#elif BLAZE_AVX2_MODE
   const sse_int32_t b( _mm256_hadd_epi32( a.value, a.value ) );
   const sse_int32_t c( _mm256_hadd_epi32( b.value, b.value ) );
   const sse_int32_t d( _mm256_hadd_epi32( c.value, c.value ) );
   return d[0];
#elif BLAZE_SSSE3_MODE
   const sse_int32_t b( _mm_hadd_epi32( a.value, a.value ) );
   const sse_int32_t c( _mm_hadd_epi32( b.value, b.value ) );
   return c[0];
#elif BLAZE_SSE2_MODE
   return a[0] + a[1] + a[2] + a[3];
#else
   return a.value;
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the sum of all elements in the single precision floating point intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline float sum( const sse_float_t& a )
{
#if BLAZE_MIC_MODE
   return _mm512_reduce_add_ps( a.value );
#elif BLAZE_AVX_MODE
   const sse_float_t b( _mm256_hadd_ps( a.value, a.value ) );
   const sse_float_t c( _mm256_hadd_ps( b.value, b.value ) );
   const sse_float_t d( _mm256_hadd_ps( c.value, c.value ) );
   return d[0];
#elif BLAZE_SSE3_MODE
   const sse_float_t b( _mm_hadd_ps( a.value, a.value ) );
   const sse_float_t c( _mm_hadd_ps( b.value, b.value ) );
   return c[0];
#elif BLAZE_SSE_MODE
   return a[0] + a[1] + a[2] + a[3];
#else
   return a.value;
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the sum of all elements in the double precision floating point intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline double sum( const sse_double_t& a )
{
#if BLAZE_MIC_MODE
   return _mm512_reduce_add_pd( a.value );
#elif BLAZE_AVX_MODE
   const sse_double_t b( _mm256_hadd_pd( a.value, a.value ) );
   const sse_double_t c( _mm256_hadd_pd( b.value, b.value ) );
   return c[0];
#elif BLAZE_SSE3_MODE
   const sse_double_t b( _mm_hadd_pd( a.value, a.value ) );
   return b[0];
#elif BLAZE_SSE2_MODE
   return a[0] + a[1];
#else
   return a.value;
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the sum of all elements in the single precision complex intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline complex<float> sum( const sse_cfloat_t& a )
{
#if BLAZE_AVX_MODE
   return complex<float>( a[0] + a[1] + a[2] + a[3] );
#elif BLAZE_SSE_MODE
   return complex<float>( a[0] + a[1] );
#else
   return a.value;
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns the sum of all elements in the double precision complex intrinsic vector.
// \ingroup intrinsics
//
// \param a The vector to be sumed up.
// \return The sum of all vector elements.
*/
inline complex<double> sum( const sse_cdouble_t& a )
{
#if BLAZE_AVX_MODE
   return complex<double>( a[0] + a[1] );
#elif BLAZE_SSE2_MODE
   return a[0];
#else
   return a.value;
#endif
}
//*************************************************************************************************

} // namespace blaze

#endif
