template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_PB;


template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class OutputDataPort_PB;


template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class EventDataPort_PB;




template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class ProcessingBlock
{
        private:

        public:

                dds::domain::DomainParticipant default_dp{org::opensplice::domain::default_id()};
                dds::pub::Publisher PB_pub{default_dp, default_dp.default_publisher_qos()};
                dds::sub::Subscriber PB_sub{default_dp, default_dp.default_subscriber_qos()};

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
                dds::topic::Topic<int>* topic_event;

                InputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* IDP0;

                InputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* IDP1;

                InputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* IDP2;

                InputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* IDP3;

                InputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* IDP4;


                OutputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* ODP0;

                OutputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* ODP1;

                OutputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* ODP2;

                OutputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* ODP3;

                OutputDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* ODP4;

                EventDataPort_PB<Data_0, Data_1,
                              Data_2, Data_3,
                              Data_4, Data_5,
                              Data_6, Data_7,
                              Data_8, Data_9>* EDP;

                int write(Data_5);
                int write(Data_6);
                int write(Data_7);
                int write(Data_8);
                int write(Data_9);
                int write_event(int);

                void read(dds::sub::LoanedSamples<Data_0>*);
                void read(dds::sub::LoanedSamples<Data_1>*);
                void read(dds::sub::LoanedSamples<Data_2>*);
                void read(dds::sub::LoanedSamples<Data_3>*);
                void read(dds::sub::LoanedSamples<Data_4>*);


};












template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class InputDataPort_PB
{
        private:
        public:

                dds::sub::DataReader<Data_0>* IDP_reader0;
                dds::sub::DataReader<Data_1>* IDP_reader1;
                dds::sub::DataReader<Data_2>* IDP_reader2;
                dds::sub::DataReader<Data_3>* IDP_reader3;
                dds::sub::DataReader<Data_4>* IDP_reader4;
                int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);

};


template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>
class OutputDataPort_PB
{
        private:

        public:
                dds::pub::DataWriter<Data_5>* ODP_writer0;
                dds::pub::DataWriter<Data_6>* ODP_writer1;
                dds::pub::DataWriter<Data_7>* ODP_writer2;
                dds::pub::DataWriter<Data_8>* ODP_writer3;
                dds::pub::DataWriter<Data_9>* ODP_writer4;
                int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string, int);

};


template
<typename Data_0, typename Data_1,
typename Data_2, typename Data_3,
typename Data_4, typename Data_5,
typename Data_6, typename Data_7,
typename Data_8, typename Data_9>

class EventDataPort_PB
{
        private:
        public:

                dds::pub::DataWriter<int>* EDP_writer;
                int attach(ProcessingBlock<Data_0,Data_1,Data_2,Data_3,Data_4,Data_5,Data_6,Data_7,Data_8,Data_9>*, std::string);

};

