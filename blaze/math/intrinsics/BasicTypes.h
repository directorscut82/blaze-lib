//=================================================================================================
/*!
//  \file blaze/math/intrinsics/BasicTypes.h
//  \brief Header file for the basic intrinsic types
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

#ifndef _BLAZE_MATH_INTRINSICS_BASICTYPES_H_
#define _BLAZE_MATH_INTRINSICS_BASICTYPES_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/system/Vectorization.h>
#include <blaze/util/Complex.h>
#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  BASIC INTRINSIC TYPES
//
//=================================================================================================

//*************************************************************************************************
/*!\class blaze::sse_int8_t
// \brief Intrinsic type for 8-bit integral data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_AVX2_MODE
struct sse_int8_t {
   inline sse_int8_t() : value( _mm256_setzero_si256() ) {}
   inline sse_int8_t( __m256i v ) : value( v ) {}
   inline int8_t&       operator[]( size_t i )       { return reinterpret_cast<int8_t*      >( &value )[i]; }
   inline const int8_t& operator[]( size_t i ) const { return reinterpret_cast<const int8_t*>( &value )[i]; }
   __m256i value;  // Contains 32 8-bit integral data values
};
#elif BLAZE_SSE2_MODE
struct sse_int8_t {
   inline sse_int8_t() : value( _mm_setzero_si128() ) {}
   inline sse_int8_t( __m128i v ) : value( v ) {}
   inline int8_t&       operator[]( size_t i )       { return reinterpret_cast<int8_t*      >( &value )[i]; }
   inline const int8_t& operator[]( size_t i ) const { return reinterpret_cast<const int8_t*>( &value )[i]; }
   __m128i value;  // Contains 16 8-bit integral data values
};
#else
struct sse_int8_t {
   inline sse_int8_t() : value( 0 ) {}
   inline sse_int8_t( int8_t v ) : value( v ) {}
   inline int8_t&       operator[]( size_t /*i*/ )       { return value; }
   inline const int8_t& operator[]( size_t /*i*/ ) const { return value; }
   int8_t value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_int16_t
