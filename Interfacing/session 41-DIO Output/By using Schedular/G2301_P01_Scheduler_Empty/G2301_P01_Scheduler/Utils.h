

#ifndef UTILS_H_
#define UTILS_H_



#define   SET_BIT(reg,bit)      (reg=reg|(1<<bit))
#define   CLEAR_BIT(reg,bit)    (reg=reg&(~(1<<bit)))
#define   READ_BIT(reg,bit)     ((reg>>bit)&1)
#define   TOGGLE_BIT(reg,bit)      (reg=reg^(1<<bit))



#endif /* UTILS_H_ */