#ifndef ISOCPP2_CRUISE_GEAR_H
#define ISOCPP2_CRUISE_GEAR_H

#include "dds/dds.hpp"

#include "cruise_gear.h"
#include "cruise_gearSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<cruise_gear::Msg>
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
        return "cruise_gear::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"cruise_gear\"><Struct name=\"Msg\"><Member name=\"id\"><Long/>",
"</Member><Member name=\"curr_gear\"><Double/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(188);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __cruise_gear_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __cruise_gear_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<cruise_gear::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<cruise_gear::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(cruise_gear::Msg)

#endif /* ISOCPP2_CRUISE_GEAR_H */
