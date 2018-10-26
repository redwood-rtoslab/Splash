#include "gear_information_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__gear_information_Msg__copyIn(
    c_base base,
    const class ::gear_information::Msg *from,
    struct _gear_information_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->curr_gear = (c_long)from->curr_gear_;
    return result;
}

void
__gear_information_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _gear_information_Msg *from = (const struct _gear_information_Msg *)_from;
    class ::gear_information::Msg *to = (class ::gear_information::Msg *)_to;
    to->id((int32_t)from->id);
    to->curr_gear((int32_t)from->curr_gear);
}

