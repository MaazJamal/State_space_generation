//STATE DEFINITIONS

#define WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF 0
#define WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON 1
#define WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF 2
#define WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF 3
#define WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON 4
#define WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON 5
#define WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 6
#define WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 7
#define WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 8
#define WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 9
#define WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 10
#define WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 11
#define WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF 12
#define WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON 13
#define WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF 14
#define WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON 15
#define WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 16
#define WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 17
#define WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 18
#define WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 19
#define WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF 20
#define WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON 21
#define WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF 22
#define WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON 23
#define WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 24
#define WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 25
#define WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 26
#define WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 27
#define WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF 28
#define WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON 29
#define WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF 30
#define WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON 31
#define WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 32
#define WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 33
#define WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 34
#define WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 35
#define WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF 36
#define WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON 37
#define WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF 38
#define WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON 39
#define WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 40
#define WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 41
#define WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 42
#define WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 43
#define WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF 44
#define WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON 45
#define WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF 46
#define WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON 47
#define WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 48
#define WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 49
#define WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF 50
#define WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON 51
#define WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF 52
#define WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON 53
#define WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF 54
#define WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON 55



 //PORTS 

struct water_temperature_defs {
    struct boiler_out : public out_port<string> { };
    struct occ_in : public out_port<string> { };
    struct water : public out_port<string> { };
    struct boiler_in : public out_port<string> { };
    struct boiler_out : public in_port<string> { };
    struct boi : public in_port<string> { };
    struct water_out : public in_port<string> { };
    struct occ_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::boiler_out,typename defs::boi,typename defs::water_out,typename defs::occ_out>;
    using output_ports = std::tuple<typename defs::boiler_out,typename defs::occ_in,typename defs::water,typename defs::boiler_in>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COLD_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COLD_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_in";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_VERYHOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_VERYHOT_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "off";
        this->ta = fin;
        break;
    case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COLD_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COLD_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "boiler_out";
        this->out = "on";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
        this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "boiler_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = inf;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "boi") {
    }
    if(this->in_port == "water_out") {
        if(this->in == "vlow"){
            switch (this->state.state) {
                case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "low"){
            switch (this->state.state) {
                case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "med"){
            switch (this->state.state) {
                case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "high"){
            switch (this->state.state) {
                case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "vhigh"){
            switch (this->state.state) {
                case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "occ_out") {
        if(this->in == "oclow"){
            switch (this->state.state) {
                case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
                case WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "ochigh"){
            switch (this->state.state) {
                case WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COLD_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_OFF_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_COOL_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_WARM_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_HOT_ON_BOI_SWITCH_OFF_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
                case WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_OFF:
                this->state.state = WATER_VERYHOT_ON_BOI_SWITCH_ON_OCC_OCCUPENCY_ON;
                this->ta = fin;
                break;
            }
        }
    }
