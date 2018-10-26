#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include "../dependencies/data_type_files/fusion_data_DCPS.hpp"
#include "../dependencies/data_type_files/splash_message_DCPS.hpp"
#include "../dependencies/data_type_files/junk_1_DCPS.hpp"
#include "../dependencies/data_type_files/junk_2_DCPS.hpp"
#include "../dependencies/data_type_files/junk_3_DCPS.hpp"
#include "../dependencies/data_type_files/junk_4_DCPS.hpp"
#include "../dependencies/data_type_files/junk_5_DCPS.hpp"
#include "../dependencies/data_type_files/junk_6_DCPS.hpp"
#include "../dependencies/data_type_files/junk_7_DCPS.hpp"
#include "../dependencies/data_type_files/junk_8_DCPS.hpp"
#include "../dependencies/data_type_files/junk_9_DCPS.hpp"
#include "address_test.cpp"



int main(void)
{

	ProcessingBlock <default_data::Msg,junk_1::Msg,junk_2::Msg,junk_3::Msg,junk_4::Msg,junk_5::Msg,junk_6::Msg,junk_7::Msg,junk_8::Msg,junk_9::Msg> PB_1;

	junk_1::Msg A;
	junk_1::Msg B;
	A.id()= 1;
	B.id()= 2;

	PB_1.transfer(A,B);



}
