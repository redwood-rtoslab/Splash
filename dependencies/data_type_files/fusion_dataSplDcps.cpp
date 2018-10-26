#include "fusion_data_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__fusion_data_QQ__copyIn(
    c_base base,
    const ::fusion_data::QQ *from,
    _fusion_data_QQ *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    int i1;

    for (i1 = 0; (i1 < 10) && V_COPYIN_RESULT_IS_OK(result); i1++) {
#ifdef OSPL_BOUNDS_CHECK
        if(((*from).data())[i1]){
            (*to)[i1] = c_stringNew_s(base, ((*from).data())[i1].c_str());
            if((*to)[i1] == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Element of 'fusion_data.(*from).data()' of type 'c_string' is NULL.");
            result = V_COPYIN_RESULT_INVALID;
        }
#else
        (*to)[i1] = c_stringNew_s(base, ((*from).data())[i1].c_str());
        if((*to)[i1] == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#endif
    }
    return result;
}

v_copyin_result
__fusion_data_Msg__copyIn(
    c_base base,
    const class ::fusion_data::Msg *from,
    struct _fusion_data_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->fusion_data_id = (c_long)from->fusion_data_id_;
    {
        typedef c_long _DestType[9];
        _DestType *dest = &to->received_port;
        memcpy (dest, (from->received_port_).data(), sizeof (*dest));
    }
    {
        typedef c_long _DestType[9];
        _DestType *dest = &to->data_id;
        memcpy (dest, (from->data_id_).data(), sizeof (*dest));
    }
    {
        typedef c_string _DestType[9];
        _DestType *dest = &to->message;
        int i1;

        for (i1 = 0; (i1 < 9) && V_COPYIN_RESULT_IS_OK(result); i1++) {
#ifdef OSPL_BOUNDS_CHECK
            if(((from->message_).data())[i1]){
                (*dest)[i1] = c_stringNew_s(base, ((from->message_).data())[i1].c_str());
                if((*dest)[i1] == NULL) {
                    result = V_COPYIN_RESULT_OUT_OF_MEMORY;
                }
            } else {
                OS_REPORT (OS_ERROR, "copyIn", 0,"Element of 'fusion_data::Msg.(from->message_).data()' of type 'c_string' is NULL.");
                result = V_COPYIN_RESULT_INVALID;
            }
#else
            (*dest)[i1] = c_stringNew_s(base, ((from->message_).data())[i1].c_str());
            if((*dest)[i1] == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
        }
    }
    to->constraint_deadline_duetime = (c_longlong)from->constraint_deadline_duetime_;
    to->constraint_freshness_gentime = (c_longlong)from->constraint_freshness_gentime_;
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __fusion_data_QQ__copyIn(c_base, const ::fusion_data::QQ *, _fusion_data_QQ *);
        result = __fusion_data_QQ__copyIn(base, &from->test_, &to->test);
    }
    return result;
}

void
__fusion_data_QQ__copyOut(
    const void *_from,
    void *_to)
{
    const _fusion_data_QQ *from = (const _fusion_data_QQ *)_from;
    ::fusion_data::QQ *to = (::fusion_data::QQ *)_to;
    int i1;

    for (i1 = 0; (i1 < 10); i1++) {
        (*to)[i1] = ((*from)[i1]) ? ((*from)[i1]) : "";
    }
}

void
__fusion_data_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _fusion_data_Msg *from = (const struct _fusion_data_Msg *)_from;
    class ::fusion_data::Msg *to = (class ::fusion_data::Msg *)_to;
    to->fusion_data_id((int32_t)from->fusion_data_id);
    {
        typedef c_long _DestType[9];
        const _DestType *src = &from->received_port;

        dds::core::array< int32_t, 9 > *dst = &to->received_port();

        memcpy ((void *)(*dst).data(), src, sizeof (*src));
    }
    {
        typedef c_long _DestType[9];
        const _DestType *src = &from->data_id;

        dds::core::array< int32_t, 9 > *dst = &to->data_id();

        memcpy ((void *)(*dst).data(), src, sizeof (*src));
    }
    {
        typedef c_string _DestType[9];
        const _DestType *src = &from->message;

        dds::core::array< std::string, 9 > *dst = &to->message();

        int i1;

        for (i1 = 0; (i1 < 9); i1++) {
            (*dst)[i1] = ((*src)[i1]) ? ((*src)[i1]) : "";
        }
    }
    to->constraint_deadline_duetime((int64_t)from->constraint_deadline_duetime);
    to->constraint_freshness_gentime((int64_t)from->constraint_freshness_gentime);
    {
        extern void __fusion_data_QQ__copyOut(const void *, void *);
        ::fusion_data::QQ &tmp = to->test();
        __fusion_data_QQ__copyOut((const void *)&from->test, (void *)&tmp);
    }
}

