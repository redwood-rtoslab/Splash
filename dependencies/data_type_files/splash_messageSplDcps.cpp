#include "splash_message_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__splash_message_new_record__copyIn(
    c_base base,
    const class ::splash_message::new_record *from,
    struct _splash_message_new_record *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->a = (c_bool)from->a_;
#ifdef OSPL_BOUNDS_CHECK
        if(((unsigned int)from->sibal_.length())) <= 28){
            to->sibal = c_stringNew_s(base, from->sibal_.c_str());
            if(to->sibal == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'splash_message::new_record.sibal' of type 'C_STRING<28>' is out of range.");
            result = V_COPYIN_RESULT_INVALID;
        }
#else
            to->sibal = c_stringNew_s(base, from->sibal_.c_str());
            if(to->sibal == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    return result;
}

v_copyin_result
__splash_message_msg0__copyIn(
    c_base base,
    const class ::splash_message::msg0 *from,
    struct _splash_message_msg0 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->k = (c_bool)from->k_;
    return result;
}

v_copyin_result
__splash_message_msg1__copyIn(
    c_base base,
    const class ::splash_message::msg1 *from,
    struct _splash_message_msg1 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->a = (c_double)from->a_;
    to->b = (c_double)from->b_;
    return result;
}

v_copyin_result
__splash_message_msg2__copyIn(
    c_base base,
    const class ::splash_message::msg2 *from,
    struct _splash_message_msg2 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->sibal = (c_short)from->sibal_;
    return result;
}

v_copyin_result
__splash_message_msg3__copyIn(
    c_base base,
    const class ::splash_message::msg3 *from,
    struct _splash_message_msg3 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
#ifdef OSPL_BOUNDS_CHECK
        if(((unsigned int)from->str_.length())) <= 14){
            to->str = c_stringNew_s(base, from->str_.c_str());
            if(to->str == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'splash_message::msg3.str' of type 'C_STRING<14>' is out of range.");
            result = V_COPYIN_RESULT_INVALID;
        }
#else
            to->str = c_stringNew_s(base, from->str_.c_str());
            if(to->str == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    to->sisi = (c_longlong)from->sisi_;
    return result;
}

v_copyin_result
__splash_message_msg4__copyIn(
    c_base base,
    const class ::splash_message::msg4 *from,
    struct _splash_message_msg4 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->a = (c_float)from->a_;
    to->kk = (c_long)from->kk_;
    return result;
}

v_copyin_result
__splash_message_msg5__copyIn(
    c_base base,
    const class ::splash_message::msg5 *from,
    struct _splash_message_msg5 *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->cc = (c_char)from->cc_;
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __splash_message_new_record__copyIn(c_base, const ::splash_message::new_record *, _splash_message_new_record *);
        result = __splash_message_new_record__copyIn(base, &from->A_, &to->A);
    }
    return result;
}

void
__splash_message_new_record__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_new_record *from = (const struct _splash_message_new_record *)_from;
    class ::splash_message::new_record *to = (class ::splash_message::new_record *)_to;
    to->a((bool)from->a);
    to->sibal(from->sibal ? from->sibal : "");
}

void
__splash_message_msg0__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg0 *from = (const struct _splash_message_msg0 *)_from;
    class ::splash_message::msg0 *to = (class ::splash_message::msg0 *)_to;
    to->id((int32_t)from->id);
    to->k((bool)from->k);
}

void
__splash_message_msg1__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg1 *from = (const struct _splash_message_msg1 *)_from;
    class ::splash_message::msg1 *to = (class ::splash_message::msg1 *)_to;
    to->id((int32_t)from->id);
    to->a((double)from->a);
    to->b((double)from->b);
}

void
__splash_message_msg2__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg2 *from = (const struct _splash_message_msg2 *)_from;
    class ::splash_message::msg2 *to = (class ::splash_message::msg2 *)_to;
    to->id((int32_t)from->id);
    to->sibal((int16_t)from->sibal);
}

void
__splash_message_msg3__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg3 *from = (const struct _splash_message_msg3 *)_from;
    class ::splash_message::msg3 *to = (class ::splash_message::msg3 *)_to;
    to->id((int32_t)from->id);
    to->str(from->str ? from->str : "");
    to->sisi((int64_t)from->sisi);
}

void
__splash_message_msg4__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg4 *from = (const struct _splash_message_msg4 *)_from;
    class ::splash_message::msg4 *to = (class ::splash_message::msg4 *)_to;
    to->id((int32_t)from->id);
    to->a((float)from->a);
    to->kk((int32_t)from->kk);
}

void
__splash_message_msg5__copyOut(
    const void *_from,
    void *_to)
{
    const struct _splash_message_msg5 *from = (const struct _splash_message_msg5 *)_from;
    class ::splash_message::msg5 *to = (class ::splash_message::msg5 *)_to;
    to->id((int32_t)from->id);
    to->cc((char)from->cc);
    {
        extern void __splash_message_new_record__copyOut(const void *, void *);
        ::splash_message::new_record &tmp = to->A();
        __splash_message_new_record__copyOut((const void *)&from->A, &tmp);
    }
}

