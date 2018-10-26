#ifndef _PROCESSING_BLOCK_CPP_
#define _PROCESSING_BLOCK_CPP_

#define NDEBUG

#ifndef NDEBUG
#define dp(fmt,args...) printf(fmt,##args)
#else
#define dp(fmt,args...)
#endif

#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <bitset>


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

/**
*	@brief Clock class of current system.
*	@details This clock implemented by using std::chrono library. DDS independent class.
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/

class SystemClock {
private:
public:
		static int64_t getCurrentTime();
};

int64_t SystemClock::getCurrentTime() {
	std::chrono::time_point<std::chrono::high_resolution_clock> _current_time;
	_current_time = std::chrono::high_resolution_clock::now();
	auto duetime_current = _current_time.time_since_epoch();
	int64_t current_time = std::chrono::duration_cast<std::chrono::milliseconds>(duetime_current).count();
	
	return current_time;
}

/**
*	@brief Detect freshness constraint violation 
*	@details 
*	@todo modify check() to correspond with new definition of message timestamp.
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/


class FreshnessMonitor_IP {
	public:
		void setup(int64_t freshness, void (*freshness_handler)());
		int check(int64_t msg_gentime);

	private:
		int64_t _constraint_freshness = -1;
		int64_t _latest_msg_gentime = -1;
		void (*_handler)();
};

void FreshnessMonitor_IP::setup(int64_t freshness, void (*freshness_handler)()) {
	_constraint_freshness = freshness;
	_handler = freshness_handler;
}


int FreshnessMonitor_IP::check(int64_t msg_gentime) {
	if(_constraint_freshness==-1 || _handler==NULL) return true;

	//printf("[Debugging] FreshnessMonitor_IP::check()\n");
	//printf("[Debugging] SystemClock::getCurrentTime():%ld\n", SystemClock::getCurrentTime());
	//printf("[Debugging] msg_gentime:%ld\n", msg_gentime);
	//printf("[Debugging] _constraint_freshness:%ld\n", _constraint_freshness);	

	if(SystemClock::getCurrentTime() - msg_gentime > _constraint_freshness) {
		//printf("[Debugging] inputport deadline violation\n");
		std::thread thread_handler(*_handler);
		thread_handler.detach();
		return false;
	}
	else return true;
}


/**
*	@brief Detect deadline constraint violation 
*	@details 
*	@todo modify setup() and check() to correspond with new definition of message timestamp and deadline constraint
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/


class DeadlineMonitor_PB {
	public:
		void setup(int64_t deadline, void (*deadline_handler)());
		void mapPort(int inputport_num, int outputport_num);
		void save(int inputport_num);
		int64_t load(int inputport_num);
		int findInputPort(int outputport_num);
		int check(int intputport_num);

	private:
		std::bitset<5> _port_mapping[5];
		int64_t _constraint_deadline = -1;
		int64_t _inputport_input_time[5];
		void (*_handler)();
};

void DeadlineMonitor_PB::setup(int64_t deadline, void (*deadline_handler)()) {
	_constraint_deadline = deadline;
	_handler = deadline_handler;
}

void DeadlineMonitor_PB::mapPort(int inputport_num, int outputport_num) {
	_port_mapping[outputport_num].set(inputport_num);
}

void DeadlineMonitor_PB::save(int inputport_num) {
	//printf("[Debugging] save()\n");
	//printf("[Debugging] _inputport_input_time[inputport_num]:%ld\n", SystemClock::getCurrentTime());	
	_inputport_input_time[inputport_num] = SystemClock::getCurrentTime();
}

int64_t DeadlineMonitor_PB::load(int inputport_num) {
	return _inputport_input_time[inputport_num];
}

int DeadlineMonitor_PB::findInputPort(int outputport_num) {
	int inputport_num;
	for(inputport_num=0; inputport_num<5; inputport_num++) {
		if(_port_mapping[outputport_num].test(inputport_num)) return inputport_num;
	}

	return -1; // error case
}

int DeadlineMonitor_PB::check(int inputport_num) {
	if(_constraint_deadline==-1 || _handler==NULL) return true;

	//printf("[Debugging] check()\n");
	//printf("[Debugging] SystemClock::getCurrentTime():%ld\n", SystemClock::getCurrentTime());
	//printf("[Debugging] inputport_input_time[inputport_num]:%ld\n", _inputport_input_time[inputport_num]);
	//printf("[Debugging] _constraint_deadline:%ld\n", _constraint_deadline);	

	if(SystemClock::getCurrentTime() - _inputport_input_time[inputport_num] > _constraint_deadline) {
		//printf("[Debugging] processingblock deadline violation\n");
		std::thread thread_handler(*_handler);
		thread_handler.detach();
		return false;
	}
	else return true;
}

/**
*	@brief Pass two time constriant variables from input messages to output messages.
*	@details 
*	@todo modify every methods to correspond with new definition of message timestamp and deadline constraint
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/


class ConstraintPassingManager_PB {
public:
	void setPortMappingFreshness(int inputport_num, int outputport_num);
	void setPortMappingFactoryDeadline(int inputport_num, int outputport_num);
	//void setPortMappingProcessingBlockDeadline(int inputport_num, int outputport_num);

	void saveFreshness(int inputport_num, int64_t gentime);
	void saveFactoryDeadline(int inputport_num, int64_t duetime);
	//void saveProcessingBlockDeadline(int inputport_num, int64_t arrive_time);

	int64_t loadFreshness(int inputport_num);
	int64_t loadFactoryDeadline(int inputport_num);
	//int64_t loadProcessingBlockDeadline(int inputport_num);	

	int findInputPortFreshness(int outputport_num);
	int findInputPortFactoryDeadline(int outputport_num);
	//int findInputPortProcessingBlockDeadline(int outputport_num);

	int64_t takeFreshness(int outputport_num); // return one of the input time
	int64_t takeFactoryDeadline(int outputport_num);
	//int64_t takeProcessingBlockDeadline(int outputport_num);	

private:

	std::bitset<5> _freshness_port_mapping[5];
	std::bitset<5> _factory_deadline_port_mapping[5]; // c.f. _port_mappint[0].set(2): <inputport 2>--(factory deadline)--><outputport 0>
	//std::bitset<5> _procssingblock_deadline_port_mapping[5];

	int64_t _freshnesses[5] = {-1, -1, -1, -1, -1};
	int64_t _factory_deadlines[5] = {-1, -1, -1, -1, -1};
	//int64_t _processingblock_deadlines[5];

};

void ConstraintPassingManager_PB::setPortMappingFreshness(int inputport_num, int outputport_num) {
	_freshness_port_mapping[outputport_num].set(inputport_num);
}

void ConstraintPassingManager_PB::setPortMappingFactoryDeadline(int inputport_num, int outputport_num) {
	_factory_deadline_port_mapping[outputport_num].set(inputport_num);
}

/*void ConstraintPassingManager_PB::setPortMappingProcessingBlockDeadline(int inputport_num, int outputport_num) {
	_procssingblock_deadline_port_mapping[outputport_num].set(inputport_num);
}*/

