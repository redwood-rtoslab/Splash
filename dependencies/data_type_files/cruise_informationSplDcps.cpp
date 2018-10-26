#include "cruise_information_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__cruise_information_Msg__copyIn(
    c_base base,
    const class ::cruise_information::Msg *from,
    struct _cruise_information_Msg *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id_;
    to->throttle = (c_double)from->throttle_;
    to->brake = (c_double)from->brake_;
    return result;
}

void
__cruise_information_Msg__copyOut(
    const void *_from,
    void *_to)
{
    const struct _cruise_information_Msg *from = (const struct _cruise_information_Msg *)_from;
    class ::cruise_information::Msg *to = (class ::cruise_information::Msg *)_to;
    to->id((int32_t)from->id);
    to->throttle((double)from->throttle);
    to->brake((double)from->brake);
}

