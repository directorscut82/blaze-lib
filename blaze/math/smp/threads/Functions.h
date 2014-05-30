//=================================================================================================
/*!
//  \file blaze/math/smp/threads/Functions.h
//  \brief Header file for the C++11 and Boost thread-based SMP utility functions
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_SMP_THREADS_FUNCTIONS_H_
#define _BLAZE_MATH_SMP_THREADS_FUNCTIONS_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <stdexcept>
#include <blaze/math/smp/threads/ThreadBackend.h>
#include <blaze/system/SMP.h>
#include <blaze/util/StaticAssert.h>


namespace blaze {

//=================================================================================================
//
//  SMP UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns the number of threads used for thread parallel operations.
// \ingroup smp
//
// \return The number of threads used for thread parallel operations.
//
// Via this function the number of threads used for thread parallel operations can be queried.
*/
inline size_t getNumThreads()
{
   return TheThreadBackend::size();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Sets the number of threads to be used for thread parallel operations.
// \ingroup smp
//
// \param number The given number of threads \f$[1..maxThreads]\f$.
// \return void
// \exception std::invalid_argument Invalid number of threads.
//
// Via this function the maximum number of threads for thread parallel operations can be specified.
// Note that the given \a number must be in the range \f$[1..maxThreads]\f$. In case an invalid
// number of threads is specified, a \a std::invalid_argument exception is thrown.
*/
inline size_t setNumThreads( size_t number )
{
   if( number == 0UL || number > maxThreads )
      throw std::invalid_argument( "Invalid number of threads" );

   TheThreadBackend::resize( number );
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  COMPILE TIME CONSTRAINTS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
namespace {

BLAZE_STATIC_ASSERT( BLAZE_CPP_THREADS_PARALLEL_MODE || BLAZE_BOOST_THREADS_PARALLEL_MODE );

}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif