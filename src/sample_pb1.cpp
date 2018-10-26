#include <chrono>
#include <thread>
#include <time.h>

#include "sample_main_header.h"


void pb_1_input_rate_handler()
{
	printf("[%ld] pb_1_input_rate_handler()\n", SystemClock::getCurrentTime());
}


void pb_1_output_rate_handler()
{
	printf("[%ld] pb_1_output_rate_handler()\n", SystemClock::getCurrentTime());
}

void pb_1_deadline_handler()
{
	printf("[%ld] pb_1_deadline_handler()\n", SystemClock::getCurrentTime());
}

void pb_1_freshness_handler()
{
	printf("[%ld] pb_1_freshness_handler()\n", SystemClock::getCurrentTime());
}



template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::spin()

{
	std::cout<<"[PB_1 START]\n"<<std::endl;

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

		output_msg.id(1001);

		if(input_msg.sensor_data() > 200) {
			printf("[msg id]%d\t\t[range]%ld\t\t[state]SAFE\n", input_msg.id(), input_msg.sensor_data());
			output_msg.message("SAFE");
			output_msg.sensor_data(input_msg.sensor_data());
		}
		else {
			printf("[msg id]%d\t\t[range]%ld\t\t[state]WARNING\n", input_msg.id(), input_msg.sensor_data());
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
		PB_1;
	InputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PIDP_10;	
	OutputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PODP_10;	

	PIDP_10.attach(&PB_1, "TOPIC_C", 0);	
	PODP_10.attach(&PB_1, "TOPIC_D", 5);

	PIDP_10.initialize(3,pb_1_input_rate_handler,2,pb_1_freshness_handler,1,1);
	PODP_10.initialize(3,pb_1_output_rate_handler);
	PB_1.initialize(ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg>::NORMAL,
					"PB_1",300,pb_1_deadline_handler,10,0,0);
	PB_1.spin();

	return 0;
}