#ifndef ISOCPP2_PATH_CU_H
#define ISOCPP2_PATH_CU_H

#include "dds/dds.hpp"

#include "path_CU.h"
#include "path_CUSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<path_CU::Msg>
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
        return "path_CU::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"path_CU\"><Struct name=\"Msg\"><Member name=\"id\"><Long/>",
"</Member><Member name=\"steering_input\"><Double/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(189);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __path_CU_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __path_CU_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<path_CU::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<path_CU::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(path_CU::Msg)

#endif /* ISOCPP2_PATH_CU_H */
