#include "../dependencies/data_type_files/default_data_DCPS.hpp"
#include <stdio.h>
#include <bitset>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/prctl.h>

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_Fac;


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class OutputDataPort_Fac;

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class Factory
{
	private:	

	public:
	
		dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
		
		dds::pub::Publisher Output_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber Input_sub{default_dp, default_dp.default_subscriber_qos()};
		
		dds::pub::Publisher Input_connector_pub{default_dp, default_dp.default_publisher_qos()};
		dds::sub::Subscriber Output_connector_sub{default_dp, default_dp.default_subscriber_qos()};
		
		std::bitset<10> connected_ports;
	
		dds::topic::Topic<Data_0>* topic0;	
		dds::topic::Topic<Data_1>* topic1;
		dds::topic::Topic<Data_2>* topic2;
		dds::topic::Topic<Data_3>* topic3;
		dds::topic::Topic<Data_4>* topic4;
		dds::topic::Topic<Data_5>* topic5;
		dds::topic::Topic<Data_6>* topic6;
		dds::topic::Topic<Data_7>* topic7;
		dds::topic::Topic<Data_8>* topic8;
		dds::topic::Topic<Data_9>* topic9;			

		dds::topic::Topic<Data_0>* connector_topic0;	
		dds::topic::Topic<Data_1>* connector_topic1;
		dds::topic::Topic<Data_2>* connector_topic2;
		dds::topic::Topic<Data_3>* connector_topic3;
		dds::topic::Topic<Data_4>* connector_topic4;
		dds::topic::Topic<Data_5>* connector_topic5;
		dds::topic::Topic<Data_6>* connector_topic6;
		dds::topic::Topic<Data_7>* connector_topic7;
		dds::topic::Topic<Data_8>* connector_topic8;
		dds::topic::Topic<Data_9>* connector_topic9;

		std::vector<dds::sub::Sample<Data_0>> input_data_1{1};
		typename std::vector<dds::sub::Sample<Data_0>>::iterator iter_1 = input_data_1.begin();
		std::vector<dds::sub::Sample<Data_1>> input_data_2{1};
		typename std::vector<dds::sub::Sample<Data_1>>::iterator iter_2 = input_data_2.begin();
		std::vector<dds::sub::Sample<Data_2>> input_data_3{1};
		typename std::vector<dds::sub::Sample<Data_2>>::iterator iter_3 = input_data_3.begin();
		std::vector<dds::sub::Sample<Data_3>> input_data_4{1};
		typename std::vector<dds::sub::Sample<Data_3>>::iterator iter_4 = input_data_4.begin();
		std::vector<dds::sub::Sample<Data_4>> input_data_5{1};
		typename std::vector<dds::sub::Sample<Data_4>>::iterator iter_5 = input_data_5.begin();
		
		std::vector<dds::sub::Sample<Data_5>> output_connector_data_1{1};
		typename std::vector<dds::sub::Sample<Data_5>>::iterator connector_iter_1;
		std::vector<dds::sub::Sample<Data_6>> output_connector_data_2{1};
		typename std::vector<dds::sub::Sample<Data_6>>::iterator connector_iter_2;		
		std::vector<dds::sub::Sample<Data_7>> output_connector_data_3{1};
		typename std::vector<dds::sub::Sample<Data_7>>::iterator connector_iter_3;
		std::vector<dds::sub::Sample<Data_8>> output_connector_data_4{1};
		typename std::vector<dds::sub::Sample<Data_8>>::iterator connector_iter_4;
		std::vector<dds::sub::Sample<Data_9>> output_connector_data_5{1};
		typename std::vector<dds::sub::Sample<Data_9>>::iterator connector_iter_5;



		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP0;

		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP1;

		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP2;
	
		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP3;

		InputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* IDP4;

	
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP0;

		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP1;

		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP2;
	
		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP3;

		OutputDataPort_Fac<Data_0, Data_1,
		              Data_2, Data_3, 
	                      Data_4, Data_5,
		              Data_6, Data_7,
			      Data_8, Data_9>* ODP4;

		void initialize (std::string, double, int, int); 		
		void execFactory(std::vector<char*> atomic_list);
		void execFactoryPort_in();
		void execFactoryPort_out();	
};


