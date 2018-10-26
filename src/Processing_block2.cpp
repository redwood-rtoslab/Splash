#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_PB;


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class OutputDataPort_PB;


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class EventDataPort_PB;
/*
	Class Name: ProcessingBlock
	Detail: An operator that executes user constructed logic 
	Class Variables:
		1. One DomainParticipant
		2. One Publisher
		3. One Subscriber
		4. Ten topic pointers (5 assigned to DataReaders, 5 assigned to DataWriters)
		5. Five InputDataPort objects (Used later for reading inputs)
	Class Function:
		1. int write(Data_{5-9});
		   -Function
			writes the specified data using the corresponding DataWriter 
		   -Parameters
			The data which will be used to sent 
			The API can determine which DataWriter to use based on the type of data
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

	public:
		
		dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
		dds::pub::Publisher PB_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber PB_sub{default_dp, default_dp.default_subscriber_qos()};
	
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
		dds::topic::Topic<int>* topic_event;		

		InputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP0;

		InputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP1;

		InputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP2;
	
		InputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP3;

		InputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP4;

	
		OutputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP0;

		OutputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP1;

		OutputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP2;
	
		OutputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP3;

		OutputDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP4;
		
		EventDataPort_PB<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* EDP;
	
		int write(Data_5);
		int write(Data_6);
		int write(Data_7);	
		int write(Data_8);
		int write(Data_9);		
		int write_event(int);
		
		void read(dds::sub::LoanedSamples<Data_0>*);
		void read(dds::sub::LoanedSamples<Data_1>*);
		void read(dds::sub::LoanedSamples<Data_2>*);
		void read(dds::sub::LoanedSamples<Data_3>*);
		void read(dds::sub::LoanedSamples<Data_4>*);


};


/*
	Class Name: InputDataPort_PB
	Detail: InputDataPort used by Processing Block in order to receive data
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
				
			   The int value can range from 0~4
		  -return value
			returns 1 on successful connections, -1 on error 
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
	public:
		
		dds::sub::DataReader<Data_0>* IDP_reader0;
		dds::sub::DataReader<Data_1>* IDP_reader1;	
		dds::sub::DataReader<Data_2>* IDP_reader2;
		dds::sub::DataReader<Data_3>* IDP_reader3;
		dds::sub::DataReader<Data_4>* IDP_reader4;
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic, int topic_number)
{
	if(topic_number==0)
	{
		
		PB->IDP0 = this;		
		PB->topic0 = new dds::topic::Topic<Data_0> {(*PB).default_dp, topic,(*PB).default_dp.default_topic_qos()};
		IDP_reader0 = new dds::sub::DataReader<Data_0>{(*PB).PB_sub, *(PB->topic0),(*PB).PB_sub.default_datareader_qos()};
		return 1;
	}		

	if(topic_number==1)
	{
		PB->IDP1 = this;			

		PB->topic1 = new dds::topic::Topic<Data_1> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader1= new dds::sub::DataReader<Data_1>((*PB).PB_sub, *(PB->topic1),(*PB).PB_sub.default_datareader_qos());
		return 1;
	}

	if(topic_number==2)
	{
		PB->IDP2 = this;		

		PB->topic2 = new dds::topic::Topic<Data_2> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader2 = new dds::sub::DataReader<Data_2> ((*PB).PB_sub, *(PB->topic2),(*PB).PB_sub.default_datareader_qos());
		
		return 1;
	}
	if(topic_number==3)
	{
		PB->IDP3 = this;
		
		PB->topic3 = new dds::topic::Topic<Data_3> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader3 = new dds::sub::DataReader<Data_3> ((*PB).PB_sub, (*PB->topic3),(*PB).PB_sub.default_datareader_qos());
		
		return 1;
	}	

	if(topic_number==4)
	{
		PB->IDP4 = this;	

		PB->topic4 = new dds::topic::Topic<Data_4> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader4 = new dds::sub::DataReader<Data_4> ((*PB).PB_sub, (*PB->topic4),(*PB).PB_sub.default_datareader_qos());
		
		return 1;
	}

	return -1;
}
/*
	Class Name: OutputDataPort_PB
	Detail: OutputDataPort used by Processing Block in order to send data
	Class Variables:
		1. Five DataWriters
	Class Functions:
		1. int attach(ProcessingBlock*, string, int)
		   -Function
			attaches the OutputDataPort to the ProcessingBlock specified in the parameter
		   -Parameters
		   	a. Uses the ProcessingBlock pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_PB will be connected to
		        c. Uses the int parameter to specify which Topic/DataReader combination should be connected.
                           The int parameter also maps which of the template data type is used for each Topic/DataReader.
                           example) if the int parameter had 1 for its value then dds::sub::DataWriter<Data_1>* ODP_Writer1 will be
                           connected to dds::topic::Topic<Data_1>* topic1. 
				
			   The int value can range from 5~9
		  -return value
			returns 1 on successful connections, -1 on error 
*/

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class OutputDataPort_PB
{
	private:

	public:
		dds::pub::DataWriter<Data_5>* ODP_writer0;
		dds::pub::DataWriter<Data_6>* ODP_writer1;
		dds::pub::DataWriter<Data_7>* ODP_writer2;
		dds::pub::DataWriter<Data_8>* ODP_writer3;
		dds::pub::DataWriter<Data_9>* ODP_writer4;	
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);	
		
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int OutputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic, int topic_number)
{
	if(topic_number==5)
	{

		PB->ODP0 = this;
		
		PB->topic5 = new dds::topic::Topic<Data_5> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());

		ODP_writer0 = new dds::pub::DataWriter<Data_5> ((*PB).PB_pub,*((*PB).topic5),(*PB).PB_pub.default_datawriter_qos());

		return 1;
	}
	
	if(topic_number==6)
	{
		PB->ODP1 = this;
		
		PB->topic6 = new dds::topic::Topic<Data_6> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		ODP_writer1 = new dds::pub::DataWriter<Data_6> ((*PB).PB_pub,(*PB->topic6),(*PB).PB_pub.default_datawriter_qos());

		return 1;
	}

	if(topic_number==7)
	{
		PB->ODP2 = this;

		PB->topic7 = new dds::topic::Topic<Data_7> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());

		ODP_writer2 = new dds::pub::DataWriter<Data_7> ((*PB).PB_pub,(*PB->topic7),(*PB).PB_pub.default_datawriter_qos());
		
		return 1;
	}

	if(topic_number==8)
	{
		PB->ODP3 = this;

		PB->topic8 = new dds::topic::Topic<Data_8> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		
		ODP_writer3 = new dds::pub::DataWriter<Data_8> ((*PB).PB_pub,(*PB->topic8),(*PB).PB_pub.default_datawriter_qos());
	
		return 1;
	}
	
	if(topic_number==9)
	{
		PB->ODP4 = this;
		
		PB->topic9 = new dds::topic::Topic<Data_9> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		
		ODP_writer4 = new dds::pub::DataWriter<Data_9> ((*PB).PB_pub,(*PB->topic9),(*PB).PB_pub.default_datawriter_qos());	
	
		return 1;
	}

		return -1;
}

