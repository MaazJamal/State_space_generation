//STATE DEFINITIONS

#define OCCUP_OCCUPIED_LIGHT_ON 0
#define OCCUP_EXIT_LIGHT_ON 1
#define OCCUP_EXIT_LIGHT_OFF 2
#define OCCUP_OCCUPIED_LIGHT_SWITCH_ON 3
#define OCCUP_EXIT_LIGHT_SWITCH_ON 4
#define OCCUP_OCCUPIED_LIGHT_SWITCH_OFF 5
#define OCCUP_EXIT_LIGHT_SWITCH_OFF 6
#define OCCUP_ENTRY_LIGHT_ON 7
#define OCCUP_NOT_OCCUPIED_LIGHT_OFF 8
#define OCCUP_ENTRY_LIGHT_OFF 9
#define OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON 10
#define OCCUP_ENTRY_LIGHT_SWITCH_ON 11
#define OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF 12
#define OCCUP_ENTRY_LIGHT_SWITCH_OFF 13



 //PORTS 

struct occupency_defs {
    struct occupency_out : public out_port<string> { };
    struct occupency_in : public out_port<string> { };
    struct ocp : public out_port<string> { };
    struct light_out : public in_port<string> { };
    struct light : public in_port<string> { };
}


//INTERNAL TRANSITIONS

switch (this->state.state) {
    case {}:
