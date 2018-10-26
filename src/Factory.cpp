#ifndef _FACTORY_CPP_
#define _FACTORY_CPP_


#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <bitset>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/prctl.h>

#include <thread>
#include <vector>
#include <string.h>

#include <ctime>
#include <chrono>

#include "Processing_block.cpp"

class DeadlineMonitor_Fac;

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_Fac;


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class OutputDataPort_Fac;

/* TODO: move to these codes to end of output port factory implementation region (start) */


class DeadlineMonitor_Fac {
	public:
		void setup(int64_t deadline, void (*deadline_handler)());
		void update(int64_t *msg_duetime);
		int check(int64_t msg_duetime, int64_t current_time);
	private:
		int64_t _constraint_deadline = -1;
		void (*_handler)();

};

void DeadlineMonitor_Fac::setup(int64_t deadline, void (*deadline_handler)()) {
	_constraint_deadline = deadline;
	_handler = deadline_handler;
}

void DeadlineMonitor_Fac::update(int64_t *msg_duetime) {
	*msg_duetime = SystemClock::getCurrentTime() + _constraint_deadline;  
	// TODO more: for nested factory
}

int DeadlineMonitor_Fac::check(int64_t msg_duetime, int64_t current_time) {
	if(_constraint_deadline==-1 || _handler==NULL) return true;

	if(msg_duetime < current_time) {
		//printf("[Debugging] factory deadline violation\n");
		std::thread thread_handler(*_handler);
		thread_handler.detach();
		return false;
	}
	else return true;
}

/**
*	@brief Splash LanguageConstructs > ComponentType > FactoryType
*	@details The smallest execution unit of stream processing. Takes data elements as inputs, performs predefined operation, and returns data elements as outputs.
*	@author Jaeho Ahn, Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class Factory
{
	private:	
		std::vector<std::thread *> FIP_pthreads;
		std::vector<std::thread *> FOP_pthreads;

		DeadlineMonitor_Fac _deadline_monitor;

	public:

		Factory();
		~Factory();
	
		dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
		
		dds::pub::Publisher Output_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber Input_sub{default_dp, default_dp.default_subscriber_qos()};
		
		dds::pub::Publisher Input_connector_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber Output_connector_sub{default_dp, default_dp.default_subscriber_qos()};
		
		std::bitset<10> connected_ports;
	
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

		dds::topic::Topic<Data_0>* connector_topic0;	
		dds::topic::Topic<Data_1>* connector_topic1;
		dds::topic::Topic<Data_2>* connector_topic2;
		dds::topic::Topic<Data_3>* connector_topic3;
		dds::topic::Topic<Data_4>* connector_topic4;
		dds::topic::Topic<Data_5>* connector_topic5;
		dds::topic::Topic<Data_6>* connector_topic6;
		dds::topic::Topic<Data_7>* connector_topic7;
		dds::topic::Topic<Data_8>* connector_topic8;
		dds::topic::Topic<Data_9>* connector_topic9;

		std::vector<dds::sub::Sample<Data_0>> input_data_1{1};
		typename std::vector<dds::sub::Sample<Data_0>>::iterator iter_1 = input_data_1.begin();
		std::vector<dds::sub::Sample<Data_1>> input_data_2{1};
		typename std::vector<dds::sub::Sample<Data_1>>::iterator iter_2 = input_data_2.begin();
		std::vector<dds::sub::Sample<Data_2>> input_data_3{1};
		typename std::vector<dds::sub::Sample<Data_2>>::iterator iter_3 = input_data_3.begin();
		std::vector<dds::sub::Sample<Data_3>> input_data_4{1};
		typename std::vector<dds::sub::Sample<Data_3>>::iterator iter_4 = input_data_4.begin();
		std::vector<dds::sub::Sample<Data_4>> input_data_5{1};
		typename std::vector<dds::sub::Sample<Data_4>>::iterator iter_5 = input_data_5.begin();
		
		std::vector<dds::sub::Sample<Data_5>> output_connector_data_1{1};
		typename std::vector<dds::sub::Sample<Data_5>>::iterator connector_iter_1;
		std::vector<dds::sub::Sample<Data_6>> output_connector_data_2{1};
		typename std::vector<dds::sub::Sample<Data_6>>::iterator connector_iter_2;		
		std::vector<dds::sub::Sample<Data_7>> output_connector_data_3{1};
		typename std::vector<dds::sub::Sample<Data_7>>::iterator connector_iter_3;
		std::vector<dds::sub::Sample<Data_8>> output_connector_data_4{1};
		typename std::vector<dds::sub::Sample<Data_8>>::iterator connector_iter_4;
		std::vector<dds::sub::Sample<Data_9>> output_connector_data_5{1};
		typename std::vector<dds::sub::Sample<Data_9>>::iterator connector_iter_5;



		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP0;
		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP1;
		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP2;	
		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP3;
		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP4;
	
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP0;
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP1;
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP2;	
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP3;
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP4;

		void initialize (std::string name, int64_t deadline, void(*deadline_handler)(), int node_id, int core_id); 		
		void execFactory(std::vector<const char*> atomic_list);
		void execFactoryPort_in();
		void execFactoryPort_out();	

		void FIP_create(const int port_id);
		void FOP_create(const int port_id);

		/* Deadline constraint check functions */
		void checkDeadline(int64_t msg_duetime);
		void updateDeadlineFIP(int64_t *msg_duetime);
		void updateDeadlineFOP(int64_t *msg_duetime);

		void setDeadline(int64_t deadline, void (*deadline_handler)());	
};





/* TODO: move to these codes to end of output port implementation region (end) */



/* TODO: move to these codes to end of factory implementation region (start) */ 


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkDeadline(int64_t msg_duetime) {
	_deadline_monitor.check(msg_duetime, SystemClock::getCurrentTime());
	// TODO more: for nested factory 
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::updateDeadlineFIP(int64_t *msg_duetime) {
	_deadline_monitor.update(msg_duetime);
	// TODO more: for nested factory
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::updateDeadlineFOP(int64_t *msg_duetime) {
	// TODO: for nested factory
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::setDeadline(int64_t deadline, void (*deadline_handler)()) {
	// argument deadline is millisecond scale variable
	_deadline_monitor.setup(deadline, deadline_handler);
}

/* TODO: move to these codes to end of factory implementation region (end) */ 

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::Factory()
{
	FIP_pthreads.reserve(5);	
	FOP_pthreads.reserve(5);
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::~Factory()
{
	// TODO: for thread join and pointer delete 
}


template <typename data_t>
class InputRateMonitor_Fac {
public:
	void setup(int input_rate, void (*input_rate_handler)());
	void setup(int input_rate, void (*input_rate_handler)(), void* user_memory);

	void check();
	void run();

	void setListener(SplashDataReaderListener<data_t>* input_rate_listener);
	SplashDataReaderListener<data_t>* ptr_listener();

private:
	int _constraint_input_rate = -1;
	SplashDataReaderListener<data_t>* _listener;
	void (*_handler)();

};

template <typename data_t>
void InputRateMonitor_Fac<data_t>::setup(int input_rate, void (*input_rate_handler)()) {
	_constraint_input_rate = input_rate;
	_handler = input_rate_handler;
}

template <typename data_t>
void InputRateMonitor_Fac<data_t>::setup(int input_rate, void (*input_rate_handler)(), void* user_memory) {
	_constraint_input_rate = input_rate;
	_handler = input_rate_handler;
}

template <typename data_t>
void InputRateMonitor_Fac<data_t>::check() {
	while(true)
	{
		int current_input_rate = _listener->rate;
		if(current_input_rate < _constraint_input_rate)
		{
			//printf("[Debugging] current_input_rate:%d\n", current_input_rate);	
			std::thread input_rate_handler(*_handler);
			input_rate_handler.detach();
		}
		
		_listener->rate = 0;
		sleep(1);
	}
}

template <typename data_t>
void InputRateMonitor_Fac<data_t>::run() {
	std::thread input_rate_check_thread(&InputRateMonitor_Fac<data_t>::check, this);
	input_rate_check_thread.detach();
}

template <typename data_t>
void InputRateMonitor_Fac<data_t>::setListener(SplashDataReaderListener<data_t>* input_rate_listener) {
	_listener = input_rate_listener;
}

template <typename data_t>
SplashDataReaderListener<data_t>* InputRateMonitor_Fac<data_t>::ptr_listener() {
	return _listener;
}

/*
	Class Name: InputDataPort_Fac
	Detail: InputDataPort used by Processing Block in order to receive data
	Class Variables:
		1. Five DataReaders
	Class Functions:
		1. int attach(Factory*, string, int)
		   -Function
			attaches the InputDataPort to the Factory specified in the parameter
		   -Parameters
		   	a. Uses the Factory pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_Fac will be connected to
		        c. Uses the int parameter to specify which Topic/DataReader combination should be connected.
                           The int parameter also maps which of the template data type is used for each Topic/DataReader.
                           example) if the int parameter had 1 for its value then dds::sub::DataReader<Data_1>* Input_reader1 will be
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

class InputDataPort_Fac
{
	private:
		Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* _attachedFactory;

		FreshnessMonitor_IP _freshness_monitor;

		InputRateMonitor_Fac<Data_0> _input_rate_monitor_port0;
		InputRateMonitor_Fac<Data_1> _input_rate_monitor_port1;
		InputRateMonitor_Fac<Data_2> _input_rate_monitor_port2;
		InputRateMonitor_Fac<Data_3> _input_rate_monitor_port3;
		InputRateMonitor_Fac<Data_4> _input_rate_monitor_port4;			

		int _topic_number;
		void* _port_memory;

	public:
		
		dds::sub::DataReader<Data_0>* Input_reader0;
		dds::sub::DataReader<Data_1>* Input_reader1;	
		dds::sub::DataReader<Data_2>* Input_reader2;
		dds::sub::DataReader<Data_3>* Input_reader3;
		dds::sub::DataReader<Data_4>* Input_reader4;

		dds::pub::DataWriter<Data_0>* Input_connector0;
		dds::pub::DataWriter<Data_1>* Input_connector1;
		dds::pub::DataWriter<Data_2>* Input_connector2;
		dds::pub::DataWriter<Data_3>* Input_connector3;
		dds::pub::DataWriter<Data_4>* Input_connector4;
				

		int attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* Fact, std::string topic, std::string connector_topic, int topic_number);
		void initialize (int rate, void (*rate_handler)(), int freshness, void (*freshness_handler)(), bool queueing, int queue_size);

		void setFreshness(int64_t freshness, void (*freshness_handler)());
		void checkFreshness(int64_t msg_gentime);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::setFreshness(int64_t freshness, void (*freshness_handler)())
{
	_freshness_monitor.setup(freshness, freshness_handler);
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkFreshness(int64_t msg_gentime)
{
	_freshness_monitor.check(msg_gentime);
}



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* Fact, std::string topic, std::string connector_topic, int topic_number)
{
	_attachedFactory = Fact;
	_topic_number = topic_number;

	if(topic_number==0)
	{
		_input_rate_monitor_port0.setListener(new SplashDataReaderListener<Data_0>);

		Fact->IDP0 = this;		
		Fact->topic0 = new dds::topic::Topic<Data_0> {(*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos()};
		Input_reader0 = new dds::sub::DataReader<Data_0>{(*Fact).Input_sub, (*Fact->topic0),(*Fact).Input_sub.default_datareader_qos()};
	
		Fact->connector_topic0 = new dds::topic::Topic<Data_0> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector0 = new dds::pub::DataWriter<Data_0>{(*Fact).Input_connector_pub, (*Fact->connector_topic0),(*Fact).Input_connector_pub.default_datawriter_qos()};
	
		Fact->connected_ports.set(0);		
		Input_reader0->listener(_input_rate_monitor_port0.ptr_listener(), dds::core::status::StatusMask::data_available());


		return 1;
	}		

	if(topic_number==1)
	{
		Fact->IDP1 = this;		
		_input_rate_monitor_port1.setListener(new SplashDataReaderListener<Data_1>);	

		Fact->topic1 = new dds::topic::Topic<Data_1> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
	
		Input_reader1= new dds::sub::DataReader<Data_1>((*Fact).Input_sub, (*Fact->topic1),(*Fact).Input_sub.default_datareader_qos());
		
		Fact->connector_topic1 = new dds::topic::Topic<Data_1> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector1 = new dds::pub::DataWriter<Data_1>{(*Fact).Input_connector_pub, (*Fact->connector_topic1),(*Fact).Input_connector_pub.default_datawriter_qos()};
		
		Fact->connected_ports.set(1);
		Input_reader1->listener(_input_rate_monitor_port1.ptr_listener(), dds::core::status::StatusMask::data_available());		

		
		return 1;
	}

	if(topic_number==2)
	{
		Fact->IDP2 = this;	
		_input_rate_monitor_port2.setListener(new SplashDataReaderListener<Data_2>);
	

		Fact->topic2 = new dds::topic::Topic<Data_2> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
	
		Input_reader2 = new dds::sub::DataReader<Data_2> ((*Fact).Input_sub, (*Fact->topic2),(*Fact).Input_sub.default_datareader_qos());
	
		Fact->connector_topic2 = new dds::topic::Topic<Data_2> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector2 = new dds::pub::DataWriter<Data_2>{(*Fact).Input_connector_pub, (*Fact->connector_topic2),(*Fact).Input_connector_pub.default_datawriter_qos()};
	
		Fact->connected_ports.set(2);
		Input_reader2->listener(_input_rate_monitor_port2.ptr_listener(), dds::core::status::StatusMask::data_available());	


		return 1;
	}
	if(topic_number==3)
	{
		Fact->IDP3 = this;
		_input_rate_monitor_port3.setListener(new SplashDataReaderListener<Data_3>);

		
		Fact->topic3 = new dds::topic::Topic<Data_3> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
		
		Input_reader3 = new dds::sub::DataReader<Data_3> ((*Fact).Input_sub, (*Fact->topic3),(*Fact).Input_sub.default_datareader_qos());

		Fact->connector_topic3 = new dds::topic::Topic<Data_3> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector3 = new dds::pub::DataWriter<Data_3>{(*Fact).Input_connector_pub, (*Fact->connector_topic3),(*Fact).Input_connector_pub.default_datawriter_qos()};

		Fact->connected_ports.set(3);
		Input_reader3->listener(_input_rate_monitor_port3.ptr_listener(), dds::core::status::StatusMask::data_available());	

		return 1;
	}	

	if(topic_number==4)
	{
		Fact->IDP4 = this;	
		_input_rate_monitor_port4.setListener(new SplashDataReaderListener<Data_4>);


		Fact->topic4 = new dds::topic::Topic<Data_4> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
		
		Input_reader4 = new dds::sub::DataReader<Data_4> ((*Fact).Input_sub, (*Fact->topic4),(*Fact).Input_sub.default_datareader_qos());
		
		Fact->connector_topic4 = new dds::topic::Topic<Data_4> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector4 = new dds::pub::DataWriter<Data_4>{(*Fact).Input_connector_pub, (*Fact->connector_topic4),(*Fact).Input_connector_pub.default_datawriter_qos()};

		Fact->connected_ports.set(4);	
		Input_reader4->listener(_input_rate_monitor_port4.ptr_listener(), dds::core::status::StatusMask::data_available());	
			

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

void InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (int rate, void (*rate_handler)(), int freshness, void (*freshness_handler)(), bool queueing, int queue_size)
{
	setFreshness(freshness, freshness_handler);

	if((_topic_number)==0)
	{
		_input_rate_monitor_port0.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port0.run();
	}

	else if((_topic_number)==1)
	{
		_input_rate_monitor_port1.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port1.run();
	}

	else if((_topic_number)==2)
	{
		_input_rate_monitor_port2.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port2.run();
	}	

	else if(_topic_number==3)
	{
		_input_rate_monitor_port3.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port3.run();
	}
	
	else if(_topic_number==4)
	{
		_input_rate_monitor_port4.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port4.run();
	}	
}


template <typename data_t>
class OutputRateMonitor_Fac {
public:
	void setup(int output_rate, void (*output_rate_handler)());
	void setup(int output_rate, void (*output_rate_handler)(), void* user_memory);
	void update();
	void check();
	void run();

	//void setListener(SplashDataWriterListener<data_t>* output_rate_listener);
	//SplashDataWriterListener<data_t>* ptr_listener();

private:
	int _constraint_output_rate = -1;
	//SplashDataWriterListener<data_t>* _listener;
	int _current_output_rate = 0;
	void (*_handler)();

};

template <typename data_t>
void OutputRateMonitor_Fac<data_t>::setup(int output_rate, void (*output_rate_handler)()) {
	_constraint_output_rate = output_rate;
	_handler = output_rate_handler;
}

template <typename data_t>
void OutputRateMonitor_Fac<data_t>::setup(int output_rate, void (*output_rate_handler)(), void* user_memory) {
	_constraint_output_rate = output_rate;
	_handler = output_rate_handler;
}

template <typename data_t>
void OutputRateMonitor_Fac<data_t>::update() {
	_current_output_rate++;
}

template <typename data_t>
void OutputRateMonitor_Fac<data_t>::check() {
	while(true) 
	{
		if(_current_output_rate < _constraint_output_rate) 
		{
			//printf("[Debugging] current_output_rate:%d\n", _current_output_rate);
			std::thread output_rate_handler(*_handler);
			output_rate_handler.detach();
		}
		//printf("[Debugging] _current_output_rate:%d\n", _current_output_rate);
		_current_output_rate = 0;
		sleep(1);
	}
}

template <typename data_t>
void OutputRateMonitor_Fac<data_t>::run() {
	std::thread output_rate_check_thread(&OutputRateMonitor_Fac<data_t>::check, this);
	output_rate_check_thread.detach();
}


/*
	Class Name: OutputDataPort_Fac
	Detail: OutputDataPort used by Processing Block in order to send data
	Class Variables:
		1. Five DataWriters
	Class Functions:
		1. int attach(Factory*, string, int)
		   -Function
			attaches the OutputDataPort to the Factory specified in the parameter
		   -Parameters
		   	a. Uses the Factory pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_Fac will be connected to
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
class OutputDataPort_Fac
{
	private:
		Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* _attachedFactory;

		OutputRateMonitor_Fac<Data_5> _output_rate_monitor_port0;
		OutputRateMonitor_Fac<Data_6> _output_rate_monitor_port1;
		OutputRateMonitor_Fac<Data_7> _output_rate_monitor_port2;
		OutputRateMonitor_Fac<Data_8> _output_rate_monitor_port3;
		OutputRateMonitor_Fac<Data_9> _output_rate_monitor_port4;

		int _topic_number = 5;
		void* _port_memory;

	public:
		dds::pub::DataWriter<Data_5>* Output_writer0;
		dds::pub::DataWriter<Data_6>* Output_writer1;
		dds::pub::DataWriter<Data_7>* Output_writer2;
		dds::pub::DataWriter<Data_8>* Output_writer3;
		dds::pub::DataWriter<Data_9>* Output_writer4;	
		
		dds::sub::DataReader<Data_5>* Output_connector0;
		dds::sub::DataReader<Data_6>* Output_connector1;
		dds::sub::DataReader<Data_7>* Output_connector2;
		dds::sub::DataReader<Data_8>* Output_connector3;
		dds::sub::DataReader<Data_9>* Output_connector4;	


		int attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, std::string, int);	

		void initialize (int rate, void (*rate_handler)());

		void checkOuputRate(int outputport_num);
		
};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void OutputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkOuputRate(int outputport_num) {
	if(outputport_num==0) _output_rate_monitor_port0.update();
	else if(outputport_num==1) _output_rate_monitor_port1.update();
	else if(outputport_num==2) _output_rate_monitor_port2.update();
	else if(outputport_num==3) _output_rate_monitor_port3.update();
	else if(outputport_num==4) _output_rate_monitor_port4.update();
}



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int OutputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* Fact, std::string topic, std::string connector_topic, int topic_number)
{
	_attachedFactory = Fact;		

	if(topic_number==5)
	{
		Fact->ODP0 = this;
		
		Fact->topic5 = new dds::topic::Topic<Data_5> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());

		Output_writer0 = new dds::pub::DataWriter<Data_5> ((*Fact).Output_pub,(*Fact->topic5),(*Fact).Output_pub.default_datawriter_qos());

		Fact->connector_topic5 = new dds::topic::Topic<Data_5> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector0 = new dds::sub::DataReader<Data_5> ((*Fact).Output_connector_sub, (*Fact->connector_topic5),(*Fact).Output_connector_sub.default_datareader_qos());
		
		Fact->connected_ports.set(5);
		return 1;
	}
	
	if(topic_number==6)
	{
		Fact->ODP1 = this;
		
		Fact->topic6 = new dds::topic::Topic<Data_6> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		Output_writer1 = new dds::pub::DataWriter<Data_6> ((*Fact).Output_pub,(*Fact->topic6),(*Fact).Output_pub.default_datawriter_qos());
	
		Fact->connector_topic6 = new dds::topic::Topic<Data_6> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector1 = new dds::sub::DataReader<Data_6> ((*Fact).Output_connector_sub, (*Fact->connector_topic6),(*Fact).Output_connector_sub.default_datareader_qos());

		Fact->connected_ports.set(6);
		return 1;
	}

	if(topic_number==7)
	{
		Fact->ODP2 = this;

		Fact->topic7 = new dds::topic::Topic<Data_7> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());

		Output_writer2 = new dds::pub::DataWriter<Data_7> ((*Fact).Output_pub,(*Fact->topic7),(*Fact).Output_pub.default_datawriter_qos());
		Fact->connector_topic7 = new dds::topic::Topic<Data_7> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector2 = new dds::sub::DataReader<Data_7> ((*Fact).Output_connector_sub, (*Fact->connector_topic7),(*Fact).Output_connector_sub.default_datareader_qos());
		
		Fact->connected_ports.set(7);
		return 1;
	}

	if(topic_number==8)
	{
		Fact->ODP3 = this;

		Fact->topic8 = new dds::topic::Topic<Data_8> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		
		Output_writer3 = new dds::pub::DataWriter<Data_8> ((*Fact).Output_pub,(*Fact->topic8),(*Fact).Output_pub.default_datawriter_qos());
		Fact->connector_topic8 = new dds::topic::Topic<Data_8> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector3 = new dds::sub::DataReader<Data_8> ((*Fact).Output_connector_sub, (*Fact->connector_topic8),(*Fact).Output_connector_sub.default_datareader_qos());

		Fact->connected_ports.set(8);
		return 1;
	}
	
	if(topic_number==9)
	{
		Fact->ODP4 = this;
		
		Fact->topic9 = new dds::topic::Topic<Data_9> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		
		Output_writer4 = new dds::pub::DataWriter<Data_9> ((*Fact).Output_pub,(*Fact->topic9),(*Fact).Output_pub.default_datawriter_qos());	
		Fact->connector_topic9 = new dds::topic::Topic<Data_9> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector4 = new dds::sub::DataReader<Data_9> ((*Fact).Output_connector_sub, (*Fact->connector_topic9),(*Fact).Output_connector_sub.default_datareader_qos());	
		
		Fact->connected_ports.set(9);
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
void OutputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (int rate, void (*rate_handler)())
{
	if(_topic_number==5)
	{
		_output_rate_monitor_port0.setup(rate, rate_handler, _port_memory);
		_output_rate_monitor_port0.run();
	}

	else if(_topic_number==6)
	{
		_output_rate_monitor_port1.setup(rate, rate_handler, _port_memory);
		_output_rate_monitor_port1.run();
	}

	else if(_topic_number==7)
	{
		_output_rate_monitor_port2.setup(rate, rate_handler, _port_memory);
		_output_rate_monitor_port2.run();
	}	

	else if(_topic_number==8)
	{
		_output_rate_monitor_port3.setup(rate, rate_handler, _port_memory);
		_output_rate_monitor_port3.run();
	}
	
	else if(_topic_number==9)
	{
		_output_rate_monitor_port4.setup(rate, rate_handler, _port_memory);
		_output_rate_monitor_port4.run();
	}	
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactory(std::vector<const char*> atomic_list)
{
	int child_id;
        for(int i=0;i<(int)atomic_list.size();i++)
        {
			child_id = fork();
		
			if(child_id==0)
			{
				execl(atomic_list[i],atomic_list[i],(char*)0);
			}
        }
}


template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::FIP_create(const int port_id)
{
	int inputport_id = port_id;

	std::cout<<"Activating Port: "<< inputport_id << std::endl;

	switch (inputport_id) {
		case 0: 
		{
			dds::sub::Sample<Data_0> sample_input0;
			Data_0 passing_sample_input0;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(IDP0->Input_reader0),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				iter_1 = input_data_1.begin();				
				IDP0->Input_reader0->take(iter_1,1);				

				sample_input0 = *iter_1;
				passing_sample_input0 = sample_input0->data();


				IDP0->checkFreshness(sample_input0->data().constraint_freshness_gentime());
				/* modify input sample data */
				updateDeadlineFIP( &(passing_sample_input0.constraint_deadline_duetime()) );

				IDP0->Input_connector0->write(passing_sample_input0);			

				//std::cout<<"RUNNING INPUT PORT 0"<< std::endl;
			}
			break;
		}

		case 1:
		{
			dds::sub::Sample<Data_1> sample_input1;
			Data_1 passing_sample_input1;	

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(IDP1->Input_reader1),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();
			
				iter_2 = input_data_2.begin();
				IDP1->Input_reader1->take(iter_2,1);				

				sample_input1 = *iter_2;
				passing_sample_input1 = sample_input1->data();

				IDP1->checkFreshness(sample_input1->data().constraint_freshness_gentime());
				/* modify input sample data */
				updateDeadlineFIP( &(passing_sample_input1.constraint_deadline_duetime()) );

				IDP1->Input_connector1->write(passing_sample_input1);			

				//std::cout<<"RUNNING INPUT PORT 1"<< std::endl;
			}
			break;
		}

		case 2:
		{
			dds::sub::Sample<Data_2> sample_input2;
			Data_2 passing_sample_input2;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(IDP2->Input_reader2),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				iter_3 = input_data_3.begin();
				IDP2->Input_reader2->take(iter_3,1);
				
				sample_input2 = *iter_3;
				passing_sample_input2 = sample_input2->data();

				IDP2->checkFreshness(sample_input2->data().constraint_freshness_gentime());
				/* modify input sample data */
				updateDeadlineFIP( &(passing_sample_input2.constraint_deadline_duetime()) );

				IDP2->Input_connector2->write(passing_sample_input2);
			}
			break;
		}

		case 3:
		{
			dds::sub::Sample<Data_3> sample_input3;
			Data_3 passing_sample_input3;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(IDP3->Input_reader3),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				iter_4 = input_data_4.begin();
				IDP3->Input_reader3->take(iter_4,1);
				
				sample_input3 = *iter_4;
				passing_sample_input3 = sample_input3->data();

				IDP3->checkFreshness(sample_input3->data().constraint_freshness_gentime());
				/* modify input sample data */
				updateDeadlineFIP( &(passing_sample_input3.constraint_deadline_duetime()) );

				IDP3->Input_connector3->write(passing_sample_input3);
			}
			break;
		}

		case 4:
		{
			dds::sub::Sample<Data_4> sample_input4;
			Data_4 passing_sample_input4;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(IDP4->Input_reader4),dds::sub::status::DataState::new_data());


			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				iter_5 = input_data_5.begin();
				IDP4->Input_reader4->take(iter_5,1);
				
				sample_input4 = *iter_5;
				passing_sample_input4 = sample_input4->data();

				IDP4->checkFreshness(sample_input4->data().constraint_freshness_gentime());
				/* modify input sample data */
				updateDeadlineFIP( &(passing_sample_input4.constraint_deadline_duetime()) );

				IDP4->Input_connector4->write(passing_sample_input4);
			}	
			break;
		}

		default:
		{
			fprintf(stderr, "unknown factory input port id: %d\n", inputport_id);
			exit(EXIT_FAILURE);
			break;
		}
	}
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::FOP_create(const int port_id)
{
	int outputport_id = port_id;

	std::cout<<"Activating Port: "<< outputport_id << std::endl;

	switch (outputport_id) {
		case 5: 
		{
			dds::sub::Sample<Data_5> sample_output0;
			Data_5 passing_sample_output0;	

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(ODP0->Output_connector0),dds::sub::status::DataState::new_data());

			while(true)
			{	
				ws.attach_condition(rc);
				ws.wait();

				connector_iter_1 = output_connector_data_1.begin();				
				ODP0->Output_connector0->take(connector_iter_1,1);

				sample_output0 = *connector_iter_1;			
				passing_sample_output0 = sample_output0->data();

				checkDeadline(passing_sample_output0.constraint_deadline_duetime());
				ODP0->checkOuputRate(0);

				ODP0->Output_writer0->write(passing_sample_output0);		

				std::cout<<"[Debugging] RUNNING OUTPUT PORT 0("<<SystemClock::getCurrentTime()<<")"<< std::endl;
			}
			break;
		}

		case 6:
		{
			dds::sub::Sample<Data_6> sample_output1;
			Data_6 passing_sample_output1;	

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(ODP1->Output_connector1),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				connector_iter_2 = output_connector_data_2.begin();
				ODP1->Output_connector1->take(connector_iter_2,1);

				sample_output1 = *connector_iter_2;
				passing_sample_output1 = sample_output1->data();

				checkDeadline(passing_sample_output1.constraint_deadline_duetime());
				ODP1->checkOuputRate(1);


				ODP1->Output_writer1->write(passing_sample_output1);
			}
			break;
		}

		case 7:
		{
			dds::sub::Sample<Data_7> sample_output2;
			Data_7 passing_sample_output2;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(ODP2->Output_connector2),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				ODP2->Output_connector2->take(connector_iter_3,1);
				connector_iter_3 = output_connector_data_3.begin();


				sample_output2 = *connector_iter_3;
				passing_sample_output2 = sample_output2->data();

				checkDeadline(passing_sample_output2.constraint_deadline_duetime());
				ODP2->checkOuputRate(2);


				ODP2->Output_writer2->write(passing_sample_output2);
			}
			break;
		}

		case 8:
		{
			dds::sub::Sample<Data_8> sample_output3;
			Data_8 passing_sample_output3;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(ODP3->Output_connector3),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				connector_iter_4 = output_connector_data_4.begin();				
				ODP3->Output_connector3->take(connector_iter_4,1);

				sample_output3 = *connector_iter_4;
				passing_sample_output3 = sample_output3->data();

				checkDeadline(passing_sample_output3.constraint_deadline_duetime());
				ODP3->checkOuputRate(3);

				ODP3->Output_writer3->write(passing_sample_output3);
			}
			break;
		}

		case 9:
		{
			dds::sub::Sample<Data_9> sample_output4;
			Data_9 passing_sample_output4;

			dds::core::cond::WaitSet ws;
			dds::sub::cond::ReadCondition rc(*(ODP4->Output_connector4),dds::sub::status::DataState::new_data());

			while(true)
			{
				ws.attach_condition(rc);
				ws.wait();

				connector_iter_5 = output_connector_data_5.begin();				
				ODP2->Output_connector3->take(connector_iter_5,1);

				sample_output4 = *connector_iter_5;
				passing_sample_output4 = sample_output4->data();

				checkDeadline(passing_sample_output4.constraint_deadline_duetime());
				ODP4->checkOuputRate(4);

				ODP4->Output_writer4->write(passing_sample_output4);
			}
			break;
		}

		default:
		{
			fprintf(stderr, "unknown factory output port id: %d\n", outputport_id);
			exit(EXIT_FAILURE);
			break;
		}
	}		
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactoryPort_in()
{
	// TODO: remove magic number. 5 is the number of maximum factory input ports 
	
	for(int port_id=0; port_id<5; port_id++)
	{
		if(connected_ports.test(port_id))
		{
			FIP_pthreads[port_id] = new std::thread(
				&Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::FIP_create, 
				this, port_id);

			//TODO: Connection existence error code

			FIP_pthreads[port_id]->detach();
		}
	}
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactoryPort_out()
{
	// TODO: remove magic number. 5 is the number of maximum factory output ports 

	//std::vector<std::thread *> FOP_pthreads(5);

	for(int port_id=5; port_id<10; port_id++)
	{
		if(connected_ports.test(port_id))
		{
			FOP_pthreads[port_id-5] = new std::thread(
				&Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::FOP_create, 
				this, port_id);

			//TODO: Connection existence error code

			FOP_pthreads[port_id-5]->detach();
		}
	}
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (std::string name, int64_t deadline, void(*deadline_handler)(), int node_id, int core_id)
{
	setDeadline(deadline, deadline_handler);
}

#endif