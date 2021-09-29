//STATE DEFINITIONS

#define CO2_LOW_OPEN_VENTS_SHUT 0
#define CO2_MEDIUM_OPEN_VENTS_SHUT 1
#define CO2_LOW_OPEN_VENTS_CLOSING 2
#define CO2_MEDIUM_OPEN_VENTS_CLOSING 3
#define CO2_LOW_OPEN_VENTS_OPENING 4
#define CO2_MEDIUM_OPEN_VENTS_OPENING 5
#define CO2_MEDIUM_OPEN_VENTS_FULL_OPEN 6
#define CO2_HIGH_OPEN_VENTS_SHUT 7
#define CO2_HIGH_OPEN_VENTS_CLOSING 8
#define CO2_HIGH_OPEN_VENTS_OPENING 9
#define CO2_HIGH_OPEN_VENTS_FULL_OPEN 10
#define CO2_LOW_CLOSED_VENTS_SHUT 11
#define CO2_MEDIUM_CLOSED_VENTS_SHUT 12
#define CO2_LOW_CLOSED_VENTS_CLOSING 13
#define CO2_MEDIUM_CLOSED_VENTS_CLOSING 14
#define CO2_LOW_CLOSED_VENTS_OPENING 15
#define CO2_MEDIUM_CLOSED_VENTS_OPENING 16
#define CO2_LOW_CLOSED_VENTS_FULL_OPEN 17
#define CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN 18
#define CO2_HIGH_CLOSED_VENTS_CLOSING 19
#define CO2_HIGH_CLOSED_VENTS_OPENING 20
#define CO2_HIGH_CLOSED_VENTS_FULL_OPEN 21



 //PORTS 

struct CO2_defs {
    struct vents_out : public out_port<string> { };
    struct co2 : public out_port<string> { };
    struct vents_in : public out_port<string> { };
    struct vents_out : public in_port<string> { };
    struct vent : public in_port<string> { };
    struct co2_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::vents_out,typename defs::vent,typename defs::co2_out>;
    using output_ports = std::tuple<typename defs::vents_out,typename defs::co2,typename defs::vents_in>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case CO2_LOW_OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW_CLOSED_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_OPEN_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_LOW_OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "vents_out") {
        if(this->in == "venth"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_LOW_CLOSED_VENTS_OPENING:
                this->state.state = CO2_LOW_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "ventl"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH_OPEN_VENTS_CLOSING:
                this->state.state = CO2_HIGH_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_LOW_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "vent") {
    }
    if(this->in_port == "co2_out") {
        if(this->in == "co2m"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2h"){
            switch (this->state.state) {
                case CO2_MEDIUM_OPEN_VENTS_SHUT:
                this->state.state = CO2_HIGH_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_HIGH_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_SHUT:
                this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2l"){
            switch (this->state.state) {
                case CO2_MEDIUM_OPEN_VENTS_SHUT:
                this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_SHUT:
                this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_LOW_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
    }
