#include "utils.h"

InputKeyErrno utils_enable_raw_mode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    return INPUT_KEY_SUCCESS;
}

InputKeyErrno utils_kbhit() {
    struct timeval tv = {0, 0};
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1) {
        return INPUT_KEY_SUCCESS;
    } else if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == -1) {
        return INPUT_KEY_ERR_NO_KEY;
    }
    return INPUT_KEY_ERR_UNKNOWN_KEY;
}

InputKeyErrno utils_get_key_press(char *key) {
    char c;
    if (utils_kbhit() == INPUT_KEY_SUCCESS) {
        read(STDIN_FILENO, &c, 1);
        *key = c;
        return INPUT_KEY_SUCCESS;
    }
    return INPUT_KEY_ERR_NO_KEY;
}

InputKeyErrno utils_disable_raw_mode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    return INPUT_KEY_SUCCESS;
}

// driver
int main() {
    char key;
    utils_enable_raw_mode();
    while (1) {
        if (utils_get_key_press(&key) == INPUT_KEY_SUCCESS) {
            printf("%c", key);
            if (key == 'q') {
                break;
            }
        }
    }
    utils_disable_raw_mode();
    return 0;
}