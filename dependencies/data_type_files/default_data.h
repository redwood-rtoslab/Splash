#ifndef _DEFAULT_DATA_H_
#define _DEFAULT_DATA_H_

#include <dds/core/ddscore.hpp>

namespace default_data
{
    class Msg OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        std::string message_;
        int64_t constraint_deadline_duetime_;
        int64_t constraint_freshness_gentime_;
        int64_t sensor_data_;

    public:
        Msg() :
                id_(0),
                constraint_deadline_duetime_(0),
                constraint_freshness_gentime_(0),
                sensor_data_(0) {}

        explicit Msg(
            int32_t id,
            const std::string& message,
            int64_t constraint_deadline_duetime,
            int64_t constraint_freshness_gentime,
            int64_t sensor_data) : 
                id_(id),
                message_(message),
                constraint_deadline_duetime_(constraint_deadline_duetime),
                constraint_freshness_gentime_(constraint_freshness_gentime),
                sensor_data_(sensor_data) {}

        Msg(const Msg &_other) : 
                id_(_other.id_),
                message_(_other.message_),
                constraint_deadline_duetime_(_other.constraint_deadline_duetime_),
                constraint_freshness_gentime_(_other.constraint_freshness_gentime_),
                sensor_data_(_other.sensor_data_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                id_(::std::move(_other.id_)),
                message_(::std::move(_other.message_)),
                constraint_deadline_duetime_(::std::move(_other.constraint_deadline_duetime_)),
                constraint_freshness_gentime_(::std::move(_other.constraint_freshness_gentime_)),
                sensor_data_(::std::move(_other.sensor_data_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                message_ = ::std::move(_other.message_);
                constraint_deadline_duetime_ = ::std::move(_other.constraint_deadline_duetime_);
                constraint_freshness_gentime_ = ::std::move(_other.constraint_freshness_gentime_);
                sensor_data_ = ::std::move(_other.sensor_data_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                message_ = _other.message_;
                constraint_deadline_duetime_ = _other.constraint_deadline_duetime_;
                constraint_freshness_gentime_ = _other.constraint_freshness_gentime_;
                sensor_data_ = _other.sensor_data_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return id_ == _other.id_ &&
                message_ == _other.message_ &&
                constraint_deadline_duetime_ == _other.constraint_deadline_duetime_ &&
                constraint_freshness_gentime_ == _other.constraint_freshness_gentime_ &&
                sensor_data_ == _other.sensor_data_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        const std::string& message() const { return this->message_; }
        std::string& message() { return this->message_; }
        void message(const std::string& _val_) { this->message_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void message(std::string&& _val_) { this->message_ = _val_; }
#endif
        int64_t constraint_deadline_duetime() const { return this->constraint_deadline_duetime_; }
        int64_t& constraint_deadline_duetime() { return this->constraint_deadline_duetime_; }
        void constraint_deadline_duetime(int64_t _val_) { this->constraint_deadline_duetime_ = _val_; }
        int64_t constraint_freshness_gentime() const { return this->constraint_freshness_gentime_; }
        int64_t& constraint_freshness_gentime() { return this->constraint_freshness_gentime_; }
        void constraint_freshness_gentime(int64_t _val_) { this->constraint_freshness_gentime_ = _val_; }
        int64_t sensor_data() const { return this->sensor_data_; }
        int64_t& sensor_data() { return this->sensor_data_; }
        void sensor_data(int64_t _val_) { this->sensor_data_ = _val_; }
    };

}

#endif /* _DEFAULT_DATA_H_ */