/*
	Class Name: InputDataPort_Fac
	Detail: InputDataPort used by Processing Block in order to receive data
	Class Variables:
		1. Five DataReaders
	Class Functions:
		1. int attach(Factory*, string, int)
		   -Function
			attaches the InputDataPort to the Factory specified in the parameter
		   -Parameters
		   	a. Uses the Factory pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_Fac will be connected to
		        c. Uses the int parameter to specify which Topic/DataReader combination should be connected.
                           The int parameter also maps which of the template data type is used for each Topic/DataReader.
                           example) if the int parameter had 1 for its value then dds::sub::DataReader<Data_1>* Input_reader1 will be
                           connected to dds::topic::Topic<Data_1>* topic1. 
				
			   The int value can range from 0~4
		  -return value
			returns 1 on successful connections, -1 on error 
*/
template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_Fac
{
	private:
	public:
		
		dds::sub::DataReader<Data_0>* Input_reader0;
		dds::sub::DataReader<Data_1>* Input_reader1;	
		dds::sub::DataReader<Data_2>* Input_reader2;
		dds::sub::DataReader<Data_3>* Input_reader3;
		dds::sub::DataReader<Data_4>* Input_reader4;

		dds::pub::DataWriter<Data_0>* Input_connector0;
		dds::pub::DataWriter<Data_1>* Input_connector1;
		dds::pub::DataWriter<Data_2>* Input_connector2;
		dds::pub::DataWriter<Data_3>* Input_connector3;
		dds::pub::DataWriter<Data_4>* Input_connector4;
				

		int attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, std::string, int);
		void initialize (double,double,bool,int);

};

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

int InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* Fact, std::string topic, std::string connector_topic, int topic_number)
{
	if(topic_number==0)
	{
		
		Fact->IDP0 = this;		
		Fact->topic0 = new dds::topic::Topic<Data_0> {(*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos()};
		Input_reader0 = new dds::sub::DataReader<Data_0>{(*Fact).Input_sub, (*Fact->topic0),(*Fact).Input_sub.default_datareader_qos()};
	
		Fact->connector_topic0 = new dds::topic::Topic<Data_0> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector0 = new dds::pub::DataWriter<Data_0>{(*Fact).Input_connector_pub, (*Fact->connector_topic0),(*Fact).Input_connector_pub.default_datawriter_qos()};
	
		Fact->connected_ports.set(0);		

		return 1;
	}		

	if(topic_number==1)
	{
		Fact->IDP1 = this;			

		Fact->topic1 = new dds::topic::Topic<Data_1> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
	
		Input_reader1= new dds::sub::DataReader<Data_1>((*Fact).Input_sub, (*Fact->topic1),(*Fact).Input_sub.default_datareader_qos());
		
		Fact->connector_topic1 = new dds::topic::Topic<Data_1> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector1 = new dds::pub::DataWriter<Data_1>{(*Fact).Input_connector_pub, (*Fact->connector_topic1),(*Fact).Input_connector_pub.default_datawriter_qos()};
		
		Fact->connected_ports.set(1);
		
		return 1;
	}

	if(topic_number==2)
	{
		Fact->IDP2 = this;		

		Fact->topic2 = new dds::topic::Topic<Data_2> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
	
		Input_reader2 = new dds::sub::DataReader<Data_2> ((*Fact).Input_sub, (*Fact->topic2),(*Fact).Input_sub.default_datareader_qos());
	
		Fact->connector_topic2 = new dds::topic::Topic<Data_2> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector2 = new dds::pub::DataWriter<Data_2>{(*Fact).Input_connector_pub, (*Fact->connector_topic2),(*Fact).Input_connector_pub.default_datawriter_qos()};
	
		Fact->connected_ports.set(2);
		
		return 1;
	}
	if(topic_number==3)
	{
		Fact->IDP3 = this;
		
		Fact->topic3 = new dds::topic::Topic<Data_3> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
		
		Input_reader3 = new dds::sub::DataReader<Data_3> ((*Fact).Input_sub, (*Fact->topic3),(*Fact).Input_sub.default_datareader_qos());

		Fact->connector_topic3 = new dds::topic::Topic<Data_3> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector3 = new dds::pub::DataWriter<Data_3>{(*Fact).Input_connector_pub, (*Fact->connector_topic3),(*Fact).Input_connector_pub.default_datawriter_qos()};

		Fact->connected_ports.set(3);
	
		return 1;
	}	

	if(topic_number==4)
	{
		Fact->IDP4 = this;	

		Fact->topic4 = new dds::topic::Topic<Data_4> ((*Fact).default_dp, topic,(*Fact).default_dp.default_topic_qos());
		
		Input_reader4 = new dds::sub::DataReader<Data_4> ((*Fact).Input_sub, (*Fact->topic4),(*Fact).Input_sub.default_datareader_qos());
		
		Fact->connector_topic4 = new dds::topic::Topic<Data_4> {(*Fact).default_dp, connector_topic, (*Fact).default_dp.default_topic_qos()};	

		Input_connector4 = new dds::pub::DataWriter<Data_4>{(*Fact).Input_connector_pub, (*Fact->connector_topic4),(*Fact).Input_connector_pub.default_datawriter_qos()};

		Fact->connected_ports.set(4);	
			
		return 1;
	}
	
	return -1;
}

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void InputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (double rate, double freshness, bool queueing, int queue_size)
{


}

/*
	Class Name: OutputDataPort_Fac
	Detail: OutputDataPort used by Processing Block in order to send data
	Class Variables:
		1. Five DataWriters
	Class Functions:
		1. int attach(Factory*, string, int)
		   -Function
			attaches the OutputDataPort to the Factory specified in the parameter
		   -Parameters
		   	a. Uses the Factory pointer to access/declare Topics 
		        b. Uses the string parameter to name the Topic which the InputDataPort_Fac will be connected to
		        c. Uses the int parameter to specify which Topic/DataReader combination should be connected.
                           The int parameter also maps which of the template data type is used for each Topic/DataReader.
                           example) if the int parameter had 1 for its value then dds::sub::DataWriter<Data_1>* ODP_Writer1 will be
                           connected to dds::topic::Topic<Data_1>* topic1. 
				
			   The int value can range from 5~9
		  -return value
			returns 1 on successful connections, -1 on error 
*/

template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class OutputDataPort_Fac
{
	private:

	public:
		dds::pub::DataWriter<Data_5>* Output_writer0;
		dds::pub::DataWriter<Data_6>* Output_writer1;
		dds::pub::DataWriter<Data_7>* Output_writer2;
		dds::pub::DataWriter<Data_8>* Output_writer3;
		dds::pub::DataWriter<Data_9>* Output_writer4;	
		
		dds::sub::DataReader<Data_5>* Output_connector0;
		dds::sub::DataReader<Data_6>* Output_connector1;
		dds::sub::DataReader<Data_7>* Output_connector2;
		dds::sub::DataReader<Data_8>* Output_connector3;
		dds::sub::DataReader<Data_9>* Output_connector4;	


		int attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, std::string, int);	

		void initialize (double);
		
};


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
int OutputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::attach(Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>* Fact, std::string topic, std::string connector_topic, int topic_number)
{
	if(topic_number==5)
	{

		Fact->ODP0 = this;
		
		Fact->topic5 = new dds::topic::Topic<Data_5> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());

		Output_writer0 = new dds::pub::DataWriter<Data_5> ((*Fact).Output_pub,(*Fact->topic5),(*Fact).Output_pub.default_datawriter_qos());

		Fact->connector_topic5 = new dds::topic::Topic<Data_5> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector0 = new dds::sub::DataReader<Data_5> ((*Fact).Output_connector_sub, (*Fact->connector_topic5),(*Fact).Output_connector_sub.default_datareader_qos());
		
		Fact->connected_ports.set(5);
		return 1;
	}
	
	if(topic_number==6)
	{
		Fact->ODP1 = this;
		
		Fact->topic6 = new dds::topic::Topic<Data_6> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		Output_writer1 = new dds::pub::DataWriter<Data_6> ((*Fact).Output_pub,(*Fact->topic6),(*Fact).Output_pub.default_datawriter_qos());
	
		Fact->connector_topic6 = new dds::topic::Topic<Data_6> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector1 = new dds::sub::DataReader<Data_6> ((*Fact).Output_connector_sub, (*Fact->connector_topic6),(*Fact).Output_connector_sub.default_datareader_qos());

		Fact->connected_ports.set(6);
		return 1;
	}

	if(topic_number==7)
	{
		Fact->ODP2 = this;

		Fact->topic7 = new dds::topic::Topic<Data_7> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());

		Output_writer2 = new dds::pub::DataWriter<Data_7> ((*Fact).Output_pub,(*Fact->topic7),(*Fact).Output_pub.default_datawriter_qos());
		Fact->connector_topic7 = new dds::topic::Topic<Data_7> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector2 = new dds::sub::DataReader<Data_7> ((*Fact).Output_connector_sub, (*Fact->connector_topic7),(*Fact).Output_connector_sub.default_datareader_qos());
		
		Fact->connected_ports.set(7);
		return 1;
	}

	if(topic_number==8)
	{
		Fact->ODP3 = this;

		Fact->topic8 = new dds::topic::Topic<Data_8> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		
		Output_writer3 = new dds::pub::DataWriter<Data_8> ((*Fact).Output_pub,(*Fact->topic8),(*Fact).Output_pub.default_datawriter_qos());
		Fact->connector_topic8 = new dds::topic::Topic<Data_8> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector3 = new dds::sub::DataReader<Data_8> ((*Fact).Output_connector_sub, (*Fact->connector_topic8),(*Fact).Output_connector_sub.default_datareader_qos());

		Fact->connected_ports.set(8);
		return 1;
	}
	
	if(topic_number==9)
	{
		Fact->ODP4 = this;
		
		Fact->topic9 = new dds::topic::Topic<Data_9> ((*Fact).default_dp,topic,(*Fact).default_dp.default_topic_qos());
		
		Output_writer4 = new dds::pub::DataWriter<Data_9> ((*Fact).Output_pub,(*Fact->topic9),(*Fact).Output_pub.default_datawriter_qos());	
		Fact->connector_topic9 = new dds::topic::Topic<Data_9> ((*Fact).default_dp,connector_topic, (*Fact).default_dp.default_topic_qos());
		
		Output_connector4 = new dds::sub::DataReader<Data_9> ((*Fact).Output_connector_sub, (*Fact->connector_topic9),(*Fact).Output_connector_sub.default_datareader_qos());	
		
		Fact->connected_ports.set(9);
		return 1;
	}

		return -1;
}


