#include "path_proxy_header.h"

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::spin()

{
	std::cout<<"entered spin"<<std::endl;
	dds::sub::Sample<cruise_gear::Msg> input_2;
	dds::sub::Sample<cruise_speed::Msg> input_1;	
	cruise_information::Msg output_1;

	double desired_speed = 70;

	this->read(&input_1);
	
	desired_speed = desired_speed - input_1->data().curr_speed();
	desired_speed = desired_speed*10;

	if(desired_speed>20) desired_speed = 20;
		else if(desired_speed<0) desired_speed = 0;
	
	this->read(&input_2);
	double gear = input_2->data().curr_gear();

	if(gear>0.5) output_1.throttle() = desired_speed;
		else output_1.throttle() = 0;

	double gear_input = (output_1.throttle()) * -1;

	if(gear_input>=0) output_1.brake() = 30;
		else output_1.brake() = 0;
			
	this->write(output_1);	

}




int main(void)
{

	ProcessingBlock <cruise_gear::Msg,cruise_speed::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,cruise_information::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PB_1;

	InputDataPort_PB <cruise_gear::Msg,cruise_speed::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,cruise_information::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PIDP_1;
	InputDataPort_PB <cruise_gear::Msg,cruise_speed::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,cruise_information::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PIDP_2;


	OutputDataPort_PB <cruise_gear::Msg,cruise_speed::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,cruise_information::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PODP_1;	

	PIDP_1.attach(&PB_1, "cruise_gear", 0);
	PIDP_2.attach(&PB_1, "cruise_speed",1);	
	PODP_1.attach(&PB_1, "cruise_information", 5);	

	PB_1.spin();

}
