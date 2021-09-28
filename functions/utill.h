#ifndef UTILL
#define UTILL

void print_success(char*);
void print_warning(char*);
void print_error(char*);
void exit_with_success(char*);
void exit_with_error(char*);
int mkdir_r(const char*, const mode_t);
int mkdir_r_777(const char*);
int sort(int fn, int is_initial, char* input_directory_path, char* output_directory_path, int ch_num1, int ch_num2);
int make_bat(int id, int before_init, int after_init, int start_file_id, int end_file_id, char* input_directory_path, char* result_directory_path, char* bat_directory_path, char* initial_directory_path, double before_P, double after_P, double before_T, double after_T, double Nrev, int make_initial, int position, int position_sp);

#endif