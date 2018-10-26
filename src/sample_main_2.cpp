#include "sample_main_header.h"

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::spin()

{
	
	default_data::Msg  output_msg;

	output_msg.id() = 1000;

	int range_front_vehicle = 300;
	
	while(true) {
		output_msg.sensor_data(range_front_vehicle);
		this->write(output_msg);	

		if(range_front_vehicle>100) std::this_thread::sleep_for(std::chrono::milliseconds(90));
		else std::this_thread::sleep_for(std::chrono::milliseconds(300));
		range_front_vehicle--;
	}
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void Fusion_operator<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::fuse()
{
	fusion_data::Msg send_data;
	
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


int main(void)
{

	ProcessingBlock <junk_5::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_1::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PB_1;

	InputDataPort_PB <junk_5::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_1::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PIDP_1;

	OutputDataPort_PB <junk_5::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_1::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PODP_1;	
	
	PIDP_1.attach(&PB_1, "TOPIC_C", 0);
	PODP_1.attach(&PB_1, "TOPIC_A", 5);	

	PIDP_1.initialize(0,NULL,0,NULL,1,1);
	PB_1.initialize(ProcessingBlock <junk_5::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_1::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg>::SOURCE,
					"Source",0,NULL,10,0,0);
	PB_1.spin();

//===============================================================================================================
/*
	Fusion_operator <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FO_1;

	InputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FIDP_1;

	InputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FIDP_2;

	OutputDataPort_F <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,fusion_data::Msg> FODP_1;	
		

	FIDP_1.attach(&FO_1, "C",0,0);	
	
	FIDP_2.attach(&FO_1, "D",1,0);

	FODP_1.attach(&FO_1, "E");
	
	FO_1.fusion_ready();	
	
	FO_1.fuse();
*/	
//================================================================================================================

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
	Factory_1.execFactory(atomic_list);
	Factory_1.execFactoryPort_in();
	Factory_1.execFactoryPort_out();	*/
	
}
