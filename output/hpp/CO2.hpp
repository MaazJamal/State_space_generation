//STATE DEFINITIONS

#define CO2_LOW-OPEN_VENTS_SHUT 0
#define CO2_LOW-CLOSED_VENTS_SHUT 1
#define CO2_LOW-CLOSED_VENTS_CLOSING 2
#define CO2_LOW-CLOSED_VENTS_OPENING 3
#define CO2_LOW-CLOSED_VENTS_FULL_OPEN 4
#define CO2_LOW-OPEN_VENTS_CLOSING 5
#define CO2_LOW-OPEN_VENTS_OPENING 6
#define CO2_MEDIUM-OPEN_VENTS_SHUT 7
#define CO2_MEDIUM-CLOSED_VENTS_SHUT 8
#define CO2_MEDIUM-CLOSED_VENTS_CLOSING 9
#define CO2_MEDIUM-CLOSED_VENTS_OPENING 10
#define CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN 11
#define CO2_MEDIUM-OPEN_VENTS_CLOSING 12
#define CO2_MEDIUM-OPEN_VENTS_OPENING 13
#define CO2_MEDIUM-OPEN_VENTS_FULL_OPEN 14
#define CO2_HIGH-OPEN_VENTS_SHUT 15
#define CO2_HIGH-CLOSED_VENTS_CLOSING 16
#define CO2_HIGH-CLOSED_VENTS_OPENING 17
#define CO2_HIGH-CLOSED_VENTS_FULL_OPEN 18
#define CO2_HIGH-OPEN_VENTS_CLOSING 19
#define CO2_HIGH-OPEN_VENTS_OPENING 20
#define CO2_HIGH-OPEN_VENTS_FULL_OPEN 21



 //PORTS 

struct CO2_defs {
    struct vents_out : public out_port<string> { };
    struct co2 : public out_port<string> { };
    struct co2_out : public out_port<string> { };
    struct vent_out : public in_port<string> { };
    struct vent : public in_port<string> { };
    struct co2_out : public in_port<string> { };
}
