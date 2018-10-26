#ifndef ISOCPP2_CRUISE_INFORMATION_H
#define ISOCPP2_CRUISE_INFORMATION_H

#include "dds/dds.hpp"

#include "cruise_information.h"
#include "cruise_informationSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<cruise_information::Msg>
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
        return "cruise_information::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"cruise_information\"><Struct name=\"Msg\"><Member name=\"id\">",
"<Long/></Member><Member name=\"throttle\"><Double/></Member><Member name=\"brake\"><Double/></Member>",
"</Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(235);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __cruise_information_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __cruise_information_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<cruise_information::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<cruise_information::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(cruise_information::Msg)

#endif /* ISOCPP2_CRUISE_INFORMATION_H */
