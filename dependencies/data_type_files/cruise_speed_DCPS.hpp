#ifndef ISOCPP2_CRUISE_SPEED_H
#define ISOCPP2_CRUISE_SPEED_H

#include "dds/dds.hpp"

#include "cruise_speed.h"
#include "cruise_speedSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<cruise_speed::Msg>
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
        return "cruise_speed::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"cruise_speed\"><Struct name=\"Msg\"><Member name=\"id\"><Long/>",
"</Member><Member name=\"curr_speed\"><Double/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(190);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __cruise_speed_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __cruise_speed_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<cruise_speed::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<cruise_speed::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(cruise_speed::Msg)

#endif /* ISOCPP2_CRUISE_SPEED_H */
