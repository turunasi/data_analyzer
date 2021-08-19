#include <stdio.h>
#include <stdlib.h>

void make_data_logger_log(int fn, char* directory_path) {
    char log_path[100];
    FILE *fp_log;

    sprintf(log_path, "%s/%08di.log", directory_path, fn);  // output log path
    if ((fp_log = fopen(log_path, "w")) == NULL) {
        printf("\x1b[31m");
        printf("failed to make %s.\n", log_path);
        printf("\x1b[39m");
        exit(1);
    }

    fprintf(fp_log, "// Sony SIR-1000 data Log file\n");
    fprintf(fp_log, "// Warning:  Do not modify the contents of this file\n");
    fprintf(fp_log, "//\n");
    fprintf(fp_log, "VERSION           4.1    \n");
    fprintf(fp_log, "DATA_FILE         %03di.BIN    \n", fn);
    fprintf(fp_log, "FORMAT            0 INTEL-86    \n");
    fprintf(fp_log, "VOLUME_CH         96000    \n");
    fprintf(fp_log, "FILE_INTVL_CH     1.041667E-005 s    \n");
    fprintf(fp_log, "REMARKS           Remarks.....    \n");
    fprintf(fp_log, "CHANNEL           001, \"Ch_001\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           002, \"Ch_002\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           003, \"Ch_003\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           004, \"Ch_004\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           005, \"Ch_005\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           006, \"Ch_006\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           007, \"Ch_007\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           008, \"Ch_008\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           009, \"Ch_009\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           010, \"Ch_010\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           011, \"Ch_011\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           012, \"Ch_012\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           013, \"Ch_013\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           014, \"Ch_014\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           015, \"Ch_015\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "CHANNEL           016, \"Ch_016\", Volt, *(2.034505e-004)+(0.000000e+000)\n");
    fprintf(fp_log, "//\n");
    fprintf(fp_log, "// Info. at Data Copy\n");
    fprintf(fp_log, "//\n");
    fprintf(fp_log, "TAPE_BC_MODE      16    \n");
    fprintf(fp_log, "TAPE_SRATE_CH     96000 original-samples/s/channel\n");
    fprintf(fp_log, "DECIMATION        0    \n");
    fprintf(fp_log, "TAPE_SPEED        1    \n");
    fprintf(fp_log, "ID                %03di    \n", fn);
    fprintf(fp_log, "DATE_TIME         20170803 163211    \n");
    fprintf(fp_log, "TRIG_MODE         1 ID    \n");
    fprintf(fp_log, "INPUT_RANGE       CH_001, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_002, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_003, 10.00V\n");
    fprintf(fp_log, "INPUT_RANGE       CH_004, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_005, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_006, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_007, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_008, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_009, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_010, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_011, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_012, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_013, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_014, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_015, 5.00V \n");
    fprintf(fp_log, "INPUT_RANGE       CH_016, 5.00V \n");

    fclose(fp_log);
}