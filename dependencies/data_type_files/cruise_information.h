#ifndef _CRUISE_INFORMATION_H_
#define _CRUISE_INFORMATION_H_

#include <dds/core/ddscore.hpp>

namespace cruise_information
{
    class Msg OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        double throttle_;
        double brake_;

    public:
        Msg() :
                id_(0),
                throttle_(0.0),
                brake_(0.0) {}

        explicit Msg(
            int32_t id,
            double throttle,
            double brake) : 
                id_(id),
                throttle_(throttle),
                brake_(brake) {}

        Msg(const Msg &_other) : 
                id_(_other.id_),
                throttle_(_other.throttle_),
                brake_(_other.brake_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                id_(::std::move(_other.id_)),
                throttle_(::std::move(_other.throttle_)),
                brake_(::std::move(_other.brake_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                throttle_ = ::std::move(_other.throttle_);
                brake_ = ::std::move(_other.brake_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                throttle_ = _other.throttle_;
                brake_ = _other.brake_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return id_ == _other.id_ &&
                throttle_ == _other.throttle_ &&
                brake_ == _other.brake_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        double throttle() const { return this->throttle_; }
        double& throttle() { return this->throttle_; }
        void throttle(double _val_) { this->throttle_ = _val_; }
        double brake() const { return this->brake_; }
        double& brake() { return this->brake_; }
        void brake(double _val_) { this->brake_ = _val_; }
    };

}

#endif /* _CRUISE_INFORMATION_H_ */
