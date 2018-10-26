#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <bitset>
#include <vector>
#include <thread>

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_F;


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class OutputDataPort_F;



template
<typename Data_0>
class SplashListener_fusion:public dds::sub::NoOpDataReaderListener<Data_0>
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

class Fusion_operator 
{
	private:	

	public:
		std::bitset<9> mandport;
		std::bitset<10> connected_ports;
		std::bitset<9> taken_ports; 
		
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
		

		dds::core::cond::WaitSet ws_0;
		dds::core::cond::WaitSet ws_1;
		dds::core::cond::WaitSet ws_2;
		dds::core::cond::WaitSet ws_3;
		dds::core::cond::WaitSet ws_4;
		dds::core::cond::WaitSet ws_5;
		dds::core::cond::WaitSet ws_6;
		dds::core::cond::WaitSet ws_7;
		dds::core::cond::WaitSet ws_8;


		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP0;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP1;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP2;
	
		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP3;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP4;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP5;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP6;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP7;

		InputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP8;


	
		OutputDataPort_F<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP;

		dds::sub::Sample<Data_0> fusion_data1;
		dds::sub::Sample<Data_1> fusion_data2;
		dds::sub::Sample<Data_2> fusion_data3;
		dds::sub::Sample<Data_3> fusion_data4;
		dds::sub::Sample<Data_4> fusion_data5;
		dds::sub::Sample<Data_5> fusion_data6;
		dds::sub::Sample<Data_6> fusion_data7;
		dds::sub::Sample<Data_7> fusion_data8;
		dds::sub::Sample<Data_8> fusion_data9; 
			


		std::vector<dds::sub::Sample<Data_0>> sample_0{1};
		typename std::vector<dds::sub::Sample<Data_0>>::iterator iter_0;
		std::vector<dds::sub::Sample<Data_1>> sample_1{1};
		typename std::vector<dds::sub::Sample<Data_1>>::iterator iter_1;
		std::vector<dds::sub::Sample<Data_2>> sample_2{1};
		typename std::vector<dds::sub::Sample<Data_2>>::iterator iter_2;
		std::vector<dds::sub::Sample<Data_3>> sample_3{1};
		typename std::vector<dds::sub::Sample<Data_3>>::iterator iter_3;
		std::vector<dds::sub::Sample<Data_4>> sample_4{1};
		typename std::vector<dds::sub::Sample<Data_4>>::iterator iter_4;
		std::vector<dds::sub::Sample<Data_5>> sample_5{1};
		typename std::vector<dds::sub::Sample<Data_5>>::iterator iter_5;
		std::vector<dds::sub::Sample<Data_6>> sample_6{1};
		typename std::vector<dds::sub::Sample<Data_6>>::iterator iter_6;
		std::vector<dds::sub::Sample<Data_7>> sample_7{1};
		typename std::vector<dds::sub::Sample<Data_7>>::iterator iter_7;
		std::vector<dds::sub::Sample<Data_8>> sample_8{1};
		typename std::vector<dds::sub::Sample<Data_8>>::iterator iter_8;
	
