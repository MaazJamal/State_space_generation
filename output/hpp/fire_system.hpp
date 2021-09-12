//STATE DEFINITIONS

#define SMOKE_SMOKE-OFF_ALARM_SWITCH_ON 0
#define SMOKE_SMOKE-OFF_ALARM_SWITCH_OFF 1
#define SMOKE_NO_SMOKE-OFF_ALARM_ALARM_OFF 2
#define SMOKE_NO_SMOKE-OFF_ALARM_SWITCH_ON 3
#define SMOKE_NO_SMOKE-OFF_ALARM_SWITCH_OFF 4
#define SMOKE_SMOKE-ON_ALARM_ALARM_ON 5
#define SMOKE_SMOKE-ON_ALARM_ALARM_OFF 6
#define SMOKE_SMOKE-ON_ALARM_SWITCH_ON 7
#define SMOKE_SMOKE-ON_ALARM_SWITCH_OFF 8
#define SMOKE_NO_SMOKE-ON_ALARM_ALARM_OFF 9
#define SMOKE_NO_SMOKE-ON_ALARM_SWITCH_ON 10
#define SMOKE_NO_SMOKE-ON_ALARM_SWITCH_OFF 11



 //PORTS 

struct fire_system_defs {
    struct smoke_out : public out_port<string> { };
    struct alarm_out : public out_port<string> { };
    struct alarm_in : public out_port<string> { };
    struct alarm_out : public in_port<string> { };
    struct smoke_out : public in_port<string> { };
    struct fire : public in_port<string> { };
}
