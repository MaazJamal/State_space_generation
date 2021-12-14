//STATE DEFINITIONS

#define INIT 0
#define OVERFLOW 1
#define EXHAUSTED 2
#define HIGH_IN 3
#define FILLED_IN 4
#define LOW_IN 5
#define HIGH_OUT 6
#define FILLED_OUT 7
#define LOW_OUT 8



 //PORTS 

struct tank_defs {
    struct ls : public out_port<string> { };
    struct hs : public out_port<string> { };
    struct e : public out_port<string> { };
    struct w : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::w>;
    using output_ports = std::tuple<typename defs::ls,typename defs::hs,typename defs::e>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case INIT:
        this->state.state = FILLED_OUT;
        this->out_port = "ls";
        this->out = "L";
        this->ta = fin;
        break;
    case LOW_IN:
        this->state.state = FILLED_IN;
        this->out_port = "ls";
        this->out = "L";
        this->ta = fin;
        break;
    case INIT:
        this->state.state = LOW_OUT;
        this->out_port = "ls";
        this->out = "NL";
        this->ta = fin;
        break;
    case FILLED_OUT:
        this->state.state = LOW_OUT;
        this->out_port = "ls";
        this->out = "NL";
        this->ta = fin;
        break;
    case INIT:
        this->state.state = HIGH_OUT;
        this->out_port = "hs";
        this->out = "H";
        this->ta = fin;
        break;
    case FILLED_IN:
        this->state.state = HIGH_IN;
        this->out_port = "hs";
        this->out = "H";
        this->ta = fin;
        break;
    case HIGH_OUT:
        this->state.state = FILLED_OUT;
        this->out_port = "hs";
        this->out = "NH";
        this->ta = fin;
        break;
    case LOW_OUT:
        this->state.state = EXHAUSTED;
        this->out_port = "e";
        this->out = "null";
        this->ta = fin;
        break;
    case HIGH_IN:
        this->state.state = OVERFLOW;
        this->out_port = "e";
        this->out = "null";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "w") {
        if(this->in == "wstop"){
            switch (this->state.state) {
                case OVERFLOW:
                this->state.state = HIGH_OUT;
                this->ta = fin;
                break;
                case HIGH_IN:
                this->state.state = HIGH_OUT;
                this->ta = fin;
                break;
                case FILLED_IN:
                this->state.state = FILLED_OUT;
                this->ta = fin;
                break;
                case LOW_IN:
                this->state.state = LOW_OUT;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "wstrt"){
            switch (this->state.state) {
                case HIGH_OUT:
                this->state.state = HIGH_IN;
                this->ta = fin;
                break;
                case FILLED_OUT:
                this->state.state = FILLED_IN;
                this->ta = fin;
                break;
                case LOW_OUT:
                this->state.state = LOW_IN;
                this->ta = fin;
                break;
                case LOW_OUT:
                this->state.state = LOW_IN;
                this->ta = fin;
                break;
            }
        }
    }
