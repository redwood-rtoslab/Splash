#ifndef _PATH_CU_H_
#define _PATH_CU_H_

#include <dds/core/ddscore.hpp>

namespace path_CU
{
    class Msg OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        double steering_input_;

    public:
        Msg() :
                id_(0),
                steering_input_(0.0) {}

        explicit Msg(
            int32_t id,
            double steering_input) : 
                id_(id),
                steering_input_(steering_input) {}

        Msg(const Msg &_other) : 
                id_(_other.id_),
                steering_input_(_other.steering_input_) {}

#ifdef OSPL_DDS_CXX11
        Msg(Msg &&_other) : 
                id_(::std::move(_other.id_)),
                steering_input_(::std::move(_other.steering_input_)) {}

        Msg& operator=(Msg &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                steering_input_ = ::std::move(_other.steering_input_);
            }
            return *this;
        }
#endif

        Msg& operator=(const Msg &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                steering_input_ = _other.steering_input_;
            }
            return *this;
        }

        bool operator==(const Msg& _other) const
        {
            return id_ == _other.id_ &&
                steering_input_ == _other.steering_input_;
        }

        bool operator!=(const Msg& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        double steering_input() const { return this->steering_input_; }
        double& steering_input() { return this->steering_input_; }
        void steering_input(double _val_) { this->steering_input_ = _val_; }
    };

}

#endif /* _PATH_CU_H_ */
