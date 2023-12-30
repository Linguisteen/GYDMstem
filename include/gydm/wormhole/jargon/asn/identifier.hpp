#pragma once

#include <cinttypes>

namespace GYDM {
    enum class ASNPrimitive {
        Boolean, Integer, /* BitString, OctetString, */ Null,
        /* ObjectIdentifier, ObjectDescriptor, External, */
        Real, Enumerated,
        UTF8_String, IA5_String
    };

    enum class ASNConstructed {
        Sequence
    };

    enum class ASN1TagClass { Universal, Application, ContextSpecific, Private };

    uint8_t asn_identifier_octet(uint8_t tag, bool constructed = false, GYDM::ASN1TagClass type = ASN1TagClass::Universal);

    uint8_t asn_identifier_tag(uint8_t octet);
    GYDM::ASN1TagClass asn_identifier_class(uint8_t octet);
    bool asn_identifier_constructed(uint8_t octet);

    uint8_t asn_primitive_identifier_octet(GYDM::ASNPrimitive type);
    uint8_t asn_constructed_identifier_octet(GYDM::ASNConstructed type);
}
