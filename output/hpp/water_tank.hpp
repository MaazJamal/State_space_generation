//STATE DEFINITIONS

#define P_STOP_T_INIT 0
#define P_ON_T_INIT 1
#define P_STOP_T_HIGH_IN 2
#define P_ON_T_HIGH_IN 3
#define P_STOP_T_FILLED_IN 4
#define P_ON_T_FILLED_IN 5
#define P_STOP_T_LOW_IN 6
#define P_ON_T_LOW_IN 7
#define P_STOP_T_HIGH_OUT 8
#define P_ON_T_HIGH_OUT 9
#define P_STOP_T_FILLED_OUT 10
#define P_ON_T_FILLED_OUT 11
#define P_STOP_T_LOW_OUT 12
#define P_ON_T_LOW_OUT 13
#define P_PUMPING_T_INIT 14
#define P_OFF_T_INIT 15
#define P_PUMPING_T_HIGH_IN 16
#define P_OFF_T_HIGH_IN 17
#define P_PUMPING_T_FILLED_IN 18
#define P_OFF_T_FILLED_IN 19
#define P_PUMPING_T_LOW_IN 20
#define P_OFF_T_LOW_IN 21
#define P_PUMPING_T_HIGH_OUT 22
#define P_OFF_T_HIGH_OUT 23
#define P_PUMPING_T_FILLED_OUT 24
#define P_OFF_T_FILLED_OUT 25
#define P_PUMPING_T_LOW_OUT 26
#define P_OFF_T_LOW_OUT 27



 //PORTS 

struct water_tank_defs {
    struct pw : public out_port<string> { };
    struct w : public out_port<string> { };
    struct pw : public out_port<string> { };
    struct w : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct hs : public in_port<string> { };
    struct e : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct hs : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct e : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::w,typename defs::ls,typename defs::hs,typename defs::e,typename defs::ls,typename defs::hs,typename defs::ls,typename defs::e>;
    using output_ports = std::tuple<typename defs::pw,typename defs::w,typename defs::pw>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case P_STOP_T_INIT:
        this->state.state = P_ON_T_INIT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_IN:
        this->state.state = P_ON_T_HIGH_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_IN:
        this->state.state = P_ON_T_FILLED_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_IN:
        this->state.state = P_ON_T_LOW_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_OUT:
        this->state.state = P_ON_T_HIGH_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_OUT:
        this->state.state = P_ON_T_FILLED_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_ON_T_LOW_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_PUMPING_T_INIT:
        this->state.state = P_OFF_T_INIT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_IN:
        this->state.state = P_OFF_T_HIGH_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_IN:
        this->state.state = P_OFF_T_FILLED_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_IN:
        this->state.state = P_OFF_T_LOW_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_OUT:
        this->state.state = P_OFF_T_HIGH_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_OUT:
        this->state.state = P_OFF_T_FILLED_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_OFF_T_LOW_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_IN:
        this->state.state = P_STOP_T_HIGH_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_IN:
        this->state.state = P_PUMPING_T_HIGH_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_IN:
        this->state.state = P_STOP_T_LOW_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_IN:
        this->state.state = P_PUMPING_T_LOW_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_OUT:
        this->state.state = P_STOP_T_HIGH_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_OUT:
        this->state.state = P_PUMPING_T_HIGH_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_OUT:
        this->state.state = P_STOP_T_FILLED_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_OUT:
        this->state.state = P_PUMPING_T_FILLED_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_STOP_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_PUMPING_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_STOP_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_PUMPING_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "w") {
        if(this->in == "wstop"){
            switch (this->state.state) {
                case P_OFF_T_INIT:
                this->state.state = P_STOP_T_INIT;
                this->ta = inf;
                break;
                case P_OFF_T_HIGH_IN:
                this->state.state = P_STOP_T_HIGH_IN;
                this->ta = inf;
                break;
                case P_OFF_T_FILLED_IN:
                this->state.state = P_STOP_T_FILLED_IN;
                this->ta = inf;
                break;
                case P_OFF_T_LOW_IN:
                this->state.state = P_STOP_T_LOW_IN;
                this->ta = inf;
                break;
                case P_OFF_T_HIGH_OUT:
                this->state.state = P_STOP_T_HIGH_OUT;
                this->ta = inf;
                break;
                case P_OFF_T_FILLED_OUT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = inf;
                break;
                case P_OFF_T_LOW_OUT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "wstrt"){
            switch (this->state.state) {
                case P_ON_T_INIT:
                this->state.state = P_PUMPING_T_INIT;
                this->ta = inf;
                break;
                case P_ON_T_HIGH_IN:
                this->state.state = P_PUMPING_T_HIGH_IN;
                this->ta = inf;
                break;
                case P_ON_T_FILLED_IN:
                this->state.state = P_PUMPING_T_FILLED_IN;
                this->ta = inf;
                break;
                case P_ON_T_LOW_IN:
                this->state.state = P_PUMPING_T_LOW_IN;
                this->ta = inf;
                break;
                case P_ON_T_HIGH_OUT:
                this->state.state = P_PUMPING_T_HIGH_OUT;
                this->ta = inf;
                break;
                case P_ON_T_FILLED_OUT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = inf;
                break;
                case P_ON_T_LOW_OUT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "ls") {
        if(this->in == "L"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_LOW_IN:
                this->state.state = P_STOP_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_ON_T_LOW_IN:
                this->state.state = P_ON_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_PUMPING_T_LOW_IN:
                this->state.state = P_PUMPING_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_OFF_T_LOW_IN:
                this->state.state = P_OFF_T_FILLED_IN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "NL"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_FILLED_OUT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_ON_T_FILLED_OUT:
                this->state.state = P_ON_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_FILLED_OUT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_FILLED_OUT:
                this->state.state = P_OFF_T_LOW_OUT;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "hs") {
        if(this->in == "H"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_FILLED_IN:
                this->state.state = P_STOP_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_ON_T_FILLED_IN:
                this->state.state = P_ON_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_PUMPING_T_FILLED_IN:
                this->state.state = P_PUMPING_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_OFF_T_FILLED_IN:
                this->state.state = P_OFF_T_HIGH_IN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "NH"){
            switch (this->state.state) {
                case P_STOP_T_HIGH_OUT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_ON_T_HIGH_OUT:
                this->state.state = P_ON_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_HIGH_OUT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_HIGH_OUT:
                this->state.state = P_OFF_T_FILLED_OUT;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "e") {
        if(this->in == "null"){
            switch (this->state.state) {
                case P_STOP_T_LOW_OUT:
                this->state.state = P_STOP_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_ON_T_LOW_OUT:
                this->state.state = P_ON_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_PUMPING_T_LOW_OUT:
                this->state.state = P_PUMPING_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_OFF_T_LOW_OUT:
                this->state.state = P_OFF_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_STOP_T_HIGH_IN:
                this->state.state = P_STOP_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_ON_T_HIGH_IN:
                this->state.state = P_ON_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_PUMPING_T_HIGH_IN:
                this->state.state = P_PUMPING_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_OFF_T_HIGH_IN:
                this->state.state = P_OFF_T_OVERFLOW;
                this->ta = fin;
                break;
            }
        }
    }
