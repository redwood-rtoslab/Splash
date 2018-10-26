#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <vector>
#include <thread>

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

template
<typename Data_0>

class SplashListener : public dds::sub::NoOpDataReaderListener<Data_0>
{
	public:
		int rate=0;
		virtual void on_data_available(dds::sub::DataReader<Data_0>& dr)
		{
			rate++;
		}

};



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
	
		
		dds::topic::qos::TopicQos topicQoS{};

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

		int output_rate=0;

		std::vector<dds::sub::Sample<Data_0>> input_data_1{1};
		typename std::vector<dds::sub::Sample<Data_0>>::iterator iter_1;
		std::vector<dds::sub::Sample<Data_1>> input_data_2{1};
		typename std::vector<dds::sub::Sample<Data_1>>::iterator iter_2;
		std::vector<dds::sub::Sample<Data_2>> input_data_3{1};
		typename std::vector<dds::sub::Sample<Data_2>>::iterator iter_3;
		std::vector<dds::sub::Sample<Data_3>> input_data_4{1};
		typename std::vector<dds::sub::Sample<Data_3>>::iterator iter_4;
		std::vector<dds::sub::Sample<Data_4>> input_data_5{1};
		typename std::vector<dds::sub::Sample<Data_4>>::iterator iter_5;		


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
		
		void read(dds::sub::Sample<Data_0>*);
		void read(dds::sub::Sample<Data_1>*);
		void read(dds::sub::Sample<Data_2>*);
		void read(dds::sub::Sample<Data_3>*);
		void read(dds::sub::Sample<Data_4>*);
		
		void initialize(std::string, int, void* ,int, bool, int);

		void spin();
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

		void* port_memory;

		SplashListener<Data_0>* listener_0;	
		SplashListener<Data_1>* listener_1;
		SplashListener<Data_2>* listener_2;	
		SplashListener<Data_3>* listener_3;
		SplashListener<Data_4>* listener_4;

		int topic_number=0;
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);
		void initialize(int,void(*rate_handler)(),int,void(*freshness_handler)(),bool,int);
	
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
		this->topic_number = topic_number;
		listener_0 = new SplashListener<Data_0>;
		
		PB->IDP0 = this;		
		
		PB->topic0 = new dds::topic::Topic<Data_0> {(*PB).default_dp, topic,(*PB).default_dp.default_topic_qos()};
		IDP_reader0 = new dds::sub::DataReader<Data_0>{(*PB).PB_sub, (*PB->topic0),(*PB).PB_sub.default_datareader_qos()};

		IDP_reader0->listener(listener_0, dds::core::status::StatusMask::data_available());
		

		return 1;
	}		

	if(topic_number==1)
	{
		this->topic_number = topic_number;
		listener_1 = new SplashListener<Data_1>;
		
		PB->IDP1 = this;			

		PB->topic1 = new dds::topic::Topic<Data_1> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader1= new dds::sub::DataReader<Data_1>((*PB).PB_sub, (*PB->topic1),(*PB).PB_sub.default_datareader_qos());

		IDP_reader1->listener(listener_1, dds::core::status::StatusMask::data_available());		
	
		return 1;
	}

	if(topic_number==2)
	{
		this->topic_number = topic_number;
		listener_2 = new SplashListener<Data_2>;
		
		PB->IDP2 = this;		

		PB->topic2 = new dds::topic::Topic<Data_2> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader2 = new dds::sub::DataReader<Data_2> ((*PB).PB_sub, (*PB->topic2),(*PB).PB_sub.default_datareader_qos());
	
		IDP_reader2->listener(listener_2, dds::core::status::StatusMask::data_available());
	
		return 1;
	}
	if(topic_number==3)
	{
		this->topic_number = topic_number;			
		listener_3 = new SplashListener<Data_3>;

		PB->IDP3 = this;
		
		PB->topic3 = new dds::topic::Topic<Data_3> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader3 = new dds::sub::DataReader<Data_3> ((*PB).PB_sub, (*PB->topic3),(*PB).PB_sub.default_datareader_qos());
		
		IDP_reader3->listener(listener_3, dds::core::status::StatusMask::data_available());

		return 1;
	}	

	if(topic_number==4)
	{
		this->topic_number = topic_number;	
		listener_4 = new SplashListener<Data_4>;

		PB->IDP4 = this;	

		PB->topic4 = new dds::topic::Topic<Data_4> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader4 = new dds::sub::DataReader<Data_4> ((*PB).PB_sub, (*PB->topic4),(*PB).PB_sub.default_datareader_qos());
		
		IDP_reader4->listener(listener_4, dds::core::status::StatusMask::data_available());

		return 1;
	}

	return -1;
}


