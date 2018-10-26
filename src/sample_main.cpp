#include <chrono>
#include <thread>
#include <time.h>

#include "sample_main_header.h"
void input_rate_handler()
{
	printf("\t\t[WARNING: Low signal strength!]\n");
}

void output_rate_handler()
{
	//printf("output_rate_handler\n");
}

void deadline_handler()
{
	//printf("deadline_handler\n");
}

void freshness_handler()
{
	//printf("freshness_handler\n");
}

void factory_deadline_handler()
{
	//printf("factory_deadline_handler\n");
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::spin()

{
	std::cout<<"USER SAMPLE APPLICATION\n"<<std::endl;
	dds::sub::Sample<default_data::Msg> input_1;
	
	default_data::Msg input_msg;
	
	this->passProcessingDeadline(0, 0);
	this->passFactoryDeadline(0, 0);
	this->passFreshness(0, 0);

	//input_msg.id()=1;
	//input_1.data(input_msg);
		
	while(true) 
	{
		
		this->read(&input_1);
		input_msg = input_1.data();

		//std::this_thread::sleep_for(std::chrono::milliseconds(200));

		if(input_msg.sensor_data() > 200) 
			printf("[msg id]%d\t\t[range]%ld\t\t[state]SAFE\n", input_msg.id(), input_msg.sensor_data());
		else 
			printf("[msg id]%d\t\t[range]%ld\t\t[state]WARNING\n", input_msg.id(), input_msg.sensor_data());
		

		junk_5::Msg  output_2;	
		this->write(output_2);

	}	

}

/*
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::fuse()
{
		
	fusion_data::Msg send_data;

	while(true)
	{	
		this->fusion_ready();

	
		for(int i=0;i<9;i++)
		{
			send_data.received_port()[i] = this->taken_ports.test(i);
		}
	

		send_data.data_id()[0] = this->fusion_data1.data().id();	
		send_data.message()[0] = this->fusion_data1.data().message();
		send_data.data_id()[1] = this->fusion_data2.data().id();
		send_data.message()[1] = this->fusion_data2.data().message();

	
		this->write(send_data);	
	}
}

*/
int main(void)
{

	ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PB_1;

	InputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PIDP_1;	

	OutputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PODP_1;	
	
	PIDP_1.attach(&PB_1, "TOPIC_A", 0);
	PODP_1.attach(&PB_1, "TOPIC_B", 5);	

	PIDP_1.initialize(10,input_rate_handler,0,freshness_handler,1,1);
	PODP_1.initialize(4,output_rate_handler);

	PB_1.initialize(ProcessingBlock<default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg>::NORMAL, 
					"Farce",3003,deadline_handler,10,0,0);
	



	PB_1.spin();


	
//===============================================================================================================
/*
	Fusion_operator <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FO_1;

	InputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FIDP_1;

	InputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FIDP_2;

	OutputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FODP_1;	
		

	FIDP_1.attach(&FO_1, "C",0,1);	
	
	FIDP_2.attach(&FO_1, "D",1,1);

	FIDP_1.initialize(5000, test,1,NULL,1,1);
	
	FIDP_2.initialize(5000, test,1,NULL,1,1);
	
	FODP_1.attach(&FO_1, "E");	
	
	FO_1.fuse();
*/	
//================================================================================================================
/*
	Factory <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> Factory_1;

        InputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacIDP_1;

        InputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacIDP_2;

        OutputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacODP_1;

	std::vector<char*> atomic_list;
	atomic_list.push_back("./sample_main_3");
	atomic_list.push_back("./sample_main_3");

	FacIDP_1.attach(&Factory_1, "F","G",0);
	FacIDP_2.attach(&Factory_1, "H","I",1);
	FacODP_1.attach(&Factory_1, "J","K",5);
	Factory_1.execFactory(atomic_list);
	Factory_1.execFactoryPort_in();
	Factory_1.execFactoryPort_out();	
*/	

/*	Factory <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> Factory_1;

        InputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacIDP_1;

        InputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacIDP_2;

        OutputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FacODP_1;

	std::vector<char*> atomic_list;
	atomic_list.push_back("./sample_main_3");
	atomic_list.push_back("./sample_main_3");

	FacIDP_1.attach(&Factory_1, "F","G",0);
	FacIDP_2.attach(&Factory_1, "H","I",1);
	FacODP_1.attach(&Factory_1, "J","K",5);



	Factory_1.initialize("test_factory", 100, factory_deadline_handler, 1, 1);
	//Factory_1.setDeadline(100, factory_deadline_handler);

	Factory_1.execFactory(atomic_list);
	Factory_1.execFactoryPort_in();
	Factory_1.execFactoryPort_out();	

	
	std::this_thread::sleep_for(std::chrono::seconds(10));*/

}
