#ifndef _CRUISE_SPEED_H_
#define _CRUISE_SPEED_H_

#include <dds/core/ddscore.hpp>

namespace cruise_speed
{
    class Msg OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        double curr_speed_;

    public:
        Msg() :
                id_(0),
                curr_speed_(0.0) {}

        explicit Msg(
            int32_t id,
            double curr_speed) : 
                id_(id),
                curr_speed_(curr_speed) {}

        Msg(const Msg &_other) : 
                id_(_other.id_),
                curr_speed_(_other.curr_speed_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                id_(::std::move(_other.id_)),
                curr_speed_(::std::move(_other.curr_speed_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                curr_speed_ = ::std::move(_other.curr_speed_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                curr_speed_ = _other.curr_speed_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return id_ == _other.id_ &&
                curr_speed_ == _other.curr_speed_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        double curr_speed() const { return this->curr_speed_; }
        double& curr_speed() { return this->curr_speed_; }
        void curr_speed(double _val_) { this->curr_speed_ = _val_; }
    };

}

#endif /* _CRUISE_SPEED_H_ */
