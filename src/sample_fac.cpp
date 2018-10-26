#include <chrono>
#include <thread>
#include <time.h>

#include "sample_main_header.h"

void fac_0_output_rate_handler()
{
	//printf("[%ld] fac_0_output_rate_handler()\n", SystemClock::getCurrentTime());
}

void fac_1_deadline_handler()
{
	printf("[%ld] fac_1_deadline_handler()\n", SystemClock::getCurrentTime());
}

void fac_1_input_rate_handler()
{
	printf("[%ld] fac_1_input_rate_handler()\n", SystemClock::getCurrentTime());
}

void fac_1_freshness_handler()
{
	printf("[%ld] fac_1_freshness_handler()\n", SystemClock::getCurrentTime());
}


int main() {
	/* Factory_0 configuation */
	Factory <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		Factory_0;
	OutputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		FacODP_00;	

	std::vector<const char*> fac_0_atomic_list;
	//std::vector<char*> fac_0_atomic_list;	
	fac_0_atomic_list.push_back("./sample_pb0");
	FacODP_00.attach(&Factory_0, "TOPIC_B", "TOPIC_A", 5);

	Factory_0.initialize("FAC_0", 0, NULL, 0, 0);
	FacODP_00.initialize(10, fac_0_output_rate_handler);

	Factory_0.execFactory(fac_0_atomic_list);
	Factory_0.execFactoryPort_out();		


	/* Factory_1 configuration */
/*	Factory <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		Factory_1;
	InputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		FacIDP_10;	
	OutputDataPort_Fac <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,default_data::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> 
		FacODP_10;	

	std::vector<const char*> fac_1_atomic_list;
	fac_1_atomic_list.push_back("./sample_pb1");	
	fac_1_atomic_list.push_back("./sample_pb2");	
	FacIDP_10.attach(&Factory_1, "TOPIC_C", "TOPIC_B", 0);
	FacODP_10.attach(&Factory_1, "TOPIC_F", "TOPIC_E", 6);

	Factory_1.initialize("FAC_1", 1000, fac_1_deadline_handler, 0, 0);
	FacIDP_10.initialize(10, fac_1_input_rate_handler, 10, fac_1_freshness_handler, false, 0);
	FacODP_10.initialize(0, NULL);

	Factory_1.execFactory(fac_1_atomic_list);
	Factory_1.execFactoryPort_in();
	Factory_1.execFactoryPort_out();*/

	while(true) {	
	}

	return 0;
}