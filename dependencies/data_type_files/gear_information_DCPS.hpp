#ifndef ISOCPP2_GEAR_INFORMATION_H
#define ISOCPP2_GEAR_INFORMATION_H

#include "dds/dds.hpp"

#include "gear_information.h"
#include "gear_informationSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<gear_information::Msg>
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
        return "gear_information::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"gear_information\"><Struct name=\"Msg\"><Member name=\"id\">",
"<Long/></Member><Member name=\"curr_gear\"><Long/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(191);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __gear_information_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __gear_information_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<gear_information::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<gear_information::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(gear_information::Msg)

#endif /* ISOCPP2_GEAR_INFORMATION_H */
