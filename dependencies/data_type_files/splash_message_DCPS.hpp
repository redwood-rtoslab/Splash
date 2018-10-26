#ifndef ISOCPP2_SPLASH_MESSAGE_H
#define ISOCPP2_SPLASH_MESSAGE_H

#include "dds/dds.hpp"

#include "splash_message.h"
#include "splash_messageSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::new_record>
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
        return "a";
    }

    static const char *getTypeName()
    {
        return "splash_message::new_record";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"new_record\"><Member name=\"a\">",
"<Boolean/></Member><Member name=\"sibal\"><String length=\"28\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(210);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_new_record__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_new_record__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::new_record>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::new_record>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::new_record)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg0>
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
        return "splash_message::msg0";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"msg0\"><Member name=\"id\">",
"<Long/></Member><Member name=\"k\"><Boolean/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(185);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg0__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg0__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg0>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg0>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg0)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg1>
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
        return "splash_message::msg1";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"msg1\"><Member name=\"id\">",
"<Long/></Member><Member name=\"a\"><Double/></Member><Member name=\"b\"><Double/></Member></Struct></Module>",
"</MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(221);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg1__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg1__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg1>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg1>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg1)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg2>
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
        return "splash_message::msg2";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"msg2\"><Member name=\"id\">",
"<Long/></Member><Member name=\"sibal\"><Short/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(187);
        for (int i = 0; i < 2; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg2__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg2__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg2>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg2>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg2)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg3>
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
        return "splash_message::msg3";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"msg3\"><Member name=\"id\">",
"<Long/></Member><Member name=\"str\"><String length=\"14\"/></Member><Member name=\"sisi\"><LongLong/>",
"</Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(242);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg3__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg3__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg3>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg3>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg3)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg4>
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
        return "splash_message::msg4";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"msg4\"><Member name=\"id\">",
"<Long/></Member><Member name=\"a\"><Float/></Member><Member name=\"kk\"><Long/></Member></Struct></Module>",
"</MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(219);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg4__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg4__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg4>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg4>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg4)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<splash_message::msg5>
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
        return "splash_message::msg5";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"splash_message\"><Struct name=\"new_record\"><Member name=\"a\">",
"<Boolean/></Member><Member name=\"sibal\"><String length=\"28\"/></Member></Struct><Struct name=\"msg5\">",
"<Member name=\"id\"><Long/></Member><Member name=\"cc\"><Char/></Member><Member name=\"A\"><Type name=\"new_record\"/>",
"</Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(368);
        for (int i = 0; i < 4; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __splash_message_msg5__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __splash_message_msg5__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<splash_message::msg5>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<splash_message::msg5>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(splash_message::msg5)

#endif /* ISOCPP2_SPLASH_MESSAGE_H */