void ConstraintPassingManager_PB::saveFreshness(int inputport_num, int64_t gentime) {
	////printf("[Debugging] saveFreshness [inputport_num:%d, gentime:%ld]\n", inputport_num, gentime);
	_freshnesses[inputport_num] = gentime;
}

void ConstraintPassingManager_PB::saveFactoryDeadline(int inputport_num, int64_t duetime) {
	////printf("[Debugging] storeDeadline [inputport_num:%d, duetime:%ld]\n", inputport_num, duetime);
	_factory_deadlines[inputport_num] = duetime;
}

/*void ConstraintPassingManager_PB::saveProcessingBlockDeadline(int inputport_num, int64_t arrive_time) {
	_processingblock_deadlines[inputport_num] = arrive_time;
}*/

int64_t ConstraintPassingManager_PB::loadFreshness(int inputport_num) {
	return _freshnesses[inputport_num];
}

int64_t ConstraintPassingManager_PB::loadFactoryDeadline(int inputport_num) {
	return _factory_deadlines[inputport_num];
}

/*int64_t ConstraintPassingManager_PB::loadProcessingBlockDeadline(int inputport_num) {
	return _processingblock_deadlines[inputport_num];
}
*/
int ConstraintPassingManager_PB::findInputPortFreshness(int outputport_num) {
	int inputport_num;
	for(inputport_num=0; inputport_num<5; inputport_num++) {
		if(_freshness_port_mapping[outputport_num].test(inputport_num)) return inputport_num;
	}

	return -1; // error case
}