		int write(Data_9);
		int setmand(std::bitset<9>*);
		void fusion_ready();
		void fuse();
		void initialize(std::string name, double correlation, int opt_count, int core_id); 
			
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_F
{
	private:
	public:
		
		dds::sub::DataReader<Data_0>* IDP_reader0;
		dds::sub::DataReader<Data_1>* IDP_reader1;	
		dds::sub::DataReader<Data_2>* IDP_reader2;
		dds::sub::DataReader<Data_3>* IDP_reader3;
		dds::sub::DataReader<Data_4>* IDP_reader4;
		dds::sub::DataReader<Data_5>* IDP_reader5;		
		dds::sub::DataReader<Data_6>* IDP_reader6;
		dds::sub::DataReader<Data_7>* IDP_reader7;
		dds::sub::DataReader<Data_8>* IDP_reader8;		

		
		SplashListener_fusion<Data_0>* listener_0;
                SplashListener_fusion<Data_1>* listener_1;
                SplashListener_fusion<Data_2>* listener_2;
                SplashListener_fusion<Data_3>* listener_3;
                SplashListener_fusion<Data_4>* listener_4;
		SplashListener_fusion<Data_5>* listener_5;
		SplashListener_fusion<Data_6>* listener_6;
		SplashListener_fusion<Data_7>* listener_7;
		SplashListener_fusion<Data_8>* listener_8;

		int topic_number=0;
		void* port_memory;
		int attach(Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int, int);

		void initialize (double, void(*)(),double, void(*)(),bool, int);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int InputDataPort_F<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic, int topic_number, int mandatory)
{
	if(topic_number==0)
	{
		this->topic_number = topic_number;
		PB->IDP0 = this;		
		PB->topic0 = new dds::topic::Topic<Data_0> {(*PB).default_dp, topic,(*PB).default_dp.default_topic_qos()};
		IDP_reader0 = new dds::sub::DataReader<Data_0>{(*PB).PB_sub, (*PB->topic0),(*PB).PB_sub.default_datareader_qos()};
		
		listener_0 = new SplashListener_fusion<Data_0>;	

		dds::sub::cond::ReadCondition rc_0(*IDP_reader0,dds::sub::status::DataState::new_data());
		PB->ws_0.attach_condition(rc_0);	
		PB->connected_ports.set(0);
	
		IDP_reader0->listener(listener_0, dds::core::status::StatusMask::data_available());

		if(mandatory==1) PB->mandport.set(0);
		return 1;
	}		

	if(topic_number==1)
	{

		this->topic_number = topic_number;
		
		PB->IDP1 = this;

		listener_1 = new SplashListener_fusion<Data_1>;			

		PB->topic1 = new dds::topic::Topic<Data_1> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader1= new dds::sub::DataReader<Data_1>((*PB).PB_sub, (*PB->topic1),(*PB).PB_sub.default_datareader_qos());
	        
		IDP_reader1->listener(listener_1, dds::core::status::StatusMask::data_available());

		dds::sub::cond::ReadCondition rc_1(*IDP_reader1,dds::sub::status::DataState::new_data());
		PB->ws_1.attach_condition(rc_1);
		PB->connected_ports.set(1);
		if(mandatory==1) PB->mandport.set(1);
		return 1;
	}

	if(topic_number==2)
	{

		this->topic_number = topic_number;
		
		PB->IDP2 = this;		
	
		listener_2 = new SplashListener_fusion<Data_2>;

		PB->topic2 = new dds::topic::Topic<Data_2> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
	
		IDP_reader2 = new dds::sub::DataReader<Data_2> ((*PB).PB_sub, (*PB->topic2),(*PB).PB_sub.default_datareader_qos());

		IDP_reader2->listener(listener_2,dds::core::status::StatusMask::data_available());
			
		dds::sub::cond::ReadCondition rc_2(*IDP_reader2,dds::sub::status::DataState::new_data());
		PB->ws_2.attach_condition(rc_2);
		PB->connected_ports.set(2);
		if(mandatory==1) PB->mandport.set(2);
		return 1;
	}
	if(topic_number==3)
	{

		this->topic_number = topic_number;		

		PB->IDP3 = this;

		listener_3 = new SplashListener_fusion<Data_3>;		

		PB->topic3 = new dds::topic::Topic<Data_3> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader3 = new dds::sub::DataReader<Data_3> ((*PB).PB_sub, (*PB->topic3),(*PB).PB_sub.default_datareader_qos());

		IDP_reader3->listener(listener_3,dds::core::status::StatusMask::data_available());

		dds::sub::cond::ReadCondition rc_3(*IDP_reader3, dds::sub::status::DataState::new_data());
		PB->ws_3.attach_condition(rc_3);
		PB->connected_ports.set(3);
		if(mandatory==1) PB->mandport.set(3);
		return 1;
	}	

	if(topic_number==4)
	{
		this->topic_number = topic_number;
		
		PB->IDP4 = this;	

		listener_4 = new SplashListener_fusion<Data_4>;

		PB->topic4 = new dds::topic::Topic<Data_4> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader4 = new dds::sub::DataReader<Data_4> ((*PB).PB_sub, (*PB->topic4),(*PB).PB_sub.default_datareader_qos());
		
		IDP_reader4->listener(listener_4,dds::core::status::StatusMask::data_available());

		dds::sub::cond::ReadCondition rc_4(*IDP_reader4, dds::sub::status::DataState::new_data());
		PB->ws_4.attach_condition(rc_4);
		PB->connected_ports.set(4);
		if(mandatory==1) PB->mandport.set(4);
		return 1;
	}

	if(topic_number==5)
	{
		this->topic_number = topic_number;

		PB->IDP5 = this;	

		listener_5 = new SplashListener_fusion<Data_5>;

		PB->topic5 = new dds::topic::Topic<Data_5> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader5 = new dds::sub::DataReader<Data_5> ((*PB).PB_sub, (*PB->topic5),(*PB).PB_sub.default_datareader_qos());
		dds::sub::cond::ReadCondition rc_5(*IDP_reader5, dds::sub::status::DataState::new_data());
		PB->ws_5.attach_condition(rc_5);
		PB->connected_ports.set(5);
		if(mandatory==1) PB->mandport.set(5);
		return 1;
	}

	if(topic_number==6)
	{
		this->topic_number = topic_number;		

		PB->IDP6 = this;	

		listener_6 = new SplashListener_fusion<Data_6>;

		PB->topic6 = new dds::topic::Topic<Data_6> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader6 = new dds::sub::DataReader<Data_6> ((*PB).PB_sub, (*PB->topic6),(*PB).PB_sub.default_datareader_qos());
		dds::sub::cond::ReadCondition rc_6(*IDP_reader6, dds::sub::status::DataState::new_data());
		PB->ws_6.attach_condition(rc_6);
		PB->connected_ports.set(6);
		if(mandatory==1) PB->mandport.set(6);
		return 1;
	}

	if(topic_number==7)
	{
		this->topic_number = topic_number;

		PB->IDP7 = this;	

		listener_7 = new SplashListener_fusion<Data_7>;		

		PB->topic7 = new dds::topic::Topic<Data_7> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader7 = new dds::sub::DataReader<Data_7> ((*PB).PB_sub, (*PB->topic7),(*PB).PB_sub.default_datareader_qos());
		dds::sub::cond::ReadCondition rc_7(*IDP_reader7, dds::sub::status::DataState::new_data());
		PB->ws_7.attach_condition(rc_7);		
		PB->connected_ports.set(7);
		if(mandatory==1) PB->mandport.set(7);
		return 1;
	}

	if(topic_number==8)
	{
		this->topic_number = topic_number;		

		PB->IDP8 = this;	

		listener_8 = new SplashListener_fusion<Data_8>;

		PB->topic8 = new dds::topic::Topic<Data_8> ((*PB).default_dp, topic,(*PB).default_dp.default_topic_qos());
		
		IDP_reader8 = new dds::sub::DataReader<Data_8> ((*PB).PB_sub, (*PB->topic8),(*PB).PB_sub.default_datareader_qos());
		dds::sub::cond::ReadCondition rc_8(*IDP_reader8, dds::sub::status::DataState::new_data());
		PB->ws_8.attach_condition(rc_8);
		PB->connected_ports.set(8);
		if(mandatory==1) PB->mandport.set(8);
		return 1;
	}


	return -1;
}

template
<typename Data_0>
void rate_check_fusion (int set_rate, SplashListener_fusion<Data_0>* listener, void* user_memory, void (*fun_ptr)())
{
        while(true)
        {
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

void InputDataPort_F<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (double rate, void (*rate_handler)(), double freshness, void(*freshness_handler)(), bool queueing, int queue_size)
{
	if((this->topic_number)==0)
        {

                std::thread rate_check_fusion_thread_0 (rate_check_fusion<Data_0>,rate,listener_0,port_memory,rate_handler);
                rate_check_fusion_thread_0.detach();
        }

        else if((this->topic_number)==1)
        {
                std::thread rate_check_fusion_thread_1 (rate_check_fusion<Data_1>,rate,listener_1,port_memory,rate_handler);
                rate_check_fusion_thread_1.detach();
        }

        else if((this->topic_number)==2)
        {
                std::thread rate_check_fusion_thread_2 (rate_check_fusion<Data_2>,rate,listener_2,port_memory,rate_handler);
                rate_check_fusion_thread_2.detach();
        }



        else if(this->topic_number==3)
        {
                std::thread rate_check_fusion_thread_3 (rate_check_fusion<Data_3>,rate,listener_3,port_memory,rate_handler);
                rate_check_fusion_thread_3.detach();
        }

        else if(this->topic_number==4)
        {
                std::thread rate_check_fusion_thread_4 (rate_check_fusion<Data_4>,rate,listener_4,port_memory,rate_handler);
                rate_check_fusion_thread_4.detach();
        }


}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class OutputDataPort_F
{
	private:

	public:
		dds::pub::DataWriter<Data_9>* ODP_writer;
		int attach(Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string);	
		void initialize(double rate);		
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int OutputDataPort_F<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* PB, std::string topic)
{

		PB->ODP = this;
		
		PB->topic9 = new dds::topic::Topic<Data_9> ((*PB).default_dp,topic,(*PB).default_dp.default_topic_qos());

		ODP_writer = new dds::pub::DataWriter<Data_9> ((*PB).PB_pub,(*PB->topic9),(*PB).PB_pub.default_datawriter_qos());
		PB->connected_ports.set(9);
		return 1;

}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void OutputDataPort_F<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (double rate)
{

}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::write(Data_9 Data)
{
	ODP->ODP_writer->write(Data);
	return 1;
}

template
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::fusion_ready()
{
	
		for(int i=0;i<9;i++)
		{
			int taken =0;
			
			if(mandport.test(i))		
				{
					switch(i)
					{
						case 0:
							if(connected_ports.test(0))
							{ 
								ws_0.wait();
								iter_0 = sample_0.begin();
								IDP0->IDP_reader0->take(iter_0,1);	
								fusion_data1 = *iter_0;
								taken_ports.set(0);
							}
							break;
						case 1: 
							if(connected_ports.test(1))
							{
								ws_1.wait();
								iter_1 = sample_1.begin();
								IDP1->IDP_reader1->take(iter_1,1);	
								fusion_data2 = *iter_1;
								taken_ports.set(1);
							}
							break;
						case 2: 
							if(connected_ports.test(2))
							{
								ws_2.wait();
								iter_2 = sample_2.begin();
								IDP2->IDP_reader2->take(iter_2,1);	
								fusion_data3 = *iter_2;
								taken_ports.set(2);
							}
							break;
						case 3:
							if(connected_ports.test(3))
							{
								ws_3.wait();
								iter_3 = sample_3.begin();
								IDP3->IDP_reader3->take(iter_3,1);	
								fusion_data4 = *iter_3;
								taken_ports.set(3);
							}
							break;
						case 4:
							if(connected_ports.test(4))
							{
								ws_4.wait();
								iter_4 = sample_4.begin();
								IDP4->IDP_reader4->take(iter_4,1);	
								fusion_data5 = *iter_4;
								taken_ports.set(4); 
							}
							break;
						case 5:
							if(connected_ports.test(5))
							{
								ws_5.wait();
								iter_5 = sample_5.begin();
								IDP5->IDP_reader5->take(iter_5,1);	
								fusion_data6 = *iter_5;
								taken_ports.set(5);
							}
							break;
						case 6:
							if(connected_ports.test(6))
							{
								ws_6.wait();
								iter_6 = sample_6.begin();
								IDP6->IDP_reader6->take(iter_6,1);
								iter_6 = sample_6.begin();
								fusion_data7 = *iter_6;
								taken_ports.set(6);
							}
							break;
						case 7:
							if(connected_ports.test(7))
							{
								ws_7.wait();	
								iter_7 = sample_7.begin();
								IDP7->IDP_reader7->take(iter_7,1);
								fusion_data8 = *iter_7;
								taken_ports.set(7);
							}
							break;
						case 8:
							if(connected_ports.test(8))
							{
								ws_8.wait();
								iter_8 = sample_8.begin();
								IDP8->IDP_reader8->take(iter_8,1);									      fusion_data9 = *iter_8;
								taken_ports.set(8);
							}
							break;
						default:
							printf("Invalid port number\n");
								
					}		
			
				}

			else
			{
					switch(i)
					{
						case 0:
							if(connected_ports.test(0))
							{ 
								taken = IDP0->IDP_reader0->take(iter_0,1);
								if(taken) taken_ports.set(0);
							}
							break;
						case 1: 
							if(connected_ports.test(1))
							{
								taken = IDP1->IDP_reader1->take(iter_1,1);
								if(taken) taken_ports.set(1);
							}
							break;
						case 2: 
							if(connected_ports.test(2))
							{
								taken = IDP2->IDP_reader2->take(iter_2,1);
								if(taken) taken_ports.set(2);
							}
							break;
						case 3:
							if(connected_ports.test(3))
							{
								IDP3->IDP_reader3->take(iter_3,1);
								if(taken) taken_ports.set(3);
							}
							break;
						case 4:
							if(connected_ports.test(4))
							{
								IDP4->IDP_reader4->take(iter_4,1);
								if(taken) taken_ports.set(4);
							}
							break;
						case 5:
							if(connected_ports.test(5))
							{
								IDP5->IDP_reader5->take(iter_5,1);
								if(taken) taken_ports.set(5);
							}
							break;
						case 6:
							if(connected_ports.test(6))
							{
								IDP6->IDP_reader6->take(iter_6,1);
								if(taken) taken_ports.set(6);
							}
							break;
						case 7:
							if(connected_ports.test(7))
							{
								IDP7->IDP_reader7->take(iter_7,1);
								if(taken) taken_ports.set(7);
							}
							break;
						case 8:
							if(connected_ports.test(8))
							{
								IDP8->IDP_reader8->take(iter_8,1);
								if(taken) taken_ports.set(8);
							}
							break;
						default:
							printf("Invalid port number\n");

					}
			}
	
		}//end of for loop
		
		
}

template
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (std::string, double correlation, int opt_count, int core_id)
{


}