template 
<typename Data_0, typename Data_1, 
typename Data_2, typename Data_3, 
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
void OutputDataPort_Fac<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (double rate)
{
	


}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactory(std::vector<char*> atomic_list)
{
	int child_id;
        	for(int i=0;i<atomic_list.size();i++)
        	{
			child_id = fork();
		
			if(child_id==0)
			{
				execl(atomic_list[i],atomic_list[i],(char*)0);
			}
        	}
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactoryPort_in()
{
	int child_id;

	for(int i=0;i<5;i++)
	{
		if(connected_ports.test(i))
		{
			child_id = fork();
			
			if(child_id==0)
			{
				std::cout<<"Activating Port"<<std::endl;

				
				if(i==0)
				{
					prctl(PR_SET_NAME, "Fac_Inp_1");
					dds::sub::Sample<Data_0> sample;
					Data_0 A;	
					while(true)
					{
						IDP0->Input_reader0->take(iter_1,1);
						iter_1 = input_data_1.begin();
						sample = *iter_1;
						A = sample->data();
						IDP0->Input_connector0->write(A);
					}
				}

				if(i==1)
				{
					prctl(PR_SET_NAME, "Fac_Inp_2");
					dds::sub::Sample<Data_1> sample;
					Data_1 A;	
					while(true)
					{
						IDP1->Input_reader1->take(iter_2,1);
						iter_2 = input_data_2.begin();
						sample = *iter_2;
						A = sample->data();
						IDP1->Input_connector1->write(A);
					}
				}
				
				if(i==2)
				{
					prctl(PR_SET_NAME, "Fac_Inp_3");
					dds::sub::Sample<Data_2> sample;
					Data_2 A;
					while(true)
					{
						IDP2->Input_reader2->take(iter_3,1);
						iter_3 = input_data_3.begin();
						sample = *iter_3;
						A = sample->data();
						IDP2->Input_connector2->write(A);
					}
				}

				if(i==3)
				{
					prctl(PR_SET_NAME, "Fac_Inp_4");
					dds::sub::Sample<Data_3> sample;
					Data_3 A;
					while(true)
					{
						IDP2->Input_reader3->take(iter_4,1);
						iter_4 = input_data_4.begin();
						sample = *iter_4;
						A = sample->data();
						IDP3->Input_connector3->write(A);
					}
				}

				if(i==4)
				{
					prctl(PR_SET_NAME, "Fac_Inp_5");
					dds::sub::Sample<Data_4> sample;
					Data_4 A;
					while(true)
					{
						IDP2->Input_reader4->take(iter_5,1);
						iter_5 = input_data_5.begin();
						sample = *iter_5;
						A = sample->data();
						IDP4->Input_connector4->write(A);
					}


				}

			}
			

		}//end of test for connected ports

	} //end of for loop
	
	
	
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::execFactoryPort_out()
{
	int child_id;

	for(int i=5;i<10;i++)
	{
		if(connected_ports.test(i))
		{
			child_id = fork();
			
			if(child_id==0)
			{
				std::cout<<"Activating Port"<<std::endl;

				
				if(i==5)
				{
					prctl(PR_SET_NAME, "Fac_out_1");
					dds::sub::Sample<Data_5> sample;
					Data_5 A;	
					while(true)
					{
						ODP0->Output_connector0->take(connector_iter_1,1);
						connector_iter_1 = output_connector_data_1.begin();
						sample = *connector_iter_1;
						A = sample->data();
						ODP0->Output_writer0->write(A);
					}
				}

				if(i==6)
				{
					prctl(PR_SET_NAME, "Fac_out_2");
					dds::sub::Sample<Data_6> sample;
					Data_6 A;	
					while(true)
					{
						ODP1->Output_connector1->take(connector_iter_2,1);
						connector_iter_2 = output_connector_data_2.begin();
						sample = *connector_iter_2;
						A = sample->data();
						ODP1->Output_writer1->write(A);
					}
				}
				
				if(i==7)
				{
					prctl(PR_SET_NAME, "Fac_out_3");
					dds::sub::Sample<Data_7> sample;
					Data_7 A;
					while(true)
					{
						ODP2->Output_connector2->take(connector_iter_3,1);
						connector_iter_3 = output_connector_data_3.begin();
						sample = *connector_iter_3;
						A = sample->data();
						ODP2->Output_writer2->write(A);
					}
				}

				if(i==8)
				{
					prctl(PR_SET_NAME, "Fac_out_4");
					dds::sub::Sample<Data_8> sample;
					Data_8 A;
					while(true)
					{
						ODP3->Output_connector3->take(connector_iter_4,1);
						connector_iter_4 = output_connector_data_4.begin();
						sample = *connector_iter_4;
						A = sample->data();
						ODP3->Output_writer3->write(A);
					}
				}

				if(i==9)
				{
					prctl(PR_SET_NAME, "Fac_out_5");
					dds::sub::Sample<Data_9> sample;
					Data_9 A;
					while(true)
					{
						ODP2->Output_connector3->take(connector_iter_5,1);
						connector_iter_5 = output_connector_data_5.begin();
						sample = *connector_iter_5;
						A = sample->data();
						ODP4->Output_writer4->write(A);
					}


				}

			}
			

		}//end of test for connected ports

	}
	
	
	
	
}

template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

void Factory<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>::initialize (std::string name, double deadline, int node_id, int core_id)
{



}
