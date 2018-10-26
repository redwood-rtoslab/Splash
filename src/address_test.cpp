//#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <vector>
#include <thread>


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class ProcessingBlock
{
	private:	

	public:
/*	
		dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
		dds::pub::Publisher PB_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber PB_sub{default_dp, default_dp.default_subscriber_qos()};	
		dds::topic::Topic<Data_0> topic0 { default_dp,"address",default_dp.default_topic_qos()};
		dds::topic::Topic<Data_1> topic1 { default_dp,"address1",default_dp.default_topic_qos()};
		dds::sub::DataReader<Data_0> IDP_reader1 {PB_sub,topic0,PB_sub.default_datareader_qos()};		      dds::pub::DataWriter<Data_1> ODP_writer1 {PB_pub,topic1,PB_pub.default_datawriter_qos()};
*/				

		Data_1 A;
		Data_1 B;

		
		void transfer(Data_1 X, Data_1 Y)
		{

			A = X;

			B = Y;


			B.id() = A.id();

		}			

};



