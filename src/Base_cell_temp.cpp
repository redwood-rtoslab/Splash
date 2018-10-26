#include "../dependencies/data_type_files/default_data_DCPS.hpp"



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class InputDataPort;

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class OutputDataPort;


/*
	Class Name: ProcessingBlock
	Detail: An operator that executes user constructed logic 
	Class Variables:
		1. One DomainParticipant
		2. One Publisher
		3. One Subscriber
		4. Ten topic pointers (5 assigned to DataReaders, 5 assigned to DataWriters)

*/

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class ProcessingBlock
{
	private:
		/*
		friend class InputDataPort<Data_0, Data_1,
					   Data_2, Data_3, 
					   Data_4, Data_5,
					   Data_6, Data_7,
					   Data_8, Data_9>;
		*/
		
		dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
		dds::pub::Publisher PB_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber PB_sub{default_dp, default_dp.default_subscriber_qos()};
	
	public:
		dds::topic::Topic<Data_0>* topic0;	
		dds::topic::Topic<Data_1>* topic1;
		dds::topic::Topic<Data_2>* topic2;
		dds::topic::Topic<Data_3>* topic3;
		dds::topic::Topic<Data_4>* topic4;
		dds::topic::Topic<Data_5>* topic5;
		dds::topic::Topic<Data_6>* topic6;
		dds::topic::Topic<Data_7>* topic7;
		dds::topic::Topic<Data_8>* topic8;
		dds::topic::Topic<Data_9>* topic9;			

		InputDataPort<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP0;

		InputDataPort<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP1;

		InputDataPort<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP2;
	
		InputDataPort<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP3;

		InputDataPort<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP4;
};


/*
	Class Name: InputDataPort_PB
	Detail: InputDataPort used by operators in order to receive data
	Class Variables:
		1. Five DataReaders
	Class Functions:
		1. int attach(ProcessingBlock*, string, int)
		   -Function
			attaches the InputDataPort to the ProcessingBlock specified in the parameter
		   -Parameters
		   	a. Uses the ProcessingBlock pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_PB will be connected to
		        c. Uses the int parameter to specify which Topic/DataReader combination should be connected.
                           The int parameter also maps which of the template data type is used for each Topic/DataReader.
                           example) if the int parameter had 1 for its value then dds::sub::DataReader<Data_1>* IDP_reader1 will be
                           connected to dds::topic::Topic<Data_1>* topic1. 
		  -return value
			returns 1 on successful connections, 0 on error 
*/
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_PB
{
	private:
		dds::sub::DataReader<Data_0>* IDP_reader0;
		dds::sub::DataReader<Data_1>* IDP_reader1;	
		dds::sub::DataReader<Data_2>* IDP_reader2;
		dds::sub::DataReader<Data_3>* IDP_reader3;
		dds::sub::DataReader<Data_4>* IDP_reader4;
	public:
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
/*Since there is no generic definition for Topic (meaning each topic needs its own data type in order to be declared) we had to 
manually match the DataReader and the Topic
*/
int InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic, int topic_number)
{
	if(topic_number==0)
	{
		PB->IDP0 = this;		

		PB->topic0 = new dds::topic::Topic<Data_0>((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		IDP_reader0 = new dds::sub::DataReader<Data_0> ((*PB).PB_sub, PB->topic0,(*PB).PB_sub.default_datareader_qos());
		return 1;
	}		

	if(topic_number==1)
	{
	
		PB->IDP1 = this;			

		PB->topic1 = new dds::topic::Topic<Data_1>((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		IDP_reader1 = new dds::sub::DataReader<Data_1> ((*PB).PB_sub, PB->topic1,(*PB).PB_sub.default_datareader_qos());
		return 1;
	}

	if(topic_number==2)
	{
		PB->IDP2 = this;		

		PB->topic2 = new dds::topic::Topic<Data_2>((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		IDP_reader2 = new dds::sub::DataReader<Data_2> ((*PB).PB_sub, PB->topic2,(*PB).PB_sub.default_datareader_qos());
		return 1;
	}
	if(topic_number==3)
	{
		PB->IDP3 = this;
		
		PB->topic3 = new dds::topic::Topic<Data_3>((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		IDP_reader3 = new dds::sub::DataReader<Data_3> ((*PB).PB_sub, PB->topic3,(*PB).PB_sub.default_datareader_qos());
		return 1;
	}	

	if(topic_number==4)
	{
		PB->IDP4 = this;	

		PB->topic4 = new dds::topic::Topic<Data_4>((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		IDP_reader4 = new dds::sub::DataReader<Data_4> ((*PB).PB_sub, PB->topic4,(*PB).PB_sub.default_datareader_qos());
		return 1;
	}

	return -1;
}

