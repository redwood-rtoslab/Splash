#include "cruise_speed_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__cruise_speed_Msg__copyIn(
    c_base base,
    const class ::cruise_speed::Msg *from,
    struct _cruise_speed_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->curr_speed = (c_double)from->curr_speed_;
    return result;
}

void
__cruise_speed_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _cruise_speed_Msg *from = (const struct _cruise_speed_Msg *)_from;
    class ::cruise_speed::Msg *to = (class ::cruise_speed::Msg *)_to;
    to->id((int32_t)from->id);
    to->curr_speed((double)from->curr_speed);
}

