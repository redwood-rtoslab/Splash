#ifndef _FUSION_DATA_H_
#define _FUSION_DATA_H_

#include <dds/core/ddscore.hpp>

namespace fusion_data
{
    typedef dds::core::array< std::string, 10 > QQ;

    class Msg OSPL_DDS_FINAL
    {
    public:
        typedef dds::core::array<int32_t, 9>  _received_port;

        typedef dds::core::array<int32_t, 9>  _data_id;

        typedef dds::core::array<std::string, 9>  _message;

        int32_t fusion_data_id_;
        dds::core::array<int32_t, 9>  received_port_;
        dds::core::array<int32_t, 9>  data_id_;
        dds::core::array<std::string, 9>  message_;
        int64_t constraint_deadline_duetime_;
        int64_t constraint_freshness_gentime_;
        fusion_data::QQ test_;

    public:
        Msg() :
                fusion_data_id_(0),
                constraint_deadline_duetime_(0),
                constraint_freshness_gentime_(0) {}

        explicit Msg(
            int32_t fusion_data_id,
            const dds::core::array<int32_t, 9> & received_port,
            const dds::core::array<int32_t, 9> & data_id,
            const dds::core::array<std::string, 9> & message,
            int64_t constraint_deadline_duetime,
            int64_t constraint_freshness_gentime,
            const fusion_data::QQ& test) : 
                fusion_data_id_(fusion_data_id),
                received_port_(received_port),
                data_id_(data_id),
                message_(message),
                constraint_deadline_duetime_(constraint_deadline_duetime),
                constraint_freshness_gentime_(constraint_freshness_gentime),
                test_(test) {}

        Msg(const Msg &_other) : 
                fusion_data_id_(_other.fusion_data_id_),
                received_port_(_other.received_port_),
                data_id_(_other.data_id_),
                message_(_other.message_),
                constraint_deadline_duetime_(_other.constraint_deadline_duetime_),
                constraint_freshness_gentime_(_other.constraint_freshness_gentime_),
                test_(_other.test_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                fusion_data_id_(::std::move(_other.fusion_data_id_)),
                received_port_(::std::move(_other.received_port_)),
                data_id_(::std::move(_other.data_id_)),
                message_(::std::move(_other.message_)),
                constraint_deadline_duetime_(::std::move(_other.constraint_deadline_duetime_)),
                constraint_freshness_gentime_(::std::move(_other.constraint_freshness_gentime_)),
                test_(::std::move(_other.test_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                fusion_data_id_ = ::std::move(_other.fusion_data_id_);
                received_port_ = ::std::move(_other.received_port_);
                data_id_ = ::std::move(_other.data_id_);
                message_ = ::std::move(_other.message_);
                constraint_deadline_duetime_ = ::std::move(_other.constraint_deadline_duetime_);
                constraint_freshness_gentime_ = ::std::move(_other.constraint_freshness_gentime_);
                test_ = ::std::move(_other.test_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                fusion_data_id_ = _other.fusion_data_id_;
                received_port_ = _other.received_port_;
                data_id_ = _other.data_id_;
                message_ = _other.message_;
                constraint_deadline_duetime_ = _other.constraint_deadline_duetime_;
                constraint_freshness_gentime_ = _other.constraint_freshness_gentime_;
                test_ = _other.test_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return fusion_data_id_ == _other.fusion_data_id_ &&
                received_port_ == _other.received_port_ &&
                data_id_ == _other.data_id_ &&
                message_ == _other.message_ &&
                constraint_deadline_duetime_ == _other.constraint_deadline_duetime_ &&
                constraint_freshness_gentime_ == _other.constraint_freshness_gentime_ &&
                test_ == _other.test_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t fusion_data_id() const { return this->fusion_data_id_; }
        int32_t& fusion_data_id() { return this->fusion_data_id_; }
        void fusion_data_id(int32_t _val_) { this->fusion_data_id_ = _val_; }
        const dds::core::array<int32_t, 9> & received_port() const { return this->received_port_; }
        dds::core::array<int32_t, 9> & received_port() { return this->received_port_; }
        void received_port(const dds::core::array<int32_t, 9> & _val_) { this->received_port_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void received_port(dds::core::array<int32_t, 9> && _val_) { this->received_port_ = _val_; }
#endif
        const dds::core::array<int32_t, 9> & data_id() const { return this->data_id_; }
        dds::core::array<int32_t, 9> & data_id() { return this->data_id_; }
        void data_id(const dds::core::array<int32_t, 9> & _val_) { this->data_id_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void data_id(dds::core::array<int32_t, 9> && _val_) { this->data_id_ = _val_; }
#endif
        const dds::core::array<std::string, 9> & message() const { return this->message_; }
        dds::core::array<std::string, 9> & message() { return this->message_; }
        void message(const dds::core::array<std::string, 9> & _val_) { this->message_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void message(dds::core::array<std::string, 9> && _val_) { this->message_ = _val_; }
#endif
        int64_t constraint_deadline_duetime() const { return this->constraint_deadline_duetime_; }
        int64_t& constraint_deadline_duetime() { return this->constraint_deadline_duetime_; }
        void constraint_deadline_duetime(int64_t _val_) { this->constraint_deadline_duetime_ = _val_; }
        int64_t constraint_freshness_gentime() const { return this->constraint_freshness_gentime_; }
        int64_t& constraint_freshness_gentime() { return this->constraint_freshness_gentime_; }
        void constraint_freshness_gentime(int64_t _val_) { this->constraint_freshness_gentime_ = _val_; }
        const fusion_data::QQ& test() const { return this->test_; }
        fusion_data::QQ& test() { return this->test_; }
        void test(const fusion_data::QQ& _val_) { this->test_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void test(fusion_data::QQ&& _val_) { this->test_ = _val_; }
#endif
    };

}

#endif /* _FUSION_DATA_H_ */
