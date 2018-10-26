#include "sample_main_header.h"

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void ProcessingBlock<Data_0, Data_1, Data_2, Data_3, Data_4, Data_5, Data_6, Data_7, Data_8, Data_9>::spin()
{
	dds::sub::Sample<splash_message::msg5> input_0;
	this->read(&input_0);

	//user code here

	splash_message::msg2 output_0;
	this->write(output_0);
}

int main(void)
{
	ProcessingBlock<splash_message::msg5, junk_1::Msg, junk_2::Msg, junk_3::Msg, junk_4::Msg, splash_message::msg2, junk_6::Msg, junk_7::Msg, junk_8::Msg, junk_9::Msg> PB;
	PB.initialize("pb2", -1.0, NULL, -1.0, false, -1);

	InputDataPort_PB<splash_message::msg5, junk_1::Msg, junk_2::Msg, junk_3::Msg, junk_4::Msg, splash_message::msg2, junk_6::Msg, junk_7::Msg, junk_8::Msg, junk_9::Msg> IDP_0;
	IDP_0.initialize(31.0, NULL, -1.0, NULL, false, -1);
	IDP_0.attach(&PB, "topic2", 0);

	OutputDataPort_PB<splash_message::msg5, junk_1::Msg, junk_2::Msg, junk_3::Msg, junk_4::Msg, splash_message::msg2, junk_6::Msg, junk_7::Msg, junk_8::Msg, junk_9::Msg> ODP_0;
	ODP_0.initialize(32.0, NULL);
	ODP_0.attach(&PB, "topic8", 5);

	PB.spin();
}
