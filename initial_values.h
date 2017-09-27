////////////////////////////////////////////////////////////////////////////////
// misc initial values
////////////////////////////////////////////////////////////////////////////////

#ifndef initial_values_h
  #define initial_values_h


// these "1 to 100" are arbitrary for now, thinking in terms of %-meshed
int C1 = 1; //capacitor 1 mesh value -- 0 to 100
int L1 = 1; //inductor 1 travel value -- 0 to 1000
int C2 = 1; //capacitor 1 mesh value -- 0 to 100

// min-max values for C1, L1, C2
int C1_min = 10; 
int C1_max = 330;

int L1_min = 20;
int L1_max = 2000;

int C2_min = 12;
int C2_max = 220;



#endif
