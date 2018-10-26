#include <chrono>
#include <thread>
#include <time.h>

#include "sample_main_header.h"

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::spin()

{
	std::cout<<"[PB_2 START]\n"<<std::endl;

	dds::sub::Sample<default_data::Msg> input_1;
	
	default_data::Msg input_msg;
	default_data::Msg output_msg;
	
	this->passProcessingDeadline(0, 0);
	this->passFactoryDeadline(0, 0);
	this->passFreshness(0, 0);

	while(true) 
	{		
		this->read(&input_1);
		input_msg = input_1.data();

		//std::this_thread::sleep_for(std::chrono::milliseconds(200));

		output_msg.id(1002);

		if(input_msg.sensor_data() > 200) {
			printf("[msg id]%d\t\t[range]%ld\t\t[state]%s\n", input_msg.id(), input_msg.sensor_data(), input_msg.message().c_str());
			output_msg.message("SAFE");
			output_msg.sensor_data(input_msg.sensor_data());
		}
		else {
			printf("[msg id]%d\t\t[range]%ld\t\t[state]%s\n", input_msg.id(), input_msg.sensor_data(), input_msg.message().c_str());
			output_msg.message("WARNING");
			output_msg.sensor_data(input_msg.sensor_data());
		}		

		this->write(output_msg);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}	

}


int main() {
	/* PB_0 configuation */
	ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PB_2;
	InputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PIDP_20;	
	OutputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PODP_20;	

	PIDP_20.attach(&PB_2, "TOPIC_D", 0);	
	PODP_20.attach(&PB_2, "TOPIC_E", 5);

	PIDP_20.initialize(0,NULL,0,NULL,1,1);
	PODP_20.initialize(0,NULL);
	PB_2.initialize(ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg>::NORMAL,
					"PB_2",0,NULL,10,0,0);
	PB_2.spin();

	return 0;
}