/*
	Class Name: EventDataPort_PB
	Detail: EventDataPort used by Processing Block in order to send data
	Class Variables:
		1. One DataWriter
	Class Functions:
		1. int attach(ProcessingBlock*, string)
		   -Function
			attaches the EventDataPort to the ProcessingBlock specified in the parameter
		   -Parameters
		   	a. Uses the ProcessingBlock pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the EventDataPort_PB will be connected to
		  -return value
			returns 1 on successful connections, -1 on error 
*/
/*
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class EventDataPort_PB
{
	private:
	public:
		
		dds::pub::DataWriter<int>* EDP_writer;
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string);

};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int EventDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic)
{
		PB->EDP = this;
		
		dds::topic::Topic<int> temp((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
	
		PB->topic_event = &temp;		

		dds::pub::DataWriter<int> temp2((*PB).PB_pub,(*PB->topic_event),(*PB).PB_pub.default_datawriter_qos());	
		EDP_writer = &temp2;

		return 1;
}
*/

//The ProcessingBlock's write member function
//Located below the IDP and ODP in order to access the ODP's writers  
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_5 sendData)
{
	ODP0->ODP_writer0->write(sendData);
	
	return 1;
}
/*

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_6 Data)
{
	ODP1->ODP_writer1->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_7 Data)
{
	ODP2->ODP_writer2->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_8 Data)
{
	ODP3->ODP_writer3->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_9 Data)
{
	ODP4->ODP_writer4->write(Data);
	return 1;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write_event(int event_type)
{
	EDP->EDP_writer->write(event_type);
	return 1;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::LoanedSamples<Data_0>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP0->IDP_reader0),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	IDP0->IDP_reader0->read();	
}*/
