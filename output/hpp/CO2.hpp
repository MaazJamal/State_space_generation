//STATE DEFINITIONS

#define CO2_LOW-OPEN_VENTS_SHUT 0
#define CO2_LOW-CLOSED_VENTS_SHUT 1
#define CO2_LOW-OPEN_VENTS_CLOSING 2
#define CO2_LOW-CLOSED_VENTS_CLOSING 3
#define CO2_LOW-OPEN_VENTS_OPENING 4
#define CO2_LOW-CLOSED_VENTS_OPENING 5
#define CO2_LOW-CLOSED_VENTS_FULL_OPEN 6
#define CO2_MEDIUM-OPEN_VENTS_SHUT 7
#define CO2_MEDIUM-CLOSED_VENTS_SHUT 8
#define CO2_MEDIUM-OPEN_VENTS_CLOSING 9
#define CO2_MEDIUM-CLOSED_VENTS_CLOSING 10
#define CO2_MEDIUM-OPEN_VENTS_OPENING 11
#define CO2_MEDIUM-CLOSED_VENTS_OPENING 12
#define CO2_MEDIUM-OPEN_VENTS_FULL_OPEN 13
#define CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN 14
#define CO2_HIGH-OPEN_VENTS_SHUT 15
#define CO2_HIGH-OPEN_VENTS_CLOSING 16
#define CO2_HIGH-CLOSED_VENTS_CLOSING 17
#define CO2_HIGH-OPEN_VENTS_OPENING 18
#define CO2_HIGH-CLOSED_VENTS_OPENING 19
#define CO2_HIGH-OPEN_VENTS_FULL_OPEN 20
#define CO2_HIGH-CLOSED_VENTS_FULL_OPEN 21



 //PORTS 

struct CO2_defs {
    struct vents_out : public out_port<string> { };
    struct co2 : public out_port<string> { };
    struct co2_out : public out_port<string> { };
    struct vent_out : public in_port<string> { };
    struct vent : public in_port<string> { };
    struct co2_out : public in_port<string> { };
};


//INTERNAL TRANSITIONS

switch (this->state.state) {
    case CO2_LOW-OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW-CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_LOW-OPEN_VENTS_CLOSING:
        this->state.state = CO2_LOW-CLOSED_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_LOW-OPEN_VENTS_OPENING:
        this->state.state = CO2_LOW-CLOSED_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_MEDIUM-OPEN_VENTS_SHUT:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_MEDIUM-OPEN_VENTS_CLOSING:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_MEDIUM-OPEN_VENTS_OPENING:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_MEDIUM-OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_HIGH-OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH-CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_HIGH-OPEN_VENTS_CLOSING:
        this->state.state = CO2_HIGH-CLOSED_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_HIGH-OPEN_VENTS_OPENING:
        this->state.state = CO2_HIGH-CLOSED_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_HIGH-OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH-CLOSED_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "ventl"
        this->ta = inf;
        break;
    case CO2_LOW-CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW-OPEN_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_LOW-CLOSED_VENTS_CLOSING:
        this->state.state = CO2_LOW-OPEN_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_LOW-CLOSED_VENTS_OPENING:
        this->state.state = CO2_LOW-OPEN_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_LOW-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW-OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_SHUT:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_CLOSING:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_OPENING:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_HIGH-CLOSED_VENTS_CLOSING:
        this->state.state = CO2_HIGH-OPEN_VENTS_CLOSING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_HIGH-CLOSED_VENTS_OPENING:
        this->state.state = CO2_HIGH-OPEN_VENTS_OPENING;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_HIGH-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH-OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth"
        this->ta = inf;
        break;
    case CO2_LOW-OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW-OPEN_VENTS_OPENING;
        this->out_port = "co2_out";
        this->out = "co2h"
        this->ta = fin;
        break;
    case CO2_MEDIUM-OPEN_VENTS_SHUT:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_OPENING;
        this->out_port = "co2_out";
        this->out = "co2h"
        this->ta = fin;
        break;
    case CO2_HIGH-OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH-OPEN_VENTS_OPENING;
        this->out_port = "co2_out";
        this->out = "co2h"
        this->ta = fin;
        break;
    case CO2_LOW-CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW-CLOSED_VENTS_OPENING;
        this->out_port = "co2_out";
        this->out = "co2h"
        this->ta = fin;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_SHUT:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_OPENING;
        this->out_port = "co2_out";
        this->out = "co2h"
        this->ta = fin;
        break;
    case CO2_MEDIUM-OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM-OPEN_VENTS_CLOSING;
        this->out_port = "co2_out";
        this->out = "co2l"
        this->ta = fin;
        break;
    case CO2_HIGH-OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH-OPEN_VENTS_CLOSING;
        this->out_port = "co2_out";
        this->out = "co2l"
        this->ta = fin;
        break;
    case CO2_LOW-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW-CLOSED_VENTS_CLOSING;
        this->out_port = "co2_out";
        this->out = "co2l"
        this->ta = fin;
        break;
    case CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM-CLOSED_VENTS_CLOSING;
        this->out_port = "co2_out";
        this->out = "co2l"
        this->ta = fin;
        break;
    case CO2_HIGH-CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH-CLOSED_VENTS_CLOSING;
        this->out_port = "co2_out";
        this->out = "co2l"
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "vent_out" {
        if(this->in == "venth"{
            switch (this->state.state) {
                case CO2_LOW-OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW-OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM-OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH-OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH-OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_LOW-CLOSED_VENTS_OPENING:
                this->state.state = CO2_LOW-CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH-CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH-CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "ventl"{
            switch (this->state.state) {
                case CO2_LOW-OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW-OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM-OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH-OPEN_VENTS_CLOSING:
                this->state.state = CO2_HIGH-OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_LOW-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW-CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH-CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "vent" {
    }
    if(this->in_port == "co2_out" {
        if(this->in == "co2m"{
            switch (this->state.state) {
                case CO2_LOW-OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW-OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW-OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH-OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_HIGH-OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_HIGH-OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH-OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM-OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_LOW-CLOSED_VENTS_SHUT:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW-CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_LOW-CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_HIGH-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_HIGH-CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH-CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2h"{
            switch (this->state.state) {
                case CO2_MEDIUM-OPEN_VENTS_SHUT:
                this->state.state = CO2_HIGH-OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_CLOSING:
                this->state.state = CO2_HIGH-OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH-OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH-OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_SHUT:
                this->state.state = CO2_HIGH-CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH-CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH-CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH-CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2l"{
            switch (this->state.state) {
                case CO2_MEDIUM-OPEN_VENTS_SHUT:
                this->state.state = CO2_LOW-OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW-OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW-OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW-OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_SHUT:
                this->state.state = CO2_LOW-CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW-CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_OPENING:
                this->state.state = CO2_LOW-CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM-CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW-CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
    }