template
<typename Data_0>
void rate_check (int set_rate, SplashListener<Data_0>* listener, void* user_memory, void (*fun_ptr)())
{
	while(true)
	{
		printf("WHAT5\n");
		int rate = listener->rate;
		if(rate<set_rate)
		{
			std::thread rate_handler(*fun_ptr);
			rate_handler.detach();
		}
		printf("rate:%d\n",rate);
		listener->rate = 0;
		sleep(1);
	}

}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (int rate, void (*rate_handler)(), int freshness, void (*freshness_handler)(), bool queueing, int queue_size)
{

	if((this->topic_number)==0)
	 {
		//std::thread rate_check_thread_0(rate_check<Data_0>,rate,listener_0,port_memory,rate_handler);
		//rate_check_thread_0.detach();

		std::thread rate_check_thread_0 (rate_check<Data_0>,rate,listener_0,port_memory,rate_handler);
		rate_check_thread_0.detach();
	}

	else if((this->topic_number)==1)
	{
		//std::thread 
		std::thread rate_check_thread_1 (rate_check<Data_1>,rate,listener_1,port_memory,rate_handler);
		rate_check_thread_1.detach();
	}

	else if((this->topic_number)==2)
	{
		//printf("WHAT2\n");
		//std::thread 
		std::thread rate_check_thread_2 (rate_check<Data_2>,rate,listener_2,port_memory,rate_handler);
		rate_check_thread_2.detach();
	
	}	



	else if(this->topic_number==3)
	{
		std::thread rate_check_thread(rate_check<Data_3>,rate,listener_3,port_memory,rate_handler);
		rate_check_thread.detach();
	}
	
	else if(this->topic_number==4)
	{
		std::thread rate_check_thread(rate_check<Data_4>,rate,listener_4,port_memory,rate_handler);
		rate_check_thread.detach();
	}	

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
		void initialize(double,void*);	
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
	

		ODP_writer0 = new dds::pub::DataWriter<Data_5> ((*PB).PB_pub,(*PB->topic5),(*PB).PB_pub.default_datawriter_qos());

		
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

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void OutputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (double rate,void* rate_handler)
{


}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_5 Data)
{
	
	output_rate++;	
	ODP0->ODP_writer0->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_6 Data)
{
	output_rate++;
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
	output_rate++;
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
	output_rate++;
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
	output_rate++;
	ODP4->ODP_writer4->write(Data);
	return 1;
}
	
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::Sample<Data_0>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP0->IDP_reader0),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	iter_1 = input_data_1.begin();
	IDP0->IDP_reader0->take(iter_1,1);	
	*samples = *iter_1;	
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::Sample<Data_1>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP1->IDP_reader1),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	iter_2 = input_data_2.begin();
	IDP1->IDP_reader1->take(iter_2,1);	
	*samples = *iter_2;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::Sample<Data_2>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP2->IDP_reader2),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	iter_3 = input_data_3.begin();
	IDP2->IDP_reader2->take(iter_3,1);
	*samples = *iter_3;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::Sample<Data_3>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP3->IDP_reader3),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	iter_4 = input_data_4.begin();
	IDP3->IDP_reader3->take(iter_4,1);	
	*samples = *iter_4;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::read(dds::sub::Sample<Data_4>* samples)
{
	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(*(IDP4->IDP_reader4),dds::sub::status::DataState::new_data());
	ws.attach_condition(rc);
	ws.wait();
	iter_5 = input_data_5.begin();
	IDP4->IDP_reader4->take(iter_5,1);	
	*samples = *iter_5;
}



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (std::string, int deadline, void* deadline_handler, int period, bool time_trigger, int core_id)
{


}
