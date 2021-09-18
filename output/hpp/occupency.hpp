//STATE DEFINITIONS

#define OCCUP_OCCUPIED_LIGHT_ON 0
#define OCCUP_EXIT_LIGHT_ON 1
#define OCCUP_OCCUPIED_LIGHT_OFF 2
#define OCCUP_EXIT_LIGHT_OFF 3
#define OCCUP_OCCUPIED_LIGHT_SWITCH_ON 4
#define OCCUP_EXIT_LIGHT_SWITCH_ON 5
#define OCCUP_OCCUPIED_LIGHT_SWITCH_OFF 6
#define OCCUP_EXIT_LIGHT_SWITCH_OFF 7
#define OCCUP_NOT_OCCUPIED_LIGHT_ON 8
#define OCCUP_ENTRY_LIGHT_ON 9
#define OCCUP_NOT_OCCUPIED_LIGHT_OFF 10
#define OCCUP_ENTRY_LIGHT_OFF 11
#define OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON 12
#define OCCUP_ENTRY_LIGHT_SWITCH_ON 13
#define OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF 14
#define OCCUP_ENTRY_LIGHT_SWITCH_OFF 15



 //PORTS 

struct occupency_defs {
    struct occupency_out : public out_port<string> { };
    struct occupency_in : public out_port<string> { };
    struct ocp : public out_port<string> { };
    struct light_out : public in_port<string> { };
    struct occupency_out : public in_port<string> { };
    struct light : public in_port<string> { };
};


//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OCCUP_OCCUPIED_LIGHT_ON:
        this->state.state = OCCUP_EXIT_LIGHT_ON;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_OCCUPIED_LIGHT_OFF:
        this->state.state = OCCUP_EXIT_LIGHT_OFF;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_OCCUPIED_LIGHT_SWITCH_ON:
        this->state.state = OCCUP_EXIT_LIGHT_SWITCH_ON;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_OCCUPIED_LIGHT_SWITCH_OFF:
        this->state.state = OCCUP_EXIT_LIGHT_SWITCH_OFF;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_ON:
        this->state.state = OCCUP_ENTRY_LIGHT_ON;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_OFF:
        this->state.state = OCCUP_ENTRY_LIGHT_OFF;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON:
        this->state.state = OCCUP_ENTRY_LIGHT_SWITCH_ON;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF:
        this->state.state = OCCUP_ENTRY_LIGHT_SWITCH_OFF;
        this->out_port = "occupency_in";
        this->out = "ocs"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_ON:
        this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF;
        this->out_port = "occupency_out";
        this->out = "ocl"
        this->ta = fin;
        break;
    case OCCUP_OCCUPIED_LIGHT_ON:
        this->state.state = OCCUP_OCCUPIED_LIGHT_SWITCH_OFF;
        this->out_port = "occupency_out";
        this->out = "ocl"
        this->ta = fin;
        break;
    case OCCUP_NOT_OCCUPIED_LIGHT_OFF:
        this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON;
        this->out_port = "occupency_out";
        this->out = "och"
        this->ta = fin;
        break;
    case OCCUP_OCCUPIED_LIGHT_OFF:
        this->state.state = OCCUP_OCCUPIED_LIGHT_SWITCH_ON;
        this->out_port = "occupency_out";
        this->out = "och"
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "light_out" {
        if(this->in == "off"{
            switch (this->state.state) {
                case OCCUP_ENTRY_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_ENTRY_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCCUP_EXIT_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_EXIT_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCCUP_OCCUPIED_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_OCCUPIED_LIGHT_OFF;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "on"{
            switch (this->state.state) {
                case OCCUP_ENTRY_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_ENTRY_LIGHT_ON;
                this->ta = inf;
                break;
                case OCCUP_EXIT_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_EXIT_LIGHT_ON;
                this->ta = inf;
                break;
                case OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_ON;
                this->ta = inf;
                break;
                case OCCUP_OCCUPIED_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_OCCUPIED_LIGHT_ON;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "occupency_out" {
        if(this->in == "ocl"{
            switch (this->state.state) {
                case OCCUP_ENTRY_LIGHT_ON:
                this->state.state = OCCUP_OCCUPIED_LIGHT_ON;
                this->ta = inf;
                break;
                case OCCUP_ENTRY_LIGHT_OFF:
                this->state.state = OCCUP_OCCUPIED_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCCUP_ENTRY_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_OCCUPIED_LIGHT_SWITCH_ON;
                this->ta = inf;
                break;
                case OCCUP_ENTRY_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_OCCUPIED_LIGHT_SWITCH_OFF;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "och"{
            switch (this->state.state) {
                case OCCUP_EXIT_LIGHT_ON:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_ON;
                this->ta = inf;
                break;
                case OCCUP_EXIT_LIGHT_OFF:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCCUP_EXIT_LIGHT_SWITCH_ON:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_ON;
                this->ta = inf;
                break;
                case OCCUP_EXIT_LIGHT_SWITCH_OFF:
                this->state.state = OCCUP_NOT_OCCUPIED_LIGHT_SWITCH_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "light" {
    }
