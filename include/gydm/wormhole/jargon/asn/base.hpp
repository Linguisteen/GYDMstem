#pragma once

#include <string>
#include <cinttypes>

#include "../../../datum/natural.hpp"

#include "identifier.hpp"

namespace GYDM {
    typedef std::basic_string<unsigned char> octets;

    bool asn_primitive_predicate(GYDM::ASNPrimitive type, const uint8_t* content, size_t offset = 0);
    bool asn_primitive_predicate(GYDM::ASNPrimitive type, const GYDM::octets& content, size_t offset = 0);
    bool asn_constructed_predicate(GYDM::ASNConstructed type, const uint8_t* content, size_t offset = 0);
    bool asn_constructed_predicate(GYDM::ASNConstructed type, const GYDM::octets& content, size_t offset = 0);

    size_t asn_length_span(size_t length);
    GYDM::octets asn_length_to_octets(size_t length);
    size_t asn_length_into_octets(size_t length, uint8_t* octects, size_t offset = 0);
    size_t asn_octets_to_length(const uint8_t* blength, size_t* offset = nullptr);
    inline size_t asn_octets_to_length(const GYDM::octets& blength, size_t* offset = nullptr) { return asn_octets_to_length(blength.c_str(), offset); }
    
    GYDM::octets asn_octets_box(uint8_t tag, const GYDM::octets& content, size_t size);
    size_t asn_octets_unbox(const uint8_t* basn, size_t* offset = nullptr);
    inline size_t asn_octets_unbox(const GYDM::octets& basn, size_t* offset = nullptr) { return asn_octets_unbox(basn.c_str(), offset); }
    GYDM::octets asn_int64_to_octets(int64_t integer, GYDM::ASNPrimitive id = ASNPrimitive::Integer);
    size_t asn_int64_into_octets(int64_t integer, uint8_t* octets, size_t offset, GYDM::ASNPrimitive id = ASNPrimitive::Integer);

    // NOTE: `asn_xxx_into_octets` does not check the boundary, please ensure that the destination is sufficient. 
    // NOTE: `asn_octets_to_xxx` does not check the tag, please ensure that the octets is really what it should be.
    inline size_t asn_boolean_span(bool b) { return 1; }
    GYDM::octets asn_boolean_to_octets(bool b);
    size_t asn_boolean_into_octets(bool b, uint8_t* octets, size_t offset = 0);
    bool asn_octets_to_boolean(const uint8_t* bbool, size_t* offset = nullptr);
    inline bool asn_octets_to_boolean(const GYDM::octets& bbool, size_t* offset = nullptr) { return asn_octets_to_boolean(bbool.c_str(), offset); }

    inline size_t asn_null_span(std::nullptr_t placeholder) { return 0; }
    GYDM::octets asn_null_to_octets(std::nullptr_t placeholder);
    size_t asn_null_into_octets(std::nullptr_t placeholder, uint8_t* octets, size_t offset = 0);
    std::nullptr_t asn_octets_to_null(const uint8_t* bnull, size_t* offset = nullptr);
    inline std::nullptr_t asn_octets_to_null(const GYDM::octets& bnull, size_t* offset = nullptr) { return asn_octets_to_null(bnull.c_str(), offset); }

    size_t asn_fixnum_span(int64_t integer);
    inline GYDM::octets asn_fixnum_to_octets(int64_t integer) { return asn_int64_to_octets(integer, ASNPrimitive::Integer); }
    inline size_t asn_fixnum_into_octets(int64_t integer, uint8_t* octets, size_t offset = 0) { return asn_int64_into_octets(integer, octets, offset, ASNPrimitive::Integer); }
    int64_t asn_octets_to_fixnum(const uint8_t* bint, size_t* offset = nullptr);
    inline int64_t asn_octets_to_fixnum(const GYDM::octets& bint, size_t* offset = nullptr) { return asn_octets_to_fixnum(bint.c_str(), offset); }

    size_t asn_flonum_span(double real);
    GYDM::octets asn_flonum_to_octets(double real);
    size_t asn_flonum_into_octets(double real, uint8_t* octets, size_t offset = 0);
    double asn_octets_to_flonum(const uint8_t* breal, size_t* offset = nullptr);
    inline double asn_octets_to_flonum(const GYDM::octets& breal, size_t* offset = nullptr) { return asn_octets_to_flonum(breal.c_str(), offset); }

    size_t asn_natural_span(GYDM::Natural& nat);
    GYDM::octets asn_natural_to_octets(GYDM::Natural& nat);
    size_t asn_natural_into_octets(GYDM::Natural& nat, uint8_t* octets, size_t offset = 0);
    GYDM::Natural asn_octets_to_natural(const uint8_t* bnat, size_t* offset = nullptr);
    inline GYDM::Natural asn_octets_to_natural(const GYDM::octets& bnat, size_t* offset = nullptr) { return asn_octets_to_natural(bnat.c_str(), offset); }

    size_t asn_ia5_span(const std::string& ia5_str);
    GYDM::octets asn_ia5_to_octets(const std::string& ia5_str);
    size_t asn_ia5_into_octets(const std::string& ia5_str, uint8_t* octets, size_t offset = 0);
    std::string asn_octets_to_ia5(const uint8_t* bia5, size_t* offset = nullptr);
    inline std::string asn_octets_to_ia5(const GYDM::octets& bia5, size_t* offset = nullptr) { return asn_octets_to_ia5(bia5.c_str(), offset); }

    size_t asn_utf8_span(const std::string& nstr);
    GYDM::octets asn_utf8_to_octets(const std::string& nstr);
    size_t asn_utf8_into_octets(const std::string& nstr, uint8_t* octets, size_t offset = 0);
    std::string asn_octets_to_utf8(const uint8_t* butf8, size_t* offset = nullptr);
    inline std::string asn_octets_to_utf8(const GYDM::octets& butf8, size_t* offset = nullptr) { return asn_octets_to_utf8(butf8.c_str(), offset); }

    inline size_t asn_span(size_t payload_span) { return 1 + asn_length_span(payload_span) + payload_span; }

    template<typename Span, typename T>
    inline size_t asn_span(Span span, T v) { return asn_span(span(v)); }

    template<class C>
    inline size_t asn_span(C instance) { return asn_span(instance->span()); }
}