int ConstraintPassingManager_PB::findInputPortFactoryDeadline(int outputport_num) {
	int inputport_num;
	for(inputport_num=0; inputport_num<5; inputport_num++) {
		if(_factory_deadline_port_mapping[outputport_num].test(inputport_num)) return inputport_num;
	}

	return -1; // error case
}

/*int ConstraintPassingManager_PB::findInputPortProcessingBlockDeadline(int outputport_num) {
	int inputport_num;
	for(inputport_num=0; inputport_num<5; inputport_num++) {
		if(_procssingblock_deadline_port_mapping[outputport_num].test(inputport_num)) return inputport_num;
	}

	return -1; // error case
}*/

int64_t ConstraintPassingManager_PB::takeFreshness(int outputport_num) {
	int inputport_num = findInputPortFreshness(outputport_num);
	if(inputport_num != -1) return _freshnesses[inputport_num];
	else return -1; // error case
}

int64_t ConstraintPassingManager_PB::takeFactoryDeadline(int outputport_num) {
	int inputport_num = findInputPortFactoryDeadline(outputport_num);
	if(inputport_num != -1)	return _factory_deadlines[inputport_num];
	else return -1; // error case
}

/**
*	@brief Splash LanguageConstructs > ComponentType > AtomicComponentType > ProcessingBlockType
*	@details The smallest execution unit of stream processing. Takes data elements as inputs, performs predefined operation, and returns data elements as outputs.
*	@author Jaeho Ahn, Beomjoon Yang
*	@date 2018-10-25
*	@version 0.0.1 
*/

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class ProcessingBlock
{
	public:	
		enum PB_TYPE: int {
			SOURCE,
			NORMAL,
			SINK
		};

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

		// int write(Data_5, int64_t input_time);
		// int write(Data_6, int64_t input_time);
		// int write(Data_7, int64_t input_time);	
		// int write(Data_8, int64_t input_time);
		// int write(Data_9, int64_t input_time);
		
		int write_event(int);
		
		void read(dds::sub::Sample<Data_0>*);
		void read(dds::sub::Sample<Data_1>*);
		void read(dds::sub::Sample<Data_2>*);
		void read(dds::sub::Sample<Data_3>*);
		void read(dds::sub::Sample<Data_4>*);
		
		void initialize(ProcessingBlock::PB_TYPE type, std::string name, int64_t deadline, void(*deadline_handler)(), int period, bool time_trigger, int core_id);

		void spin();

		void setProcessingBlockDeadline(int64_t deadline, void (*deadline_handler)());
		void checkProcessingBlockDeadline(int outputport_num); // this function called by write()

		void passProcessingDeadline(int inputport_num, int outputport_num);
		void passFactoryDeadline(int inputport_num, int outputport_num);
		void passFreshness(int inputport_num, int outputport_num);

	private:
		ConstraintPassingManager_PB _constraint_passing_manager;
		DeadlineMonitor_PB _deadline_monitor;	
		PB_TYPE _type;
		
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::setProcessingBlockDeadline(int64_t deadline, void (*deadline_handler)()) {
	_deadline_monitor.setup(deadline, deadline_handler);
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkProcessingBlockDeadline(int outputport_num) {
	//printf("[Debugging] checkProcessingBlockDeadline\n");
	int inputport_num = _deadline_monitor.findInputPort(outputport_num);
	_deadline_monitor.check(inputport_num);
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::passProcessingDeadline(int inputport_num, int outputport_num) {
	_deadline_monitor.mapPort(inputport_num, outputport_num);
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::passFactoryDeadline(int inputport_num, int outputport_num) {
	_constraint_passing_manager.setPortMappingFactoryDeadline(inputport_num, outputport_num);
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::passFreshness(int inputport_num, int outputport_num) {
	_constraint_passing_manager.setPortMappingFreshness(inputport_num, outputport_num);
}


template
<typename data_t>
class SplashDataReaderListener : public dds::sub::NoOpDataReaderListener<data_t>
{
	public:
		int rate=0;
		virtual void on_data_available(dds::sub::DataReader<data_t>& dr)
		{
			rate++;
		}

};

/**
*	@brief detect input rate constriant violation
*	@details 
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/

template <typename data_t>
class InputRateMonitor_PB {
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
void InputRateMonitor_PB<data_t>::setup(int input_rate, void (*input_rate_handler)()) {
	_constraint_input_rate = input_rate;
	_handler = input_rate_handler;
}

template <typename data_t>
void InputRateMonitor_PB<data_t>::setup(int input_rate, void (*input_rate_handler)(), void* user_memory) {
	_constraint_input_rate = input_rate;
	_handler = input_rate_handler;
}

template <typename data_t>
void InputRateMonitor_PB<data_t>::check() {
	while(true)
	{
		int current_input_rate = _listener->rate;
		if(current_input_rate < _constraint_input_rate)
		{
			printf("[Debugging] current_input_rate:%d\n", current_input_rate);	
			std::thread input_rate_handler(*_handler);
			input_rate_handler.detach();
		}
		
		_listener->rate = 0;
		sleep(1);
	}
}

template <typename data_t>
void InputRateMonitor_PB<data_t>::run() {
	std::thread input_rate_check_thread(&InputRateMonitor_PB<data_t>::check, this);
	input_rate_check_thread.detach();
}

template <typename data_t>
void InputRateMonitor_PB<data_t>::setListener(SplashDataReaderListener<data_t>* input_rate_listener) {
	_listener = input_rate_listener;
}

template <typename data_t>
SplashDataReaderListener<data_t>* InputRateMonitor_PB<data_t>::ptr_listener() {
	return _listener;
}

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

/**
*	@brief Splash LanguageConstructs > PortPrototype > ReceiveInterface > InputStreamPort
*	@details A input data port used by Processing Block in order to receive data
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

class InputDataPort_PB
{
	private:
		FreshnessMonitor_IP _freshness_monitor;

		InputRateMonitor_PB<Data_0> _input_rate_monitor_port0;
		InputRateMonitor_PB<Data_1> _input_rate_monitor_port1;
		InputRateMonitor_PB<Data_2> _input_rate_monitor_port2;
		InputRateMonitor_PB<Data_3> _input_rate_monitor_port3;
		InputRateMonitor_PB<Data_4> _input_rate_monitor_port4;

		void* _port_memory;

	public:
		
		dds::sub::DataReader<Data_0>* IDP_reader0;
		dds::sub::DataReader<Data_1>* IDP_reader1;	
		dds::sub::DataReader<Data_2>* IDP_reader2;
		dds::sub::DataReader<Data_3>* IDP_reader3;
		dds::sub::DataReader<Data_4>* IDP_reader4;
	

		int topic_number=0;
		
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);
		void initialize(int rate, void (*rate_handler)(), int freshness, void (*freshness_handler)(), bool queueing, int queue_size);

		void setFreshness(int64_t freshness, void (*freshness_handler)());	
		void checkFreshness(int64_t msg_gentime);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::setFreshness(int64_t freshness, void (*freshness_handler)())
{
	_freshness_monitor.setup(freshness, freshness_handler);
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkFreshness(int64_t msg_gentime)
{
	_freshness_monitor.check(msg_gentime);
}

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
		_input_rate_monitor_port0.setListener(new SplashDataReaderListener<Data_0>);
		
		PB->IDP0 = this;		
		
		PB->topic0 = new dds::topic::Topic<Data_0> {(*PB).default_dp, topic,(*PB).default_dp.default_topic_qos()};
		IDP_reader0 = new dds::sub::DataReader<Data_0>{(*PB).PB_sub, (*PB->topic0),(*PB).PB_sub.default_datareader_qos()};

		IDP_reader0->listener(_input_rate_monitor_port0.ptr_listener(), dds::core::status::StatusMask::data_available());
		

		return 1;
	}		

	if(topic_number==1)
	{
		this->topic_number = topic_number;
		_input_rate_monitor_port1.setListener(new SplashDataReaderListener<Data_1>);
		
		PB->IDP1 = this;			

		PB->topic1 = new dds::topic::Topic<Data_1> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader1= new dds::sub::DataReader<Data_1>((*PB).PB_sub, (*PB->topic1),(*PB).PB_sub.default_datareader_qos());

		IDP_reader1->listener(_input_rate_monitor_port1.ptr_listener(), dds::core::status::StatusMask::data_available());		
	
		return 1;
	}

	if(topic_number==2)
	{
		this->topic_number = topic_number;
		_input_rate_monitor_port2.setListener(new SplashDataReaderListener<Data_2>);
		
		PB->IDP2 = this;		

		PB->topic2 = new dds::topic::Topic<Data_2> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader2 = new dds::sub::DataReader<Data_2> ((*PB).PB_sub, (*PB->topic2),(*PB).PB_sub.default_datareader_qos());
	
		IDP_reader2->listener(_input_rate_monitor_port2.ptr_listener(), dds::core::status::StatusMask::data_available());	
	
		return 1;
	}
	if(topic_number==3)
	{
		this->topic_number = topic_number;			
		_input_rate_monitor_port3.setListener(new SplashDataReaderListener<Data_3>);

		PB->IDP3 = this;
		
		PB->topic3 = new dds::topic::Topic<Data_3> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader3 = new dds::sub::DataReader<Data_3> ((*PB).PB_sub, (*PB->topic3),(*PB).PB_sub.default_datareader_qos());
		
		IDP_reader3->listener(_input_rate_monitor_port3.ptr_listener(), dds::core::status::StatusMask::data_available());	

		return 1;
	}	

	if(topic_number==4)
	{
		this->topic_number = topic_number;	
		_input_rate_monitor_port4.setListener(new SplashDataReaderListener<Data_4>);

		PB->IDP4 = this;	

		PB->topic4 = new dds::topic::Topic<Data_4> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader4 = new dds::sub::DataReader<Data_4> ((*PB).PB_sub, (*PB->topic4),(*PB).PB_sub.default_datareader_qos());
		
		IDP_reader4->listener(_input_rate_monitor_port4.ptr_listener(), dds::core::status::StatusMask::data_available());	

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

void InputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (int rate, void (*rate_handler)(), int freshness, void (*freshness_handler)(), bool queueing, int queue_size)
{
	setFreshness(freshness, freshness_handler);

	if((this->topic_number)==0)
	{
		_input_rate_monitor_port0.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port0.run();
		/*
		std::thread rate_check_thread_0 (rate_check<Data_0>,rate,listener_0,port_memory,rate_handler);
		rate_check_thread_0.detach();
		*/
	}

	else if((this->topic_number)==1)
	{
		_input_rate_monitor_port1.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port1.run();
	}

	else if((this->topic_number)==2)
	{
		_input_rate_monitor_port2.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port2.run();
	}	

	else if(this->topic_number==3)
	{
		_input_rate_monitor_port3.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port3.run();
	}
	
	else if(this->topic_number==4)
	{
		_input_rate_monitor_port4.setup(rate, rate_handler, _port_memory);
		_input_rate_monitor_port4.run();
	}	

}

/*template <typename data_t>
class SplashDataWriterListener : public dds::pub::NoOpDataWriterListener<data_t>
{
	public:
		int rate=0;
		virtual void on_data_available(dds::pub::DataWriter<data_t>& dr)
		{
			rate++;
			printf("[Debugging] increse output rate:%d\n", rate);
		}

};*/

/**
*	@brief detect output rate constriant violation
*	@details 
*	@author Beomjoon Yang
*	@date 2018-10-26
*	@version 0.0.1 
*/

template <typename data_t>
class OutputRateMonitor_PB {
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
void OutputRateMonitor_PB<data_t>::setup(int output_rate, void (*output_rate_handler)()) {
	_constraint_output_rate = output_rate;
	_handler = output_rate_handler;
}

template <typename data_t>
void OutputRateMonitor_PB<data_t>::setup(int output_rate, void (*output_rate_handler)(), void* user_memory) {
	_constraint_output_rate = output_rate;
	_handler = output_rate_handler;
}

template <typename data_t>
void OutputRateMonitor_PB<data_t>::update() {
	_current_output_rate++;
}

template <typename data_t>
void OutputRateMonitor_PB<data_t>::check() {
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
void OutputRateMonitor_PB<data_t>::run() {
	std::thread output_rate_check_thread(&OutputRateMonitor_PB<data_t>::check, this);
	output_rate_check_thread.detach();
}


/*template <typename data_t>
void OutputRateMonitor_PB<data_t>::setListener(SplashDataWriterListener<data_t>* output_rate_listener) {
	_listener = output_rate_listener;
}


template <typename data_t>
SplashDataWriterListener<data_t>* OutputRateMonitor_PB<data_t>::ptr_listener() {
	return _listener;
}*/



/**
*	@brief Splash LanguageConstructs > PortPrototype > ReceiveInterface > OutputStreamPort
*	@details A output data port used by Processing Block in order to sned data
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
class OutputDataPort_PB
{
	private:
		OutputRateMonitor_PB<Data_5> _output_rate_monitor_port0;
		OutputRateMonitor_PB<Data_6> _output_rate_monitor_port1;
		OutputRateMonitor_PB<Data_7> _output_rate_monitor_port2;
		OutputRateMonitor_PB<Data_8> _output_rate_monitor_port3;
		OutputRateMonitor_PB<Data_9> _output_rate_monitor_port4;

		int _topic_number = 5;

		void* _port_memory;

	public:
		dds::pub::DataWriter<Data_5>* ODP_writer0;
		dds::pub::DataWriter<Data_6>* ODP_writer1;
		dds::pub::DataWriter<Data_7>* ODP_writer2;
		dds::pub::DataWriter<Data_8>* ODP_writer3;
		dds::pub::DataWriter<Data_9>* ODP_writer4;
		


		//int output_rate;	
		int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);	
		void initialize(int rate, void (*rate_handler)());

		void checkOuputRate(int outputport_num);
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void OutputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::checkOuputRate(int outputport_num) {
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
int OutputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic, int topic_number)
{
	_topic_number = topic_number;

	if(topic_number==5)
	{
		//_output_rate_monitor_port0.setListener(new SplashDataWriterListener<Data_5>);

		PB->ODP0 = this;		
		PB->topic5 = new dds::topic::Topic<Data_5> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		ODP_writer0 = new dds::pub::DataWriter<Data_5> ((*PB).PB_pub,(*PB->topic5),(*PB).PB_pub.default_datawriter_qos());
		//ODP_writer0->listener(_output_rate_monitor_port0.ptr_listener(), dds::core::status::StatusMask::data_available());
		
		return 1;
	}
	
	if(topic_number==6)
	{
		//_output_rate_monitor_port1.setListener(new SplashDataWriterListener<Data_6>);

		PB->ODP1 = this;		
		PB->topic6 = new dds::topic::Topic<Data_6> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		ODP_writer1 = new dds::pub::DataWriter<Data_6> ((*PB).PB_pub,(*PB->topic6),(*PB).PB_pub.default_datawriter_qos());
		//ODP_writer1->listener(_output_rate_monitor_port1.ptr_listener(), dds::core::status::StatusMask::data_available());

		return 1;
	}

	if(topic_number==7)
	{
		//_output_rate_monitor_port2.setListener(new SplashDataWriterListener<Data_7>);

		PB->ODP2 = this;

		PB->topic7 = new dds::topic::Topic<Data_7> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());

		ODP_writer2 = new dds::pub::DataWriter<Data_7> ((*PB).PB_pub,(*PB->topic7),(*PB).PB_pub.default_datawriter_qos());
		//ODP_writer2->listener(_output_rate_monitor_port2.ptr_listener(), dds::core::status::StatusMask::data_available());
		
		return 1;
	}

	if(topic_number==8)
	{
		//_output_rate_monitor_port3.setListener(new SplashDataWriterListener<Data_8>);

		PB->ODP3 = this;

		PB->topic8 = new dds::topic::Topic<Data_8> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		
		ODP_writer3 = new dds::pub::DataWriter<Data_8> ((*PB).PB_pub,(*PB->topic8),(*PB).PB_pub.default_datawriter_qos());
		//ODP_writer3->listener(_output_rate_monitor_port3.ptr_listener(), dds::core::status::StatusMask::data_available());
	
		return 1;
	}
	
	if(topic_number==9)
	{
		//_output_rate_monitor_port4.setListener(new SplashDataWriterListener<Data_9>);

		PB->ODP4 = this;
		
		PB->topic9 = new dds::topic::Topic<Data_9> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());
		
		ODP_writer4 = new dds::pub::DataWriter<Data_9> ((*PB).PB_pub,(*PB->topic9),(*PB).PB_pub.default_datawriter_qos());	
		//ODP_writer4->listener(_output_rate_monitor_port4.ptr_listener(), dds::core::status::StatusMask::data_available());
	
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
void OutputDataPort_PB<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (int rate, void (*rate_handler)())
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

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_5 Data)
{
	//printf("[Debugging] write(Data_5 Data)\n");


	checkProcessingBlockDeadline(0);
	Data.constraint_deadline_duetime(_constraint_passing_manager.takeFactoryDeadline(0));
	if(_type == ProcessingBlock::SOURCE) 
		Data.constraint_freshness_gentime(SystemClock::getCurrentTime());
	else if(_type == ProcessingBlock::NORMAL) 
		Data.constraint_freshness_gentime(_constraint_passing_manager.takeFreshness(0));
	ODP0->checkOuputRate(0);

	//printf("[Debugging] sending message information:\n");
	//printf("[Debugging] ==============[current time: %ld]==============\n", SystemClock::getCurrentTime());
	//printf("[Debugging] id:%d\n", Data.id());
	//printf("[Debugging] message:%s\n", Data.message().c_str());
	//printf("[Debugging] constraint_deadline_duetime:%ld\n", Data.constraint_deadline_duetime());
	//printf("[Debugging] constraint_freshness_gentime:%ld\n", Data.constraint_freshness_gentime());
	//printf("[Debugging] ============================\n");


	ODP0->ODP_writer0->write(Data);

	////printf("[Debugging] write(Data_5 Data end)\n");

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
	checkProcessingBlockDeadline(1);
	Data.constraint_deadline_duetime(_constraint_passing_manager.takeFactoryDeadline(1));
	if(_type == ProcessingBlock::SOURCE) 
		Data.constraint_freshness_gentime(SystemClock::getCurrentTime());
	else if(_type == ProcessingBlock::NORMAL) 
		Data.constraint_freshness_gentime(_constraint_passing_manager.takeFreshness(1));
	ODP1->checkOuputRate(1);	

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
	checkProcessingBlockDeadline(2);
	Data.constraint_deadline_duetime(_constraint_passing_manager.takeFactoryDeadline(2));
	if(_type == ProcessingBlock::SOURCE) 
		Data.constraint_freshness_gentime(SystemClock::getCurrentTime());
	else if(_type == ProcessingBlock::NORMAL) 
		Data.constraint_freshness_gentime(_constraint_passing_manager.takeFreshness(2));
	ODP2->checkOuputRate(2);		

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
	checkProcessingBlockDeadline(3);
	Data.constraint_deadline_duetime(_constraint_passing_manager.takeFactoryDeadline(3));
	if(_type == ProcessingBlock::SOURCE) 
		Data.constraint_freshness_gentime(SystemClock::getCurrentTime());
	else if(_type == ProcessingBlock::NORMAL) 
		Data.constraint_freshness_gentime(_constraint_passing_manager.takeFreshness(3));	
	ODP3->checkOuputRate(3);	

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
	checkProcessingBlockDeadline(4);
	Data.constraint_deadline_duetime(_constraint_passing_manager.takeFactoryDeadline(4));
	if(_type == ProcessingBlock::SOURCE) 
		Data.constraint_freshness_gentime(SystemClock::getCurrentTime());
	else if(_type == ProcessingBlock::NORMAL) 
		Data.constraint_freshness_gentime(_constraint_passing_manager.takeFreshness(4));	
	ODP4->checkOuputRate(4);

	ODP4->ODP_writer4->write(Data);
	return 1;
}


/* Remove this codes: write(Data_*, int input_time)
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_5 Data, int64_t input_time)
{
	int64_t curr_time = SystemClock::getCurrentTime() ;

	printf("%d - %d = %d\n",curr_time,input_time,curr_time-input_time);
	int diff = curr_time-input_time;
	printf("%d\n",diff);	
	if(diff>deadline_constraint)
	{
	}
	ODP0->output_rate++;
	ODP0->ODP_writer0->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_6 Data, int64_t input_time)
{
	
	ODP1->output_rate++;
	ODP1->ODP_writer1->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_7 Data, int64_t input_time)
{
	ODP2->output_rate++;
	ODP2->ODP_writer2->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_8 Data, int64_t input_time)
{
	ODP3->output_rate++;
	ODP3->ODP_writer3->write(Data);
	return 1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_9 Data, int64_t input_time)
{
	ODP4->output_rate++;
	ODP4->ODP_writer4->write(Data);
	return 1;
}
*/

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

	IDP0->checkFreshness(samples->data().constraint_freshness_gentime());

		/* constraints-related input time save */
	_deadline_monitor.save(0);
	_constraint_passing_manager.saveFactoryDeadline(0, samples->data().constraint_deadline_duetime());
	_constraint_passing_manager.saveFreshness(0, samples->data().constraint_freshness_gentime());
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

	IDP1->checkFreshness(samples->data().constraint_freshness_gentime());

	/* constraints-related input time save */
	_deadline_monitor.save(1);
	_constraint_passing_manager.saveFactoryDeadline(1, samples->data().constraint_deadline_duetime());
	_constraint_passing_manager.saveFreshness(1, samples->data().constraint_freshness_gentime());

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

	IDP2->checkFreshness(samples->data().constraint_freshness_gentime());

	/* constraints-related input time save */
	_deadline_monitor.save(2);
	_constraint_passing_manager.saveFactoryDeadline(2, samples->data().constraint_deadline_duetime());
	_constraint_passing_manager.saveFreshness(2, samples->data().constraint_freshness_gentime());


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

	IDP3->checkFreshness(samples->data().constraint_freshness_gentime());

	/* constraints-related input time save */
	_deadline_monitor.save(3);
	_constraint_passing_manager.saveFactoryDeadline(3, samples->data().constraint_deadline_duetime());
	_constraint_passing_manager.saveFreshness(3, samples->data().constraint_freshness_gentime());


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

	IDP4->checkFreshness(samples->data().constraint_freshness_gentime());

	/* constraints-related input time save */
	_deadline_monitor.save(4);
	_constraint_passing_manager.saveFactoryDeadline(4, samples->data().constraint_deadline_duetime());
	_constraint_passing_manager.saveFreshness(4, samples->data().constraint_freshness_gentime());


}



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (ProcessingBlock::PB_TYPE type, std::string name, int64_t deadline, void(*deadline_handler)(), int period, bool time_trigger, int core_id)
{
	setProcessingBlockDeadline(deadline, deadline_handler);
	_type = type;
}

#endif