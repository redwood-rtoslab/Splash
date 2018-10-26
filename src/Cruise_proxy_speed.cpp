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
	//UDP comm here

	cruise_speed::Msg output_1;
	
	this->write(output_1);			

}




int main(void)
{

	ProcessingBlock <junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,cruise_speed::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PB_1;

	OutputDataPort_PB <junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,cruise_speed::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PODP_1;	

	PODP_1.attach(&PB_1, "cruise_speed", 5);	

	PB_1.spin();

}
