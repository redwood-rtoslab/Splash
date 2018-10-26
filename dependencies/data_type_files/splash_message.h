#ifndef _SPLASH_MESSAGE_H_
#define _SPLASH_MESSAGE_H_

#include <dds/core/ddscore.hpp>

namespace splash_message
{
    class new_record OSPL_DDS_FINAL
    {
    public:
        bool a_;
        std::string sibal_;

    public:
        new_record() :
                a_(false) {}

        explicit new_record(
            bool a,
            const std::string& sibal) : 
                a_(a),
                sibal_(sibal) {}

        new_record(const new_record &_other) : 
                a_(_other.a_),
                sibal_(_other.sibal_) {}

#ifdef OSPL_DDS_CXX11
        new_record(new_record &&_other) : 
                a_(::std::move(_other.a_)),
                sibal_(::std::move(_other.sibal_)) {}

        new_record& operator=(new_record &&_other)
        {
            if (this != &_other) {
                a_ = ::std::move(_other.a_);
                sibal_ = ::std::move(_other.sibal_);
            }
            return *this;
        }
#endif

        new_record& operator=(const new_record &_other)
        {
            if (this != &_other) {
                a_ = _other.a_;
                sibal_ = _other.sibal_;
            }
            return *this;
        }

        bool operator==(const new_record& _other) const
        {
            return a_ == _other.a_ &&
                sibal_ == _other.sibal_;
        }

        bool operator!=(const new_record& _other) const
        {
            return !(*this == _other);
        }

        bool a() const { return this->a_; }
        bool& a() { return this->a_; }
        void a(bool _val_) { this->a_ = _val_; }
        const std::string& sibal() const { return this->sibal_; }
        std::string& sibal() { return this->sibal_; }
        void sibal(const std::string& _val_) { this->sibal_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void sibal(std::string&& _val_) { this->sibal_ = _val_; }
#endif
    };

    class msg0 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        bool k_;

    public:
        msg0() :
                id_(0),
                k_(false) {}

        explicit msg0(
            int32_t id,
            bool k) : 
                id_(id),
                k_(k) {}

        msg0(const msg0 &_other) : 
                id_(_other.id_),
                k_(_other.k_) {}

#ifdef OSPL_DDS_CXX11
        msg0(msg0 &&_other) : 
                id_(::std::move(_other.id_)),
                k_(::std::move(_other.k_)) {}

        msg0& operator=(msg0 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                k_ = ::std::move(_other.k_);
            }
            return *this;
        }
#endif

        msg0& operator=(const msg0 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                k_ = _other.k_;
            }
            return *this;
        }

        bool operator==(const msg0& _other) const
        {
            return id_ == _other.id_ &&
                k_ == _other.k_;
        }

        bool operator!=(const msg0& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        bool k() const { return this->k_; }
        bool& k() { return this->k_; }
        void k(bool _val_) { this->k_ = _val_; }
    };

    class msg1 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        double a_;
        double b_;

    public:
        msg1() :
                id_(0),
                a_(0.0),
                b_(0.0) {}

        explicit msg1(
            int32_t id,
            double a,
            double b) : 
                id_(id),
                a_(a),
                b_(b) {}

        msg1(const msg1 &_other) : 
                id_(_other.id_),
                a_(_other.a_),
                b_(_other.b_) {}

#ifdef OSPL_DDS_CXX11
        msg1(msg1 &&_other) : 
                id_(::std::move(_other.id_)),
                a_(::std::move(_other.a_)),
                b_(::std::move(_other.b_)) {}

        msg1& operator=(msg1 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                a_ = ::std::move(_other.a_);
                b_ = ::std::move(_other.b_);
            }
            return *this;
        }
#endif

        msg1& operator=(const msg1 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                a_ = _other.a_;
                b_ = _other.b_;
            }
            return *this;
        }

        bool operator==(const msg1& _other) const
        {
            return id_ == _other.id_ &&
                a_ == _other.a_ &&
                b_ == _other.b_;
        }

        bool operator!=(const msg1& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        double a() const { return this->a_; }
        double& a() { return this->a_; }
        void a(double _val_) { this->a_ = _val_; }
        double b() const { return this->b_; }
        double& b() { return this->b_; }
        void b(double _val_) { this->b_ = _val_; }
    };

    class msg2 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        int16_t sibal_;

    public:
        msg2() :
                id_(0),
                sibal_(0) {}

        explicit msg2(
            int32_t id,
            int16_t sibal) : 
                id_(id),
                sibal_(sibal) {}

        msg2(const msg2 &_other) : 
                id_(_other.id_),
                sibal_(_other.sibal_) {}

#ifdef OSPL_DDS_CXX11
        msg2(msg2 &&_other) : 
                id_(::std::move(_other.id_)),
                sibal_(::std::move(_other.sibal_)) {}

        msg2& operator=(msg2 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                sibal_ = ::std::move(_other.sibal_);
            }
            return *this;
        }
