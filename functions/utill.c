/**
 * @file utill.c
 * @author Yuki NISHII (turunasi@ruri.waseda.jp)
 * @brief utillity functions
 * @date 2021-08-07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PATH_MAX_STRING_SIZE 256

void print_success(char *comment) {
    printf("\x1b[32m"); 
    printf("%s", comment);
    printf("\x1b[39m");
}

void print_warning(char *comment) {
    printf("\x1b[33m");
    printf("%s", comment);
    printf("\x1b[39m");
}

void print_error(char *comment) {
    printf("\x1b[31m");
    printf("%s", comment);
    printf("\x1b[39m");
}

void exit_with_success(char *comment) {
    print_success(comment);
    exit(0);
}

void exit_with_error(char *comment) {
    print_error(comment);
    exit(1);
}

/* recursive mkdir */
int mkdir_r(const char *dir, const mode_t mode) {
    char tmp[PATH_MAX_STRING_SIZE];
    char *p = NULL;
    struct stat sb;
    size_t len;
    
    /* copy path */
    len = strnlen (dir, PATH_MAX_STRING_SIZE);
    if (len == 0 || len == PATH_MAX_STRING_SIZE) {
        return -1;
    }
    memcpy (tmp, dir, len);
    tmp[len] = '\0';

    /* remove trailing slash */
    if(tmp[len - 1] == '/') {
        tmp[len - 1] = '\0';
    }

    /* check if path exists and is a directory */
    if (stat (tmp, &sb) == 0) {
        if (S_ISDIR (sb.st_mode)) {
            return 0;
        }
    }
    
    /* recursive mkdir */
    for(p = tmp + 1; *p; p++) {
        if(*p == '/') {
            *p = 0;
            /* test path */
            if (stat(tmp, &sb) != 0) {
                /* path does not exist - create directory */
                if (mkdir(tmp, mode) < 0) {
                    return -1;
                }
            } else if (!S_ISDIR(sb.st_mode)) {
                /* not a directory */
                return -1;
            }
            *p = '/';
        }
    }
    /* test path */
    if (stat(tmp, &sb) != 0) {
        /* path does not exist - create directory */
        if (mkdir(tmp, mode) < 0) {
            return -1;
        }
    } else if (!S_ISDIR(sb.st_mode)) {
        /* not a directory */
        return -1;
    }
    return 0;
}

int mkdir_r_777(const char *dir) {
    return mkdir_r(dir,
        S_IRUSR | S_IWUSR | S_IXUSR |
        S_IRGRP | S_IWGRP | S_IXGRP |
        S_IROTH | S_IXOTH | S_IXOTH // permission 777
    );
}
