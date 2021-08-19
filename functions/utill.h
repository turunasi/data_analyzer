#ifndef UTILL
#define UTILL

void print_success(char*);
void print_warning(char*);
void print_error(char*);
void exit_with_success(char*);
void exit_with_error(char*);
int mkdir_r(const char*, const mode_t);
int mkdir_r_777(const char*);

#endif