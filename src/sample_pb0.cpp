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
	std::cout<<"[PB_0 START]\n"<<std::endl;

	default_data::Msg  output_msg;

	output_msg.id() = 1000;
	output_msg.message() = "PB_0 message";

	int range_front_vehicle = 300;
	
	while(true) {
		output_msg.sensor_data(range_front_vehicle);
		printf("send(%ld)\n",SystemClock::getCurrentTime());
		this->write(output_msg);	

		if(range_front_vehicle<100) std::this_thread::sleep_for(std::chrono::milliseconds(300));
		if(range_front_vehicle>=100) std::this_thread::sleep_for(std::chrono::milliseconds(90));

		range_front_vehicle--;
	}

}


int main() {
	/* PB_0 configuation */
	ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PB_0;
	OutputDataPort_PB <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		PODP_00;	
	
	PODP_00.attach(&PB_0, "TOPIC_A", 5);	

	PODP_00.initialize(0,NULL);
	PB_0.initialize(ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg>::SOURCE,
					"PB_0",0,NULL,10,0,0);
	PB_0.spin();

	return 0;
}