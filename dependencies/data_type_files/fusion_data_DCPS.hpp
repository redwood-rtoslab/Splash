#ifndef ISOCPP2_FUSION_DATA_H
#define ISOCPP2_FUSION_DATA_H

#include "dds/dds.hpp"

#include "fusion_data.h"
#include "fusion_dataSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<fusion_data::Msg>
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
        return "fusion_data_id";
    }

    static const char *getTypeName()
    {
        return "fusion_data::Msg";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"fusion_data\"><TypeDef name=\"QQ\"><Array size=\"10\"><String/>",
"</Array></TypeDef><Struct name=\"Msg\"><Member name=\"fusion_data_id\"><Long/></Member><Member name=\"received_port\">",
"<Array size=\"9\"><Long/></Array></Member><Member name=\"data_id\"><Array size=\"9\"><Long/></Array></Member>",
"<Member name=\"message\"><Array size=\"9\"><String/></Array></Member><Member name=\"constraint_deadline_duetime\">",
"<LongLong/></Member><Member name=\"constraint_freshness_gentime\"><LongLong/></Member><Member name=\"test\">",
"<Type name=\"QQ\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(612);
        for (int i = 0; i < 6; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __fusion_data_Msg__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __fusion_data_Msg__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<fusion_data::Msg>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<fusion_data::Msg>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(fusion_data::Msg)

#endif /* ISOCPP2_FUSION_DATA_H */
