#ifndef BOOST_HASH2_DETAIL_READ_HPP_INCLUDED
#define BOOST_HASH2_DETAIL_READ_HPP_INCLUDED

// Copyright 2017, 2018 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.

#include <boost/hash2/byte_type.hpp>
#include <boost/cstdint.hpp>
#include <boost/config.hpp>
#include <cstring>

namespace boost
{
namespace hash2
{
namespace detail
{

BOOST_FORCEINLINE boost::uint32_t read32le( byte_type const * p )
{
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)

    boost::uint32_t v;
    std::memcpy( &v, p, sizeof(v) );
    return v;

#else

    return
        static_cast<boost::uint32_t>( p[0] ) +
        ( static_cast<boost::uint32_t>( p[1] ) <<  8 ) +
        ( static_cast<boost::uint32_t>( p[2] ) << 16 ) +
        ( static_cast<boost::uint32_t>( p[3] ) << 24 );

#endif
}

BOOST_FORCEINLINE boost::uint64_t read64le( byte_type const * p )
{
#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)

    boost::uint64_t v;
    std::memcpy( &v, p, sizeof(v) );
    return v;

#else

    return
        static_cast<boost::uint64_t>( p[0] ) +
        ( static_cast<boost::uint64_t>( p[1] ) <<  8 ) +
        ( static_cast<boost::uint64_t>( p[2] ) << 16 ) +
        ( static_cast<boost::uint64_t>( p[3] ) << 24 ) +
        ( static_cast<boost::uint64_t>( p[4] ) << 32 ) +
        ( static_cast<boost::uint64_t>( p[5] ) << 40 ) +
        ( static_cast<boost::uint64_t>( p[6] ) << 48 ) +
        ( static_cast<boost::uint64_t>( p[7] ) << 56 );

#endif
}

BOOST_FORCEINLINE boost::uint32_t read32be( byte_type const * p )
{
    return
        static_cast<boost::uint32_t>( p[3] ) +
        ( static_cast<boost::uint32_t>( p[2] ) <<  8 ) +
        ( static_cast<boost::uint32_t>( p[1] ) << 16 ) +
        ( static_cast<boost::uint32_t>( p[0] ) << 24 );
}

BOOST_FORCEINLINE boost::uint64_t read64be( byte_type const * p )
{
    return
        static_cast<boost::uint64_t>( p[7] ) +
        ( static_cast<boost::uint64_t>( p[6] ) <<  8 ) +
        ( static_cast<boost::uint64_t>( p[5] ) << 16 ) +
        ( static_cast<boost::uint64_t>( p[4] ) << 24 ) +
        ( static_cast<boost::uint64_t>( p[3] ) << 32 ) +
        ( static_cast<boost::uint64_t>( p[2] ) << 40 ) +
        ( static_cast<boost::uint64_t>( p[1] ) << 48 ) +
        ( static_cast<boost::uint64_t>( p[0] ) << 56 );
}

} // namespace detail
} // namespace hash2
} // namespace boost

#endif // #ifndef BOOST_HASH2_DETAIL_READ_HPP_INCLUDED
