#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>


int main(void)
{
	dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
	dds::pub::Publisher PB_pub{default_dp, default_dp.default_publisher_qos()};
	dds::sub::Subscriber PB_sun{default_dp, default_dp.default_subscriber_qos()};
	dds::topic::Topic<void> topic0 {default_dp, "A",default_dp.default_topic_qos()};
	dds::topic::Topic<void>* topic1;
	dds::topic::Topic<default_data::Msg>* topic2;
	
	(dds::topic::Topic<default_data::Msg>*)topic1 = new dds::topic::Topic<default_data::Msg> {default_dp, "A",default_dp.default_topic_qos()}	
}