// \brief Intrinsic type for 16-bit integral data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_AVX2_MODE
struct sse_int16_t {
   inline sse_int16_t() : value( _mm256_setzero_si256() ) {}
   inline sse_int16_t( __m256i v ) : value( v ) {}
   inline int16_t&       operator[]( size_t i )       { return reinterpret_cast<int16_t*      >( &value )[i]; }
   inline const int16_t& operator[]( size_t i ) const { return reinterpret_cast<const int16_t*>( &value )[i]; }
   __m256i value;  // Contains 16 16-bit integral data values
};
#elif BLAZE_SSE2_MODE
struct sse_int16_t {
   inline sse_int16_t() : value( _mm_setzero_si128() ) {}
   inline sse_int16_t( __m128i v ) : value( v ) {}
   inline int16_t&       operator[]( size_t i )       { return reinterpret_cast<int16_t*      >( &value )[i]; }
   inline const int16_t& operator[]( size_t i ) const { return reinterpret_cast<const int16_t*>( &value )[i]; }
   __m128i value;  // Contains 8 16-bit integral data values
};
#else
struct sse_int16_t {
   inline sse_int16_t() : value( 0 ) {}
   inline sse_int16_t( int16_t v ) : value( v ) {}
   inline int16_t&       operator[]( size_t /*i*/ )       { return value; }
   inline const int16_t& operator[]( size_t /*i*/ ) const { return value; }
   int16_t value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_int32_t
// \brief Intrinsic type for 32-bit integral data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct sse_int32_t {
   inline sse_int32_t() : value( _mm512_setzero_epi32() ) {}
   inline sse_int32_t( __m512i v ) : value( v ) {}
   inline int32_t&       operator[]( size_t i )       { return reinterpret_cast<int32_t*      >( &value )[i]; }
   inline const int32_t& operator[]( size_t i ) const { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m512i value;  // Contains 16 32-bit integral data values
};
#elif BLAZE_AVX2_MODE
struct sse_int32_t {
   inline sse_int32_t() : value( _mm256_setzero_si256() ) {}
   inline sse_int32_t( __m256i v ) : value( v ) {}
   inline int32_t&       operator[]( size_t i )       { return reinterpret_cast<int32_t*      >( &value )[i]; }
   inline const int32_t& operator[]( size_t i ) const { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m256i value;  // Contains 8 32-bit integral data values
};
#elif BLAZE_SSE2_MODE
struct sse_int32_t {
   inline sse_int32_t() : value( _mm_setzero_si128() ) {}
   inline sse_int32_t( __m128i v ) : value( v ) {}
   inline int32_t&       operator[]( size_t i )       { return reinterpret_cast<int32_t*      >( &value )[i]; }
   inline const int32_t& operator[]( size_t i ) const { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m128i value;  // Contains 4 32-bit integral data values
};
#else
struct sse_int32_t {
   inline sse_int32_t() : value( 0 ) {}
   inline sse_int32_t( int32_t v ) : value( v ) {}
   inline int32_t&       operator[]( size_t /*i*/ )       { return value; }
   inline const int32_t& operator[]( size_t /*i*/ ) const { return value; }
   int32_t value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_int64_t
// \brief Intrinsic type for 64-bit integral data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct sse_int64_t {
   inline sse_int64_t() : value( _mm512_setzero_epi32() ) {}
   inline sse_int64_t( __m512i v ) : value( v ) {}
   inline int64_t&       operator[]( size_t i )       { return reinterpret_cast<int64_t*      >( &value )[i]; }
   inline const int64_t& operator[]( size_t i ) const { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m512i value;  // Contains 8 64-bit integral data values
};
#elif BLAZE_AVX2_MODE
struct sse_int64_t {
   inline sse_int64_t() : value( _mm256_setzero_si256() ) {}
   inline sse_int64_t( __m256i v ) : value( v ) {}
   inline int64_t&       operator[]( size_t i )       { return reinterpret_cast<int64_t*      >( &value )[i]; }
   inline const int64_t& operator[]( size_t i ) const { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m256i value;  // Contains 4 64-bit integral data values
};
#elif BLAZE_SSE2_MODE
struct sse_int64_t {
   inline sse_int64_t() : value( _mm_setzero_si128() ) {}
   inline sse_int64_t( __m128i v ) : value( v ) {}
   inline int64_t&       operator[]( size_t i )       { return reinterpret_cast<int64_t*      >( &value )[i]; }
   inline const int64_t& operator[]( size_t i ) const { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m128i value;  // Contains 2 64-bit integral data values
};
#else
struct sse_int64_t {
   inline sse_int64_t() : value( 0 ) {}
   inline sse_int64_t( int64_t v ) : value( v ) {}
   inline int64_t&       operator[]( size_t /*i*/ )       { return value; }
   inline const int64_t& operator[]( size_t /*i*/ ) const { return value; }
   int64_t value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_float_t
// \brief Intrinsic type for 32-bit single precision floating point data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct sse_float_t {
   inline sse_float_t() : value( _mm512_setzero_ps() ) {}
   inline sse_float_t( __m512 v ) : value( v ) {}
   inline float&       operator[]( size_t i )       { return reinterpret_cast<float*      >( &value )[i]; }
   inline const float& operator[]( size_t i ) const { return reinterpret_cast<const float*>( &value )[i]; }
   __m512 value;  // Contains 16 32-bit single precision floating point values
};
#elif BLAZE_AVX_MODE
struct sse_float_t {
   inline sse_float_t() : value( _mm256_setzero_ps() ) {}
   inline sse_float_t( __m256 v ) : value( v ) {}
   inline float&       operator[]( size_t i )       { return reinterpret_cast<float*      >( &value )[i]; }
   inline const float& operator[]( size_t i ) const { return reinterpret_cast<const float*>( &value )[i]; }
   __m256 value;  // Contains 8 32-bit single precision floating point values
};
#elif BLAZE_SSE_MODE
struct sse_float_t {
   inline sse_float_t() : value( _mm_setzero_ps() ) {}
   inline sse_float_t( __m128 v ) : value( v ) {}
   inline float&       operator[]( size_t i )       { return reinterpret_cast<float*      >( &value )[i]; }
   inline const float& operator[]( size_t i ) const { return reinterpret_cast<const float*>( &value )[i]; }
   __m128 value;  // Contains 4 32-bit single precision floating point values
};
#else
struct sse_float_t {
   inline sse_float_t() : value( 0.0F ) {}
   inline sse_float_t( float v ) : value( v ) {}
   inline float&       operator[]( size_t /*i*/ )       { return value; }
   inline const float& operator[]( size_t /*i*/ ) const { return value; }
   float value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_double_t
// \brief Intrinsic type for 64-bit double precision floating point data values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct sse_double_t {
   inline sse_double_t() : value( _mm512_setzero_pd() ) {}
   inline sse_double_t( __m512d v ) : value( v ) {}
   inline double&       operator[]( size_t i )       { return reinterpret_cast<double*      >( &value )[i]; }
   inline const double& operator[]( size_t i ) const { return reinterpret_cast<const double*>( &value )[i]; }
   __m512d value;  // Contains 8 64-bit double precision floating point values
};
#elif BLAZE_AVX_MODE
struct sse_double_t {
   inline sse_double_t() : value( _mm256_setzero_pd() ) {}
   inline sse_double_t( __m256d v ) : value( v ) {}
   inline double&       operator[]( size_t i )       { return reinterpret_cast<double*      >( &value )[i]; }
   inline const double& operator[]( size_t i ) const { return reinterpret_cast<const double*>( &value )[i]; }
   __m256d value;  // Contains 4 64-bit double precision floating point values
};
#elif BLAZE_SSE2_MODE
struct sse_double_t {
   inline sse_double_t() : value( _mm_setzero_pd() ) {}
   inline sse_double_t( __m128d v ) : value( v ) {}
   inline double&       operator[]( size_t i )       { return reinterpret_cast<double*      >( &value )[i]; }
   inline const double& operator[]( size_t i ) const { return reinterpret_cast<const double*>( &value )[i]; }
   __m128d value;  // Contains 2 64-bit double precision floating point values
};
#else
struct sse_double_t {
   inline sse_double_t() : value( 0.0 ) {}
   inline sse_double_t( double v ) : value( v ) {}
   inline double&       operator[]( size_t /*i*/ )       { return value; }
   inline const double& operator[]( size_t /*i*/ ) const { return value; }
   double value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_cfloat_t
// \brief Intrinsic type for 32-bit single precision complex values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_AVX_MODE
struct sse_cfloat_t {
   inline sse_cfloat_t() : value( _mm256_setzero_ps() ) {}
   inline sse_cfloat_t( __m256 v ) : value( v ) {}
   inline complex<float>&       operator[]( size_t i )       { return reinterpret_cast<complex<float>*      >( &value )[i]; }
   inline const complex<float>& operator[]( size_t i ) const { return reinterpret_cast<const complex<float>*>( &value )[i]; }
   __m256 value;  // Contains 4 32-bit single precision complex values
};
#elif BLAZE_SSE_MODE
struct sse_cfloat_t {
   inline sse_cfloat_t() : value( _mm_setzero_ps() ) {}
   inline sse_cfloat_t( __m128 v ) : value( v ) {}
   inline complex<float>&       operator[]( size_t i )       { return reinterpret_cast<complex<float>*      >( &value )[i]; }
   inline const complex<float>& operator[]( size_t i ) const { return reinterpret_cast<const complex<float>*>( &value )[i]; }
   __m128 value;  // Contains 2 32-bit single precision complex values
};
#else
struct sse_cfloat_t {
   inline sse_cfloat_t() : value( 0.0F, 0.0F ) {}
   inline sse_cfloat_t( complex<float> v ) : value( v ) {}
   inline complex<float>&       operator[]( size_t /*i*/ )       { return value; }
   inline const complex<float>& operator[]( size_t /*i*/ ) const { return value; }
   complex<float> value;
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::sse_cdouble_t
// \brief Intrinsic type for 64-bit double precision complex values.
// \ingroup intrinsics
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_AVX_MODE
struct sse_cdouble_t {
   inline sse_cdouble_t() : value( _mm256_setzero_pd() ) {}
   inline sse_cdouble_t( __m256d v ) : value( v ) {}
   inline complex<double>&       operator[]( size_t i )       { return reinterpret_cast<complex<double>*      >( &value )[i]; }
   inline const complex<double>& operator[]( size_t i ) const { return reinterpret_cast<const complex<double>*>( &value )[i]; }
   __m256d value;  // Contains 2 64-bit double precision complex value
};
#elif BLAZE_SSE2_MODE
struct sse_cdouble_t {
   inline sse_cdouble_t() : value( _mm_setzero_pd() ) {}
   inline sse_cdouble_t( __m128d v ) : value( v ) {}
   inline complex<double>&       operator[]( size_t i )       { return reinterpret_cast<complex<double>*      >( &value )[i]; }
   inline const complex<double>& operator[]( size_t i ) const { return reinterpret_cast<const complex<double>*>( &value )[i]; }
   __m128d value;  // Contains 1 64-bit double precision complex value
};
#else
struct sse_cdouble_t {
   inline sse_cdouble_t() : value( 0.0, 0.0 ) {}
   inline sse_cdouble_t( complex<double> v ) : value( v ) {}
   inline complex<double>&       operator[]( size_t /*i*/ )       { return value; }
   inline const complex<double>& operator[]( size_t /*i*/ ) const { return value; }
   complex<double> value;
};
#endif
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
