#ifndef ISOCPP2_JUNK_1_H
#define ISOCPP2_JUNK_1_H

#include "dds/dds.hpp"

#include "junk_1.h"
#include "junk_1SplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<junk_1::Msg>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "id";
    }

    static const char *getTypeName()
    {
        return "junk_1::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"junk_1\"><Struct name=\"Msg\"><Member name=\"id\"><Long/></Member>",
"<Member name=\"message\"><String/></Member><Member name=\"constraint_deadline_duetime\"><LongLong/></Member>",
"<Member name=\"constraint_freshness_gentime\"><LongLong/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(312);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __junk_1_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __junk_1_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<junk_1::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<junk_1::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(junk_1::Msg)

#endif /* ISOCPP2_JUNK_1_H */
