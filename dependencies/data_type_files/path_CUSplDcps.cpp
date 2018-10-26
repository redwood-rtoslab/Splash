#include "path_CU_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__path_CU_Msg__copyIn(
    c_base base,
    const class ::path_CU::Msg *from,
    struct _path_CU_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->steering_input = (c_double)from->steering_input_;
    return result;
}

void
__path_CU_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _path_CU_Msg *from = (const struct _path_CU_Msg *)_from;
    class ::path_CU::Msg *to = (class ::path_CU::Msg *)_to;
    to->id((int32_t)from->id);
    to->steering_input((double)from->steering_input);
}

