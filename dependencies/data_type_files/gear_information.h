#ifndef _GEAR_INFORMATION_H_
#define _GEAR_INFORMATION_H_

#include <dds/core/ddscore.hpp>

namespace gear_information
{
    class Msg OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        int32_t curr_gear_;

    public:
        Msg() :
                id_(0),
                curr_gear_(0) {}

        explicit Msg(
            int32_t id,
            int32_t curr_gear) : 
                id_(id),
                curr_gear_(curr_gear) {}

        Msg(const Msg &_other) : 
                id_(_other.id_),
                curr_gear_(_other.curr_gear_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                id_(::std::move(_other.id_)),
                curr_gear_(::std::move(_other.curr_gear_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                curr_gear_ = ::std::move(_other.curr_gear_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                curr_gear_ = _other.curr_gear_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return id_ == _other.id_ &&
                curr_gear_ == _other.curr_gear_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        int32_t curr_gear() const { return this->curr_gear_; }
        int32_t& curr_gear() { return this->curr_gear_; }
        void curr_gear(int32_t _val_) { this->curr_gear_ = _val_; }
    };

}

#endif /* _GEAR_INFORMATION_H_ */