#endif

        msg2& operator=(const msg2 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                sibal_ = _other.sibal_;
            }
            return *this;
        }

        bool operator==(const msg2& _other) const
        {
            return id_ == _other.id_ &&
                sibal_ == _other.sibal_;
        }

        bool operator!=(const msg2& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        int16_t sibal() const { return this->sibal_; }
        int16_t& sibal() { return this->sibal_; }
        void sibal(int16_t _val_) { this->sibal_ = _val_; }
    };

    class msg3 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        std::string str_;
        int64_t sisi_;

    public:
        msg3() :
                id_(0),
                sisi_(0) {}

        explicit msg3(
            int32_t id,
            const std::string& str,
            int64_t sisi) : 
                id_(id),
                str_(str),
                sisi_(sisi) {}

        msg3(const msg3 &_other) : 
                id_(_other.id_),
                str_(_other.str_),
                sisi_(_other.sisi_) {}

#ifdef OSPL_DDS_CXX11
        msg3(msg3 &&_other) : 
                id_(::std::move(_other.id_)),
                str_(::std::move(_other.str_)),
                sisi_(::std::move(_other.sisi_)) {}

        msg3& operator=(msg3 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                str_ = ::std::move(_other.str_);
                sisi_ = ::std::move(_other.sisi_);
            }
            return *this;
        }
#endif

        msg3& operator=(const msg3 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                str_ = _other.str_;
                sisi_ = _other.sisi_;
            }
            return *this;
        }

        bool operator==(const msg3& _other) const
        {
            return id_ == _other.id_ &&
                str_ == _other.str_ &&
                sisi_ == _other.sisi_;
        }

        bool operator!=(const msg3& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        const std::string& str() const { return this->str_; }
        std::string& str() { return this->str_; }
        void str(const std::string& _val_) { this->str_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void str(std::string&& _val_) { this->str_ = _val_; }
#endif
        int64_t sisi() const { return this->sisi_; }
        int64_t& sisi() { return this->sisi_; }
        void sisi(int64_t _val_) { this->sisi_ = _val_; }
    };

    class msg4 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        float a_;
        int32_t kk_;

    public:
        msg4() :
                id_(0),
                a_(0.0f),
                kk_(0) {}

        explicit msg4(
            int32_t id,
            float a,
            int32_t kk) : 
                id_(id),
                a_(a),
                kk_(kk) {}

        msg4(const msg4 &_other) : 
                id_(_other.id_),
                a_(_other.a_),
                kk_(_other.kk_) {}

#ifdef OSPL_DDS_CXX11
        msg4(msg4 &&_other) : 
                id_(::std::move(_other.id_)),
                a_(::std::move(_other.a_)),
                kk_(::std::move(_other.kk_)) {}

        msg4& operator=(msg4 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                a_ = ::std::move(_other.a_);
                kk_ = ::std::move(_other.kk_);
            }
            return *this;
        }
#endif

        msg4& operator=(const msg4 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                a_ = _other.a_;
                kk_ = _other.kk_;
            }
            return *this;
        }

        bool operator==(const msg4& _other) const
        {
            return id_ == _other.id_ &&
                a_ == _other.a_ &&
                kk_ == _other.kk_;
        }

        bool operator!=(const msg4& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        float a() const { return this->a_; }
        float& a() { return this->a_; }
        void a(float _val_) { this->a_ = _val_; }
        int32_t kk() const { return this->kk_; }
        int32_t& kk() { return this->kk_; }
        void kk(int32_t _val_) { this->kk_ = _val_; }
    };

    class msg5 OSPL_DDS_FINAL
    {
    public:
        int32_t id_;
        char cc_;
        splash_message::new_record A_;

    public:
        msg5() :
                id_(0),
                cc_(0) {}

        explicit msg5(
            int32_t id,
            char cc,
            const splash_message::new_record& A) : 
                id_(id),
                cc_(cc),
                A_(A) {}

        msg5(const msg5 &_other) : 
                id_(_other.id_),
                cc_(_other.cc_),
                A_(_other.A_) {}

#ifdef OSPL_DDS_CXX11
        msg5(msg5 &&_other) : 
                id_(::std::move(_other.id_)),
                cc_(::std::move(_other.cc_)),
                A_(::std::move(_other.A_)) {}

        msg5& operator=(msg5 &&_other)
        {
            if (this != &_other) {
                id_ = ::std::move(_other.id_);
                cc_ = ::std::move(_other.cc_);
                A_ = ::std::move(_other.A_);
            }
            return *this;
        }
#endif

        msg5& operator=(const msg5 &_other)
        {
            if (this != &_other) {
                id_ = _other.id_;
                cc_ = _other.cc_;
                A_ = _other.A_;
            }
            return *this;
        }

        bool operator==(const msg5& _other) const
        {
            return id_ == _other.id_ &&
                cc_ == _other.cc_ &&
                A_ == _other.A_;
        }

        bool operator!=(const msg5& _other) const
        {
            return !(*this == _other);
        }

        int32_t id() const { return this->id_; }
        int32_t& id() { return this->id_; }
        void id(int32_t _val_) { this->id_ = _val_; }
        char cc() const { return this->cc_; }
        char& cc() { return this->cc_; }
        void cc(char _val_) { this->cc_ = _val_; }
        const splash_message::new_record& A() const { return this->A_; }
        splash_message::new_record& A() { return this->A_; }
        void A(const splash_message::new_record& _val_) { this->A_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void A(splash_message::new_record&& _val_) { this->A_ = _val_; }
#endif
    };

}

#endif /* _SPLASH_MESSAGE_H_ */
